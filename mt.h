#ifndef MT_H
#define MT_H

#include <QWidget>
#include <QList>
#include <QMessageBox>
#include <QTime>
#include <QDate>
#include <QThread>
#include <QShortcut>
#include "nvsmi.h"
#include "nvinspector.h"
#include "logger.h"
#include <QKeyEvent>
#include <QTimer>
#include <QPoint>

enum class statusesMT
{
    active,
    stopped,
    paused
};

namespace Ui {
class MT;
}

class MT : public QWidget
{
    Q_OBJECT

public:
    explicit MT(int tuning_seconds, int tuning_wait_seconds, QString app_name, QWidget *parent = 0);
    ~MT();
    int nvsmi_init();
    int nvinspector_init();
    statusesMT tuningStatus;
    QTimer visualization_tm;
    void change_log_window_pos(QPoint main_app_pos, int x_pos_offset);

public slots:
    void gpu_index_changed();
    // visualize data
    void update_displays();

private:
    Ui::MT *ui;
    // object to control nvidia-smi application
    nvsmi nvidiaSMI;
    // object to control nvidia inspector application
    nvinspector nvidiaInspector;
    // object to show a log at the additional form and write it in the .csv file
    logger application_log;
    // managed gpu index
    int gpu_index = -1;
    // managed gpu name
    QString gpu_name = "";
    // temporary solution, we need to understand current pstate
    int pstate = 0;
    // main tuning function
    void tuning_core();
    // lists with frequencies and power limits for tuning
    QList<int> generate_memory_list();
    QList<int> generate_pl_list(int min, int def, int max);
    QList<int> generate_core_list();
    // one iteration N seconds
    int tuning_seconds_per_iteration;
    // each wait M seconds. TOTAL N/M iterations
    int tuning_seconds_wait_per_iteration;
    QString application_name;
    QList<int> get_available_gpu_indexes();
    void keyPressEvent(QKeyEvent* event);
    void event_filter_settings();
    bool eventFilter(QObject* obj, QEvent *event);
    // sleep in main thread without gui freezing
    void my_msleep(int msec);

private slots:
    // manual control
    void offset_core();
    void offset_mem();
    void set_power_limit();
    void apply_all_core_mem_pl();
    // tuning buttons
    void tuning_start_stop();
    void tuning_pause_resume();
};



#endif // MT_H
