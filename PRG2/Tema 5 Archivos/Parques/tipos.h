#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct fecha{
  int dia, mes, anio;
};
/**C�digo de animal (int), nombre (char[30]), clasificaci�n (char[5]), zona de habitat (entero entre 1 y 10), y
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
C�digo de animal (int), fecha (d�a, mes y a�o), zona de avistaje (entero entre 1 y 10)
**/
struct avistaje{
  int codigoAnimal;
  fecha fechaVista;
  int zonaAvistaje;
  bool estado;
};


#endif // TIPOS_H_INCLUDED
