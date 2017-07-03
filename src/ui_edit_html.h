/********************************************************************************
** Form generated from reading ui file 'edit_html.ui'
**
** Created: Thu 15. Mar 00:14:01 2007
**      by: Qt User Interface Compiler version 4.2.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_EDIT_HTML_H
#define UI_EDIT_HTML_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QFontComboBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QTabWidget>
#include <QTextEdit>
#include <QToolButton>
#include <QWidget>
#include "qvimedit.h"

class Ui_Edit_html
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout1;
    QVimedit *wtext;
    QWidget *tab_2;
    QGridLayout *gridLayout2;
    QHBoxLayout *hboxLayout;
    QTextEdit *sline;
    QTextEdit *stext;
    QHBoxLayout *hboxLayout1;
    QComboBox *list_ul;
    QFontComboBox *fontname;
    QComboBox *fontsize;
    QToolButton *vol_color;
    QToolButton *vol_br;
    QToolButton *vol_img;
    QToolButton *val_table;
    QPushButton *savecache;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout2;
    QToolButton *vol_print;
    QToolButton *vol_pdf;
    QToolButton *vol_html;
    QToolButton *vol_undo;
    QToolButton *vol_redo;
    QToolButton *vol_cut;
    QToolButton *vol_copy;
    QToolButton *mypaste;
    QToolButton *vol_link;
    QToolButton *vol_bold;
    QToolButton *vol_italic;
    QToolButton *vol_underline;
    QToolButton *vol_left;
    QToolButton *vol_center;
    QToolButton *vol_right;
    QToolButton *vol_justify;
    QToolButton *vol_source;
    QSpacerItem *spacerItem1;

    void setupUi(QWidget *Edit_html)
    {
    Edit_html->setObjectName(QString::fromUtf8("Edit_html"));
    gridLayout = new QGridLayout(Edit_html);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(9);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    tabWidget = new QTabWidget(Edit_html);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    gridLayout1 = new QGridLayout(tab);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(9);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    wtext = new QVimedit(tab);
    wtext->setObjectName(QString::fromUtf8("wtext"));
    wtext->setAcceptDrops(false);
    wtext->setReadOnly(false);
    wtext->setOpenExternalLinks(true);

    gridLayout1->addWidget(wtext, 0, 0, 1, 1);

    tabWidget->addTab(tab, QIcon(QString::fromUtf8(":/img/icon.png")), QApplication::translate("Edit_html", "Edit and View", 0,0));
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    gridLayout2 = new QGridLayout(tab_2);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(9);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    sline = new QTextEdit(tab_2);
    sline->setObjectName(QString::fromUtf8("sline"));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(sline->sizePolicy().hasHeightForWidth());
    sline->setSizePolicy(sizePolicy);
    sline->setMinimumSize(QSize(75, 0));
    sline->setMaximumSize(QSize(75, 16777215));
    QPalette palette;
    QBrush brush(QColor(208, 208, 208, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Light, brush);
    QBrush brush1(QColor(0, 0, 0, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    QBrush brush2(QColor(223, 223, 223, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Base, brush2);
    QBrush brush3(QColor(0, 0, 0, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
    QBrush brush4(QColor(208, 208, 208, 255));
    brush4.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::Light, brush4);
    QBrush brush5(QColor(0, 0, 0, 255));
    brush5.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
    QBrush brush6(QColor(223, 223, 223, 255));
    brush6.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
    QBrush brush7(QColor(0, 0, 0, 255));
    brush7.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush7);
    QBrush brush8(QColor(208, 208, 208, 255));
    brush8.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::Light, brush8);
    QBrush brush9(QColor(0, 0, 0, 255));
    brush9.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush9);
    QBrush brush10(QColor(235, 233, 237, 255));
    brush10.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush10);
    QBrush brush11(QColor(0, 0, 0, 255));
    brush11.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush11);
    sline->setPalette(palette);
    sline->setCursor(QCursor(static_cast<Qt::CursorShape>(14)));
    sline->setFrameShadow(QFrame::Raised);
    sline->setReadOnly(true);

    hboxLayout->addWidget(sline);

    stext = new QTextEdit(tab_2);
    stext->setObjectName(QString::fromUtf8("stext"));
    stext->setAutoFormatting(QTextEdit::AutoAll);
    stext->setAcceptRichText(false);

    hboxLayout->addWidget(stext);


    gridLayout2->addLayout(hboxLayout, 0, 0, 1, 1);

    tabWidget->addTab(tab_2, QIcon(QString::fromUtf8(":/img/view-source.png")), QApplication::translate("Edit_html", "Source View", 0, 0));

    gridLayout->addWidget(tabWidget, 2, 0, 1, 1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    list_ul = new QComboBox(Edit_html);
    list_ul->setObjectName(QString::fromUtf8("list_ul"));

    hboxLayout1->addWidget(list_ul);

    fontname = new QFontComboBox(Edit_html);
    fontname->setObjectName(QString::fromUtf8("fontname"));

    hboxLayout1->addWidget(fontname);

    fontsize = new QComboBox(Edit_html);
    fontsize->setObjectName(QString::fromUtf8("fontsize"));

    hboxLayout1->addWidget(fontsize);

    vol_color = new QToolButton(Edit_html);
    vol_color->setObjectName(QString::fromUtf8("vol_color"));
    vol_color->setIcon(QIcon(QString::fromUtf8(":/img/info.png")));
    vol_color->setIconSize(QSize(22, 22));

    hboxLayout1->addWidget(vol_color);

    vol_br = new QToolButton(Edit_html);
    vol_br->setObjectName(QString::fromUtf8("vol_br"));
    vol_br->setIcon(QIcon(QString::fromUtf8(":/img/document.png")));
    vol_br->setIconSize(QSize(22, 22));

    hboxLayout1->addWidget(vol_br);

    vol_img = new QToolButton(Edit_html);
    vol_img->setObjectName(QString::fromUtf8("vol_img"));
    vol_img->setIcon(QIcon(QString::fromUtf8(":/img/pictures.png")));
    vol_img->setIconSize(QSize(22, 22));

    hboxLayout1->addWidget(vol_img);

    val_table = new QToolButton(Edit_html);
    val_table->setObjectName(QString::fromUtf8("val_table"));
    val_table->setIcon(QIcon(QString::fromUtf8(":/img/table.png")));
    val_table->setIconSize(QSize(22, 22));

    hboxLayout1->addWidget(val_table);

    savecache = new QPushButton(Edit_html);
    savecache->setObjectName(QString::fromUtf8("savecache"));
    savecache->setIcon(QIcon(QString::fromUtf8(":/img/filesave.png")));
    savecache->setIconSize(QSize(22, 22));

    hboxLayout1->addWidget(savecache);

    spacerItem = new QSpacerItem(141, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem);


    gridLayout->addLayout(hboxLayout1, 1, 0, 1, 1);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setSpacing(6);
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    vol_print = new QToolButton(Edit_html);
    vol_print->setObjectName(QString::fromUtf8("vol_print"));
    vol_print->setIcon(QIcon(QString::fromUtf8(":/img/fileprint.png")));
    vol_print->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_print);

    vol_pdf = new QToolButton(Edit_html);
    vol_pdf->setObjectName(QString::fromUtf8("vol_pdf"));
    vol_pdf->setIcon(QIcon(QString::fromUtf8(":/img/exportpdf.png")));
    vol_pdf->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_pdf);

    vol_html = new QToolButton(Edit_html);
    vol_html->setObjectName(QString::fromUtf8("vol_html"));
    vol_html->setIcon(QIcon(QString::fromUtf8(":/img/filesave.png")));
    vol_html->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_html);

    vol_undo = new QToolButton(Edit_html);
    vol_undo->setObjectName(QString::fromUtf8("vol_undo"));
    vol_undo->setIcon(QIcon(QString::fromUtf8(":/img/editundo.png")));
    vol_undo->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_undo);

    vol_redo = new QToolButton(Edit_html);
    vol_redo->setObjectName(QString::fromUtf8("vol_redo"));
    vol_redo->setIcon(QIcon(QString::fromUtf8(":/img/editredo.png")));
    vol_redo->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_redo);

    vol_cut = new QToolButton(Edit_html);
    vol_cut->setObjectName(QString::fromUtf8("vol_cut"));
    vol_cut->setIcon(QIcon(QString::fromUtf8(":/img/cut.png")));
    vol_cut->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_cut);

    vol_copy = new QToolButton(Edit_html);
    vol_copy->setObjectName(QString::fromUtf8("vol_copy"));
    vol_copy->setIcon(QIcon(QString::fromUtf8(":/img/copy.png")));
    vol_copy->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_copy);

    mypaste = new QToolButton(Edit_html);
    mypaste->setObjectName(QString::fromUtf8("mypaste"));
    mypaste->setIcon(QIcon(QString::fromUtf8(":/img/paste.png")));
    mypaste->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(mypaste);

    vol_link = new QToolButton(Edit_html);
    vol_link->setObjectName(QString::fromUtf8("vol_link"));
    vol_link->setIcon(QIcon(QString::fromUtf8(":/img/link.png")));
    vol_link->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_link);

    vol_bold = new QToolButton(Edit_html);
    vol_bold->setObjectName(QString::fromUtf8("vol_bold"));
    vol_bold->setIcon(QIcon(QString::fromUtf8(":/img/textbold.png")));
    vol_bold->setIconSize(QSize(22, 22));
    vol_bold->setCheckable(true);

    hboxLayout2->addWidget(vol_bold);

    vol_italic = new QToolButton(Edit_html);
    vol_italic->setObjectName(QString::fromUtf8("vol_italic"));
    vol_italic->setIcon(QIcon(QString::fromUtf8(":/img/textitalic.png")));
    vol_italic->setIconSize(QSize(22, 22));
    vol_italic->setCheckable(true);

    hboxLayout2->addWidget(vol_italic);

    vol_underline = new QToolButton(Edit_html);
    vol_underline->setObjectName(QString::fromUtf8("vol_underline"));
    vol_underline->setIcon(QIcon(QString::fromUtf8(":/img/textunder.png")));
    vol_underline->setIconSize(QSize(22, 22));
    vol_underline->setCheckable(true);

    hboxLayout2->addWidget(vol_underline);

    vol_left = new QToolButton(Edit_html);
    vol_left->setObjectName(QString::fromUtf8("vol_left"));
    vol_left->setIcon(QIcon(QString::fromUtf8(":/img/textleft.png")));
    vol_left->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_left);

    vol_center = new QToolButton(Edit_html);
    vol_center->setObjectName(QString::fromUtf8("vol_center"));
    vol_center->setIcon(QIcon(QString::fromUtf8(":/img/textcenter.png")));
    vol_center->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_center);

    vol_right = new QToolButton(Edit_html);
    vol_right->setObjectName(QString::fromUtf8("vol_right"));
    vol_right->setIcon(QIcon(QString::fromUtf8(":/img/textright.png")));
    vol_right->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_right);

    vol_justify = new QToolButton(Edit_html);
    vol_justify->setObjectName(QString::fromUtf8("vol_justify"));
    vol_justify->setIcon(QIcon(QString::fromUtf8(":/img/textjustify.png")));
    vol_justify->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_justify);

    vol_source = new QToolButton(Edit_html);
    vol_source->setObjectName(QString::fromUtf8("vol_source"));
    vol_source->setIcon(QIcon(QString::fromUtf8(":/img/view-source.png")));
    vol_source->setIconSize(QSize(22, 22));
    vol_source->setCheckable(true);

    hboxLayout2->addWidget(vol_source);

    spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem1);


    gridLayout->addLayout(hboxLayout2, 0, 0, 1, 1);


    retranslateUi(Edit_html);

    QSize size(622, 485);
    size = size.expandedTo(Edit_html->minimumSizeHint());
    Edit_html->resize(size);


    tabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(Edit_html);
    } // setupUi

    void retranslateUi(QWidget *Edit_html)
    {
    Edit_html->setWindowTitle(QApplication::translate("Edit_html", "Form", 0, 0));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Edit_html", "Edit and View", 0, 0));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Edit_html", "Source View", 0, 0));
    list_ul->clear();
    list_ul->addItem(QIcon(QString::fromUtf8(":/img/unordered-list.png")), QApplication::translate("Edit_html", "New Item", 0, 0));
    fontsize->clear();
    fontsize->addItem(QApplication::translate("Edit_html", "12", 0, 0));
    fontsize->addItem(QApplication::translate("Edit_html", "15", 0, 0));
    vol_color->setToolTip(QApplication::translate("Edit_html", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Font color</p></body></html>", 0, 0));
    vol_color->setWhatsThis(QApplication::translate("Edit_html", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">Font color</p></body></html>", 0, 0));
    vol_color->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_br->setToolTip(QApplication::translate("Edit_html", "Break Line", 0, 0));
    vol_br->setStatusTip(QApplication::translate("Edit_html", "Break Line", 0, 0));
    vol_br->setWhatsThis(QApplication::translate("Edit_html", "Break Line", 0, 0));
    vol_br->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_img->setToolTip(QApplication::translate("Edit_html", "New Image", 0, 0));
    vol_img->setStatusTip(QApplication::translate("Edit_html", "New Image", 0, 0));
    vol_img->setWhatsThis(QApplication::translate("Edit_html", "New Image", 0, 0));
    vol_img->setText(QApplication::translate("Edit_html", "...", 0, 0));
    val_table->setToolTip(QApplication::translate("Edit_html", "New Table", 0, 0));
    val_table->setStatusTip(QApplication::translate("Edit_html", "New Table", 0, 0));
    val_table->setWhatsThis(QApplication::translate("Edit_html", "New Table", 0, 0));
    val_table->setText(QApplication::translate("Edit_html", "...", 0, 0));
    savecache->setText(QApplication::translate("Edit_html", "Save HTML ", 0, 0));
    vol_print->setToolTip(QApplication::translate("Edit_html", "Print File", 0, 0));
    vol_print->setStatusTip(QApplication::translate("Edit_html", "Print File", 0, 0));
    vol_print->setWhatsThis(QApplication::translate("Edit_html", "Print File", 0, 0));
    vol_print->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_pdf->setToolTip(QApplication::translate("Edit_html", "Export as PDF", 0, 0));
    vol_pdf->setStatusTip(QApplication::translate("Edit_html", "Export as PDF", 0, 0));
    vol_pdf->setWhatsThis(QApplication::translate("Edit_html", "Export as PDF", 0, 0));
    vol_pdf->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_html->setToolTip(QApplication::translate("Edit_html", "Export as html", 0, 0));
    vol_html->setStatusTip(QApplication::translate("Edit_html", "Export as html", 0, 0));
    vol_html->setWhatsThis(QApplication::translate("Edit_html", "Export as html", 0, 0));
    vol_html->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_undo->setToolTip(QApplication::translate("Edit_html", "Undo", 0, 0));
    vol_undo->setStatusTip(QApplication::translate("Edit_html", "Undo", 0, 0));
    vol_undo->setWhatsThis(QApplication::translate("Edit_html", "Undo", 0, 0));
    vol_undo->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_redo->setToolTip(QApplication::translate("Edit_html", "Redo", 0, 0));
    vol_redo->setStatusTip(QApplication::translate("Edit_html", "Redo", 0, 0));
    vol_redo->setWhatsThis(QApplication::translate("Edit_html", "Redo", 0, 0));
    vol_redo->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_cut->setToolTip(QApplication::translate("Edit_html", "Cut", 0, 0));
    vol_cut->setStatusTip(QApplication::translate("Edit_html", "Cut", 0, 0));
    vol_cut->setWhatsThis(QApplication::translate("Edit_html", "Cut", 0, 0));
    vol_cut->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_copy->setToolTip(QApplication::translate("Edit_html", "Copy", 0, 0));
    vol_copy->setStatusTip(QApplication::translate("Edit_html", "Copy", 0, 0));
    vol_copy->setWhatsThis(QApplication::translate("Edit_html", "Copy", 0, 0));
    vol_copy->setText(QApplication::translate("Edit_html", "...", 0, 0));
    mypaste->setToolTip(QApplication::translate("Edit_html", "Paste", 0, 0));
    mypaste->setStatusTip(QApplication::translate("Edit_html", "Paste", 0, 0));
    mypaste->setWhatsThis(QApplication::translate("Edit_html", "Paste", 0, 0));
    mypaste->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_link->setToolTip(QApplication::translate("Edit_html", "Link", 0, 0));
    vol_link->setStatusTip(QApplication::translate("Edit_html", "Link", 0, 0));
    vol_link->setWhatsThis(QApplication::translate("Edit_html", "Link", 0, 0));
    vol_link->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_bold->setToolTip(QApplication::translate("Edit_html", "Bold", 0, 0));
    vol_bold->setStatusTip(QApplication::translate("Edit_html", "Bold", 0, 0));
    vol_bold->setWhatsThis(QApplication::translate("Edit_html", "Bold", 0, 0));
    vol_bold->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_italic->setToolTip(QApplication::translate("Edit_html", "Italic", 0, 0));
    vol_italic->setStatusTip(QApplication::translate("Edit_html", "Italic", 0, 0));
    vol_italic->setWhatsThis(QApplication::translate("Edit_html", "Italic", 0, 0));
    vol_italic->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_underline->setToolTip(QApplication::translate("Edit_html", "Underline", 0, 0));
    vol_underline->setStatusTip(QApplication::translate("Edit_html", "Underline", 0, 0));
    vol_underline->setWhatsThis(QApplication::translate("Edit_html", "Underline", 0, 0));
    vol_underline->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_left->setToolTip(QApplication::translate("Edit_html", "Text align Left", 0, 0));
    vol_left->setStatusTip(QApplication::translate("Edit_html", "Text align Left", 0, 0));
    vol_left->setWhatsThis(QApplication::translate("Edit_html", "Text align Left", 0, 0));
    vol_left->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_center->setToolTip(QApplication::translate("Edit_html", "Text align Center", 0, 0));
    vol_center->setStatusTip(QApplication::translate("Edit_html", "Text align Center", 0, 0));
    vol_center->setWhatsThis(QApplication::translate("Edit_html", "Text align Center", 0, 0));
    vol_center->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_right->setToolTip(QApplication::translate("Edit_html", "Text align Center", 0, 0));
    vol_right->setStatusTip(QApplication::translate("Edit_html", "Text align Center", 0, 0));
    vol_right->setWhatsThis(QApplication::translate("Edit_html", "Text align Center", 0, 0));
    vol_right->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_justify->setToolTip(QApplication::translate("Edit_html", "Text align Justify", 0, 0));
    vol_justify->setStatusTip(QApplication::translate("Edit_html", "Text align Justify", 0, 0));
    vol_justify->setWhatsThis(QApplication::translate("Edit_html", "Text align Justify", 0, 0));
    vol_justify->setText(QApplication::translate("Edit_html", "...", 0, 0));
    vol_source->setToolTip(QApplication::translate("Edit_html", "Source View", 0, 0));
    vol_source->setStatusTip(QApplication::translate("Edit_html", "Source View", 0, 0));
    vol_source->setWhatsThis(QApplication::translate("Edit_html", "Source View", 0, 0));
    vol_source->setText(QApplication::translate("Edit_html", "...", 0, 0));
    Q_UNUSED(Edit_html);
    } // retranslateUi

};

namespace Ui {
    class Edit_html: public Ui_Edit_html {};
} // namespace Ui

#endif // UI_EDIT_HTML_H
