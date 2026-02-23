#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Nappi,&QPushButton::clicked,this,&MainWindow::handleClick);
    //connect(ui->)
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleClick()
{
    ui->Naytto->setText("Toimii");
    qDebug()<<"Nappia painettu";
}

void MainWindow::buttonClick()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    qDebug()<<"Painike:"<<button->text();
}

void MainWindow::handleNapit(QPushButton *)
{

}
