#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   // this->osc = new OSC();
    this->osc = new MyOSC();
   this->osc2 = new MyOSC();
    ui->setupUi(this);
    connect(this->osc, SIGNAL(PublishCommandline(QString)), this, SLOT(CommandLine(QString)));
    connect(this->osc, SIGNAL(PublishLog(QString)), this, SLOT(Log(QString)));
    connect(this->osc, SIGNAL(ReportProgress(int)), this, SLOT(progress(int)));
    connect(this->osc, SIGNAL(PageComplete(int)), this, SLOT(PageComplete(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PageComplete(int pagenum){
  QPalette p;
  p.setColor(QPalette::All, QPalette::WindowText, QColorConstants::Green);
  switch(pagenum){
    case 0:
      ui->checkBox->setPalette(p);
      break;
    case 1:
      ui->checkBox_2->setPalette(p);
      break;
    case 2:
      ui->checkBox_3->setPalette(p);
      break;
    case 3:
      ui->checkBox_4->setPalette(p);
      break;
    case 4:
      ui->checkBox_5->setPalette(p);
      break;
    case 5:
      ui->checkBox_6->setPalette(p);
      break;
    case 6:
      ui->checkBox_7->setPalette(p);
      break;
    case 7:
      ui->checkBox_8->setPalette(p);
      break;
    case 8:
      ui->checkBox_9->setPalette(p);
      break;
    case 9:
      ui->checkBox_10->setPalette(p);
      break;
    case 10:
      ui->checkBox_11->setPalette(p);
      break;

    }
}


void MainWindow::on_pushButton_clicked()
{
    this->osc->Connect(ui->lineEdit->text(), ui->spinBox->value(), ui->spinBox_2->value());

}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
   // this->osc->Test(ui->horizontalSlider->value());
  //  this->osc->test(ui->horizontalSlider->value());
}


void MainWindow::on_pushButton_2_clicked()
{
    this->osc->Test(128);
}

void MainWindow::CommandLine(QString commandline){
    this->ui->lineEdit_2->setText(commandline);
}

void MainWindow::Log(QString Item){
   // ui->plainTextEdit->(Item + '\n');
    // ui->listWidget->insertItem(0, Item);
    if(ui->listWidget->count() > 100){
        QListWidgetItem *it = ui->listWidget->item(ui->listWidget->count()-1);
        ui->listWidget->removeItemWidget(it);
    }
}

void MainWindow::progress(int left){
    int gedaan = this->PageCreateTotalPress - left;
    uint64_t TimeDiff = QDateTime::currentMSecsSinceEpoch() - this->PageCreateStartTime.toMSecsSinceEpoch();
    if(gedaan > 0){
        uint64_t timePerTick = TimeDiff / gedaan;
        uint64_t timetogo = left * timePerTick;

        ui->label_13->setText(QString::number(timePerTick) + " ms");

        int hours = 0;
        int minutes = 0;
        int seconds = 0;
        int msecs = timetogo;
        while(msecs >= 1000){
            msecs = msecs - 1000;
            seconds++;
            if(seconds >= 60){
                seconds = seconds - 60;
                minutes++;
                if(minutes >= 60){
                    minutes = minutes - 60;
                    hours++;
                }
            }
        }
        QString SHours = QString::number(hours);
        QString SMinutes = QString::number(minutes);
        QString SSeconds = QString::number(seconds);
        if(minutes < 10){
            SMinutes = "0"+ SMinutes;
        }
        if(seconds < 10){
            SSeconds = "0"+ SSeconds;
        }
        ui->label_15->setText(SHours + ":"+ SMinutes +"."+ SSeconds);

    }
    ui->label_11->setText(QString::number(left));
    ui->progressBar->setValue(ui->progressBar->maximum() - left);
}


void MainWindow::on_pushButton_3_clicked()
{


    //Create Pages
    QVector<PageHelper*>list;
    this->osc->common->Begin();
    if(ui->checkBox->isChecked()){
        this->CreateDefault();
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE_0_COMPLETE);
    }
    if(ui->checkBox_2->isChecked()){
        this->CreatePage1();
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE_1_COMPLETE);
    }
    if(ui->checkBox_3->isChecked()){
        this->CreatePage2();
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE_2_COMPLETE);
    }
    if(ui->checkBox_4->isChecked()){
        this->CreatePage3();
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE_3_COMPLETE);
    }
    if(ui->checkBox_5->isChecked()){
        this->CreatePage4();
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE_4_COMPLETE);
    }
    if(ui->checkBox_6->isChecked()){
        this->CreatePage5();
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE_5_COMPLETE);
    }
    if(ui->checkBox_7->isChecked()){
        this->CreatePage6();
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE_6_COMPLETE);
    }
    if(ui->checkBox_8->isChecked()){
        this->CreatePage7();
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE_7_COMPLETE);
    }
    if(ui->checkBox_9->isChecked()){
        this->CreatePage8();
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE_8_COMPLETE);
    }
    if(ui->checkBox_10->isChecked()){
        this->CreatePage9();
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE_9_COMPLETE);
    }
    if(ui->checkBox_11->isChecked()){
        this->CreatePage10();
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE_10_COMPLETE);
    }

    QVector<OSC_Common::btns> buttons = this->osc->common->End();
    this->PageCreateStartTime = QDateTime::currentDateTime();
    this->PageCreateTotalPress = buttons.size();
    ui->label_7->setText(PageCreateStartTime.toString());
    ui->label_9->setText(QString::number(buttons.size()));
    ui->progressBar->setMaximum(buttons.size());
    ui->progressBar->setValue(0);

    //Publish
    for(int i = 0; i < buttons.size(); i++){
        this->osc->add_Quee(buttons[i]);
    }
}

