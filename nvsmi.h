#ifndef NVSMI_H
#define NVSMI_H
#include <QString>
#include <QStringList>
#include <QStorageInfo>
#include <QProcess>
#include <QRegExp>
#include <QThread>
#include <QTime>
#include <QCoreApplication>

class nvsmi
{
public:
    nvsmi();
    int smi_init();
    int get_value(QString query, int index);
    QString get_string(QString query, int index);
    int set_power_limit(int index, int new_limit);

    // INT nvidia-smi constants
    const QString cst_cur_core = "clocks.current.sm";
    const QString cst_cur_mem = "clocks.current.memory";
    const QString cst_cur_power = "power.draw";
    const QString cst_cur_power_limit = "power.limit";
    const QString cst_max_power_limit = "power.max_limit";
    const QString cst_max_core = "clocks.max.sm";
    const QString cst_max_mem = "clocks.max.memory";
    const QString cst_min_power_limit = "power.min_limit";
    const QString cst_def_power_limit = "power.default_limit";
    // STRING nvidia-smi constants
    const QString cst_gpu_name = "name";

private:
    QString path_to_application;
    // sleep in main thread without gui freezing
    void my_msleep(int msec);
};

#endif // NVSMI_H
