#include "base_edit.h"
//
// mainwindow append here & base edit ... init to reorder file 4.7.2017
//

void MainWindow::setBaselightTxt(const QString &txt) {

  QObject *obj = sender();
  const QString namefrom = obj->objectName();
  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  qDebug() << "### sender from  " << namefrom;
  statusLabel->setText(txt);
}

MainWindow::~MainWindow() { this->deleteLater(); }

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  // create objects for the label and progress bar
  statusLabel = new QLabel(this);
  statusProgressBar = new QProgressBar(this);
  // set text for the label
  statusLabel->setText("Il Callo di strada...");
  // make progress bar text invisible
  statusProgressBar->setTextVisible(false);
  this->setStatusBar(new QStatusBar(this));
  /// statusBar()
  // add the two controls to the status bar
  statusBar()->addPermanentWidget(statusLabel);
  statusBar()->addPermanentWidget(statusProgressBar, 1);
}

Base_Edit::Base_Edit() {
  setupUi(this);
  vol_link->setCheckable(true);
  passage = 6;
  xytextpos = 0;
  lastscroll = 1;
  numeroimmagine = 0;
  bellavista = false;
  doc = new QTextDocument(this);
  textliner = sline->verticalScrollBar();
  textareatext = stext->verticalScrollBar();
  wysiwyg_sroll = wtext->verticalScrollBar();
  //////////fontComboBox->setMinimumWidth(55);
  connect(textliner, SIGNAL(valueChanged(int)), textareatext,
          SLOT(setValue(int)));
  connect(textareatext, SIGNAL(valueChanged(int)), textliner,
          SLOT(setValue(int)));
  connect(wysiwyg_sroll, SIGNAL(valueChanged(int)), this,
          SLOT(RamPosition_wysiwyg(int)));
  connect(textareatext, SIGNAL(valueChanged(int)), this,
          SLOT(RamPosition_source(int)));
  connect(stext, SIGNAL(textChanged()), this, SLOT(UpdateSourceLineNr()));
  connect(tabWidget, SIGNAL(currentChanged(int)), this,
          SLOT(SwapModeView(int)));
  connect(savecache, SIGNAL(clicked()), this, SLOT(SaveStream()));
  connect(vol_source, SIGNAL(clicked(bool)), this, SLOT(ModusView(bool)));
  connect(vol_img, SIGNAL(clicked()), this, SLOT(CreateanewImage()));
  connect(val_table, SIGNAL(clicked()), this, SLOT(CreateanewTable()));
  connect(mypaste, SIGNAL(clicked()), this, SLOT(Paste_All()));
  connect(vol_cut, SIGNAL(clicked()), this, SLOT(Cute_All()));
  connect(vol_copy, SIGNAL(clicked()), this, SLOT(Copy_All()));
  connect(vol_link, SIGNAL(clicked(bool)), this, SLOT(MakehrefLink()));
  connect(vol_undo, SIGNAL(clicked()), this, SLOT(Undo_All()));
  connect(vol_redo, SIGNAL(clicked()), this, SLOT(Redo_All()));
  connect(vol_br, SIGNAL(clicked(bool)), this, SLOT(MakeBreak()));
  connect(wtext, SIGNAL(IncommingHTML()), this,
          SLOT(Reload_Editor())); /* paste html extern ....*/

  //// connect(wtext, SIGNAL(SaveStreamer()), this, SLOT(SaveX()));
  //// connect(stext, SIGNAL(SaveStreamer()), this, SLOT(SaveX()));

  connect(wtext, SIGNAL(TakeImage(QString)), this, SLOT(PicsFromCopy(QString)));

  QShortcut *sxp1 = new QShortcut(this);
  sxp1->setKey(QKeySequence::Save);
  connect(sxp1, SIGNAL(activated()), this, SLOT(SaveStream()));
  QShortcut *shortopen = new QShortcut(this);
  shortopen->setKey(QKeySequence::Open);
  connect(shortopen, SIGNAL(activated()), this, SLOT(OpenNewDoc()));

  setAcceptDrops(true);
  html = "";
  sourcerun = false;
  editrun = true;
  wtext->clear();
  wtext->setReadOnly(false);
  wtext->setOpenExternalLinks(false);
  wtext->setContextMenuPolicy(Qt::CustomContextMenu);
  tabWidget->setCurrentIndex(0);
  emit statusMessage("Loading end...");
  AutoReload();
}