/*
void MainWindow::on_pushButton_4_clicked()
{
    this->osc->common->Begin();

    // PAGE ALL
    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 121;
    h->group = 361;
    h->group2 = 381;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 401;
    h->group2 = 421;
    h->group3 = 441;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 461;
    h->group2 = 481;
    h->group3 = 501;
    h->group4 = 521;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 361;
    h->group2 = 381;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 401;
    h->group2 = 421;
    h->group3 = 441;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 461;
    h->group2 = 481;
    h->group3 = 501;
    h->group4 = 521;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 361;
    h->group2 = 381;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 401;
    h->group2 = 421;
    h->group3 = 441;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 461;
    h->group2 = 481;
    h->group3 = 501;
    h->group4 = 521;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);



    for(int i = 1; i < 11; i++){
        for(int y = 0; y < template_list.size(); y++){
            h = new PageHelper();
            h->page = template_list[y]->page + i;
            h->group = template_list[y]->group + i;
            h->group2 = template_list[y]->group2 + i;
            h->group3 = template_list[y]->group3 + i;
            h->group4 = template_list[y]->group4 + i;
            h->fader = template_list[y]->fader;
            h->parts = template_list[y]->parts;
            h->fade_inc = template_list[y]->fade_inc;
            h->fade_dec = template_list[y]->fade_dec;
            h->snap = template_list[y]->snap;
            list.push_back(h);
        }
    }

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 15; cue++){
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(OSC_Common::BEAM, cue + 100);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
             this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(OSC_Common::BEAM, cue + 100);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(OSC_Common::BEAM, cue + 100);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(OSC_Common::BEAM, cue + 100);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }
    }

    QVector<OSC_Common::btns>buttons;
    buttons = this->osc->common->End();
    this->PageCreateStartTime = QDateTime::currentDateTime();
    this->PageCreateTotalPress = buttons.size();
    ui->label_7->setText(PageCreateStartTime.toString());
    ui->label_9->setText(QString::number(buttons.size()));
    ui->progressBar->setMaximum(buttons.size());
    ui->progressBar->setValue(0);

    //Publish
    for(int i = 0; i < buttons.size(); i++){
        this->osc->add_Quee(buttons[i]);
    }
}
*/


void MainWindow::CreateDefault()
{
    //Default Page
    QVector <PageHelper*> pagelist;
    PageHelper *hPage = new PageHelper();
    hPage->page = 100;
    hPage->group = 321;
    hPage->FlashStrobeCue = 1;
    pagelist.push_back(hPage);

   // QVector<OSC_Common::btns>buttons;
   // this->osc->common->Begin();
    for(int i = 0; i < pagelist.size(); i++){
        int group = pagelist[i]->group;
        int page = pagelist[i]->page;
        int flashstrobecue = pagelist[i]->FlashStrobeCue;
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        //Intensity
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE2);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 0, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 16);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 17);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 18);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 19);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 20);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 21);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 22);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 23);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 24);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 25);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 26);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 34);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 35);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 36);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 37);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 38);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 39);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 40);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //COLOURS

        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE3);

        for(int y = 1; y< 19; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::COLOUR, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //POSITION
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE4);

        for(int y = 1; y< 12; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::POSITION, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 1
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE5);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 2
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE6);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y + 10);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //Pos FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE7);
        for(int y = 1; y< 8; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 60);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //COL FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE8);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 80);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //FLASH WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE9);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //STROBE WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE10);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 8);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);

    }

    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 121;
    h->group = 361;
    h->group2 = 381;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 401;
    h->group2 = 421;
    h->group3 = 441;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 461;
    h->group2 = 481;
    h->group3 = 501;
    h->group4 = 521;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 361;
    h->group2 = 381;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 401;
    h->group2 = 421;
    h->group3 = 441;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 461;
    h->group2 = 481;
    h->group3 = 501;
    h->group4 = 521;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 361;
    h->group2 = 381;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 401;
    h->group2 = 421;
    h->group3 = 441;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 121;
    h->group = 461;
    h->group2 = 481;
    h->group3 = 501;
    h->group4 = 521;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 19; cue++){
            QVector<OSC_Common::btns> CueTemplate;
            switch(cue){
                case 1:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                CueTemplate = this->osc2->common->End();
                break;
                case 2:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                CueTemplate = this->osc2->common->End();
                break;
                case 3:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 4:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 5:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 7);
                CueTemplate = this->osc2->common->End();
                break;
                case 6:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 11);
                CueTemplate = this->osc2->common->End();
                break;
                case 7:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 9);
                CueTemplate = this->osc2->common->End();
                break;
                case 8:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 13);
                CueTemplate = this->osc2->common->End();
                break;
                case 9:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 5);
                CueTemplate = this->osc2->common->End();
                break;
                case 10:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 11:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 12:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 13:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 14:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
              case 15:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
              CueTemplate = this->osc2->common->End();
              break;
              case 16:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 17:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 18:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
            }


            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(CueTemplate);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(CueTemplate);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(CueTemplate);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(CueTemplate);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }

    }


}


