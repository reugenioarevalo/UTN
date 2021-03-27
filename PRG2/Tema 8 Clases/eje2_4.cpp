#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

    void puntoA();
    void puntoB();
float sumarToneladas(int  );
void mostrarMatriz(int [][12]);
class Fecha{
private:
    int dia, mes, anio;
    public:
        int getAnio(){return anio;}
        int getMes(){return mes;}
};
class Cereal{
    private:
        int codCereal;
        char nombre[30];
        float importe;

    public:
        int getCodigoCereal(){return codCereal;}
        const char  *getNombre(){return nombre;}
        bool leerDeDisco(int );

};
class Cosecha{
private:
    int numeroCosecha, codigoCereal;
    float cantidadToneladas;
     Fecha fechaCosecha;
public:
    int  getCodigoCereal(){return  codigoCereal;}
    float getCantidad(){return cantidadToneladas; }
    Fecha getFechaCosecha(){return fechaCosecha;}
    bool leerDeDisco(int);
};
class CantidadCereal{
     private:
        int codCereal;
        char nombre[30];
        float cantidadToneladas;
    public:
        void setCodigoCereal(int cc){ codCereal= cc;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setCantidad(float c){ cantidadToneladas= c;}
        bool  grabarEnDisco();

};

int main (){

    puntoA();
    puntoB();

return 0;
}
bool Cereal::leerDeDisco(int pos){
            FILE *p;
            p=fopen("Cereal.dat", "rb");
            if(p==NULL){return false;}
            fseek(p, pos*sizeof*this, 0);
            bool leyo= fread(this, sizeof*this, 1, p);
            fclose(p);
            return leyo;
}
bool Cosecha::leerDeDisco(int pos){
            FILE *p;
            p=fopen("Cosecha.dat", "rb");
            if(p==NULL){return false;}
            fseek(p, pos*sizeof*this, 0);
            bool leyo= fread(this, sizeof*this, 1, p);
            fclose(p);
            return leyo;
}
bool  CantidadCereal::grabarEnDisco(){
    FILE *p;
    p=fopen("CantidadCereal.dat", "ab");
    if(p==NULL){return false;}
    bool grabo= fwrite(this, sizeof *this, 1,p);
    fclose(p);
    return grabo;
}

void puntoA(){
    int pos=0;
    Cereal obj;
    CantidadCereal aux;
    while(obj.leerDeDisco(pos++)){
        aux.setCodigoCereal(obj.getCodigoCereal());
        aux.setNombre(obj.getNombre());
        aux.setCantidad(sumarToneladas(obj.getCodigoCereal()));

    }
}
float sumarToneladas(int cc ){
        Cosecha reg;
        int  pos = 0;
        float cant=0;
        while(reg.leerDeDisco(pos++)){
            if(reg.getFechaCosecha().getAnio()==2019
               && reg.getCodigoCereal()==cc){
                cant+=reg.getCantidad();
               }
        }
        return cant;
}
void puntoB(){
    Cosecha reg;
    int pos=0;
    int m[20][12]={0};
    while(reg.leerDeDisco(pos++)){
        if(reg.getFechaCosecha().getAnio()==2019){
            m[reg.getCodigoCereal()-1][reg.getFechaCosecha().getMes()-1]++;
        }
    }
    mostrarMatriz(m);
}
void mostrarMatriz(int m[][12]){
    for(int i=0; i<20;i++){
            for(int j=0; j<12;){
                   cout<<m[i][j]<<"\t";
            }
        cout<<endl;
        }
}
