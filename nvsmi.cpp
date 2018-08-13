#include "nvsmi.h"

nvsmi::nvsmi()
{
    path_to_application = "";
}


//get nvidia-smi path and check the application
int nvsmi::smi_init()
{
    // get the system disk letter
    QString system_disk = QStorageInfo::root().rootPath();
    // the command should be wrapped in quotes as the path to nvidia-smi contain spaces
    QString path_to_nvsmi = QString("\"")+system_disk+
            QString("Program Files/NVIDIA Corporation/NVSMI/nvidia-smi.exe")+QString("\"");
    // create the nvidia-smi process
    QProcess test_nvsmi_process;
    // start nvidia-smi application to check it
    test_nvsmi_process.start(path_to_nvsmi);
    // wait while the application will be executed to collect the output log
    test_nvsmi_process.waitForFinished();
    QString nvsmi_output = QString::fromLocal8Bit(test_nvsmi_process.readAllStandardOutput());
    // non empty output means correct path to nvidia-smi
    if (nvsmi_output.isEmpty())
    {
        return -1;
    }
    else
    {
        // path to the nvidia-smi application has been found
        path_to_application = path_to_nvsmi;
        return 0;
    }
}


int nvsmi::get_value(QString query, int index)
{
    // create the nvidia-smi process
    QProcess nvsmi_process;
    // arguments for nvidia-smi command
    QStringList args;
    args << "--format=csv,noheader,nounits" << "--query-gpu="+query << "--id="+QString::number(index);
    // start the process with necessary parameters
    nvsmi_process.start(path_to_application,args);
    nvsmi_process.waitForFinished();
    // collect the output from nvidia-smi
    QString nvsmi_output = QString::fromLocal8Bit(nvsmi_process.readAllStandardOutput());
    // create the digit re
    QRegExp re_digit("\\d*");
    // if the output contain not only digits
    if (!re_digit.exactMatch(nvsmi_output))
    {
        // reaise the error
        return -1;
    }
    return nvsmi_output.toInt();
}


QString nvsmi::get_string(QString query, int index)
{
    // create the nvidia-smi process
    QProcess nvsmi_process;
    // arguments for nvidia-smi command
    QStringList args;
    args << "--format=csv,noheader,nounits" << "--query-gpu="+query << "--id="+QString::number(index);
    // start the process with necessary parameters
    nvsmi_process.start(path_to_application,args);
    nvsmi_process.waitForFinished();
    // collect the output from nvidia-smi
    QString nvsmi_output = QString::fromLocal8Bit(nvsmi_process.readAllStandardOutput());
    // remove white spaces from the output
    return nvsmi_output.trimmed();
}


int nvsmi::set_power_limit(int index, int new_limit)
{
    // create the nvidia-smi process
    QProcess nvsmi_process;
    // arguments for nvidia-smi command
    QStringList args;
    args << "--power-limit="+QString::number(new_limit) << "--id="+QString::number(index);
    // start the process with necessary parameters
    nvsmi_process.start(path_to_application,args);
    nvsmi_process.waitForFinished();
    // wait while changes will apply
    my_msleep(100);
    // check the actual power limit
    if (new_limit != get_value(cst_cur_power_limit, index))
    {
        return -1;
    }
    return 0;
}

void nvsmi::my_msleep(int msec)
{
    QTime dieTime= QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
