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

    QVBoxLayout *mainVerticalLayout = new QVBoxLayout(&mainWindow);
    mainVerticalLayout->addWidget(pQLineEdit,0,Qt::AlignTop);

    QString buttonTitleArray[16] = {

                                    "7","8","9","/",

                                    "4","5","6","x",

                                    "1","2","3","-",

                                    "0","C","=","+"

                                    };

    QPushButton *calculatorPushButtonsArray[16];

    //define layout for calculator push buttons

    QGridLayout *buttonGridLayout = new QGridLayout();

    // initialize 16 QPushButtons, add them to the button grid layout

    int i = 0;

    for (int rowNumber = 0; rowNumber < 4; rowNumber++)
    {
        for(int columnNumber = 0; columnNumber < 4; columnNumber++)
        {
            calculatorPushButtonsArray[i] = new QPushButton(buttonTitleArray[i]);
            calculatorPushButtonsArray[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            buttonGridLayout->addWidget(calculatorPushButtonsArray[i],rowNumber, columnNumber);
            calculatorPushButtonsArray[i]->setStyleSheet(
                "QPushButton {"
                "  background-color: white;"      // normal state
                "  border: 1px solid #ccc;"
                "  font-size: 18px;"
                "}"
                "QPushButton:hover {"
                "  background-color: lightblue;"  // hover state
                "}"
                "QPushButton:pressed {"
                "  background-color: lightblue;"
                "  border: 1px solid #2196F3;"  // optional: to show press feedback
                "  color: black;"               // prevent color fade
                "}"
                );

            i++;

        }
    }

    mainVerticalLayout->addLayout(buttonGridLayout,1);

    mainWindow.show();                        //  show the window

    return calculator.exec();                 // start event loop (heart of the application)
}
