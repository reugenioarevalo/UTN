/**
1) Una peluquería tiene un archivo (color.dat) con la información de las coloraciones (tinturas) realizadas a los/las clientes
en lo que va del año. Cada registro contiene los siguientes campos:
Código de tintura (número entero entre el 100 y el 135), fecha (día, mes y año), género (‘H’: hombre; ‘M’: mujer; ‘O’: otro), tipo de pelo.
a) Informar el/los códigos de tintura que hayan registrado al menos 10 coloraciones en el mes de marzo (resuelto en clase)
b) El código de tintura menos utilizado.
c) Un listado de la cantidad de coloraciones por día realizadas en enero.
d) El porcentaje de coloraciones para cada género.
e) El día del año con más coloraciones realizadas
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>


using namespace std;

#include "tipos.h"
#include "fun_general.h"
#include "fecha.h"
#include "peluquria.h"


///Cargar y mostrar un vector de vehículos de 5 componentes.
///Hacer el programa dentro de un proyecto. Desarrollar un menú

int main(){
   int opc;
    while(true){
        system("cls");
        cout << "---MENU ALUMNOS---" << endl;
        cout << "1. punto a" << endl;
        cout << "2. punto b" << endl;
        cout << "3. punto c" << endl;
        cout << "4. punto d" << endl;
        cout << "5. punto e" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "--------------------" << endl;
        cout << "INGRESE UNA OPCION: " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
                case 1:puntoA();
                        break;
                case 2:puntoB();
                        break;
                case 3:puntoC();
                    break;
                case 4:
                        break;
                case 5:
                        break;
                case 0: return 0;
                        break;

        }
        system("pause");
    }
    return 0;
}
