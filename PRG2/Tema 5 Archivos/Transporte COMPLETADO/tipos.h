#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct fecha{
  int dia, mes, anio;
};
/**N�mero de viaje, c�digo de empresa, marca del autob�s (1 a 10), cantidad de km del viaje (float),
cantidad de combustible consumido (float), fecha.
**/

struct viaje{
    int numeroViaje, marca;
    char codigoEmpresa[5];
    float cantidadKm, cantidadCombustible;
    fecha fechaViaje;
    bool estado;
};

/**
C�digo de empresa (char[5]), nombre, direcci�n, tipo de empresa (1: local.; 2: interurbano; 3: nacional; 4: internacional)
**/
struct empresa{
  char codigoEmpresa[5];
  char nombreEmpresa[30], direccion[40];
  int tipoEmpresa;
  bool estado;
};

/*
C�digo de empresa, nombre, y promedio de consumo de combustible entre todos los viajes.
*/
struct Consumo{
    char codigoEmpresa[5];
    char nombreEmpresa[30];
    float prom;
};

#endif // TIPOS_H_INCLUDED
