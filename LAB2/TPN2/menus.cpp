#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include "funcionesTP.h"
#include "menus.h"
#include "fechas.h"
#include "rutinas.h"
using namespace std;


void menu()
{

    while(true)
    {
        cout<<"1 - USUARIOS"<<endl;
        cout<<"2 - ENTRENAMIENTOS"<<endl;
        cout<<"3 - REPORTES"<<endl;
        cout<<"4 - CONFIGURACION"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"0 - SALIR   "<<endl;
        int opcion;
        cout<<"> ";
        cin>>opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            menuUsuarios();
            break;
        case 2:
            menuRutinas();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}

void menuUsuarios()
{

    while(true)
    {
        system("cls");
        cout<<"1 - NUEVO USUARIO "<<endl;
        cout<<"2 - MODIFICAR USUARIO "<<endl;
        cout<<"3 - LISTAR USUARIO POR ID "<<endl;
        cout<<"4 - LISTAR TODOS LOS USUARIOS"<<endl;
        cout<<"5 - ELIMINAR USUARIO "<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        int opcion;
        cout<<"> ";
        cin>> opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            guardarUsuario();
            break;
        case 2:
            modificarUsuario();
            break;
        case 3:
            listarId();
            break;
        case 4:
            listarUsuarios();
            break;
        case 5:
            eliminarUsuario();
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    }
}

void menuRutinas()
{
    system("cls");
    cout<<"MEN� ENTRENAMIENTOS"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"1) NUEVO ENTRENAMIENTO"<<endl;
    cout<<"2) MODIFICAR ENTRENAMIENTO"<<endl;
    cout<<"3) LISTAR ENTRENAMIENTO POR ID"<<endl;
    cout<<"4) LISTAR ENTRENAMIENTOS POR IDUSUARIO"<<endl;
    cout<<"4) LISTAR TODOS LOS ENTRENAMIENTOS"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"0) VOLVER AL MEN� PRINCIPAL"<<endl;
    int opcion;
    cout<<"> ";
    cin>> opcion;
    system("cls");
    switch(opcion)
    {
    case 1:
        nuevaRutina();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 0:
        return;
        break;
    default:
        break;
    }

}


