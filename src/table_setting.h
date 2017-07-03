#ifndef TABLE_SETTING_H
#define TABLE_SETTING_H
#include "base_modul.h"
#include <QStringList>
#include <QSettings>
#include <QActionGroup>
#include <QColorDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTextDocumentFragment>
#include <QTextCursor>
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include <QFontDatabase>
#include <QTextBlockFormat>
#include <QTextListFormat>
#include <QTextFormat>
#include <QTextList>
#include <QTextCodec>
#include <QByteArray>
#include <QDebug>
#include <QSettings>
#include <QErrorMessage>
#include <QProcess>
#include <QTextCursor>
#include <QTextTable>
#include <QTextTableCell>
#include <QTextTableFormat>
#include <QInputDialog>
#include <QMenu>
#include <QTextLength>
#include "ui_table_setting.h"
//
/*  Save file as table_setting.h  */
/*  Class Table_Setting Created on Tue Sep 12 13:46:10 CEST 2006  */
//
#include <QPointer>
//
class Table_Setting : public QDialog, public Ui::Table_Setting, public Base_Modul
{
	Q_OBJECT
	//
public:
	static Table_Setting* self( QWidget* = 0 );
    void SetFormat( QTextTable *existingtable );
    QTextTableFormat GetNewFormats();
	//
protected:
	void closeEvent( QCloseEvent* );
	//
private:
	Table_Setting( QWidget* = 0 );
	static QPointer<Table_Setting> _self;
    QTextTable *format_table;
    QTextTableFormat formtab;
    QTextLength trolengh;
    qreal xpadding;
    qreal xspacing;
    QBrush xbgcolor;
    int setfoundalign;
    int allineaesistente;
    qreal intborder;
    QColor normalcolor;
    QAction *TableColor;
    QPixmap pix;
	//
 public slots:
     void ChoisColor();
     void UpdateFormats();

};
//
#endif // TABLE_SETTING_H