void MainWindow::CreatePage1()
{
    //DPAGE 1
    QVector <PageHelper*> pagelist;
    PageHelper *hPage = new PageHelper();
    hPage->page = 101;
    hPage->group = 322;
    hPage->FlashStrobeCue = 2;
    pagelist.push_back(hPage);
    hPage = new PageHelper();
    hPage->page = 111;
    hPage->group = 342;
    hPage->FlashStrobeCue = 2;
    pagelist.push_back(hPage);

   // QVector<OSC_Common::btns>buttons;
   // this->osc->common->Begin();
    for(int i = 0; i < pagelist.size(); i++){
        int group = pagelist[i]->group;
        int page = pagelist[i]->page;
        int flashstrobecue = pagelist[i]->FlashStrobeCue;
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        //Intensity
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE2);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 0, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
         this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 16);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 17);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 18);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 19);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 20);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 21);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 22);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 23);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 24);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 25);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 26);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 34);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 35);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 36);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 37);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 38);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 39);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 40);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //COLOURS

        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE3);

        for(int y = 1; y< 19; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::COLOUR, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //POSITION
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE4);

        for(int y = 1; y< 12; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::POSITION, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 1
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE5);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 2
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE6);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y + 10);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //Pos FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE7);
        for(int y = 1; y< 8; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 60);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //COL FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE8);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 80);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //FLASH WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE9);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //STROBE WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE10);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 8);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);

    }

    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 122;
    h->group = 362;
    h->group2 = 382;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 122;
    h->group = 402;
    h->group2 = 422;
    h->group3 = 442;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 122;
    h->group = 462;
    h->group2 = 482;
    h->group3 = 502;
    h->group4 = 522;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 122;
    h->group = 362;
    h->group2 = 382;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 122;
    h->group = 402;
    h->group2 = 422;
    h->group3 = 442;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 122;
    h->group = 462;
    h->group2 = 482;
    h->group3 = 502;
    h->group4 = 522;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 122;
    h->group = 362;
    h->group2 = 382;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 122;
    h->group = 402;
    h->group2 = 422;
    h->group3 = 442;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 122;
    h->group = 462;
    h->group2 = 482;
    h->group3 = 502;
    h->group4 = 522;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 19; cue++){
            QVector<OSC_Common::btns> CueTemplate;
            switch(cue){
                case 1:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                CueTemplate = this->osc2->common->End();
                break;
                case 2:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                CueTemplate = this->osc2->common->End();
                break;
                case 3:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 4:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 5:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 7);
                CueTemplate = this->osc2->common->End();
                break;
                case 6:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 11);
                CueTemplate = this->osc2->common->End();
                break;
                case 7:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 9);
                CueTemplate = this->osc2->common->End();
                break;
                case 8:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 13);
                CueTemplate = this->osc2->common->End();
                break;
                case 9:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 5);
                CueTemplate = this->osc2->common->End();
                break;
                case 10:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 11:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 12:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 13:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 14:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
              case 15:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
              CueTemplate = this->osc2->common->End();
              break;
              case 16:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 17:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 18:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
            }


            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(CueTemplate);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(CueTemplate);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(CueTemplate);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(CueTemplate);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }

    }


}

void MainWindow::CreatePage2()
{
    //DPAGE 2
    QVector <PageHelper*> pagelist;
    PageHelper *hPage = new PageHelper();
    hPage->page = 102;
    hPage->group = 323;
    hPage->FlashStrobeCue = 3;
    pagelist.push_back(hPage);
    hPage = new PageHelper();
    hPage->page = 112;
    hPage->group = 343;
    hPage->FlashStrobeCue = 3;
    pagelist.push_back(hPage);

    // QVector<OSC_Common::btns>buttons;
    // this->osc->common->Begin();
    for(int i = 0; i < pagelist.size(); i++){
        int group = pagelist[i]->group;
        int page = pagelist[i]->page;
        int flashstrobecue = pagelist[i]->FlashStrobeCue;
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        //Intensity
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE2);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 0, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
         this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 16);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 17);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 18);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 19);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 20);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 21);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 22);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 23);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 24);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 25);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 26);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 34);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 35);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 36);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 37);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 38);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 39);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 40);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //COLOURS

        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE3);

        for(int y = 1; y< 19; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::COLOUR, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //POSITION
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE4);

        for(int y = 1; y< 12; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::POSITION, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 1
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE5);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 2
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE6);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y + 10);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //Pos FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE7);
        for(int y = 1; y< 8; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 60);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //COL FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE8);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 80);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //FLASH WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE9);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //STROBE WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE10);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 8);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);

    }

    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 123;
    h->group = 363;
    h->group2 = 383;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 123;
    h->group = 403;
    h->group2 = 423;
    h->group3 = 443;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 123;
    h->group = 463;
    h->group2 = 483;
    h->group3 = 503;
    h->group4 = 523;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 123;
    h->group = 363;
    h->group2 = 383;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 123;
    h->group = 403;
    h->group2 = 423;
    h->group3 = 443;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 123;
    h->group = 463;
    h->group2 = 483;
    h->group3 = 503;
    h->group4 = 523;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 123;
    h->group = 363;
    h->group2 = 383;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 123;
    h->group = 403;
    h->group2 = 423;
    h->group3 = 443;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 123;
    h->group = 463;
    h->group2 = 483;
    h->group3 = 503;
    h->group4 = 523;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 19; cue++){
            QVector<OSC_Common::btns> CueTemplate;
            switch(cue){
                case 1:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                CueTemplate = this->osc2->common->End();
                break;
                case 2:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                CueTemplate = this->osc2->common->End();
                break;
                case 3:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 4:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 5:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 7);
                CueTemplate = this->osc2->common->End();
                break;
                case 6:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 11);
                CueTemplate = this->osc2->common->End();
                break;
                case 7:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 9);
                CueTemplate = this->osc2->common->End();
                break;
                case 8:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 13);
                CueTemplate = this->osc2->common->End();
                break;
                case 9:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 5);
                CueTemplate = this->osc2->common->End();
                break;
                case 10:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 11:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 12:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 13:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 14:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
              case 15:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
              CueTemplate = this->osc2->common->End();
              break;
              case 16:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 17:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 18:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
            }


            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(CueTemplate);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(CueTemplate);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(CueTemplate);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(CueTemplate);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }

    }


}

