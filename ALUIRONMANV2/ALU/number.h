#ifndef NUMBER_H
#define NUMBER_H
#include <QString>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using std::fpclassify;
using namespace std;

class number
{
public:
    number(float a, float b);
    ~number();

    int getNumeroA();
    int getNumeroB();
    int getNumeroResultado();
    float getFloatResultado();

    void sumar();
    void multiplicar();
    void dividir();


    /*VARIABLES ALGORITMO*/
    unsigned int p;
    unsigned int g;
    unsigned int r;
    unsigned int st;
    int n;
    bool operandoIntercambiado;
    bool complementadoP;
    int d;
    unsigned int p_d;
    unsigned int c1;


    struct campos{
       unsigned fraccionaria:23;
       unsigned exp:8;
       unsigned sig:1;
    };

    union numero {
       struct campos c;
       unsigned int sinSingno;
       signed int entero;
       float decimal;
    };

    union numero A;
    union numero B;
    union numero res;


    void suma(union numero *A,  union numero *B, union numero *result);
       void producto(union numero *A,  union numero *B, union numero *result);
       void division(union numero *A,  union numero *B, union numero *result);

       bool esNan(unsigned int exp, unsigned int fraccionaria);
       bool esInfinito(unsigned int exp, unsigned int fraccionaria);
       bool esDenormal(unsigned int exp);

       float floatFromMantisa(union numero *sc);
       number::campos floatToStruct(float num);
       unsigned int getFractionFromFloat(float X);
};

#endif // NUMBER_H
