/*
2) Una pinturería tiene un archivo con la información de sus productos (productos.dat) con el siguiente formato:
Código de producto (int), nombre (char[30]), tipo de pintura (char[5]), precio unitario, stock
y estado (1= registro activo; 0: registro inactivado o borrado)
La empresa ha decidido incrementar los precios de toda la línea de productos que sean de tipo de pintura “hdqk” un 12%,
por lo que se pide se desarrolle una función que actualice el precio unitario de todos los registros de ese tipo
*/
# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>

using namespace std;

struct Producto{
int codigo;
char descri[30];
char tipoPintura[5];
float precio;
int stock;
bool estado;
};

 void puntoA();


void puntoA(){
      FILE *p;
    Producto reg;
   int aumento= 1.12;
    p=fopen("productos.dat", "rb+");
    if(p==NULL){cout<<"fallo la aperturda del archivo. "; return ;}
    while(fread(&reg, sizeof(Producto), 1, p)){
        if(strcmp(reg.tipoPintura, "hdqk")==0){
               reg.precio=reg.precio*aumento;
               fseek(p, -sizeof(Producto), 1);//retrocedo para posicionarme en el registro
                fwrite(&reg, sizeof reg, 1, p);// y como estoy con rb+ lo grabo
                fseek(p, sizeof(Producto), 1);//y avanzo un registro mas
       }
    }
    fclose(p);
}

int main (){
puntoA();

return 0;
}
