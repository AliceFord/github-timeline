#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QLabel* label = new QLabel("Test");
    this->setCentralWidget(label);
    this->setGeometry(100, 100, 500, 500);
}

MainWindow::~MainWindow()
{
}

