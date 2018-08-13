#include "nvinspector.h"

nvinspector::nvinspector()
{
    path_to_inspector = "";
}


int nvinspector::inspector_init()
{
    QDir dir(".");
    QString possible_path_to_inspector = dir.absolutePath()+QString("/apps/nvidiaInspector.exe");
    QFileInfo possible_inspector_file(possible_path_to_inspector);
    if (possible_inspector_file.exists() && possible_inspector_file.isFile())
    {
        // add quotes to nvidia inspector path, due to spaces issue
        path_to_inspector =  QString("\"")+possible_path_to_inspector+QString("\"");
        return 0;
    }
    else
    {
        return -1;
    }
}


int nvinspector::core_offset(int index, int pstate, int offset)
{
    // create the nvidia inspector process
    QProcess nvinspector_process;
    // arguments to nvidia inspector command
    QStringList args;
    args << "-setBaseClockOffset:"+QString::number(index)+","+QString::number(pstate)+","+QString::number(offset);
    // start the nvidia inspector process
    nvinspector_process.start(path_to_inspector, args);
    nvinspector_process.waitForFinished();
    return 0;
}


int nvinspector::mem_offset(int index, int pstate, int offset)
{
    // create the nvidia inspector process
    QProcess nvinspector_process;
    // arguments to nvidia inspector command
    QStringList args;
    args << "-setMemoryClockOffset:"+QString::number(index)+","+QString::number(pstate)+","+QString::number(offset);
    // start the nvidia inspector process
    nvinspector_process.start(path_to_inspector, args);
    nvinspector_process.waitForFinished();
    return 0;
}


int nvinspector::core_mem_offset(int index, int pstate, int core_offset, int mem_offset)
{
    // create the nvidia inspector process
    QProcess nvinspector_process;
    // arguments to nvidia inspector command
    QStringList args;
    args << "-setBaseClockOffset:"+QString::number(index)+","+QString::number(pstate)+","+QString::number(core_offset)
         << "-setMemoryClockOffset:"+QString::number(index)+","+QString::number(pstate)+","+QString::number(mem_offset);
    // start the nvidia inspector process
    nvinspector_process.start(path_to_inspector, args);
    nvinspector_process.waitForFinished();
    return 0;
}
