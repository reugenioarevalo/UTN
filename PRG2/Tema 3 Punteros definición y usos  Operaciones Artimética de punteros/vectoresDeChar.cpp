/** clase por youtube  https://youtu.be/gLor_8rgQqY?t=1373*/
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void cargarVectorC(char  *v, int tam){
    int  i;
    for(i=0; i<tam; i++){
         v[i]='a' + i;
    }
}

void mostrarVectorC(char  *v, int tam){
    int i;
    for(i=0; i<tam; i++){
        cout<<v[i]<<endl;
    }
}


int main (){
char palabra[20];

cargarVectorC(palabra, 10);
mostrarVectorC(palabra, 10);
return 0;
}
