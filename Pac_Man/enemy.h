#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QTimer>

class enemy: public QObject, public QGraphicsItem
{
    int r=50;
    int velocidad = 1;
    int posx=246, posy=200;
    float columnas,filas;
    float ancho,alto;

    Q_OBJECT

public:
    explicit enemy(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;



    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void up();
    void down();
    void left();
    void right();

    void setPosx(int value);
    void setPosy(int value);

    void setFilas(float value);

signals:

public slots:
    void Actualizacion();

};

#endif // ENEMY_H
