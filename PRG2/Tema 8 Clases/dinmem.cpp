
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
class Cadena{
    private:
        char *palabra;
        int tam;
    public:
        Cadena(const char *cad="Valor por omision" ){
            tam=strlen(cad)+1;
            palabra =new char[tam];
            if(palabra==NULL){return;}
            strcpy(palabra, cad);
        }
        const char *getPalabra(){return palabra;}
        void setPalabra(const char  *aux){
            delete palabra;/// elimino lo q traia
            tam = strlen(aux)+1;// busco el tamanio de la nueva cadena
            palabra =new char[tam]; ///pido otra vez memoria
            if(palabra==NULL){return;}//evaluo
            strcpy(palabra, aux);


        }

         ~Cadena(){delete palabra;}
};
int main (){
    Cadena obj(" cargando valor "), reg;
    cout<<" cargando en el constructor : "<<obj.getPalabra()<<endl;

    cout<<" valor por omision : "<<reg.getPalabra()<<endl;

    reg.setPalabra("que onda??");
    cout<<" cargando con el seter  : "<<reg.getPalabra()<<endl;
//    int *v;
//        v=new int[5];
//        if(v==NULL){return -1;}
// v[0]=15;
// cout<<" tiene el valro : "<<v[0];
//    delete v;

//        Cliente *v;
//        v=new Cliente[5];
//        if(v==NULL){return -1;}
//        v[0].Cargar();
//        v[0].Mostrar();
//        delete v;

//        Cliente (*v)[3];
//        v=new Cliente[5][3];
//        if(v==NULL){return -1;}
//         delete v;

return 0;
}
