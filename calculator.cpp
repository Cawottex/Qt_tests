#include "calculator.h"

void    Calculator::initOperationButtons()
{
    operations[0] = new QPushButton("+");
    operations[0]->setFixedSize(50, 50);
    operations[0]->setStyleSheet("background: #B0C4DE");
    operations[1] = new QPushButton("-");
    operations[1]->setFixedSize(50, 50);
    operations[1]->setStyleSheet("background: #B0C4DE");
    operations[2] = new QPushButton("*");
    operations[2]->setFixedSize(50, 50);
    operations[2]->setStyleSheet("background: #B0C4DE");
    operations[3] = new QPushButton("/");
    operations[3]->setFixedSize(50, 50);
    operations[3]->setStyleSheet("background: #B0C4DE");
    operations[4] = new QPushButton("=");
    operations[4]->setFixedSize(50, 50);
    operations[4]->setStyleSheet("background: #1E90FF");
    operations[5] = new QPushButton("<-");
    operations[5]->setFixedSize(50, 50);
    operations[5]->setStyleSheet("background: #B0C4DE");
}

void    Calculator::initWidgets()
{
    principalLayout = new QVBoxLayout;
    resultLine = new QLineEdit;
    gridButtons = new QGridLayout;
    result = 0;
    int i = 0;
    curOpe = 'o';
    while (i < 10)
    {
        numbers[i] = new QPushButton(QString::number(i));
        numbers[i]->setMinimumSize(50, 50);
        //numbers[i]->setFixedSize(50, 50);
        i++;
    }
    initOperationButtons();
}

void    Calculator::setWidgets()
{
    gridButtons->addWidget(numbers[7], 0, 0);
    gridButtons->addWidget(numbers[8], 0, 1);
    gridButtons->addWidget(numbers[9], 0, 2);
    gridButtons->addWidget(numbers[4], 1, 0);
    gridButtons->addWidget(numbers[5], 1, 1);
    gridButtons->addWidget(numbers[6], 1, 2);
    gridButtons->addWidget(numbers[1], 2, 0);
    gridButtons->addWidget(numbers[2], 2, 1);
    gridButtons->addWidget(numbers[3], 2, 2);
    gridButtons->addWidget(numbers[0], 3, 0, 1, 2);
    gridButtons->addWidget(operations[0], 1, 3);
    gridButtons->addWidget(operations[1], 2, 3);
    gridButtons->addWidget(operations[2], 3, 3);
    gridButtons->addWidget(operations[3], 4, 3);
    gridButtons->addWidget(operations[4], 3, 2);
    gridButtons->addWidget(operations[5], 0, 3);
}

void    Calculator::clickNumbers()
{
    connect(numbers[0], SIGNAL(clicked()), this, SLOT(addZero()));
    connect(numbers[1], SIGNAL(clicked()), this, SLOT(addOne()));
    connect(numbers[2], SIGNAL(clicked()), this, SLOT(addTwo()));
    connect(numbers[3], SIGNAL(clicked()), this, SLOT(addThree()));
    connect(numbers[4], SIGNAL(clicked()), this, SLOT(addFour()));
    connect(numbers[5], SIGNAL(clicked()), this, SLOT(addFive()));
    connect(numbers[6], SIGNAL(clicked()), this, SLOT(addSix()));
    connect(numbers[7], SIGNAL(clicked()), this, SLOT(addSeven()));
    connect(numbers[8], SIGNAL(clicked()), this, SLOT(addEight()));
    connect(numbers[9], SIGNAL(clicked()), this, SLOT(addNine()));
    connect(operations[0], SIGNAL(clicked()), this, SLOT(sumNumber()));
    connect(operations[1], SIGNAL(clicked()), this, SLOT(subNumber()));
    connect(operations[2], SIGNAL(clicked()), this, SLOT(multNumber()));
    connect(operations[3], SIGNAL(clicked()), this, SLOT(divNumber()));
    connect(operations[4], SIGNAL(clicked()), this, SLOT(affResult()));
    connect(operations[5], SIGNAL(clicked()), this, SLOT(eraseLast()));
}

Calculator::Calculator() : QMainWindow()
{
    QWidget *centralZone = new QWidget;

    setFixedSize(240, 300);
    initWidgets();
    setWidgets();
    resultLine->setReadOnly(true);
    principalLayout->addWidget(resultLine);
    principalLayout->addLayout(gridButtons);
    centralZone->setLayout(principalLayout);
    setCentralWidget(centralZone);
    clickNumbers();
}
