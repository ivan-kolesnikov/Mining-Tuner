#include "mt.h"
#include "ui_mt.h"

MT::MT(int tuning_seconds, int tuning_wait_seconds, QString app_name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MT)
{
    ui->setupUi(this);
    // application name and version
    application_name = app_name;
    this->setWindowTitle(application_name);
    // by default tuning
    tuningStatus = statusesMT::stopped;
    // time to stay on the one tuning iteration
    tuning_seconds_per_iteration = tuning_seconds;
    // wait time in one iteration
    tuning_seconds_wait_per_iteration = tuning_wait_seconds;
    // prepare video cards indexes in combo box
    QList<int> gpu_indexes_lst = get_available_gpu_indexes();
    for (int i = 0; i < gpu_indexes_lst.count(); i++)
    {
        ui->cb_card_index->addItem(QString::number(gpu_indexes_lst[i]));
    }
    // start work with the first card from the gpu_indexes_lst
    gpu_index = gpu_indexes_lst[0];
    // change video card index
    connect(ui->cb_card_index, SIGNAL(currentTextChanged(QString)), this, SLOT(gpu_index_changed()));
    // manual control buttons
    connect(ui->btn_offset_core, SIGNAL(clicked()), this, SLOT(offset_core()));
    connect(ui->btn_offset_mem, SIGNAL(clicked()), this, SLOT(offset_mem()));
    connect(ui->btn_set_pl, SIGNAL(clicked()), this, SLOT(set_power_limit()));
    connect(ui->btn_apply_all_core_mem_pl, SIGNAL(clicked()), this, SLOT(apply_all_core_mem_pl()));
    // tuning buttons
    connect(ui->btn_start_stop, SIGNAL(clicked()), this, SLOT(tuning_start_stop()));
    connect(ui->btn_pause_resume, SIGNAL(clicked()), this, SLOT(tuning_pause_resume()));
    // visualization
    connect(&visualization_tm, SIGNAL(timeout()), this, SLOT(update_displays()));
    // for correct handling of keyboard events from all form elements
    event_filter_settings();
}

MT::~MT()
{
    delete ui;
}


int MT::nvsmi_init()
{
    return nvidiaSMI.smi_init();
}


int MT::nvinspector_init()
{
    return nvidiaInspector.inspector_init();
}


void MT::offset_core()
{
    nvidiaInspector.core_offset(gpu_index, pstate, ui->sb_core_offset->value());
}


void MT::offset_mem()
{
    nvidiaInspector.mem_offset(gpu_index, pstate, ui->sb_mem_offset->value());
}


void MT::set_power_limit()
{
    nvidiaSMI.set_power_limit(gpu_index, ui->sb_pow_limit->value());
}


void MT::apply_all_core_mem_pl()
{
    offset_core();
    offset_mem();
    set_power_limit();
}


QList<int> MT::get_available_gpu_indexes()
{
    QList<int> gpu_indexes;
    gpu_indexes << 0 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9;
    return gpu_indexes;
}

void MT::update_displays()
{
    if (tuningStatus != statusesMT::active)
    {
        int cur_core, cur_mem, cur_pl, cur_power;
        // get current core frequency
        cur_core = nvidiaSMI.get_value(nvidiaSMI.cst_cur_core, gpu_index);
        // current memory frequency
        cur_mem = nvidiaSMI.get_value(nvidiaSMI.cst_cur_mem, gpu_index);
        // power limit
        cur_pl = nvidiaSMI.get_value(nvidiaSMI.cst_cur_power_limit, gpu_index);
        // power consumption
        cur_power = nvidiaSMI.get_value(nvidiaSMI.cst_cur_power, gpu_index);
        // display these values
        ui->display_current_pl->display(QString::number(cur_pl));
        ui->display_current_memory->display(QString::number(cur_mem));
        ui->display_current_core->display(QString::number(cur_core));
        ui->display_power->display(QString::number(cur_power));
    }
}


void MT::gpu_index_changed()
{
    // update gpu_index
    gpu_index = ui->cb_card_index->currentText().toInt();
    // update gpu name in the application
    gpu_name = nvidiaSMI.get_string(nvidiaSMI.cst_gpu_name, gpu_index);
    // and on the label
    ui->lbl_card_name->setText(gpu_name);
    // update maximum values on the displays
    ui->display_maximum_core->display(QString::number(nvidiaSMI.get_value(nvidiaSMI.cst_max_core, gpu_index)));
    ui->display_maximum_memory->display(QString::number(nvidiaSMI.get_value(nvidiaSMI.cst_max_mem, gpu_index)));
    ui->display_maximum_pl->display(QString::number(nvidiaSMI.get_value(nvidiaSMI.cst_max_power_limit, gpu_index)));
    // update minimum and default power limit on the labels
    ui->lbl_min_pl->setText(QString("MIN POW LIMIT ")+
                            QString::number(nvidiaSMI.get_value(nvidiaSMI.cst_min_power_limit, gpu_index)));
    ui->lbl_def_pl->setText(QString("DEFAULT POW LIMIT ")+
                            QString::number(nvidiaSMI.get_value(nvidiaSMI.cst_def_power_limit, gpu_index)));
}


