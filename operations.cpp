#include "calculator.h"

void    Calculator::doOpe()
{
    char    tmpOpe = curOpe;

    curOpe = 'o';
    if (tmpOpe == '+')
        sumNumber();
    else if (tmpOpe == '-')
        subNumber();
    else if (tmpOpe == '*')
        multNumber();
    else if (tmpOpe == '/')
        divNumber();
}

void    Calculator::sumNumber()
{
    if (curOpe != 'o')
        doOpe();
    else if (tmpNbr != "" && result == 0)
    {
        result = tmpNbr.toInt();
        tmpNbr = "";
    }
    else if (tmpNbr != "" && result != 0)
    {
        result += tmpNbr.toInt();
        resultLine->setText(QString::number(result));
        tmpNbr = "";
    }
    curOpe = '+';
}

void    Calculator::subNumber()
{
    if (curOpe != 'o')
        doOpe();
    else if (tmpNbr != "" && result == 0)
    {
        result = tmpNbr.toInt();
        tmpNbr = "";
    }
    else if (tmpNbr != "" && result != 0)
    {
        result -= tmpNbr.toInt();
        resultLine->setText(QString::number(result));
        tmpNbr = "";
    }
    curOpe = '-';
}

void    Calculator::multNumber()
{
    if (curOpe != 'o')
        doOpe();
    else if (tmpNbr != "" && result == 0)
    {
        result = tmpNbr.toInt();
        tmpNbr = "";
    }
    else if (tmpNbr != "" && result != 0)
    {
        result *= tmpNbr.toInt();
        resultLine->setText(QString::number(result));
        tmpNbr = "";
    }
    curOpe = '*';
}

void    Calculator::divNumber()
{
    if (curOpe != 'o')
        doOpe();
    else if (tmpNbr != "" && result == 0)
    {
        result = tmpNbr.toInt();
        tmpNbr = "";
    }
    else if (tmpNbr != "" && result != 0)
    {
        if (tmpNbr.toInt() != 0)
        {
            result /= tmpNbr.toInt();
            resultLine->setText(QString::number(result));
        }
        else
        {
            result = 0;
            resultLine->setText("Division par zero impossible !");
        }
        tmpNbr = "";
    }
    curOpe = '/';
}

void    Calculator::affResult()
{
    int divperzero;

    divperzero = 0;
    if (curOpe == '+')
        result += tmpNbr.toInt();
    if (curOpe == '-')
        result -= tmpNbr.toInt();
    if (curOpe == '*')
        result *= tmpNbr.toInt();
    if (curOpe == '/')
        if (tmpNbr.toInt() != 0)
            result /= tmpNbr.toInt();
        else
            divperzero = 1;
    if (divperzero == 1)
    {
        resultLine->setText("Division par zero impossible !");
        result = 0;
    }
    else
        resultLine->setText(QString::number(result));
    tmpNbr = "";
    curOpe = 'o';
}

void    Calculator::eraseLast()
{
    if (tmpNbr == "")
        result = 0;
    tmpNbr.remove(tmpNbr.size()-1, 1);
    resultLine->setText(tmpNbr);
}