void MainWindow::CreatePage3()
{
    //DPAGE 3
    QVector <PageHelper*> pagelist;
    PageHelper *hPage = new PageHelper();
    hPage->page = 103;
    hPage->group = 324;
    hPage->FlashStrobeCue = 4;
    pagelist.push_back(hPage);
    hPage = new PageHelper();
    hPage->page = 113;
    hPage->group = 344;
    hPage->FlashStrobeCue = 4;
    pagelist.push_back(hPage);

    // QVector<OSC_Common::btns>buttons;
    // this->osc->common->Begin();
    for(int i = 0; i < pagelist.size(); i++){
        int group = pagelist[i]->group;
        int page = pagelist[i]->page;
        int flashstrobecue = pagelist[i]->FlashStrobeCue;
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        //Intensity
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE2);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 0, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
         this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 16);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 17);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 18);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 19);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 20);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 21);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 22);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 23);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 24);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 25);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 26);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 34);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 35);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 36);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 37);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 38);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 39);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 40);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //COLOURS

        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE3);

        for(int y = 1; y< 19; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::COLOUR, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //POSITION
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE4);

        for(int y = 1; y< 12; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::POSITION, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 1
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE5);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 2
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE6);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y + 10);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //Pos FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE7);
        for(int y = 1; y< 8; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 60);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //COL FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE8);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 80);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //FLASH WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE9);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //STROBE WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE10);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 8);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);

    }

    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 124;
    h->group = 364;
    h->group2 = 384;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 124;
    h->group = 404;
    h->group2 = 424;
    h->group3 = 444;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 124;
    h->group = 464;
    h->group2 = 484;
    h->group3 = 504;
    h->group4 = 524;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 124;
    h->group = 364;
    h->group2 = 384;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 124;
    h->group = 404;
    h->group2 = 424;
    h->group3 = 444;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 124;
    h->group = 464;
    h->group2 = 484;
    h->group3 = 504;
    h->group4 = 524;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 124;
    h->group = 364;
    h->group2 = 384;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 124;
    h->group = 404;
    h->group2 = 424;
    h->group3 = 444;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 124;
    h->group = 464;
    h->group2 = 484;
    h->group3 = 504;
    h->group4 = 524;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 19; cue++){
            QVector<OSC_Common::btns> CueTemplate;
            switch(cue){
                case 1:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                CueTemplate = this->osc2->common->End();
                break;
                case 2:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                CueTemplate = this->osc2->common->End();
                break;
                case 3:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 4:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 5:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 7);
                CueTemplate = this->osc2->common->End();
                break;
                case 6:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 11);
                CueTemplate = this->osc2->common->End();
                break;
                case 7:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 9);
                CueTemplate = this->osc2->common->End();
                break;
                case 8:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 13);
                CueTemplate = this->osc2->common->End();
                break;
                case 9:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 5);
                CueTemplate = this->osc2->common->End();
                break;
                case 10:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 11:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 12:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 13:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 14:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
              case 15:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
              CueTemplate = this->osc2->common->End();
              break;
              case 16:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 17:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 18:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
            }


            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(CueTemplate);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(CueTemplate);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(CueTemplate);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(CueTemplate);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }

    }


}

void MainWindow::CreatePage4()
{
    //DPAGE 4
    QVector <PageHelper*> pagelist;
    PageHelper *hPage = new PageHelper();
    hPage->page = 104;
    hPage->group = 325;
    hPage->FlashStrobeCue = 5;
    pagelist.push_back(hPage);
    hPage = new PageHelper();
    hPage->page = 114;
    hPage->group = 345;
    hPage->FlashStrobeCue = 5;
    pagelist.push_back(hPage);

    // QVector<OSC_Common::btns>buttons;
    // this->osc->common->Begin();
    for(int i = 0; i < pagelist.size(); i++){
        int group = pagelist[i]->group;
        int page = pagelist[i]->page;
        int flashstrobecue = pagelist[i]->FlashStrobeCue;
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        //Intensity
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE2);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 0, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
         this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 16);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 17);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 18);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 19);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 20);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 21);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 22);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 23);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 24);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 25);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 26);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 34);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 35);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 36);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 37);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 38);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 39);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 40);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //COLOURS

        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE3);

        for(int y = 1; y< 19; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::COLOUR, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //POSITION
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE4);

        for(int y = 1; y< 12; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::POSITION, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 1
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE5);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 2
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE6);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y + 10);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //Pos FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE7);
        for(int y = 1; y< 8; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 60);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //COL FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE8);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 80);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //FLASH WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE9);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //STROBE WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE10);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 8);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);

    }

    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 125;
    h->group = 365;
    h->group2 = 385;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 125;
    h->group = 405;
    h->group2 = 425;
    h->group3 = 445;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 125;
    h->group = 465;
    h->group2 = 485;
    h->group3 = 505;
    h->group4 = 525;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 125;
    h->group = 365;
    h->group2 = 385;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 125;
    h->group = 405;
    h->group2 = 425;
    h->group3 = 445;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 125;
    h->group = 465;
    h->group2 = 485;
    h->group3 = 505;
    h->group4 = 525;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 125;
    h->group = 365;
    h->group2 = 385;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 125;
    h->group = 405;
    h->group2 = 425;
    h->group3 = 445;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 125;
    h->group = 465;
    h->group2 = 485;
    h->group3 = 505;
    h->group4 = 525;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 19; cue++){
            QVector<OSC_Common::btns> CueTemplate;
            switch(cue){
                case 1:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                CueTemplate = this->osc2->common->End();
                break;
                case 2:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                CueTemplate = this->osc2->common->End();
                break;
                case 3:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 4:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 5:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 7);
                CueTemplate = this->osc2->common->End();
                break;
                case 6:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 11);
                CueTemplate = this->osc2->common->End();
                break;
                case 7:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 9);
                CueTemplate = this->osc2->common->End();
                break;
                case 8:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 13);
                CueTemplate = this->osc2->common->End();
                break;
                case 9:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 5);
                CueTemplate = this->osc2->common->End();
                break;
                case 10:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 11:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 12:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 13:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 14:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
              case 15:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
              CueTemplate = this->osc2->common->End();
              break;
              case 16:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 17:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 18:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
            }


            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(CueTemplate);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(CueTemplate);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(CueTemplate);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(CueTemplate);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }

    }


}

