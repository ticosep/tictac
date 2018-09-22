#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

private:
   QString turn;

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void init();

public:
    bool answerCheck();

public:
    void connectAllButtons();

public:
    void changeTurn();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
