#include "edit_html.h"
//
/*  Save file as edit_html.cpp  */
/*  incomming class name Edit_html */
//
#include <QCloseEvent>

Edit_html::Edit_html()
{
	/* fopenutf8("index.html") */
   
   connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(RContext(QPoint)));
   connect(wtext, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(RContext(QPoint)));
    connect(this, SIGNAL(OnSave(QString)), this, SLOT(SaveAction(QString)));
    connect(vol_pdf, SIGNAL(clicked()), this, SLOT(MakefilePrintPdf()));
     connect(vol_print, SIGNAL(clicked()), this, SLOT(MakefilePrint()));
    connect(fontname, SIGNAL(activated(const QString &)), this, SLOT(TextFamily(const QString &)));
     connect(wtext, SIGNAL(currentCharFormatChanged(const QTextCharFormat &)), this, SLOT(currentCharFormatChanged(const QTextCharFormat &)));
    connect(vol_html, SIGNAL(clicked()), this, SLOT(SaveAsFile()));
    
    connect(wtext, SIGNAL(DDClick()), this, SLOT(DoubleClick()));
    
    
    list_ul->clear();
    list_ul->addItem("Standard");
    list_ul->addItem("Bullet List (Disc)");
    list_ul->addItem("Bullet List (Circle)");
    list_ul->addItem("Bullet List (Square)");
    list_ul->addItem("Ordered List (Decimal)");
    list_ul->addItem("Ordered List (Alpha lower)");
    list_ul->addItem("Ordered List (Alpha upper)");
    connect(list_ul, SIGNAL(activated(int)), this, SLOT(TextStyle(int)));
    
    
    QActionGroup *grp = new QActionGroup(this);
    connect(grp, SIGNAL(triggered(QAction *)), this, SLOT(MaketextAlign(QAction *)));
    
    actionAlignLeft = new QAction(QIcon(":/img/textleft.png"), tr("Text align left"),grp);
    actionAlignLeft->setShortcut(Qt::CTRL + Qt::Key_S);
    actionAlignLeft->setCheckable(true);
    actionAlignRight = new QAction(QIcon(":/img/textright.png"), tr("Text align right"),grp);
    actionAlignRight->setShortcut(Qt::CTRL + Qt::Key_D);
    actionAlignRight->setCheckable(true);
    actionAlignCenter = new QAction(QIcon(":/img/textcenter.png"), tr("Text align center"),grp);
    actionAlignCenter->setShortcut(Qt::CTRL + Qt::Key_E);
    actionAlignCenter->setCheckable(true);
    actionAlignJustify = new QAction(QIcon(":/img/textjustify.png"), tr("Text align Justify"),grp);
    actionAlignJustify->setShortcut(Qt::CTRL + Qt::Key_G);
    actionAlignJustify->setCheckable(true);
    
    QPixmap pix(22, 22);
    pix.fill(Qt::black);
    
    actionTextColor = new QAction(pix, tr("Font Color"),this);
    actionTextColor->setShortcut(Qt::CTRL + Qt::Key_O);
    actionTextColor->setCheckable(true);
    actionTextColor->setIcon(pix);  
    connect(actionTextColor, SIGNAL(triggered()), this, SLOT(MaketextColor()));
    
    vol_left->setDefaultAction(actionAlignLeft);
    vol_right->setDefaultAction(actionAlignRight);
    vol_center->setDefaultAction(actionAlignCenter);
    vol_justify->setDefaultAction(actionAlignJustify); 
    vol_color->setDefaultAction(actionTextColor);
    fontsize->clear();
    for ( int x = 0; x < 60; ++x ) {
        if (x > 5) {
        fontsize->addItem(QString("%1").arg(x));
        }
    }
    
    connect(fontsize, SIGNAL(activated(const QString &)), this, SLOT(TextSize(const QString &)));
    fontsize->setCurrentIndex(fontsize->findText(QString::number(QApplication::font().pointSize())));
    
    connect(vol_bold, SIGNAL(clicked()), this, SLOT(MakeTextBold()));
    connect(vol_italic, SIGNAL(clicked(bool)), wtext, SLOT(setFontItalic(bool)));
    connect(vol_underline, SIGNAL(clicked(bool)), wtext, SLOT(setFontUnderline(bool)));
    
    
    
}


