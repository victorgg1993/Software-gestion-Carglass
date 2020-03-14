#ifndef _acc_prim_y_seg_nivel_h_
#define _acc_prim_y_seg_nivel_h_

#ifdef __linux__
#include <iostream>
#include "linux_adapter.h"
#include <string>
#include <sstream>
#elif _WIN32
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#else
#endif

#include "estructuras_y_tablas.h"
#include "acc_prim_y_seg_nivel.h"

void leerinfoSM(Umovil *serv);
void leerinfo(Partes *part);
void escribirinfo(Partes *part);
void escribirinfoSM(Umovil *serv);
void sobreescribirinfo(Partes *part);
void buscarfichaMAT(Partes *part, std::string mat, bool *trobat, int *i);
void introducir(Partes *part);
void mostrardatos(Partes *part, bool *trobat, int *i);
void borrardatos(Partes *part, int y);
void buscarfichaDNI(Partes *part, std::string dni, bool *trobat, int *i);
void buscarfichaSINI(Partes *part, int *sini, bool *trobat, int *i);
void modificardatos(Partes *part, bool *trobat, int *i);
void estadistica(Partes *part);
void mostrarSM(Partes *part, Umovil *sermovil);
void SMasignado(Partes *part, Umovil *sermovil);
void modificarSM(Umovil *sermovil);
void borrarSM(Partes *part, Umovil *sermovil);

#endif
