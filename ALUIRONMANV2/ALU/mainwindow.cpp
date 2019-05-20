#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <number.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_sumar_clicked()
{
    /*convertimos los numeros leidos por la entrada a float*/
    float n1 = ui->entradaA->text().toFloat();
    float n2 = ui->entradaB->text().toFloat();

    /*creamos un objeto con esos numeros ya mencionados*/
    number *n = new number(n1,n2);

    /*limpiamos la casilla y imprimirmos los resultados en hexadecimal*/
    ui->entradaHexA->clear();
    ui->entradaHexA->appendPlainText("0x"+ QString::number(n->getNumeroA(),16));

    ui->entradaHexB->clear();
    ui->entradaHexB->appendPlainText("0x"+ QString::number(n->getNumeroB(),16));

    /*llamamos a la funcion sumar*/
        n->sumar();

    /*limpiamos la casilla e imprimimos el resultado de la suma en float*/
    ui->salida->clear();
    ui->salida->appendPlainText( QString::number(n->getFloatResultado()) );

     /*limpiamos la casilla e imprimimos el resultado de la suma en hexadecimal*/
    ui->salidaHexadecimal->clear();
    ui->salidaHexadecimal->appendPlainText("0x"+ QString::number(n->getNumeroResultado(),16));
}

void MainWindow::on_multiplicar_clicked()
{

    /*convertimos los numeros leidos por la entrada a float*/
    float n1 = ui->entradaA->text().toFloat();
    float n2 = ui->entradaB->text().toFloat();

    /*creamos un objeto con esos numeros ya mencionados*/
    number *n = new number(n1,n2);

    /*limpiamos la casilla y imprimirmos los resultados en hexadecimal*/
    ui->entradaHexA->clear();
    ui->entradaHexA->appendPlainText("0x"+ QString::number(n->getNumeroA(),16));

    ui->entradaHexB->clear();
    ui->entradaHexB->appendPlainText("0x"+ QString::number(n->getNumeroB(),16));

    /*llamamos a la funcion multiplicar*/
     n->multiplicar();

    /*limpiamos la casilla e imprimimos el resultado de la suma en float*/
    ui->salida->clear();
    ui->salida->appendPlainText( QString::number(n->getFloatResultado()));

    /*limpiamos la casilla e imprimimos el resultado de la suma en hexadecimal*/
    ui->salidaHexadecimal->clear();
    ui->salidaHexadecimal->appendPlainText("0x"+ QString::number(n->getNumeroResultado(),16));


}

void MainWindow::on_dividir_clicked()
{
    /*convertimos los numeros leidos por la entrada a float*/
    float n1 = ui->entradaA->text().toFloat();
    float n2 = ui->entradaB->text().toFloat();


    /*creamos un objeto con esos numeros ya mencionados*/
    number *n = new number(n1,n2);

    /*llamamos a la funcion dividir*/
    n->dividir();

    /*limpiamos la casilla e imprimimos el resultado de la suma en float*/
    ui->salida->clear();
    ui->salida->appendPlainText( QString::number(n->getFloatResultado()));

    /*limpiamos la casilla e imprimimos el resultado de la suma en hexadecimal*/
    ui->salidaHexadecimal->clear();
    ui->salidaHexadecimal->appendPlainText("0x"+ QString::number(n->getNumeroResultado(),16));

}
