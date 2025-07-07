#include<iostream>
#include "mybutton.h"

MyButton::MyButton(QString &buttonLabel, QWidget *parent) : QPushButton(buttonLabel,parent)
{
    std::cout<<"inside MyButton constructor"<<std::endl;
    connect(this, &QPushButton::clicked,this,&MyButton::handleClick);
}

void MyButton::handleClick()
{
    std::cout<<"inside handle clicked function"<<std::endl;
    emit ButtonClicked(this->text());
}
