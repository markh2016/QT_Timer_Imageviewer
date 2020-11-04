#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H

#include <QDialog>
#include <QDir>
#include <QDebug>
#include <QScrollBar>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class ImageDialog; }
QT_END_NAMESPACE

class ImageDialog : public QDialog
{
    Q_OBJECT

public:
    ImageDialog(QWidget *parent = nullptr);
    ~ImageDialog();
    bool loadDir(const QDir &path);

private slots:
     void update();
     void start_M_Timer();

private:
    Ui::ImageDialog *ui;
    QDir dirOne = QDir("/home/mark/Pictures") ; // initialise  Diectrory from which we want to load files
    QStringList list ;
    QTimer *timer ;

    int stack ;
    int m_counter=2 ;
};
#endif // IMAGEDIALOG_H
