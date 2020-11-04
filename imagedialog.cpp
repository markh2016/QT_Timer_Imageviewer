#include "imagedialog.h"
#include "ui_imagedialog.h"

#include <QImageReader>
#include <QPixmap>

ImageDialog::ImageDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ImageDialog)
{
    ui->setupUi(this);
    this->setFixedSize(size());
    this->loadDir(dirOne)  ;
    this->timer =new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(ui->btnStartTimer, SIGNAL(clicked()), this, SLOT(start_M_Timer()));
}

ImageDialog::~ImageDialog()
{
    delete ui;
}

bool ImageDialog::loadDir(const QDir &path)
{




     qDebug()<< path.exists() ;
     list = path.entryList(QDir::AllEntries);

     ui->QImageSlider->setMaximum(list.size()-1) ;
     qDebug()<< "List size = " << list.size()<< Qt::endl;
     for (int i = 2; i < list.size(); i++)
     {
        // qDebug() << "Filename " << i << " = " << path.filePath(list.at(i));
     }

     return path.exists() ;

}

void ImageDialog::update()
{

    if(m_counter==list.size())
    {
        m_counter = 2;
    }

    if(m_counter <= list.size()){
        QString m_element=  dirOne.filePath(list.at(m_counter));
        QPixmap pm(m_element) ;
        ui->ImageLabel->setPixmap(pm);
        ui->ImageLabel->setScaledContents(true);
        ui->QImageSlider->setValue(m_counter-1) ;
        m_counter+=1 ;

        ui->QImageSlider->setValue(m_counter-1) ;
   }




}

void ImageDialog::start_M_Timer()
{
   QString btext = ui->btnStartTimer->text();
   if(btext=="Start Timer")
   {
   timer->start(3000);
   ui->btnStartTimer->setText("Stop  Timer") ;
   }
   else
   {
       timer->stop();
       m_counter=2 ;

        ui->btnStartTimer->setText("Start Timer") ;
   }
}