void  Edit_html::SaveAction( QString source  ) 
{
    fwriteutf8(basefilestart,source);
}


   
   



/* save as file current textarea */
void  Edit_html::SaveAsFile()
{
    
      qDebug() << "### " << __FILE__ << "-" << __FUNCTION__  << "line:" << __LINE__;
      Refresh_Source();
      SaveAction(html);
      bool tclean;
      QString s = QFileDialog::getSaveFileName(this,tr("Select place to export file html"),QString(setter.value("LastDir").toString()),"Plain text (*.xhtml *.html)");
      
        QString msgDB =tr("You Like to Tidy File? (Clean conform)");
        int removeyes = QMessageBox::question(this, tr("Pleas Confirm!"),msgDB,
                                                            tr("&Yes"), tr("&No"),
                                                             QString(),8888,9999);
         QString responder = QString::number(removeyes);
         if (responder =="0")  {
          tclean = true;
         } else {
          tclean = false;  
         }
    
      if (s.size() > 3) {
          
          if (!s.endsWith("html") ) {
              s = s+".html"; 
            }
            QString ultimacartellaaperta = s.left(s.lastIndexOf("/"))+"/";
            ///////QUrl deloc(ultimacartellaaperta);
            /////////ExportImagetoPath(DesktopFile(deloc.toLocalFile()));
            
            ExportImagetoPath(ultimacartellaaperta);
            const QString goextern = html.replace(QString("src=\"%1").arg(imagecache),"src=\"./",Qt::CaseInsensitive);
            
            if (tclean) {
                
                const  QString tidicaches = QString("%2/.qtidy/").arg(QDir::homePath());
                QTidy *tidy = new QTidy();   /* QTidy  *tidy; */
                tidy->Init(tidicaches);  /* tidy cache remove on last event */
                
            fwriteutf8(s,tidy->TidyCleanfullxhtml(goextern));
            } else {
            fwriteutf8(s,goextern);  
            }
            
            
            setter.setValue("LastDir",ultimacartellaaperta);  
          
            /////////qDebug() << "### ultimacartellaaperta   " << ultimacartellaaperta;         
            /////////////qDebug() << "### imagecache   " << imagecache;  
           ///////////// qDebug() << "### imagecache   " << imagecache;  
           ////////////////// qDebug() << "### imagecache   " << imagecache;  
            
          
           if (is_file(s)) {
           setter.setValue("LastFileOpen",s);
           }
      }

      
      
}


void  Edit_html::ExportImagetoPath( const QString path  ) 
{
    QRegExp expression( "src=[\"\'](.*)[\"\']", Qt::CaseInsensitive );
    expression.setMinimal(true);
    int iPosition = 0;
    int canna = 0;
    while( (iPosition = expression.indexIn( html , iPosition )) != -1 ) {
        QString semi1 = expression.cap( 1 );
        canna++;
        if (is_file(semi1)) {
            QFileInfo fi(semi1);
             QString namedest = QString("%1%2").arg(path).arg(fi.fileName());
             Copy_To(fi.absoluteFilePath(),namedest); 
        }
        iPosition += expression.matchedLength();
    }
}












void Edit_html::MaketextColor()
{
    QColor col = QColorDialog::getColor(wtext->textColor(), this);
    if (!col.isValid()) {
        return;
    } else {
    wtext->setTextColor(col);
    QPixmap pix(22, 22);
    pix.fill(col);
    actionTextColor->setIcon(pix);  
    }
}



    /* bold text  */
void  Edit_html::MakeTextBold()
{
  wtext->setFontWeight(vol_bold->isChecked() ? QFont::Bold : QFont::Normal);
}