void MainWindow::CreatePage5()
{
    //DPAGE 5
    QVector <PageHelper*> pagelist;
    PageHelper *hPage = new PageHelper();
    hPage->page = 105;
    hPage->group = 326;
    hPage->FlashStrobeCue = 6;
    pagelist.push_back(hPage);
    hPage = new PageHelper();
    hPage->page = 115;
    hPage->group = 346;
    hPage->FlashStrobeCue = 6;
    pagelist.push_back(hPage);

    // QVector<OSC_Common::btns>buttons;
    // this->osc->common->Begin();
    for(int i = 0; i < pagelist.size(); i++){
        int group = pagelist[i]->group;
        int page = pagelist[i]->page;
        int flashstrobecue = pagelist[i]->FlashStrobeCue;
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        //Intensity
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE2);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 0, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
         this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 16);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 17);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 18);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 19);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 20);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 21);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 22);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 23);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 24);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 25);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 26);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 34);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 35);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 36);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 37);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 38);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 39);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 40);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //COLOURS

        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE3);

        for(int y = 1; y< 19; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::COLOUR, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //POSITION
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE4);

        for(int y = 1; y< 12; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::POSITION, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 1
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE5);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 2
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE6);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y + 10);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //Pos FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE7);
        for(int y = 1; y< 8; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 60);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //COL FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE8);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 80);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //FLASH WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE9);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //STROBE WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE10);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 8);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);

    }

    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 126;
    h->group = 366;
    h->group2 = 386;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 126;
    h->group = 406;
    h->group2 = 426;
    h->group3 = 446;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 126;
    h->group = 466;
    h->group2 = 486;
    h->group3 = 506;
    h->group4 = 526;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 126;
    h->group = 366;
    h->group2 = 386;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 126;
    h->group = 406;
    h->group2 = 426;
    h->group3 = 446;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 126;
    h->group = 466;
    h->group2 = 486;
    h->group3 = 506;
    h->group4 = 526;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 126;
    h->group = 366;
    h->group2 = 386;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 126;
    h->group = 406;
    h->group2 = 426;
    h->group3 = 446;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 126;
    h->group = 466;
    h->group2 = 486;
    h->group3 = 506;
    h->group4 = 526;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 19; cue++){
            QVector<OSC_Common::btns> CueTemplate;
            switch(cue){
                case 1:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                CueTemplate = this->osc2->common->End();
                break;
                case 2:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                CueTemplate = this->osc2->common->End();
                break;
                case 3:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 4:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 5:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 7);
                CueTemplate = this->osc2->common->End();
                break;
                case 6:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 11);
                CueTemplate = this->osc2->common->End();
                break;
                case 7:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 9);
                CueTemplate = this->osc2->common->End();
                break;
                case 8:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 13);
                CueTemplate = this->osc2->common->End();
                break;
                case 9:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 5);
                CueTemplate = this->osc2->common->End();
                break;
                case 10:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 11:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 12:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 13:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 14:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
              case 15:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
              CueTemplate = this->osc2->common->End();
              break;
              case 16:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 17:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 18:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
            }


            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(CueTemplate);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(CueTemplate);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(CueTemplate);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(CueTemplate);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }

    }


}

void MainWindow::CreatePage6()
{
    //DPAGE 6
    QVector <PageHelper*> pagelist;
    PageHelper *hPage = new PageHelper();
    hPage->page = 106;
    hPage->group = 327;
    hPage->FlashStrobeCue = 7;
    pagelist.push_back(hPage);
    hPage = new PageHelper();
    hPage->page = 116;
    hPage->group = 347;
    hPage->FlashStrobeCue = 7;
    pagelist.push_back(hPage);

    // QVector<OSC_Common::btns>buttons;
    // this->osc->common->Begin();
    for(int i = 0; i < pagelist.size(); i++){
        int group = pagelist[i]->group;
        int page = pagelist[i]->page;
        int flashstrobecue = pagelist[i]->FlashStrobeCue;
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        //Intensity
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE2);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 0, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
         this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 16);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 17);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 18);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 19);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 20);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 21);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 22);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 23);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 24);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 25);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 26);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 34);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 35);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 36);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 37);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 38);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 39);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 40);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //COLOURS

        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE3);

        for(int y = 1; y< 19; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::COLOUR, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //POSITION
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE4);

        for(int y = 1; y< 12; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::POSITION, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 1
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE5);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 2
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE6);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y + 10);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //Pos FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE7);
        for(int y = 1; y< 8; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 60);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //COL FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE8);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 80);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //FLASH WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE9);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //STROBE WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE10);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 8);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);

    }

    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 127;
    h->group = 367;
    h->group2 = 387;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 127;
    h->group = 407;
    h->group2 = 427;
    h->group3 = 447;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 127;
    h->group = 467;
    h->group2 = 487;
    h->group3 = 507;
    h->group4 = 527;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 127;
    h->group = 367;
    h->group2 = 387;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 127;
    h->group = 407;
    h->group2 = 427;
    h->group3 = 447;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 127;
    h->group = 467;
    h->group2 = 487;
    h->group3 = 507;
    h->group4 = 527;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 127;
    h->group = 367;
    h->group2 = 387;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 127;
    h->group = 407;
    h->group2 = 427;
    h->group3 = 447;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 127;
    h->group = 467;
    h->group2 = 487;
    h->group3 = 507;
    h->group4 = 527;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 19; cue++){
            QVector<OSC_Common::btns> CueTemplate;
            switch(cue){
                case 1:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                CueTemplate = this->osc2->common->End();
                break;
                case 2:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                CueTemplate = this->osc2->common->End();
                break;
                case 3:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 4:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 5:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 7);
                CueTemplate = this->osc2->common->End();
                break;
                case 6:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 11);
                CueTemplate = this->osc2->common->End();
                break;
                case 7:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 9);
                CueTemplate = this->osc2->common->End();
                break;
                case 8:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 13);
                CueTemplate = this->osc2->common->End();
                break;
                case 9:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 5);
                CueTemplate = this->osc2->common->End();
                break;
                case 10:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 11:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 12:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 13:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 14:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
              case 15:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
              CueTemplate = this->osc2->common->End();
              break;
              case 16:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 17:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 18:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
            }


            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(CueTemplate);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(CueTemplate);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(CueTemplate);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(CueTemplate);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }

    }


}


