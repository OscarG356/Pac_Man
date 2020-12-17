#include "live.h"
#include <QFont>

Live::Live(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    live=3;
    setPlainText(QString("Lives: ")+ QString::number(live));//COnvertir entero a string
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Tekton Pro",25));
    setPos(430,-40);
}

void Live::decrease()
{
    live--;
    setPlainText(QString("Live: ")+ QString::number(live));//COnvertir entero a string
}

int Live::getlive()
{

    return live;
}
