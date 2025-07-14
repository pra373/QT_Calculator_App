#include "myLabel.h"

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{

}

void myLabel::appendText(const QString &buttonText)
{
    this->setText(this->text() + buttonText);
}
