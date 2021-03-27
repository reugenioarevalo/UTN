#ifndef FUNCIONES_ANIMALES_H_INCLUDED
#define FUNCIONES_ANIMALES_H_INCLUDED


void menuAnimales(){
    struct animal reg;
    int opc;
    while(true){
      system("cls");
      cout << "-----MENU DE ANIMALES-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. ALTA DE ANIMAL" << endl;
      cout << "2. BAJA DE ANIMAL"<<endl;
      cout << "3. LISTAR ANIMAL" << endl;
      cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case 1: reg=cargarAnimal();
                if(reg.estado==true){
                  if(grabarRegistroAnimal(reg)==true){
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
        case 3: leerArchivoAnimal();
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


int contarRegistrosAnimal(){
  int cantReg;
  FILE *p;
  p=fopen(ARCHIVO_ANIMALES, "rb");
  if(p==NULL) return -1;
  fseek(p,0,2);
  cantReg=ftell(p)/sizeof(struct animal);
  fclose(p);
  return cantReg;

}

struct animal cargarAnimal(){
  system("cls");
  struct animal var;
  cout<<"INGRESE EL CODIGO: ";
  cin>>var.codigoAnimal;
  cout<<"INGRESE EL NOMBRE: " ;
  cargarCadena(var.nombreAnimal, 30);
  cout<<"INGRESE la CLASIFICACION: ";
  cargarCadena(var.clasificacion, 5);
  cout<<"INGRESE LA ZONA: "<<endl;
  cin>>var.zonaHabitat;
  var.estado=true;
  return var;
}

void mostrarAnimal(animal var){
  if(var.estado==true){
    system("cls");
    cout<<"CODIGO: ";
    cout<<var.codigoAnimal<<endl;
    cout<<"NOMBRE: ";
    cout<<var.nombreAnimal<<endl;
    cout<<"CLASIFICACION: ";
    cout<<var.clasificacion<<endl;
    cout<<"ZONA: ";
    cout<<var.zonaHabitat<<endl;
    system("pause>nul");
  }
}


bool grabarRegistroAnimal(animal aux){
    FILE *p;
		p=fopen(ARCHIVO_ANIMALES, "ab");
		///devuelve NULL si no se pudo abrir

		if(p==NULL) return false;

    fwrite(&aux,sizeof aux,1 ,p);

    fclose(p);
    return true;
}

bool leerArchivoAnimal(){
    FILE *pColor;
    animal aux;
		pColor=fopen(ARCHIVO_ANIMALES, "rb");
		///devuelve NULL si no se pudo abrir

		if(pColor==NULL) return false;
    while(fread(&aux,sizeof aux,1 ,pColor)==1){
        mostrarAnimal(aux);
        cout<<endl;
    }
    fclose(pColor);
    return true;
}


struct animal leerAnimal(int pos){
  FILE *p=NULL;
  struct animal reg;
  p=fopen(ARCHIVO_ANIMALES, "rb");
  if(p==NULL) return reg;///????
  fseek(p, sizeof reg*pos,0);
  fread(&reg, sizeof reg, 1, p);
  fclose(p);
  return reg;
};


void menuReportes(){

}


#endif // FUNCIONES_ANIMALES_H_INCLUDED
