#ifndef BASE_MODUL_H
#define BASE_MODUL_H
#include <QtCore>
#include <QFile>
#include <QtCore> 
#include <QTextCodec>
#include <QCoreApplication>
#include <QDomDocument>
#include <QtDebug>
#include <QDebug> 
#include <QSettings>
#include <QDomDocument>
#include <QDomElement>
#include <QDomImplementation>
#include <QDomProcessingInstruction>
#include <QFile>
#include <QTextCodec>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCalendarWidget>
#include <QDialog>
#include <QTextTable>
#include <QInputDialog>
#include <QMenu>
#include <QString>
#include <QtDebug>
#include <QDebug> 
#include <QDesktopServices>
#include <QDebug>
#include <QString>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QHeaderView>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QMap>
#include <QList>
#include <QStringList>
#include <QObject>
#include <QDateTime>
#include <QDate>
#include <QImageReader>
#include <QPixmap>
#include <QSettings>
#include <QTimer>
#include <QProgressDialog>
#include <QPainter>
#include <QPixmap>
#include <QUrl>
#include <QColorDialog>
#include <QSqlField>
#include <QFileDialog>
#include <QMessageBox>
#include <QMdiArea>
#include <QDockWidget>
#include <QTcpSocket>
#include <QString>
#include <QDebug>
#include <QObject>
#include <QFileInfo>
#include <QObject>
#include <QNetworkAccessManager>
#include <QFile>
#include <QBuffer> 
#include <QTcpSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QAbstractSocket>
#include <QDateTime>
#include <QDate>
#include <QLocale>
#include <QObject>
#include <QFileInfo>
#include <QObject>
#include <QFile>
#include <QBuffer>
#include <QMenuBar>
#include <QMainWindow>
#include <QApplication>
#include <QtGui>
#include <QtCore>
#include <QtDebug>
#include <QTextBrowser>
#include <QStatusBar>
#include <QProgressBar>
#include "main.h"
#include "app_config.h"
#include "tidy.h" 
#include <QShortcut>
#include <QKeySequence>


static QString bytesToSize(const qint64 size) {
    if (size < 0)
        return QString();
    if (size < 1024)
        return QObject::tr("%1 B").arg(QString::number(((double) size), 'f', 0));
    if ((size >= 1024) && (size < 1048576))
        return QObject::tr("%1 KB").arg(QString::number(((double) size) / 1024, 'f', 0));
    if ((size >= 1048576) && (size < 1073741824))
        return QObject::tr("%1 MB").arg(QString::number(((double) size) / 1048576, 'f', 2));
    if (size >= 1073741824)
        return QObject::tr("%1 GB").arg(QString::number(((double) size) / 1073741824, 'f', 2));
    return QString();
}


