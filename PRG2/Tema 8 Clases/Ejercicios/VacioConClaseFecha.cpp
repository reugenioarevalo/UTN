#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
//prototipos
void puntoA();
int buscarNacionalidad(int _dni);
void puntoB();
int buscarMaximo(int *, int );
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
class Astronauta{
    //Astronautas.dat: DNI (int), nombre y apellido (char[50]),
    //nacionalidad (entero entre 1 y 50), edad y género (1 a 3), especialidad (1 a 25).
     private:
         int dni;
         char nombreApellido[50];
         int nacionalidad;//(entero entre 1 y 50),
         int edad;
         char genero;// (1 a 3),
         int especialidad; //(1 a 25).

    public:
        //2) Agregar un constructor para alguna de las clases del ejercicio 1,
        //que por omisión ponga las propiedades numéricas en 0.
        //Al menos una de estas propiedades tiene que tener
        // responder de la siguiente manera: si se le envía un valor,
        // lo asigna a la propiedad; si no se le envía valor se le pone un 0.
        Astronauta(int _d=0, int _n=0, int _e=0, int _esp=0){
            dni=_d;
            nacionalidad=_n;
            edad=_e;
            if(_esp>0)especialidad=_esp;
            else specialidad=0;
        }
         int getDni(){return dni;}
         int getNacionalidad(){return nacionalidad;}
        bool leerDeDisco(int );

};
class Mision{
    //Misiones.dat: Número de misión, DNI del astronauta  a cargo (int),
    // fecha de inicio(día, mes y año),  tiempo de duración de la misión (días).
     private:
        int codMision;
        Fecha fechaInicio;
        int diasDeMision;
         int dni;
    public:
         int getCodMision(){return codMision;}
         Fecha getFecha(){return fechaInicio;}
         int getDiasDeMision(){return diasDeMision;}
         int getDni(){return dni;}
        bool leerDeDisco(int );


};
class Mshort{
    //Número de misión, y DNI y nacionalidad del astronauta a cargo. (3 puntos)
private:
    int codMision;
    int dni;
    int nacionalidad;
public:
    void setCodMision(int _cm){ codMision=_cm;}
    void setDni(int _d){ dni = _d;}
    void setNacionalidad(int _n){ nacionalidad= _n;}
    bool grabarEnDisco(){
        FILE *p;
        p=fopen("mision_corta.dat","ab");
        if(p==NULL){return false;}
        bool grabo = fwrite(this,sizeof *this,1,p);
        fclose(p);
        return grabo;
	}
};


//fin de Definiciones de clases
//Funciones de clases

bool Astronauta::leerDeDisco(int pos){
	FILE *p;
	p=fopen("Astronautas.dat","rb");
	if(p==NULL){return 0;}
	fseek(p,pos*sizeof *this,0);
	bool leyo=fread(this,sizeof *this,1,p);
	fclose(p);
	return leyo;
}
bool Mision::leerDeDisco(int pos){
	FILE *p;
	p=fopen("Misiones.dat","rb");
	if(p==NULL){return 0;}
	fseek(p,pos*sizeof *this,0);
	bool leyo=fread(this,sizeof *this,1,p);
	fclose(p);
	return leyo;
}

//Fin de funciones de clases

int main (){
setlocale(LC_ALL, "spanish");
int opc;
	while(1){
		system("cls");
		cout<<"-------------Menú Principal-------------"<<endl;
		cout<<"1. PUNTO A"<<endl;
		cout<<"2. PUNTO B"<<endl;
		cout<<"0. SALIR"<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<"Digite su opción: "<<endl;
		cin>>opc;
		switch(opc)
			{
			 case 0: return 0;
			 case 1: system("cls"); puntoA(); system("pause");break;
			 case 2: system("cls"); puntoB(); system("pause");break;
			 default: cout<<"Opcion incorrecta. Presione una tecla para continuar";
            system("pause");
            break;
			}
		}
   return 0;
}

//Funciones globales
int buscarNacionalidad(int _dni){
    Astronauta reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
      if(reg.getDni()==_dni){
        return reg.getNacionalidad();
      }
   }
   return 0;
}
void puntoA(){
//a) Generar un archivo nuevo (mision_corta.dat) con los datos de las misiones de 2020
// de menos de 20 días de tiempo de duración con el siguiente formato de registro:
//Número de misión, y DNI y nacionalidad del astronauta a cargo. (3 puntos)
    Mision reg;
    Mshort aux;
int con=0;
while(reg.leerDeDisco(con++)){
    if(reg.getFecha().getAnio()==2020 && reg.getDiasDeMision()<20){
        aux.setCodMision(reg.getCodMision());
        aux.setDni(reg.getDni());
        aux.setNacionalidad(buscarNacionalidad(reg.getDni()));
        aux.grabarEnDisco();
    }
}

}
int buscarMaximo(int *v, int tam){
   int posMax=v[0];
    for(int i=0;i<tam;i++){
        if(v[i]>posMax){
            posMax=v[i];
        }

    }
    return posMax;
}
void puntoB(){
    //b) El mes del año 2010 con más misiones.(3 puntos)
    Mision reg;
    int v[12]={0};
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getFecha().getAnio()==2010)
            v[reg.getFecha().getMes()-1]++;
    }
    cout<<" El Mes del año 2010 con masmisiones fué el : "<<buscarMaximo(v,  12)<<endl<<endl;
}
///punto 3
class Insecto: protected Animal{
private:
    bool alas;
public:
    void setTieneAlas(bool _tiene){alas =_tiene;}
    bool getAlas(){return alas;}
};
//3) Suponiendo que exista una clase de nombre Animal, generar a partir de
//ella una nueva clase de nombre Insecto, que tenga además de lo
//ya establecido en Animal, una propiedad para definir si tiene o
//no alas. Agregar el set y el get para esta propiedad.
