#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include<QLineEdit>
#include"mylabel.h"

class MyLineEdit : public QLineEdit
{
    Q_OBJECT

private:
    MyLabel * label;
    QString firstNumber;
    QString secondNumber;
    QString operatorSymbol;


public:
    MyLineEdit(MyLabel * myLabel = nullptr, QWidget *parent = nullptr);

public slots:
    void handleButtonClicked(const QString &buttonText);

};

#endif
