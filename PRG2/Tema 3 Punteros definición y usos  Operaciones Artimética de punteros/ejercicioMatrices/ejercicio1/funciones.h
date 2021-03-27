#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
//prototipos
void cargarMaterias(char nombreMaterias[][30] , int cant[][2] );
void mostrarMaterias(char nombreMaterias[][30] , int cant[][2] );
void cargarAccesos(float *horasMaterias, int marzoMaterias[][31]);
void materiasSinAcceso(float *horasMaterias);
void mayorCantAcceso(float *horasMaterias );
void accesosMarzo(int marzoMaterias[][31]);
int maximoVector(float  *v, int tam);
void cargarCadenas(char *palabra, int tam);
//fin de prototipos


void cargarCadenas(char *palabra, int tam){ //funcion para cargar cadenas en gral
    int i;
    fflush(stdin);
    for(i=0; i<tam ; i++){
        palabra[i]=cin.get();
        if(palabra[i]=='\n')break;
    }
    palabra[i]='\0';
    fflush(stdin);
}

void cargarAccesos(float *horasMaterias, int marzoMaterias[][31]) {
    int legajo, dia, mes, nroMateria;
    float cantidadHoras;
    cout<<"Legajo : ";
    cin>>legajo;
    while(legajo!=0){
        cout<<"DIA :";
        cin>>dia;
        cout<<" MES : ";
        cin>>mes;
        cout<<" Materia";
        cin>>nroMateria;
        cout<<"Cantidad de Horas : ";
        cin>>cantidadHoras;

            //Puntos a y b
            horasMaterias[nroMateria-1]+=cantidadHoras;
            //punto c
            if(mes==3) marzoMaterias[nroMateria-1][dia-1]++;

        cout<<"Legajo : ";
        cin>>legajo;

    }
}
void materiasSinAcceso(float *horasMaterias) {
    for(int i=0; i<20; i++){
        if(horasMaterias[i]==0)
            cout<<" materias en cero : "<<i+1;
    }
}

void mayorCantAcceso(float *horasMaterias ) {
    int posMax;
    posMax= maximoVector(horasMaterias, 20);
    cout<<" Materias con mas Horas:  "<<posMax+1<<endl;
}

void accesosMarzo(int marzoMaterias[][31]) {
    int  i, j;
        for(i=0; i<20; i++){
            for(j=0; j<31; j++){
                if(marzoMaterias[i][j]>0){
                    cout<<"MATERIA: "<<"\t"<<i+1;
                    cout<<"DIA: "<<"\t"<<j+1;
                    cout<<"ACCESO:  "<<marzoMaterias[i][j]<<endl;
                }
            }
        }
    }

int maximoVector(float *v, int tam){
    int posMax=0, i;
    for(i=1; i< tam; i++){
        if(v[i]> v[posMax]){
            posMax = i;
        }
    }
        return posMax;
}
void cargarMaterias(char nombreMaterias[][30] , int cant[][2] ){
    int numero;
    for(int i=0; i < 3; i++ ){
        cout<<"Numero de Materia: ";
        cin>>numero;
        cout<<"NOmbre Materia; ";
       cargarCadenas(nombreMaterias[numero-1],  30);
        cout<<"cantidad de Alumnos: ";
        cin>>cant[numero-1][0];
        cout<<"cantidad de profesores: ";
        cin>>cant[numero-1][1];

    }
}

void mostrarMaterias(char nombreMaterias[][30] , int cant[][2] ){

    for(int i=0; i < 3; i++ ){
        cout<<"Numero de Materia: ";
        cout<<i+1<<endl;
        cout<<"NOmbre Materia; ";
        cout<<nombreMaterias[i]<<endl;
        cout<<"cantidad de Alumnos: ";
        cout<<cant[i][0]<<endl;
        cout<<"cantidad de profesores: ";
        cout<<cant[i][1]<<endl<<endl;

    }
}
#endif // FUNCIONES_H_INCLUDED
