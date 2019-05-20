#include "number.h"
#include <stdio.h>
#include <math.h>


using std::fpclassify; //Categorizes floating point value arg into the following categories: zero, subnormal, normal, infinite, NAN, or implementation-defined category.
/*
 * Constructor de la clase number
 */
number::number(float a, float b)
{
    A.decimal = a;
    B.decimal = b;
}

/*
 * Destructor de la clase number
 */
number::~number()
{
    delete this;
}

/*
 * Método que calcula la suma de los numeros A y B
 */
void number::suma(union numero *A, union numero *B, union numero *result){

    /*------------------------------* COMPROBACIONES *----------------------------------*/

    //NAN
    if((fpclassify(A->decimal) == FP_NAN) || fpclassify(B->decimal) == FP_NAN) {
        result->decimal = NAN;
        return;
    }

    //INF + INF = INF
    if( ((fpclassify(A->decimal) == FP_INFINITE) && (fpclassify(B->decimal) == FP_INFINITE))){
        result->decimal = INFINITY;
        return;
    }

    //INF - INF = 0
    if( (((fpclassify(A->decimal) == FP_INFINITE) && (fpclassify(B->decimal) == -FP_INFINITE)))){
        result->decimal = INFINITY;
        return;
    }

    // INF + X = INF , -INF + X = -INF
    if( (esInfinito(A->c.exp, A->c.fraccionaria) && !esInfinito(B->c.exp, B->c.fraccionaria)) ){
        result->c.sig = A->c.sig;
        result->c.exp = 255;
        result->c.fraccionaria = 0;
        return;
    }

    // X + INF = INF , X + (-INF) = -INF
    if( (!esInfinito(A->c.exp, A->c.fraccionaria) && esInfinito(B->c.exp, B->c.fraccionaria)) ){
        result->c.sig = B->c.sig;
        result->c.exp = 255;
        result->c.fraccionaria = 0;
        return;
    }

    //Si A es 0
    if( (fpclassify(A->decimal)) == FP_ZERO){
        result->decimal = B->decimal;
        return;
    }

    //Si B es 0
    if( (fpclassify(B->decimal)) == FP_ZERO ){
         result->decimal = A->decimal;
        return;
    }
    //Si A y B son iguales pero de diferente signo = 0
    if( ((A->c.exp==B->c.exp) && (A->c.fraccionaria == B->c.fraccionaria)) && (A->c.sig != B->c.sig)){
        result->decimal = 0;
        return;
    }
    /*------------------------------------------------------------------------------------*/
    /*-- PASO 1: --*/
    p = 0;
    r = 0;
    g = 0;
    st = 0;
    n = 24;
    operandoIntercambiado = false;
    complementadoP = false;

     /*-- PASO 2: --*/
    if(A->c.exp < B->c.exp){
        union numero *temp = A;
        A = B;
        B = temp;

        operandoIntercambiado = true;
    }

    /*---------------------------* CREAMOS MANTISAS *-------------------------------------*/

    unsigned int mA = A->c.fraccionaria;
    if(!esDenormal(A->c.exp)){
        mA = (mA | 0x800000);
    }else{
        A->c.exp = 1;
    }

    unsigned int mB = B->c.fraccionaria;
    if(!esDenormal(B->c.exp)){
        mB = (mB | 0x800000);
    }else{
        B->c.exp = 1;
    }
    /*-------------------------------------------------------------------------------------*/

     /*-- PASO 3: --*/
    result->c.exp = A->c.exp;
    d = A->c.exp - B->c.exp;

     /*-- PASO 5: --*/
    p = mB;

     /*-- PASO 4: --*/
    if(A->c.sig != B->c.sig){
        p = (p ^ ~0) + 1; //(P ^ 4294967295) + 1;
        p = (p ^ 0xff000000);
    }

     /*-- PASO 6: --*/
    if((d-1) >= 0)
        g = ((p >> (d-1))&1);



    if((d-2) >= 0)
        r = ((p >> (d-2))&1);

    if(d-3 >= 0)
        for(int i = (d-3); i >= 0 ;i--){
            if(i >= 0){
                st = (st | ((p >> (i)) & 1) );
            }
        }

     /*-- PASO 7: --*/
    if(A->c.sig != B->c.sig){
        int i =0;
        while(i<d){
            p = p >> 1;
            p = (p | 0x800000);
            i++;
        }
    } else {
        p = p >> d;
    }

     /*-- PASO 8: --*/
    p = p + mA;
    c1 = ((p >> 24)&1);
    p_d = p;
    p = p - (c1 * 0x1000000);

     /*-- PASO 9: --*/
    if((A->c.sig != B->c.sig) && ( ((p >> (n-1))&1) == 1) && (c1 == 0)){
        p = (p ^ ~0) + 1;
        p = (p ^ 0xff000000);
        complementadoP = true;
    }

     /*-- PASO 10: --*/
    int k = 0;
    if((A->c.sig == B->c.sig) && (c1 == 1)){
        st = g | r | st;
        r = ((p >> 0)&1);
        p = p_d >> 1;
        result->c.exp = result->c.exp+1;
    } else {
        unsigned int Pc = p;
        int j = 23;
        while(j>=0){
            if( !((Pc >> 23)&1 ) ){
                Pc = Pc << 1;
                k++;
            }else{
                break;
            }
           j--;
        }

        if(k == 0){
            st = (r | st);
            r = g;
        }else if(k > 1){
            r = 0;
            st = 0;
        }

        int t = 0;
        while(t<k){
            p = p << 1;
            if(g == 1)
                p = (p | 1);
            t++;
        }

        result->c.exp = result->c.exp - k;
    }

     /*-- PASO 11: --*/
    unsigned int c2 = 0;
    if( ((r==1) && (st==1)) || ((r==1)&&(st==0)&& (((p >> (0))&1) == 1)) ){
        p = p +1;
        c2 = ((p >> 24)&1);
        p_d = p;
        p = p - (c2 * 0x1000000);

        if(c2 == 1){
            p = p_d >> 1;
            result->c.exp = result->c.exp + 1;
        }
    }

    result->c.fraccionaria = p;

     /*-- PASO 12: --*/
    if(!operandoIntercambiado && complementadoP){
        result->c.sig = B->c.sig;
    }else{
        result->c.sig = A->c.sig;
    }
}


