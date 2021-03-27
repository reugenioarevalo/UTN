#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
//Prototipos funciones externas
int buscar_pro(char *);
void alta_pro();
void modifica_telPro();
void baja_logica_pro();
void listar_pro();
void menu_proveedores();
////////////////////
//DEFINICION DE LA CLASE

class Proveedor{
	private:
		char CUIT[5];
		char nombre[30];
		char direccion[30];
		char localidad[30];
		char ntel[15];
		int activo;
	public:
		int Cargar();
		void Mostrar();
		char * getCUIT(){return CUIT;};
		char * getnombre(){return nombre;};
		char * getdireccion(){return direccion;};
		char * getlocalidad(){return localidad;};
		char * getntel(){return ntel;};
		int getactivo(){return activo;};
		void setCUIT(char *c){strcpy(CUIT,c);};
		void setnombre(char *d){strcpy(nombre,d);};
		void setdireccion(char *di){strcpy(direccion,di);};
		void setlocalidad(char *l){strcpy(localidad,l);};
		void settel(char *tel){strcpy(ntel,tel);};
		void setactivo(int s){activo=s;};
		void Grabar_en_disco(void);
		int Leer_de_disco(int);
		void Modificar_en_disco(int);
		};
//****************
//desarrollo de los metodos
int Proveedor::Cargar(){
  int encontro;
	cout<<"Ingrese el codigo de Proveedor: ";
	cin>>CUIT;
	encontro=buscar_pro(CUIT);
	if(encontro==-1){
    cout<<"Ingrese el nombre:  ";
    cin>>nombre;
    cout<<"Ingrese la direccion:  ";
    cin>>direccion;
    cout<<"Ingrese la localidad:  ";
    cin>>localidad;
    cout<<"Ingrese el telefono:  ";
    cin>>ntel;
    activo=1;
    return 1;
	}
	return 0;
	}
void Proveedor::Mostrar()	{
	cout<<"Codigo de Proveedor: ";
	cout<<CUIT<<endl;
	cout<<"Nombre: ";
  cout<<nombre<<endl;
  cout<<"Direccion: ";
  cout<<direccion<<endl;
  cout<<"Localidad: ";
  cout<<localidad<<endl;
  cout<<"Telefono: ";
  cout<<ntel<<endl;
	}
void Proveedor::Grabar_en_disco(void){
	FILE *p;
	p=fopen("Proveedor.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}
int Proveedor::Leer_de_disco(int pos){
	int x;
	FILE *p;
	p=fopen("Proveedor.dat","rb");
	if(p==NULL){
		cout<<"No existe el archivo";
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return 0;
	}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}
void Proveedor::Modificar_en_disco(int pos)	{
	FILE *p;
	p=fopen("Proveedor.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
}

//*****************************
//DESARROLLO DE LAS FUNCIONES EXTERNAS
void menu_proveedores(){
	int opc;
	while(1){
		system("cls");
		cout<<"Menu Proveedors"<<endl;
		cout<<"1. Altas"<<endl;
		cout<<"2. Modificar telefono"<<endl;
		cout<<"3. Baja"<<endl;
		cout<<"4. Listado"<<endl;
		cout<<"5. Volver al menu principal"<<endl;
		cout<<"Ingrese la opcion: "<<endl;
		cin>>opc;
		switch(opc){
			 case 1: alta_pro();break;
			 case 2: modifica_tel();break;
			 case 3: baja_logica_pro();break;
			 case 4:listar_pro(); break;
			 case 5: return;
			 default: cout<<"Opcion incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
			}
		}
}
int buscar_pro(char *cod){
	int pos=0;
	Proveedor reg;
	while(reg.Leer_de_disco(pos)==1){
		if(strcmp(cod,reg.getCUIT())==0 && reg.getactivo()==1)
			return pos;
		pos++;
		}
	return -1;
}
void alta_pro(){
	Proveedor reg;
	system("cls");
	if(reg.Cargar()){
            reg.Grabar_en_disco();
    }else{
	  cout<<"Ya existe ese código";
	  cout<<"Presione una tecla para continuar";
	  system("pause>null");
	  }
}
void modifica_telPro(){
	char cod[5], tel[15];
	int pos;
	Proveedor reg;
	system("cls");
	cout<<"Ingrese el codigo del Proveedor a modificar:";
	cin>>cod;
	pos=buscar_pro(cod);
	if(pos!=-1){
		cout<<"Ingrese el nuevo telefono: ";
		cin>>tel;
		reg.Leer_de_disco(pos);
		reg.settel(tel);
		reg.Modificar_en_disco(pos);
		}else{
		cout<<"No existe el Proveedor"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}
}
void baja_logica_pro(){
	char cod[5];
	int pos;
	Proveedor reg;
	system("cls");
	cout<<"Ingrese el codigo del Proveedor a eliminar:";
	cin>>cod;
	pos=buscar_pro(cod);
	if(pos!=-1){
		reg.Leer_de_disco(pos);
		reg.setactivo(0);
		reg.Modificar_en_disco(pos);
		}else{
		cout<<"No existe el Proveedor"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}

}
void listar_pro(){
	Proveedor reg;
	int pos=0;
	system("cls");
	while(reg.Leer_de_disco(pos++)==1)	{
		if(reg.getactivo()==1){
            reg.Mostrar();
			system("pause>null");
			}
		}
		if(pos==1)	{
		cout<<"No existen registros"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}

	}





#endif // PROVEEDOR_H_INCLUDED
