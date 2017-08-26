#include "interface.h"
//
/*  Save file as interface.cpp  */
/*  incomming class name Interface */
//

#include <QCloseEvent>
//
QPointer<Interface> Interface::_self = 0L;
//
Interface *Interface::self(QWidget *parent) {
  if (!_self)
    _self = new Interface(parent);
  return _self;
}

void Interface::PrintScreen() {
  QDesktopWidget *desk = qApp->desktop();
  QPixmap desktopscreen = QPixmap::grabWindow(desk->screen()->winId());
  desktopscreen.save(origImageFilename, extension.data(), qualvalue->value());
  BaseReset();
  showMaximized();
}

void Interface::MakePrintScreen() {
  bool ok;
  int i = QInputDialog::getInt(
      this, tr("Wait Sec. to PrintScreen...."),
      tr("Wait Sec. to PrintScreen....<br>Sec: from 1/10"), 1, 1, 10, 1, &ok);
  if (ok && i > 0 && i < 11) {
    QTimer::singleShot(i * 1000, this, SLOT(PrintScreen()));
  }
}

Interface::Interface(QWidget *parent) : QDialog(parent) {
  setWindowFlags(Qt::Window);
  setWindowModality(Qt::ApplicationModal);
  setupUi(this);
  setWindowTitle(tr("Image minimal editor"));
  pushButton->setText(tr("Save and Exit"));
  pushButton->setToolTip(tr("Only save CTRL+S"));
  airotato = false;
  cento = 100.0;
  onwi = false;
  rotazione = 0;
  ratio = cento;
  CTRL_Pressed = false;
  moverecci = false;
  Dstart = QPoint(0, 0);
  wrapper = new Foto_DD(this);
  scrolla->setWidget(wrapper);
  scrolla->setBackgroundRole(QPalette::Dark);

  QRect areaplace(QPoint(0, 0), QPoint(0, 0));
  TagliaPoi = areaplace;

  sx1 = scrolla->verticalScrollBar();
  sx2 = scrolla->horizontalScrollBar();

  connect(wrapper, SIGNAL(PrMouse(QMouseEvent *)), this,
          SLOT(Mousepress(QMouseEvent *)));
  connect(wrapper, SIGNAL(MoMouse(QMouseEvent *)), this,
          SLOT(Mousemove(QMouseEvent *)));
  populateWithColors(comboBox);
  color1 = qvariant_cast<QColor>(currentItemData(comboBox));
  connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SetColor()));
  connect(horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(SetZoom(int)));

  connect(horizontalSlider_2, SIGNAL(sliderReleased()), this,
          SLOT(misurecambiaA()));
  connect(horizontalSlider_3, SIGNAL(sliderReleased()), this,
          SLOT(misurecambiaL()));
  connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(misurecambiaA()));
  connect(spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(misurecambiaL()));

  connect(spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(setRotate(int)));
  connect(pushButton, SIGNAL(clicked()), this, SLOT(BaseSave()));
  connect(pushButton_2, SIGNAL(clicked()), this, SLOT(CropNow()));

  connect(comboBox_2, SIGNAL(currentIndexChanged(QString)), this,
          SLOT(applyFilter(QString)));

  populateFilter(comboBox_2);
}

void Interface::SetFormat(QTextImageFormat e) {
  nowimage = e;
  SetPic(e.name());
}

QTextImageFormat Interface::GetFormat() {
  nowimage.setHeight(HighteReal);
  nowimage.setWidth(LargeReal);
  return nowimage;
}

void Interface::SetPic(const QString pic) {
  origImageFilename = pic;
  QFileInfo ImageInfo(pic);
  fi = ImageInfo;
  QString ext = ImageInfo.completeSuffix();
  ext.toUpper();
  extension = ext.toLocal8Bit();
  display = QPixmap(pic);
  original = QPixmap(pic);
  original2 = original;
  ///////////////QApplication::clipboard()->setImage(original.toImage(),QClipboard::Clipboard);
  wrapper->paint(display);
  spinBox_3->setValue(ratio);
  LargeReal = original.width();
  HighteReal = original.height();
  cento = 100.0;
  rotazione = 0;
  ratio = cento;

  CTRL_Pressed = false;
  moverecci = false;
  Top_startX = 0;
  QRect areaplace(QPoint(0, 0), QPoint(0, 0));
  TagliaPoi = areaplace;
  UpdateNow();
  /////////////////qDebug() << "####### size().width()  " << size().width();
  int nuovadim;
  if (LargeReal > size().width()) {
    nuovadim = ratio = (size().width() * cento) / LargeReal;
    ////////////qDebug() << "####### ratio sp   " << nuovadim;
    spinBox_3->setValue(ratio);
    SetZoom(nuovadim);
    return;
  }
}

