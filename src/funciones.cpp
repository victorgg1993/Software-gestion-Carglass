#ifdef __linux__
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>         // ifstream ofstream
#include "linux_adapter.h" /* ACCIONES QUE NO FORMAN PARTE DEL TEMARIO*/
#elif _WIN32
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#else
#endif

#include "funciones.h"
#include "logos.h"
#include "estructuras_y_tablas.h" /* ESTRUCTURAS Y TABLAS */
#include "acc_prim_y_seg_nivel.h" /* ACCIONES DE PRIMER NIVEL Y DE SEGUNDO NIVEL */

char *textos_menu_1[11] =
    {
        "",
        "                                         MENU PRINCIPAL",
        "                            ___________________________________________",
        "                                      1 - APERTURAR PARTE",
        "                                      2 - CONSULTA DE POLIZA",
        "                                      3 - MODIFICAR PARTE",
        "                                      4 - BORRAR PARTE",
        "                                      5 - SERVICIO MOVIL",
        "                                      6 - ESTADISTICAS",
        "                                                                            0 - SALIR",
        "            Elija una opcion: ",
};

int n_salts_menu_1[11] = {3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0};
int colors_menu_1[11] = {14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0};

bool AjustarVentana(int Ancho, int Alto)
{
#ifdef __linux__
    SetConsoleScreenBufferSize();
    SetConsoleWindowInfo();
#elif _WIN32
    _COORD Coordenada;
    Coordenada.X = Ancho;
    Coordenada.Y = Alto;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Right = Ancho - 1;
    Rect.Bottom = Alto - 1;
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(hConsola, Coordenada);
    SetConsoleWindowInfo(hConsola, true, &Rect); // antes => ( x, TRUE, x);
#else
#endif

    return true; // antes TRUE;
}

char menu(int n_menu)
{
    char opcion = 0;

#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else
#endif

    switch (n_menu)
    {
    case 1:
        logo1();
        logo();

        for (int i = 0; i < 11; i++)
        {
            print_text_color(colors_menu_1[i], textos_menu_1[i], n_salts_menu_1[i]);
        }
        opcion = 0;
        break;

    case 2:

    opcion = 1;
    break;

    case 3:

    opcion = 2;
    break;

    default:
        break;
    }

    std::cin >> opcion;

#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else
#endif

    return opcion;
}


char menu2()
{
    char opcion = 0;

    print_text_color(14, "", 3);
    print_text_color(14, "                                 BUSCAR DATOS       ", 1);
    print_text_color(14, "\n                       -------------------------------", 6);
    print_text_color(14, "                           1 - BUSCAR POR MATRICULA", 2);
    print_text_color(14, "                           2 - BUSCAR POR DNI DEL CONDUCTOR", 2);
    print_text_color(14, "                           3 - BUSCAR POR NUMERO DE SINIESTRO ASOCIADO", 3);
    print_text_color(14, "                                                                 0 - VOLVER AL MENU PRINCIPAL", 2);
    print_text_color(0, "            Elija una opcion: ", 0);
    std::cin >> opcion;

    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else
    #endif

    return opcion;
}

char menu3()
{
    char opcion = 0;
    print_text_color(14, "", 6);
    print_text_color(14, "                           1 - ASIGNAR SERVICIO MOVIL", 2);
    print_text_color(14, "                           2 - MODIFICAR FECHA DE SERVICIO MOVIL", 2);
    print_text_color(14, "                           3 - BORRAR SERVICIO MOVIL", 3);
    print_text_color(14, "                                                                 0 - VOLVER AL MENU PRINCIPAL", 2);
    print_text_color(0, "            Elija una opcion: ", 0);

    std::cin >> opcion;

    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else
    #endif

    return opcion;
}
