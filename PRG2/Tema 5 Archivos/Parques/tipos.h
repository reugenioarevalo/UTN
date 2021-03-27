#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct fecha{
  int dia, mes, anio;
};
/**Código de animal (int), nombre (char[30]), clasificación (char[5]), zona de habitat (entero entre 1 y 10), y
estado (1= registro activo; 0: registro inactivado o borrado)
**/

struct animal{
    int codigoAnimal;
    char nombreAnimal[30];
    char clasificacion[5];
    int zonaHabitat;
    bool estado;
};

/**
Código de animal (int), fecha (día, mes y año), zona de avistaje (entero entre 1 y 10)
**/
struct avistaje{
  int codigoAnimal;
  fecha fechaVista;
  int zonaAvistaje;
  bool estado;
};


#endif // TIPOS_H_INCLUDED
