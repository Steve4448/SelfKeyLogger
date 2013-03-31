#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H

#include <windows.h>
#include <windowsx.h>
#include <QDebug>
#include <QPlainTextEdit>

class KeyboardListener
{
	public:
		KeyboardListener();
		static LRESULT recordListener(int code, WPARAM wprm, LPARAM lprm);
		static QPlainTextEdit *up;
		static Qt::KeyboardModifiers curModifiers;
		static char getCharForVKCode(uint code, Qt::KeyboardModifiers modifier);
        static QFile output;
		void setTextAddress(QPlainTextEdit *up);
		HHOOK ahook;
		BOOL destroy();
};

#endif // JOURNALLISTENER_H
