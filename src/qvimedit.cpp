#include "qvimedit.h"
#include "app_config.h"
#include <QDesktopWidget>

//
/*  Save file as qvimedit.cpp  */
/*  incomming class name QVimedit */
//

QVimedit::QVimedit(QWidget *parent) : QTextBrowser(parent) {
  numerobase = 0;
  shortcut0 = new QShortcut(QKeySequence(tr("Ctrl+W", "Print Screen")), this);
  connect(shortcut0, SIGNAL(activated()), this, SLOT(MakePrintScreen()));
  shortcut1 = new QShortcut(QKeySequence("F2"), this);
  connect(shortcut1, SIGNAL(activated()), this, SLOT(SaveCurrentDoc()));
  setContentsMargins(20, 20, 20, 20);
}

QVimedit::~QVimedit() { numerobase = 0; }

void QVimedit::SaveCurrentDoc() { emit SaveStreamer(); }

void QVimedit::PrintScreen() {
  QDesktopWidget *dw = QApplication::desktop();
  QPixmap desktopscreen =
      QPixmap::grabWindow(dw->winId(), 0, 0, dw->width(), dw->height());
  numerobase++;
  const QString nuovaim =
      QString("%2/image_%1.png").arg(numerobase).arg(QDir::homePath());
  desktopscreen.save(nuovaim, "PNG", 100);
  emit TakeImage(nuovaim); /* and remove nuovaim  */
}

void QVimedit::MakePrintScreen() {
  bool ok;
  int i = QInputDialog::getInt(
      0, tr("Wait Sec. to PrintScreen...."),
      tr("Wait Sec. to PrintScreen....<br>Sec: from 1/10"), 1, 1, 10, 1, &ok);
  if (ok && i > 0 && i < 11) {
    QTimer::singleShot(i * 1000, this, SLOT(PrintScreen()));
  }
}

bool QVimedit::canInsertFromMimeData(const QMimeData *source) {
  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  return QTextEdit::canInsertFromMimeData(source);
}

void QVimedit::keyPressEvent(QKeyEvent *e) { QTextBrowser::keyPressEvent(e); }

void QVimedit::mouseDoubleClickEvent(QMouseEvent *e) {
  qDebug() << "### mouseDoubleClickEvent ";
  emit DDClick();
  QTextEdit::mouseDoubleClickEvent(e);
}

void QVimedit::insertFromMimeData(const QMimeData *source) {
  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  if (source->hasImage()) {
    numerobase++;
    QDateTime timer1(QDateTime::currentDateTime());
    const qint64 secsince70 = timer1.currentMSecsSinceEpoch();
    QString pathx = IMM_BUILD;
    pathx.append("im_");
    pathx.append(QString("%1").arg(secsince70));
    pathx.append("_mime_");
    pathx.append(QString("%1.png").arg(numerobase));
    const QString nuovaim = pathx;

    qDebug() << "### nuovaim... " << nuovaim;

    QImage images = qvariant_cast<QImage>(source->imageData());
    bool salvato = images.save(nuovaim, "PNG", 100);
    if (salvato) {
      emit TakeImage(nuovaim);
    }
    return;
  }

  if (source->formats().contains("text/html")) {
    ////////qDebug() << "### incomming paste text/html  ";
    const QString tidicaches = QString("%2/.qtidy/").arg(QDir::homePath());
    QString draghtml = source->html();
    /* fwriteutf8(QString fullFileName,QString xml) */
    QTidy *tidy = new QTidy(); /* QTidy  *tidy; */
    tidy->Init(tidicaches);    /* tidy cache remove on last event */
    const QString xhtmlnew = tidy->TidyExternalHtml(draghtml);
    ///////fwriteutf8("copy_in.html",xhtmlnew);
    QTextDocumentFragment fragment = QTextDocumentFragment::fromHtml(xhtmlnew);
    textCursor().insertFragment(fragment);
    emit IncommingHTML();
    return;
  }
}
