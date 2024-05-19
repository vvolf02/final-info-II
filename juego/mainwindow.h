#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mc.h>
#include <puntos.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <pared.h>
#include <QList>
#include <string>
#include <QTimer>

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

private slots:

private:
    Ui::MainWindow *ui;
    mc *prota;
    QGraphicsScene *scene;
    QKeyEvent *event;
    QList<pared *> paredes;
    QList<puntos *> punto;
    bool EvaluarColision();
    void colPuntos();
    QTimer *timer;
    int timeLeft;
    int score;
    string resize(string row, char caracter);
    string grupito(string row, char caracter);
    void updateTimer();
};
#endif // MAINWINDOW_H
