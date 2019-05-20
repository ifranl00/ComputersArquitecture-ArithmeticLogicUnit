/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *entradaHexA;
    QPlainTextEdit *entradaHexB;
    QLineEdit *entradaA;
    QLineEdit *entradaB;
    QPushButton *dividir;
    QPushButton *multiplicar;
    QPushButton *sumar;
    QPlainTextEdit *salida;
    QPlainTextEdit *salidaHexadecimal;
    QMenuBar *menuBar;
    QMenu *menuIEEE754_CALCULATOR;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *grupo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(460, 369);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 185, 228);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        entradaHexA = new QPlainTextEdit(centralWidget);
        entradaHexA->setObjectName(QString::fromUtf8("entradaHexA"));
        entradaHexA->setGeometry(QRect(20, 70, 201, 31));
        entradaHexA->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 232, 240);"));
        entradaHexA->setReadOnly(true);
        entradaHexB = new QPlainTextEdit(centralWidget);
        entradaHexB->setObjectName(QString::fromUtf8("entradaHexB"));
        entradaHexB->setGeometry(QRect(230, 70, 201, 31));
        entradaHexB->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 232, 240);"));
        entradaHexB->setReadOnly(true);
        entradaA = new QLineEdit(centralWidget);
        entradaA->setObjectName(QString::fromUtf8("entradaA"));
        entradaA->setGeometry(QRect(20, 30, 201, 31));
        entradaA->setStyleSheet(QString::fromUtf8("#entradaA:hover{\n"
"	\n"
"background-color: rgb(160, 240, 236);\n"
"}\n"
"\n"
"#entradaA{\n"
"background-color: rgb(193, 232, 240);\n"
"}"));
        entradaA->setMaxLength(32767);
        entradaA->setReadOnly(false);
        entradaB = new QLineEdit(centralWidget);
        entradaB->setObjectName(QString::fromUtf8("entradaB"));
        entradaB->setGeometry(QRect(230, 30, 201, 31));
        entradaB->setStyleSheet(QString::fromUtf8("#entradaB:hover{\n"
"	background-color: rgb(160, 240, 236);\n"
"}\n"
"\n"
"#entradaB{\n"
"background-color: rgb(193, 232, 240);\n"
"}"));
        dividir = new QPushButton(centralWidget);
        grupo = new QButtonGroup(MainWindow);
        grupo->setObjectName(QString::fromUtf8("grupo"));
        grupo->addButton(dividir);
        dividir->setObjectName(QString::fromUtf8("dividir"));
        dividir->setGeometry(QRect(320, 140, 101, 31));
        dividir->setCursor(QCursor(Qt::PointingHandCursor));
        dividir->setStyleSheet(QString::fromUtf8("#transformar{\n"
"	\n"
"	\n"
"	background-color: rgb(120, 227, 197);\n"
"	border-style: solid;\n"
"	border-color: black;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"#transformar:pressed{\n"
"	\n"
"	background-color: rgb(49, 151, 97);\n"
"}\n"
"\n"
"#dividir{\n"
"	\n"
"	\n"
"	background-color: rgb(147, 179, 238);\n"
"	border-style: solid;\n"
"	border-color: black;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"#dividir:pressed{\n"
"	\n"
"	background-color: rgb(52, 101, 164);\n"
"}"));
        multiplicar = new QPushButton(centralWidget);
        grupo->addButton(multiplicar);
        multiplicar->setObjectName(QString::fromUtf8("multiplicar"));
        multiplicar->setGeometry(QRect(160, 140, 141, 31));
        multiplicar->setCursor(QCursor(Qt::PointingHandCursor));
        multiplicar->setStyleSheet(QString::fromUtf8("#transformar{\n"
"	\n"
"	\n"
"	background-color: rgb(120, 227, 197);\n"
"	border-style: solid;\n"
"	border-color: black;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"#transformar:pressed{\n"
"	\n"
"	background-color: rgb(49, 151, 97);\n"
"}\n"
"#multiplicar{\n"
"	\n"
"	\n"
"	background-color: rgb(147, 179, 238);\n"
"	border-style: solid;\n"
"	border-color: black;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"#multiplicar:pressed{\n"
"	\n"
"	\n"
"	background-color: rgb(52, 101, 164);\n"
"}"));
        sumar = new QPushButton(centralWidget);
        grupo->addButton(sumar);
        sumar->setObjectName(QString::fromUtf8("sumar"));
        sumar->setGeometry(QRect(30, 140, 111, 31));
        sumar->setCursor(QCursor(Qt::PointingHandCursor));
        sumar->setStyleSheet(QString::fromUtf8("#transformar{\n"
"	\n"
"	\n"
"	background-color: rgb(120, 227, 197);\n"
"	border-style: solid;\n"
"	border-color: black;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"#transformar:pressed{\n"
"	\n"
"	background-color: rgb(49, 151, 97);\n"
"}\n"
"#sumar{\n"
"		\n"
"	background-color: rgb(147, 179, 238);\n"
"	border-style: solid;\n"
"	border-color: black;\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"#sumar:pressed{\n"
"	\n"
"	background-color: rgb(52, 101, 164);\n"
"}"));
        salida = new QPlainTextEdit(centralWidget);
        salida->setObjectName(QString::fromUtf8("salida"));
        salida->setGeometry(QRect(70, 210, 341, 31));
        salida->setStyleSheet(QString::fromUtf8("#salida:hover{\n"
"background-color: rgb(160, 240, 236);\n"
"}\n"
"#salida{\n"
"background-color: rgb(193, 232, 240);\n"
"}"));
        salida->setReadOnly(true);
        salidaHexadecimal = new QPlainTextEdit(centralWidget);
        salidaHexadecimal->setObjectName(QString::fromUtf8("salidaHexadecimal"));
        salidaHexadecimal->setGeometry(QRect(70, 250, 341, 31));
        salidaHexadecimal->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 232, 240);"));
        salidaHexadecimal->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 460, 22));
        menuIEEE754_CALCULATOR = new QMenu(menuBar);
        menuIEEE754_CALCULATOR->setObjectName(QString::fromUtf8("menuIEEE754_CALCULATOR"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuIEEE754_CALCULATOR->menuAction());
        menuIEEE754_CALCULATOR->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ALU", nullptr));
        entradaHexA->setPlaceholderText(QApplication::translate("MainWindow", "resultado A en hexadecimal", nullptr));
        entradaHexB->setPlaceholderText(QApplication::translate("MainWindow", "resultado B en hexadecimal", nullptr));
#ifndef QT_NO_WHATSTHIS
        entradaA->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        entradaA->setInputMask(QString());
        entradaA->setPlaceholderText(QApplication::translate("MainWindow", "inserte el numero A", nullptr));
        entradaB->setInputMask(QString());
        entradaB->setText(QString());
        entradaB->setPlaceholderText(QApplication::translate("MainWindow", "inserte el numero B", nullptr));
        dividir->setText(QApplication::translate("MainWindow", "DIVISION", nullptr));
        multiplicar->setText(QApplication::translate("MainWindow", "MULTIPLICACION", nullptr));
        sumar->setText(QApplication::translate("MainWindow", "SUMA", nullptr));
        salida->setPlaceholderText(QApplication::translate("MainWindow", "Resultado operacion", nullptr));
        salidaHexadecimal->setPlaceholderText(QApplication::translate("MainWindow", "resultado operacion en hexadecimal", nullptr));
        menuIEEE754_CALCULATOR->setTitle(QApplication::translate("MainWindow", "IEEE754 CALCULATOR 30000", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
