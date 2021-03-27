/*
ABML hecho para preparar el final  20/02/2021

*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>


using namespace std;

#include "tipos.h"
#include "fun_general.h"
#include "fecha.h"
#include "fun_alumnos.h"


///Cargar y mostrar un vector de vehículos de 5 componentes.
///Hacer el programa dentro de un proyecto. Desarrollar un menú

int main(){
   int opc;
    while(true){
        system("cls");
        cout << "---MENU ALUMNOS---" << endl;
        cout << "1. ALTA ALUMNO" << endl;
        cout << "2. BAJA ALUMNO" << endl;
        cout << "3. MODIFICAR ALUMNO" << endl;
        cout << "4. MOSTRAR ALUMNOS" << endl;
        cout << "5. CONTAR ALUMNOS ACTIVOS" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "--------------------" << endl;
        cout << "INGRESE UNA OPCION: " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
                case 1: altaAlumno();
                        break;
                case 2: bajaAlumno();
                        break;
                case 3: if(modificarAlumno()==true){
                        cout<<"MODIFICIACION REALIZADA CON EXITO!."<<endl;
                    }else{
                        cout<<"FALLO SU MODIFICIACION, REINTENTELO!."<<endl;
                    };
                        break;
                case 4: mostrarAlumnos();
                        break;
                case 5: mostrarCantidad();
                        break;
                case 0: return 0;
                        break;

        }
        system("pause");
    }
    return 0;
}
