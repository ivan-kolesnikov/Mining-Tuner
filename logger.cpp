#include "logger.h"
#include "ui_logger.h"

logger::logger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logger)
{
    ui->setupUi(this);
    /*
    // disable close buttons on the form
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    */
    // focus settings for correct handling of keyboard events
    focus_settings();
}

logger::~logger()
{
    delete ui;
}

void logger::focus_settings()
{
    ui->te_log->setFocusProxy(this);
}


void logger::pos_init(QPoint main_app_pos, int x_pos_offset)
{
    this->move(main_app_pos.x()+x_pos_offset,main_app_pos.y());
}


void logger::keyPressEvent(QKeyEvent* event)
{
    // 0x26 - nativeScanSode for L symbol in any layout, but depends of keyboard
    if (event->key() == Qt::Key_L || event->nativeScanCode() == 0x26)
    {
        if (this->isHidden())
        {
            this->show();
        }
        else
        {
            this->hide();
        }
    }
}


void logger::append(QString name, QList<QString> header, QList<QString> line)
{
    QDir dir(".");
    // check the logs folder
    QString logs_folder_path = dir.absolutePath()+QString("/Logs");
    // if the logs folder does not exist
    if (!QDir(logs_folder_path).exists())
    {
        // create the logs folder
        if (!QDir().mkdir(logs_folder_path))
        {
            // show the message in case of error
            QMessageBox::critical(0, "Error", QString("Can't create the Logs folder. Check the application permissions!"));
            // and out from logging
            return;
        }
    }
    // check the log file
    QString log_file_path = logs_folder_path+QString("/")+name;
    QFileInfo log_file(log_file_path);
    // write a header for new files
    bool header_needed = !log_file.exists();
    // open the log file with append modifier
    QFile log_fd(log_file_path);
    if (!log_fd.open(QIODevice::Append))
    {
        // show the message in case of error
        QMessageBox::critical(0, "Error", QString("Can't create the log file. Check the application permissions!"));
        return;
    }
    // text stream object to convenient write info in the log
    QTextStream log_text_stream(&log_fd);
    // write header if this is necessary
    if (header_needed)
    {
        for (int i_h = 0; i_h < header.size(); i_h++)
        {
            log_text_stream << header[i_h] << "\t";
        }
        log_text_stream << "\n";
    }
    // write the line
    for (int i_l = 0; i_l < line.size(); i_l++)
    {
        log_text_stream << line[i_l] << "\t";
    }
    log_text_stream << "\n";
    // close the log file
    log_fd.close();
    // write data to the text edit
    ui->te_log->append(line.join(" "));
}
