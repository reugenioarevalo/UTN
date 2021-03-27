#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;


#include "articulo.h"
#include "cliente.h"
#include "venta.h"
#include "proveedor.h"



//****************************
//Prototipos funciones externas
int buscar_art(char *);
void alta_art();
void modifica_pu();
void baja_logica_art();
void listar_art();
void menu_articulos();

//*****************************

//CLASE
class Articulo
	{
	private:
		char codart[5];
		char desc[30];
		float pu;
		int stock;
		int activo;
	public:

		Articulo(const char *c="nada", const char *d="nada", float p=0, int s=0, bool e=true);
		Articulo(float, int);
		Articulo(int, float);
		int Cargar();
		void Mostrar();
		char * getcodart(){return codart;};
		char * getdesc(){return desc;};
		float getpu(){return pu;};
		int getstock(){return stock;};
		int getactivo(){return activo;};
		void setcodart(char *c){strcpy(codart,c);};
		void setdesc(char *d){strcpy(desc,d);};
		void setpu(float p){pu=p;};
		void setstock(int s){stock+=s;};
		void setactivo(int s){activo=s;};
		void Grabar_en_disco(void);
		int Leer_de_disco(int);
		void Modificar_en_disco(int);
		};
//****************
//desarrollo de los metodos
Articulo::Articulo(char *c="0", char *d="0", float p=0.0, int s=0)
  {
    strcpy(codart,c);
    strcpy(desc,d);
    pu=p;
    stock=s;
    }

Articulo::Articulo(float p, int s=0)
  {
    pu=p;
    stock=s;
    }

Articulo::Articulo(int s, float p=0.0)
  {
    stock=s;
    pu=p;
    }

int Articulo::Cargar()
	{
	int encontro;
	cout<<"Ingrese el codigo: ";
	cin>>codart;
	encontro=buscar_art(codart);
	if(encontro==-1)
	{
    cout<<"Ingrese la descripcion:  ";
    cin>>desc;
    cout<<"Ingrese el precio:  ";
    cin>>pu;
    cout<<"Ingrese el sotck:  ";
    cin>>stock;
    activo=1;
    return 1;
	}
	return 0;
	}

void Articulo::Mostrar()
	{
	cout<<"Codigo: ";
	cout<<codart<<endl;
	cout<<"Descripcion: ";
	cout<<desc<<endl;
	cout<<"Precio: ";
	cout<<pu<<endl;
	cout<<"Stock: ";
	cout<<stock<<endl;
	}

void Articulo::Grabar_en_disco(void)
	{
	FILE *p;
	p=fopen("articulo.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

int Articulo::Leer_de_disco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("articulo.dat","rb");
	if(p==NULL)
		{
		cout<<"No existe el archivo";
		cout<<"Presione una tecla para continuar";
    system("pause<null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}

void Articulo::Modificar_en_disco(int pos)
	{
	FILE *p;
	p=fopen("articulo.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

//FUNCIONES EXTERNAS
int buscar_art(char *cod)
{
	int pos=0;
	Articulo reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(strcmp(cod,reg.getcodart())==0 && reg.getactivo()==1)
			return pos;
		pos++;
		}
	return -1;
}


void alta_art()
{
	Articulo reg;
	system("cls");
	if(reg.Cargar())
    reg.Grabar_en_disco();
  else
  	{
	  cout<<"Ya existe ese código";
	  cout<<"Presione una tecla para continuar";
	  system("pause>null");

	  }
}

void modifica_pu()
{
	char cod[5];
	float npu;
	int pos;
	Articulo reg;
	system("cls");
	cout<<"Ingrese el codigo del articulo a modificar:";
	cin>>cod;
	pos=buscar_art(cod);
	if(pos!=-1)
		{
		cout<<"Ingrese el nuevo precio: ";
		cin>>npu;
		reg.Leer_de_disco(pos);
		reg.setpu(npu);
		reg.Modificar_en_disco(pos);
		}
	else
		{
		cout<<"No existe el articulo"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}
}

void baja_logica_art()
{
	char cod[5];
	int pos;
	Articulo reg;
	system("cls");
	cout<<"Ingrese el codigo del articulo a eliminar:";
	cin>>cod;
	pos=buscar_art(cod);
	if(pos!=-1)
		{
		reg.Leer_de_disco(pos);
		reg.setactivo(0);
		reg.Modificar_en_disco(pos);
		}
	else
		{
		cout<<"No existe el articulo"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}

}


void listar_art()
	{
	Articulo reg;
	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++)==1)
		{
		if(reg.getactivo()==1)
			{reg.Mostrar();
			system("pause>null");
			}
		}
	if(pos==1)
		{
		cout<<"No existen registros"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}
	}


void menu_articulos()
	{
	int opc;
	while(1)
		{
		system("cls");
		cout<<"MENU ARTICULOS"<<endl;
		cout<<"1. Altas"<<endl;
		cout<<"2. Modificar precio unitario"<<endl;
		cout<<"3. Baja"<<endl;
		cout<<"4. Listado"<<endl;
		cout<<"5. Volver al MENU PRINCIPAL"<<endl;
		cout<<"INGRESE LA OPCION: "<<endl;
		cin>>opc;
		switch(opc)
			{
			 case 1: alta_art();break;
			 case 2: modifica_pu();break;
			 case 3: baja_logica_art();break;
			 case 4:listar_art(); break;
			 case 5: return;
			 default: cout<<"Opcion incorrecta. Presione una tecla para continuar";
								system("pause>null");
								break;
			}
		}
	}


//FIN FUNCIONES EXTERNAS



#endif // ARTICULO_H_INCLUDED
