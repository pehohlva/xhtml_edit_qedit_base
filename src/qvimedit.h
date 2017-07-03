#ifndef QVIMEDIT_H
#define QVIMEDIT_H


#include "base_modul.h"
//
/*  Save file as qvimedit.h  */
/*  incomming class name QVimedit */
//
//
class QVimedit : public QTextBrowser, public Base_Modul
{
     Q_OBJECT
//
public:	 
    QVimedit( QWidget *parent = 0);
    ~QVimedit();
    bool canInsertFromMimeData ( const QMimeData * source );
    void insertFromMimeData ( const QMimeData * source );
    QShortcut *shortcut0;
    QShortcut *shortcut1;
//
protected:
//
    void keyPressEvent(QKeyEvent *e);
    void mouseDoubleClickEvent ( QMouseEvent *e );
private:
    int numerobase;
signals:
     void IncommingHTML();
     void DDClick();
     void SaveStreamer();
     void TakeImage( QString nuovaimagine );
public slots:
    void PrintScreen();
     void MakePrintScreen();
    void  SaveCurrentDoc();

};
//
#endif // QVIMEDIT_H