class QTidy : public QObject
{
    Q_OBJECT
    
public:
    QString ErrorMSG;
    QString TMP_Dir;
    QString TMP_Config;
    QTextCodec *setcurrentcodec;
    QStringList  tidiconfigfile;
    int status;
    TidyDoc doc;

QTidy()
{
    
}

void Init( QString dircache )
{
    if (!dircache.endsWith("/")) {
      TMP_Dir = dircache + "/";  
    } else {
      TMP_Dir = dircache; 
    }
    QDateTime timer1( QDateTime::currentDateTime() ); 
    const uint timert =  timer1.toTime_t();
    
    TMP_Config = QString( "%1tidy.conf" ).arg( TMP_Dir );
    setcurrentcodec = QTextCodec::codecForMib(106);  /* utf8 */ 
    QDir dira(TMP_Dir);
    if ( dira.mkpath(TMP_Dir) ) { } else {
    ErrorMSG = QString("ERROR! on %1 not Possibel to make dir \"%2\"\n").arg(timert).arg( TMP_Dir );
    }
}


QString TidyCleanfullxhtml( QString body )
{
    QString newbody;
    bool ok = false;;
    QString sucleanfile = QString( "%1tidy_tmp.xml" ).arg( TMP_Dir );
    QString sucleanfileout = QString( "%1tidy_tmp_out.xml" ).arg( TMP_Dir );
    
    
              ok = file_put_utf8contents(sucleanfile,body);
    
    /* file_put_utf8contents   Readutf8File  */
    if (!ok) {
    return body;
    } else {
    SetUp_xhtml_full_page();
    CleanTidy(sucleanfile,sucleanfileout);
    newbody =  Readutf8File(sucleanfileout);
            if (newbody.size() > 2) {
            return newbody;
            } else {
            return body;   
            }
    }        
}




/* prepare config tidy config file xhtml clean */
bool SetUp_xhtml_full_page()
{
    status = 0;
    ErrorMSG ="";
    doc = tidyCreate();
    /////////qDebug() << "### load config. xhtml ...  ";
    /* --output-xhtml y --indent "auto" --wrap "90" */
    bool ok;
    tidiconfigfile.clear();
    tidiconfigfile.append("output-xhtml: yes");
    tidiconfigfile.append("indent: auto");
    tidiconfigfile.append("wrap: 90");
    
    //////tidiconfigfile.append("show-body-only: yes");  /* only body checks */
    QString configtotsl = tidiconfigfile.join("\n");
    ok = tidy_file_set_config(configtotsl);   /* TIDY_CONF */
    if (ok) {
         QByteArray configfileti = TMP_Config.toUtf8();
         status = tidyLoadConfig( doc, configfileti.data() );  /* http://ch2.php.net/manual/de/function.tidy-load-config.php */
        if ( status != 0 ) {
         ErrorMSG ="Not possibel to load Config File!";
         return false;
        } else { 
        return true;
        }
    } else {
      ErrorMSG ="Not possibel to load Config File!";
     return false; 
    } 
}

/* prepare config tidy config file xhtml clean */
bool SetUp_xhtml()
{
    status = 0;
    ErrorMSG ="";
    doc = tidyCreate();
    qDebug() << "### load config. xhtml ...  ";
    bool ok;
    tidiconfigfile.clear();
    tidiconfigfile.append("output-xhtml: yes");
    tidiconfigfile.append("clean: yes");
    tidiconfigfile.append("wrap: 550");
    tidiconfigfile.append("indent-spaces: 1");
    tidiconfigfile.append("char-encoding: utf8");
    tidiconfigfile.append("output-encoding: utf8");
    tidiconfigfile.append("wrap-attributes: yes");
    tidiconfigfile.append("hide-comments: yes");
    tidiconfigfile.append("numeric-entities: yes");
    tidiconfigfile.append("drop-proprietary-attributes: no");
    tidiconfigfile.append("word-2000: yes");
    //////tidiconfigfile.append("bare: yes");
    tidiconfigfile.append("show-body-only: yes");  /* only body checks */
    QString configtotsl = tidiconfigfile.join("\n");
    ok = tidy_file_set_config(configtotsl);   /* TIDY_CONF */
    if (ok) {
         QByteArray configfileti = TMP_Config.toUtf8();
         status = tidyLoadConfig( doc, configfileti.data() );  /* http://ch2.php.net/manual/de/function.tidy-load-config.php */
        if ( status != 0 ) {
         ErrorMSG ="Not possibel to load Config File!";
         return false;
        } else { 
        return true;
        }
    } else {
      ErrorMSG ="Not possibel to load Config File!";
     return false; 
    } 
}

/* prepare config tidy config file xml clean */
bool SetUp_xml()
{
    status = 0;
    ErrorMSG ="";
    doc = tidyCreate();
    /*qDebug() << "### load config xml ....  ";*/
    bool ok;
    tidiconfigfile.clear();
    tidiconfigfile.append("input-xml: yes");
    tidiconfigfile.append("char-encoding: utf8");
    tidiconfigfile.append("output-encoding: ascii");
    tidiconfigfile.append("output-xml: yes");
    tidiconfigfile.append("hide-comments: no");
    tidiconfigfile.append("numeric-entities: yes");
    tidiconfigfile.append("add-xml-space: no");
    QString configtotsl = tidiconfigfile.join("\n");
    ok = tidy_file_set_config(configtotsl);   /* TIDY_CONF */
    if (ok) {
         QByteArray configfileti = TMP_Config.toUtf8();
         status = tidyLoadConfig( doc, configfileti.data() );  /* http://ch2.php.net/manual/de/function.tidy-load-config.php */
        if ( status != 0 ) {
         ErrorMSG ="Not possibel to load Config File!";
         return false;
        } else { 
        return true;
        }
    } else {
      ErrorMSG ="Not possibel to load Config File!";
     return false; 
    } 
}



QString TidyExternalHtml( QString body )
{
    QString prehtml = TidyCleanhtml(body);  /* base clean to stay on minimal standard xhtml */
    QStringList notneed;
    notneed.clear();
    ///////////////width="456" lang  class
    QRegExp expression( "width=[\"\'](.*)[\"\']", Qt::CaseInsensitive );  /* table td tr width image amen */
    QRegExp expression2( "style=[\"\'](.*)[\"\']", Qt::CaseInsensitive );
    QRegExp expression3( "lang=[\"\'](.*)[\"\']", Qt::CaseInsensitive );
    QRegExp expression4( "class=[\"\'](.*)[\"\']", Qt::CaseInsensitive );
    
    
    expression.setMinimal(true);
    expression2.setMinimal(true);
    expression3.setMinimal(true);
    expression4.setMinimal(true);
    
    int iPosition = 0;
    while( (iPosition = expression.indexIn( prehtml , iPosition )) != -1 ) {
        QString semi1 = expression.cap( 1 );
        notneed.append(QString("width=\"%1\"").arg(semi1));
        notneed.append(QString("width='%1'").arg(semi1));
        iPosition += expression.matchedLength();
    }
    
    iPosition = 0;
       while( (iPosition = expression2.indexIn( prehtml , iPosition )) != -1 ) {
        QString semi2 = expression2.cap( 1 );
        notneed.append(QString("style=\"%1\"").arg(semi2));
        notneed.append(QString("style='%1'").arg(semi2));
        iPosition += expression2.matchedLength();
    }
    
    iPosition = 0;
       while( (iPosition = expression3.indexIn( prehtml , iPosition )) != -1 ) {
        QString semi3 = expression3.cap( 1 );
        notneed.append(QString("lang=\"%1\"").arg(semi3));
        notneed.append(QString("lang='%1'").arg(semi3));
        iPosition += expression3.matchedLength();
    }
    
     iPosition = 0;
       while( (iPosition = expression4.indexIn( prehtml , iPosition )) != -1 ) {
        QString semi4 = expression4.cap( 1 );
        notneed.append(QString("class=\"%1\"").arg(semi4));
        notneed.append(QString("class='%1'").arg(semi4));
        iPosition += expression4.matchedLength();
    }
    
    for (int i = 0; i < notneed.size(); ++i)  {
          const QString fluteremove = notneed.at(i);
          prehtml = prehtml.replace(fluteremove,"", Qt::CaseInsensitive );
    }
    
    return prehtml;
}

QString TidyCleanhtml( QString body )
{
    QString newbody;
    bool ok = false;;
    QString sucleanfile = QString( "%1tidy_tmp.xml" ).arg( TMP_Dir );
    QString sucleanfileout = QString( "%1tidy_tmp_out.xml" ).arg( TMP_Dir );
    
           ok = file_put_utf8contents(sucleanfile,body);
    
    if (!ok) {
    return body;
    } else {
    SetUp_xhtml();
    CleanTidy(sucleanfile,sucleanfileout);
    newbody =  Readutf8File(sucleanfileout);
            if (newbody.size() > 2) {
            return newbody;
            } else {
            return body;   
            }
    }        
}

QString TidyCleanxml( QString body )
{
    QString newbody;
    bool ok = false;;
    QString sucleanfile = QString( "%1tidy_tmp.xml" ).arg( TMP_Dir );
    QString sucleanfileout = QString( "%1tidy_tmp_out.xml" ).arg( TMP_Dir );
    
    
              ok = file_put_utf8contents(sucleanfile,body);
    
    /* file_put_utf8contents   Readutf8File  */
    if (!ok) {
    return body;
    } else {
    SetUp_xml();
    CleanTidy(sucleanfile,sucleanfileout);
    newbody =  Readutf8File(sucleanfileout);
            if (newbody.size() > 2) {
            return newbody;
            } else {
            return body;   
            }
    }        
}



bool Copy_To(QString inputfile, QString outfile)
{
    bool actioncpy = false;
    QFile Imagedi(inputfile);
    QFile Imagedd(outfile);
    if (Imagedd.exists()) {
           Imagedd.remove();
            
               if (!Imagedi.copy(outfile)) { 
                   ErrorMSG ="Not possibel to copy!";         
                } else {
                   actioncpy = true; 
                }
    }
return actioncpy;
}

/*  Readutf8File file_put_utf8contents */
/* read the contenet of a local file as qstring */
QString Readutf8File(QString fullFileName)
{
    QString inside = "";
    QFile file(fullFileName); 
    if (file.exists()) {
                if (file.open(QFile::ReadOnly | QFile::Text)) {
                    inside = QString::fromUtf8(file.readAll());   
                    file.close();
                }
    }

return inside;
}

bool file_put_utf8contents(QString fullFileName,QString xml)
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










/* write the config file */
bool tidy_file_set_config(QString xml)
{
return file_put_utf8contents(TMP_Config,xml);
    /* file_put_utf8contents   Readutf8File  */
} 


/* QString clean file inputfile and put to outfile */
bool CleanTidy(QString inputfile, QString outfile)
{
    /*qDebug() << "### load inputfile....  "  << inputfile;*/
    /*qDebug() << "### load outfile....  "  << outfile;*/
    Bool ok;
    ctmbstr cfgfil = NULL, outputfil = NULL, htmlfil = NULL;
    int rc = 0 - 10;
    int base = 0 - 10;
    int status = 0;
    QByteArray infile = inputfile.toUtf8();
    QByteArray outfi = outfile.toUtf8();
    htmlfil = infile.data();   /* incomming file entra */
    outputfil = outfi.data();
    rc = tidyParseFile( doc, htmlfil );
   
                if ( outputfil ) {
                    status = tidySaveFile( doc, outputfil );
                    ///////////qDebug() << "### save to out file ... ";
                } else {
                    status = tidySaveStdout( doc );
                }
               
    /* check if file exist if not copy in to out */
    QFile f( outfile );
   if (!f.exists()) {
    //////////qDebug() << "### file out not exist copy in to out... ";
       QFile Imaged(inputfile); 
      if (!Imaged.copy(outfile)) { 
       ErrorMSG ="Not possibel to copy!";         
       }
   } else {
    ///////////qDebug() << "### file found SUCCESS!!!!!!!! bravo ... ";
    return true;
    }
    /* check if file exist if not copy in to out */

return false;
}

QString ToXmlClean( QString body )
{
  return ToXmlFopTag(CleanTagQt4(body,"FopDest"));
}

QString ToXmlFopTag( QString body )
{
    
    body.replace("</","###end###/html:");
    body.replace("<","<html:");
    body.replace("###end###/html:","</html:");
    body.replace("xmlns=","xmlns:html=");
    QString foxml = body;
    return foxml;
    
}

/* remove all style qt html style and bring to xhtml on tidy  */
QString CleanTagQt4( QString body , QString class_name )
{
    /*qDebug() << "### start clean tag ";*/
    QString finale, finale4;
    QString newbody = body;
    newbody.replace(QRegExp("<div[^>]*>([^<]*)</div>",Qt::CaseInsensitive), "\\1 <!-- QRegExp -->");
    newbody.replace("-qt-paragraph-type","devnull-type");
    newbody.replace("margin-top","devnull-top");
    newbody.replace("margin-bottom","devnull-bottom"); 
    newbody.replace("margin-left","devnull-left");
    newbody.replace("margin-right","devnull-right");
    /////////newbody.replace("#0000ff","#464646");
    newbody.replace("text-indent","devnull-indent");
    newbody.replace("font-size","devnull-size");
    newbody.replace("#target=_blank\"","\" target=\"_blank\"");
    newbody.replace("#target=_top\"","\" target=\"_top\"");
    newbody.replace("#target=_self\"","\" target=\"_self\"");
    newbody.replace("#target=_main\"","\" target=\"_main\"");
    newbody.replace("#target=_menu\"","\" target=\"_menu\"");
    newbody.replace("\n"," ");
    QString wbody = newbody.trimmed();
    
    QDateTime dt = QDateTime::currentDateTime();
    QDate timecute;
    QString day_en = timecute.shortDayName(timecute.day());
    QString month_en = timecute.shortMonthName (timecute.month());
    QString last = dt.toString("yyyy hh:mm:ss");
    QString tname = QString( "%1, %2 %3 %4 +0200" ).arg( day_en , QString::number(timecute.day()), month_en ,   last ); 
    finale = TidyCleanhtml(QString("<div xmlns=\"http://www.w3.org/1999/xhtml\" class=\"####CLASSNAME####\" title=\"Programm powered by PPK-Webprogramm www.ciz.ch document from %2 \">%1</div>").arg(wbody).arg(tname));
    finale.replace("\n"," ");
    finale.replace("####CLASSNAME####",class_name);
    finale4 = finale.trimmed();
 return finale4;
} 






};










