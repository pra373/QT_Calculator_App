#include<QApplication>
#include<QWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include<QGridLayout>
#include<QLineEdit>

int main(int argc, char * argv[])
{
    //initialize window classes.
    // set up for message dispatching (Event loop)
    // do other preparations which are required to set up a window in Win32 SDK

    QApplication calculator(argc,argv);

    //creates a blank top level window as no parent is specified

    QWidget mainWindow;
    mainWindow.resize(300,400);               // set window size
    mainWindow.setWindowTitle("Calculator");  // set window title

    // Create QIcon object which can be used with QWidgets
    // loads image into memory in QPixmap format

    QIcon appIcon(":/icons/Images/calculator.ico");

    mainWindow.setWindowIcon(appIcon);        // set window icon



    // Add QlineEdit in the window

    QLineEdit *pQLineEdit = new QLineEdit();
    pQLineEdit->setMinimumHeight(70);
    pQLineEdit->setAlignment(Qt::AlignRight);
    pQLineEdit->setReadOnly(true);
    pQLineEdit->setText("0");
    pQLineEdit->setStyleSheet("font-size: 33px; padding: 5px");

    //add above Qlineedit to layout

    QVBoxLayout *layoutForQLineEdit = new QVBoxLayout(&mainWindow);



    // define push buttons

    QPushButton *buttonForNumber1 = new QPushButton("1");
    QPushButton *buttonForNumber2 = new QPushButton("2");
    QPushButton *buttonForNumber3 = new QPushButton("3");
    QPushButton *buttonForNumber4 = new QPushButton("4");
    QPushButton *buttonForNumber5 = new QPushButton("5");
    QPushButton *buttonForNumber6 = new QPushButton("6");
    QPushButton *buttonForNumber7 = new QPushButton("7");
    QPushButton *buttonForNumber8 = new QPushButton("8");
    QPushButton *buttonForNumber9 = new QPushButton("9");
    QPushButton *buttonForNumber0 = new QPushButton("0");
    QPushButton *buttonForLetterC = new QPushButton("C");
    QPushButton *buttonForEqualitySymbol = new QPushButton("=");
    QPushButton *buttonForAdditionSymbol = new QPushButton("+");
    QPushButton *buttonForSubstractionSymbol = new QPushButton("-");
    QPushButton *buttonForMultiplicationSymbol = new QPushButton("x");
    QPushButton *buttonForDivisionSymbol = new QPushButton("/");

    // add push buttons to QGridLayout

    QGridLayout *buttonGridLayout = new QGridLayout();

    // row 3

    buttonGridLayout->addWidget(buttonForNumber0,3,0);
    buttonForNumber0->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonGridLayout->addWidget(buttonForLetterC,3,1);
    buttonForLetterC->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonGridLayout->addWidget(buttonForEqualitySymbol,3,2);
    buttonForEqualitySymbol->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonGridLayout->addWidget(buttonForAdditionSymbol,3,3);
    buttonForAdditionSymbol->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    //row 2

    buttonGridLayout->addWidget(buttonForNumber1,2,0);
    buttonForNumber1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonGridLayout->addWidget(buttonForNumber2,2,1);
    buttonForNumber2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonGridLayout->addWidget(buttonForNumber3,2,2);
    buttonForNumber3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonGridLayout->addWidget(buttonForSubstractionSymbol,2,3);
    buttonForSubstractionSymbol->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // row 1

    buttonGridLayout->addWidget(buttonForNumber4,1,0);
    buttonForNumber4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonGridLayout->addWidget(buttonForNumber5,1,1);
    buttonForNumber5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonGridLayout->addWidget(buttonForNumber6,1,2);
    buttonForNumber6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonGridLayout->addWidget(buttonForMultiplicationSymbol,1,3);
    buttonForMultiplicationSymbol->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    //row 0

    buttonGridLayout->addWidget(buttonForNumber7,0,0);
    buttonForNumber7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonGridLayout->addWidget(buttonForNumber8,0,1);
    buttonForNumber8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    buttonGridLayout->addWidget(buttonForNumber9,0,2);
    buttonForNumber9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    buttonGridLayout->addWidget(buttonForDivisionSymbol,0,3);
    buttonForDivisionSymbol->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layoutForQLineEdit->addWidget(pQLineEdit,0,Qt::AlignTop);
    layoutForQLineEdit->addLayout(buttonGridLayout,1);

    mainWindow.show();                        //  show the window

    return calculator.exec();                 // start event loop (heart of the application)
}