void MainWindow::CreatePage7()
{
    //DPAGE 7
    QVector <PageHelper*> pagelist;
    PageHelper *hPage = new PageHelper();
    hPage->page = 107;
    hPage->group = 328;
    hPage->FlashStrobeCue = 8;
    pagelist.push_back(hPage);
    hPage = new PageHelper();
    hPage->page = 117;
    hPage->group = 348;
    hPage->FlashStrobeCue = 8;
    pagelist.push_back(hPage);

    // QVector<OSC_Common::btns>buttons;
    // this->osc->common->Begin();
    for(int i = 0; i < pagelist.size(); i++){
        int group = pagelist[i]->group;
        int page = pagelist[i]->page;
        int flashstrobecue = pagelist[i]->FlashStrobeCue;
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        //Intensity
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE2);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 0, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
         this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 16);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 17);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 18);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 19);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 20);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 21);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 22);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 23);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 24);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 25);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 26);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 34);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 35);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 36);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 37);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 38);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 39);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 40);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //COLOURS

        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE3);

        for(int y = 1; y< 19; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::COLOUR, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //POSITION
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE4);

        for(int y = 1; y< 12; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::POSITION, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 1
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE5);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 2
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE6);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y + 10);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //Pos FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE7);
        for(int y = 1; y< 8; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 60);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //COL FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE8);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 80);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //FLASH WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE9);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //STROBE WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE10);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 8);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);

    }

    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 128;
    h->group = 368;
    h->group2 = 388;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 128;
    h->group = 408;
    h->group2 = 428;
    h->group3 = 448;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 128;
    h->group = 468;
    h->group2 = 488;
    h->group3 = 508;
    h->group4 = 528;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 128;
    h->group = 368;
    h->group2 = 388;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 128;
    h->group = 408;
    h->group2 = 428;
    h->group3 = 448;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 128;
    h->group = 468;
    h->group2 = 488;
    h->group3 = 508;
    h->group4 = 528;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 128;
    h->group = 368;
    h->group2 = 388;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 128;
    h->group = 408;
    h->group2 = 428;
    h->group3 = 448;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 128;
    h->group = 468;
    h->group2 = 488;
    h->group3 = 508;
    h->group4 = 528;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 19; cue++){
            QVector<OSC_Common::btns> CueTemplate;
            switch(cue){
                case 1:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                CueTemplate = this->osc2->common->End();
                break;
                case 2:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                CueTemplate = this->osc2->common->End();
                break;
                case 3:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 4:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 5:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 7);
                CueTemplate = this->osc2->common->End();
                break;
                case 6:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 11);
                CueTemplate = this->osc2->common->End();
                break;
                case 7:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 9);
                CueTemplate = this->osc2->common->End();
                break;
                case 8:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 13);
                CueTemplate = this->osc2->common->End();
                break;
                case 9:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 5);
                CueTemplate = this->osc2->common->End();
                break;
                case 10:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 11:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 12:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 13:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 14:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
              case 15:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
              CueTemplate = this->osc2->common->End();
              break;
              case 16:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 17:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 18:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
            }

            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(CueTemplate);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(CueTemplate);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(CueTemplate);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(CueTemplate);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }

    }


}

void MainWindow::CreatePage8()
{
    //DPAGE 8
    QVector <PageHelper*> pagelist;
    PageHelper *hPage = new PageHelper();
    hPage->page = 108;
    hPage->group = 329;
    hPage->FlashStrobeCue = 9;
    pagelist.push_back(hPage);
    hPage = new PageHelper();
    hPage->page = 118;
    hPage->group = 349;
    hPage->FlashStrobeCue = 9;
    pagelist.push_back(hPage);

    // QVector<OSC_Common::btns>buttons;
    // this->osc->common->Begin();
    for(int i = 0; i < pagelist.size(); i++){
        int group = pagelist[i]->group;
        int page = pagelist[i]->page;
        int flashstrobecue = pagelist[i]->FlashStrobeCue;
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        //Intensity
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE2);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 0, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
         this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 16);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 17);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 18);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 19);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 20);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 21);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 22);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 23);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 24);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 25);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 26);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 34);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 35);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 36);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 37);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 38);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 39);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 40);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //COLOURS

        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE3);

        for(int y = 1; y< 19; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::COLOUR, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //POSITION
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE4);

        for(int y = 1; y< 12; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::POSITION, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 1
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE5);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 2
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE6);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y + 10);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //Pos FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE7);
        for(int y = 1; y< 8; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 60);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //COL FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE8);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 80);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //FLASH WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE9);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //STROBE WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE10);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 8);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);

    }

    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 129;
    h->group = 369;
    h->group2 = 389;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 129;
    h->group = 409;
    h->group2 = 429;
    h->group3 = 449;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 129;
    h->group = 469;
    h->group2 = 489;
    h->group3 = 509;
    h->group4 = 529;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 129;
    h->group = 369;
    h->group2 = 389;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 129;
    h->group = 409;
    h->group2 = 429;
    h->group3 = 449;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 129;
    h->group = 469;
    h->group2 = 489;
    h->group3 = 509;
    h->group4 = 529;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 129;
    h->group = 369;
    h->group2 = 389;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 129;
    h->group = 409;
    h->group2 = 429;
    h->group3 = 449;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 129;
    h->group = 469;
    h->group2 = 489;
    h->group3 = 509;
    h->group4 = 529;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 19; cue++){
            QVector<OSC_Common::btns> CueTemplate;
            switch(cue){
                case 1:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                CueTemplate = this->osc2->common->End();
                break;
                case 2:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                CueTemplate = this->osc2->common->End();
                break;
                case 3:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 4:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 5:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 7);
                CueTemplate = this->osc2->common->End();
                break;
                case 6:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 11);
                CueTemplate = this->osc2->common->End();
                break;
                case 7:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 9);
                CueTemplate = this->osc2->common->End();
                break;
                case 8:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 13);
                CueTemplate = this->osc2->common->End();
                break;
                case 9:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 5);
                CueTemplate = this->osc2->common->End();
                break;
                case 10:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 11:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 12:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 13:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 14:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
              case 15:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
              CueTemplate = this->osc2->common->End();
              break;
              case 16:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 17:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 18:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
            }


            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(CueTemplate);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(CueTemplate);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(CueTemplate);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(CueTemplate);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }

    }


}