//
/*  Save file as base_modul.h  */
/*  incomming class name Base_Modul */
//
//
class Base_Modul
{

//
public: 
Base_Modul()
{
 Load_Connector();
}
/* grep nummer on [77] */
QString  Firstupper( QString nametomake )
{
    QString firtupper,lower,fullname,na,nb;
    int xse = nametomake.size();
    na = nametomake.toLower();
    nb = nametomake.toUpper();
    firtupper = nb.left(1);
    fullname = QString("%1%2").arg(firtupper).arg(na.mid(1,xse - 1));
    
return fullname;
}

bool  image_extension( QString nametomake )
{
    bool fanny = false;
    QString na;
    na = nametomake.toLower();
    if ( na.endsWith(".png") or na.endsWith(".jpeg") or na.endsWith(".jpg") or na.endsWith(".gif") ) {
     fanny = true;   
    }
return fanny;
}

bool file_put_contents_append(QString fullFileName,QString xml)
{
    QString data = xml+"\n";
    QFile f( fullFileName );
	if ( f.open( QFile::Append | QFile::Text ) )
	{
		QTextStream sw( &f );
		sw << data;
		f.close();
		return true;
	}
	return false;
    
}





const char*  Rotate( int casir )
{
    const char *bane;
    
    switch(casir)
                {
                case 1:
                bane ="-";
                break;
                case 2:
                bane ="\\";
                break;
                case 3:
                bane ="|";
                break;
                case 4:
                bane ="/";
                break;
                
    }
    
return bane;
}



QString DesktopFile( QString fullFileName )
{
    if (fullFileName.startsWith("http://", Qt::CaseInsensitive) or 
        fullFileName.startsWith("https://", Qt::CaseInsensitive) or
        fullFileName.startsWith("ftp://", Qt::CaseInsensitive) or
        fullFileName.startsWith("news://", Qt::CaseInsensitive) or
        fullFileName.startsWith("mailto:", Qt::CaseInsensitive) or
        fullFileName.startsWith("webdav://", Qt::CaseInsensitive)  )
       { 
         return fullFileName;
       } else {
         return fullFileName.prepend("file:///");  
       }
}

QString BrowserDir( uint unixtime , QString base )
{
    QString base_3 ="";
    QString base_0 = QString("/%1/%2/").arg( base , datetr("yyyy",(uint)unixtime) );
    QString base_1 = QString("%1%2/").arg( base_0 , datetr("MM",(uint)unixtime) );
    QString base_2 = QString("%1%2/").arg( base_1 , datetr("dd",(uint)unixtime) );
    base_3 = QString("%1%2/").arg( base_2 , QString::number(unixtime) );
     return base_3;
}

QString LocalDir( uint unixtime , QString base )
{
    QString base_3 ="";
    QString base_0 = QString("%1%2/").arg( base , datetr("yyyy",(uint)unixtime) );
    QString base_1 = QString("%1%2/").arg( base_0 , datetr("MM",(uint)unixtime) );
    QString base_2 = QString("%1%2/").arg( base_1 , datetr("dd",(uint)unixtime) );
    base_3 = QString("%1%2/").arg( base_2 , QString::number(unixtime) );
     return base_3;
}

/* encode to url strings */
QString EncodeUrlPart( QString xml  )
{
    QUrl urlmod(QString("http://localhost/%1").arg(xml));
    QByteArray capsed(urlmod.toEncoded());
    QString res = QString("%1").arg(capsed.data());
    res = res.replace("%20","_");
    res = res.replace("%","");
    QUrl urlmod2(res);
    res = urlmod2.path ();
    res = res.replace("/","");
    return res;
}


/* time null unix time long nummer */
uint QTime_Null()
{
    QDateTime timer1( QDateTime::currentDateTime() ); 
    return timer1.toTime_t();
}

/* display a mail date format  UmanTimeFromUnix(QTime_Null())   */
QString UmanTimeFromUnix( uint unixtime )
{
     /* mail rtf Date format! http://www.faqs.org/rfcs/rfc788.html */
     QDateTime fromunix;
     fromunix.setTime_t(unixtime); 
     QStringList RTFdays = QStringList() << "day_NULL" << "Mon" << "Tue" << "Wed" << "Thu" << "Fri" << "Sat" << "Sun";
     QStringList RTFmonth = QStringList() << "month_NULL" << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jul" << "Aug" << "Sep" << "Oct" << "Nov" << "Dec";
     QDate timeroad(dateswap("yyyy",unixtime),dateswap("M",unixtime),dateswap("d",unixtime));
     /*qDebug() << "### RTFdays " << RTFdays.at(timeroad.dayOfWeek());
     qDebug() << "### RTFmonth " << RTFmonth.at(dateswap("M",unixtime));
     qDebug() << "### yyyy " << dateswap("yyyy",unixtime);
     qDebug() << "### M " << dateswap("M",unixtime);
     qDebug() << "### d " << dateswap("d",unixtime);*/
     QStringList rtfd_line;
     rtfd_line.clear();
     rtfd_line.append("Date: ");
     rtfd_line.append(RTFdays.at(timeroad.dayOfWeek()));
     rtfd_line.append(", ");
     rtfd_line.append(QString::number(dateswap("d",unixtime)));
     rtfd_line.append(" ");
     rtfd_line.append(RTFmonth.at(dateswap("M",unixtime)));
     rtfd_line.append(" ");
     rtfd_line.append(QString::number(dateswap("yyyy",unixtime)));
     rtfd_line.append(" ");
     rtfd_line.append(fromunix.toString("hh:mm:ss"));
     rtfd_line.append("");
     /*qDebug() << "### mail rtf Date format " << rtfd_line.join("");*/
return QString(rtfd_line.join(""));
}
/* date format to stirng */
QString datetr(QString form, uint unixtime )
{
     QDateTime fromunix;
     fromunix.setTime_t(unixtime); 
     return fromunix.toString((const QString)form);
}
/* take a qstring and put to double */
double direct_double(QString xid)
{
    double newnummer = 0.01;
    if (is_numeric(xid)) {
        bool ok; 
        newnummer = xid.toDouble(&ok);
        return newnummer;
    }
 return newnummer;
}

/* take a qstring and put to int */
int direct_int(QString xid)
{
    int newnummer = 0;
    if (is_numeric(xid)) {
        bool ok; 
        newnummer = xid.toInt(&ok);
        return newnummer;
    }
 return newnummer;
}

/* return int value from a unixtime date MMM YYY ... */
int dateswap(QString form, uint unixtime )
{
     QDateTime fromunix;
     fromunix.setTime_t(unixtime); 
     QString numeric = fromunix.toString((const QString)form);
     bool ok; 
     return (int)numeric.toFloat(&ok);
}


/* check if a int or float nummer */
bool is_numeric(QString incomming)
{
    incomming.replace(QString(" "), QString("")); /* trimm */
    QString str2 = incomming;
    bool ok; 
    str2.toFloat(&ok); 
return ok;
}

/* encode to name */
QString encodeBase64( QString xml )
{
    QByteArray text;
    text.append(xml);
    return text.toBase64();
}

/* decode to name */
QString decodeBase64( QString xml )
{
    QByteArray xcode("");;
    xcode.append(xml);
    QByteArray precode(QByteArray::fromBase64(xcode));
    QString notetxt = precode.data();
    return notetxt;
}
/* extract domaine from a url */
QString Domain( QString url )
{
   QString hdomain = "";
   QUrl wurl( url );
   hdomain = QString( "http://%1/" ).arg( wurl.host() );
   return hdomain;
}
/* return a config setting from a xml file */
QString  Global_Config_Base( QString tagname , QString filename )
{
    QFile xmlfile(filename);
    QString isis="";
    if(!xmlfile.open( QIODevice::ReadOnly ) ) {
    return isis;
    }
    QString errorStr, obname, inhalt;
    int errorLine;
    int errorColumn;
    
    QDomDocument doc("http://www.pulitzer.ch/2005/PuliCMS/1.0"); 
     if (!doc.setContent(&xmlfile,true, &errorStr, &errorLine, &errorColumn)) {
     return isis;
     xmlfile.close();
     } 
    QDomElement root = doc.documentElement();
    if( root.tagName() != "setting" ) {
    return isis;
    }
    QDomNode n = root.firstChild();
    while( !n.isNull() )
    {
        QDomElement e = n.toElement();
        if( !e.isNull() )
        {
                   if( e.tagName() == tagname ) {
                   xmlfile.close();
                   return decodeBase64(e.text());
                   }
                   
         n = n.nextSibling();
        } 
    }
xmlfile.close();
return isis;
}

/* read the contenet of a local file as qstring */
QString fopenutf8(QString fullFileName)
{
    QString inside = "";
    QFile file(fullFileName); 
    if (file.exists()) {
                if (file.open(QFile::ReadOnly | QFile::Text)) {
                    inside = QString::fromUtf8(file.readAll());
                  file.close();
                }
    }

return inside;
}


/* read the contenet of a local file as qstring */
QString fopeniso(QString fullFileName)
{
    QString inside = "";
    QFile file(fullFileName); 
    if (file.exists()) {
                if (file.open(QFile::ReadOnly | QFile::Text)) {
                    inside =file.readAll();   
                  file.close();
                }
    }

return inside;
}

/* write a file to utf-8 format */
bool fwriteutf8(QString fullFileName,QString xml)
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

/* write a file to iso format */
bool fwriteiso(QString fullFileName,QString xml)
{
    
    if (fullFileName.contains("/", Qt::CaseInsensitive)) {
    
    QString ultimacartellaaperta = fullFileName.left(fullFileName.lastIndexOf("/"))+"/";
    QDir dira(ultimacartellaaperta);
    if ( dira.mkpath(ultimacartellaaperta) ) { } else {
    return false;
    }
    
    }
    
    
        QTextCodec *codecx;
        codecx = QTextCodec::codecForMib(4);
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


/* check if a file exist alert dons say true if a zero byte file!  */
bool is_file(QString fullFileName)
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

/* remove a file */
bool qt_unlink(QString fullFileName)
{
    if (fullFileName.size() > 0) {
    QFile f( fullFileName );
	if ( f.exists(fullFileName) ) {
       if (f.remove()) {
        return true;
       }
	}
    }
return false;
}

/* copy file from a to b ... if dir not exist make it ...*/
bool Copy_To(QString inputfile, QString outfile)
{
    bool actioncpy = false;
    QString ultimacartellaaperta = outfile.left(outfile.lastIndexOf("/"))+"/";
    QDir dira(ultimacartellaaperta);
    if ( dira.mkpath(ultimacartellaaperta) ) { } else {
    return actioncpy;
    }
    if (is_file(inputfile)) {
           qt_unlink(outfile);
           QFile Imaged(inputfile); 
               if (Imaged.copy(outfile)) {
                   actioncpy = true; 
                }
    }
return actioncpy;
}




/* quote and dequote sql s result */
QString sql_Quote( QString xml )
{
   //the following checks are necessary before exporting
  //strings to XML. see http://hdf.ncsa.uiuc.edu/HDF5/XML/xml_escape_chars.html for details
   QString text = xml;
   text.replace("\"","\\\"");  /* 228 ``*/
   text.replace("'","`");
   return text;
}

QString sql_DeQuote( QString xml )
{
   //the following checks are necessary before exporting
  //strings to XML. see http://hdf.ncsa.uiuc.edu/HDF5/XML/xml_escape_chars.html for details
  QString text = xml;
   text.replace("\\\"","\"");  /* 228 ``*/
   text.replace("`","\'");
  return text;
}








/* decode url from cookie or other */
QString  Url_Decode( QString indata )
{
/*
http://www.blooberry.com/indexdot/html/topics/urlencoding.htm
Dollar ("$")  24 
Ampersand ("&") 26
Plus ("+") 2B
Comma (",")  2C
Forward slash/Virgule ("/") 2F
Colon (":")  3A
Semi-colon (";") 3B
Equals ("=") 3D
Question mark ("?") 3F
'At' symbol ("@")  40
Left Curly Brace ("{")  7B
Right Curly Brace ("}") 7D
Vertical Bar/Pipe ("|") 7C
Backslash ("\") 5C
Caret ("^") 5E
Tilde ("~") 7E
Left Square Bracket ("[") 5B
Right Square Bracket ("]") 5D
Grave Accent ("`")  60
*/
QString blnull = "";
QString notaccept = "%60|%5D|%5B|%7E|%5E|%5C|%7C|%7D|%7B";
QStringList notallow;
            notallow = notaccept.split("|");

             for (int i = 0; i < notallow.size(); ++i) {
                 if ( indata.contains(notallow.at(i)) ) {
                   return blnull;   
                 } 
             }
  
         QString spaceout = indata.replace("%20"," ");
                 spaceout = spaceout.replace("%3A",":");  
                 spaceout = spaceout.replace("%3B",";");
                 spaceout = spaceout.replace("%3D","=");
                 spaceout = spaceout.replace("%2F","/");
                 spaceout = spaceout.replace("%3F","?");
                 spaceout = spaceout.replace("%40","@");
                 spaceout = spaceout.replace("%24","$");
                 spaceout = spaceout.replace("%2B","+");
                 spaceout = spaceout.replace("+"," ");  
                 int zool = spaceout.indexOf(";",0);
         return spaceout.left(zool);;
}


/* grep nummer on [77] */
int  BraketNummer( QString braket )
{
    int esanummer = 0;
    if (braket.startsWith("[")) {
       braket.replace(QString("["), QString("")); 
       int zool = braket.indexOf("]",0); 
           if (zool > 0) {
              QString   xid = braket.left(zool);  
               if (is_numeric(xid)) {
                      bool ok; 
                      esanummer = xid.toInt(&ok);
               }
           }
    }
return esanummer;
}

/* remove dir recursive */
void DownDir_RM(const QString d)
{
   QDir dir(d);
   //////SqlLog("order to delete dir:"+d+" ");
   if (dir.exists())
   {
      const QFileInfoList list = dir.entryInfoList();
      QFileInfo fi;
      for (int l = 0; l < list.size(); l++)
      {
         fi = list.at(l);
         if (fi.isDir() && fi.fileName() != "." && fi.fileName() != "..")
            DownDir_RM(fi.absoluteFilePath());
         else if (fi.isFile())
         {
            qt_unlink(fi.absoluteFilePath());
            ///////if (!ret) {
               ////////SqlLog("Can't remove: " + fi.absoluteFilePath() + " (write-protect?)");
         } 
        
      }
     /////// SqlLog("Remove: " + d + " ");
      dir.rmdir(d);
      
   }
} 
/* simple md5 to found diffs */
QString myMd5( QString xml )
{
    QString str = xml;
    str.resize(38);
    QString upperd = str.toUpper();
    QByteArray text;
    text.append(upperd);
    QString parse = text.toBase64();
    parse.resize(12);
    QString md7 = parse;
    return md7;
}
void ResetDir()
{
    QDir::setCurrent(currentdir); 
}
protected:
private:
   QString currentdir;
 void Load_Connector()
{
currentdir = QDir::currentPath();   /* remember current path on start! */
}
signals:
public slots:

};
//
#endif // BASE_MODUL_H

