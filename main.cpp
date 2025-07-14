#include<QApplication>
#include<QWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include<QGridLayout>
#include<QLineEdit>
#include<QLabel>
#include"mybutton.h"
#include"myLineEdit.h"
#include"myLabel.h"

int main(int argc, char * argv[])
{
    //initialize window classes.
    // set up for message dispatching (Event loop)
    // do other preparations which are required to set up a window in Win32 SDK

    QApplication calculator(argc,argv);

    calculator.setStyle("Fusion");

    //creates a blank top level window as no parent is specified

    QWidget mainWindow;
    mainWindow.resize(300,400);               // set window size
    mainWindow.setWindowTitle("Calculator");  // set window title

    // Create QIcon object which can be used with QWidgets
    // loads image into memory in QPixmap format

    QIcon appIcon(":/icons/Images/calculator.ico");

    mainWindow.setWindowIcon(appIcon);        // set window icon

    // add QLable to the window

    myLabel *pMiniDisplay = new myLabel();
    pMiniDisplay->setMinimumHeight(30);
    pMiniDisplay->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    pMiniDisplay->setStyleSheet("font-size: 16px; color: white; padding: 5px");
    pMiniDisplay->setText("0"); // Start with empty mini-display


    // Add QlineEdit in the window

    MyLineEdit *pMyLineEdit = new MyLineEdit(pMiniDisplay);
    pMyLineEdit->setMinimumHeight(70);
    pMyLineEdit->setAlignment(Qt::AlignRight);
    pMyLineEdit->setReadOnly(true);
    pMyLineEdit->setText("0");
    pMyLineEdit->setStyleSheet("font-size: 33px; padding: 5px");

    //add above Qlineedit to layout

    QVBoxLayout *mainVerticalLayout = new QVBoxLayout(&mainWindow);
    mainVerticalLayout->addWidget(pMiniDisplay,0,Qt::AlignTop);
    mainVerticalLayout->addWidget(pMyLineEdit,0,Qt::AlignVCenter);

    QString buttonTitleArray[16] = {

                                    "7","8","9","/",

                                    "4","5","6","x",

                                    "1","2","3","-",

                                    "0","C","=","+"

                                    };

    MyButton *calculatorPushButtonsArray[16];

    //define layout for calculator push buttons

    QGridLayout *buttonGridLayout = new QGridLayout();

    // initialize 16 QPushButtons, add them to the button grid layout

    int i = 0;

    for (int rowNumber = 0; rowNumber < 4; rowNumber++)
    {
        for(int columnNumber = 0; columnNumber < 4; columnNumber++)
        {
            calculatorPushButtonsArray[i] = new MyButton(buttonTitleArray[i]);
            calculatorPushButtonsArray[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            buttonGridLayout->addWidget(calculatorPushButtonsArray[i],rowNumber, columnNumber);


            // connect custome button signal to QLineEdit Slot
            QObject::connect(calculatorPushButtonsArray[i], SIGNAL(ButtonClicked(const QString &)),
                             pMyLineEdit, SLOT(handleButtonClicked(const QString &)));


            // connect custome button signal to myLabel

            //QObject::connect(calculatorPushButtonsArray[i],SIGNAL(ButtonClicked(const QString &)),pMiniDisplay,SLOT(appendText(const QString &)));

            i++;


        }
    }

    mainVerticalLayout->addLayout(buttonGridLayout,1);

    mainWindow.show();                        //  show the window

    return calculator.exec();                 // start event loop (heart of the application)
}
