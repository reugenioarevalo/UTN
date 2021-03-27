#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
///prototipos

void menuReportes();
bool mostrarPuntoA();
bool generarArchivoConsumo();
void mostrarEmpresasNoExterior();
void mostrarCombustibleMarcaMes();
void mostrarMatriz(float m[][10],  int , int );

void mostrarKmEmpresaNacionales();
float contarKmRecorridosPorEmpresaNac(char *, int);

void mostrarEmpresaViajeMayorKm();
viaje buscarRegistroMayor(viaje *, int );
empresa leerEmpresaPorCodigo( char  *);

void mostrarMarcaMenorConsumo();
int  buscarMenor(float *, int tam);
int contarRegistrosViajeAnio(int);

float calcularPromedioCombustible(char *, int anio);
bool grabarRegistroConsumo(Consumo  reg);
bool crearArchivoConsumo();

void mostrarMesConMayorCanViajes();
///fin protipos

void menuReportes(){

    int opc;
    while(true){
      system("cls");
      cout << "-----MENU DE REPORTES-----" << endl;
      cout << "-------------------------" << endl;
      cout << "1. ARCHIVOS EMPRESAS PROMEDIOS" << endl;
      cout << "11. MOSTRAR ARCHIVOS EMPRESAS PROMEDIOS" << endl;
      cout << "2. EMPRESAS SIN VIAJES AL EXTERIOR"<<endl;
      cout << "3. COMBUSTIBLE POR MES Y POR MARCA" << endl;
      cout << "4. CANTIDAD DE KM RECORRIDOS NACIONAL" << endl;
      cout << "5. EMPRESA Y VIAJE CON MAYOR KM " << endl;
      cout << "6. MARCA DE MENOS CONSUMO POR KM RECORRIDOS " << endl;
      cout << "7. MES CON MAYOR CANTIDAD DE VIAJES " << endl;
      cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
      cout << "- SELECCIONE UNA OPCION: - " << endl;
      cout << "-------------------------" << endl;
      cin>>opc;
      system("cls");
      switch(opc){
        case 1: if(generarArchivoConsumo()){
            cout<<"ARCHIVO GENERADO CORRECTAMENTE!."<<endl;
        }else{
            cout<<"NO SE PUDO GENEREAR EL ARCHIVO."<<endl;
        };
                break;
        case 11: mostrarPuntoA();
                break;
        case 2: mostrarEmpresasNoExterior();
                break;
        case 3: mostrarCombustibleMarcaMes();
                break;
        case 4: mostrarKmEmpresaNacionales();
            break;
        case 5: mostrarEmpresaViajeMayorKm();
            break;
//        case 6: cout<<" cantidad  "<<contarRegistrosViajeAnio(2019)<<endl;
        case 6: mostrarMarcaMenorConsumo();
            break;
        case 7: mostrarMesConMayorCanViajes();
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
float calcularPromedioCombustible(char *codigoEmpresa, int anio){
    FILE *p;
    viaje reg;
    int cantViajes=0;
    float cantCombustible=0;
    p=fopen("viajes.dat", "rb");
    if(p==NULL){return -1;}

    while(fread(&reg, sizeof(viaje), 1,p)){
        if(reg.fechaViaje.anio==anio){
            if(strcmp(reg.codigoEmpresa, codigoEmpresa)==0){
                cantViajes++;
                cantCombustible+=reg.cantidadCombustible;
            }
        }
    }
    fclose(p);
    if(cantViajes!=0) return cantCombustible/cantViajes;
    else return 0;
}
bool grabarRegistroConsumo(Consumo  reg){
    FILE *p;
     p=fopen("consumos.dat", "ab");
     if(p==NULL)return false;
     bool grabo= fwrite(&reg, sizeof(Consumo),1, p);
     fclose(p);
     return grabo;
}
bool generarArchivoConsumo(){
    if(!crearArchivoConsumo())return false;
    FILE *p;
    Consumo reg;
    empresa  emp;
    p=fopen("empresas.dat", "rb");
    if(p==NULL){return false;}
    while(fread(&emp, sizeof(empresa), 1, p)){
        strcpy(reg.codigoEmpresa, emp.codigoEmpresa);
        strcpy(reg.nombreEmpresa, emp.nombreEmpresa);
        reg.prom=calcularPromedioCombustible(reg.codigoEmpresa, 2019);
        if(!grabarRegistroConsumo(reg)){
            fclose(p);
            return false;
        }
    }
    fclose(p);
    return true;
}

void mostrarEmpresasNoExterior(){
     empresa reg;
     /*opcion a*/
     /*FILE *p;
     p=fopen("empresas.dat", "rb");
     if(p==NULL){return ;}
    while(fread(&reg, sizeof(empresa), 1, p)){
        if(reg.tipoEmpresa!=4){
            mostrarEmpresa(reg);
        }
    }
     fclose(p);*/

     /*opcion b*/
     int i, cantReg=contarRegistrosEmpresa();
     for(i=0;i<cantReg;i++){
            reg=leerEmpresa(i);
        if(reg.tipoEmpresa!=4){
            mostrarEmpresa(reg);
        }
     }
}

void mostrarKmEmpresaNacionales(){

    FILE *p;
     empresa  reg;
     float cant=0;
    p=fopen("empresas.dat", "rb");
    if(p==NULL){return ;}
    while(fread(&reg, sizeof(empresa), 1, p)){
    if(reg.tipoEmpresa!=4){
       cant+= contarKmRecorridosPorEmpresaNac(reg.codigoEmpresa, 2019);
        }
    }
    fclose(p);
    cout<<"la canitidad de km recorrido por empresas nacionales es: ";
        cout<<cant<<endl<<endl;

}
float contarKmRecorridosPorEmpresaNac(char *codigoEmpresa, int anio){
    FILE *p;
    viaje reg;

    float cantKm=0;
    p=fopen("viajes.dat", "rb");
    if(p==NULL){return -1;}

    while(fread(&reg, sizeof(viaje), 1,p)){
        if(reg.fechaViaje.anio==anio){
            if(strcmp(reg.codigoEmpresa, codigoEmpresa)==0){
                cantKm+=reg.cantidadKm;
            }
        }
    }
    fclose(p);
   return cantKm;

}

void mostrarCombustibleMarcaMes(){
 FILE *p;
    float mesMarca[12][10]={0};
    viaje reg;

    float cantCombustible=0;
    p=fopen("viajes.dat", "rb");
    if(p==NULL){return ;}

    while(fread(&reg, sizeof(viaje), 1,p)){
        if(reg.fechaViaje.anio==2019){
            mesMarca[reg.fechaViaje.mes-1][reg.marca-1]+=reg.cantidadCombustible;
        }
    }
    fclose(p);
    mostrarMatriz(mesMarca, 12,10);

}
void mostrarMatriz(float m[][10],  int filas, int colum){
    cout<<"consumo por Marca y mes  : "<<endl;
    cout<<"Nro de Marca"<<"\t1"<<"\t2"<<"\t3"<<"\t4"<<"\t5"<<"\t6"<<"\t7"<<"\t8"<<"\t9"<<"\t10"<<endl;
    for(int i=0; i<filas; i++){
            cout<<"mes: "<<i+1<<"\t\t";
            for(int j=0; j<colum;j++){
                cout<<m[i][j]<<"\t";
            }
            cout<<endl;

    }
}

bool mostrarPuntoA(){
        FILE *p;
        Consumo reg;
     p=fopen("consumos.dat", "rb");
     if(p==NULL)return false;
    while(fread(&reg, sizeof(Consumo),1, p)){
        cout<<"codigo empresa: "<<reg.codigoEmpresa<<endl;
        cout<<"nombre de empresa: "<<reg.nombreEmpresa<<endl;
        cout<<"consumo prom : "<<reg.prom<<endl;
    }
     fclose(p);
return true;
}
bool crearArchivoConsumo(){///utilizado para pisar el anterior en caso de reportes de promedios
    FILE *p;
     p=fopen("consumos.dat", "wb");///este es el punto clave
    if(p==NULL)return false;
     fclose(p);
    return true;
}

void mostrarEmpresaViajeMayorKm(){
    viaje reg, *aux;
    empresa emp;
    int cantViajes= contarRegistrosViaje();

    aux= (viaje *)malloc(cantViajes*sizeof(viaje));
    if(aux==NULL){return;}

    for(int i=0;i<cantViajes;i++){
        aux[i] = leerViaje(i);
       // mostrarViaje(aux[i]);
    }

    reg = buscarRegistroMayor(aux, cantViajes);
    emp = leerEmpresaPorCodigo(reg.codigoEmpresa);
free(aux);
    cout<<"el nombre de la empresa es : "<<emp.nombreEmpresa<<endl;
    cout<<"el numero de viaje es: "<<reg.numeroViaje<<endl;
    cout<<"el kilometraje recorrido mas alto es: "<<reg.cantidadKm<<endl;

}
viaje buscarRegistroMayor(viaje *reg, int cant ){
float mayorKm=0;
viaje aux;
    for(int i=0; i<cant;i++){
        if(reg[i].cantidadKm>mayorKm){
          mayorKm=reg[i].cantidadKm;
          aux=reg[i];
        }
    }
    return aux;
}
empresa leerEmpresaPorCodigo( char  *codigoEmpresa){
    empresa reg;
    int i, cantReg=contarRegistrosEmpresa();
     for(i=0;i<cantReg;i++){
        reg=leerEmpresa(i);
        if(strcmp(reg.codigoEmpresa, codigoEmpresa)==0){
            return reg;
        }
     }
}

void mostrarMarcaMenorConsumo(){
    viaje reg, aux;
    int  cantViajes= contarRegistrosViaje();
    float *v;
    v=(float *)malloc(sizeof(float)*cantViajes);
    FILE *p;
    p=fopen("viajes.dat", "rb");
    if(p==NULL){
            return;
    }
        while(fread(&reg, sizeof(viaje), 1,p)){
             v[reg.numeroViaje-1]=reg.cantidadCombustible/reg.cantidadKm;
        }
    fclose(p);
    aux=leerViaje(buscarMenor(v,cantViajes));
    free(v);
    mostrarViaje(aux);
    cout<<"la marca q menos consumio por km fue la nro: "<<aux.marca<<endl;
}
int  buscarMenor(float *v, int tam){
float menor=1;
int viajeNro;
    for(int i=0; i<tam;i++){
        if(v[i]<menor){
            menor=v[i];
            viajeNro=i;
        }
   }
    return viajeNro;
}
int contarRegistrosViajeAnio(int anio){
    int cont=0;
    viaje reg;
    FILE *p;
    p=fopen("viajes.dat", "rb");
    if(p==NULL){return -1;}
    while(fread(&reg, sizeof(viaje), 1,p)){
        if(reg.fechaViaje.anio==anio){
          cont++;
        }
    }
    fclose(p);
    return cont;
}

void mostrarMesConMayorCanViajes(){
    FILE *p;
    viaje reg, *vAux;
    int v[12]={0};
    int cont=0, cantViajes = contarRegistrosViajeAnio(2019);
    vAux= (viaje *)malloc(sizeof(viaje)*cantViajes);
    p=fopen("viajes.dat", "rb");
    if(p==NULL)return;
    while(fread(&reg, sizeof(viaje), 1, p)){
        if(reg.fechaViaje.anio==2019){
            vAux[cont]=reg;
            cont++;
        }
    }
    fclose(p);

    for(int i=0; i<12;i++){
        for(int j=0; j<cantViajes;j++){
            if(vAux[j].fechaViaje.mes ==i+1){
                v[vAux[j].fechaViaje.mes-1]++;
            }
        }
    }
    free(vAux);
    int mes, mayor=0;
    for(int k=0;k<12;k++){
          if(v[k]>mayor){
                mayor=v[k];
                mes = k+1;
          }
    }
    cout<<" el mes con mayor cantidad de viajes es el  : "<<mes<<" con una cantidad de : "<<mayor<<endl;
}
#endif // REPORTES_H_INCLUDED