void Base_Edit::AutoReload() {

  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  ////  emit statusMessage(QString("Check html:
  ///%1").arg(UmanTimeFromUnix(QTime_Null())));
  /////  QTimer::singleShot(5000, this, SLOT(AutoReload()));
}

void Base_Edit::SaveX() {
  /////////// QMessageBox::warning(0, tr("Edit xhtml"),tr("Saved 0..."));
  SaveStream();
}

void Base_Edit::SaveStream() {
  emit statusMessage(QString("Save file ..%1..").arg(basefilestart)); ////
  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

  Refresh_Source();
  //// move image from cache!!!
  const QString goextern = html.replace(QString("src=\"%1").arg(imagecache),
                                        "src=\"./", Qt::CaseInsensitive);
  QApplication::restoreOverrideCursor();

  emit OnSave(goextern);
}

void Base_Edit::set_Cache(const QString path) {
  imagecache = path;
  if (!imagecache.endsWith("/")) {
    imagecache = imagecache.append("/");
  }
  if (imagecache.size() > 2) {
    ///////////////DownDir_RM(imagecache); /* clean cache if writable */
  } else {
    return;
  }
  const QString putindex = QString("%1index.xml").arg(imagecache);
  fwriteutf8(putindex, UmanTimeFromUnix(QTime_Null()));
}

void Base_Edit::OpenNewDoc() {
  QString im, argument;
  im = QFileDialog::getOpenFileName(this, tr("Select a xhtml file to edit "),
                                    "", "XHTML (*.xhtml *.html *.htm)");
  if (im.size() > 0) {
    SetFileBase(im);
  }
}

void Base_Edit::SetFileBase(QString file) {
  QString baseref, absolutefilepath;

  if (is_file(file)) {
    /* fix image path */
    const QString dirfromfile = file.left(file.lastIndexOf("/")) + "/";
    QString externhtml = fopenutf8(file);

    if (!externhtml.contains("qrichtext", Qt::CaseInsensitive)) {
      const QString tidicaches = QString("%2/.qtidy/").arg(QDir::homePath());
      QTidy *tidy = new QTidy(); /* QTidy  *tidy; */
      tidy->Init(tidicaches);    /* tidy cache remove on last event */
      externhtml = tidy->TidyExternalHtml(externhtml);
    }

    //// const QString goextern =
    /// externhtml.replace("src=\"./",QString("src=\"%1").arg(dirfromfile),Qt::CaseInsensitive);
    //// fwriteutf8(file,goextern);
    /* fix image path */

    QFileInfo fix(file);
    absolutefilepath = fix.absoluteFilePath();
    baseref = fix.absolutePath();
    if (!baseref.endsWith("/")) {
      baseref = baseref.append("/");
    }
  } else {
    return;
  }

  basefilepath = baseref;
  basefilestart = absolutefilepath;

  qDebug() << "#### aprifile html  ->" << basefilestart;

  set_XHTML(fopenutf8(basefilestart));
}

void Base_Edit::set_XHTML(const QString source) {
  html = source;
  Load_Xhtml();
  Refresh_Source();
}
void Base_Edit::Load_Xhtml() {
  ////////////////qDebug() << "### Load_Xhtml   ";
  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
  doc = new QTextDocument(this);
  doc->setHtml("");
  wtext->setDocument(doc);

  /////////// qDebug() << "#### imagecache  ->" << imagecache;
  ////////////// qDebug() << "#### basefilepath  ->" << basefilepath;

  lesshtml = new Html_Loader(html, imagecache, basefilepath);
  connect(lesshtml, SIGNAL(LoadedFlush()), this, SLOT(SetNewDoc()));
}

