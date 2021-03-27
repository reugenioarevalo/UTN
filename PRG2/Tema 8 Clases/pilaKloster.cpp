
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
class Pila{
private:
    int  tam, tope;
    int *p;
public:
    Pila(int t=2){
        tam=t;
        p=new int[t];
        if(p==NULL){return;}
        for(int i=0; i<tam;i++){
                p[i]=-1;
            }
            tope=0;
    }
    ~Pila(){
        delete p;
    }
    void mostrar(){
        int i;
        for(i=0; i<tam;i++){
            cout<<p[i]<<endl;
        }
    }
    bool agregar(int  x){
        if(tope==tam)return false;
        //si tope igual al tamaño es porque esta llena.
        //se agrega solo si no está llena osea debe preguntarse
        //si se puede agregar
        p[tope]=x;
        tope++;
        return true;
    }
    bool sacar(int &x){
        if(tope==0)return false;
        tope--;
        x=p[tope];
        return true;
    }
};
int main (){
    int valor;
    Pila p(5);
   // p.mostrar();
   if(p.sacar(valor))cout<<valor<<endl;
   else cout<<"No se puede sacar porque esta vacia."<<endl;
    p.agregar(14);
    p.mostrar();
    if(p.sacar(valor))cout<<"quitamos el : "<<valor<<endl;
   else cout<<"No se puede sacar porque esta vacia."<<endl;
    p.agregar(22);
    p.agregar(23);
    p.agregar(24);
    p.agregar(25);
    p.agregar(26);
    p.mostrar();
    while(p.sacar(valor)) cout<<"quitamos el : "<<valor<<endl;
      if(p.sacar(valor))cout<<"quitamos el : "<<valor<<endl;
   else cout<<"pila vacia."<<endl;
return 0;
}
