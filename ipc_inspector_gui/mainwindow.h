#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pipeButton_clicked();
    void on_mqButton_clicked();
    void on_shmButton_clicked();
    void on_deadlockButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif
