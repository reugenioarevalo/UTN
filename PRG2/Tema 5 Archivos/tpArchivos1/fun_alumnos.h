#ifndef FUN_ALUMNOS_H_INCLUDED
#define FUN_ALUMNOS_H_INCLUDED

///PROTOTIPOS
int contarAlumnos();
int buscarLegajoAlumno(int legajo);

bool altaAlumno();
bool modificarRegistroAlumno(alumno, int);
bool grabarRegistroAlumno(alumno);
bool bajaAlumno();
bool modificarAlumno();

void mostrarCantidad();
void mostrarAlumnos();
void mostrarAlumno(alumno);

alumno leerRegistroAlumno(int );
alumno cargarAlumno();


///FIN PROTOTIPOS
int contarAlumnos(){
    alumno reg;
    FILE *p;
    int con=0;
    p=fopen("alumnos.dat", "rb");
    if(p==NULL)return 0;
    while(fread(&reg, sizeof(alumno), 1, p)){
            if(reg.estado==true){
                con++;
            }
    }
    fclose(p);
    return con;
}
int buscarLegajoAlumno(int legajo){
    FILE *p;
    alumno reg;
    int pos=0;
    p=fopen("alumnos.dat", "rb");
    if(p==NULL){return -1;}
    while(fread(&reg, sizeof(alumno), 1, p)){
        if(reg.legajo==legajo){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool altaAlumno(){
    alumno reg;
    bool grabo;
    int pos;
    reg = cargarAlumno();
    pos=buscarLegajoAlumno(reg.legajo);
    if(pos>=0){ cout<<"YA EXISTE EL LEGAJO:"; return false;}
    if(reg.estado==false){ cout<<"EL LEGAJO YA FUE UTILIZADO Y SE ENCUENTRA DE BAJA:"; return false;}
   grabo=grabarRegistroAlumno(reg);
   return  grabo;
}
bool modificarRegistroAlumno(alumno reg, int pos){
    FILE *p;
    bool grabo;
    p=fopen("alumnos.dat", "rb+");
    if(p==NULL)return false;
    fseek(p, sizeof(alumno)*pos, 0);
    grabo=fwrite(&reg, sizeof(alumno), 1, p);
    fclose(p);
    return grabo;
}
bool grabarRegistroAlumno(alumno reg){
    FILE *p;
    bool grabo;
    p=fopen("alumnos.dat", "ab");
    if(p==NULL)return false;
    grabo=fwrite(&reg, sizeof(alumno), 1, p);
    fclose(p);
    return grabo;
}
bool bajaAlumno(){
//pedir el ingreso del registro
//buscarlo el registro en el archivo (si no existe irse)
//si existe cambiar a false el estado.
//escribirlo en el archivo.

    alumno reg;
    bool baja;
    int legajo, pos;
    cout<<"Ingresar el nro de legajo";
    cin>>legajo;
    pos= buscarLegajoAlumno(legajo);
    if(pos==-1){return false;    }
    reg= leerRegistroAlumno(pos);
    mostrarAlumno(reg);
    reg.estado= false;
    baja= modificarRegistroAlumno(reg, pos);
    return baja;
}
bool modificarAlumno(){
    int legajo, pos;
    char email[30];
    bool cambio;
    alumno reg;
    cout<<"ingrese el legajo a modificar:";
    cin>>legajo;
    pos=buscarLegajoAlumno(legajo);
    reg=leerRegistroAlumno(pos);
    cout<<"ingrese el nuevo email: "<<endl;
    cargarCadena(email,30);
    strcpy(reg.email, email);
    cambio= modificarRegistroAlumno(reg, pos);
    mostrarAlumno(reg);
    return cambio;
}

void mostrarCantidad(){
    int cuantos = contarAlumnos();
    cout<<"cantidad de alumnos "<<cuantos<<endl<<endl;
}
void mostrarAlumnos(){
    alumno reg;
    FILE *p;
    p=fopen("alumnos.dat", "rb");
    if(p==NULL)
        return;
    while(fread(&reg, sizeof reg, 1, p))
    {
        mostrarAlumno(reg);
    }
    fclose(p);
}
void mostrarAlumno( alumno var){
//    if(var.estado==true)
//    {

        cout<<"legajo: ";
        cout<<var.legajo<<endl;
        cout<<"Nombre: ";
        cout<<var.nombre<<endl;
        cout<<"Apellido: ";
        cout<<var.apellido<<endl;
        cout<<"Email: ";
        cout<<var.email<<endl;
        cout<<"Fecha: ";
        mostrarFecha(var.fNacimiento);
        cout<<"Estado: "<<var.estado;
        cout<<endl<<endl;
//    }
}

alumno cargarAlumno(){
    alumno reg;
    cout<<"Legajo : ";
    cin>>reg.legajo;
    cout<<"Nombre : ";
    cargarCadena(reg.nombre, 9);
    cout<<"Apellido: ";
    cargarCadena(reg.apellido, 20);
    cout<<"Email: ";
    cargarCadena(reg.email, 20);
    cout<<"fecha de nacimiento : ";
    reg.fNacimiento = cargarFecha();
    reg.estado=true;
    return reg;
}
alumno leerRegistroAlumno(int  pos){
    FILE *p;
    alumno reg;
    reg.estado=false; //por si fallase el registro lo devuelvo en falso.

    p=fopen("alumnos.dat", "rb");
    if(p==NULL)    {return reg; }
    fseek(p, pos*sizeof(alumno), 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}
#endif // FUN_ALUMNOS_H_INCLUDED
