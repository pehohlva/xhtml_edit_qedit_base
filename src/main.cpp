#include <QFile>
#include <QApplication>
#include <QtGui>
#include <QtCore> 
#include <QTextCodec>
#include <QCoreApplication>
#include <QApplication>
#include <QtGui>
#include "main.h"
#include "edit_html.h"
#include "base_modul.h"
#include "app_config.h"
#include <QKeySequence>
#include <QShortcut>


/// nuova config di git sali

static inline bool fwriteutf8(QString fullFileName,QString xml)
{
    if (fullFileName.contains("/", Qt::CaseInsensitive)) {
    QString ultimacartellaaperta = fullFileName.left(fullFileName.lastIndexOf("/"))+"/";
    QDir dira(ultimacartellaaperta);
    if ( dira.mkpath(ultimacartellaaperta) ) { } else {
    return false;
    }
    }
    
        QTextCodec *codecx;
        codecx = QTextCodec::codecForMib(106);
        QFile f( fullFileName );
        if ( f.open( QFile::WriteOnly | QFile::Text ) )
        {
        QTextStream sw( &f );
        sw.setCodec(codecx);
        sw << xml;
        f.close();
        return true;
        }
        return false;
}



static inline bool is_file(QString fullFileName)
{
    if (!fullFileName.size() > 3) {
      return false;  
    }
    QFile f( fullFileName );
	if ( f.exists(fullFileName) ) {
    return true;  
	} else {
	return false;
    }
}


static inline QString UserLanguage()
{
     /////////////QSettings setter;
     QString languser,languagesistem,langqt; 
	QLocale loci = QLocale::system();
             languser = getenv("LANG");
             languser = languser.toLower();
             languagesistem = loci.name();
             languagesistem = languagesistem.toLower();
	     languagesistem = languagesistem.left(2);
     /* Window XP Prof MUI Multiuser == stay only "c" language && user setting setenv !!! */
     if (languagesistem == "c") { 
         if (languser.size() > 2 && languser.contains("_")) {
             languagesistem = languser.left(2);
         }
     }
     ////////////setter.setValue("userlanguage",languagesistem);
     ///////////qDebug() << "### save to qsetting " << languagesistem;
    ///////// qDebug() << "### QT grep language " << QLocale::languageToString( QLocale::system().language());
     /////////qDebug() << "### User setenv " << getenv("LANG"); 
     return languagesistem;
}


int main(int argc, char *argv[]) {
     QApplication a( argc, argv );
    
        QCoreApplication::setOrganizationName(_ORGANIZATION_NAME_);
        QCoreApplication::setOrganizationDomain(_PROGRAM_NAME_DOMAINE_);
        QCoreApplication::setApplicationName(_PROGRAM_NAME_);

#if defined Q_OS_MAC
QStringList path;
path.append(QApplication::applicationDirPath());
QDir dir(QApplication::applicationDirPath());
dir.cdUp();
path.append(dir.absolutePath());
dir.cd("plugins");
path.append(dir.absolutePath());
dir.cdUp();
path.append(dir.absolutePath());
QApplication::setLibraryPaths(path);
QDir::setCurrent(dir.absolutePath());   /* here down -> Frameworks */
#endif
    
    
      
     QString localedirfile,openfile;
    
    /*
    linux and mac copy yourself or make installer!
    #define WORK_CACHEDIR \
               QString( "%1/.%2/" ).arg(QDir::homePath(),_PROGRAM_SHORT_NAME) 
    
    */
    
    
#if defined Q_OS_MAC
localedirfile = QString("%1/locale/edit_%2.qm").arg(QDir::currentPath()).arg(UserLanguage()); 
#endif
#if defined Q_WS_WIN
localedirfile = QString("%1/locale/edit_%2.qm").arg(QCoreApplication::applicationDirPath()).arg(UserLanguage());
#endif
#if defined Q_WS_X11
localedirfile = QString("%1/locale/edit_%2.qm").arg(WORK_CACHEDIR).arg(UserLanguage()); 
#endif
    
    

    QTranslator translator;
    translator.load(localedirfile);
    a.installTranslator(&translator);
    qDebug() << "### " << __FILE__ << "-" << __FUNCTION__  << "line:" << __LINE__;
    qDebug() << "### primo arg  " << argv[1] << " secondo arg " << argv[2];
    
    QStringList debi;
    debi.append(QString("Locale file: %1").arg(localedirfile));
     foreach (QString path, a.libraryPaths())  {
     debi.append(QString("libraryPaths file: %1").arg(path));
     }
    debi.append(QString(".. WORK_CACHEDIR file: %1").arg(WORK_CACHEDIR));
    debi.append(QString(".. _PROGRAM_TITLE_: %1").arg(_PROGRAM_TITLE_));
    
     
    MainWindow mainWin;
    QString titlenow = _PROGRAM_TITLE_;
    titlenow.append(" - ");
    titlenow.append(QDate::currentDate().toString());
    mainWin.setWindowTitle(titlenow);
    
    Edit_html w;
    mainWin.setCentralWidget(&w);



    #if defined Q_OS_MAC

    /* mac icon menu tray icon mac...  */
      QMenu *macdocks = new QMenu();  //// menu by mac bar icons
      macdocks->addAction(QObject::tr("&App Quit."),&a, SLOT(quit()));
      macdocks->addAction(QObject::tr("&Open xhtml - html file"),&w, SLOT(OpenNewDoc()));
      macdocks->addSeparator();
      //// qt_mac_set_dock_menu(macdocks);
      macdocks->setAsDockMenu();
    #endif
     
     
    QMenu *menu = mainWin.menuBar()->addMenu(QObject::tr("&File"));
    menu->addAction(QObject::tr("Apri File xhtml - html"), &w, SLOT(OpenNewDoc()));
    menu->addSeparator();
    menu->addAction(QObject::tr("&App Quit."),&a, SLOT(quit()));
    
    w.set_Cache(IMM_BUILD);
    QString im, argument;
    QString defaultfile = QString("%2/index.xhtml").arg(QDir::homePath());
    debi.append(QString("defaultfile file: %1").arg(defaultfile));
    if (!is_file(defaultfile))  {
    fwriteutf8(defaultfile,"<p>Hello World! open or write your html or xhtml file.... </p>");
    }
    
    argument = argv[1];
    bool other = is_file(argument);
    
    if (other) {
        QFileInfo fi(argument);
        QString ext = fi.suffix();
        ext = ext.toLower();
        if (ext == "xhtml" or ext == "html") {
         defaultfile = argument;
        } else {
          other = false; 
          QMessageBox::warning(0,"Error \"XHTML Editor\" ",QString("The file \"%1\" is not xhtml or html").arg(argument));            
        }
        
    }
    
    
    if (!other) {
    ////////////im = QFileDialog::getOpenFileName(0,"Select a xhtml file to edit ","","XHTML (*.xhtml *.html)");
    } else {
    defaultfile = argument;   
    }
    
    
    w.SetFileBase(defaultfile);
	
    QRect screens = QApplication::desktop()->availableGeometry();

    const int largox = screens.width() / 10 * 9;
    const int altox = screens.height() / 10 * 9;
    mainWin.show();
    mainWin.setMinimumSize(largox,altox);
    mainWin.setMaximumSize(largox,altox);
    QRect r = mainWin.geometry();
    r.moveCenter(QApplication::desktop()->availableGeometry().center());
    mainWin.setGeometry(r);


   mainWin.connect(&w, SIGNAL(statusMessage(QString)),&mainWin, SLOT(setBaselightTxt(QString)));
   mainWin.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}




///  #include "main.moc"