void Base_Edit::Paste_All() {
  int tabulator = tabWidget->currentIndex();
  if (tabulator == 0) {
    wtext->paste();
  } else {
    stext->paste();
  }
}
void Base_Edit::Copy_All() {
  int tabulator = tabWidget->currentIndex();
  if (tabulator == 0) {
    wtext->copy();
  } else {
    stext->copy();
  }
}

void Base_Edit::Cute_All() {
  int tabulator = tabWidget->currentIndex();
  if (tabulator == 0) {
    wtext->cut();
  } else {
    stext->cut();
  }
}

void Base_Edit::Undo_All() {
  int tabulator = tabWidget->currentIndex();
  if (tabulator == 0) {
    wtext->undo();
  } else {
    stext->undo();
  }
}

void Base_Edit::Redo_All() {
  int tabulator = tabWidget->currentIndex();
  if (tabulator == 0) {
    wtext->redo();
  } else {
    stext->redo();
  }
}

void Base_Edit::SwapModeView(int tabi) {
  lastcursor = wtext->textCursor();
  int tabulator = tabWidget->currentIndex();
  if (html.size() > 0) {
    if (tabulator == 0) {
      ShowModusPanelEdit(); /* edit mouse wymsyng */
    }
    if (tabulator == 1) {
      ShowModusPanelSourceView(); /* edit source */
    }
  }
}

void Base_Edit::RamPosition_source(int position) {
  if (position > 0) {
    slastscroll = position;
  }
}

void Base_Edit::RamPosition_wysiwyg(int position) {
  ////////////qDebug() << "### lastscroll   " << position;

  if (position > 0) {
    lastscroll = position;
  }
}

/* load base connection */
void Base_Edit::Load_Base_Connec() {}

void Base_Edit::SetNewDoc() {
  doc = new QTextDocument(this);
  doc = lesshtml->GetDoc();
  QStringList errorloist = lesshtml->GetErrors();
  wtext->setDocument(doc);
  wtext->setFontFamily("Arial");
  QApplication::restoreOverrideCursor();
  editrun = true;
  if (lastscroll > 0) {
    wysiwyg_sroll->setValue(lastscroll);
  }
}

/*  write line nr..... */
void Base_Edit::UpdateSourceLineNr() {
  QString lineNumbers = "";
  int i;
  int numberOfLines = 0;
  QString sorgente = stext->toPlainText();
  numberOfLines = sorgente.count(QRegExp("\n"));
  for (i = 1; i <= numberOfLines + 1; i++) {
    if (i < 999) {
      lineNumbers.append(QString::number(i) + "#\n");
    } else {
      lineNumbers.append("#\n");
    }
  }
  sline->setPlainText(lineNumbers);
  sline->toPlainText();
}

void Base_Edit::BaseButton_Switsch() {

  vol_print->setEnabled(buttoneditrun);
  vol_pdf->setEnabled(buttoneditrun);
  vol_html->setEnabled(buttoneditrun);
  vol_link->setEnabled(buttoneditrun);
  vol_bold->setEnabled(buttoneditrun);
  vol_italic->setEnabled(buttoneditrun);
  vol_underline->setEnabled(buttoneditrun);
  vol_left->setEnabled(buttoneditrun);
  vol_center->setEnabled(buttoneditrun);
  vol_right->setEnabled(buttoneditrun);
  vol_justify->setEnabled(buttoneditrun);
  val_table->setEnabled(buttoneditrun);
  vol_img->setEnabled(buttoneditrun);
  fontsize->setEnabled(buttoneditrun);
  fontname->setEnabled(buttoneditrun);
  list_ul->setEnabled(buttoneditrun);
  vol_color->setEnabled(buttoneditrun);
  vol_br->setEnabled(buttoneditrun);
  vol_link->setEnabled(buttoneditrun);
}

void Base_Edit::SwaptoSource() { ModusView(true); }

void Base_Edit::SwaptoEdit() { ModusView(false); }

void Base_Edit::ModusView(bool src) {
  if (src) {
    tabWidget->setCurrentIndex(1);
  } else {
    tabWidget->setCurrentIndex(0);
  }
}

/* ##########################  view & source && edit modus
 * #################################*/
