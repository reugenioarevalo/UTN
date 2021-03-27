#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>



using namespace std;

const char *ARCHIVO_ANIMALES="animales.dat";
const char *ARCHIVO_AVISTAJES="avistajes.dat";

#include "tipos.h"
#include "prototipos.h"
#include "funciones.h"
#include "funciones_animales.h"
#include "funciones_avistajes.h"


int main(){
    int opc;
    while(true){
      system("cls");
      cout << "-----MENU PRINCIPAL-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. ANIMALES" << endl;
      cout << "2. AVISTAJES" << endl;
      cout << "3. REPORTES" << endl;
      cout << "4. CONFIGURACION" << endl;
      cout << "0. FIN DEL PROGRAMA" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case 1: menuAnimales();
                break;
        case 2: menuAvistajes();
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