/*
 * Método que calcula el producto de los numeros A y B
 */
void number::producto(union numero *A, union numero *B, union numero *result){

    /*----------------------------------* COMPROBACIONES CERO *------------------------------------------*/

    //NAN * NAN = NAN
        if( fpclassify(A->decimal) == FP_NAN || fpclassify(B->decimal) == FP_NAN ){
            result->decimal = NAN;
            return;
        }

        //0 * INF = 0
        if( (fpclassify(A->decimal) == FP_ZERO || (fpclassify(B->decimal) == FP_ZERO)) && (fpclassify(A->decimal) == FP_INFINITE || fpclassify(B->decimal) == FP_INFINITE) ){
            result->decimal = 0;
            return;
        }

        // INF * INF = INF || INF * -INF || -INF * INF
        if((esInfinito(A->c.exp, A->c.fraccionaria)) || (esInfinito(B->c.exp, B->c.fraccionaria))){
            result->c.sig = A->c.sig | B->c.sig;
                   result->c.exp = 255;
                   result->c.fraccionaria = 0;
                   return;
        }
        // 0 * 0
        if(fpclassify(A->decimal) == FP_ZERO  ||fpclassify(B->decimal) == FP_ZERO  ){
            result->decimal = 0;
            return;
        }

    /*--------------------------------------------------------------------------------------------------*/

    // inicializamos las variables
     p = 0;
     r = 0;
     st = 0;
     n = 24;

     /*-- PASO 1: --*/
    result->c.sig = A->c.sig ^ B->c.sig;

     /*-- PASO 2: --*/
    result->c.exp = (A->c.exp - 127) + (B->c.exp - 127);
    result->c.exp = (result->c.exp + 127);

    /*-------------------------* CREAMOS LAS MANTISAS *--------------------------------*/

    unsigned int Ma = A->c.fraccionaria;
    Ma = ( Ma | 0x800000 );

    unsigned int Mb = B->c.fraccionaria;
    Mb = ( Mb | 0x800000 );

    /*--------------------------------------------------------------------------------*/

    /*-- PASO 3: --*/
    // PASO 3.1
    unsigned int Mac = Ma;
    int i = 0;
    while(i<24){
        if( ((Mac >> (0))&1) ){
            p = p + Mb;
        }

        p = p >> 1;
        Mac = Mac >> 1;
        i++;
    }

    // PASO 3.2
    if( !((p >> (n-1))&1) )
        p = p << 1;
    else
        result->c.exp = result->c.exp + 1;

    // PASO 3.3
    r = ((Ma >> (n-1))&1);

    // PASO 3.4
    for (int i = (n-2); i >= 0; i--) {
        st = (st | ((Ma >> (i))&1));
    }

    // PASO 3.5
    if( (r == 1 && st == 1) || (r == 1 && st == 0 && ((p >> (0))&1)) ){
        p = p + 1;
    }

    /*------------------------------------* UNDERFLOW *--------------------------------------*/
    int t = 0;
    if(result->c.exp < 127){
        t = 127 - result->c.exp;
        if( t < 24 ){
            int i1 = 0;
            while(i1<t){
                p = p >> 1;

                if( ((p>>23)&1) )
                    p = p | 0x800000;
               i1++;
            }
            result->c.exp = 127;
        }
    }
    /*-------------------------------------------------------------------------------------*/

    /*---------------------------------* DENORMALES *--------------------------------------*/

    if(esDenormal(A->c.exp) || esDenormal(B->c.exp)){
        if(result->c.exp > 127){
            int t1 = result->c.exp - 127;
            int t2 = 0;
            unsigned int Pc = p;
            int i2 = 23;
            while(i2 >=0){
                if( !((Pc >> 23)&1 ) ){
                    Pc = Pc << 1;
                    t2++;
                }else{
                    break;
                }
                i2--;
            }

            if(t1 < t2){
                t = t1;
            }else{
                t = t2;
            }

            result->c.exp = result->c.exp - t;

            int i3 = 0;
            while(i3<t){
                p = p << 1;

                if( ((p>>0)&1) )
                    p = p | 0x800000;
                i3++;
            }
        }
    }

    result->c.fraccionaria = p;

    /*------------------------------------------------------------------------------------*/
}


