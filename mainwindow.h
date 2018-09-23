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

    // vetores de pointeros para as respostas
    QStringList *vlp, *vcp, *vrp, *htp, *hcp, *hbp, *dlp, *drp;
    QList<QStringList * > anwserVectorsPointer;

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void answerCheck();
    void connectAllButtons();
    void changeTurn();
    void insertAnswerVector(QString value, QString btn);
    bool checkAnswerVector(QStringList v);


public slots:
    void init();

private:
    Ui::MainWindow *ui;
    void linkLists();


};

#endif // MAINWINDOW_H