/* ##########################  view & source && edit modus
 * #################################*/
/* ##########################  view & source && edit modus
 * #################################*/
/* ##########################  view & source && edit modus
 * #################################*/
/* ##########################  view & source && edit modus
 * #################################*/

void Base_Edit::ShowModusPanelEdit() {
  /* update source make job and take html */
  Refresh_Source();
  editrun = true;
  sourcerun = false;
  buttoneditrun = true;
  bellavista = false;
  BaseButton_Switsch();
  wtext->clear();
  wtext->setReadOnly(false);
  wtext->setOpenExternalLinks(false);
  Load_Xhtml();
  vol_source->setChecked(false);
  if (lastscroll > 0) {
    wysiwyg_sroll->setValue(lastscroll);
  }
  tabWidget->setCurrentIndex(0);
  tabWidget->setTabIcon(0, QIcon(QString::fromUtf8(":/img/icon.png")));
}
void Base_Edit::ShowModusPanelView() {
  Refresh_Source();
  editrun = true;
  sourcerun = false;
  buttoneditrun = false;
  bellavista = true;
  BaseButton_Switsch();
  /////////// qDebug() << "### ed html   " << html;
  /////////////qDebug() << "### ed modus   editrun->" << editrun << "
  /// sourcerun->" << sourcerun;
  tabWidget->setCurrentIndex(0);
  tabWidget->setTabIcon(0, QIcon(QString::fromUtf8(":/img/html_div.png")));
  wtext->clear();
  wtext->setReadOnly(true);
  wtext->setOpenExternalLinks(true);
  Load_Xhtml();
  vol_source->setChecked(false);
  if (lastscroll > 0) {
    wysiwyg_sroll->setValue(lastscroll);
  }
  tabWidget->setCurrentIndex(0);
}
void Base_Edit::ShowModusPanelSourceView() {
  Refresh_Source();
  editrun = false;
  sourcerun = true;
  buttoneditrun = false;
  BaseButton_Switsch();
  tabWidget->setCurrentIndex(1);
  tabWidget->setTabIcon(1, QIcon(QString::fromUtf8(":/img/view-source.png")));
  ///////////qDebug() << "### so html   " << html;
  /////////////qDebug() << "### so modus   editrun->" << editrun << "
  /// sourcerun->" << sourcerun;
  highlight = new XmlHighlighter(stext->document());
  stext->clear();
  stext->setReadOnly(false);
  stext->insertPlainText(html);
  vol_source->setChecked(true);

  if (slastscroll > 0) {
    textareatext->setValue(slastscroll);
  }
  tabWidget->setCurrentIndex(1);
}

/*
connect( textliner, SIGNAL(valueChanged(int)), textareatext,
SLOT(setValue(int))); connect( textareatext, SIGNAL(valueChanged(int)),
textliner, SLOT(setValue(int))); connect( wysiwyg_sroll,
SIGNAL(valueChanged(int)), this, SLOT(RamPosition_wysiwyg(int))); connect(
textareatext, SIGNAL(valueChanged(int)), this, SLOT(RamPosition_source(int)));
    connect( stext, SIGNAL(textChanged()), this, SLOT( UpdateSourceLineNr() ));
    connect(vol_source, SIGNAL(clicked(bool)), this, SLOT(SwapModeView(int)));

*/

/* ##########################  view & source && edit modus
 * #################################*/
/* ##########################  view & source && edit modus
 * #################################*/
/* ##########################  view & source && edit modus
 * #################################*/
/* ##########################  view & source && edit modus
 * #################################*/
/* ##########################  view & source && edit modus
 * #################################*/

void Base_Edit::RedirectToUrl(QUrl loc) {
#if defined Q_WS_WIN
  QString winbuh = DesktopFile(loc.toString());
  bool wr = QDesktopServices::openUrl(QUrl(winbuh));
  if (!wr) {
    QMessageBox::warning(
        0, tr("Error"),
        tr("Unable to open file or dir  %1").arg(loc.toString()));
  }
  return;
#endif
  bool r = QDesktopServices::openUrl(loc);
  if (!r) {
    QMessageBox::warning(
        0, tr("Error"),
        tr("Unable to open file or dir  %1").arg(loc.toString()));
  }
}

