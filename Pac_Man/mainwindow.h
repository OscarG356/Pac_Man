#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cuerpo.h"
#include "enemy.h"
#include "pared.h"
#include "score.h"
#include "moneda.h"
#include "live.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QMediaPlayer>
#include <QDebug>
#include <QList>
#include <qlist.h>
#include "anuncios.h"
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<moneda *> monedas;
    QList<pared *> paredes;


public slots:
    void moveEnemy();

private:
    Ui::MainWindow *ui;
    cuerpo *personaje;
    enemy *enemigo;
    Score *puntaje;
    Live *vida;
    Anuncios *win;
    Anuncios *lose;
    QGraphicsScene *scene;
    void keyPressEvent(QKeyEvent * evento);
    QTimer *timer;
    QList<moneda *> eliminarMonedas(QList<moneda *> monedas,int pos);   
    QList<pared *> eliminarParedes(QList<pared *> paredes, int pos);
    int w,h,x,y,r;
    void clear_all();    
    std::ifstream Archivo;

};
#endif // MAINWINDOW_H
