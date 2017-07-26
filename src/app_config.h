#ifndef APP_CONFIG_H
#define APP_CONFIG_H



#define WEBAGENTNAME "Google"
#define _PROGRAM_NAME_ QString("XHTML di Peter H.")
#define _PROGRAM_NAME_DOMAINE_ QString("qt.io")
#define _ORGANIZATION_NAME_ QString("PPK-Screendesign/Webprogramm")
#define _PROGRAM_VERSION_ QString("version 3.9.1 / go git")
#define _PROGRAM_OWNER_ QString("version 3.9.1")
#define _PROGRAM_TITLE_ QString("XHTML Editor version 3.9")
#define Q_WORKS_PEND QString("open")
#define _PROGRAM_SHORT_NAME QString("xhtmledit")
#define _WATERMARK_ QString("www.pulitzer.ch")
#define TUMNAIL_SIZE 120
#define PICS_SIZE_LIMIT 740
#define PICS_DISPLAY_LIMIT 300

#define WORK_CACHEDIR \
               QString( "%1/.%2/" ).arg(QDir::homePath(),_PROGRAM_SHORT_NAME)

#define IMM_BUILD \
               QString( "%1pics/" ).arg(WORK_CACHEDIR)


#define CURL_DIR \
               QString( "%1curl/" ).arg(WORK_CACHEDIR)
#define IMAGE_TMP_DIR \
               QString( "%1imgtmp/" ).arg(WORK_CACHEDIR)

#define LOGCURLSTDOUT \
               QString( "%1curl.log" ).arg(CURL_DIR)

#define _BASEDBDIR_ \
               QString( "%1user/" ).arg(WORK_CACHEDIR)
#define APPLICATION_SETTING \
               QString( "%1config.xml" ).arg(WORK_CACHEDIR)

#define APPLICATION_LOGS \
               QString( "%1/logfile.txt" ).arg(WORK_CACHEDIR)
#define UNZIPDIR \
               QString( "%1tmp/" ).arg(WORK_CACHEDIR)
#define _XML_STREAMS_ \
               QString( "%1/streams.xml" ).arg(WORK_CACHEDIR)

#define DEBUGFILE \
               QString( "%1/saypath.txt" ).arg(QDir::homePath())


#define LOGSQLERROR \
               QString( "%1curl.log" ).arg(QDir::currentPath())



#endif // APP_CONFIG_H
