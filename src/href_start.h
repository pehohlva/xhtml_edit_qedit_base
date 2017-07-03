#ifndef HREF_START_H
#define HREF_START_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>

class Ui_Href_Gui
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *vboxLayout1;
    QLineEdit *text_href;
    QLineEdit *url_href;
    QComboBox *target_href;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem1;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Href_Gui)
    {
    Href_Gui->setObjectName(QString::fromUtf8("Href_Gui"));
    Href_Gui->resize(QSize(420, 140).expandedTo(Href_Gui->minimumSizeHint()));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(Href_Gui->sizePolicy().hasHeightForWidth());
    Href_Gui->setSizePolicy(sizePolicy);
    Href_Gui->setMinimumSize(QSize(420, 140));
    Href_Gui->setMaximumSize(QSize(420, 140));
    gridLayout = new QGridLayout(Href_Gui);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem, 1, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    vboxLayout = new QVBoxLayout();
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(0);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    label = new QLabel(Href_Gui);
    label->setObjectName(QString::fromUtf8("label"));
    label->setTextFormat(Qt::PlainText);

    vboxLayout->addWidget(label);

    label_2 = new QLabel(Href_Gui);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setTextFormat(Qt::PlainText);

    vboxLayout->addWidget(label_2);

    label_3 = new QLabel(Href_Gui);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setTextFormat(Qt::PlainText);

    vboxLayout->addWidget(label_3);


    hboxLayout->addLayout(vboxLayout);

    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setSpacing(6);
    vboxLayout1->setMargin(0);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    text_href = new QLineEdit(Href_Gui);
    text_href->setObjectName(QString::fromUtf8("text_href"));

    vboxLayout1->addWidget(text_href);

    url_href = new QLineEdit(Href_Gui);
    url_href->setObjectName(QString::fromUtf8("url_href"));
    QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(url_href->sizePolicy().hasHeightForWidth());
    url_href->setSizePolicy(sizePolicy1);
    url_href->setMinimumSize(QSize(355, 18));

    vboxLayout1->addWidget(url_href);

    target_href = new QComboBox(Href_Gui);
    target_href->setObjectName(QString::fromUtf8("target_href"));

    vboxLayout1->addWidget(target_href);


    hboxLayout->addLayout(vboxLayout1);


    gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    spacerItem1 = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem1);

    okButton = new QPushButton(Href_Gui);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout1->addWidget(okButton);

    cancelButton = new QPushButton(Href_Gui);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

    hboxLayout1->addWidget(cancelButton);


    gridLayout->addLayout(hboxLayout1, 2, 0, 1, 1);

    retranslateUi(Href_Gui);
  

    QMetaObject::connectSlotsByName(Href_Gui);
    } // setupUi

    void retranslateUi(QDialog *Href_Gui)
    {
    Href_Gui->setWindowTitle(QApplication::translate("Href_Gui", "Url / www", 0, 0));
    label->setText(QApplication::translate("Href_Gui", "Text:", 0, 0));
    label_2->setText(QApplication::translate("Href_Gui", "Url:", 0, 0));
    label_3->setText(QApplication::translate("Href_Gui", "Target / Name:", 0, 0));
    target_href->clear();
    target_href->addItem(QApplication::translate("Href_Gui", "_top", 0, 0));
    target_href->addItem(QApplication::translate("Href_Gui", "_self", 0, 0));
    target_href->addItem(QApplication::translate("Href_Gui", "_blank", 0, 0));
    target_href->addItem(QApplication::translate("Href_Gui", "_main", 0, 0));
    target_href->addItem(QApplication::translate("Href_Gui", "_menu", 0, 0));
    target_href->addItem(QApplication::translate("Href_Gui", "#name", 0, 0));
    okButton->setText(QApplication::translate("Href_Gui", "OK", 0, 0));
    cancelButton->setText(QApplication::translate("Href_Gui", "Cancel", 0, 0));
    Q_UNUSED(Href_Gui);
    } // retranslateUi

};

namespace Ui {
    class Href_Gui: public Ui_Href_Gui {};
} // namespace Ui

#endif // HREF_START_H
