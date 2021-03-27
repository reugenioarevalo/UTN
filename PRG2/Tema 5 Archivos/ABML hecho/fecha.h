#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

Fecha cargarFecha();
Fecha mostrarFecha(Fecha);


Fecha cargarFecha(){
    Fecha reg;
     cout<<"\nDia :";
     cin>>reg.dia;
      cout<<"mes :";
     cin>>reg.mes;
      cout<<"anio :";
     cin>>reg.anio;
     return reg;
}

Fecha mostrarFecha(Fecha f){
    cout<<f.dia<<"/"<<f.mes<<"/ "<<f.anio<<endl;
    return f;
}
#endif // FECHA_H_INCLUDED
