//Ejercicio: CLASE PRA MANEJO DE ARCHIVOS
//Autor:DEK
//Fecha:07/06/2013
//Comentario:USA UNA CLASE ABSTRACTA Y OBLIGA A HEREDAR DE ELLA

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
//Registro
//Clase base abstracta Registro.
//Todas las clases que se quieran utilizar con la clase Archivo
//deben derivar de ella, y se obliga a redefinir los métodos virtuales
//en cada clase.
//La idea fue aportada por Brian Lara Campos

class Registro{
  public:
      virtual void Cargar()=0;
      virtual void Mostrar()=0;
      virtual int getSize()=0;//DEVUELVE EL SIZEOF DEL OBJETO
      virtual Registro& operator = (Registro *) =0;//SOBRECARGA PARA ASIGNAR UN PUNTERO REGISTRO A UNA REFERENCIA A UN OBJETO DE UNA CLASE DERIVADA DE REGISTRO
      virtual bool comparaID(Registro*)=0;// SE SUPONE QUE CADA CLASE TIENE UNA PROPIEDAD QUE
  };                                      // IDENTIFICA A CADA OBJETO (UN PROPIEDAD CLAVE)
     //COMO ESA IDENTIFICACION UNICA (ID) PUEDE SER DE DISTINTO TIPO SE DEBE HACER UN METODO
      //PARA COMPARAR EL VALOR DE LA PROPIEDAD CLAVE ENTRE DISTINTOS OBJETOS


//////////CLASE ARTICULO
class Articulo:public Registro{

	private://PROPIEDADES
          char codArt[5];
          char desc[30];
          float pu;
          int stock;
          bool activo;
	public: //METODOS
          Articulo(const char *, const char *,float, int);     //Constructor
          Articulo(float, int);//Constructor
          char * getCodArt(){return codArt;}
          char * getDesc(){return desc;}
          void setPu(float p) {pu=p;}
          //METODOS REDEFINIDOS HEREDADOS DE REGISTRO
          void Cargar();
          void Mostrar();
          int getSize(){return sizeof *this;}
          int getStock(){return stock;}
          Articulo& operator = (Registro *temp){
            Articulo *aux=(Articulo *)temp;
            strcpy(this->codArt,aux->codArt);
            strcpy(this->desc, aux->desc);
            pu=aux->pu;
            stock=aux->stock;
            activo=aux->activo;
            }
          bool comparaID(Registro *temp){
            Articulo *aux=(Articulo *)temp;
            if(strcmp(aux->codArt,codArt)==0) return true;
            return false;
            };
};

Articulo::Articulo(const char *c="HOLA", const char *d="CHAU",float p=0.0, int s=0)
{
  strcpy(codArt, c);
  strcpy(desc, d);
  pu=p;
  stock=s;
}

Articulo::Articulo(float p, int s=0)
{
  pu=p;
  stock=s;
}

void Articulo::Cargar()
{
  cout<<"Ingrese el Codigo: ";
  cin>>codArt;
  cout<<"Ingrese la descripcion: ";
  cin.ignore();
  cin.getline(desc,30);
  cout<<"Ingrese el precio: ";
  cin>>pu;
  cout<<"Ingrese el stock disponible: ";
  cin>>stock;
  }

void Articulo::Mostrar()
{
  cout<<"Codigo del Articulo: "<<codArt<<endl;
  cout<<"Descripcion del Articulo: "<<desc<<endl;
  cout<<"Precio unitaro del Articulo: "<<pu<<endl;
  cout<<"Stock disponible: "<<stock<<endl;
}
/////////////

//////////CLASE CLIENTE
class Cliente:public Registro{

	private://PROPIEDADES
          int codCli;
          char nombre[30];
          char direccion[40];
          bool activo;
	public: //METODOS
          int getCodCli(){return codCli;}
          char * getNombre(){return nombre;}
          char * getDireccion(){return direccion;}
          //METODOS REDEFINIDOS HEREDADOS DE REGISTRO
          void Cargar();
          void Mostrar();
          int getSize(){return sizeof *this;}
          Cliente& operator = (Registro *temp){
            Cliente *aux=(Cliente *)temp;
            strcpy(this->nombre,aux->nombre);
            strcpy(this->direccion, aux->direccion);
            codCli=aux->codCli;
            activo=aux->activo;
            }
          bool comparaID(Registro *temp){
            Cliente *aux=(Cliente *)temp;
            if(codCli==aux->codCli) return true;
            return false;
            }
         };


