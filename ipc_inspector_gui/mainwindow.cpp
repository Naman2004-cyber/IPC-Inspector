#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "pipe_debugger.h"
#include "mq_debugger.h"
#include "shm_debugger.h"
#include "deadlock_detector.h"


#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pipeButton_clicked() {
    run_pipe_demo();
    loadLogs(ui->logTextEdit);
}

void MainWindow::on_mqButton_clicked() {
    run_mq_demo();
    loadLogs(ui->logTextEdit);
}

void MainWindow::on_shmButton_clicked() {
    run_shm_demo();
    loadLogs(ui->logTextEdit);
}

void MainWindow::on_deadlockButton_clicked() {
    simulate_deadlock();
    loadLogs(ui->logTextEdit);
}

void loadLogs(QTextEdit *textEdit) {
    std::ifstream file("../logs/ipc.log");
    std::string line;

    textEdit->clear();
    while (std::getline(file, line)) {
        textEdit->append(QString::fromStdString(line));
    }
}

