#ifndef NVINSPECTOR_H
#define NVINSPECTOR_H
#include <QString>
#include <QDir>
#include <QFileInfo>
#include <QProcess>

class nvinspector
{
public:
    nvinspector();
    int inspector_init();
    int core_offset(int index, int pstate, int offset);
    int mem_offset(int index, int pstate, int offset);
    int core_mem_offset(int index, int pstate, int core_offset, int mem_offset);
private:
    QString path_to_inspector;
};

#endif // NVINSPECTOR_H
