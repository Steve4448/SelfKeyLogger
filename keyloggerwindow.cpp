#include "main.h"
#include "keyloggerwindow.h"
#include "ui_keyloggerwindow.h"
#include <QDebug>

KeyLoggerWindow::KeyLoggerWindow(QWidget *parent) :
	QWidget(parent),
    ui(new Ui::KeyLoggerWindow)
{
    setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
    Main::keyboardListener->setTextAddress((QPlainTextEdit*)ui->plainTextEdit);
}

KeyLoggerWindow::~KeyLoggerWindow()
{
    Main::keyboardListener->destroy();
	delete ui;
}