void Base_Edit::Refresh_Source() {
  passage++;
  if (html.size() > 0) {
    if (editrun) {
      QString xhtmlsource = html;
      QString xhtmlsource1 = doc->toHtml(QByteArray("utf-8"));
      int totahtml = xhtmlsource.size();
      int totahtml1 = xhtmlsource1.size();
      ////////////// qDebug() << "### p." << passage << " totahtml   0=" <<
      /// totahtml << " 1=" << totahtml1;

      if (totahtml != totahtml1) {
        html = xhtmlsource1;
        html = html.replace("</p>", "</p>\n");
        html = html.replace("</span>", "</span>\n");
        html = html.replace("</head>", "</head>\n\n");
        html = html.replace("</body>", "\n\n</body>\n");
      }
    }
    ////////////////qDebug() << "### 1p." << passage << " htmlsize   base=" <<
    /// html.size();
    if (sourcerun) {
      html = stext->toPlainText();
    }
    ////////////qDebug() << "### 2p." << passage << " htmlsize   base=" <<
    /// html.size();
  } else {
    /////////////////qDebug() << "### doc vuoto
    ///...#################################################";
  }

  //////////////////qDebug() << "### Refresh_Source end   htmlsize->"  <<
  /// html.size()    <<     " editrun->" << editrun << " sourcerun->" <<
  /// sourcerun;
}

void Base_Edit::dragEnterEvent(QDragEnterEvent *event) {
  //////////qDebug() << "### dragEnterEvent " << event;
  event->acceptProposedAction();
}
void Base_Edit::dropEvent(QDropEvent *event) {
  ////////////qDebug() << "### dropEvent " << event;

  if (event && event->mimeData()) {
    Grabdata(event->mimeData());
  }
}

void Base_Edit::CleanCache() {
  if (imageincommingcache.size() > 0) {
    /////qt_unlink(imageincommingcache);
    imageincommingcache = "";
  }
}

void Base_Edit::PicsFromCopy(const QString filenew) {
  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  imageincommingcache = filenew;
  ///// QTimer::singleShot(2000, this, SLOT(CleanCache()));   /* wait to write
  /// ready image on disk cache */
  qDebug() << "### entra PicsFromCopy " << filenew;
  Create_New_Image_Tag(filenew);
  Reload_Editor();
}

void Base_Edit::Grabdata(const QMimeData *data) {
  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  if (!data) {
    return;
  }

  if (!editrun) {
    QMessageBox::warning(this, tr("Error"),
                         tr("Pleas Drag on edit modus... on View Modus is not "
                            "possibel to insert items!"));
    return;
  }

  if (data->hasImage()) {
    numeroimmagine++;

    const QString nuovaimmagine =
        QString("%2image_%1.png").arg(numeroimmagine).arg(WORK_CACHEDIR);
    QImage images = qvariant_cast<QImage>(data->imageData());
    bool salvato = images.save(nuovaimmagine, "PNG", 100);
    /////////qDebug() << "###salva in cartella    " << nuovaimmagine;
    ////////////////qDebug() << "###s alvato   " << salvato;

    if (salvato) {
      Create_New_Image_Tag(nuovaimmagine);
      Reload_Editor();
    }

    return;
  }

  if (data->formats().contains("text/html")) {
    ////////////////qDebug() << "### incomming drag text/html  ";
    QString draghtml = data->html();
    QTextDocumentFragment fragment = QTextDocumentFragment::fromHtml(draghtml);
    wtext->textCursor().insertFragment(fragment);
    if (draghtml.contains("<img", Qt::CaseInsensitive)) {
      Reload_Editor(); /* to grab image like firefox */
    }
    ////////////// qDebug() << "### draghtml   " << draghtml;
    return;
  }

  if (data->formats().contains("text/plain")) {
    ////////////////qDebug() << "### incomming drag text/html  ";
    QString draghtml = data->text();
    draghtml = draghtml.replace("\n", "<br/>");
    QTextDocumentFragment fragment =
        QTextDocumentFragment::fromHtml(QString("<p>%1</p>").arg(draghtml));
    wtext->textCursor().insertFragment(fragment);
    return;
  }

  QStringList urlmixed;
  urlmixed.clear();

  QList<QUrl> urlelist;
  if (data->hasUrls()) {
    urlelist = data->urls();
    for (int i = 0; i < urlelist.size(); ++i) {
      QUrl gettyurl(urlelist.at(i));
      if (gettyurl.isValid()) {
        QString shema = gettyurl.scheme();
        ///////qDebug() << "### shema   " << shema;
        //////////qDebug() << "### gettyurl  " << gettyurl;
        if (shema == "file") {
          urlmixed.append(QString(gettyurl.toLocalFile()));
        } else {
          urlmixed.append(QString(gettyurl.toString()));
        }
      }
    }
    for (int i = 0; i < urlmixed.size(); ++i) {
      QString itemimage = urlmixed.at(i);
      Create_New_Image_Tag(itemimage);
      //////////////////qDebug() << "### itemimage  " << itemimage;
    }
  }

#if defined Q_WS_MAC
  Reload_Editor();
#endif
#if defined Q_WS_WIN
  /////////qDebug() << "### wait on save time time..........  " <<
  /// urlmixed.size();
  QTimer::singleShot(
      300, this,
      SLOT(Reload_Editor())); /* wait to write ready image on disk cache */
#endif
#if defined Q_WS_X11
  Reload_Editor();
#endif
}

