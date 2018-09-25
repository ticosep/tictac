#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // popula qlist com os vetores de resposta
    this->anwserVectors<<vl<<vc<<vr<<ht<<hc<<hb<<dl<<dr;

    this->connectAllButtons();
    this->init();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insertAnswerVector(QString value, QString btn){

    if(QString::compare(btn, "topLeft") == 0){
        anwserVectors[6] << value;
        anwserVectors[3] << value;
        anwserVectors[0] << value;
    } else if(QString::compare(btn, "centerLeft") == 0) {
        anwserVectors[0] << value;
        anwserVectors[4] << value;
    } else if(QString::compare(btn, "bottomLeft") == 0) {
        anwserVectors[0] << value;
        anwserVectors[5] << value;
        anwserVectors[7] << value;
    } else if(QString::compare(btn, "centerTop") == 0){
        anwserVectors[1] << value;
        anwserVectors[3] << value;
    } else if(QString::compare(btn, "center") == 0) {
        anwserVectors[1] << value;
        anwserVectors[4] << value;
        anwserVectors[6] << value;
        anwserVectors[7] << value;
    } else if(QString::compare(btn, "centerBottom") == 0) {
        anwserVectors[1] << value;
        anwserVectors[5] << value;
    }  if(QString::compare(btn, "topRight") == 0){
        anwserVectors[7] << value;
        anwserVectors[3] << value;
        anwserVectors[2] << value;
    } else if(QString::compare(btn, "centerRight") == 0) {
        anwserVectors[2] << value;
        anwserVectors[4] << value;
    } else if(QString::compare(btn, "bottomRight") == 0) {
        anwserVectors[2] << value;
        anwserVectors[5] << value;
        anwserVectors[6] << value;
    }
}



// checa se os valores nos vetores de respotas completos são corretos
void MainWindow::answerCheck()
{

    foreach(QStringList lst, anwserVectors){
       qDebug() << lst;
    }


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
               btn->setEnabled(true);
           }
     }

    // limpa valores da lista de respostas
    for(int i = 0; i < this->anwserVectors.size(); i++){
        QStringList* e = &anwserVectors[i];
        e->clear();
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

    // percore a lista de QPushButton e conecta o slot com btnClick, funcao lambda
    foreach(QPushButton*btn, list){
          QString btName = btn->objectName();
           if(strlen(btName.toLatin1().data()) > 2){
               connect (btn,&QPushButton::clicked,this,[=](){
                   btn->setText(this->turn);
                   btn->setEnabled(false);
                   this->insertAnswerVector(this->turn,btn->objectName());
                   this->answerCheck();
                   this->changeTurn();
               });
           }
     }
}
