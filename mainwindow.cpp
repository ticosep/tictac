#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connectAllButtons();
    this->init();

}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::answerCheck()
{
    double *v;
    v = new double[3];
    return true;
}

// troca o turno do jogador
void MainWindow::changeTurn()
{
    if(QString::compare(this->turn, "X") == 0){
        this->turn = "O";
    } else {
        this->turn = "X";
    }

    ui->turn->setText(QString("Turn : %1").arg(this->turn));
}
// metodo que inicia o jogo, ie, zera todos os botoes e seta turno inicial p X
void MainWindow::init()
{
    this->turn = "X";
    ui->turn->setText(QString("Turn : %1").arg(this->turn));

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

void MainWindow::connectAllButtons()
{
    // conecta new game button
    connect(ui->nw, &QPushButton::clicked,this, &MainWindow::init);

    // conecta quit button
    connect(ui->qt, &QPushButton::clicked,this, &MainWindow::close);

    // cria lista com todos os QWidget presentes no jogo
    QList<QPushButton*> list = this->findChildren<QPushButton *>();

    // percore a lista de QPushButton e conecta o slot com btnClick
    foreach(QPushButton*btn, list){
          QString btName = btn->objectName();
           if(strlen(btName.toLatin1().data()) > 2){
               connect (btn,&QPushButton::clicked,this,[=](){
                   btn->setText(this->turn);
                   this->changeTurn();
               });
           }
     }
}
