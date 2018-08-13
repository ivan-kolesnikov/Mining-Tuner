/********************************************************************************
** Form generated from reading UI file 'mt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MT_H
#define UI_MT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MT
{
public:
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_14;
    QComboBox *cb_card_index;
    QLabel *lbl_card_name;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_16;
    QLCDNumber *display_power;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *label_12;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QLCDNumber *display_maximum_core;
    QLCDNumber *display_maximum_memory;
    QLCDNumber *display_maximum_pl;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_10;
    QLCDNumber *display_current_core;
    QLCDNumber *display_current_memory;
    QLCDNumber *display_current_pl;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_9;
    QSpinBox *sb_core_offset;
    QPushButton *btn_offset_core;
    QVBoxLayout *verticalLayout_10;
    QSpinBox *sb_mem_offset;
    QPushButton *btn_offset_mem;
    QVBoxLayout *verticalLayout_12;
    QSpinBox *sb_pow_limit;
    QPushButton *btn_set_pl;
    QVBoxLayout *verticalLayout_13;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btn_apply_all_core_mem_pl;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_start_stop;
    QPushButton *btn_pause_resume;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_min_pl;
    QSpacerItem *horizontalSpacer;
    QLabel *lbl_def_pl;

    void setupUi(QWidget *MT)
    {
        if (MT->objectName().isEmpty())
            MT->setObjectName(QStringLiteral("MT"));
        MT->resize(345, 412);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MT->sizePolicy().hasHeightForWidth());
        MT->setSizePolicy(sizePolicy);
        MT->setStyleSheet(QStringLiteral(""));
        verticalLayout_7 = new QVBoxLayout(MT);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_14 = new QLabel(MT);
        label_14->setObjectName(QStringLiteral("label_14"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_14->setFont(font);
        label_14->setTextFormat(Qt::AutoText);
        label_14->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        verticalLayout_15->addWidget(label_14);

        cb_card_index = new QComboBox(MT);
        cb_card_index->setObjectName(QStringLiteral("cb_card_index"));
        cb_card_index->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_15->addWidget(cb_card_index);


        horizontalLayout_4->addLayout(verticalLayout_15);

        lbl_card_name = new QLabel(MT);
        lbl_card_name->setObjectName(QStringLiteral("lbl_card_name"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbl_card_name->sizePolicy().hasHeightForWidth());
        lbl_card_name->setSizePolicy(sizePolicy2);
        lbl_card_name->setMinimumSize(QSize(135, 40));
        lbl_card_name->setFont(font);
        lbl_card_name->setTextFormat(Qt::AutoText);
        lbl_card_name->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        horizontalLayout_4->addWidget(lbl_card_name);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_16 = new QLabel(MT);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);
        label_16->setMinimumSize(QSize(0, 0));
        label_16->setFont(font);
        label_16->setTextFormat(Qt::AutoText);
        label_16->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        verticalLayout_14->addWidget(label_16);

        display_power = new QLCDNumber(MT);
        display_power->setObjectName(QStringLiteral("display_power"));
        display_power->setMinimumSize(QSize(100, 0));

        verticalLayout_14->addWidget(display_power);


        horizontalLayout_4->addLayout(verticalLayout_14);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(MT);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_2);

        label_12 = new QLabel(MT);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);
        label_12->setTextFormat(Qt::AutoText);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_12);

        label_13 = new QLabel(MT);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);
        label_13->setTextFormat(Qt::AutoText);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_13);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_11 = new QLabel(MT);
        label_11->setObjectName(QStringLiteral("label_11"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);
        label_11->setMinimumSize(QSize(0, 0));
        label_11->setFont(font);
        label_11->setTextFormat(Qt::AutoText);
        label_11->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        verticalLayout_2->addWidget(label_11);

        display_maximum_core = new QLCDNumber(MT);
        display_maximum_core->setObjectName(QStringLiteral("display_maximum_core"));
        display_maximum_core->setLayoutDirection(Qt::LeftToRight);
        display_maximum_core->setSmallDecimalPoint(false);
        display_maximum_core->setSegmentStyle(QLCDNumber::Filled);

        verticalLayout_2->addWidget(display_maximum_core);

        display_maximum_memory = new QLCDNumber(MT);
        display_maximum_memory->setObjectName(QStringLiteral("display_maximum_memory"));
        display_maximum_memory->setLayoutDirection(Qt::LeftToRight);
        display_maximum_memory->setSmallDecimalPoint(false);
        display_maximum_memory->setSegmentStyle(QLCDNumber::Filled);

        verticalLayout_2->addWidget(display_maximum_memory);

        display_maximum_pl = new QLCDNumber(MT);
        display_maximum_pl->setObjectName(QStringLiteral("display_maximum_pl"));
        display_maximum_pl->setLayoutDirection(Qt::LeftToRight);
        display_maximum_pl->setSmallDecimalPoint(false);
        display_maximum_pl->setSegmentStyle(QLCDNumber::Filled);

        verticalLayout_2->addWidget(display_maximum_pl);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_10 = new QLabel(MT);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setTextFormat(Qt::AutoText);
        label_10->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        verticalLayout_3->addWidget(label_10);

        display_current_core = new QLCDNumber(MT);
        display_current_core->setObjectName(QStringLiteral("display_current_core"));
        display_current_core->setLayoutDirection(Qt::LeftToRight);
        display_current_core->setSmallDecimalPoint(false);
        display_current_core->setSegmentStyle(QLCDNumber::Filled);
        display_current_core->setProperty("intValue", QVariant(0));

        verticalLayout_3->addWidget(display_current_core);

        display_current_memory = new QLCDNumber(MT);
        display_current_memory->setObjectName(QStringLiteral("display_current_memory"));
        display_current_memory->setLayoutDirection(Qt::LeftToRight);
        display_current_memory->setStyleSheet(QStringLiteral(""));
        display_current_memory->setSmallDecimalPoint(false);
        display_current_memory->setSegmentStyle(QLCDNumber::Filled);

        verticalLayout_3->addWidget(display_current_memory);

        display_current_pl = new QLCDNumber(MT);
        display_current_pl->setObjectName(QStringLiteral("display_current_pl"));
        display_current_pl->setLayoutDirection(Qt::LeftToRight);
        display_current_pl->setStyleSheet(QStringLiteral(""));
        display_current_pl->setSmallDecimalPoint(false);
        display_current_pl->setSegmentStyle(QLCDNumber::Filled);

        verticalLayout_3->addWidget(display_current_pl);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalSpacer_2 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_8->addItem(verticalSpacer_2);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        sb_core_offset = new QSpinBox(MT);
        sb_core_offset->setObjectName(QStringLiteral("sb_core_offset"));
        sb_core_offset->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sb_core_offset->setMinimum(-99999);
        sb_core_offset->setMaximum(99999);
        sb_core_offset->setSingleStep(1);
        sb_core_offset->setValue(0);
        sb_core_offset->setDisplayIntegerBase(10);

        verticalLayout_9->addWidget(sb_core_offset);

        btn_offset_core = new QPushButton(MT);
        btn_offset_core->setObjectName(QStringLiteral("btn_offset_core"));

        verticalLayout_9->addWidget(btn_offset_core);


        verticalLayout_8->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        sb_mem_offset = new QSpinBox(MT);
        sb_mem_offset->setObjectName(QStringLiteral("sb_mem_offset"));
        sb_mem_offset->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sb_mem_offset->setMinimum(-99999);
        sb_mem_offset->setMaximum(99999);
        sb_mem_offset->setSingleStep(1);
        sb_mem_offset->setValue(0);
        sb_mem_offset->setDisplayIntegerBase(10);

        verticalLayout_10->addWidget(sb_mem_offset);

        btn_offset_mem = new QPushButton(MT);
        btn_offset_mem->setObjectName(QStringLiteral("btn_offset_mem"));

        verticalLayout_10->addWidget(btn_offset_mem);


        verticalLayout_8->addLayout(verticalLayout_10);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        sb_pow_limit = new QSpinBox(MT);
        sb_pow_limit->setObjectName(QStringLiteral("sb_pow_limit"));
        sb_pow_limit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sb_pow_limit->setMinimum(0);
        sb_pow_limit->setMaximum(99999);
        sb_pow_limit->setSingleStep(1);
        sb_pow_limit->setValue(0);
        sb_pow_limit->setDisplayIntegerBase(10);

        verticalLayout_12->addWidget(sb_pow_limit);

        btn_set_pl = new QPushButton(MT);
        btn_set_pl->setObjectName(QStringLiteral("btn_set_pl"));
        btn_set_pl->setAutoRepeatInterval(100);

        verticalLayout_12->addWidget(btn_set_pl);


        verticalLayout_8->addLayout(verticalLayout_12);


        horizontalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalSpacer_3 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_13->addItem(verticalSpacer_3);

        btn_apply_all_core_mem_pl = new QPushButton(MT);
        btn_apply_all_core_mem_pl->setObjectName(QStringLiteral("btn_apply_all_core_mem_pl"));
        btn_apply_all_core_mem_pl->setMinimumSize(QSize(0, 150));
        btn_apply_all_core_mem_pl->setMaximumSize(QSize(20, 16777215));
        btn_apply_all_core_mem_pl->setAutoRepeat(false);
        btn_apply_all_core_mem_pl->setAutoExclusive(false);
        btn_apply_all_core_mem_pl->setFlat(false);

        verticalLayout_13->addWidget(btn_apply_all_core_mem_pl);


        horizontalLayout_2->addLayout(verticalLayout_13);


        verticalLayout_7->addLayout(horizontalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(85, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_17 = new QLabel(MT);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);
        label_17->setMinimumSize(QSize(0, 0));
        label_17->setFont(font);
        label_17->setTextFormat(Qt::AutoText);
        label_17->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_5->addWidget(label_17);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(67, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btn_start_stop = new QPushButton(MT);
        btn_start_stop->setObjectName(QStringLiteral("btn_start_stop"));
        btn_start_stop->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(btn_start_stop);

        btn_pause_resume = new QPushButton(MT);
        btn_pause_resume->setObjectName(QStringLiteral("btn_pause_resume"));

        horizontalLayout_3->addWidget(btn_pause_resume);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_7->addLayout(verticalLayout_5);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbl_min_pl = new QLabel(MT);
        lbl_min_pl->setObjectName(QStringLiteral("lbl_min_pl"));
        lbl_min_pl->setFont(font);
        lbl_min_pl->setTextFormat(Qt::AutoText);
        lbl_min_pl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lbl_min_pl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbl_def_pl = new QLabel(MT);
        lbl_def_pl->setObjectName(QStringLiteral("lbl_def_pl"));
        lbl_def_pl->setFont(font);
        lbl_def_pl->setTextFormat(Qt::AutoText);
        lbl_def_pl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lbl_def_pl);


        verticalLayout_7->addLayout(horizontalLayout);


        retranslateUi(MT);

        QMetaObject::connectSlotsByName(MT);
    } // setupUi

    void retranslateUi(QWidget *MT)
    {
        MT->setWindowTitle(QApplication::translate("MT", "MT", Q_NULLPTR));
        label_14->setText(QApplication::translate("MT", "NVIDIA CARD", Q_NULLPTR));
        lbl_card_name->setText(QApplication::translate("MT", "___________", Q_NULLPTR));
        label_16->setText(QApplication::translate("MT", "POWER", Q_NULLPTR));
        label_2->setText(QApplication::translate("MT", "CORE", Q_NULLPTR));
        label_12->setText(QApplication::translate("MT", "MEMORY", Q_NULLPTR));
        label_13->setText(QApplication::translate("MT", "POW LIMIT", Q_NULLPTR));
        label_11->setText(QApplication::translate("MT", "MAXIMUM", Q_NULLPTR));
        label_10->setText(QApplication::translate("MT", "CURRENT", Q_NULLPTR));
        sb_core_offset->setPrefix(QString());
        btn_offset_core->setText(QApplication::translate("MT", "OFFSET C", Q_NULLPTR));
        sb_mem_offset->setPrefix(QString());
        btn_offset_mem->setText(QApplication::translate("MT", "OFFSET M", Q_NULLPTR));
        sb_pow_limit->setPrefix(QString());
        btn_set_pl->setText(QApplication::translate("MT", "SET PL", Q_NULLPTR));
        btn_apply_all_core_mem_pl->setText(QApplication::translate("MT", ">", Q_NULLPTR));
        label_17->setText(QApplication::translate("MT", "TUNING", Q_NULLPTR));
        btn_start_stop->setText(QApplication::translate("MT", "START", Q_NULLPTR));
        btn_pause_resume->setText(QApplication::translate("MT", "PAUSE", Q_NULLPTR));
        lbl_min_pl->setText(QApplication::translate("MT", "MIN POW LIMIT 0", Q_NULLPTR));
        lbl_def_pl->setText(QApplication::translate("MT", "DEFAULT POW LIMIT 0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MT: public Ui_MT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MT_H
