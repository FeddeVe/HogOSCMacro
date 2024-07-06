#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include "myosc.h"
#include "pagehelper.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void CommandLine(QString commandline);
    void Log(QString item);
    void progress(int left);

private slots:
    void on_pushButton_clicked();
    void on_horizontalSlider_valueChanged(int value);



    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

   // void on_pushButton_4_clicked();

  //  void on_pushButton_5_clicked();
//
    //void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void PageComplete(int pagenum);

private:
    Ui::MainWindow *ui;
    MyOSC *osc;
    MyOSC *osc2;

    QDateTime PageCreateStartTime;
    int PageCreateTotalPress;

    void CreateDefault();
    void CreatePage1();
    void CreatePage2();
    void CreatePage3();
    void CreatePage4();
    void CreatePage5();
    void CreatePage6();
    void CreatePage7();
    void CreatePage8();
    void CreatePage9();
    void CreatePage10();



};
#endif // MAINWINDOW_H
