
/**
/**
ejecicio matrices  clase 12/08/2020: Las autoridades de la utn estan realizando un analisis de los cursos virtuales de las distintas
materrias. por cada una de las 20 materias de la carrera tiene la siguiente informacion

numero de materia (1 a 20), nombre, cantidad de alumnos inscriptos, cant de profesores.

 Ademas por cada ingreso de los estudiantes al aula virtual  se registra la siguinte:
 legajo, fecha de acceso (dia y mes), nro de Materia, cant Hs. (nro Real).
 el fin de los datos se indica con un numero de legajo igual a 0.
 se quiere responder a las sigui9nete preguntas.
 a) Las materias que no tuvieron acceso de alumnos nunca.
 b) la Materia que mas cantidad de horas registro de acceso de alumnos.
 c) por cada materia y dia de marzo  la cantidad de alumnos que ingresaron a las aula virtuale.s


*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
#include "funciones.h"


int main()
{

    float horasMaterias[20]={0};
    int marzoMaterias[20][31]={0};
    int cant[20][2]={0};
    char nombreMaterias[20][30];
    int opc;
    while(true){
    system("cls");
    cout<<"-------------------------------MENU---------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"1. Cargar datos de la materias."<<endl;
    cout<<"6. mostrar materias."<<endl;
    cout<<"2. Cargar datos de accesos."<<endl;
    cout<<"3. Materias sin accesos."<<endl;
    cout<<"4. Materias con mayor cantidad de horas de acceso. "<<endl;
    cout<<"5. Cantidad de accesos por materia y dia de Marzo."<<endl;
    cout<<"0. salir."<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cin>>opc;
    system("cls");
    switch(opc){
        case 1: cargarMaterias(nombreMaterias, cant); break;
        case 2: cargarAccesos(  horasMaterias,  marzoMaterias); break;
        case 3: materiasSinAcceso( horasMaterias); break;
        case 4: mayorCantAcceso( horasMaterias ); break;
        case 5: accesosMarzo( marzoMaterias); break;
        case 6:mostrarMaterias(nombreMaterias, cant); break;
        case 0: return 0; break;
    }
 system("pause");
    }



    return 0;
}
