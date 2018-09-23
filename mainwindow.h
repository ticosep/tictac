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

    // vetores que alocam as respostas
    QStringList vl, vc, vr, ht, hc, hb, dl, dr;
    QList<QStringList> anwserVectors;

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void init();

public:
    void answerCheck();
    void connectAllButtons();
    void changeTurn();
    void insertAnswerVector(QString value, QString btn);
    bool checkAnswerVector(QStringList v);

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
