/* B)
2) Una empresa que comercializa pintura tiene un archivo con la información de sus productos (productos.dat)
 con el siguiente formato:
Código de producto (int), nombre (char[30]), tipo de pintura (char[5]), precio unitario, stock
y estado (1= registro activo; 0: registro inactivado o borrado)
La empresa ha decidido dejar de trabajar con toda la línea de productos que sean de tipo de pintura “ab14”,
por lo que se pide se desarrolle una función que dé de baja lógica todos los registros de ese tipo.
*/
# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>

using namespace std;
struct Pintura{
    int  codProd;
    char desc[30];
    char tipoPintura[5];
    float precio;
    int  stock;
    int estado;
};

void puntoA();
bool darBajaRegistro(Pintura, int);
 int cantidadRegitros();
 Pintura leerRegistro(int  );
int main (){
puntoA();
return 0;
}

void puntoA(){
    FILE *p;
    Pintura reg;
    int cantReg= cantidadRegitros();

    p=fopen("productos.dat", "rb");
    if(p==NULL){cout<<"fallo:"; return;}

    for(int i=0; i<cantReg;i++){
        reg=leerRegistro(i);
        if(strcmp(reg.tipoPintura, "ab14")==0){
            reg.estado=0;
            darBajaRegistro(reg, i);
        }

    }
    fclose(p);
}
bool darBajaRegistro(Pintura reg, int pos){
    FILE *p;
    bool grabo;
    p=fopen("alumnos.dat", "rb+");
    if(p==NULL)return false;
    fseek(p, sizeof(Pintura)*pos, 0);
    grabo=fwrite(&reg, sizeof(Pintura), 1, p);
    fclose(p);
    return grabo;
}
 int cantidadRegitros(){
    int cant, bytes;
    FILE *p;
    p=fopen("productos.dat", "rb");
    if(p==NULL){return -1;}
        fseek(p, 0, SEEK_END);
        bytes = ftell(p);
        cant = bytes / sizeof(Pintura);
        fclose(p);
        return cant;
 }
Pintura leerRegistro(int  pos){
    FILE *p;
    Pintura reg;
    reg.estado=false; //por si fallase el registro lo devuelvo en falso.
    p=fopen("alumnos.dat", "rb");
    if(p==NULL)    {return reg; }
    fseek(p, pos*sizeof(Pintura), 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}
