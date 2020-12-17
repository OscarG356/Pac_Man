#include "cuerpo.h"

void cuerpo::setPosx(int value)
{
    posx = value;
}

void cuerpo::setPosy(int value)
{
    posy = value;
}

cuerpo::cuerpo(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    columnas = 0; //Para variar en el sprite

    pixmap = new QPixmap(":/PACMAN.png"); //Añadir imagen

    //Dimensiones
    ancho = 100;
    alto = 100;
    setScale(0.35);

    setPos(posx,posy);

    //Movimineto
    timer->start(80);
    connect(timer, &QTimer::timeout, this, &cuerpo::Actualizacion);
}

QRectF cuerpo::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::red);
//    painter->drawEllipse(boundingRect());

    QPixmap pac;
    pac.load(":/PACMAN.png");
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

void cuerpo::up()
{
    posy-= velocidad;
    setPos(posx,posy);
    setRotation(270);
}

void cuerpo::down()
{

    posy+= velocidad;
    setPos(posx,posy);
    setRotation(90);
}

void cuerpo::left()
{
    posx-= velocidad;
    setPos(posx,posy);
    setRotation(180);

}

void cuerpo::right()
{
    posx+= velocidad;
    setPos(posx,posy);
    setRotation(0);
}

void cuerpo::Actualizacion()
{
    columnas +=100;
    if(columnas>=400){
        columnas=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}





