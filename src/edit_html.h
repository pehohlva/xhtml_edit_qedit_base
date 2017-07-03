#ifndef EDIT_HTML_H
#define EDIT_HTML_H

#include <QPrinter>
#include "base_edit.h"

#include <QPointer>
//
class Edit_html : public Base_Edit
{
     Q_OBJECT
//
public:	 
    Edit_html();
    
protected:
    void closeEvent( QCloseEvent* );
    bool isqtextblok;
    QTextBlock textblocc;
    void keyPressEvent(QKeyEvent *e);
private:
      
     QMenu *TContext;
 QMenu *TtableContext;
 QMenu *TimageContext;
  QAction *actionAlignLeft,
        *actionAlignCenter,
        *actionAlignRight,
        *actionAlignJustify,
        *actionTextColor,
        *actionUndo,
        *actionPscreen,
        *actionSave,
        *actionRedo,
        *actionCut,
        *actionCopy,
        *actionCleanertext,
        *actionPaste;
  void ExportImagetoPath( const QString path  );
signals:
   

   /* on base edit is this void OnSave( QString source ); image are on image path wo set before !!  image html  looks (src="./image.png") replace to your path dest...[./].. */

public slots:
    void RContext(  const QPoint & pos );
    void SaveAction( QString source  );
    void MakefilePrintPdf();
    void MakefilePrint();
    void TextFamily(const QString &f);
    void TextSize(const QString &p);
    void FontChanged(const QFont &f);
    void currentCharFormatChanged(const QTextCharFormat &format);
    void MakealignmentChanged(Qt::Alignment a);
    void MaketextAlign(QAction *a);
    void TextStyle(int styleIndex);
    void MaketextColor();
    void  MakeTextBold();
    void  SaveAsFile();
    void  DoubleClick();
    void  SetTableCellColor();
    void  SetColumLarge();
    void  SetTextBlockMargin();

};
//
#endif // EDIT_HTML_H

