#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
//prototipos
void puntoA();
float promedioVisibilidad(int );
void puntoB();
int gradosDeVisibilidad(float );
void mostrarMatriz(int m[31][6], int nf, int nc);
void puntoC();
int contarVisibilidad(int );
void puntoD();
int contarCiudades();
int buscarMenor(int *, int);
//fin de prototipos

// Definiciones de clases
class Fecha{
private:
    int dia, mes, anio;
    public:
       int  getDia(){return dia;}
       int  getMes(){return mes;}
       int  getAnio(){return anio;}
};
class Ciudad{
    //Ciudades.dat
    //Código de ciudad, nombre, código de provincia (1 a 24).
    private:
    int codCiudad;
    int codProv;
    char nombre[30];

    public:
        void setCodCiudad(int _a=0){codCiudad=_a;}
        const char *getNombre(){return nombre;}
        int  getCodCiudad(){return codCiudad;}
        int  getCodProv(){return codProv;}
        bool leerDeDisco(int pos);
        Ciudad buscarCiudad(int _cod);
        void mostrarCiudad(Ciudad aux){

            cout<<"Código de Provincia:"<<aux.getCodProv()<<endl;
            cout<<"Código de Ciudad: "<<aux.getCodCiudad()<<endl;
            cout<<"Nombre de la ciudad: "<<aux.getNombre()<<endl;
        }

};
class Medicion{
    //Mediciones.dat
//Código de ciudad, visibilidad, temperatura, fecha (día, mes y año).

    private:
        int codCiudad;
        float visibilidad;
        float temperatura;
        Fecha fechaMedicion;

    public:

        int getCodCiudad(){return codCiudad;}
        float getVisibilidad(){return visibilidad;}
        Fecha getFecha(){return fechaMedicion;}
        bool leerDeDisco(int pos);
};
class Promedio{
    private:
        int codCiudad;
        char nombre[30];
        float promVisib;
    public:
        void setCodCiudad(int cc){ codCiudad=cc;}
        void setNombre(const char * n){ strcpy(nombre, n);}
        void setPromVisib(float pv){ promVisib= pv;}
        bool grabarEnDisco();
};
class Visibilidad{
    private:
        int codCiudad;
        char nombre[30];
        int cantidad;
    public:
        void setCodCiudad(int cc){ codCiudad=cc;}
        void setNombre(const char * n){ strcpy(nombre, n);}
        void setCantidad(float cv){ cantidad= cv;}
        bool grabarEnDisco();
};
//fin de Definiciones de clases
int main (){
setlocale(LC_ALL, "spanish");
int opc;
	while(1)
		{
		system("cls");
		cout<<"-------------Menú Principal-------------"<<endl;
		cout<<"1. PUNTO A"<<endl;
		cout<<"2. PUNTO B"<<endl;
		cout<<"3. PUNTO C"<<endl;
		cout<<"4. PUNTO D"<<endl;
		cout<<"0. SALIR"<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<"Digite su opción: "<<endl;
		cin>>opc;
		switch(opc)
			{
			 case 0: return 0;
			 case 1: system("cls"); puntoA(); system("pause");break;
			 case 2: system("cls"); puntoB(); system("pause");break;
			 case 3: system("cls"); puntoC(); system("pause");break;
			 case 4: system("cls"); puntoD(); system("pause");break;
			 default: cout<<"Opcion incorrecta. Presione una tecla para continuar";
            system("pause");
            break;
			}
		}
    return 0;
return 0;
}
//Funciones de clases
//Fin de funciones de clases
Ciudad buscarCiudad(int cc){
    Ciudad reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getCodCiudad()==cc){
            return reg;
        }
    }
    reg.setCodCiudad(-1);
    return reg;
}
bool Ciudad::leerDeDisco(int pos){
	FILE *p;
	p=fopen("Ciudades.dat","rb");
	if(p==NULL){return 0;}
	fseek(p,pos*sizeof *this,0);
	bool leyo=fread(this,sizeof *this,1,p);
	fclose(p);
	return leyo;
}


bool Medicion::leerDeDisco(int pos){
	FILE *p;
	p=fopen("Mediciones.dat","rb");
	if(p==NULL){return 0;}
	fseek(p,pos*sizeof *this,0);
	bool leyo=fread(this,sizeof *this,1,p);
	fclose(p);
	return leyo;
}

