#ifndef FUNCIONES_EMPRESAS_H_INCLUDED
#define FUNCIONES_EMPRESAS_H_INCLUDED

void menuEmpresas(){
    struct empresa reg;
    int opc;
    while(true){
      system("cls");
      cout << "-----MENU DE EMPRESAS-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. ALTA DE EMPRESA" << endl;
      cout << "2. BAJA DE EMPRESA"<<endl;
      cout << "3. LISTAR EMPRESA" << endl;
      cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case 1: reg=cargarEmpresa();
                if(reg.estado==true){
                  if(grabarRegistroEmpresa(reg)==true){
                    cout<<"REGISTRO GRABADO EN EL ARCHIVO"<<endl;
                  }
                  else{
                    cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                  }
                }
                else{
                  cout<<"ERROR DE DATOS"<<endl;
                }
                break;
        case 3: leerArchivoEmpresa();
                break;
        case 0: return;
                break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
      system("pause");
    }
    return;
}

int contarRegistrosEmpresa(){
  int cantReg;
  FILE *p;
  p=fopen(ARCHIVO_EMPRESAS, "rb");
  if(p==NULL) return -1;
  fseek(p,0,2);
  cantReg=ftell(p)/sizeof(struct empresa);
  fclose(p);
  return cantReg;

}

 char codigoEmpresa[5];
  char nombreEmpresa[30], direccion[40];
  int tipoEmpresa;
  bool estado;

struct empresa cargarEmpresa(){
  system("cls");
  struct empresa var;
  cout<<"INGRESE EL CODIGO: ";
  cargarCadena(var.codigoEmpresa,5);
  cout<<"INGRESE EL NOMBRE: ";
  cargarCadena(var.nombreEmpresa,30);
  cout<<"INGRESE LA DIRECCION: ";
  cargarCadena(var.direccion,40);
  cout<<"INGRESE EL TIPO: ";
  cin>>var.tipoEmpresa;
  var.estado=true;
  return var;
}

void mostrarEmpresa(empresa var){
  if(var.estado==true){
    system("cls");
   cout<<"CODIGO: ";
  cout<<var.codigoEmpresa<<endl;
  cout<<"NOMBRE: ";
  cout<<var.nombreEmpresa<<endl;
  cout<<"DIRECCION: ";
  cout<<var.direccion<<endl;
  cout<<"TIPO: ";
  cout<<var.tipoEmpresa<<endl;
    system("pause>nul");
  }
}


bool grabarRegistroEmpresa(empresa aux){
    FILE *p;
		p=fopen(ARCHIVO_EMPRESAS, "ab");
		///devuelve NULL si no se pudo abrir

		if(p==NULL) return false;

    fwrite(&aux,sizeof aux,1 ,p);

    fclose(p);
    return true;
}

bool leerArchivoEmpresa(){
    FILE *pColor;
    empresa aux;
		pColor=fopen(ARCHIVO_EMPRESAS, "rb");
		///devuelve NULL si no se pudo abrir

		if(pColor==NULL) return false;
    while(fread(&aux,sizeof aux,1 ,pColor)==1){
        mostrarEmpresa(aux);
        cout<<endl;
    }
    fclose(pColor);
    return true;
}


struct empresa leerEmpresa(int pos){
  FILE *p=NULL;
  struct empresa reg;
  p=fopen(ARCHIVO_EMPRESAS, "rb");
  if(p==NULL) return reg;///????
  fseek(p, sizeof reg*pos,0);
  fread(&reg, sizeof reg, 1, p);
  fclose(p);
  return reg;
};

#endif // FUNCIONES_EMPRESAS_H_INCLUDED
