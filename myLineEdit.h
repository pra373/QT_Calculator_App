#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include<QLineEdit>
#include"mylabel.h"

class MyLineEdit : public QLineEdit
{
    Q_OBJECT

private:
    myLabel * label;
    QString firstOperator;
    QString secondOperator;
    QString operatorSymbol;
    bool waitingForSecondNumber;

public:
    MyLineEdit(myLabel * myLabel = nullptr, QWidget *parent = nullptr);

public slots:
    void handleButtonClicked(const QString &buttonText);

};

#endif
