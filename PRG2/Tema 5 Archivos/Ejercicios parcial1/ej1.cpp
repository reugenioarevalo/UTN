/*
1) Una empresa de turismo tiene un archivo (viajes.dat) con la información de los viajes realizados en el año 2017.
 Cada registro contiene los siguientes campos:
Código de ciudad (char[5]), fecha (día, mes y año), tipo de transporte (‘C’: común; ‘E’: especial) , y
cantidad de pasajeros.
Hacer un programa para informar el mes que haya registrado

mayor cantidad de pasajeros para la ciudad “mdq”.
*/
# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>

using namespace std;
struct Fecha{
int dia, mes, anio;
};
struct Viaje{
char codCiudad[5];
Fecha fe;
char tipo;
int cantidad;
};
 int buscarMaximo(int *, int);
 void puntoA();


void puntoA(){
      FILE *p;
    Viaje reg;
    int mayor, mes[12]={0};

    p=fopen("viajes.dat", "ab");
    if(p==NULL){cout<<"fallo la aperturda del archivo. "; return ;}
    while(fread(&reg, sizeof(Viaje), 1, p)){
        if(strcmp(reg.codCiudad, "mqd")==0){
               mes[reg.fe.mes-1]+=reg.cantidad;
       }

    }
    fclose(p);
    mayor= buscarMaximo(mes, 12);
    cout<<"el mes con mayor cantidad de pasajes a MQD fue: "<<mayor;
}
int buscarMaximo(int v[], int tam){
    int mes, maximo=0;
    for(int i=0;i <tam; i++){
            maximo=v[i];
        if(v[i]>maximo){
            maximo=v[i];
            mes=i+1;
        }
    }
    return mes;
}
int main (){
puntoA();

return 0;
}
