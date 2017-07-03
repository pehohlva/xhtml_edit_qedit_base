#ifndef HREF_GUI_H
#define HREF_GUI_H
#include <QStringList>
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
#include "href_start.h"
//
/*  Save file as href_gui.h  */
/*  Class Href_Gui Created on Fri Jun 2 11:13:27 CEST 2006  */
//
#include <QPointer>
#include <QStringList>

/* typedef QMap<int, QStringList> Userconf;*/
    
class Href_Gui : public QDialog, public Ui::Href_Gui
{
	Q_OBJECT
	//
public:
    Href_Gui( QWidget* = 0 );
	static Href_Gui* self( QWidget* = 0 );
    QStringList GetUserConfig();
    static QPointer<Href_Gui> _self;
	//
protected:
	void closeEvent( QCloseEvent* );
	//
private:
	
	
    QStringList hrefconfisuser;

	//
 public slots:
     void Acceptvars();
     void reject();

};
//
#endif // HREF_GUI_H