void Base_Edit::Reload_Editor() {
  if (editrun) {
    lastcursor = wtext->textCursor();
    Refresh_Source();
    Load_Xhtml();
    if (!lastcursor.isNull()) {
      wtext->setTextCursor(lastcursor);
    }
  }
}

/* void QTextCursor::setPosition ( int pos, MoveMode m = MoveAnchor )  */

/*  Image tag img  functions  manipulator
 * ################################################################### */
/*  Image tag img  functions  manipulator
 * ################################################################### */

void Base_Edit::Create_New_Image_Tag(const QString urlremoteorlocal) {
  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  if (image_extension(urlremoteorlocal)) {
    QString subtext = QString("<p><img src=\"%1\" />").arg(urlremoteorlocal);
    QTextDocumentFragment fragment = QTextDocumentFragment::fromHtml(subtext);
    wtext->textCursor().insertFragment(fragment);
    emit statusMessage(QString("Image new : %1").arg(urlremoteorlocal));
  }
}

void Base_Edit::Image_mod_Setting() {
  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  /* QTextImageFormat nowimage;  */
  if (nowimage.isValid()) {
    Interface::self(this)->SetFormat(nowimage);
    Interface::self(this)->exec();
    QTextImageFormat newforminepic = Interface::self(this)->GetFormat();
    if (newforminepic.isValid()) {

      ///////////////newforminepic.setAnchorHref("http://www.trolltech.com/index.htm");
      ////////////nowimage = newforminepic;
      /*  QTextCursor lastcursor;   ( last cursor ) */
      lastcursor.setCharFormat(newforminepic);
      ////////////////qDebug() << "### Draw image h ... " << nowimage.height();
      ///////////////// qDebug() << "### Draw image w... " << nowimage.width();
      Reload_Editor();
      /* http://www.qtcentre.org/forum/f-qt-programming-2/t-loading-images-in-qtextbrowser-5046.html/?highlight=QTextImageFormat
       */
    }
  }
}

void Base_Edit::CreateanewImage() {
  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  QString fileimg = QFileDialog::getOpenFileName(
      this, tr("Choose Image"), QString(setter.value("LastDir").toString()),
      tr("Image Files supported (*)"));

  if (fileimg.isEmpty()) {
    return;
  }

  QImage base(fileimg);
  if (base.isNull() || !image_extension(fileimg)) {
    QMessageBox::warning(
        this, tr("Image Plugin"),
        tr("Pleas install the plugin for this format.. or select other..\nOr "
           "copy and paste image from your images application. \nTo convert on "
           "web image. png jpg gif"));
    RedirectToUrl(QUrl(fileimg));
    return;
  }

  QString pathimage = fileimg.left(fileimg.lastIndexOf("/")) + "/";
  setter.setValue("LastDir", pathimage);

  Create_New_Image_Tag(fileimg);
  Reload_Editor();
}

