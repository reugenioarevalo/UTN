
//Ejercicio:
//Autor:DEK
//Fecha:
//Comentario:

# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>

using namespace std;

class Fecha{
  private:
    int dia, mes, anio;
  public:
    Fecha(){
      dia=mes=anio=0;
      }
    void setDia(int d){dia=d;}
    void setMes(int d){mes=d;}
    void setAnio(int d){anio=d;}
    void Cargar(){
      cout<<"INGRESE LA FECHA"<<endl;
      cout<<"DIA: ";
      cin>>dia;
      cout<<"MES: ";
      cin>>mes;
      cout<<"ANIO: ";
      cin>>anio;
      }
    void Mostrar(){
      cout<<"FECHA"<<endl;
      cout<<"DIA: ";
      cout<<dia<<endl;
      cout<<"MES: ";
      cout<<mes<<endl;
      cout<<"ANIO: ";
      cout<<anio<<endl;
      }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
  };

class Alumno{
  private:
    char legajo[10];
    char nombre[25];
    char apellido[30];
    Fecha fechaNacimiento;
    int codigoCarrera;
    bool activo;// campo que define si el registro está
  // o no borrado
  public:
    void Cargar();
    void Mostrar();
    const char* getLegajo(){return legajo;}
    void setLegajo(char *legajo){strcpy(this->legajo,legajo);}
    bool grabarEnDisco(int);
    bool leerDeDisco(int pos);
    void setActivo(bool estado){activo=estado;}
    void setCodigoCarrera(int cc){codigoCarrera=cc;}
};

void Alumno::Cargar(){
  system("cls");
  cout<<"LEGAJO: ";
  cin>>legajo;
  cout<<"NOMBRE: ";
  cin>>nombre;
  cout<<"APELLIDO: ";
  cin>>apellido;
  cout<<"FECHA DE NACIMIENTO: ";
  fechaNacimiento.Cargar();
  cout<<"CARRERA: ";
  cin>>codigoCarrera;
  activo=true;
}

void Alumno::Mostrar(){
  if(activo){
    cout<<"LEGAJO: ";
    cout<<this->legajo<<endl;
    cout<<"NOMBRE: ";
    cout<<this->nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<"CARRERA: ";
    cout<<codigoCarrera;
  }
}

bool Alumno::leerDeDisco(int pos){
  FILE *p;
  bool leyo;
  p=fopen("alumno.dat","rb");
  if(p==NULL)return false;
  fseek(p, sizeof *this*pos, 0);
  leyo=fread(this, sizeof *this, 1, p);
  fclose(p);
  return leyo;
 }


bool Alumno::grabarEnDisco(int pos){
  FILE *p;
  if(pos<0){
    p=fopen("alumno.dat","ab");
    if(p==NULL){return false;}
  }
  else{
    p=fopen("alumno.dat","rb+");
    if(p==NULL){return false;}
    fseek(p, pos*sizeof *this,0);
  }
  bool grabo=fwrite(this, sizeof *this, 1, p);
  fclose(p);
  return grabo;
}
/////////////////////////////
Alumno leerRegistroAlumno(int);
int buscarRegistroAlumno(const char *legajo);
bool grabarRegistroAlumno(Alumno, int);
int contarRegistrosAlumno(){};
void altaAlumno();
void bajaLogicaAlumno();
void modificacionAlumno();
bool listadoAlumnos();
/////////////////////////////

int main(){
  int opc;
  while(1){
    system("cls");
    cout<<"MENU ALUMNOS"<<endl;
    cout<<"1. ALTA"<<endl;
    cout<<"2. BAJA "<<endl;
    cout<<"3. MODIFICACION"<<endl;
    cout<<"4. LISTADO"<<endl;
    cout<<"5. FIN DEL PROGRAMA"<<endl;
    cout<<"OPCION: ";
    cin>>opc;
    system("cls");
    switch(opc){
      case 1:
            altaAlumno();
            break;
      case 2:
            bajaLogicaAlumno();
            break;
      case 3:
            modificacionAlumno();
            break;
      case 4:
            if(!listadoAlumnos()){
              cout<<"NO HAY REGISTRO PARA LISTAR"<<endl;
              //system("pause");
              };
            break;
      case 5:
            return 0;
            break;
      default: cout<<"OPCION INCORRECTA";
            break;
      }

    system("pause");
  }
  return 0;
}
/////////////////////////////////

void altaAlumno(){
  Alumno reg;
  reg.Cargar();
  int pos=buscarRegistroAlumno(reg.getLegajo());
  if(pos!=-1){
    cout<<"EL LEGAJO YA EXISTE"<<endl;
    return;
  }
  if(reg.grabarEnDisco(pos)){
    cout<<"REGISTRO AGREGADO"<<endl;
    }
  else{
    cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    }
  system("pause");
}




int buscarRegistroAlumno(const char *legajo){
  FILE *p;
  Alumno reg;
  int pos=0;
  p=fopen("alumno.dat","rb");
  if(p==NULL){return -1;}
  while(fread(&reg, sizeof reg, 1, p)==1){
    if(strcmp(reg.getLegajo(),legajo)==0){
      fclose(p);
      return pos;
      }
    pos++;
    }
  fclose(p);
  return -1;
}

void bajaLogicaAlumno(){
  char legajo[10];
  Alumno reg;
  int pos;
  //PEDIR EL LEGAJO DEL ALUMNO A ELIMINAR
  cout<<"INGRESE EL LEGAJO DEL ALUMNO A DAR DE BAJA: ";
  cin>>legajo;
  pos=buscarRegistroAlumno(legajo);
  if(pos==-1){
    cout<<"NO EXISTE EL LEGAJO"<<endl;
    return;
    }
  reg.leerDeDisco(pos);
  reg.setActivo(false);
  if(reg.grabarEnDisco(pos)){
    cout<<"REGISTRO ELIMINADO"<<endl;
    }
  else{
    cout<<"NO SE PUDO ELIMINAR EL REGISTRO"<<endl;
    }
  //BUSCAR SI EL LEGAJO EXISTE
  //LEER EL REGISTRO QUE TIENE EL LEGAJO
  //CAMBIAR EL VALOR DEL CAMPO ACTIVO
  //GRABAR REGISTRO EN EL ARCHIVO
  }

void modificacionAlumno(){
  char legajo[10];
  Alumno reg;
  int pos;
  //PEDIR EL LEGAJO DEL ALUMNO A MODIFICAR
  cout<<"INGRESE EL LEGAJO DEL ALUMNO A MODIFICAR: ";
  cin>>legajo;
  pos=buscarRegistroAlumno(legajo);
  if(pos==-1){
    cout<<"NO EXISTE EL LEGAJO"<<endl;
    return;
    }
  reg.leerDeDisco(pos);
  int codigoCarrera;
  cout<<"INGRESE EL NUEVO CODIGO DE CARRERA: ";
  cin>>codigoCarrera;
  reg.setCodigoCarrera(codigoCarrera);
  if(reg.grabarEnDisco(pos)){
    cout<<"REGISTRO MODIFICADO"<<endl;
    }
  else{
    cout<<"NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
    }

  }

bool listadoAlumnos(){
  Alumno reg;
  int pos=0;
  int cantReg=contarRegistrosAlumno();
  if(!cantReg) return false;
  while(reg.leerDeDisco(pos)){
    reg.Mostrar();
    cout<<endl<<endl;
    pos++;
    }
  return true;
}


