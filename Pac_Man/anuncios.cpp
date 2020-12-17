#include "anuncios.h"
#include <QFont>

Anuncios::Anuncios(QGraphicsItem *parent, bool evento): QGraphicsTextItem(parent)
{
    if(evento){
        setPlainText(QString("¡¡¡YOU WIN!!!"));
        setDefaultTextColor(Qt::yellow);
        setFont(QFont("Tekton Pro",50));
        setPos(120,250);
    }
    else{
        setPlainText(QString("YOU LOSE"));
        setDefaultTextColor(Qt::yellow);
        setFont(QFont("Tekton Pro",50));
        setPos(120,250);
    }
}

