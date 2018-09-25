#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

private:
    QString turn;

    // matriz que aloca as respostas
    QString answerMatrix[3][3];

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void answerCheck();
    void connectAllButtons();
    void changeTurn();
    void insertAnswerMatrix(QString value, QString btn);
    void endGame(QString value);



public slots:
    void init();

private:
    Ui::MainWindow *ui;
    void linkLists();


};

#endif // MAINWINDOW_H
