#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
struct Fecha{
    int dia, mes, anio;
};
struct Tintura{
    int codigo;
    char genero;
    int tipoPelo;
    Fecha fTintura;
};


#endif // TIPOS_H_INCLUDED
