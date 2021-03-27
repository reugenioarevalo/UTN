#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include "funcionesTP.h"
#include "menus.h"
#include "fechas.h"
using namespace std;

Fecha hoy(){

    Fecha reg;
    time_t  hoy = time(0);
    tm *time=localtime(&hoy);
    reg.anio=1900+ time->tm_year;
    reg.mes= 1 + time->tm_mon;
    reg.dia= time->tm_mday;
    return reg;
}

bool validarEdad(int dia, int mes, int anio){

    int edad;
    Fecha fecha= hoy();

    if(validarFecha(dia,mes,anio)==false){return false;}

    if (fecha.mes > mes){edad = fecha.anio - anio;}
    else if(fecha.mes == mes){

        if (fecha.dia >= dia){edad = fecha.anio - anio;}

    } else{edad  = (fecha.anio - 1) - anio;}

    if(edad>=13 && edad<90){return true;}
    else{return false;}
}

bool validarFecha( int dia, int mes, int anio){

//  Se han de recibir tres par�metros, todos ellos de tipo entero.
//  Se devolver� un 0/false o un 1/true.

    bool fec = 0;

    if( mes >= 1 && mes <= 12 )
    {

        switch( mes )
        {

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if( dia >= 1 && dia <= 31 )
            {
                fec = true;
            }
            break;


        case 4:
        case 6:
        case 9:
        case 11:
            if( dia >= 1 && dia <= 30 )
            {
                fec = true;
            }
            break;


        case 2:
//Si el a�o es bisiesto +1 d�a.
            if( ((anio%4 == 0)   &&   (anio%100 != 0)) ||   (anio%400 == 0) )
            {
                if( dia >= 1 && dia <= 29 )
                {
                    fec = true;
                }
            }
            else
            {
                if( dia >= 1 && dia <= 28 )
                {
                    fec = true;
                }
            }
            break;

        }

    }

    return fec;
}