void Interface::misurecambiaA() {
  if (!onwi) {
    setMesure(spinBox->value(), 0);
  }
}

void Interface::misurecambiaL() {
  if (!onwi) {
    setMesure(spinBox_2->value(), 1);
  }
}

void Interface::setMesure(int w, int mode) {
  onwi = true;
  QPixmap resized;
  QPixmap picsa(origImageFilename);
  if (mode == 0) {
    resized = picsa.scaledToWidth(w);
  } else {
    resized = picsa.scaledToHeight(w);
  }
  ratio = 100.0;
  display = resized;
  original = resized;
  original2 = resized;
  SetZoom(100);
}

void Interface::setRotate(int r) {
  if (r < 360) { /* -360   - 360  */
    rotazione = r;
    /////QPixmap base(origImageFilename);
    QImage base(origImageFilename);
    int massimo =
        QMAX(base.width(), base.height()); /* find  max cube from image */
    int fotox = (massimo / 2) - (base.width() / 2);
    int fotoy = (massimo / 2) - (base.height() / 2);
    QPixmap nuovo(massimo, massimo);
    QPainter painter;
    painter.begin(&nuovo);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate((massimo / 2), (massimo / 2));
    painter.rotate(r);
    painter.translate(-(massimo / 2), -(massimo / 2));
    /////painter.drawPixmap(fotox,fotoy,base);
    painter.drawImage(fotox, fotoy, base, Qt::MonoOnly);
    painter.end();
    int newlarge = (massimo / cento) * ratio;
    display = nuovo.scaledToWidth(newlarge, Qt::FastTransformation);
    original = nuovo;

    wrapper->paint(display);
    ////////SetZoom( ratio );
    airotato = true;
  }
}

void Interface::resizeEvent(QResizeEvent *) {
  wrapper->setMinimumSize(original.width(), original.height());
}

void Interface::BaseReset() {
  if (origImageFilename.size() > 0) {
    SetPic(origImageFilename);
    SetZoom(ratio);
  }
  sx1->setValue(0);
  sx2->setValue(0);
  Top_startX = 0;
  QApplication::restoreOverrideCursor();
}

void Interface::TmpSave() {
  if (TagliaPoi.width() > 10) {
    SetZoom(ratio);
  }
  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

  Top_startX = 0;

  QRect areaplace(QPoint(0, 0), QPoint(0, 0));
  TagliaPoi = areaplace;

  if (origImageFilename.size() > 0) {
    ratio = 100.0;
    original.save(origImageFilename, extension.data(), qualvalue->value());
    rotazione = 0;
    spinBox_4->setValue(rotazione);
    BaseReset();
  }
  QApplication::restoreOverrideCursor();
}

void Interface::BaseSave() {
  if (TagliaPoi.width() > 10) {
    SetZoom(ratio);
  }

  Top_startX = 0;

  QRect areaplace(QPoint(0, 0), QPoint(0, 0));
  TagliaPoi = areaplace;

  if (origImageFilename.size() > 0) {
    ratio = 100.0;
    original.save(origImageFilename, extension.data(), qualvalue->value());
    rotazione = 0;
    spinBox_4->setValue(rotazione);
    BaseReset();
  }
  accept();
}

void Interface::CropNow() {
  if (TagliaPoi.width() > 5) {
    original = original2.copy(TagliaPoi);
    TmpSave();
  }
  sx1->setValue(0);
  sx2->setValue(0);
  Top_startX = 0;
}

//

