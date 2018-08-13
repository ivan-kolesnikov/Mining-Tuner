#include "mt.h"
#include <QApplication>
#include <QString>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    // application name and version
    QString app_name = "MiningTuner 1.0";
    // time to stay on the one tuning iteration
    int iter_time_s = 30;
    int iter_wait_time_s = 5;
    QApplication a(argc, argv);
    MT miningTuner(iter_time_s, iter_wait_time_s, app_name);
    // raise error if nvidiasmi application did not found
    if (miningTuner.nvsmi_init() == -1)
    {
        // show critical error form
        QMessageBox::critical(0, app_name, QString("nvidia-smi.exe did't found"));
        return 1;
    }
    // raise error if nvidia inspector did not found
    if (miningTuner.nvinspector_init() == -1)
    {
        // show critical error form
        QMessageBox::critical(0, app_name, QString("nvidiaInspector.exe did't found"));
        return 1;
    }
    miningTuner.show();
    // start work with the first card from the checkbox
    miningTuner.gpu_index_changed();
    // start visualization
    miningTuner.update_displays();
    // move the log window
    miningTuner.change_log_window_pos(miningTuner.pos(), -300);
    miningTuner.visualization_tm.start(5000);
    return a.exec();
}