/*
 * Método que calcula la division de los numeros A y B
 */
void number::division(union numero *A, union numero *B, union numero *result){

    /*----------------------------------* OPERANDOS *-------------------------------------*/

    //si alguno de los operandos en NAN
    if( (fpclassify(A->decimal) == FP_NAN ||fpclassify(B->decimal) == FP_NAN)){
        result->decimal = NAN;
        return;
    }
    //si B es 0 el resultado sera indeterminacion que marcaremos como NAN
    if(fpclassify(B->decimal) == FP_ZERO){
        result->decimal = NAN;
        return;
    }

    // INF/INF = 1 , -INF/INF = -1
    if( fpclassify(A->decimal) == FP_INFINITE && fpclassify(B->decimal) == FP_INFINITE ){
        result->decimal = 1;
        result->c.sig = signbit(A->decimal) ^ signbit(B->decimal);
        return;
    }

    // INF / X = INF , -INF / X = -INF
    if( (esInfinito(A->c.exp, A->c.fraccionaria) && !esInfinito(B->c.exp, B->c.fraccionaria)) ){
        result->c.sig = A->c.sig;
        result->c.exp = 255;
        result->c.fraccionaria = 0;
        return;
    }

    // X / INF = 0
    if( (!esInfinito(A->c.exp, A->c.fraccionaria) && esInfinito(B->c.exp, B->c.fraccionaria)) ){
        result->decimal = 0;
        return;
    }

    // Si A es 0, 0 / x = 0
    if( (fpclassify(A->decimal) == FP_ZERO) ){
           result->decimal = 0;
        return;
    }

    // Los operandos tienen mismo valor absoluto
    if( (B->c.exp == A->c.exp) && (B->c.fraccionaria == A->c.fraccionaria) ){
        result->decimal = 1;
        result->c.sig = signbit(A->decimal) ^ signbit(B->decimal);
        return;
    }

    /*--------------------------------------------------------------------------------------*/

    /*-- PASO 1: --*/
    /*Asignamos al resultado el signo que tendra la division*/
    result->c.sig = A->c.sig ^ B->c.sig;

    /*-- PASO 2: --*/
     float Bprima = 0;

    /*Escalamos las mantisas*/
    float mantisaA = (A->decimal/scalbln(1.0,ilogb(A->decimal)));
    float mantisaB = (B->decimal/scalbln(1.0,ilogb(B->decimal)));


    if(mantisaB < 1.25){    //si esta en el intervalo de [1, 1'25) vale 1
        Bprima = 1.00;
    }else{                  //si esta en el intervalo de (1'25, 2] vale 0'8
        Bprima = 0.80;
    }

    /*convertimos el float en union y lo guardamos en numA, numB y Bprima*/
    union numero numA;
    numA.decimal = mantisaA;

    union numero numB;
    numB.decimal = mantisaB;

    union numero numBprima;
    numBprima.decimal = Bprima;


    /* calculamos el producto de */
    producto(&numA, &numBprima, result);
    number::numero X = res;
    number::numero Xant = X;

    producto(&numB, &numBprima, result);
    number::numero Y = res;
    number::numero r;

    //convertimos de float a struct
    union numero num2;
    num2.decimal = 2.0;

    /*
    do{
        number::numero yN = Y;
        yN.c.sig = 1;

        suma(&num2, &yN, result);
        r = res;

        producto(&Y, &r, result);
        Y = res;

        Xant = X;
        producto(&X, &r, result);
        X = res;
    }while(((Xant.decimal/scalbln(1.0,ilogb(Xant.decimal))) - (X.decimal/scalbln(1.0,ilogb(X.decimal)))) < 0.0001);
    */
    result->c.exp = A->c.exp - B->c.exp + 127;

    if( mantisaA <= mantisaB){
        result->c.exp = result->c.exp - 1;
    }

    /*
    union numero *fraction;
    fraction->decimal =(ldexp((X.decimal/scalbln(1.0,ilogb(X.decimal))), (result->c.exp-127)));
    result->c.fraccionaria = fraction->c.fraccionaria;
    */
    //result.c.fraccionaria =getFractionFromFloat(ldexp((X.decimal/scalbln(1.0,ilogb(X.decimal))), (result.c.exp-127)));


}

