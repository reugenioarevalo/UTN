#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>



using namespace std;

const char *ARCHIVO_VIAJES="viajes.dat";
const char *ARCHIVO_EMPRESAS="empresas.dat";

#include "tipos.h"
#include "prototipos.h"
#include "funciones.h"
#include "funciones_empresas.h"
#include "funciones_viajes.h"
#include "reportes.h"


int main(){
    int opc;
    while(true){
      system("cls");
      cout << "-----MENU PRINCIPAL-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. EMPRESAS" << endl;
      cout << "2. VIAJES" << endl;
      cout << "3. REPORTES" << endl;
      cout << "4. CONFIGURACION" << endl;
      cout << "0. FIN DEL PROGRAMA" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case 1: menuEmpresas();
                break;
        case 2: menuViajes();
                break;
        case 3: menuReportes();
                break;
        case 0: return 0;
                break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
      system("pause");
    }
    return 0;
}
