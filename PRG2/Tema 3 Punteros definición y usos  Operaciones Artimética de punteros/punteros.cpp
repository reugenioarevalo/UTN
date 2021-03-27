/** clase por youtube https://www.youtube.com/watch?v=gLor_8rgQqY&feature=youtu.be*/
#include <iostream>
using namespace std;

void cambiarValor(int *x){
    *x=23;
}
void cargarVector(int  *v, int tam){
    for(int i=0; i <tam; i++){
        v[i]=i+1;
    }
}
void mostrarVector(int *v, int tam){
    for(int i=0; i <tam; i++){
        cout<<v[i]<<endl;
    }
}

int main (){

int v[5], *p, t=5; //el puntero almacena la direccion de memoria

cout<<"valor de t: "<<t<<endl;
cout <<"\n direccion de  t mostrando con & :" <<&t<<endl;
p=&t; //asigancion de la dfireccion de t a la variable puntero p.

cout<<" Valor de la  variable p (es una direccion) : "<<p<<endl;
cout<<" Contenido de  la variable puntero p se le asigno la variable t : "<<*p<<endl;
*p=15; //altero el contenido de la variable que almacena el puntero p, osea altero t.
cout<<" Contenido de  la variable puntero p se le asigno la variable t : "<<*p<<endl;
cout<<"valor de t: "<<t<<endl;


/*usamos una funcion y pasamos la direccion de t por parametros para qeu luego la
alteremos con un puntero
*/
cambiarValor(&t); //parametro por referencia o direccion
cout<<"valor de t luego de pasar por la funcion cambiarValor() : "<<t<<endl;
cout<<v<<endl; //el nombre de un vector es una direccion de memoria.


//cargar un vector
cargarVector(v, 5);
mostrarVector(v, 5);
return 0;
}
