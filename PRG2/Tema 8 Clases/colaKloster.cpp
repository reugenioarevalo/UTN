
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
typedef int info;//info es un alias de int
class Cola{
private:
    info *p;
    int  pcio, fin, tam;
public:
    Cola(int);
    bool agregar(info);
    bool sacar(info &);
    ~Cola();

};
    Cola::Cola(int cant=1 ){
        tam=cant;
        pcio=fin=0;
        p=new info[tam];
        if(p==NULL)exit(1);
   }
    Cola::~Cola(){
        if(p!=NULL){delete p;}
    }
    bool Cola::agregar(info  x){
        if(tam==fin)return false;
         p[fin]=x;
        fin++;
        return true;
    }
    bool Cola::sacar(info &aux){
        if(pcio==fin)return false;
         aux=p[pcio];
         pcio++;
        return true;
    }

int main (){
    info valor;
    Cola p(5);
    for(int i=0; i<5; i++){
            cout<<"\n ingrese un numero :";
        cin>>valor;
        p.agregar(valor);
    }
   info sacar;
    while(p.sacar(sacar)) cout<<"quitamos de la cola el : "<<sacar<<endl;
      if(p.sacar(sacar))cout<<"quitamos el : "<<sacar<<endl;
   else cout<<"cola vacia."<<endl;
return 0;
}