void Edit_html::TextStyle(int styleIndex)
{
    QTextCursor cursor = wtext->textCursor();

    if (styleIndex != 0) {
        QTextListFormat::Style style = QTextListFormat::ListDisc;

        switch (styleIndex) {
            default:
            case 1:
                style = QTextListFormat::ListDisc;
                break;
            case 2:
                style = QTextListFormat::ListCircle;
                break;
            case 3:
                style = QTextListFormat::ListSquare;
                break;
            case 4:
                style = QTextListFormat::ListDecimal;
                break;
            case 5:
                style = QTextListFormat::ListLowerAlpha;
                break;
            case 6:
                style = QTextListFormat::ListUpperAlpha;
                break;
        }

        cursor.beginEditBlock();

        QTextBlockFormat blockFmt = cursor.blockFormat();

        QTextListFormat listFmt;

        if (cursor.currentList()) {
            listFmt = cursor.currentList()->format();
        } else {
            listFmt.setIndent(blockFmt.indent() + 1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }

        listFmt.setStyle(style);

        cursor.createList(listFmt);

        cursor.endEditBlock();
    } else {
        // ####
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }
}


void Edit_html::currentCharFormatChanged(const QTextCharFormat &format)
{
    FontChanged(format.font());
    /*colorChanged(format.foreground().color());*/
    MakealignmentChanged(wtext->alignment());
}

void Edit_html::MakealignmentChanged(Qt::Alignment a)
{
    if (a & Qt::AlignLeft)
        actionAlignLeft->setChecked(true);
    else if (a & Qt::AlignHCenter)
        actionAlignCenter->setChecked(true);
    else if (a & Qt::AlignRight)
        actionAlignRight->setChecked(true);
    else if (a & Qt::AlignJustify)
        actionAlignJustify->setChecked(true);
}

void Edit_html::MaketextAlign(QAction *a)
{
    if (a == actionAlignLeft)
        wtext->setAlignment(Qt::AlignLeft);
    else if (a == actionAlignCenter)
        wtext->setAlignment(Qt::AlignHCenter);
    else if (a == actionAlignRight)
        wtext->setAlignment(Qt::AlignRight);
    else if (a == actionAlignJustify)
        wtext->setAlignment(Qt::AlignJustify);
}


void Edit_html::FontChanged(const QFont &f)
{
    
    vol_link->setChecked(f.underline());
    
    fontname->setCurrentIndex(fontname->findText(f.family()));
    fontsize->setCurrentIndex(fontsize->findText(QString::number(f.pointSize())));
    vol_bold->setChecked(f.bold());
    vol_italic->setChecked(f.italic());
    vol_underline->setChecked(f.underline());
}


void Edit_html::TextFamily(const QString &f)
{
    wtext->setFontFamily(f);
}

void Edit_html::TextSize(const QString &p)
{
    wtext->setFontPointSize(p.toFloat());
}







void Edit_html::MakefilePrint()
{
#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::HighResolution);
    printer.setFullPage(true);
    QPrintDialog *dlg = new QPrintDialog(&printer, this);
    if (dlg->exec() == QDialog::Accepted) {
        wtext->document()->print(&printer);
    }
    delete dlg;
#endif
}


void Edit_html::MakefilePrintPdf()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export PDF",QString(setter.value("LastDir").toString()), "*.pdf");
    if (fileName.size() > 1) {
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
            if (!fileName.endsWith(".pdf")) {
                         fileName = fileName+".pdf"; 
            }
        QString ultimacartellaaperta = fileName.left(fileName.lastIndexOf("/"))+"/";
        setter.setValue("LastDir",ultimacartellaaperta);   
        printer.setOutputFileName(fileName);
        wtext->document()->print(&printer);
        emit statusMessage(QString("Pdf: %1").arg(fileName));
        /////////////QMessageBox::information( this, tr( "File info." ),tr("Il file ? stato salvato"));
            if (is_file(fileName)) {
                QApplication::restoreOverrideCursor();
                //// file://
                const QString trafile = fileName.prepend("file://");
                bool r = QDesktopServices::openUrl(QUrl(trafile));
               if (!r) {
               QMessageBox::warning(this, tr("Error"),tr("Unable to open file or dir %1").arg(trafile));
               }
            }
    }
    QApplication::restoreOverrideCursor();
}








/*


    QToolButton *vol_undo;
    QToolButton *vol_redo;
    QToolButton *vol_cut;
    QToolButton *vol_copy;
    QToolButton *mypaste;
    QToolButton *vol_source;


    QToolButton *vol_print;
    QToolButton *vol_pdf;
    QToolButton *vol_html;

    QToolButton *vol_link;
    QToolButton *vol_bold;
    QToolButton *vol_italic;
    QToolButton *vol_underline;
    QToolButton *vol_left;
    QToolButton *vol_center;
    QToolButton *vol_right;
    QToolButton *vol_justify;
    

*/