/*
 * Método que recive el exponente y la parte fraccionaria y comprueba si es NaN
 */
bool number::esNan(unsigned int e, unsigned int f){
    if( ((e >> 0)&1) && ((e >> 1)&1) && ((e >> 2)&1) && ((e >> 3)&1) && ((e >> 4)&1) && ((e >> 5)&1) && ((e >> 6)&1) && ((e >> 7)&1) ){
        if(f != 0){
            return true;
        }
    }
    return false;
}


/*
 * Método que recive el exponente y la parte fraccionaria y comprueba si es Infinito
 */
bool number::esInfinito(unsigned int e, unsigned int f){
    if( ((e >> 0)&1) && ((e >> 1)&1) && ((e >> 2)&1) && ((e >> 3)&1) && ((e >> 4)&1) && ((e >> 5)&1) && ((e >> 6)&1) && ((e >> 7)&1) ){
        if(f == 0){
            return true;
        }
    }
    return false;
}


/*
 * Método que recive el exponente y comprueba is es Denormal
 */
bool number::esDenormal(unsigned int e){
    if( !((e >> 0)&1) && !((e >> 1)&1) && !((e >> 2)&1) && !((e >> 3)&1) && !((e >> 4)&1) && !((e >> 5)&1) && !((e >> 6)&1) && !((e >> 7)&1) ){
        return true;
    }
    return false;
}


/*
 * Método que calcula la suma de los numeros A y B y la gurada en el resultado
 */
void number::sumar(){
    suma(&A, &B, &res);
}

/*
 * Método que calcula el rpoducto de los numeros A y B y lo guarda en el resultado
 */
void number::multiplicar(){
    producto(&A, &B, &res);
}

void number::dividir(){
    division(&A, &B, &res);
}



/*-----------* GETTERS *------------*/

int number::getNumeroA(){
    return this->A.entero;
}

int number::getNumeroB(){
    return this->B.entero;
}

int number::getNumeroResultado(){
    return this->res.entero;
}

float number::getFloatResultado(){
    return this->res.decimal;
}
/*-----------------------------------*/