void MT::tuning_start_stop()
{
    // start
    if (tuningStatus == statusesMT::stopped)
    {
        tuningStatus = statusesMT::active;
        tuning_core();
    }
    // stop
    else
    {
        tuningStatus = statusesMT::stopped;
    }
}


void MT::tuning_pause_resume()
{
    // pause
    if (tuningStatus == statusesMT::active)
    {
        tuningStatus = statusesMT::paused;
    }
    // resume
    else if (tuningStatus == statusesMT::paused)
    {
        tuningStatus = statusesMT::active;
    }
}


void MT::tuning_core()
{
    // update start/stop button text to STOP as the tuning algorithm already started
    ui->btn_start_stop->setText("STOP");
    // memory frequency offsets for tuning
    QList<int> lst_mem = generate_memory_list();
    // power limits identification
    int pl_min = nvidiaSMI.get_value(nvidiaSMI.cst_min_power_limit, gpu_index);
    int pl_def = nvidiaSMI.get_value(nvidiaSMI.cst_def_power_limit, gpu_index);
    int pl_max = nvidiaSMI.get_value(nvidiaSMI.cst_max_power_limit, gpu_index);
    QString error_code = "";
    if (pl_min == -1)
    {
        error_code += "Can't identify minimum power limit\r\n";
    }
    if (pl_def == -1)
    {
        error_code += "Can't identify default power limit\r\n";
    }
    if (pl_max == -1)
    {
        error_code += "Can't identify maximum power limit\r\n";
    }
    // if one of the power limits didn't identified
    if (!error_code.isEmpty())
    {
        // show error message with description
        QMessageBox::critical(0, "Error", error_code);
        // stop the tuning algorithm
        tuningStatus = statusesMT::stopped;
        ui->btn_start_stop->setText("START");
        return;
    }
    // power limits for tuning
    QList<int> lst_pl = generate_pl_list(pl_min, pl_def, pl_max);
    // core frequency offsets for tuning
    QList<int> lst_core = generate_core_list();

    // define working variables and lists
    QList<QString> log_line, log_header;
    QString log_name, iter_time;
    int cur_core, cur_mem, cur_pl, cur_power;
    for (int i_mem = 0; i_mem < lst_mem.count(); i_mem++)
    {
        // memory offset
        nvidiaInspector.mem_offset(gpu_index, pstate, lst_mem[i_mem]);
        for (int i_pl = 0; i_pl < lst_pl.count(); i_pl++)
        {
            // power limit
            nvidiaSMI.set_power_limit(gpu_index, lst_pl[i_pl]);
            for (int i_core = 0; i_core < lst_core.count(); i_core++)
            {
                // core offset
                nvidiaInspector.core_offset(gpu_index, pstate, lst_core[i_core]);
                for (int i_sec = 0; i_sec < tuning_seconds_per_iteration/tuning_seconds_wait_per_iteration; i_sec++)
                {
                    // get current core frequency
                    cur_core = nvidiaSMI.get_value(nvidiaSMI.cst_cur_core, gpu_index);
                    // and display it
                    ui->display_current_core->display(QString::number(cur_core));
                    // get current memory frequency
                    cur_mem = nvidiaSMI.get_value(nvidiaSMI.cst_cur_mem, gpu_index);
                    ui->display_current_memory->display(QString::number(cur_mem));
                    // get current power limit
                    cur_pl = nvidiaSMI.get_value(nvidiaSMI.cst_cur_power_limit, gpu_index);
                    ui->display_current_pl->display(QString::number(cur_pl));
                    // get current power consumption
                    cur_power = nvidiaSMI.get_value(nvidiaSMI.cst_cur_power, gpu_index);
                    ui->display_power->display(QString::number(cur_power));

                    // STOP tuning
                    if (tuningStatus == statusesMT::stopped)
                    {
                        // update start/stop button text to START as the tuning algorithm already stopped
                        ui->btn_start_stop->setText("START");
                        // update pause/resume button text to PAUSE
                        ui->btn_pause_resume->setText("PAUSE");
                        // out from tuning mode
                        return;
                    }
                    // PAUSE tuning
                    else if (tuningStatus == statusesMT::paused)
                    {
                        // decrement seconds index -> it create infinite loop while stop or resume buttons don't clicked
                        --i_sec;
                        // update pause/resume button text to RESUME as the tuning algorithm paused
                        ui->btn_pause_resume->setText("RESUME");
                        // sleep in mseconds
                        my_msleep(tuning_seconds_wait_per_iteration*1000);
                        // go to the cycle start while the tuningStatus not change
                        continue;
                    }
                    // RESUME tuning
                    else if (tuningStatus == statusesMT::active)
                    {
                        // if tuning algorithm has been resumed
                        if (ui->btn_pause_resume->text() == "RESUME")
                        {
                            // update pause/resume button text to PAUSE
                            ui->btn_pause_resume->setText("PAUSE");
                        }
                    }

                    // empty log line and header
                    log_line.clear();
                    log_header.clear();
                    log_name = QDate::currentDate().toString("yyyy-MM-dd")+QString("_")+
                            QString::number(gpu_index)+QString("_")+gpu_name+QString(".csv");
                    // current iteretion time
                    iter_time = QTime::currentTime().toString("hh:mm:ss");
                    log_header << QString("time") << QString("memory_offset") << QString("power_limit") << QString("core_offset")
                               << QString("current_memory") << QString("current_power") << QString("current_core");
                    log_line << iter_time << QString::number(lst_mem[i_mem]) << QString::number(lst_pl[i_pl]) << QString::number(lst_core[i_core])
                             << QString::number(cur_mem) << QString::number(cur_power) << QString::number(cur_core);
                    // append information to the log file
                    application_log.append(log_name, log_header, log_line);
                    // sleep in mseconds
                    my_msleep(tuning_seconds_wait_per_iteration*1000);
                }
            }
        }
    }
}


