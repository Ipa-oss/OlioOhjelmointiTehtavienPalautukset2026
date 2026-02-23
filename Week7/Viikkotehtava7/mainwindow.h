#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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
private slots:
    void countHandler();
    void resetHandler();
    void numberClickedHandler();
    void clearAndEnterClickHandler();
    void addSubMulDivCLickHandler();
    void resetLineEdits();
private:
    Ui::MainWindow *ui;
    int num=0;
    QString number1,number2;
    int state=1; //Need to init as 1, otherwise the number switch doesn't work.
    float result;
    short operand;
};
#endif // MAINWINDOW_H
