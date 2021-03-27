#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED


void menuReportes();

void cargarCadena(char *, int);

///EMPRESAS
struct empresa cargarEmpresa();

void mostrarEmpresa(empresa var);


bool grabarRegistroEmpresa(empresa);

bool leerArchivoEmpresa();

void bajaLogicaEmpresa();

int buscarEmpresa(int );

struct empresa leerEmpresa(int);

bool modificarRegistroEmpresa(struct empresa, int);


int contarRegistrosEmpresa();

void menuEmpresa();

///fin empresas

///Viajes
struct viaje cargarViaje();

void mostrarViaje(viaje var);


bool grabarRegistroViaje(viaje);

bool leerArchivoViaje();

void bajaLogicaViaje();


int buscarViaje(int );

struct viaje leerViaje(int);

bool modificarRegistroViaje(struct viaje, int);


int contarRegistrosViaje();

void menuViaje();


#endif // PROTOTIPOS_H_INCLUDED
