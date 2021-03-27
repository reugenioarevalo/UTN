/* B)
1) El Servicio Meteorológico tiene un archivo (mediciones.dat) con la información del clima en distintas ciudades del país.
Cada registro contiene los siguientes campos:
Código de ciudad (char[5]), fecha (día, mes y año), temperatura máxima, temperatura mínima
y cantidad de mm de lluvia.
Hacer un programa para informar el mes que haya registrado mayor cantidad de lluvia en el año 2017.
*/
# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>

using namespace std;
struct fecha{
    int dia, mes, anio;
};

struct Ciudad{
char codigo[5];
fecha fe;
int tempMax, tempMin, cantLluvia;
};

void puntoA();
int  buscarMaximo(int *, int);

void puntoA(){
    int v[12]={0};
    int mesConMasLluvias;
    FILE *p;
    Ciudad reg;
    p=fopen("mediciones.dat", "rb");
    if(p==NULL) cout<<" fallo el arcvhio ";return;
    while(&reg, sizeof(Ciudad), 1, p){

            if(reg.fe.anio==2017){
                v[reg.fe.mes-1]+=reg.cantLluvia;
            }
    }
    fclose(p);
    mesConMasLluvias=buscarMaximo(v, 12);

    cout<<"El mes con mas lluvia del año 2017 fue: "<<mesConMasLluvias;
}
int  buscarMaximo(int *v, int tam){
    int mes, maximo=0;
    for(int i=0; i<tam; i++){
        if(v[i]>maximo){
            maximo=v[i];
            mes=i+1;
        }
    }
}

int main (){
puntoA();

return 0;
}
