#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pQTimer=new QTimer();
    pQTimer->setTimerType(Qt::PreciseTimer); //Very accurate timer, consumes more resources.
    connect(pQTimer,SIGNAL(timeout()),this,SLOT(clockTimeout()));
    ui->p1Bar->setValue(0); //Why the fuck is the default 24, lmao
    ui->p2Bar->setValue(0);
    //Player buttons
    connect(ui->p1Switch,&QPushButton::clicked,this,&MainWindow::playerButtonHandler);
    connect(ui->p2Switch,&QPushButton::clicked,this,&MainWindow::playerButtonHandler);
    //Common buttons
    connect(ui->longGame,&QPushButton::clicked,this,&MainWindow::commonButtonHandler);
    connect(ui->shortGame,&QPushButton::clicked,this,&MainWindow::commonButtonHandler);
    connect(ui->stopButton,&QPushButton::clicked,this,&MainWindow::commonButtonHandler);
    connect(ui->startButton,&QPushButton::clicked,this,&MainWindow::commonButtonHandler);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete pQTimer;
}

void MainWindow::clockTimeout()
{
    if(currentPlayer==1){
        player1Time--;
    }else{
        player2Time--;
    }
    updateProgressBar();
}

void MainWindow::updateProgressBar()
{
    ui->p1Bar->setValue(int((float(player1Time)/float(gameTime))*100));
    ui->p2Bar->setValue(int((float(player2Time)/float(gameTime))*100));
    if(player1Time==0){
        pQTimer->stop();
        currentPlayer=0;
        gameTime=0;
        player1Time=gameTime;
        player2Time=gameTime;
        setGameInfoText("Player 2 won by timeout! Select new game length and press: Start Game",11);
    }else if(player2Time==0){
        pQTimer->stop();
        currentPlayer=0;
        gameTime=0;
        player1Time=gameTime;
        player2Time=gameTime;
        setGameInfoText("Player 1 won by timeout! Select new game length and press: Start Game",11);
    }
}

void MainWindow::setGameInfoText(QString teksti, short fontKoko)
{
    ui->label->setText(teksti);
    QFont fontti=ui->label->font(); //We don't actually change the font size, because I don't want to. This is completely useless.
    fontti.setPointSize(fontKoko);
}

void MainWindow::playerButtonHandler()
{
    QPushButton* button=qobject_cast<QPushButton*>(sender());
    if(player1Time!=0&&player2Time!=0){
        if(button->objectName()=="p1Switch"&&currentPlayer==1){
            currentPlayer=2;
            setGameInfoText("Player 2 turn.",11);
        }else if(button->objectName()=="p2Switch"&&currentPlayer==2){
            currentPlayer=1;
            setGameInfoText("Player 1 turn.",11);
        }
    }
}

void MainWindow::commonButtonHandler()
{
    QPushButton* button=qobject_cast<QPushButton*>(sender());
    if(button->objectName()=="stopButton"&&currentPlayer!=0){//Stop can't be pressed if the game is not running.
        pQTimer->stop();
        currentPlayer=0;
        gameTime=0;
        player1Time=gameTime;
        player2Time=gameTime;
        ui->p1Bar->setValue(0);
        ui->p2Bar->setValue(0);
        setGameInfoText("Game Stopped. Select new game length and press: Start Game",11);
    }else if((button->objectName()=="startButton"&&gameTime!=0)&&currentPlayer==0){//gameTime!=0 makes sure we have selected a game length.
        player1Time=gameTime;
        player2Time=gameTime;
        currentPlayer=1;
        setGameInfoText("Game Started. Player 1 turn.",11);
        pQTimer->start(1000);
        //If we wanted a competetive quality chess clock, we would put qtimer in its own time critical thread here, but since that isn't specified in the exercise instructions, we won't do that.
        //For the record, here's how it would be done:
        //in header: QThread *pQThread;
        //in MainWindow(): pQThread = new QThread;
        //in here (after pQTimer->start):
        // pQTimer->moveToThread(pQThread);
        // pQThread->start(QThread::Priority::TimeCriticalPriority);
        //BUT, to do this we would need to create custom signals and slots for the thread, count milliseconds and define the counters as something other than short.
    }else if(button->objectName()=="longGame"&&currentPlayer==0){//currentPlayer==0 means the game is not running.
        gameTime=300;
        ui->p1Bar->setValue(100);
        ui->p2Bar->setValue(100);
        setGameInfoText("Selected 5 minute game. Press start.",11);
    }else if(button->objectName()=="shortGame"&&currentPlayer==0){
        gameTime=120;
        ui->p1Bar->setValue(100);
        ui->p2Bar->setValue(100);
        setGameInfoText("Selected 2 minute game. Press start.",11);
    }
}
