#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtGui/QApplication>
#include <QMainWindow>
#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QDebug>

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator();

public slots:
    void    addZero();
    void    addOne();
    void    addTwo();
    void    addThree();
    void    addFour();
    void    addFive();
    void    addSix();
    void    addSeven();
    void    addEight();
    void    addNine();
    void    sumNumber();
    void    subNumber();
    void    multNumber();
    void    divNumber();
    void    affResult();
    void    eraseLast();

private:
    QVBoxLayout *principalLayout;
    QLineEdit   *resultLine;
    QGridLayout *gridButtons;
    QPushButton *numbers[10];
    QPushButton *operations[6];
    QString     tmpNbr;
    char        curOpe;
    int         result;

    void    initWidgets();
    void    initOperationButtons();
    void    setWidgets();
    void    clickNumbers();
    void    doOpe();

};

#endif // CALCULATOR_H
