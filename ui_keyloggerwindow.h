/********************************************************************************
** Form generated from reading UI file 'keyloggerwindow.ui'
**
** Created: Sun Jan 27 10:34:39 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYLOGGERWINDOW_H
#define UI_KEYLOGGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyLoggerWindow
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *KeyLoggerWindow)
    {
        if (KeyLoggerWindow->objectName().isEmpty())
            KeyLoggerWindow->setObjectName(QStringLiteral("KeyLoggerWindow"));
        KeyLoggerWindow->setEnabled(false);
        KeyLoggerWindow->resize(479, 213);
        verticalLayout = new QVBoxLayout(KeyLoggerWindow);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(KeyLoggerWindow);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setEnabled(false);
        plainTextEdit->setUndoRedoEnabled(false);
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);


        retranslateUi(KeyLoggerWindow);

        QMetaObject::connectSlotsByName(KeyLoggerWindow);
    } // setupUi

    void retranslateUi(QWidget *KeyLoggerWindow)
    {
        KeyLoggerWindow->setWindowTitle(QApplication::translate("KeyLoggerWindow", "Key Logger Window", 0));
    } // retranslateUi

};

namespace Ui {
    class KeyLoggerWindow: public Ui_KeyLoggerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYLOGGERWINDOW_H
