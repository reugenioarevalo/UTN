
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
    bool operator ==(Fecha);
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
bool Fecha::operator ==(Fecha _f){
    if(dia!=_f.dia)return false;
    if(mes!=_f.mes)return false;
    if(anio!=_f.anio)return false;
    return true;
}
bool int::operator ==(int aux){
    if(mes==aux)return true;
    return false;
}
int main(){
    Fecha a, b;
    a.Cargar();
    b.Cargar();

    if(a==b){
        cout<<"IGUALES";
    }else{
        cout<<"DISTINTOS";
    }


    return 0;
}
