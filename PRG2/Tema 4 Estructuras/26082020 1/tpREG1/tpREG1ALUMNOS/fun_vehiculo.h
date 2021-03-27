#ifndef FUN_VEHICULO_H_INCLUDED
#define FUN_VEHICULO_H_INCLUDED

///PROTOTIPOS
void cargarVehiculos(vehiculo *, int );
void mostrarVehiculos(vehiculo *, int);
vehiculo cargarVehiculo();
void mostrarVehiculo(vehiculo);

///FIN PROTOTIPOS

void cargarVehiculos(vehiculo *v, int tam){
    int i;
    for(i=0; i<tam;i++){
            system("cls");
            v[i]=cargarVehiculo();
    }

}

void mostrarVehiculos(vehiculo *v, int tam){
    int i;
    for(i=0; i<tam;i++){
            mostrarVehiculo(v[i]);
    }

}

vehiculo cargarVehiculo(){
    vehiculo reg;
    cout<<"PATENTE: ";
    cargarCadena(reg.patente, 9);
    cout<<"MARCA: ";
    cargarCadena(reg.marca, 20);
    cout<<"MODELO: ";
    cargarCadena(reg.modelo, 20);
    cout<<"ANIO: ";
    cin>>reg.anioFabricacion;
    cout<<"PRECIO: ";
    cin>>reg.precio;
    return reg;
}

void mostrarVehiculo(vehiculo var){
    cout<<"PATENTE: ";
    cout<<var.patente<<endl;
    cout<<"MARCA: ";
    cout<<var.marca<<endl;
    cout<<"MODELO: ";
    cout<<var.modelo<<endl;
    cout<<"ANIO: ";
    cout<<var.anioFabricacion<<endl;
    cout<<"PRECIO: ";
    cout<<var.precio<<endl<<endl;
}


#endif // FUN_VEHICULO_H_INCLUDED
