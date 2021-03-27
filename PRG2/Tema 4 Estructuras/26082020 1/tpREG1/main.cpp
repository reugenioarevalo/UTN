#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>


using namespace std;

#include "tipos.h"
#include "fun_general.h"
#include "fun_vehiculo.h"


///Cargar y mostrar un vector de vehículos de 5 componentes.
///Hacer el programa dentro de un proyecto. Desarrollar un menú

int main(){
    vehiculo vReg[5];
    int opc;
    while(true){
        system("cls");
        cout << "---MENU VEHICULOS---" << endl;
        cout << "1. CARGAR VEHICULOS" << endl;
        cout << "2. MOSTRAR VEHICULOS" << endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "--------------------" << endl;
        cout << "INGRESE UNA OPCION: " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
                case 1: cargarVehiculos(vReg,3);
                        break;
                case 2: mostrarVehiculos(vReg,3);
                        break;
                case 0:return 0;
                        break;

        }
        system("pause");
    }
    return 0;
}
