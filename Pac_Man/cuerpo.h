#ifndef CUERPO_H
#define CUERPO_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>


class cuerpo: public QObject, public QGraphicsItem
{

    int posx=-150, posy=110;
    int velocidad = 3;
    float columnas;
    float ancho,alto;

        Q_OBJECT
public:
    explicit cuerpo(QObject *parent = nullptr);

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

signals:

public slots:
    void Actualizacion();

};
#endif // CUERPO_H
