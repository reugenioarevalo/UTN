#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;


#include "articulo.h"
#include "cliente.h"
#include "Clientes.h"
#include "venta.h"
#include "proveedor.h"

void genera_ar();//prototipo de la funcion que genera los archivos si no existen

int main()
{
	int opc;
  genera_ar();
	while(1)
		{
		system("cls");
		cout<<"Menu Principal"<<endl;
		cout<<"1. Articulos"<<endl;
		cout<<"2. Clientes"<<endl;
		cout<<"3. Ventas"<<endl;
		cout<<"4. Proveedores"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Ingrese la opcion: "<<endl;
		cin>>opc;
		switch(opc)
			{
			 case 1: menu_articulos();break;
			 case 2: menu_clientes();break;
			 case 3: menu_ventas(); break;
			 case 4: menu_proveedores();break;
			 case 5: return 0;
			 default: cout<<"Opcion incorrecta. Presione una tecla para continuar";
								system("pause>null");
								break;
			}
		}
    return 0;
}


void genera_ar()
	{
	FILE *p;
	p=fopen("articulo.dat","rb");
	if(p==NULL)
		p=fopen("articulo.dat","wb");
	fclose(p);


	p=fopen("ventas.dat","rb");
	if(p==NULL)
		p=fopen("ventas.dat","wb");
	fclose(p);

	p=fopen("cliente.dat","rb");
	if(p==NULL)
		p=fopen("cliente.dat","wb");
	fclose(p);

	p=fopen("Proveedor.dat","rb");
	if(p==NULL)
		p=fopen("Proveedor.dat","wb");
	fclose(p);
	}
