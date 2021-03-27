#ifndef PELUQURIA_H_INCLUDED
#define PELUQURIA_H_INCLUDED
///PROTOTIPOS
Tintura leerRegistro(int );

int contarRegistros();
int contarRegistros(int, int);
int buscarCodigo(int codigo);
int buscarMenor(int *, int);
void ordenarVector(int *, int );
void puntoA();
void puntoB();
void puntoC();
void puntoD();
void puntoe();



///FIN PROTOTIPOS
int contarRegistros(){}
int contarRegistros(int, int){}
int buscarCodigo(int codigo){}
void ordenarVector(int *v, int tam ){
    int posmin, i, j, aux;
    for(i=0; i<tam-1; i++ ){
            posmin=i;
        for(j=i+1;j<tam; j++){
                if(v[posmin]>v[j]){
                    posmin=j;
                }
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

int buscarMenor(int *v, int tam){
    int pos=0, menor=0;
    for(int i = 0; i<tam;i++){
        if(v[i]<menor){
            menor=v[i];
            pos=i;
        }
    }
    return pos;
}
void puntoA(){
    FILE *p;
    Tintura reg;
    int codigoTint[36]={0};
    p= fopen("color.dat", "ab");
    if(p==NULL){return;}
    while(fread(&reg, sizeof(Tintura), 1, p)){
       // reg=leerRegistro(pos);
        if(reg.fTintura.mes==3) {
            codigoTint[reg.codigo-100]++;
        }
    }
    fclose(p);

    ordenarVector(codigoTint, 36);
    for(int i=0;i<36;i++){
        if(codigoTint[i]>9){
            cout<<"el codigo : "<<i+100<<" tuvo 10 o mas registros en el mes de marzo "<<endl;
        }
    }
}
void puntoB(){
     FILE *p;
    Tintura reg;
    int codigoTint[36]={0};
    p= fopen("color.dat", "ab");
    if(p==NULL){return;}
    while(fread(&reg, sizeof(Tintura), 1, p)){
        codigoTint[reg.codigo-100]++;
    }
    fclose(p);
    ordenarVector(codigoTint, 36);
     cout<<"el codigo menos usado es : "<<buscarMenor(codigoTint, 36)+100<<""<<endl;


}
void puntoC(){
    FILE *p;
    Tintura reg;
    int dias[31]={0};
    p= fopen("color.dat", "ab");
    if(p==NULL){return;}
    while(fread(&reg, sizeof(Tintura), 1, p)){
            if(reg.fTintura.mes!=1){
                dias[reg.fTintura.dia-1]++;
            }
    }
    fclose(p);
    for(int i=0; i<31;i++){
            if(dias[i]==0) cout<<"para el dia : "<<i+1<<" tuvo la cantidad de: " <<dias[i]<<endl;
    }
}
void puntoD(){}
void puntoe(){}

#endif // PELUQURIA_H_INCLUDED
