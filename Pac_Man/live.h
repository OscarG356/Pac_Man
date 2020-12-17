#ifndef LIVE_H
#define LIVE_H


#include <QGraphicsTextItem>

class Live: public QGraphicsTextItem
{
public:
    Live(QGraphicsItem * parent=0);
    void decrease();
    int getlive();


private:
    int live;
};

#endif // LIVE_H
