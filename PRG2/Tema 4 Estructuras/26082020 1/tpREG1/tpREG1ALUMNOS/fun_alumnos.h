#ifndef FUN_ALUMNOS_H_INCLUDED
#define FUN_ALUMNOS_H_INCLUDED

///PROTOTIPOS
void cargarAlumnos( );
void mostrarAlumnos();
alumno cargarAlumno();
void mostrarAlumno(alumno);
int buscarAlumno(int legajo);
void modificarAlumno( alumno *pReg);

///FIN PROTOTIPOS

int buscarAlumno(int legajo){}
void modificarAlumno( alumno *pReg){}

void cargarAlumnos(){
    alumno reg;
    reg =cargarAlumno();
    FILE *p;
    p=fopen("alumnos.dat", "ab");
    if(p==NULL) cout<<"Error en lecutra de archivo."<<endl; return;

    fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
}

alumno cargarAlumno(){
    alumno reg;
    cout<<"Nombre : ";
    cargarCadena(reg.nombre, 9);
    cout<<"Apellido: ";
    cargarCadena(reg.apellido, 20);
    cout<<"Email: ";
    cargarCadena(reg.email, 20);
    cout<<"DIA: ";
    cin>>reg.dia;
     cout<<"MES: ";
    cin>>reg.mes;
    cout<<"ANIO: ";
    cin>>reg.anio;
    return reg;
}

void mostrarAlumnos(){

}
void mostrarAlumno(alumno var){
    cout<<"Apellido: ";
    cout<<var.nombre<<endl;
    cout<<"Nombre: ";
    cout<<var.apellido<<endl;
    cout<<"Email: ";
    cout<<var.email<<endl;
    cout<<"Fecha: ";
    cout<<var.dia<<"/"<<var.mes<<"/"<<var.anio<<endl;
    cout<<endl<<endl;
}



#endif // FUN_ALUMNOS_H_INCLUDED
