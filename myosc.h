#ifndef MYOSC_H
#define MYOSC_H

#include <QObject>
#include <QMutex>
#include "osc_interface.h"
#include "osc_common.h"
#include "osc_button.h"

//QT_FORWARD_DECLARE_CLASS(OSC_Interface);
//QT_FORWARD_DECLARE_CLASS(OSC_Button);

class MyOSC : public QObject
{
    Q_OBJECT




public:
    explicit MyOSC(QObject *parent = nullptr);
    void Connect(QString IP, int hostport, int myport);
    void Press(OSC_Common::btns button);
    void Test(int faderpos);

    void add_Quee(OSC_Common::btns btn);
    void Pauze(bool pauze);

    OSC_Interface *osc_interface;
     OSC_Common *common;



public slots:
     void dispatchMessage(OSC_Interface::osc_message message);
  //
   // void dispatchBundle(const QOscBundle&);
   // void dispatchMessage(const QOscMessage&);

private:
    QMutex m;
    QVector<OSC_Common::btns>Quee;
    QVector<OSC_Common::btns>Fallback;
    void LoadButtons();

    QVector<OSC_Button*>buttons;

    int last_report;
    void Work();
    bool pauze;
    // OSC *osc;

signals:
    void PublishCommandline(QString commandline);
    void PublishLog(QString item);
    void ReportProgress(int QueeLength);
    void PageComplete(int pagenum);
};

#endif // MYOSC_H
