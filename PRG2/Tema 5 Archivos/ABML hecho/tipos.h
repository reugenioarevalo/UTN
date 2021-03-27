#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
struct Fecha{
    int dia, mes, anio;
};
struct alumno{
    int legajo;
    char nombre[30];
    char apellido[30];
    char email[30];
    Fecha fNacimiento;
    bool estado;
};


#endif // TIPOS_H_INCLUDED
