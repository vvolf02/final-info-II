#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QPixmap>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , score(0)
    , timeLeft(90)
{
    string row, posx, posy, ancho, alto, radio;
    int x, y, h, al, r;
    ui->setupUi(this);
    prota=new mc(13, 175, 12);
    scene=new QGraphicsScene();
    scene->setSceneRect(0, 0, 867, 389);
    QPixmap background(":/Imagen/marmol.jpg");
    scene->setBackgroundBrush(background);
    ui->graphicsView->setScene(scene);
    scene->addItem(prota);
    ifstream file("paredes.txt");
    while (getline(file, row))
    {
        if (row.empty()) continue;
        posx=grupito(row, ',');
        x=stoi(posx);
        row=resize(row, ',');
        posy=grupito(row, ',');
        y=stoi(posy);
        row=resize(row, ',');
        ancho=grupito(row, ',');
        h=stoi(ancho);
        row=resize(row, ',');
        alto=grupito(row, ',');
        al=stoi(alto);
        int id=0;
        paredes.push_back(new pared(x, y, h, al, id));
        scene->addItem(paredes.back());
    }
    file.close();
    if (!paredes.empty())
    {
        scene->addItem(paredes.back());
    }
    pared* npared=new pared(349, 205, 172, 62, 1);
    npared->setTexture(":/Imagen/escaleras.jpg");
    paredes.push_back(npared);
    scene->addItem(paredes.back());
    row="";
    ifstream archivo("punticos.txt");
    while (getline(archivo, row))
    {
        if (row.empty()) continue;
        posx=grupito(row, ',');
        x=stoi(posx);
        row=resize(row, ',');
        posy=grupito(row, ',');
        y=stoi(posy);
        row=resize(row, ',');
        radio=grupito(row, ',');
        r=stoi(radio);
        punto.push_back(new puntos(x, y, r));
        scene->addItem(punto.back());
    }
    archivo.close();
    if (!punto.empty())
    {
        scene->addItem(punto.back());
    }

    /*scene->addItem(paredes.back());
    puntos.push_back(new punto(34, 34, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(34, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(70, 34, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(106, 34, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(34, 106, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(34, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(34, 178, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(32, 212, 5));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(106, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(106, 106, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(106, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(142, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(178, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(214, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(214, 106, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(214, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(178, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(142, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(250, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(286, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(322, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(358, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(358, 34, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(394, 34, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(430, 32, 5));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(466, 34, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(502, 34, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(502, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(538, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(574, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(610, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(646, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(682, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(718, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(754, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(754, 34, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(790, 34, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(826, 34, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(826, 70, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(826, 106, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(826, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(826, 178, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(824, 212, 5));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(826, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(826, 322, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(826, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(790, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(754, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(718, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(682, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(646, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(610, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(574, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(538, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(502, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(466, 356, 5));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(394, 356, 5));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(358, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(322, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(286, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(250, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(214, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(178, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(142, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(106, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(70, 358, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(34, 322, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(34, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(34, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(754, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(718, 286, 3));//
    scene->addItem(puntos.back());
    puntos.push_back(new punto(682, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(646, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(610, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(574, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(538, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(502, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(466, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(394, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(358, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(322, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(286, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(250, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(214, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(178, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(142, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(106, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(70, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(790, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(430, 286, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(574, 322, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(286, 322, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(538, 250, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(538, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(574, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(610, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(646, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(682, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(718, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(718, 250, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(754, 212, 5));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(646, 178, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(646, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(646, 106, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(682, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(718, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(754, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(754, 106, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(538, 178, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(142, 250, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(574, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(574, 178, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(574, 106, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(502, 106, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(502, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(502, 178, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(466, 178, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(428, 176, 5));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(394, 178, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(358, 178, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(322, 178, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(286, 178, 3));//
    scene->addItem(puntos.back());
    puntos.push_back(new punto(286, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(286, 106, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(286, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(322, 250, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(322, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(358, 142, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(358, 106, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(250, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(214, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(214, 178, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(178, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(142, 214, 3));
    scene->addItem(puntos.back());
    puntos.push_back(new punto(106, 212, 5));
    scene->addItem(puntos.back());*/
    ui->lcdNumber->display(timeLeft);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    timer->start(1000); // Actualizar cada segundo
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_W)
    {
        if(!EvaluarColision())
            prota->MoverArriba();
        else
            prota->MoverAbajo();
        colPuntos();
    }
    else if(event->key()==Qt::Key_S)
    {
        if(!EvaluarColision())
            prota->MoverAbajo();
        else
            prota->MoverArriba();
        colPuntos();
    }
    else if(event->key()==Qt::Key_D)
    {
        if(!EvaluarColision())
            prota->MoverDer();
        else
            prota->MoverIzq();
        colPuntos();
    }
    else if(event->key()==Qt::Key_A)
    {   if(!EvaluarColision())
            prota->MoverIzq();
        else
            prota->MoverDer();
        colPuntos();
    }
}

bool MainWindow::EvaluarColision()
{
    for(int i=0; i<paredes.size(); i++)
    {

        if(paredes.at(i)->collidesWithItem(prota))
            return true;
    }
    return false;
}

void MainWindow::colPuntos()
{
    for (int i=punto.size()-1; i>=0; i--)
    {
        if (punto.at(i)->collidesWithItem(prota))
        {
            scene->removeItem(punto.at(i));
            delete punto.at(i);
            punto.erase(punto.begin() + i); // Eliminar el punto de la lista
            score++; // Incrementar marcador
            ui->lcdNumber->display(score); // Actualizar valor del LCD
        }
    }
}

void MainWindow::updateTimer()
{
    if(timeLeft > 0)
    {
        timeLeft--;
        ui->lcdNumber->display(timeLeft);
        if(timeLeft == 0)
        {
            timer->stop();
        }
    }
}

string MainWindow::resize(string row, char caracter) //recorta el tamaño del string, quitando el contenido existente hasta encontrar el caracter ingresado
{
    string fila="";
    int posicion=row.find(caracter);
    int tamano=row.size();
    for(int i=posicion+1; i<tamano; i++)
    {
        fila+=row[i];
    }
    return fila;
}

string MainWindow::grupito(string row, char caracter)
{
    string grupo="";
    int posicion=row.find(caracter);
    for(int i=0; i<posicion; i++)
    {
        grupo+=row[i];
    }
    return grupo;
}

