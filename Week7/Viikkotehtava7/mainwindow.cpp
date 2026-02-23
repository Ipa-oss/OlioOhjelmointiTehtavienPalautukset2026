#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->count,&QPushButton::clicked,this,&MainWindow::countHandler);
    connect(ui->reset,&QPushButton::clicked,this,&MainWindow::resetHandler);
    //Numbers
    connect(ui->B0,&QPushButton::clicked,this,&MainWindow::numberClickedHandler); //Have to do it this way since we create the buttons in mainwindow.ui and not here.
    connect(ui->B1,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B2,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B3,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B4,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B5,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B6,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B7,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B8,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->B9,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    //Clear and equals
    connect(ui->clear,&QPushButton::clicked,this,&MainWindow::clearAndEnterClickHandler);
    connect(ui->equals,&QPushButton::clicked,this,&MainWindow::clearAndEnterClickHandler);
    //Operands
    connect(ui->add,&QPushButton::clicked,this,&MainWindow::addSubMulDivCLickHandler);
    connect(ui->subtract,&QPushButton::clicked,this,&MainWindow::addSubMulDivCLickHandler);
    connect(ui->product,&QPushButton::clicked,this,&MainWindow::addSubMulDivCLickHandler);
    connect(ui->divide,&QPushButton::clicked,this,&MainWindow::addSubMulDivCLickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::countHandler()
{
    num++;
    ui->counterWindow->setText(QString::number(num));
}

void MainWindow::resetHandler()
{
    ui->counterWindow->setText("0");
    num=0;
}

void MainWindow::numberClickedHandler()
{
    QPushButton *button=qobject_cast<QPushButton*>(sender());
    switch(state){
        case 1:
            number1.append(button->text());
            ui->num1->setText(number1);
            break;
        case 2:
            number2.append(button->text());
            ui->num2->setText(number2);
            break;
        case 3: //Allows handling number inputs if equals has been pressed, but clear hasn't been.
            resetLineEdits();
            number1.append(button->text());
            ui->num1->setText(number1);
            state=1;
            break;
        default: //Unnecessary, but good to have.
            break;
    }
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton *button=qobject_cast<QPushButton*>(sender());
    if(button->objectName()=="clear"){
        resetLineEdits();
        state=1;
    }else{
        switch(operand){
            case 0:
                result=number1.toFloat()+number2.toFloat();
                break;
            case 1:
                result=number1.toFloat()-number2.toFloat();
                break;
            case 2:
                result=number1.toFloat()*number2.toFloat();
                break;
            case 3:
                result=number1.toFloat()/number2.toFloat();
                break;
            default:
                break;
        }
        QString sResult = QString::number(result);
        ui->result->setText(sResult);
        state=3;
    }
}

void MainWindow::addSubMulDivCLickHandler() //The way this is setup allows for operand changing mid operation. It would be useful to show the current operand to the user, but we don't.
{
    QPushButton *button=qobject_cast<QPushButton*>(sender());
    if(button->text()=="+"){ //This is ugly, but we have to do it like this
        operand=0;
    }else if(button->text()=="-"){
        operand=1;
    }else if(button->text()=="*"){
        operand=2;
    }else{
        operand=3;
    }
    state=2;
}

void MainWindow::resetLineEdits()
{
    ui->num1->setText("");
    number1.clear();
    ui->num2->setText("");
    number2.clear();
    ui->result->setText("");
}