void  Edit_html::DoubleClick() 
{
    Eframe = false;
    Eimage = false;
    Etable = false;
    
    lastcursor = wtext->textCursor();
    xytextpos = lastcursor.position();
    Eframe = lastcursor.currentFrame();
    nowimage = lastcursor.charFormat().toImageFormat();
    nowtable = lastcursor.currentTable();
    Eimage = nowimage.isValid();
    Etable = lastcursor.currentTable();
    
    if (bellavista) {
    return;
    }
    
        if (Eimage) {
             Image_mod_Setting();
             return;
        }
        if (lastcursor.currentTable()) { 
            TableSetting();
            return;
        }  
}



/* context menu */
void  Edit_html::RContext( const QPoint & pos ) 
{
    ////////////////qDebug() << "### contextMenuEvent   " << pos;
    Eframe = false;
    Eimage = false;
    Etable = false;
    
    QPixmap pix(22, 22);
    pix.fill(Qt::black);
    
    /* QTextCursor lastcursor;  */
    lastcursor = wtext->textCursor();
    xytextpos = lastcursor.position();
    QTextCursor c = wtext->textCursor();
    int startb = c.selectionStart();
    int endb = c.selectionEnd();
    
    /////////////qDebug() << "### xytextpos   " << xytextpos;
    
    /////////////////QTextBlock QTextCursor::block () QTextFormat  const 
    
    ///////QTextCharFormat QTextCursor::charFormat () const 
    
    textblocc = lastcursor.block();
    
             Eframe = lastcursor.currentFrame();
             nowimage = lastcursor.charFormat().toImageFormat();
             nowtable = lastcursor.currentTable();
             Eimage = nowimage.isValid();
             Etable = lastcursor.currentTable();
             isqtextblok = textblocc.isValid();
             qDebug() << "### Textblock   " << isqtextblok;   /* QTextBlock */
             qDebug() << "### Eframe   " << Eframe;
             qDebug() << "### Eimage   " << Eimage;
             qDebug() << "### Etable   " << Etable;
             qDebug() << "### blocktext    " << textblocc.text();
             
             
             
             
    TContext = new QMenu(this);
    TContext->addAction(tr( "Open other xhtml or html file" ), this , SLOT( OpenNewDoc() ) );
    TContext->addSeparator();
    
    
    if (bellavista) {
    TContext->addAction(tr( "Edit Modus" ), this , SLOT( ShowModusPanelEdit() ) );
    } else {
    TContext->addAction(tr( "View Modus" ), this , SLOT( ShowModusPanelView() ) );  
    TContext->addSeparator();
    TContext->addAction(pix,tr( "Text color" ), this , SLOT( MaketextColor() ) );
    TContext->addAction(QIcon(QString::fromUtf8(":/img/textbold.png")),tr( "Text Bold" ),vol_bold , SLOT( click() ) );  
    TContext->addAction(QIcon(QString::fromUtf8(":/img/textitalic.png")),tr( "Text italic" ),vol_italic , SLOT( click() ) );  
    TContext->addAction(QIcon(QString::fromUtf8(":/img/textunder.png")),tr( "Text underline" ),vol_underline , SLOT( click() ) );          
    TContext->addAction(QIcon(QString::fromUtf8(":/img/link.png")),tr( "Link or UnLink selected Text (mailto,http)" ),vol_link , SLOT( click() ) );  
    TContext->addAction(QIcon(QString::fromUtf8(":/img/document.png")),tr( "Line Break" ),vol_br , SLOT( click() ) );  
    
        
    TContext->addSeparator();
    TContext->addAction(QIcon(QString::fromUtf8(":/img/textleft.png")),tr( "Text align Left" ),vol_left , SLOT( click() ) ); 
    TContext->addAction(QIcon(QString::fromUtf8(":/img/textright.png")),tr( "Text align Right" ),vol_right , SLOT( click() ) ); 
    TContext->addAction(QIcon(QString::fromUtf8(":/img/textcenter.png")),tr( "Text align Center" ),vol_center , SLOT( click() ) ); 
    TContext->addAction(QIcon(QString::fromUtf8(":/img/textjustify.png")),tr( "Text align Justify" ),vol_justify , SLOT( click() ) ); 
    TContext->addSeparator();






        
    }
    if (!bellavista) {
    
                TtableContext = new QMenu(tr("Table Option"),TContext);
                TtableContext->setIcon(QIcon(QString::fromUtf8(":/img/table.png")));
                TtableContext->addAction(tr( "Insert Table here" ), this , SLOT( CreateanewTable() ) );
                if (lastcursor.currentTable()) { 
                TtableContext->addAction(QIcon(QString::fromUtf8(":/img/table.png")),tr( "Table (this) Propriety BackgroundColor, Padding, Spacing" ), this , SLOT( TableSetting() ) );
                TtableContext->addAction(QIcon(QString::fromUtf8(":/img/row_table.png")),tr( "Merge selected cell (if select)" ), this , SLOT( MergeCellByCursorPosition() ) );
                TtableContext->addAction(tr( "Append Row on this table" ), this , SLOT( AppendTableRows() ) );
                TtableContext->addAction(tr( "Append Cools on this table" ), this , SLOT( AppendTableCools() ) );
                TtableContext->addAction(tr( "Remove this row" ), this , SLOT( RemoveRowByCursorPosition() ) );
                TtableContext->addAction(tr( "Remove this cool" ), this , SLOT( RemoveCoolByCursorPosition() ) );
                TtableContext->addAction(tr( "Set Cell backgroundColor" ), this , SLOT( SetTableCellColor() ) );
                TtableContext->addAction(tr( "Set Cell Width" ), this , SLOT( SetColumLarge() ) );  
                    
                    
                    
                 }
                 TContext->addAction(TtableContext->menuAction());  
                 TimageContext = new QMenu(tr("Image edit or new "),TContext);
                 TimageContext->setIcon(QIcon(QString::fromUtf8(":/img/pictures.png")));
                 TimageContext->addAction(tr( "Insert new image" ), this , SLOT( CreateanewImage() ) );
                 if (Eimage) {
                     QString picname = nowimage.name();
                     QFileInfo locinfo(picname);
                     TimageContext->addAction(tr( "Image edit \"%1\" width - height" ).arg(locinfo.fileName()), this , SLOT( Image_mod_Setting() ) ); 
                 }
                 
                 TContext->addAction(TimageContext->menuAction()); 
    
    act_mycopy = new QAction(tr("&Copy"), this);
    act_mycopy->setShortcut(tr("Ctrl+C"));
    connect(act_mycopy, SIGNAL(triggered()), wtext, SLOT(copy()));
    TContext->addAction(act_mycopy);
    act_myselectall = new QAction(tr("&Select all"), this);
    act_myselectall->setShortcut(tr("Ctrl+A"));
    connect(act_myselectall, SIGNAL(triggered()), wtext, SLOT(selectAll()));
    TContext->addAction(act_myselectall);
    act_mycute = new QAction(tr("&Cut"), this);
    act_mycute->setShortcut(tr("Ctrl+X"));
    connect(act_mycute, SIGNAL(triggered()), wtext, SLOT(cut()));
     TContext->addAction(act_mycute);
    act_mypaste = new QAction(tr("&Paste"), this);
    act_mypaste->setShortcut(tr("Ctrl+V"));
    connect(act_mypaste, SIGNAL(triggered()), wtext, SLOT(paste()));    
    TContext->addAction(act_mypaste);
                 
    actionPscreen = new QAction(tr("&Print Screen"), this);
    actionPscreen->setShortcut(tr("Ctrl+W"));
    connect(actionPscreen, SIGNAL(triggered()), wtext, SLOT(MakePrintScreen()));    
    TContext->addAction(actionPscreen);    
                 
    /////actionSave = new QAction(tr("&Save current"), this);
    /////////connect(actionSave, SIGNAL(triggered()), this, SLOT(SaveStream()));    
    //////////TContext->addAction(actionSave);  


     
                 
    }
    TContext->addSeparator();
    if (isqtextblok) {
        QString texticurrent = textblocc.text();
                    texticurrent = texticurrent.left(5);
                    texticurrent.append("...");
                    QTextBlockFormat formatibb = textblocc.blockFormat();
     TContext->addAction(tr( "Changes Text Margin \"%2px\" to %1.." ).arg(texticurrent).arg(formatibb.topMargin()), this , SLOT( SetTextBlockMargin() ) );  
     TContext->addSeparator();  
    }
    TContext->addAction(tr( "Source View" ), this , SLOT( SwaptoSource() ));
    TContext->addAction(tr( "Close context" ), TContext , SLOT( close() ) );
    TContext->exec(QCursor::pos()); 
}

