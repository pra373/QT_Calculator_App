#include "mylineedit.h"
#include <iostream>

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent)
{
}

void MyLineEdit::handleButtonClicked(const QString &buttonText)
{


    //if C is pressed set display to 0 again and return

    if(buttonText == "C")
    {
        this->setText("0");
        return;
    }

    QString currentDisplayedText = this->text();


    if(currentDisplayedText == "0")
    {
        this->setText(buttonText);
    }
    else
    {
        std::cout << "Inside MyLineEdit slot: handleButtonClicked" << std::endl;
        this->insert(buttonText);
    }






}
