/********************************************************************************
** Form generated from reading UI file 'edit_html.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_HTML_H
#define UI_EDIT_HTML_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "qvimedit.h"

QT_BEGIN_NAMESPACE

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
        if (Edit_html->objectName().isEmpty())
            Edit_html->setObjectName(QStringLiteral("Edit_html"));
        Edit_html->resize(622, 485);
        gridLayout = new QGridLayout(Edit_html);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(9, 9, 9, 9);
        tabWidget = new QTabWidget(Edit_html);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout1 = new QGridLayout(tab);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        gridLayout1->setHorizontalSpacing(6);
        gridLayout1->setVerticalSpacing(6);
        gridLayout1->setContentsMargins(9, 9, 9, 9);
        wtext = new QVimedit(tab);
        wtext->setObjectName(QStringLiteral("wtext"));
        wtext->setAcceptDrops(false);
        wtext->setReadOnly(false);
        wtext->setOpenExternalLinks(true);

        gridLayout1->addWidget(wtext, 0, 0, 1, 1);

        const QIcon icon = QIcon(QString::fromUtf8(":/img/icon.png"));
        tabWidget->addTab(tab, icon, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout2 = new QGridLayout(tab_2);
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        gridLayout2->setHorizontalSpacing(6);
        gridLayout2->setVerticalSpacing(6);
        gridLayout2->setContentsMargins(9, 9, 9, 9);
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        sline = new QTextEdit(tab_2);
        sline->setObjectName(QStringLiteral("sline"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
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
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        QBrush brush3(QColor(235, 233, 237, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        sline->setPalette(palette);
        sline->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ForbiddenCursor)));
        sline->setFrameShadow(QFrame::Raised);
        sline->setReadOnly(true);

        hboxLayout->addWidget(sline);

        stext = new QTextEdit(tab_2);
        stext->setObjectName(QStringLiteral("stext"));
        stext->setAutoFormatting(QTextEdit::AutoAll);
        stext->setAcceptRichText(false);

        hboxLayout->addWidget(stext);


        gridLayout2->addLayout(hboxLayout, 0, 0, 1, 1);

        const QIcon icon1 = QIcon(QString::fromUtf8(":/img/view-source.png"));
        tabWidget->addTab(tab_2, icon1, QString());

        gridLayout->addWidget(tabWidget, 2, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        list_ul = new QComboBox(Edit_html);
        const QIcon icon2 = QIcon(QString::fromUtf8(":/img/unordered-list.png"));
        list_ul->addItem(icon2, QString());
        list_ul->setObjectName(QStringLiteral("list_ul"));

        hboxLayout1->addWidget(list_ul);

        fontname = new QFontComboBox(Edit_html);
        fontname->setObjectName(QStringLiteral("fontname"));

        hboxLayout1->addWidget(fontname);

        fontsize = new QComboBox(Edit_html);
        fontsize->setObjectName(QStringLiteral("fontsize"));

        hboxLayout1->addWidget(fontsize);

        vol_color = new QToolButton(Edit_html);
        vol_color->setObjectName(QStringLiteral("vol_color"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/img/info.png"));
        vol_color->setIcon(icon3);
        vol_color->setIconSize(QSize(22, 22));

        hboxLayout1->addWidget(vol_color);

        vol_br = new QToolButton(Edit_html);
        vol_br->setObjectName(QStringLiteral("vol_br"));
        const QIcon icon4 = QIcon(QString::fromUtf8(":/img/document.png"));
        vol_br->setIcon(icon4);
        vol_br->setIconSize(QSize(22, 22));

        hboxLayout1->addWidget(vol_br);

        vol_img = new QToolButton(Edit_html);
        vol_img->setObjectName(QStringLiteral("vol_img"));
        const QIcon icon5 = QIcon(QString::fromUtf8(":/img/pictures.png"));
        vol_img->setIcon(icon5);
        vol_img->setIconSize(QSize(22, 22));

        hboxLayout1->addWidget(vol_img);

        val_table = new QToolButton(Edit_html);
        val_table->setObjectName(QStringLiteral("val_table"));
        const QIcon icon6 = QIcon(QString::fromUtf8(":/img/table.png"));
        val_table->setIcon(icon6);
        val_table->setIconSize(QSize(22, 22));

        hboxLayout1->addWidget(val_table);

        savecache = new QPushButton(Edit_html);
        savecache->setObjectName(QStringLiteral("savecache"));
        const QIcon icon7 = QIcon(QString::fromUtf8(":/img/filesave.png"));
        savecache->setIcon(icon7);
        savecache->setIconSize(QSize(22, 22));

        hboxLayout1->addWidget(savecache);

        spacerItem = new QSpacerItem(141, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);


        gridLayout->addLayout(hboxLayout1, 1, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        vol_print = new QToolButton(Edit_html);
        vol_print->setObjectName(QStringLiteral("vol_print"));
        const QIcon icon8 = QIcon(QString::fromUtf8(":/img/fileprint.png"));
        vol_print->setIcon(icon8);
        vol_print->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_print);

        vol_pdf = new QToolButton(Edit_html);
        vol_pdf->setObjectName(QStringLiteral("vol_pdf"));
        const QIcon icon9 = QIcon(QString::fromUtf8(":/img/exportpdf.png"));
        vol_pdf->setIcon(icon9);
        vol_pdf->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_pdf);

        vol_html = new QToolButton(Edit_html);
        vol_html->setObjectName(QStringLiteral("vol_html"));
        vol_html->setIcon(icon7);
        vol_html->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_html);

        vol_undo = new QToolButton(Edit_html);
        vol_undo->setObjectName(QStringLiteral("vol_undo"));
        const QIcon icon10 = QIcon(QString::fromUtf8(":/img/editundo.png"));
        vol_undo->setIcon(icon10);
        vol_undo->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_undo);

        vol_redo = new QToolButton(Edit_html);
        vol_redo->setObjectName(QStringLiteral("vol_redo"));
        const QIcon icon11 = QIcon(QString::fromUtf8(":/img/editredo.png"));
        vol_redo->setIcon(icon11);
        vol_redo->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_redo);

        vol_cut = new QToolButton(Edit_html);
        vol_cut->setObjectName(QStringLiteral("vol_cut"));
        const QIcon icon12 = QIcon(QString::fromUtf8(":/img/cut.png"));
        vol_cut->setIcon(icon12);
        vol_cut->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_cut);

        vol_copy = new QToolButton(Edit_html);
        vol_copy->setObjectName(QStringLiteral("vol_copy"));
        const QIcon icon13 = QIcon(QString::fromUtf8(":/img/copy.png"));
        vol_copy->setIcon(icon13);
        vol_copy->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_copy);

        mypaste = new QToolButton(Edit_html);
        mypaste->setObjectName(QStringLiteral("mypaste"));
        const QIcon icon14 = QIcon(QString::fromUtf8(":/img/paste.png"));
        mypaste->setIcon(icon14);
        mypaste->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(mypaste);

        vol_link = new QToolButton(Edit_html);
        vol_link->setObjectName(QStringLiteral("vol_link"));
        const QIcon icon15 = QIcon(QString::fromUtf8(":/img/link.png"));
        vol_link->setIcon(icon15);
        vol_link->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_link);

        vol_bold = new QToolButton(Edit_html);
        vol_bold->setObjectName(QStringLiteral("vol_bold"));
        const QIcon icon16 = QIcon(QString::fromUtf8(":/img/textbold.png"));
        vol_bold->setIcon(icon16);
        vol_bold->setIconSize(QSize(22, 22));
        vol_bold->setCheckable(true);

        hboxLayout2->addWidget(vol_bold);

        vol_italic = new QToolButton(Edit_html);
        vol_italic->setObjectName(QStringLiteral("vol_italic"));
        const QIcon icon17 = QIcon(QString::fromUtf8(":/img/textitalic.png"));
        vol_italic->setIcon(icon17);
        vol_italic->setIconSize(QSize(22, 22));
        vol_italic->setCheckable(true);

        hboxLayout2->addWidget(vol_italic);

        vol_underline = new QToolButton(Edit_html);
        vol_underline->setObjectName(QStringLiteral("vol_underline"));
        const QIcon icon18 = QIcon(QString::fromUtf8(":/img/textunder.png"));
        vol_underline->setIcon(icon18);
        vol_underline->setIconSize(QSize(22, 22));
        vol_underline->setCheckable(true);

        hboxLayout2->addWidget(vol_underline);

        vol_left = new QToolButton(Edit_html);
        vol_left->setObjectName(QStringLiteral("vol_left"));
        const QIcon icon19 = QIcon(QString::fromUtf8(":/img/textleft.png"));
        vol_left->setIcon(icon19);
        vol_left->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_left);

        vol_center = new QToolButton(Edit_html);
        vol_center->setObjectName(QStringLiteral("vol_center"));
        const QIcon icon20 = QIcon(QString::fromUtf8(":/img/textcenter.png"));
        vol_center->setIcon(icon20);
        vol_center->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_center);

        vol_right = new QToolButton(Edit_html);
        vol_right->setObjectName(QStringLiteral("vol_right"));
        const QIcon icon21 = QIcon(QString::fromUtf8(":/img/textright.png"));
        vol_right->setIcon(icon21);
        vol_right->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_right);

        vol_justify = new QToolButton(Edit_html);
        vol_justify->setObjectName(QStringLiteral("vol_justify"));
        const QIcon icon22 = QIcon(QString::fromUtf8(":/img/textjustify.png"));
        vol_justify->setIcon(icon22);
        vol_justify->setIconSize(QSize(22, 22));

        hboxLayout2->addWidget(vol_justify);

        vol_source = new QToolButton(Edit_html);
        vol_source->setObjectName(QStringLiteral("vol_source"));
        vol_source->setIcon(icon1);
        vol_source->setIconSize(QSize(22, 22));
        vol_source->setCheckable(true);

        hboxLayout2->addWidget(vol_source);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem1);


        gridLayout->addLayout(hboxLayout2, 0, 0, 1, 1);


        retranslateUi(Edit_html);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Edit_html);
    } // setupUi

    void retranslateUi(QWidget *Edit_html)
    {
        Edit_html->setWindowTitle(QApplication::translate("Edit_html", "Form", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Edit_html", "Edit and View", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Edit_html", "Source View", Q_NULLPTR));
        list_ul->setItemText(0, QApplication::translate("Edit_html", "New Item", Q_NULLPTR));

        fontsize->clear();
        fontsize->insertItems(0, QStringList()
         << QApplication::translate("Edit_html", "12", Q_NULLPTR)
         << QApplication::translate("Edit_html", "15", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        vol_color->setToolTip(QApplication::translate("Edit_html", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Font color</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        vol_color->setWhatsThis(QApplication::translate("Edit_html", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">Font color</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_color->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_br->setToolTip(QApplication::translate("Edit_html", "Break Line", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_br->setStatusTip(QApplication::translate("Edit_html", "Break Line", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_br->setWhatsThis(QApplication::translate("Edit_html", "Break Line", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_br->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_img->setToolTip(QApplication::translate("Edit_html", "New Image", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_img->setStatusTip(QApplication::translate("Edit_html", "New Image", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_img->setWhatsThis(QApplication::translate("Edit_html", "New Image", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_img->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        val_table->setToolTip(QApplication::translate("Edit_html", "New Table", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        val_table->setStatusTip(QApplication::translate("Edit_html", "New Table", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        val_table->setWhatsThis(QApplication::translate("Edit_html", "New Table", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        val_table->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
        savecache->setText(QApplication::translate("Edit_html", "Save HTML ", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        savecache->setShortcut(QApplication::translate("Edit_html", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        vol_print->setToolTip(QApplication::translate("Edit_html", "Print File", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_print->setStatusTip(QApplication::translate("Edit_html", "Print File", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_print->setWhatsThis(QApplication::translate("Edit_html", "Print File", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_print->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_pdf->setToolTip(QApplication::translate("Edit_html", "Export as PDF", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_pdf->setStatusTip(QApplication::translate("Edit_html", "Export as PDF", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_pdf->setWhatsThis(QApplication::translate("Edit_html", "Export as PDF", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_pdf->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_html->setToolTip(QApplication::translate("Edit_html", "Export as html", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_html->setStatusTip(QApplication::translate("Edit_html", "Export as html", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_html->setWhatsThis(QApplication::translate("Edit_html", "Export as html", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_html->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_undo->setToolTip(QApplication::translate("Edit_html", "Undo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_undo->setStatusTip(QApplication::translate("Edit_html", "Undo", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_undo->setWhatsThis(QApplication::translate("Edit_html", "Undo", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_undo->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_redo->setToolTip(QApplication::translate("Edit_html", "Redo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_redo->setStatusTip(QApplication::translate("Edit_html", "Redo", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_redo->setWhatsThis(QApplication::translate("Edit_html", "Redo", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_redo->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_cut->setToolTip(QApplication::translate("Edit_html", "Cut", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_cut->setStatusTip(QApplication::translate("Edit_html", "Cut", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_cut->setWhatsThis(QApplication::translate("Edit_html", "Cut", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_cut->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_copy->setToolTip(QApplication::translate("Edit_html", "Copy", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_copy->setStatusTip(QApplication::translate("Edit_html", "Copy", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_copy->setWhatsThis(QApplication::translate("Edit_html", "Copy", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_copy->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        mypaste->setToolTip(QApplication::translate("Edit_html", "Paste", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        mypaste->setStatusTip(QApplication::translate("Edit_html", "Paste", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        mypaste->setWhatsThis(QApplication::translate("Edit_html", "Paste", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        mypaste->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_link->setToolTip(QApplication::translate("Edit_html", "Link", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_link->setStatusTip(QApplication::translate("Edit_html", "Link", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_link->setWhatsThis(QApplication::translate("Edit_html", "Link", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_link->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_bold->setToolTip(QApplication::translate("Edit_html", "Bold", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_bold->setStatusTip(QApplication::translate("Edit_html", "Bold", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_bold->setWhatsThis(QApplication::translate("Edit_html", "Bold", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_bold->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_italic->setToolTip(QApplication::translate("Edit_html", "Italic", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_italic->setStatusTip(QApplication::translate("Edit_html", "Italic", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_italic->setWhatsThis(QApplication::translate("Edit_html", "Italic", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_italic->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_underline->setToolTip(QApplication::translate("Edit_html", "Underline", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_underline->setStatusTip(QApplication::translate("Edit_html", "Underline", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_underline->setWhatsThis(QApplication::translate("Edit_html", "Underline", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_underline->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_left->setToolTip(QApplication::translate("Edit_html", "Text align Left", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_left->setStatusTip(QApplication::translate("Edit_html", "Text align Left", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_left->setWhatsThis(QApplication::translate("Edit_html", "Text align Left", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_left->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_center->setToolTip(QApplication::translate("Edit_html", "Text align Center", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_center->setStatusTip(QApplication::translate("Edit_html", "Text align Center", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_center->setWhatsThis(QApplication::translate("Edit_html", "Text align Center", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_center->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_right->setToolTip(QApplication::translate("Edit_html", "Text align Center", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_right->setStatusTip(QApplication::translate("Edit_html", "Text align Center", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_right->setWhatsThis(QApplication::translate("Edit_html", "Text align Center", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_right->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_justify->setToolTip(QApplication::translate("Edit_html", "Text align Justify", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_justify->setStatusTip(QApplication::translate("Edit_html", "Text align Justify", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_justify->setWhatsThis(QApplication::translate("Edit_html", "Text align Justify", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_justify->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vol_source->setToolTip(QApplication::translate("Edit_html", "Source View", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        vol_source->setStatusTip(QApplication::translate("Edit_html", "Source View", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        vol_source->setWhatsThis(QApplication::translate("Edit_html", "Source View", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        vol_source->setText(QApplication::translate("Edit_html", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Edit_html: public Ui_Edit_html {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_HTML_H
