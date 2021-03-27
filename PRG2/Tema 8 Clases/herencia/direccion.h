#ifndef DIRECCION_H_INCLUDED
#define DIRECCION_H_INCLUDED

class Direccion
{
  private:
    char nombre_calle[25];
    char numero[10];
    char piso[3];
    char depto[3];
    char localidad[30];
    char cod_postal[10];
  public:
    void Cargar();
    void Mostrar();
    char *getNombre_calle(){return nombre_calle;}
    char *getNumero(){return numero;}
    char *getPiso(){return piso;}
    char * getDepto(){return depto;}
    char * getLocalidad(){return localidad;}
    char * getCod_postal(){return cod_postal;}
    void setNombre_calle(char *n){strcpy(nombre_calle,n);}
    void setNumero(char * n){strcpy(numero,n);}
    void setPiso(char *p){strcpy(piso,p);}
    void setDepto(char *d){strcpy(depto,d);}
    void setLocalidad(char *l){strcpy(localidad,l);}
    void setCod_postal(char *cp){strcpy(cod_postal,cp);}
    friend istream& operator>>(istream &,Direccion&);
    friend ostream& operator<<(ostream &,Direccion&);
};

void Direccion::Cargar()
{


  }

void Direccion::Mostrar()
{

  }

 istream& operator>>(istream &entrada,Direccion &obj)
 {
   entrada.ignore();
   cout<<"Ingrese la calle: ";
   entrada.getline(obj.nombre_calle,25);
   cout<<"Ingrese el numero: ";
   entrada>>obj.numero;
   cout<<"Ingrese el piso: ";
   entrada>>obj.piso;
   cout<<"Ingrese el departamento: ";
   entrada>>obj.depto;
   cout<<"Ingrese la localidad: ";
   entrada>>obj.localidad;
   cout<<"Ingrese el codigo postal: ";
   entrada>>obj.cod_postal;
   return entrada;
   }
ostream & operator<<(ostream &salida ,Direccion &obj)
{
   cout<<"Calle: ";
   cout<<obj.nombre_calle<<endl;
   cout<<"Numero: ";
   salida<<obj.numero<<endl;
   cout<<"Piso: ";
   salida<<obj.piso<<endl;
   cout<<"Departamento: ";
   salida<<obj.depto<<endl;
   cout<<"Localidad: ";
   salida<<obj.localidad<<endl;
   cout<<"Codigo postal: ";
   salida<<obj.cod_postal<<endl;
   return salida;
  }
#endif // DIRECCION_H_INCLUDED