void MainWindow::CreatePage9()
{
    //DPAGE 9
    QVector <PageHelper*> pagelist;
    PageHelper *hPage = new PageHelper();
    hPage->page = 109;
    hPage->group = 330;
    hPage->FlashStrobeCue = 10;
    pagelist.push_back(hPage);
    hPage = new PageHelper();
    hPage->page = 119;
    hPage->group = 350;
    hPage->FlashStrobeCue = 10;
    pagelist.push_back(hPage);

    // QVector<OSC_Common::btns>buttons;
    // this->osc->common->Begin();
    for(int i = 0; i < pagelist.size(); i++){
        int group = pagelist[i]->group;
        int page = pagelist[i]->page;
        int flashstrobecue = pagelist[i]->FlashStrobeCue;
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        //Intensity
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE2);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 0, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
         this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 16);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 17);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 18);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 19);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 20);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 21);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 22);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 23);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 24);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 25);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 26);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 34);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 35);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 36);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 37);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 38);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 39);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 40);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //COLOURS

        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE3);

        for(int y = 1; y< 19; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::COLOUR, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //POSITION
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE4);

        for(int y = 1; y< 12; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::POSITION, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 1
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE5);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 2
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE6);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y + 10);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //Pos FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE7);
        for(int y = 1; y< 8; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 60);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //COL FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE8);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 80);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //FLASH WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE9);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //STROBE WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE10);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 8);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);

    }

    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 130;
    h->group = 370;
    h->group2 = 390;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 130;
    h->group = 410;
    h->group2 = 430;
    h->group3 = 450;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 130;
    h->group = 470;
    h->group2 = 490;
    h->group3 = 510;
    h->group4 = 530;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 130;
    h->group = 370;
    h->group2 = 390;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 130;
    h->group = 410;
    h->group2 = 430;
    h->group3 = 450;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 130;
    h->group = 470;
    h->group2 = 490;
    h->group3 = 510;
    h->group4 = 530;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 130;
    h->group = 370;
    h->group2 = 390;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 130;
    h->group = 410;
    h->group2 = 430;
    h->group3 = 450;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 130;
    h->group = 470;
    h->group2 = 490;
    h->group3 = 510;
    h->group4 = 530;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 19; cue++){
            QVector<OSC_Common::btns> CueTemplate;
            switch(cue){
                case 1:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                CueTemplate = this->osc2->common->End();
                break;
                case 2:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                CueTemplate = this->osc2->common->End();
                break;
                case 3:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 4:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 5:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 7);
                CueTemplate = this->osc2->common->End();
                break;
                case 6:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 11);
                CueTemplate = this->osc2->common->End();
                break;
                case 7:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 9);
                CueTemplate = this->osc2->common->End();
                break;
                case 8:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 13);
                CueTemplate = this->osc2->common->End();
                break;
                case 9:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 5);
                CueTemplate = this->osc2->common->End();
                break;
                case 10:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 11:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 12:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 13:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 14:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
              case 15:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
              CueTemplate = this->osc2->common->End();
              break;
              case 16:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 17:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 18:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
            }


            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(CueTemplate);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(CueTemplate);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(CueTemplate);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(CueTemplate);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }

    }


}

