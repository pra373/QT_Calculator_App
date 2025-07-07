#ifndef MYBUTTON_H
#define MYBUTTON_H

#include<QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT

public:
    MyButton(QString &buttonLabel, QWidget *parent = nullptr);

signals:
    void ButtonClicked(const QString &buttonText);

private slots:
    void handleClick();

};


#endif // MYBUTTON_H
