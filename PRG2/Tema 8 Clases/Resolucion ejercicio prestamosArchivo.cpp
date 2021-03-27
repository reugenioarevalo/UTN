//Ejercicio: Ejercicio tipo parcial 2
//Autor:DEK
//Fecha:1/07/2020
//Comentario:

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;


class Fecha{
    private:
        int dia, mes, anio;
    public:
        int getDia(){return dia;}
};

class Cliente{
    private:
        char CUIT[12];
        char nombre[30];
        int categoria;
    public:
        int getCategoria(){return categoria;}
        const char *getCUIT(){return CUIT;}
        const char *getNombre(){return nombre;}
        bool leerDeDisco(int pos);
};

bool Cliente::leerDeDisco(int pos){
    FILE *p;
    p=fopen("clientes.dat", "rb");
    if(p==NULL) return false;
    fseek(p, sizeof(Cliente)*pos, 0);
    bool leyo=fread(this, sizeof(Cliente),1,p);
    fclose(p);
    return leyo;
}

class Prestamo{
    private:
        int numeroPrestamo;
        int codigoBanco;
        char CUIT[12];
        float importe;
        int plazo;
        Fecha fechaPrestamo;
    public:
        const char *getCUIT(){return CUIT;}
        float getImporte(){return importe;}
        bool leerDeDisco(int pos);
        void setFechaPrestamo(Fecha f){fechaPrestamo=f;}
};

bool Prestamo::leerDeDisco(int pos){
    FILE *p;
    p=fopen("prestamos.dat", "rb");
    if(p==NULL) return false;
    fseek(p, sizeof(Prestamo)*pos, 0);
    bool leyo=fread(this, sizeof(Prestamo),1,p);
    fclose(p);
    return leyo;
}

class Prestamo_2019{
    private:
        char CUIT[12];
        char nombre[30];
        float importe;
    public:
        Prestamo_2019(){
            importe=0;
        }
        void setCUIT(const char *c){strcpy(CUIT,c);}
        void setNombre(const char *n){strcpy(nombre,n);}
        void setImporte(float i){importe=i;}
        bool grabarEnDisco();
        float getImporte(){return importe;}
        const char *getCUIT(){return CUIT;}
};

bool Prestamo_2019::grabarEnDisco(){
    FILE *p;
    p=fopen("pre_2019.dat", "rb");
    if(p==NULL) return false;
    bool grabo=fwrite(this, sizeof(Prestamo_2019),1,p);
    fclose(p);
    return grabo;
}

///para evitar que se dupliquen los registros en el archivo nuevo
crearArchivo(){
    FILE *p;
    p=fopen("pre_2019.dat","wb");
    if(p==NULL) return false;
    fclose(p);
    return true;
}

void puntoA();
    float sumarCreditos(const char *);
void puntoB();
     mostrarVector(int *cat){};

void puntoADinamico();/// se lee solo una vez cada archivo
    int contarRegistrosCliente();
    void copiarClientes(Prestamo_2019 *v);
    int buscarClienteEnVector(const char *c, Prestamo_2019 *p, int cant);
    void generarArchivo(Prestamo_2019 *v, int cant);


int main(){
    if(crearArchivo())return -1;
    puntoA();
    puntoB();
    return 0;
}


void puntoA(){
    Cliente obj;
    int pos=0;
    float total;
    Prestamo_2019 aux;
    while(obj.leerDeDisco(pos++)){
        total=sumarCreditos(obj.getCUIT());
        if(total>0){
            aux.setCUIT(obj.getCUIT());
            aux.setNombre(obj.getNombre());
            aux.setImporte(total);
            aux.grabarEnDisco();
        }
     }
}

float sumarCreditos(const char *c){
    Prestamo reg;
    int pos=0;
    float imp=0;
    while(reg.leerDeDisco(pos++)){
        if(strcmp(c,reg.getCUIT())==0){
            imp+=reg.getImporte();
        }
    }
    return imp;
}

void puntoB(){
    Cliente obj;
    int cat[4]={0}, pos=0;
    while(obj.leerDeDisco(pos++)){
        cat[obj.getCategoria()-1]++;
    }
    mostrarVector(cat);
}


void puntoADinamico(){
    Prestamo_2019 *p;
    int cantReg=contarRegistrosCliente();
    if(cantReg==0) return;
    p=new Prestamo_2019[cantReg];
    if(p==NULL) return;
    copiarClientes(p);
    Prestamo obj;
    int pos=0, posCli;
    while(obj.leerDeDisco(pos++)){
        posCli=buscarClienteEnVector(obj.getCUIT(), p, cantReg);
        if(posCli!=-1) p[posCli].setImporte(p[posCli].getImporte()+obj.getImporte());
    }
    generarArchivo(p, cantReg);
    delete p;
}


int contarRegistrosCliente(){
    FILE *p;
    p=fopen("clientes.dat", "rb");
    if(p==NULL) return 0;
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Cliente);
}

void copiarClientes(Prestamo_2019 *v){
    Cliente obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        v[pos].setCUIT(obj.getCUIT());
        v[pos].setNombre(obj.getNombre());
        v[pos].setImporte(0);
        pos++;
    }
}

int buscarClienteEnVector(const char *c, Prestamo_2019 *p, int cant){
    int i;
    for(i=0;i<cant;i++){
        if(strcmp(c, p[i].getCUIT())==0)
            return i;
    }
    return -1;
}

void generarArchivo(Prestamo_2019 *v, int cant){
    int i;
    for(i=0;i<cant;i++){
        if(v[i].getImporte()>0)
            v[i].grabarEnDisco();
    }
}
///PUNTO 2
/**class MamiferoTerrestre:public Mamifero{
    private:
        int cantidadPatas;
        float velocidad;
    public:
        void Cargar(){
            Mamifero::Cargar();
            cout<<"PATAS: ";
            cin>>cantidadPatas;
            cout<<"VELOCIDAD: ";
            cin>>velocidad;
        }
        void Mostrar(){
            Mamifero::Mostrar();
            cout<<"PATAS: ";
            cout<<cantidadPatas<<endl;
            cout<<"VELOCIDAD: ";
            cout<<velocidad<<endl;
        }

};

*/
