#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnClick()
{


    repaint();
}

bool MainWindow::answerCheck()
{
    double *v;
    v = new double[3];
    return true;
}

// metodo que inicia o jogo, ie, zera todos os botoes e seta turno inicial p X
void MainWindow::init()
{
    ui->turn->setText(QString("Turn : X"));

    // cria lista com todos os QWidget presentes no jogo
    QList<QPushButton*> list = this->findChildren<QPushButton *>();

    // percore a lista de QPushButton e zera os botoes
    foreach(QPushButton*btn, list){
          QString btName = btn->objectName();
           if(strlen(btName.toLatin1().data()) > 2){
               btn->setText("");
           }
     }
}
