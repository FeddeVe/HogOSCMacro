#ifndef PAGEHELPER_H
#define PAGEHELPER_H

#include <QObject>

class PageHelper : public QObject
{
    Q_OBJECT
public:
    explicit PageHelper(QObject *parent = nullptr);
    int page;
    int group;
    int group2;
    int group3;
    int group4;
    int parts;
    int fader;
    int fade_inc;
    int fade_dec;
    int FlashStrobeCue;
    bool snap;

signals:

};

#endif // PAGEHELPER_H