void Interface::UpdateNow() {

  QDateTime lastm = fi.lastModified();

  spinBox_3->setValue(ratio);
  LargeReal = original2.width();
  HighteReal = original2.height();

  spinBox->setValue(LargeReal);
  spinBox_2->setValue(HighteReal);

  horizontalSlider_2->setValue(LargeReal);
  horizontalSlider_3->setValue(HighteReal);
  /*
  connect(horizontalSlider_2, SIGNAL(sliderReleased()), this,
SLOT(misurecambiaA())); connect(horizontalSlider_3, SIGNAL(sliderReleased()),
this, SLOT(misurecambiaL())); connect(spinBox, SIGNAL(valueChanged(int)), this,
SLOT(misurecambiaA())); connect(spinBox_2, SIGNAL(valueChanged(int)), this,
SLOT(misurecambiaL()));

*/

  spinBox_4->setValue(rotazione);

  if (Top_startX > 0) {
    pushButton_2->setEnabled(true);
    imgcoo->setText(
        tr("Init crop on X=%1 Y=%2  px %3x%4 CTRL + mouse to move crop area.")
            .arg(Top_startX)
            .arg(Top_startY)
            .arg(TagliaPoi.width())
            .arg(TagliaPoi.height()));
  } else {
    imgcoo->setText(tr("No crop action"));
    pushButton_2->setEnabled(false);
  }

  QString help = "";

  if (rotazione != 0) {
    help = tr("Save image after rotation!");
  }

  imginfo->setText(tr("Name: %1 %2x%3 / Size %4 / lastModified %5 %6")
                       .arg(fi.fileName())
                       .arg(LargeReal)
                       .arg(HighteReal)
                       .arg(BiteorMega(fi.size()))
                       .arg(lastm.toString(Qt::ISODate))
                       .arg(help));

  QResource xmlres(":/img/tip.html");
  QString sale = "";
  QFile file(xmlres.absoluteFilePath());
  if (file.exists()) {
    if (file.open(QFile::ReadOnly | QFile::Text)) {
      sale = QString::fromUtf8(file.readAll());
      file.close();
    }
  }
  imginfo->setToolTip(QString(sale));

  onwi = false;
}

/*

 int fotox = (massimo / 2) - (base.width() / 2);
                int fotoy = (massimo / 2) - (base.height() / 2);

*/
/* ##################################################################################
 */
/* ###################################event
 * mouse############################################### */
/* ##################################################################################
 */

void Interface::keyPressEvent(QKeyEvent *e) {
  qDebug() << "### " << __FILE__ << "-" << __FUNCTION__ << "line:" << __LINE__;

  if (e->key() == Qt::Key_Control && TagliaPoi.width() > 0) {
    moverecci = true;
    CTRL_Pressed = true;
    setCursor(Qt::OpenHandCursor);
    return;
  }

  if (e->key() == Qt::Key_Escape) {
    BaseReset();
    return;
  }

  if (e->key() == Qt::Key_D && e->modifiers()) {
    MakePrintScreen();
    return;
  }

  if (e->key() == Qt::Key_S && e->modifiers()) {
    TmpSave();
    return;
  }

  if (e->key() == Qt::Key_V && e->modifiers()) {
    const QMimeData *data = QApplication::clipboard()->mimeData();
    if (data->hasImage()) {
      nrpic++;
      QImage images = qvariant_cast<QImage>(data->imageData());
      bool saved = images.save(origImageFilename, extension, 100);
      if (saved) {
        BaseReset();
      }
    }
    return;
  }

  ////////////////if( e->key() ==  Qt::Key_C)

  if (e->key() == Qt::Key_C && e->modifiers()) {
    QApplication::clipboard()->setImage(display.toImage(),
                                        QClipboard::Clipboard);
    return;
  }

  if (e->key() == Qt::Key_Plus) {
    int pluspuls = ratio + 1;
    SetZoom(pluspuls);
    return;
  }

  if (e->key() == Qt::Key_Minus) {
    int minuspuls = ratio - 1;
    SetZoom(minuspuls);
    return;
  }
}
void Interface::keyReleaseEvent(QKeyEvent *e) {
  setCursor(Qt::ArrowCursor);
  moverecci = false;
  CTRL_Pressed = false;
}

void Interface::Mousepress(QMouseEvent *e) /* mouse start */
{
  if (CTRL_Pressed) {
    setCursor(Qt::OpenHandCursor);
    return;
  }

  Dstart = QPoint(0, 0);
  if (e->button() == Qt::LeftButton && !CTRL_Pressed) {
    Dstart = ScalePoint(e->pos());
    setCursor(Qt::CrossCursor);
    moverecci = false;
    CTRL_Pressed = false;
  }
}

