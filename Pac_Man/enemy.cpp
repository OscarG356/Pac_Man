#include "enemy.h"


enemy::enemy(QObject *parent) : QObject(parent)
{
    columnas = 0; //Para variar en el sprite
    filas=0;

    pixmap = new QPixmap(":/Enemy.png"); //Añadir imagen

    //Dimensiones
    ancho = 100;
    alto = 100;
    setScale(0.35);

    setPos(posx,posy);

    //Movimineto;
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &enemy::Actualizacion);
    timer->start(150);
}


QRectF enemy::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap ghost;
    ghost.load(":/Enemy.png");
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);

}

void enemy::up()
{
    posy -= velocidad;
    setFilas(0);
    setPos(posx, posy);    
}

void enemy::down()
{
    posy += velocidad;
    setFilas(300);
    setPos(posx, posy);
}

void enemy::left()
{
    posx -= velocidad;
    setFilas(200);
    setPos(posx, posy);
}

void enemy::right()
{
    posx += velocidad;
    setFilas(100);
    setPos(posx, posy);
}

void enemy::Actualizacion()
{
    columnas += 100;
    if(columnas >= 200){
        columnas = 0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}


void enemy::setFilas(float value)
{
    filas = value;
}
void enemy::setPosx(int value)
{
    posx = value;
}


void enemy::setPosy(int value)
{
    posy = value;
}