void Cliente::Cargar()
{
  cout<<"Ingrese el Codigo: ";
  cin>>codCli;
  cout<<"Ingrese el nombre: ";
  cin.ignore();
  cin.getline(nombre,30);
  cout<<"Ingrese direccion: ";
  cin.getline(direccion,40);
  }

void Cliente::Mostrar()
{
  cout<<"Codigo del Cliente: "<<codCli<<endl;
  cout<<"Nombre: "<<nombre<<endl;
  cout<<"Direccion: "<<direccion<<endl;
  }

///////////////////////////
//TIPOS ENUMERADOS PARA USAR CON LA CLASE ARCHIVO
enum Estado{//DEFINE LOS ESTADOS EN LOS QUE PUEDE ESTAR EL ARCHIVO
  NoExiste,
  Cerrado,
  AbiertoR,
  AbiertoW,
  AbiertoA,
  AbiertoRW
  };

 enum Modo{//DEFINE LOS MODOS DE APERTURA DE UN ARCHIVO
   SoloLectura,
   Escritura,
   Agregar,
   LecturaEscritura
   };

/////////////
//DEFINICIONES CLASE ARCHIVO
//Los registros del archivo deben ser objetos de clases
//derivadas de la clase registro
//
//Los métodos reciben una referencia a un objeto Registro.
//A partir de esta referencia, que representará a un objeto
//de alguna clase derivada de Registro, se consigue la especificidad
//de cada archivo.
//
//Todos los métodos abren y cierran el archivo de acuerdo
//a lo que sea necesario. No se pueda abrir el archivo desde fuera de la clase
///////////////////////////////////
class Archivo{
  private:
    FILE *pF;
    int tamanioRegistro;
    void *pRegistro;
    char *nombreArchivo;
    int cantRegistros;
    int estado;
    int cantidadRegistros(){
      if(!abrirArchivo(SoloLectura)){
         estado=Cerrado;
         return 0;
        }
      fseek(pF,0,2);
      long cant=ftell(pF)/tamanioRegistro;
      cerrarArchivo();
      return (int) cant;
      }
    bool abrirArchivo(Modo modo);
    void Archivo::cerrarArchivo(){
      fclose(pF);
      estado=Cerrado;
      }

  public:
    Archivo(const char *nombre, int tam){
      nombreArchivo=new char[strlen(nombre)+1];
      if(nombreArchivo==NULL)exit(1);
      strcpy(nombreArchivo,nombre);
      tamanioRegistro=tam;
      pRegistro=(void *)malloc(tamanioRegistro);
      cantRegistros=cantidadRegistros();
      estado=Cerrado;
      }
    ~Archivo(){
      delete nombreArchivo;
      if(pF)fclose(pF);
      free(pRegistro);
      }

      int leerRegistro(Registro &,int );
      int buscarRegistro(Registro &);
      int grabarRegistro( Registro & , int);

      int alta(Registro &);
      const char *getNombreArchivo(){return nombreArchivo;}
      int getCantidadRegistros(){return cantRegistros;}
      bool listarArchivo(Registro &aux);
  };

//leerRegistro(Registro &var, int pos)
//LEE EL REGISTRO UBICADO EN LA POSICIÓN pos, Y LO ESCRIBE EN LA REFERENCIA var
//DEVUELVE 1 SI LEYO; 0 SI NO LEYO; -1 SI EL ARCHIVO NO EXISTE
int  Archivo::leerRegistro(Registro &var, int pos){
       int x;
       if(!abrirArchivo(SoloLectura)){
         return -1;
       }
        fseek(pF,pos*var.getSize(),0);
        x=fread(pRegistro,var.getSize(),1,pF);
        fclose(pF);
        var=(Registro *)pRegistro;
        cerrarArchivo();
        return x;
       }

//grabarRegistro( Registro &dato, int pos).
//ESCRIBE EN EL DISCO LOS DATOS EXISTENTES EN LA REFERENCIA dato
//SI EL VALOR DE POS ES -1 AGREGA UN REGISTRO NUEVO
// SI EL VALOR ES 0 O POSITIVO SOBREESCRIBE EL REGISTRO UBICADO EN ESA POSICION
//DEVUELVE 1 SI GRABO; -1 SI NO EXISTE; 0 SI NO PUDO GRABAR
int Archivo::grabarRegistro( Registro &dato, int pos){
      int grabo;
      if(pos==-1){
        if(!abrirArchivo(Agregar)){
        cout<<"no pudo abrir en AB"<<endl;
        system("pause");
        return -1;
        }
      }
      else{
        if(!abrirArchivo(LecturaEscritura)){
          return -1;
          }
        fseek(pF,pos*tamanioRegistro,0);
      }
      grabo=fwrite(&dato,tamanioRegistro,1,pF);
      cerrarArchivo();
      if(grabo &&pos==-1)  cantRegistros++;
      return grabo;
    }

