//Ejercicio:
//Autor:DEK
//Fecha:
//Comentario:

#include <iostream>
#include <cstdlib>

using namespace std;

struct punto{
  int x,y;
};

void cargar(punto [], int);

void mostrar(punto *, int);



int main(){
    punto *v;
    int cant, cantidadBytes;
    cout<<"INGRESE LA CANTIDAD DE ELEMENTOS DEL VECTOR: ";
    cin>>cant;
    ///PEDIR MEMORIA ->malloc()
    cantidadBytes=cant*sizeof(punto);
    v=(punto*) malloc(cantidadBytes);
    if(v==NULL){
      cout<<"PROBLEMA AL ASIGNAR MEMORIA"<<endl;
      return -8;
    }

    ///void * malloc(size_t);
    cargar(v, cant);
    mostrar(v, cant);

    system("pause");
    ///LIBERAR LA MEMORIA ->free()
    free(v);
    return 0;
}

void cargar(punto *p, int tam){
  int i;
  for(i=0;i<tam;i++){
      p[i].x=i+1;
      p[i].y=i+3;
  }
}

void mostrar(punto *p, int tam){
  int i;
  for(i=0;i<tam;i++){
        cout<<p[i].x<<","<<p[i].y<<endl;
    }
  }