bool Promedio::grabarEnDisco(){
	FILE *p;
	p=fopen("Promedio.dat","ab");
	if(p==NULL){return false;}
	bool grabo = fwrite(this,sizeof *this,1,p);
	fclose(p);
	return grabo;
}
bool Visibilidad::grabarEnDisco(){
	FILE *p;
	p=fopen("Visibilidad_por_ciudad.dat","ab");
	if(p==NULL){return false;}
	bool grabo = fwrite(this,sizeof *this,1,p);
	fclose(p);
	return grabo;
}

//Funciones globales
void puntoA(){
  //  a) Generar un archivo con el siguiente formato:
    int pos=0;
    Promedio reg;
    Ciudad aux;
    while(aux.leerDeDisco(pos++)){
        reg.setCodCiudad(aux.getCodCiudad());
        reg.setNombre(aux.getNombre());
        reg.setPromVisib(promedioVisibilidad(aux.getCodCiudad()));
        reg.grabarEnDisco();
    }
}
float promedioVisibilidad(int cc){
    Medicion reg;
    float prom=0;
    int pos=0, cont=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getFecha().getMes()<=6 && reg.getCodCiudad()==cc){
            prom+=reg.getVisibilidad();
            cont++;
        }
    }
    if(prom==0)return 0;
    return prom/cont;
}
void puntoB(){
//b) La cantidad de mediciones de cada grado de visibilidad por cada día del mes de mayo.
    Medicion reg;
    int m[31][6]={0};
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getFecha().getMes()==5){
            m[reg.getFecha().getDia()-1][gradosDeVisibilidad(reg.getVisibilidad())]++;
        }

    }
    mostrarMatriz(m, 31, 6);
}
int gradosDeVisibilidad(float vv){
    if(vv<=50)return 0;
    if(vv<=500)return 1;
    if(vv<=1000)return 2;
    if(vv<=4000)return 3;
    if(vv<=10000)return 4;
    if(vv>10000)return 5;
}

void mostrarMatriz(int m[31][6], int nf, int nc){
    int i, j;
    cout<<"Grados: \t"<<endl;
    for(i=0; i<nf; i++){
    cout<<"dia "<<i+1<<"\t: ";
        for(j=0; j<nc; j++){
           cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void puntoC(){
    Ciudad reg;
    Visibilidad aux;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        aux.setCodCiudad(reg.getCodCiudad());
        aux.setNombre(reg.getNombre());
        aux.setCantidad(contarVisibilidad(reg.getCodCiudad()));
    }
}
int contarVisibilidad(int cc){
 Medicion reg;
    int pos=0, cont=0;
    while(reg.leerDeDisco(pos++)){
        if( reg.getFecha().getMes()<=6 && reg.getCodCiudad()==cc){
            if(gradosDeVisibilidad(reg.getVisibilidad())>3){
                cont++;
            }
        }
    }
    return cont;
}
void puntoD(){
    Ciudad reg;
    int *rAux;
   int cantCity=contarCiudades();
    Medicion aux;

    rAux=(int *)malloc(sizeof(int)*cantCity);
    if(rAux==NULL)return;

    int pos=0, pAux=0;
    while(reg.leerDeDisco(pos++)){
        while(aux.leerDeDisco(pAux++)){
        if( aux.getFecha().getMes()<=6 && aux.getCodCiudad()==reg.getCodCiudad()){
            if(gradosDeVisibilidad(aux.getVisibilidad())<4){
                rAux[aux.getCodCiudad()-1]++;
            }
        }
    }
    reg.mostrarCiudad(buscarCiudad(buscarMenor(rAux, cantCity )));
    free(rAux);
    }
}
int contarCiudades(){
    FILE *p;
    p=fopen("Ciudades.dat", "rb");
    if(p==NULL) return 0;
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Ciudad);

}
int buscarMenor(int *v, int cant){
    int i, posi, posmin=v[0];
    for(i=0;i<cant;i++){
            if(v[i] < posmin){
                posmin=v[i];
                posi=i+1;
            }

    }
    return posi;
}
