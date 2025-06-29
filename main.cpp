#include<QApplication>
#include<QWidget>

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
    mainWindow.show();                        //  show the window
    return calculator.exec();                 // start event loop (heart of the application)
}
