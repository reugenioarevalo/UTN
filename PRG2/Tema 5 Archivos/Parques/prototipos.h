#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED


void menuReportes();

void cargarCadena(char *, int);

///ANIMALES
struct animal cargarAnimal();

void mostrarAnimal(animal var);


bool grabarRegistroAnimal(animal);

bool leerArchivoAnimal();

void bajaLogicaAnimal();

int buscarAnimal(int );

struct animal leerAnimal(int);

bool modificarRegistroAnimal(struct animal, int);


int contarRegistrosAnimal();

void menuAnimal();

///fin ANIMALES

///AVISTAJES
struct avistaje cargarAvistaje();

void mostrarAvistaje(avistaje var);


bool grabarRegistroAvistaje(avistaje);

bool leerArchivoAvistaje();

void bajaLogicaAvistaje();


int buscarAvistaje(int );

struct avistaje leerAvistaje(int);

bool modificarRegistroAvistaje(struct Avistaje, int);


int contarRegistrosAvistaje();

void menuAvistaje();



#endif // PROTOTIPOS_H_INCLUDED
