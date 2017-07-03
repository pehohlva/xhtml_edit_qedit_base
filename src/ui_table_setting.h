/********************************************************************************
** Form generated from reading ui file 'table_setting.ui'
**
** Created: Thu 22. Feb 10:01:18 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TABLE_SETTING_H
#define UI_TABLE_SETTING_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QDialog>
#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QSpinBox>
#include <QToolButton>

class Ui_Table_Setting
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QHBoxLayout *hboxLayout;
    QLabel *label_3;
    QSpinBox *vborder;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout1;
    QLabel *label_6;
    QSpinBox *largotable;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout2;
    QLabel *label;
    QDoubleSpinBox *tapadding;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout3;
    QLabel *label_5;
    QComboBox *xalign;
    QSpacerItem *spacerItem3;
    QHBoxLayout *hboxLayout4;
    QLabel *label_2;
    QDoubleSpinBox *taspacing;
    QSpacerItem *spacerItem4;
    QHBoxLayout *hboxLayout5;
    QLabel *label_4;
    QToolButton *tablecolor;
    QSpacerItem *spacerItem5;
    QHBoxLayout *hboxLayout6;
    QSpacerItem *spacerItem6;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Table_Setting)
    {
    Table_Setting->setObjectName(QString::fromUtf8("Table_Setting"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(0));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(Table_Setting->sizePolicy().hasHeightForWidth());
    Table_Setting->setSizePolicy(sizePolicy);
    Table_Setting->setMinimumSize(QSize(16, 280));
    Table_Setting->setMaximumSize(QSize(16777215, 280));
    Table_Setting->setWindowIcon(QIcon(QString::fromUtf8(":/img/table.png")));
    gridLayout = new QGridLayout(Table_Setting);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox = new QGroupBox(Table_Setting);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout1 = new QGridLayout(groupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setTextFormat(Qt::PlainText);

    hboxLayout->addWidget(label_3);

    vborder = new QSpinBox(groupBox);
    vborder->setObjectName(QString::fromUtf8("vborder"));

    hboxLayout->addWidget(vborder);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);


    gridLayout1->addLayout(hboxLayout, 1, 0, 1, 1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    label_6 = new QLabel(groupBox);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setTextFormat(Qt::PlainText);

    hboxLayout1->addWidget(label_6);

    largotable = new QSpinBox(groupBox);
    largotable->setObjectName(QString::fromUtf8("largotable"));
    largotable->setMaximum(100);
    largotable->setMinimum(10);
    largotable->setValue(10);

    hboxLayout1->addWidget(largotable);

    spacerItem1 = new QSpacerItem(282, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem1);


    gridLayout1->addLayout(hboxLayout1, 0, 0, 1, 1);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));
    label->setTextFormat(Qt::PlainText);

    hboxLayout2->addWidget(label);

    tapadding = new QDoubleSpinBox(groupBox);
    tapadding->setObjectName(QString::fromUtf8("tapadding"));
    tapadding->setDecimals(1);
    tapadding->setMaximum(10);

    hboxLayout2->addWidget(tapadding);

    spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem2);


    gridLayout1->addLayout(hboxLayout2, 2, 0, 1, 1);

    hboxLayout3 = new QHBoxLayout();
    hboxLayout3->setSpacing(6);
    hboxLayout3->setMargin(0);
    hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
    label_5 = new QLabel(groupBox);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setTextFormat(Qt::PlainText);

    hboxLayout3->addWidget(label_5);

    xalign = new QComboBox(groupBox);
    xalign->setObjectName(QString::fromUtf8("xalign"));

    hboxLayout3->addWidget(xalign);

    spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout3->addItem(spacerItem3);


    gridLayout1->addLayout(hboxLayout3, 5, 0, 1, 1);

    hboxLayout4 = new QHBoxLayout();
    hboxLayout4->setSpacing(6);
    hboxLayout4->setMargin(0);
    hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setTextFormat(Qt::PlainText);

    hboxLayout4->addWidget(label_2);

    taspacing = new QDoubleSpinBox(groupBox);
    taspacing->setObjectName(QString::fromUtf8("taspacing"));
    taspacing->setDecimals(1);
    taspacing->setMaximum(10);

    hboxLayout4->addWidget(taspacing);

    spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout4->addItem(spacerItem4);


    gridLayout1->addLayout(hboxLayout4, 3, 0, 1, 1);

    hboxLayout5 = new QHBoxLayout();
    hboxLayout5->setSpacing(6);
    hboxLayout5->setMargin(0);
    hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setTextFormat(Qt::PlainText);

    hboxLayout5->addWidget(label_4);

    tablecolor = new QToolButton(groupBox);
    tablecolor->setObjectName(QString::fromUtf8("tablecolor"));

    hboxLayout5->addWidget(tablecolor);

    spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout5->addItem(spacerItem5);


    gridLayout1->addLayout(hboxLayout5, 4, 0, 1, 1);


    gridLayout->addWidget(groupBox, 0, 0, 1, 1);

    hboxLayout6 = new QHBoxLayout();
    hboxLayout6->setSpacing(6);
    hboxLayout6->setMargin(0);
    hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
    spacerItem6 = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout6->addItem(spacerItem6);

    okButton = new QPushButton(Table_Setting);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout6->addWidget(okButton);

    cancelButton = new QPushButton(Table_Setting);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

    hboxLayout6->addWidget(cancelButton);


    gridLayout->addLayout(hboxLayout6, 1, 0, 1, 1);


    retranslateUi(Table_Setting);

    QSize size(561, 280);
    size = size.expandedTo(Table_Setting->minimumSizeHint());
    Table_Setting->resize(size);

    QObject::connect(okButton, SIGNAL(clicked()), Table_Setting, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), Table_Setting, SLOT(reject()));

    QMetaObject::connectSlotsByName(Table_Setting);
    } // setupUi

    void retranslateUi(QDialog *Table_Setting)
    {
    Table_Setting->setWindowTitle(QApplication::translate("Table_Setting", "Table setting & Propriety", 0, 0));
    groupBox->setTitle(QApplication::translate("Table_Setting", "Table setting:", 0, 0));
    label_3->setText(QApplication::translate("Table_Setting", "Border:", 0, 0));
    label_6->setText(QApplication::translate("Table_Setting", "Table setting widht:", 0, 0));
    largotable->setSuffix(QApplication::translate("Table_Setting", "%", 0, 0));
    largotable->setPrefix(QString());
    label->setText(QApplication::translate("Table_Setting", "CellPadding:", 0, 0));
    label_5->setText(QApplication::translate("Table_Setting", "Table Align:", 0, 0));
    label_2->setText(QApplication::translate("Table_Setting", "CellSpacing:", 0, 0));
    label_4->setText(QApplication::translate("Table_Setting", "BackgroundColor:", 0, 0));
    tablecolor->setText(QApplication::translate("Table_Setting", "...", 0, 0));
    okButton->setText(QApplication::translate("Table_Setting", "OK", 0, 0));
    cancelButton->setText(QApplication::translate("Table_Setting", "Cancel", 0, 0));
    Q_UNUSED(Table_Setting);
    } // retranslateUi

};

namespace Ui {
    class Table_Setting: public Ui_Table_Setting {};
} // namespace Ui

#endif // UI_TABLE_SETTING_H
