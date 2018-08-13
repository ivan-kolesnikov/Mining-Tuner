/********************************************************************************
** Form generated from reading UI file 'logger.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGER_H
#define UI_LOGGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logger
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *te_log;

    void setupUi(QWidget *logger)
    {
        if (logger->objectName().isEmpty())
            logger->setObjectName(QStringLiteral("logger"));
        logger->resize(293, 412);
        verticalLayout = new QVBoxLayout(logger);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        te_log = new QTextEdit(logger);
        te_log->setObjectName(QStringLiteral("te_log"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        te_log->setFont(font);

        verticalLayout->addWidget(te_log);


        retranslateUi(logger);

        QMetaObject::connectSlotsByName(logger);
    } // setupUi

    void retranslateUi(QWidget *logger)
    {
        logger->setWindowTitle(QApplication::translate("logger", "Log", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class logger: public Ui_logger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGER_H
