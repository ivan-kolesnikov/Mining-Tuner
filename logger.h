#ifndef LOGGER_H
#define LOGGER_H

#include <QWidget>
#include <QString>
#include <QList>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPoint>

namespace Ui {
class logger;
}

class logger : public QWidget
{
    Q_OBJECT

public:
    explicit logger(QWidget *parent = 0);
    ~logger();
    void append(QString name, QList<QString> header, QList<QString> line);
    void pos_init(QPoint main_app_pos, int x_pos_offset);

private:
    Ui::logger *ui;
    void keyPressEvent(QKeyEvent* event);
    void focus_settings();
};

#endif // LOGGER_H
