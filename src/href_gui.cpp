#include "href_gui.h"
//
/*  Save file as href_gui.cpp  */
/*  Class Href_Gui Created on Fri Jun 2 11:13:28 CEST 2006  */
//
#include <QCloseEvent>
//
QPointer<Href_Gui> Href_Gui::_self = 0L;
//
Href_Gui* Href_Gui::self( QWidget* parent )
{
	if ( !_self )
		_self = new Href_Gui( parent );
	return _self;
}
//
Href_Gui::Href_Gui( QWidget* parent )
	: QDialog( parent )
{
	setupUi( this );
    hrefconfisuser.clear(); 
    connect(okButton, SIGNAL(clicked()), this, SLOT(Acceptvars()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}
void Href_Gui::Acceptvars()
{
    QString te = text_href->text();
    QString url = url_href->text();
    QString target = target_href->itemText(target_href->currentIndex()); 
    if (te.size() < 1 or  url.size() < 1) {
        QMessageBox::warning( this, tr( "Error Text!" ),tr("Mettete una url valida o un testo valido!"));
        return;
    }
    hrefconfisuser.clear(); 
    hrefconfisuser.append(te);
    hrefconfisuser.append(url);
    hrefconfisuser.append(target);
    accept();
}
QStringList Href_Gui::GetUserConfig()
{
    return hrefconfisuser;
}
void Href_Gui::reject()
{
	hrefconfisuser.clear(); 
    close();
}
void Href_Gui::closeEvent( QCloseEvent* e )
{
    hrefconfisuser.clear();
	e->accept();
}
