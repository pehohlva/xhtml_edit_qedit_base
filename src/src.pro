######################################################################
# Automatically generated by qmake (2.01a) mer 14. mar 23:01:02 2007
######################################################################

TEMPLATE = app
TARGET = XHTML_Editor
DESTDIR	+= ../
DEPENDPATH += .
INCLUDEPATH += .

MOC_DIR	= build/.moc
RCC_DIR	= build/.rcc
OBJECTS_DIR = build/.obj
UI_DIR	= ui

CONFIG   += qt warn_off release
######################win32:debug { CONFIG += console }

QT += xml
QT += network widgets printsupport
QT += sql

win32:RC_FILE = win.rc
macx:RC_FILE = VolumeIcon.icns


INCLUDEPATH += ../libhtml
DEPENDPATH += ../libhtml
INCLUDEPATH += ../libhtml/include
DEPENDPATH += ../libhtml/include
LIBS += ../all_os_libs/libtidy.a

# Input
HEADERS += base_edit.h \
           base_modul.h \
           edit_html.h \
           interface.h \
           href_gui.h \
           href_start.h \
           html_loader.h \
           main.h \
           qvimedit.h \
           table_setting.h \
           baseui.h \
           ui_edit_html.h \
           ui_table_setting.h \
           xmlhighlighter.h \
           app_config.h
FORMS += ui/edit_html.ui
SOURCES += base_edit.cpp \
           edit_html.cpp \
           interface.cpp \
           href_gui.cpp \
           main.cpp \
           qvimedit.cpp \
           table_setting.cpp \
           xmlhighlighter.cpp
           
RESOURCES += attach.qrc




TRANSLATIONS += locale/edit_de.ts \
                locale/edit_en.ts \
                locale/edit_fr.ts \
                locale/edit_it.ts