void MainWindow::CreatePage10()
{
    //DPAGE 10
    QVector <PageHelper*> pagelist;
    PageHelper *hPage = new PageHelper();
    hPage->page = 110;
    hPage->group = 331;
    hPage->FlashStrobeCue = 11;
    pagelist.push_back(hPage);
    hPage = new PageHelper();
    hPage->page = 120;
    hPage->group = 351;
    hPage->FlashStrobeCue = 11;
    pagelist.push_back(hPage);

    // QVector<OSC_Common::btns>buttons;
    // this->osc->common->Begin();
    for(int i = 0; i < pagelist.size(); i++){
        int group = pagelist[i]->group;
        int page = pagelist[i]->page;
        int flashstrobecue = pagelist[i]->FlashStrobeCue;
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        //Intensity
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE2);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 0, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
         this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 16);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 17);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 18);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 19);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 4,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 20);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 21);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 22);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 5,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 23);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 24);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 25);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 26);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 6,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 34);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 35);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 36);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 7,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 37);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 38);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,1);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 39);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,2);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 40);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, 8,3);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //COLOURS

        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE3);

        for(int y = 1; y< 19; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::COLOUR, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //POSITION
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE4);

        for(int y = 1; y< 12; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::POSITION, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 1
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE5);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //BEAM 2
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE6);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::BEAM, y + 10);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //Pos FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE7);
        for(int y = 1; y< 8; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 60);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //COL FX
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE8);
        for(int y = 1; y< 11; y++){
            this->osc->common->Add_Step(OSC_Common::GROUP, group);
            this->osc->common->Add_Step(OSC_Common::EFFECT, y + 80);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, y);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::CLEAR);
        }
        //FLASH WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE9);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        //STROBE WHITE
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CHOOSE10);
        this->osc->common->Add_Step(OSC_Common::GROUP, group);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 15);
        this->osc->common->Add_Step(OSC_Common::INTENSITY, 8);
        this->osc->common->Add_Step(OSC_Common::COLOUR, 1);
        this->osc->common->Add_Step(OSC_Common::TIME, 0);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, flashstrobecue);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        this->osc->common->Add_Step(OSC_Common::CLEAR);

    }

    QVector<PageHelper*>list;
    QVector<PageHelper*>template_list;
    PageHelper *h = new PageHelper();
    h->page = 131;
    h->group = 371;
    h->group2 = 391;
    h->fader = 2;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 131;
    h->group = 411;
    h->group2 = 431;
    h->group3 = 451;
    h->fader = 3;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 131;
    h->group = 471;
    h->group2 = 491;
    h->group3 = 511;
    h->group4 = 531;
    h->fader = 4;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 0;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 131;
    h->group = 371;
    h->group2 = 391;
    h->fader = 5;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 131;
    h->group = 411;
    h->group2 = 431;
    h->group3 = 451;
    h->fader = 6;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 131;
    h->group = 471;
    h->group2 = 491;
    h->group3 = 511;
    h->group4 = 531;
    h->fader = 7;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = false;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 131;
    h->group = 371;
    h->group2 = 391;
    h->fader = 8;
    h->parts = 2;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 131;
    h->group = 411;
    h->group2 = 431;
    h->group3 = 451;
    h->fader = 9;
    h->parts = 3;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    h = new PageHelper();
    h->page = 131;
    h->group = 471;
    h->group2 = 491;
    h->group3 = 511;
    h->group4 = 531;
    h->fader = 10;
    h->parts = 4;
    h->fade_inc = 0;
    h->fade_dec = 8;
    h->snap = true;
    list.push_back(h);
    template_list.push_back(h);

    for(int i = 0; i < list.size(); i++){
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::PAGE, list[i]->page);
        this->osc->common->Add_Step(OSC_Common::ENTER);
        switch(list[i]->fader){
        case 1:
            this->osc->common->Add_Step(OSC_Common::CHOOSE1);
            break;
        case 2:
            this->osc->common->Add_Step(OSC_Common::CHOOSE2);
            break;
        case 3:
            this->osc->common->Add_Step(OSC_Common::CHOOSE3);
            break;
        case 4:
            this->osc->common->Add_Step(OSC_Common::CHOOSE4);
            break;
        case 5:
            this->osc->common->Add_Step(OSC_Common::CHOOSE5);
            break;
        case 6:
            this->osc->common->Add_Step(OSC_Common::CHOOSE6);
            break;
        case 7:
            this->osc->common->Add_Step(OSC_Common::CHOOSE7);
            break;
        case 8:
            this->osc->common->Add_Step(OSC_Common::CHOOSE8);
            break;
        case 9:
            this->osc->common->Add_Step(OSC_Common::CHOOSE9);
            break;
        case 10:
            this->osc->common->Add_Step(OSC_Common::CHOOSE10);
            break;
        } // case fader

        this->osc->common->Add_Step(OSC_Common::CLEAR);
        this->osc->common->Add_Step(OSC_Common::FALL_BACK);
        for(int cue = 1; cue < 19; cue++){
            QVector<OSC_Common::btns> CueTemplate;
            switch(cue){
                case 1:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                CueTemplate = this->osc2->common->End();
                break;
                case 2:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                CueTemplate = this->osc2->common->End();
                break;
                case 3:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 4:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 5:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 7);
                CueTemplate = this->osc2->common->End();
                break;
                case 6:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 11);
                CueTemplate = this->osc2->common->End();
                break;
                case 7:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 9);
                CueTemplate = this->osc2->common->End();
                break;
                case 8:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 13);
                CueTemplate = this->osc2->common->End();
                break;
                case 9:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 5);
                CueTemplate = this->osc2->common->End();
                break;
                case 10:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 11:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 2);
                CueTemplate = this->osc2->common->End();
                break;
                case 12:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::BEAM, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 13:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 1);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
                case 14:
                this->osc2->common->Begin();
                this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
                this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
                CueTemplate = this->osc2->common->End();
                break;
              case 15:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::INTENSITY, 4);
              CueTemplate = this->osc2->common->End();
              break;
              case 16:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 17:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
              case 18:
              this->osc2->common->Begin();
              //this->osc2->common->Add_Step(OSC_Common::COLOUR, 15);
              this->osc2->common->Add_Step(OSC_Common::CLEAR);
              CueTemplate = this->osc2->common->End();
              break;
            }

            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            if(list[i]->snap){
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,1);
                this->osc->common->Add_Step(OSC_Common::ENTER);
            }
            this->osc->common->Add_Step(OSC_Common::CLEAR);
            this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group);
            this->osc->common->Add_Step(CueTemplate);
            this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
            this->osc->common->Add_Step(OSC_Common::ENTER);
            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue,15);
            this->osc->common->Add_Step(OSC_Common::ENTER);

            if(list[i]->parts > 1){
                if(list[i]->snap){
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 2);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                }
                this->osc->common->Add_Step(OSC_Common::CLEAR);
                this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group2);
                this->osc->common->Add_Step(CueTemplate);
                this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                this->osc->common->Add_Step(OSC_Common::ENTER);
                this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 25);
                this->osc->common->Add_Step(OSC_Common::ENTER);

                if(list[i]->parts > 2){
                    if(list[i]->snap){
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 3);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                    }
                    this->osc->common->Add_Step(OSC_Common::CLEAR);
                    this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group3);
                    this->osc->common->Add_Step(CueTemplate);
                    this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                    this->osc->common->Add_Step(OSC_Common::ENTER);
                    this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 35);
                    this->osc->common->Add_Step(OSC_Common::ENTER);

                    if(list[i]->parts > 3){
                        if(list[i]->snap){
                            this->osc->common->Add_Step(OSC_Common::CLEAR);
                            this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 4);
                            this->osc->common->Add_Step(OSC_Common::ENTER);
                        }
                        this->osc->common->Add_Step(OSC_Common::CLEAR);
                        this->osc->common->Add_Step(OSC_Common::GROUP, list[i]->group4);
                        this->osc->common->Add_Step(CueTemplate);
                        this->osc->common->Add_Step(OSC_Common::TIME, list[i]->fade_inc, list[i]->fade_dec);
                        this->osc->common->Add_Step(OSC_Common::ENTER);
                        this->osc->common->Add_Step(OSC_Common::RECORD, OSC_Common::CUE, cue, 45);
                        this->osc->common->Add_Step(OSC_Common::ENTER);

                    }
                }
            }
        }

    }


}



void MainWindow::on_pushButton_7_clicked()
{
  this->osc->add_Quee(OSC_Common::A);
  this->osc->add_Quee(OSC_Common::B);
}