void  Edit_html::SetTextBlockMargin()
{
    
    
    int now = 0;
    textblocc = lastcursor.block();
    isqtextblok = textblocc.isValid();
        if (isqtextblok) {
            
            QString texticurrent = textblocc.text();
                    texticurrent = texticurrent.left(5);
                    texticurrent.append("...");
            
            QTextBlockFormat formatibb = textblocc.blockFormat();
            
                    
                   
        bool ok;
        qreal LargeMargin = QInputDialog::getInt(this, tr("Set Text Margin to %1").arg(texticurrent),
                                      tr("Pixel:"), formatibb.topMargin(), 0, 300, 1, &ok);
            if (LargeMargin < 301 && ok) {
         ////////////////bottomMargin(), setTopMargin(), setLeftMargin(), and setRightMargin().
             
                 //////qDebug() << "### formatibb.leftMargin() " << formatibb.leftMargin();
                 ////qDebug() << "### formatibb.rightMargin() " << formatibb.rightMargin();
                 //////qDebug() << "### formatibb.bottomMargin() " << formatibb.bottomMargin();
                 /////qDebug() << "### formatibb.topMargin() " << formatibb.topMargin();
                 formatibb.setLeftMargin(LargeMargin);
                 formatibb.setBottomMargin(LargeMargin);
                 formatibb.setTopMargin(LargeMargin);
                 formatibb.setRightMargin(LargeMargin);
                 lastcursor.setBlockFormat(formatibb);
            }
        }
       
}