void Interface::Mousemove(QMouseEvent *e) /* mouse start */
{

  if (CTRL_Pressed && moverecci && TagliaPoi.width() > 10) {
    moverecci = true;
    CTRL_Pressed = true;

    setCursor(Qt::ClosedHandCursor);

    QRect TMPrect = TagliaPoi;

    Dmove = ScalePoint(e->pos());

    Dmove.setX(Dmove.x() - (TMPrect.width() / 2));
    Dmove.setY(Dmove.y() - (TMPrect.height() / 2));
    TMPrect.moveTo(Dmove);
    DisegnaRect(TMPrect.topLeft(), TMPrect.bottomRight());
    //////////////qDebug() << "####### TMPrect.width()  " << TMPrect.height() <<
    ///" TMPrect.width() " << TMPrect.width();
    //////////////////qDebug() << "####### TagliaPoi  " << TagliaPoi;
    return;
  }

  if (Dstart.x() > 0) {
    Dstop = ScalePoint(e->pos());
    DisegnaRect(Dstart, Dstop);
    setCursor(Qt::CrossCursor);
    moverecci = false;
    CTRL_Pressed = false;
  }
}

void Interface::mouseReleaseEvent(QMouseEvent *e) /* mouse start */
{
  setCursor(Qt::ArrowCursor);
  moverecci = false;
  CTRL_Pressed = false;
}

QPoint Interface::ScalePoint(QPoint p) {
  if (ratio == 100) {
    return p;
  } else {
    int ReX = (p.x() / ratio) * cento;
    int ReY = (p.y() / ratio) * cento;
    return QPoint(ReX, ReY);
  }
}

/* ##################################################################################
 */
/* ###################################event
 * mouse############################################### */
/* ##################################################################################
 */

void Interface::DisegnaRect(QPoint topLeft, QPoint bottomRight) {
  Top_startX = QMIN(topLeft.x(), bottomRight.x());
  Top_startY = QMIN(topLeft.y(), bottomRight.y());

  int Bot_endX = QMAX(topLeft.x(), bottomRight.x());
  int Bot_endY = QMAX(topLeft.y(), bottomRight.y());

  QPoint topLefta(Top_startX, Top_startY);
  QPoint bottomRighta(Bot_endX, Bot_endY);
  QRect areaplace(topLefta, bottomRighta);

  /*

  */

  TagliaPoi = areaplace;

  /////////////////qDebug() << "####### TagliaPoi.width()  " <<
  ///TagliaPoi.height();

  if (areaplace.width() > 9) {
    TagliaPoi = areaplace;
    QPen pen;
    pen.setStyle(Qt::SolidLine);

    pen.setWidth(2);
    if (ratio > 80 && ratio < 110) {
      pen.setWidth(2);
    }
    if (ratio < 81) {
      pen.setWidth(4);
    }
    if (ratio < 50) {
      pen.setWidth(6);
    }
    if (ratio > 130) {
      pen.setWidth(1);
    }

    pen.setColor(color1);
    QPixmap nuovo(original2.width(), original2.height());
    QPainter painter;
    painter.begin(&nuovo);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawPixmap(0, 0, original2);
    painter.setPen(pen);         /* penna */
    painter.drawRect(areaplace); /* disegna */
    painter.end();
    display = nuovo;
    int newlarge = (original2.width() / cento) * ratio;
    wrapper->paint(
        QPixmap(display.scaledToWidth(newlarge, Qt::FastTransformation)));
    setCursor(Qt::CrossCursor);
    UpdateNow();
  }
}

void Interface::wheelEvent(QWheelEvent *event) {
  int numDegrees = event->delta() / 8;
  int numTicks = numDegrees / 15;
  /////////////qDebug() << "###  wheelEvent numTicks " << numTicks;
  if (numTicks == 1) {
    int pluspuls = ratio + 1;
    SetZoom(pluspuls);
  } else {
    int minuspuls = ratio - 1;
    SetZoom(minuspuls);
  }
  QApplication::restoreOverrideCursor();
  return;
}

/* ##################################################################################
 */
/* ###################################event
 * mouse############################################### */
/* ##################################################################################
 */

void Interface::SetZoom(int percentual) {

  //////////////qDebug() << "####### percentual  " << percentual;
  if (original.isNull()) {
    return;
  }
  ////////////qDebug() << "####### percentual  " << percentual;
  ratio = percentual;
  QRect screenSize = qApp->desktop()->availableGeometry();
  int newlarge = (original.width() / cento) * percentual;
  display = original2.scaledToWidth(newlarge, Qt::FastTransformation);
  wrapper->paint(display);
  UpdateNow();
}

void Interface::closeEvent(QCloseEvent *e) { e->accept(); }