/*  Table functions  manipulator
 * ################################################################### */
/*  Table functions  manipulator
 * ################################################################### */
/*  Table functions  manipulator
 * ################################################################### */
/*  Table functions  manipulator
 * ################################################################### */
/*  Table functions  manipulator
 * ################################################################### */
/*  Table functions  manipulator
 * ################################################################### */
/*  Table functions  manipulator
 * ################################################################### */
/*  Table functions  manipulator
 * ################################################################### */

/* insert table   */
void Base_Edit::CreateanewTable() {

  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  QString subtext, collx, rowx;
  bool ok;
  int colonne = QInputDialog::getInt(this, tr("New Table cool"), tr("Cool:"), 3,
                                     1, 10, 1, &ok);
  int righe = QInputDialog::getInt(this, tr("New Table row"), tr("Row:"), 3, 1,
                                   100, 1, &ok);
  int largo = QInputDialog::getInt(this, tr("New Table percent on page"),
                                   tr("Percent \%:"), 100, 10, 100, 1, &ok);
  if (colonne > 0 and righe > 0 and largo > 0) {
    QStringList tables;
    tables.clear();
    tables.append(
        QString("<table border=\"1\" align=\"center\" width=\"%1%\" "
                "cellspacing=\"0\" cellpadding=\"0\" bgcolor=\"#ffffff\">")
            .arg(largo));
    for (int i = 0; i < righe; i++) {
      tables.append(QString("<tr>"));
      for (int o = 0; o < colonne; o++) {
        tables.append(QString("<td><p></p></td>"));
      }
      tables.append(QString("</tr>"));
    }
    tables.append(QString("</table>"));

    subtext = tables.join("\n");
    QTextDocumentFragment fragment = QTextDocumentFragment::fromHtml(subtext);
    wtext->textCursor().insertFragment(fragment);
  }
}

void Base_Edit::TableSetting() {
  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;
  QTextCursor findercursor(wtext->textCursor());
  Etable = findercursor.currentTable();
  if (Etable) {
    Table_Setting::self(this)->SetFormat(nowtable);
    Table_Setting::self(this)->exec();
    QTextTableFormat newformine = Table_Setting::self(this)->GetNewFormats();
    if (newformine.isValid()) {
      nowtable->setFormat(newformine);
    }
  }
}

void Base_Edit::MergeCellByCursorPosition() {
  QTextCursor findercursor(wtext->textCursor());
  Etable = findercursor.currentTable();
  if (Etable) {
    nowtable->mergeCells(findercursor);
  }
}

void Base_Edit::RemoveRowByCursorPosition() {
  QTextCursor findercursor(wtext->textCursor());
  Etable = findercursor.currentTable();
  if (Etable) {
    QTextTableCell existingcell = nowtable->cellAt(findercursor);
    int cellcoolcursoris =
        existingcell.column();                /* int value start from zero */
    int cellrowcursoris = existingcell.row(); /* int value start from zero */
    nowtable->removeRows(cellrowcursoris, 1);
  }
}

void Base_Edit::RemoveCoolByCursorPosition() {
  QTextCursor findercursor(wtext->textCursor());
  Etable = findercursor.currentTable();
  if (Etable) {
    QTextTableCell existingcell = nowtable->cellAt(findercursor);
    int cellcoolcursoris =
        existingcell.column();                /* int value start from zero */
    int cellrowcursoris = existingcell.row(); /* int value start from zero */
    nowtable->removeColumns(cellcoolcursoris, 1);
  }
}

