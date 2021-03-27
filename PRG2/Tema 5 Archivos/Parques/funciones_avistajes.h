#ifndef FUNCIONES_AVISTAJES_H_INCLUDED
#define FUNCIONES_AVISTAJES_H_INCLUDED

void menuAvistajes(){
    struct avistaje reg;
    int opc;
    while(true){
      system("cls");
      cout << "-----MENU DE AVISTAJES-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. ALTA DE AVISTAJE" << endl;
      cout << "2. BAJA DE AVISTAJE"<<endl;
      cout << "3. LISTAR AVISTAJE" << endl;
      cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case 1: reg=cargarAvistaje();
                if(reg.estado==true){
                  if(grabarRegistroAvistaje(reg)==true){
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
        case 3: leerArchivoAvistaje();
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

int contarRegistrosAvistaje(){
  int cantReg;
  FILE *p;
  p=fopen(ARCHIVO_AVISTAJES, "rb");
  if(p==NULL) return -1;
  fseek(p,0,2);
  cantReg=ftell(p)/sizeof(struct animal);
  fclose(p);
  return cantReg;

}

struct avistaje cargarAvistaje(){
  system("cls");
  struct avistaje var;
  cout<<"INGRESE EL CODIGO: ";
  cin>>var.codigoAnimal;
  cout<<"INGRESE LA FECHA (DD/MM/AAAA): ";
  cin>>var.fechaVista.dia;
  cin>>var.fechaVista.mes;
  cin>>var.fechaVista.anio;
  cout<<"INGRESE LA ZONA: "<<endl;
  cin>>var.zonaAvistaje;
  var.estado=true;
  return var;
}

void mostrarAvistaje(avistaje var){
  if(var.estado==true){
    system("cls");
    cout<<"CODIGO: ";
    cout<<var.codigoAnimal<<endl;
    cout<<"INGRESE LA FECHA (DD/MM/AAAA): ";
    cout<<var.fechaVista.dia<<"/";
    cout<<var.fechaVista.mes<<"/";
    cout<<var.fechaVista.anio<<endl;
    cout<<"ZONA: ";
    cout<<var.zonaAvistaje<<endl;
    system("pause>nul");
  }
}


bool grabarRegistroAvistaje(avistaje aux){
    FILE *p;
		p=fopen(ARCHIVO_AVISTAJES, "ab");
		///devuelve NULL si no se pudo abrir

		if(p==NULL) return false;

    fwrite(&aux,sizeof aux,1 ,p);

    fclose(p);
    return true;
}

bool leerArchivoAvistaje(){
    FILE *pColor;
    avistaje aux;
		pColor=fopen(ARCHIVO_AVISTAJES, "rb");
		///devuelve NULL si no se pudo abrir

		if(pColor==NULL) return false;
    while(fread(&aux,sizeof aux,1 ,pColor)==1){
        mostrarAvistaje(aux);
        cout<<endl;
    }
    fclose(pColor);
    return true;
}


struct avistaje leerAvistaje(int pos){
  FILE *p=NULL;
  struct avistaje reg;
  p=fopen(ARCHIVO_AVISTAJES, "rb");
  if(p==NULL) return reg;///????
  fseek(p, sizeof reg*pos,0);
  fread(&reg, sizeof reg, 1, p);
  fclose(p);
  return reg;
};

#endif // FUNCIONES_AVISTAJES_H_INCLUDED