void Interface::SetColor() {
  color1 = qvariant_cast<QColor>(currentItemData(comboBox));
  wrapper->paint(display);
}

void Interface::populateWithColors(QComboBox *comboBox) {
  QPixmap pix(22, 22);

  QStringList colorNames = QColor::colorNames();
  foreach (QString name, colorNames) {
    pix.fill(QColor(name));
    comboBox->addItem(pix, name, QColor(name));
  }
}

QVariant Interface::currentItemData(QComboBox *comboBox) {
  return comboBox->itemData(comboBox->currentIndex());
}

int Interface::QMIN(int x, int y) {
  if (x < y) {
    return x;
  } else {
    return y;
  }
}

int Interface::QMAX(int x, int y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}

int Interface::QRAPORT(int n, qreal r) {
  int x = (n / r) * cento;
  if (x < 1) {
    x = 0;
  }
  return x;
}

void Interface::populateFilter(QComboBox *comboBox) {
  QPixmap pix(22, 22);

  QStringList colorNames = QColor::colorNames();
  comboBox->addItem(tr("Select a filter.."));
  pix.fill(QColor("grey"));
  comboBox->addItem(pix, tr("GreyScale"));
  comboBox->addItem(tr("RGB Swapped"));
  comboBox->addItem(tr("InvertPixels color"));
  pix.fill(QColor(162, 128, 101));
  comboBox->addItem(pix, tr("Colorize") + QString(" color=\"sepia\""));
  comboBox->addItem(tr("Colorize") + QString(" color=\"mycolor\""));

  foreach (QString name, colorNames) {

    pix.fill(QColor(name));
    comboBox->addItem(pix, tr("Colorize") + QString(" color=\"%1\"").arg(name));
  }
}

void Interface::applyFilter(QString filtername) {
  QImage income(origImageFilename);
  QImage base = income.convertToFormat(QImage::Format_RGB32);
  int newlarge = (original.width() / cento) * ratio;
  int largeful = base.width();
  QPixmap result;
  if (base.isNull()) {
    return;
  }
  if (filtername == tr("Select a filter..")) {
    //////qDebug() << "### return " << filtername;
    return;
  }
  QColor gtr;
  comboBox_2->setCurrentIndex(0);
  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

  qDebug() << "### filtername " << filtername;

  /* start to pray filter */
  if (filtername.contains(tr("Colorize"))) {
    const QString colorn = BraketName(filtername);

    if (colorn == "sepia") {
      gtr = QColor(162, 128, 101);
    } else if (colorn == "mycolor") {
      QApplication::restoreOverrideCursor();
      QColor col = QColorDialog::getColor(QColor("red"), this);
      QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
      gtr = col;
    } else {
      gtr = QColor(colorn);
    }
    ///////////qDebug() << "### colorn " << colorn;
    int sepiaH, sepiaS, sepiaL;
    ///////QColor(162,128,101).getHsv( &sepiaH, &sepiaS, &sepiaL );
    gtr.getHsv(&sepiaH, &sepiaS, &sepiaL);
    // iterate over each selected scanline
    int x, y, pixelLuminance;
    QRgb *rgb;
    QColor sepiaColor;
    uchar *scanLine;

    for (y = 0; y < base.height(); y++) {
      scanLine = base.scanLine(y);
      for (x = 0; x < base.width(); x++) {
        rgb = ((QRgb *)scanLine + x);
        pixelLuminance = (int)(0.2125 * qRed(*rgb) + 0.7154 * qGreen(*rgb) +
                               0.0721 * qBlue(*rgb));
        sepiaColor.setHsv(sepiaH, sepiaS, pixelLuminance);
        *rgb = sepiaColor.rgb();
      }
    }
    qDebug() << "### base.isNull() 1111  must see false!  " << base.isNull();
    result = QPixmap::fromImage(base);

  } else if (filtername == tr("GreyScale")) {

    result = QPixmap::fromImage(GreyScale(base));

  } else if (filtername == tr("RGB Swapped")) {

    base.rgbSwapped();
    result = QPixmap::fromImage(base);

  } else if (filtername == tr("InvertPixels color")) {

    base.invertPixels();
    result = QPixmap::fromImage(base);

  } else {

    return;
  }

  original = result;

  qDebug() << "### base.isNull() 333  must see false!  " << result.isNull();

  display = result.scaledToWidth(newlarge, Qt::FastTransformation);
  wrapper->paint(display);
  UpdateNow();

  QApplication::restoreOverrideCursor();
}