//alta(Registro &obj)
//AGREGA UN REGISTRO AL ARCHIVO
//VALIDA EL CAMPO CLAVE
//DEVUELVE -1 SI NO PUDO ABRIR EL ARCHIVO, 1 SI GRABO, 0 SI NO GRABO Y -2 SI SE REPITE EL CODIGO
int Archivo::alta(Registro &obj){
  int grabo;
  if(!abrirArchivo(Agregar)){
    return -1;
  }
  system("cls");
  cout<<"ALTA DE REGISTRO"<<endl;
  obj.Cargar();
  int pos=buscarRegistro(obj);
  if(pos==-1){
    grabo=grabarRegistro(obj,-1);
    cerrarArchivo();
    return grabo;
    }
  else{
    cout<<"YA EXISTE EL CODIGO"<<endl;
    cout<<"NO SE GRABO EL REGISTRO"<<endl;
    system("pause");
    }
  return -2;
  }
//listarArchivo(Registro &aux)
//LISTA EL ARCHIVO COMPLETO
bool Archivo::listarArchivo(Registro &aux){
       if(cantRegistros==0)return false;
       if(!abrirArchivo(SoloLectura)){
         return false;
       }
       while(fread(pRegistro,tamanioRegistro,1,pF)){
         aux=(Registro *)pRegistro;
         aux.Mostrar();
         };
       cerrarArchivo();
       return true;
    }


//buscarRegistro(Registro &obj)
//COMPARA EL CAMPO CLAVE DEL REGISTRO RECIBIDO COMO PARAMETRO
//CON LOS REGISTROS DEL ARCHIVO.
//SI YA EXISTE EL VALOR DEL CAMPO CLAVE DEVUELVE LA POSICIÓN QUE OCUPA EN EL ARCHIVO
//SI NO LO ENCUENTRA DEVUELVE -1, Y SI NO PUDO ABRIR EL ARCHIVO DEVUELVE -2
int Archivo::buscarRegistro(Registro &obj){
       if(!abrirArchivo(SoloLectura)){
         return -2;
       }
       while(fread(pRegistro,tamanioRegistro,1,pF)){
            if(obj.comparaID((Registro*)pRegistro)){
              int pos=(ftell(pF)-tamanioRegistro)/tamanioRegistro;
              cerrarArchivo();
              return pos;
            }
         };
       cerrarArchivo();
       return -1;
      }


//abrirArchivo(Modo modo)
//ABRE EL ARCHIVO EN EL MODO ESTABLECIDO POR EL PARAMETRO modo.
//DEVUELVE TRUE SI PUDO ABRIR Y FALSE SI NO PUDO ABRIR
bool Archivo::abrirArchivo(Modo modo){
  switch(estado){
    case AbiertoR:
    case AbiertoW:
    case AbiertoA:
    case AbiertoRW:cerrarArchivo();
                    break;
    }
  switch(modo){
      case SoloLectura:
                      pF=fopen(nombreArchivo,"rb");
                      if(!pF)return false;
                      estado=AbiertoR;
                      break;
      case Escritura:
                      pF=fopen(nombreArchivo,"wb");
                      if(!pF)return false;
                      estado=AbiertoW;
                      break;
      case Agregar:
                      pF=fopen(nombreArchivo,"ab");
                      if(!pF) return false;
                      estado=AbiertoA;
                      break;
      case LecturaEscritura:
                      pF=fopen(nombreArchivo,"rb+");
                      if(!pF)return false;
                      estado=AbiertoRW;
                      break;

    }
    return true;
  }





int main()
{
Archivo clientes("clientes.dat",sizeof(Cliente));
Archivo articulos("articulos.dat",sizeof(Articulo));

Articulo regArt;
regArt.Cargar();
int x=articulos.grabarRegistro(regArt,-1);
if(x==1){
  cout<<"SE GRABO EL REGISTRO"<<endl;
  }
else{
  cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
  }
system("pause");
articulos.alta(regArt);
if(!articulos.listarArchivo(regArt)){
  cout<<"NO HAY REGISTROS PARA LISTAR"<<endl;
  system("pause");
  }
system("pause");

Cliente regCli;
clientes.alta(regCli);
if(!clientes.listarArchivo(regCli)){
  cout<<"NO HAY REGISTROS PARA LISTAR"<<endl;
  system("pause");
  }
cout<<endl<<endl;
system("pause");
return 0;
}


