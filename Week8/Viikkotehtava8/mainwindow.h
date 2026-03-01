#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void clockTimeout();
private:
    Ui::MainWindow *ui;
    short player1Time=0;
    short player2Time=0;
    short currentPlayer=0; //This will double as a game state variant.
    short gameTime=0;
    QTimer *pQTimer;
private slots:
    void updateProgressBar();
    void setGameInfoText(QString,short);
    void playerButtonHandler();
    void commonButtonHandler();
};
#endif // MAINWINDOW_H
