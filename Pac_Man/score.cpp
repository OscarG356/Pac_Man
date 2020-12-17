#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score=0;
    setPlainText(QString("Score: ")+ QString::number(score));//COnvertir entero a string
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Tekton Pro",25));
    setPos(-150,-40);
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+ QString::number(score));//COnvertir entero a string
}

int Score::getScore()
{

    return score;
}
