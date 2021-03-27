#ifndef CLIENTES_H
#define CLIENTES_H
class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(int d=0, int m=0, int a=0){
        dia=d;
        mes = m;
        anio= a;
    }
     ~Fecha(){ cout<<"se murio el objeto :-("<<endl;}
    void cargar(){
        cout<<"ingrese el dia ";        cin>>dia;
        cout<<"el mes ";        cin>>mes;
        cout<<"el anio ";        cin>>anio;
    }
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void mostrar(){
        cout<<"dia "<<getDia();
        cout<<"el mes "<<getMes();
        cout<<"el anio "<<getAnio();
    }
};

class Clientes
{
    private:
    int DNI;
    Fecha feNacimiento;
    char Nombre[30];
    char Apellido[30];
    char Email[30];
    char Telefono[15];


    public:
        Clientes();
        virtual ~Clientes();
        void Cargar();
        void Mostrar();

        int  getDni(){return DNI;}
        Fecha getFechaNacimienot(){return feNacimiento;}
        const char * getNombre(){return Nombre;}
        const char * getApellido(){return Apellido;}
        const char * getEmail(){return Email;}
        const char * getTelefono(){return Telefono;}

        void setDNI(int d){DNI=d;}
        void setFechaNacimiento(Fecha f){feNacimiento=f;}
        void setNombre(const char *a){strcpy(Nombre, a);}
        void setApellido(const char *a){strcpy(Apellido, a);}
        void setEmail(const char *a){strcpy(Email, a);}
        void setTelefono(const char *a){strcpy(Telefono, a);}

        void leerDeDisco(int);
        void grabarEnDisco();

        ///Un constructor con valores por omisión para los parámetros.
        Clientes(int d=123, const char *n="nada", const char *a="nada", const char *e="nada", const char * t="000" ){
            DNI=d;
            strcpy(Nombre,n);
            strcpy(Apellido,a);
            strcpy(Email, e);
            strcpy(Telefono, t);
        }
        //Un constructor para asignar valor a la propiedad nombre.
        Clientes(const char  * n="nada"){
            strcpy(Nombre, n);
        }
        //La propiedad fecha de nacimiento debe ser un objeto de la clase Fecha


};
void Clientes::Cargar(){
        cout<<"DNI";
        cin>>DNI;
        feNacimiento.cargar();
        cout<<"Nombre"<<endl;
        cin>>Nombre;
        cout<<"Apellido"<<endl;
        cin>>Apellido;
        cout<<"Email"<<endl;
        cin>>Email;
        cout<<"Telefono"<<endl;
        cin>>Telefono;
}
void Clientes::Mostrar(){
        cout<<"DNI";
       cout<<DNI<<endl;
        feNacimiento.mostrar();
        cout<<"Nombre"<<endl;
        cout<<Nombre;
        cout<<"Apellido"<<endl;
        cout<<Apellido;
        cout<<"Email"<<endl;
        cout<<Email;
        cout<<"Telefono"<<endl;
        cout<<Telefono;
}
void Clientes::leerDeDisco(int pos){
int x;
	FILE *p;
	p=fopen("cliente.dat","rb");
	if(p==NULL)
		{
		cout<<"No existe el archivo";
		cout<<"Presione una tecla para continuar";
    system("pause<null");
		return ;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);

	}

void Clientes::grabarEnDisco(){
    FILE *p;
        p=fopen("cliente.dat","ab");
        if(p==NULL){cout<<"Error de archivo";exit(1);}
        fwrite(this,sizeof *this,1,p);
        fclose(p);
    }
#endif // CLIENTES_H
