#ifndef OSC_COMMON_H
#define OSC_COMMON_H

#include <QObject>

class OSC_Common : public QObject
{
    Q_OBJECT
public:
    explicit OSC_Common(QObject *parent = nullptr);

    enum btns{
        CHOOSE1,
        CHOOSE2,
        CHOOSE3,
        CHOOSE4,
        CHOOSE5,
        CHOOSE6,
        CHOOSE7,
        CHOOSE8,
        CHOOSE9,
        CHOOSE10,
        CUE,
        LIST,
        PAGE,
        RECORD,
        INTENSITY,
        POSITION,
        COLOUR,
        BEAM,
        EFFECT,
        TIME,
        GROUP,
        FIXTURE,
        ZERO,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        DOT,
        ENTER,
        CLEAR,
        A,
        B,
        FALL_BACK,
        PAGE_0_COMPLETE,
        PAGE_1_COMPLETE,
        PAGE_2_COMPLETE,
        PAGE_3_COMPLETE,
        PAGE_4_COMPLETE,
        PAGE_5_COMPLETE,
        PAGE_6_COMPLETE,
        PAGE_7_COMPLETE,
        PAGE_8_COMPLETE,
        PAGE_9_COMPLETE,
        PAGE_10_COMPLETE,
        TOTAL_BUTTONS,
    };

    void inc_tickDelay();
    void dec_tickDelay();

    int TickDelay;

    void Begin();
    void Add_Step(btns);
    void Add_Step(btns, int); // signle int
    void Add_Step(btns, int, int); // Decimal int
    void Add_Step(btns, btns, int); // Record Cue 10
    void Add_Step(btns, btns, int, int); //Record Cue 10.1
    void Add_Step(QVector<OSC_Common::btns> btns);
    QVector<btns> End();

private:
    QVector<btns>Result;

    void Add_Integer(int value);
signals:

};

#endif // OSC_COMMON_H
