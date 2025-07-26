#include "mylineedit.h"
#include "mylabel.h"
#include <iostream>
#define maxDigitLimit 14

bool divideByZeroError = false;
bool waitingForSecondNumber;
bool resultIsShown;
bool chainingExpressionAfterResult ;
bool isFirstNumberConversionValid;
bool isSecondNumberConversionValid;
short countOfDigits = 0;

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


        if(countOfDigits < maxDigitLimit)
        {
            if(currentDisplayedText == "0" || waitingForSecondNumber || resultIsShown)
            {
                this->setText(buttonText);
                countOfDigits = 1;

                waitingForSecondNumber = false;

                if(resultIsShown == true)
                {
                    resultIsShown = false;
                    label->setText("0");
                }
                else if(chainingExpressionAfterResult)
                {
                    chainingExpressionAfterResult = false;
                }


            }
            else
            {
                std::cout << "Inside MyLineEdit slot: handleButtonClicked else part" << std::endl;
                this->insert(buttonText);
                countOfDigits++;
                std::cout<<countOfDigits<<std::endl;
            }
        }

    }

    if(divideByZeroError == false && (buttonText == "+" || buttonText == "-" || buttonText == "x" || buttonText == "/"))
    {
        std::cout<<"Inside operator pressed if check"<<std::endl;
        firstNumber = currentDisplayedText;
        operatorSymbol = buttonText;

        if(resultIsShown)
        {
            resultIsShown = false;
            chainingExpressionAfterResult  = true;
        }

        label->setText(firstNumber + " " + operatorSymbol + " ");
        waitingForSecondNumber = true;
        countOfDigits = 0;



    }

    if(divideByZeroError == false && buttonText == "=")
    {
        secondNumber = this->text();

        double num1 = firstNumber.toDouble(&isFirstNumberConversionValid);
        double num2 = secondNumber.toDouble(&isSecondNumberConversionValid);
        double result = 0;

        if(!isFirstNumberConversionValid || !isSecondNumberConversionValid)
        {
            this->setText("Number out of bound error");
            label->setText("Error");
            return;
        }

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
        label->setText(firstNumber + " " + operatorSymbol + " " + secondNumber + " " + "=");
        resultIsShown = true;

    }

}
