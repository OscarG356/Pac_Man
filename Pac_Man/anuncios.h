#ifndef ANUNCIOS_H
#define ANUNCIOS_H

#include <QGraphicsTextItem>

class Anuncios: public QGraphicsTextItem
{
public:
    Anuncios(QGraphicsItem * parent=0,bool evento=false);
};

#endif // ANUNCIOS_H
