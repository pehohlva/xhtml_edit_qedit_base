#ifndef BASE_EDIT_H
#define BASE_EDIT_H
//
#include "ui_edit_html.h"
#include "base_modul.h"

//////////////#include "main.h"
#include "interface.h"

#include "href_gui.h"
#include "xmlhighlighter.h"
#include "html_loader.h"
#include "table_setting.h"
#include <QKeyEvent>
#include <QScrollBar>
#include <QTextDocument>
/*  Save file as base_edit.h  */
/*  incomming class name Base_Edit */
//
#include <QPointer>
//
class Base_Edit : public QWidget, public Ui::Edit_html, public Base_Modul
{
     Q_OBJECT
public:	 
    Base_Edit();
    void  SetFileBase( QString file  );
    void set_XHTML( const QString source );
    void set_Cache( const QString path );
 QString basefilestart;
 QString basefilepath;
 QString html;
 QString imageincommingcache;
 QString imagecache;
 int xytextpos;
 bool editrun;
 bool bellavista;
 bool buttoneditrun;
 int passage;
 bool sourcerun;
 void Load_Base_Connec();
 QTextDocument *doc;
 Html_Loader *lesshtml;
 QShortcut *shortcut1;
 XmlHighlighter *highlight;
 QScrollBar *textliner;
 QTextCursor lastcursor;
 QScrollBar *textareatext;
 QScrollBar *wysiwyg_sroll;
 int lastscroll;
 int slastscroll;
 QAction *act_mypaste, 
          *act_mycute,
          *act_mycopy,
     *act_myselectall;
 void dragEnterEvent(QDragEnterEvent *event);
 void dropEvent(QDropEvent *event);
 void Grabdata(const QMimeData *data);
 void Create_New_Image_Tag( const QString urlremoteorlocal );
 QTextImageFormat nowimage;
 QTextTable  *nowtable;
 bool Eframe;
 bool Eimage;
 bool Etable;
 int numeroimmagine;
 void BaseButton_Switsch();
 QSettings setter;
 protected:	 
    
private:
signals:
  void OnSave( QString source );
  void statusMessage(QString);
public slots:
    public slots:
    void RedirectToUrl( QUrl loc );
    void OpenDesktop( QUrl loc );
    void ShowModusPanelView();
    void ShowModusPanelEdit();
    void ShowModusPanelSourceView();
    void SwapModeView( int tabi );
    void UpdateSourceLineNr();
    void Refresh_Source();
    void SaveStream();
    void Load_Xhtml();
    void SetNewDoc();
    void CreateanewTable();
    void MergeCellByCursorPosition();
    void AppendTableRows();
    void AppendTableCools();
    void RemoveRowByCursorPosition();
    void RemoveCoolByCursorPosition();
    void TableSetting();
    void Reload_Editor();
    void CreateanewImage();
    void Image_mod_Setting();
    void PicsFromCopy( QString filenew );
    void RamPosition_wysiwyg( int position );
    void RamPosition_source( int position );
    void ModusView( bool src );
    void SwaptoSource();
    void SwaptoEdit();
    void  Copy_All(); 
    void  Paste_All();
    void  Cute_All();
    void  Redo_All();
    void  Undo_All();
    void CleanCache();
    void MakehrefLink();
    void MakeBreak();
    void OpenNewDoc();
    void SaveX();
    void AutoReload();

};
//
#endif // BASE_EDIT_H

