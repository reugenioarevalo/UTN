
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

class Fecha{
private:
    int dia, mes, anio;
public:
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}
    void Cargar();
    void Mostrar();
    bool operator ==(Fecha &);
    bool operator ==(int);
};
void Fecha::Cargar(){
cout<<"DIA: ";
cin>>dia;
cout<<"MES: ";
cin>>mes;
cout<<"ANIO: ";
cin>>anio;
}
void Fecha::Mostrar(){
cout<<"DIA: ";
cout<<dia<<"/";
cout<<mes<<"/";
cout<<anio;
}

bool Fecha::operator ==(Fecha &aux){
    cout<<this<<endl;
    cout<<"esta la direccion de aux "<<&aux<<endl;
    if(dia!=aux.dia)return false;
    if(mes!=aux.mes)return false;
    if(anio!=aux.anio)return false;
    return true;
}

bool Fecha::operator ==(int aux){
    if(mes==aux)return true;
    return false;
}

int main(){
    Fecha a, &b=a;
    a.Cargar();
    //b.Cargar();
    cout<<"direccion de b "<<&b<<endl;
    if(a==b){
        cout<<"IGUALES";
    }else{
        cout<<"DISTINTOS";
    }
   return 0;
}