void  Edit_html::SetTableCellColor()
{
    /* QTextTable  *nowtable; */
    QTextCursor findercursor(wtext->textCursor());
    Etable = findercursor.currentTable();
    if (Etable) {  
    bool ok;
    QTextTableCell existingcell =  nowtable->cellAt(findercursor); 
        /* reformat this -> existingcell */
        QTextCharFormat existformat = existingcell.format();
                     /* get color */
                     QColor col = QColorDialog::getRgba(NULL,&ok, this);
                     if (!col.isValid()) {
                        return; 
                     }
                        QBrush stylesin(col);
                        existformat.setBackground(stylesin);
                        existingcell.setFormat(existformat); 
    }
}


void  Edit_html::SetColumLarge()
{
    /* QTextTable  *nowtable; */ 
    QTextCursor findercursor(wtext->textCursor());
    Etable = findercursor.currentTable();
    if (Etable) {  
    QTextTableCell existingcell =  nowtable->cellAt(findercursor);
        
        QTextTableFormat tbforms = nowtable->format();
        
    int cellcoolcursoris = existingcell.column(); /* int value start from zero */
        /* get lengh % to set on cell .... */
        bool ok;
        int LargeSet = QInputDialog::getInt(this, tr("Set Cell Width"),
                                      tr("Percentage Length:"), 10, 1, 100, 1, &ok);
        if (ok && LargeSet > 0) {
        QVector<QTextLength> constraints = tbforms.columnWidthConstraints();
        for (int i = 0; i < constraints.size(); ++i) {
            if (i == cellcoolcursoris) {
                constraints.replace(i,QTextLength(QTextLength::PercentageLength, LargeSet)); 
            }
        }
        tbforms.setColumnWidthConstraints(constraints);
        
        nowtable->setFormat(tbforms);
        }
    }
}


void Edit_html::keyPressEvent(QKeyEvent *e)
{
    /////////////qDebug() << "### e->key()   " << e->key();  
    
    
    
}




void Edit_html::closeEvent( QCloseEvent* e )
{
    //////////////////qDebug() << "### closeEvent   ";
	e->accept();
}
