#include "mylineedit.h"
#include "mylabel.h"
#include <iostream>

bool divideByZeroError = false;
bool waitingForSecondNumber;
bool resultIsShown;
bool chainingExpressionAfterResult ;

MyLineEdit::MyLineEdit(MyLabel * myLebel, QWidget *parent) : QLineEdit(parent)
{
    label = myLebel;
}

void MyLineEdit::handleButtonClicked(const QString &buttonText)
{


    //if C is pressed set display to 0 again and return

    if(buttonText == "C")
    {
        this->setText("0");
        label->setText("0");
        divideByZeroError = false;
        return;
    }

    QString currentDisplayedText = this->text();

    // below if else is written to handle the case when initial 0 is present in QLineEdit and we need to reset that 0 and start with new number

    if( divideByZeroError == false && (buttonText == "0" || buttonText == "1" || buttonText == "2" || buttonText == "3" || buttonText == "4" || buttonText == "5" || buttonText == "6" || buttonText == "7" || buttonText == "8" || buttonText == "9"))
    {
        if(currentDisplayedText == "0" || waitingForSecondNumber || resultIsShown)
        {
            this->setText(buttonText);

            waitingForSecondNumber = false;

            if(resultIsShown == true)
            {
                resultIsShown = false;
                label->setText("0");
            }
            else if(chainingExpressionAfterResult)
            {
                // continuing from result
                chainingExpressionAfterResult = false;
                // don't clear label
            }


        }
        else
        {
            std::cout << "Inside MyLineEdit slot: handleButtonClicked else part" << std::endl;
            this->insert(buttonText);
        }
    }

    if(divideByZeroError == false && (buttonText == "+" || buttonText == "-" || buttonText == "x" || buttonText == "/"))
    {
        std::cout<<"Inside operator pressed if check"<<std::endl;
        firstOperator = currentDisplayedText;
        operatorSymbol = buttonText;

        if(resultIsShown)
        {
            resultIsShown = false;
            chainingExpressionAfterResult  = true;
        }

        label->setText(firstOperator + " " + operatorSymbol + " ");
        waitingForSecondNumber = true;


    }

    if(divideByZeroError == false && buttonText == "=")
    {
        secondOperator = this->text();

        double num1 = firstOperator.toDouble();
        double num2 = secondOperator.toDouble();
        double result = 0;

        if(operatorSymbol == "+")
        {
            result = num1 + num2;
        }
        else if(operatorSymbol == "-")
        {
            result = num1 - num2;
        }
        else if(operatorSymbol == "x")
        {
            result = num1 * num2;
        }
        else
        {
            if(num2 == 0)
            {
                this->setText("Error");
                label->setText("Cannot divide by 0");
                divideByZeroError = true;
                return;
            }
            result = num1/num2;
        }

        QString resultToString = QString::number(result);

        this->setText(resultToString);
        label->setText(firstOperator + " " + operatorSymbol + " " + secondOperator + " " + "=");
        resultIsShown = true;

    }

}
