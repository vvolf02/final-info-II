#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mc.h>
#include <enemy.h>
#include <punto.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <pared.h>
#include <QList>
#include <string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent( QKeyEvent *event);
    bool EvaluarColision();
    void colPuntos();
    int score;
    string resize(string row, char caracter);
    string grupito(string row, char caracter);

private slots:

private:
    Ui::MainWindow *ui;
    mc *ball;
    enemy *ghost;
    QGraphicsScene *scene;
    QKeyEvent *event;
    QList<pared *> paredes;
    QList<punto *> puntos;

};
#endif // MAINWINDOW_H