void Base_Edit::AppendTableRows() {
  bool ok = false;
  QTextCursor findercursor(wtext->textCursor());
  Etable = findercursor.currentTable();
  if (Etable) {
    QTextTableCell existingcell = nowtable->cellAt(findercursor);
    int cellcoolcursoris =
        existingcell.column();                /* int value start from zero */
    int cellrowcursoris = existingcell.row(); /* int value start from zero */
    int approwtot = QInputDialog::getInt(this, tr("Append NR. line row"),
                                         tr("Row:"), 1, 1, 100, 1, &ok);
    if (ok and approwtot > 0) {
      nowtable->insertRows(cellrowcursoris + 1, approwtot);
    }
  }
}

void Base_Edit::AppendTableCools() {
  bool ok = false;
  QTextCursor findercursor(wtext->textCursor());
  Etable = findercursor.currentTable();
  if (Etable) {
    QTextTableCell existingcell = nowtable->cellAt(findercursor);
    int cellcoolcursoris =
        existingcell.column();                /* int value start from zero */
    int cellrowcursoris = existingcell.row(); /* int value start from zero */
    int appcooltot = QInputDialog::getInt(this, tr("Tabella appendi colonne"),
                                          tr("Cool:"), 1, 1, 10, 1, &ok);
    if (ok and appcooltot > 0) {
      nowtable->insertColumns(cellcoolcursoris + 1, appcooltot);
    }
  }
}

void Base_Edit::OpenDesktop(QUrl loc) {
////////////qDebug() << "### OpenDesktop ............." << loc;
////////////qDebug() << "### OpenDesktop ............." << loc.toString();
#if defined Q_WS_WIN
  QString winbuh = DesktopFile(loc.toString());
  ////////qDebug() << "### winbuh ............." << winbuh;
  bool wr = QDesktopServices::openUrl(QUrl(winbuh));
  if (!wr) {
    QMessageBox::warning(
        this, tr("Error"),
        tr("Unable to open file or dir  %1").arg(loc.toString()));
  }
  return;
#endif
  bool r = QDesktopServices::openUrl(loc);
  if (!r) {
    QMessageBox::warning(
        this, tr("Error"),
        tr("Unable to open file or dir  %1").arg(loc.toString()));
  }
}

void Base_Edit::MakeBreak() {
  const QString breaker = "<br />";
  QTextDocumentFragment fragment = QTextDocumentFragment::fromHtml(breaker);
  wtext->textCursor().insertFragment(fragment);
}

void Base_Edit::MakehrefLink() {
  bool is_selected = wtext->textCursor().hasSelection();
  QString sthtml = wtext->textCursor().selectedText();
  if (vol_link->isChecked()) {
    QString ltext, linkerma, hrefprimo, satarget;
    if (sthtml.size() < 1) {
      sthtml = "Text to link";
    }
    Href_Gui::self(this)->text_href->setText(sthtml);
    Href_Gui::self(this)->exec();
    if (Href_Gui::self) {
      QStringList data = Href_Gui::_self->GetUserConfig();
      if (data.count() > 0) {
        /*qDebug() << "### linerr rrr   " << QString(data.at(0));
        qDebug() << "### linerr rrr   " << QString(data.at(1));
        qDebug() << "### linerr rrr   " << QString(data.at(2));*/
        hrefprimo = QString(data.at(1));
        satarget = QString(data.at(2));

        if (hrefprimo.startsWith("#")) {
          linkerma = hrefprimo;
        } else {
          if (!hrefprimo.contains("@") or !hrefprimo.contains("mailto:")) {
            linkerma = hrefprimo + "#target=" + satarget;
          } else {
            linkerma = hrefprimo;
          }
        }
        if (satarget != "#name") {
          ltext =
              "<a href=\"" + linkerma + "\">" + QString(data.at(0)) + "</a>";
        } else {
          hrefprimo.replace("#", "");
          hrefprimo.replace(" ", "");

          ltext = "<a name=\"" + hrefprimo + "\"></a> " + QString(data.at(0));
        }
        QTextDocumentFragment fragment = QTextDocumentFragment::fromHtml(ltext);
        wtext->textCursor().insertFragment(fragment);
        vol_link->setChecked(false);
      }
    }
  } else {
    QTextDocumentFragment fragment = QTextDocumentFragment::fromHtml(sthtml);
    wtext->textCursor().insertFragment(fragment);
  }
}
