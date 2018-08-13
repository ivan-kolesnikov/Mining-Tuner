/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_log
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *log)
    {
        if (log->objectName().isEmpty())
            log->setObjectName(QStringLiteral("log"));
        log->resize(507, 362);
        verticalLayout = new QVBoxLayout(log);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(log);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(log);

        QMetaObject::connectSlotsByName(log);
    } // setupUi

    void retranslateUi(QWidget *log)
    {
        log->setWindowTitle(QApplication::translate("log", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class log: public Ui_log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
