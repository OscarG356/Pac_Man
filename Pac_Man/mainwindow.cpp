#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,400,400);

    personaje = new cuerpo();
    enemigo = new enemy();
    puntaje = new Score();
    vida = new Live();
    win = new Anuncios(0,true);
    lose = new Anuncios(0,false);

    try {
         Archivo.open("Muros.txt");
         if(!Archivo.is_open()){
             throw 1;
         }

    }  catch (int c) {
        if(c==1){
            qDebug()<<"No se encontro el archivo Muros.txt";
        }
    }
    while(!Archivo.eof()){
        Archivo>>w>>h>>x>>y;
        paredes.push_back(new pared(w,h,x,y));scene->addItem(paredes.back());
    }
    Archivo.close();

    try {
         Archivo.open("Monedas.txt");
         if(!Archivo.is_open()){
             throw 1;
         }

    }  catch (int c) {
        if(c==1){
            qDebug()<<"No se encontro el archivo Monedas.txt";
        }
    }
    while(!Archivo.eof()){
        Archivo>>r>>x>>y;
        monedas.push_back(new moneda(r,x,y));scene->addItem(monedas.back());
    }
    Archivo.close();

    scene->addItem(personaje);
    scene->addItem(enemigo);
    scene->addItem(puntaje);
    scene->addItem(vida);


    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    timer->start(30);


    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/prefix1/pacman-song.mp3"));
    music->play();

}



void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/prefix1/pacman-waka-waka.mp3"));

    //qDebug()<<"x: "<<personaje->x()<<" "<<"y: "<<personaje->y();

    if(evento->key() == Qt::Key_A){
        personaje->left();

        if(monedas.size()==0){
            clear_all();
            scene->addItem(win);
        }

        if(personaje->collidesWithItem(enemigo)){
            vida->decrease();

            personaje->setPosx(-150);
            personaje->setPosy(110);
            enemigo->setPosx(246);
            enemigo->setPosy(200);

            if(vida->getlive()==0){
                clear_all();
                scene->addItem(lose);
            }
        }

        for (int i = 0;i < monedas.size();i++) {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                puntaje->increase();
                if(music->state()== QMediaPlayer::PlayingState){
                    music->setPosition(0);
                }
                else if(music->state() == QMediaPlayer::StoppedState){
                    music->play();
                }

                music->play();
                //monedas = eliminarMonedas(monedas,i);
                monedas.removeAt(i);
            }
        }

        for(int i=0; i<paredes.size();i++){
            if(personaje->collidesWithItem(paredes.at(i))){
                personaje->right();
            }
        }
        if(personaje->x() <=-170){
            personaje->setPosx(570);
        }
    }
    else if(evento->key() == Qt::Key_D){
        personaje->right();

        if(monedas.size()==0){
            clear_all();
            scene->addItem(win);
        }

        if(personaje->collidesWithItem(enemigo)){
            vida->decrease();

            personaje->setPosx(-150);
            personaje->setPosy(110);
            enemigo->setPosx(246);
            enemigo->setPosy(200);

            if(vida->getlive()==0){
                clear_all();
                scene->addItem(lose);
            }
        }

        for (int i = 0;i < monedas.size();i++) {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                puntaje->increase();
                if(music->state()== QMediaPlayer::PlayingState){
                    music->setPosition(0);
                    music->play();
                }
                else if(music->state() == QMediaPlayer::StoppedState){
                    music->play();
                }
                //monedas = eliminarMonedas(monedas,i);
                monedas.removeAt(i);
            }
        }

        for(int i=0; i<paredes.size();i++){
            if(personaje->collidesWithItem(paredes.at(i))){
                personaje->left();
            }
        }
        if(personaje->x() >=571){
            personaje->setPosx(-169);
        }
    }

    else if(evento->key() == Qt::Key_W){
        personaje->up();

        if(monedas.size()==0){
            clear_all();
            scene->addItem(win);
        }

        if(personaje->collidesWithItem(enemigo)){
            vida->decrease();

            personaje->setPosx(-150);
            personaje->setPosy(110);
            enemigo->setPosx(246);
            enemigo->setPosy(200);

            if(vida->getlive()==0){
                clear_all();
                scene->addItem(lose);
            }
        }

        for (int i = 0;i < monedas.size();i++) {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                puntaje->increase();
                if(music->state()== QMediaPlayer::PlayingState){
                    music->setPosition(0);
                }
                else if(music->state() == QMediaPlayer::StoppedState){
                    music->play();
                }

                music->play();
                monedas.removeAt(i);
            }
        }

        for(int i=0; i<paredes.size();i++){
            if(personaje->collidesWithItem(paredes.at(i))){
                personaje->down();
            }
        }
        if(personaje->y() <=90){
            personaje->setPosy(455);
        }
    }

    else if(evento->key() == Qt::Key_S){
        personaje->down();

        if(monedas.size()==0){
            clear_all();
            scene->addItem(win);
        }

        if(personaje->collidesWithItem(enemigo)){
            vida->decrease();

            personaje->setPosx(-150);
            personaje->setPosy(110);
            enemigo->setPosx(246);
            enemigo->setPosy(200);

            if(vida->getlive()==0){
                clear_all();
                scene->addItem(lose);
            }
        }
        for (int i = 0;i < monedas.size();i++) {
            if(personaje->collidesWithItem(monedas.at(i))){
                scene->removeItem(monedas.at(i));
                puntaje->increase();
                if(music->state()== QMediaPlayer::PlayingState){
                    music->setPosition(0);
                    music->play();
                }
                else if(music->state() == QMediaPlayer::StoppedState){
                    music->play();
                }

                //monedas = eliminarMonedas(monedas,i);
                monedas.removeAt(i);
            }
        }

        for(int i=0; i<paredes.size();i++){
            if(personaje->collidesWithItem(paredes.at(i))){
                personaje->up();
            }
        }
        if(personaje->y() >=456){
            personaje->setPosy(91);
        }
    }
}

QList<moneda *> MainWindow::eliminarMonedas(QList<moneda *> monedas, int pos)
{
    QList<moneda *> aux;
    for (int i = 0;i < monedas.size() ; i++) {
        if(i != pos){
            aux.push_back(monedas.at(i));
        }
    }
    return aux;
}

QList<pared *> MainWindow::eliminarParedes(QList<pared *> paredes, int pos)
{
    QList<pared *> aux;
    for (int i = 0;i < paredes.size() ; i++) {
        if(i != pos){
            aux.push_back(paredes.at(i));
        }
    }
    return aux;
}

void MainWindow::clear_all()
{
    scene->removeItem(personaje);
    scene->removeItem(enemigo);

    for (int i = 0;i < monedas.size();i++) {
        scene->removeItem(monedas.at(i));
        eliminarMonedas(monedas,i);
    }

    for (int i = 0;i < paredes.size();i++) {
        scene->removeItem(paredes.at(i));
        eliminarParedes(paredes,i);
    }
}


void MainWindow::moveEnemy()
{
    if(enemigo->x() < personaje->x()){
        enemigo->right();
        for(int i=0; i<paredes.size();i++){
            if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->left();
            }
        }
    }
    else if(enemigo->x() > personaje->x()){
        enemigo->left();
        for(int i=0; i<paredes.size();i++){
            if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->right();
            }
        }
    }

    if(enemigo->y() < personaje->y()){
        enemigo->down();
        for(int i=0; i<paredes.size();i++){
            if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->up();
            }
        }
    }
    else if(enemigo->y() > personaje->y()){
        enemigo->up();
        for(int i=0; i<paredes.size();i++){
            if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->down();
            }
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}




