#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
class Persona
	{
	 protected:
		char ndoc[20];
		char nombre[20];
		char apellido[20];
		Fecha fecha_nac;
		Direccion domicilio;
		char telefono[20];
	 public:
		void Cargar();
		void Mostrar();
		char * getNdoc(){return ndoc;}
		char * getNombre(){return nombre;}
		char * getApellido(){return apellido;}
		Fecha getFecha(){return fecha_nac;}
		Direccion getDomicilio(){return domicilio;}
		char * getTelefono(){return telefono;}
		void setNdoc(char *n){strcpy(ndoc,n);}
		void setNombre(char *n){strcpy(nombre,n);}
		void setApellido(char *a){strcpy(apellido,a);}
		void setFecha_nac(Fecha f){fecha_nac=f;}
		void setDomicilio(Direccion d){domicilio=d;}
		void setTelefono(char *tel){strcpy(telefono,tel);}
	 };

class Alumno:public Persona
	{
	 private:
		char nleg[15];
		char carrera[20];
	 public:
		void Cargar();
		void Mostrar();
	 };

void Persona::Cargar()
	{
	cout<<"Ingrese el nombre: ";
	cin>>nombre;
	cout<<"Ingrese el apellido: ";
	cin>>apellido;
	cout<<"Ingrese la fecha de nacimiento: ";
	cin>>fecha_nac;
	cout<<"Ingrese la direccion: ";
	cin>>domicilio;
	cout<<"Ingrese el numero de documento: ";
	cin>>ndoc;
	cout<<"Ingrese el numero de telefono: ";
	cin>>telefono;
	}

void Persona::Mostrar()
	{
	cout<<"Nombre: ";
	cout<<nombre<<endl;
	cout<<"Apellido: ";
	cout<<apellido<<endl;
	cout<<"Fecha de nacimiento: "<<endl;
	cout<<fecha_nac;
	cout<<"Domicilio: "<<endl;
	cout<<domicilio<<endl;
	cout<<"Documento: ";
	cout<<ndoc<<endl;
	cout<<"Telefono: ";
	cout<<telefono<<endl;
	}

void Alumno::Cargar()
	{
	Persona::Cargar();
	cout<<"Ingrese el numero de legajo: ";
	cin>>nleg;
	cout<<"Ingrese la carrera: ";
	cin>>carrera;
	}

void Alumno::Mostrar()
	{
	Persona::Mostrar();
	cout<<"Numero de legajo: ";
	cout<<nleg<<endl;
	cout<<"Carrera: ";
	cout<<carrera;
	}





#endif // PERSONA_H_INCLUDED
