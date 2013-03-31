#ifndef KEYLOGGERWINDOW_H
#define KEYLOGGERWINDOW_H

#include <QWidget>
#include "keyboardlistener.h"

namespace Ui {
	class KeyLoggerWindow;
}

class KeyLoggerWindow : public QWidget
{
		Q_OBJECT

	public:
		explicit KeyLoggerWindow(QWidget *parent = 0);
		~KeyLoggerWindow();
	private:
        Ui::KeyLoggerWindow *ui;
};

#endif // KEYLOGGERWINDOW_H
