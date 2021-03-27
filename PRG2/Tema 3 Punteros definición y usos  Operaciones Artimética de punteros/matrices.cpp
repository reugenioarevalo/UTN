/**
ejecicio matriz*/
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
void cargarMatriz(int m[5][3], int nf, int nc){
    int i, j;
    for(i=0; i<nf; i++){
        for(j=0; j<nc; j++){
            m[i][j]=i+1;
        }
    }
}

void mostrarMatriz(int m[5][3], int nf, int nc){
    int i, j;
    for(i=0; i<nf; i++){
        for(j=0; j<nc; j++){
           cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main (){
   int  m1[5][3];
cargarMatriz(m1, 5, 3);
mostrarMatriz(m1, 5, 3);
return 0;
}
