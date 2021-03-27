//Ejercicio: Ejercicio tipo parcial 2
//Autor:DEK
//Fecha:6/11/2014
//Comentario:

#include <iostream>
#include <cstdlib>

using namespace std;

class Ruta{
  private:
    char codigoRuta[5];
    char codigoCiudadOrigen[5];
    char codigoCiudadFin[5];
    float longitud;
    int tipoRuta;
    bool peaje;
  public:
    char * getCodigoRuta(){return codigoRuta;}
    char * getCiudadOrigen(){return codigoCiudadOrigen;}
    char * getCiudadFin(){return codigoCiudadFin;}
    float getLongitud(){return longitud;}
    int getTipoRuta(){return tipoRuta;}
    bool leerDeDisco(int);
    };

///
bool Ruta::leerDeDisco(int pos){
  FILE *p;
  bool leyo;
  p=fopen("rutas.dat","rb");
  if(p==NULL) return false;
  fseek(p, sizeof(Ruta)*pos,0);
  leyo=fread(this, sizeof *this,1,p);
  fclose(p);
  return leyo;
  }


class EstadoRuta{
  private:
    int dia, mes, anio;
    char codigoRuta[5];
    int estado;
  public:
    char *getCodigoRuta(){return codigoRuta;}
    int getEstado(){return estado;}
    bool leerDeDisco(int ){};
    int getAnio(){return anio;}
};

class EstadoAnual{
  private:
    char codigoRuta[5];
    int cantDias;
  public:
    void setCodigoRuta(char *cod){strcpy(codigoRuta,cod);}
    void setDias(int _dias){cantDias=_dias;}
    void grabarEnDisco(){
          FILE *p;
          p=fopen("Estadoanual.dat","ab");
          if(p==NULL) return;
          fwrite(this, sizeof(EstadoAnual),1,p);
          fclose(p);
        }
  };


class Ciudad{
  private:
   char codigoCiudad[5];
   char nombreCiudad[30];
   int codigoProvincia;
  public:
    char * getCodigoCiudad(){return codigoCiudad;}
    char * getNombreCiudad(){return nombreCiudad;}
    int getCodigoProvincia(){return codigoProvincia;}
    bool leerDeDisco(int pos){};
    };

class Provincia{
    private:
      int codigoProvincia;
      char nombreProvincia[25];
      char region;
    public:
      int getCodigoProvincia(){return codigoProvincia;}
      char * getNombreProvincia(){return nombreProvincia;}
      bool leerDeDisco(int){};
};

void puntoA();

  Ciudad buscarCiudad(char *c){
    Ciudad obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
      if(strcmp(obj.getCodigoCiudad(),c)==0)
        return obj;
      }
    }

  Provincia buscarProvincia(int cp){
    Provincia obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
      if(obj.getCodigoProvincia()==cp)
        return obj;
      }
    }

void puntoB();
  int contarDiasMal(char *);
void puntoC();
  void ponerCero(int *c){};
  void mostrar(int *c){};

int main(){
  puntoA();
  puntoB();
  puntoC();
  system("pause");
  return 0;
}


void puntoA(){
    Ruta obj, aux;
    Ciudad ciu;
    Provincia prov;
    float max=0;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
      if(obj.getLongitud()>max){
        max=obj.getLongitud();
        aux=obj;
        }
      }
    cout<<"RUTA MAS LARGA: "<<aux.getCodigoRuta()<<endl;
    ciu=buscarCiudad(aux.getCiudadOrigen());
    cout<<"CIUDAD DE ORIGEN: "<<ciu.getNombreCiudad();
    prov=buscarProvincia(ciu.getCodigoProvincia());
    cout<<"PROVINCIA DE ORIGEN: "<<prov.getNombreProvincia();

    ciu=buscarCiudad(aux.getCiudadFin());
    cout<<"CIUDAD DE FIN: "<<ciu.getNombreCiudad();
    prov=buscarProvincia(ciu.getCodigoProvincia());
    cout<<"PROVINCIA DE FIN: "<<prov.getNombreProvincia();
  }


void puntoB(){
  Ruta obj;
  EstadoAnual aux;
  int cantDias, pos=0;
  while(obj.leerDeDisco(pos++)){
    cantDias=contarDiasMal(obj.getCodigoRuta());
    if(cantDias>0){
      aux.setCodigoRuta(obj.getCodigoRuta());
      aux.setDias(cantDias);
      aux.grabarEnDisco();
      }
    }
  }

void puntoC(){
  Ruta obj;
  int tipoRuta[5], pos=0;
  ponerCero(tipoRuta);
  while(obj.leerDeDisco(pos++)){
    tipoRuta[obj.getTipoRuta()-1]++;
    }
  mostrar(tipoRuta);
}


int contarDiasMal(char *codigoRuta){
  EstadoRuta obj;
  int pos=0;
  int cant=0;
  while(obj.leerDeDisco(pos++)){
    if(strcmp(codigoRuta, obj.getCodigoRuta())==0){
      if(obj.getAnio()==2015 && obj.getEstado()==2){
        cant++;
        }
      }
    }
  return cant;
}



