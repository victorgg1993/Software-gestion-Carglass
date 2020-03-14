#ifndef _estructuras_y_tablas_h_
#define _estructuras_y_tablas_h_

#ifdef __linux__
#include <iostream>
#include <string>
#include <sstream>
#elif _WIN32
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#else
#endif

const int pmax = 100;

struct Nombre
{
    std::string Nombre, ape1, ape2;
};
struct Fecha
{
    int dia, mes, anyo;
};
struct Direccion
{
    int CP;
    std::string Poblacion, calle;
};
struct Coche
{
    std::string marca, modelo, color;
    std::string matcoche;
    std::string dnicon;
    int anyo, siniestro;
    Fecha fechasin;
    char danyo;
    bool SM;
};
struct Conductor
{
    std::string email;
    Direccion dicon;
    std::string matcoche;
    Nombre nomcon;
    std::string dnicon;
    int siniestro;
};
struct SM
{
    Fecha fechasm;
    std::string matricula;
};

typedef SM SerMov[pmax];
typedef Conductor tCon[pmax];
typedef Coche tCoche[pmax];

struct tCondu
{
    tCon coches;
    int nCondu;
};
struct tCoch
{
    tCoche coches;
    int nCoches;
};
struct Partes
{
    tCon Conductores;
    tCoch Coches;
    int nPartes;
};
struct Umovil
{
    SerMov tmovil;
    int nmovil;
};



#endif
