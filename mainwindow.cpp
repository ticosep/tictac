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

// muda string do turno e trava outros botoes caso fim do jogo foi alcanlçado
void MainWindow::endGame(QString value){

    if(QString::compare(value, "draw") == 0){

        //muda letreiro para empate
        ui->turn->setText(QString("******DRAW******"));
        QList<QPushButton*> list = this->findChildren<QPushButton *>();

        // percore a lista de QPushButton e trava btn
        foreach(QPushButton*btn, list){
              QString btName = btn->objectName();
               if(strlen(btName.toLatin1().data()) > 2){
                  btn->setEnabled(false);
               }
         }

    }else {

    }
}

void MainWindow::insertAnswerMatrix(QString value, QString btn){
    // converte os caracteres da posição presentes nos botoes
    char iChar = btn.at(3).toLatin1();
    char jChar = btn.at(4).toLatin1();

    int i = iChar - '0';
    int j = jChar - '0';

    // adiona o valor da vez na posição correta da matriz
    this->answerMatrix[i][j] = value;

}



void MainWindow::answerCheck()
{

    // checa se existe resposta nas diagonais
    QString a = this->answerMatrix[0][0];
    QString b = this->answerMatrix[1][1];
    QString c = this->answerMatrix[2][2];

    if(QString::compare(a,b) == 0 && QString::compare(b,c) == 0){
        qDebug() << "horizontal win";
    }

    a = this->answerMatrix[0][2];
    b = this->answerMatrix[1][1];
    c = this->answerMatrix[2][0];

    if(QString::compare(a,b) == 0 && QString::compare(b,c) == 0){
        qDebug() << "horizontal win";
    }

    for(int i = 0; i < 3; i++){
        // checa se existe resposta correta nas verticais
        a = this->answerMatrix[0][i];
        b = this->answerMatrix[1][i];
        c = this->answerMatrix[2][i];

        if(QString::compare(a,b) == 0 && QString::compare(b,c) == 0){
            qDebug() << "vertical win";
        }

        // checa se existe resposta correta nas horizontais
        a = this->answerMatrix[i][0];
        b = this->answerMatrix[i][1];
        c = this->answerMatrix[i][2];

        if(QString::compare(a,b) == 0 && QString::compare(b,c) == 0){
            qDebug() << "horizontal win";
        }

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

    // limpa valores da matriz de respostas e coloca numero que todos os slots se diferencie
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::string a = std::to_string(i) + std::to_string(j);
            QString diffAnswer = QString::fromUtf8(a.c_str());

            this->answerMatrix[i][j].clear();
            this->answerMatrix[i][j] = diffAnswer;

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

    // percore a lista de QPushButton e conecta o slot com btnClick, funcao lambda
    foreach(QPushButton*btn, list){
          QString btName = btn->objectName();
           if(strlen(btName.toLatin1().data()) > 2){
               connect (btn,&QPushButton::clicked,this,[=](){
                   btn->setText(this->turn);
                   btn->setEnabled(false);
                   this->insertAnswerMatrix(this->turn,btn->objectName());
                   this->answerCheck();
                   this->changeTurn();
               });
           }
     }
}
