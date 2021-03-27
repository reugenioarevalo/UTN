/* C)
1) La Dirección de Tránsito tiene un archivo con las multas realizadas en las 10
localidades del municipio durante 2018. Por cada multa se almacena:
• Código de localidad (1 a 10)
• Tipo de vehículo (1: moto; 2: autos; 3: camionetas: 4: camiones y 5: colectivos)
• Fecha
• Importe
Calcular e informar:
a) La cantidad de multas de cada tipo de vehículo por cada localidad en el mes de marzo.
b) El mes de mayor recaudación del primer semestre
*/
# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>

using namespace std;
struct fecha{int anio, mes, dia;};

struct multas{
    int localidad;
    int tipoCoche;
    fecha fe;
    float importe;
};
void punto1();
void punto2();
void mostraMatriz(int m[][5]);
int  buscarMaximoSemestre2018();
int main (){
punto1();
punto2();
return 0;
}
void punto1(){
    FILE *p;
    multas reg;
    int m[10][5]={0};
//    p=fopen("multas.dat", "rb");
//    if(p==NULL){cout<<"fallo ";return;}
//    while(fread(&reg, sizeof(multas), 1, p)){
//
//        if(reg.fe.anio==2018 && reg.fe.mes==3){
//            m[reg.localidad-1][reg.tipoCoche-1]++;
//        }
//    }
//    fclose(p);
    mostraMatriz(m);
}
void punto2(){}


void mostraMatriz(int m[][5]){
    int col=5;
    int fila=10;
    cout<<"Las multas de marzo por vehiculos segun las localidades son : "<<endl;
    cout<<"Tipo vehiculo:"<<"\t1"<<"\t2"<<"\t3"<<"\t4"<<"\t5"<<endl;
    for(int i=0; i<fila; i++){
            cout<<"localidad: "<<i+1<<"\t";
            for(int j=0; j<col;j++){
                cout<<m[i][j]<<"\t";
            }
            cout<<endl;

    }
}
int  buscarMaximoSemestre2018(){}