QList<int> MT::generate_memory_list()
{
    QList<int> lst_tune_mem;
    lst_tune_mem << 900 << 800 << 700 << 600;
    return lst_tune_mem;
}


QList<int> MT::generate_pl_list(int min, int def, int max)
{
    QList<int> lst_tune_pl;
    lst_tune_pl << max*0.9 << def << max/2 << min;
    return lst_tune_pl;
}


QList<int> MT::generate_core_list()
{
    QList<int> lst_tune_core;
    lst_tune_core << 50 << 75 << 100 << 125 << 150;
    return lst_tune_core;
}


void MT::my_msleep(int msec)
{
    // save the tuningStatus at start sleep function
    statusesMT previousTuningStatus = tuningStatus;
    QTime dieTime= QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        // if tuningStatus has been changed
        if (previousTuningStatus != tuningStatus )
        {
            // out from sleep function
            return;
        }
    }
}

void MT::change_log_window_pos(QPoint main_app_pos, int x_pos_offset)
{
    application_log.pos_init(main_app_pos, x_pos_offset);
}


void MT::event_filter_settings()
{
    ui->sb_core_offset->installEventFilter(this);
    ui->sb_mem_offset->installEventFilter(this);
    ui->sb_pow_limit->installEventFilter(this);
    ui->cb_card_index->installEventFilter(this);
}


void MT::keyPressEvent(QKeyEvent* event)
{
    // 0x26 - nativeScanSode for L symbol in any layout, but depends of keyboard
    if (event->key() == Qt::Key_L || event->nativeScanCode() == 0x26)
    {
        if (application_log.isHidden())
        {
            application_log.show();
        }
        else
        {
            application_log.hide();
        }
    }
}


bool MT::eventFilter(QObject* obj, QEvent *event)
{
    // CORE spinbox
    if (obj == ui->sb_core_offset)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            // L pressed
            if (keyEvent->key() == Qt::Key_L || keyEvent->nativeScanCode() == 0x26)
            {
                if (application_log.isHidden())
                {
                    application_log.show();
                    return true;
                }
                else
                {
                    application_log.hide();
                    return true;
                }
            }
            // ENTER pressed
            else if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
            {
                // press the core offset button
                ui->btn_offset_core->click();
                return true;
            }
        }
        return false;
    }
    // MEMORY spinbox
    else if (obj == ui->sb_mem_offset)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            // L pressed
            if (keyEvent->key() == Qt::Key_L || keyEvent->nativeScanCode() == 0x26)
            {
                if (application_log.isHidden())
                {
                    application_log.show();
                    return true;
                }
                else
                {
                    application_log.hide();
                    return true;
                }
            }
            // ENTER pressed
            else if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
            {
                // press the memory offset button
                ui->btn_offset_mem->click();
                return true;
            }
        }
        return false;
    }
    // POWER LIMIT spinbox
    else if (obj == ui->sb_pow_limit)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            // L pressed
            if (keyEvent->key() == Qt::Key_L || keyEvent->nativeScanCode() == 0x26)
            {
                if (application_log.isHidden())
                {
                    application_log.show();
                    return true;
                }
                else
                {
                    application_log.hide();
                    return true;
                }
            }
            // ENTER pressed
            else if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
            {
                // press the power limit button
                ui->btn_set_pl->click();
                return true;
            }
        }
        return false;
    }
    // CARD INDEX combobox
    else if (obj == ui->cb_card_index)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            // L pressed
            if (keyEvent->key() == Qt::Key_L || keyEvent->nativeScanCode() == 0x26)
            {
                if (application_log.isHidden())
                {
                    application_log.show();
                    return true;
                }
                else
                {
                    application_log.hide();
                    return true;
                }
            }
        }
        return false;
    }
    return MT::eventFilter(obj, event);
}
