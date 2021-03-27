#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
//****************************
//Prototipos funciones externas
int buscar_nroventa();
int buscar_venta(int);
void alta_venta();
void baja_logica_venta();
void listar_ventas();
void menu_ventas();
///////////////////////

class Ventas{
	private:
		int nroventa;
		char codart[5];
		char codcli[5];
		float importe;
		int cant,dia,mes;
		int activo;
	public:
		void Cargar_codart();
		void Cargar_codcli();
		void Cargar_cant();
		void Cargar_fecha();
		void Mostrar();
		int getnroventa(){return nroventa;};
		char * getcodart(){return codart;};
		char * getcodcli(){return codcli;};
		float getimporte(){return importe;};
		int getcant(){return cant;};
		int getdia(){return dia;};
		int getmes(){return mes;};
		int getactivo(){return activo;};
		void setnroventa(int nv){nroventa=nv;};
		void setcant(int c){cant=c;};
		void setimporte(float p){importe=p;};
		void setdia(int d){dia=d;};
		void setmes(int m){mes=m;};
		void setactivo(int s){activo=s;};
		void Grabar_en_disco(void);
		int Leer_de_disco(int);
		void Modificar_en_disco(int);
		};
//****************
//desarrollo de los m‚todos
void Ventas::Cargar_codart(){
	cout<<"Ingrese el codigo de articulo: ";
	cin>>codart;
	}

void Ventas::Cargar_codcli()	{
	cout<<"Ingrese el codigo de cliente: ";
	cin>>codcli;
	}

void Ventas::Cargar_cant(){
	cout<<"Ingrese la cantidad:  ";
	cin>>cant;
	}

void Ventas::Cargar_fecha(){
		cout<<"Ingrese el dia:  ";
		cin>>dia;
		cout<<"Ingrese el mes:  ";
		cin>>mes;
		activo=1;
	}


void Ventas::Mostrar(){
	cout<<"Numero de venta: ";
	cout<<nroventa<<endl;
	cout<<"Codigo de articulo: ";
	cout<<codart<<endl;
	cout<<"Codigo de cliente: ";
	cout<<codcli<<endl;
	cout<<"Cantidad: ";
	cout<<cant<<endl;
	cout<<"Importe: ";
	cout<<importe<<endl;
	cout<<"Dia: ";
	cout<<dia<<endl;
	cout<<"Mes: ";
	cout<<mes<<endl;
	}

void Ventas::Grabar_en_disco(void){
	FILE *p;
	p=fopen("ventas.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

int Ventas::Leer_de_disco(int pos){
	int x;
	FILE *p;
	p=fopen("ventas.dat","rb");
	if(p==NULL)
		{
		cout<<"No existe el archivo"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}

void Ventas::Modificar_en_disco(int pos){
	FILE *p;
	p=fopen("ventas.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

//*****************************

void menu_ventas(){
	int opc;
	while(1)
		{
		system("cls");
		cout<<"Menu Ventas"<<endl;
		cout<<"1. Altas"<<endl;
		cout<<"2. Baja"<<endl;
		cout<<"3. Listado"<<endl;
		cout<<"4. Volver al menu principal"<<endl;
		cout<<"Ingrese la opcion: "<<endl;
		cin>>opc;
		switch(opc)
			{
			 case 1: alta_venta();break;
			 case 2: baja_logica_venta();break;
			 case 3: listar_ventas(); break;
			 case 4: return;
			 default: cout<<"Opcion incorrecta. Presione una tecla para continuar";
								system("pause>null");
								break;
			}
		}
	}

int buscar_nroventa(){
	int pos=0;
	int max=0;
	Ventas reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(reg.getnroventa()>max && reg.getactivo()==1)
				max=reg.getnroventa();
		pos++;
		}
	return max+1;
}

int buscar_venta(int nro){
	int pos=0;
	Ventas reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(nro==reg.getnroventa() && reg.getactivo()==1)
			return pos;
		pos++;
		}
	return -1;
}


void alta_venta(){
	Ventas reg;
	Articulo regart;
	int posart,poscli;
	system("cls");
	reg.Cargar_codart();
	posart=buscar_art(reg.getcodart());
	if(posart==-1){
		cout<<"No existe el codigo de articulo"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return;
		}
	reg.Cargar_codcli();
	poscli=buscar_cli(reg.getcodcli());
	if(poscli==-1){
		cout<<"No existe el codigo de cliente"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return;
		}
	reg.setnroventa(buscar_nroventa());
	reg.Cargar_cant();
	regart.Leer_de_disco(posart);
	if(reg.getcant()>regart.getstock())	{
		cout<<"No hay stock suficiente para la venta"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		return;
		}
	reg.setimporte(reg.getcant()*regart.getpu());
	reg.Cargar_fecha();
	reg.Grabar_en_disco();
	reg.Mostrar();
	regart.setstock(-reg.getcant());
	regart.Modificar_en_disco(posart);
	cout<<"Presione una tecla para continuar";
	system("pause>null");
}


void baja_logica_venta(){
	int nro;
	int pos;
	Ventas reg;
	system("cls");
	cout<<"Ingrese el numero de la venta a eliminar:";
	cin>>nro;
	pos=buscar_venta(nro);
	if(pos!=-1){
		reg.Leer_de_disco(pos);
		reg.setactivo(0);
		reg.Modificar_en_disco(pos);
		}else{
		cout<<"No existe la venta"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}

}


void listar_ventas(){
	Ventas reg;
	Articulo regart;
	Cliente regcli;
	int pos=0,poscli,posart;
	system("cls");
	while(reg.Leer_de_disco(pos++)==1){
		if(reg.getactivo()==1)
			{reg.Mostrar();
			 posart=buscar_art(reg.getcodart());
			 regart.Leer_de_disco(posart);
			 cout<<endl<<regart.getdesc()<<endl;
			 poscli=buscar_cli(reg.getcodcli());
			 regcli.Leer_de_disco(poscli);
			 cout<<regcli.getnombre();
			system("pause>null");
			}
		}
		if(pos==1){
		cout<<"No existen registros"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>null");
		}
	}



#endif // VENTA_H_INCLUDED
