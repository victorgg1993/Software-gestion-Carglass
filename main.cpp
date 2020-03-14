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

#include "logos.h"
#include "estructuras_y_tablas.h" /* ESTRUCTURAS Y TABLAS */
#include "acc_prim_y_seg_nivel.h" /* ACCIONES DE PRIMER NIVEL Y DE SEGUNDO NIVEL */
#include "funciones.h"            /* FUNCIONES */

using namespace std;

// usadas dentro el switch
void aperturar_parte(Partes *part);
void consulta_de_poliza(bool *trobat, Partes *part, int *sin, std::string dni, int *i, std::string mat, char *opcion2);
void modificar_parte(char *sino, bool *trobat, Partes *part, int *sin, std::string dni, int *i, std::string mat, char *opcion3);
void borrar_parte(char *sino, bool *trobat, Partes *part, int *sin, std::string dni, int *i, std::string mat, char *opcion4);
void servicio_movil(Partes *part, Umovil *sermovil, char *opcion5);
void estadisticas(Partes *part);

int main()
{
/*
    for (int i = 0; i < 50; i++)
    {
        std::cout << "i: " << i << " ==> ";
        printf("\033[0;%dmHello!\033[0m   ---  ", i);
        printf("\033[1;%dmHello!\033[0m\n", i);
    }
*/
    AjustarVentana(100, 60);
    SetConsoleTitle("Carglass, Servicio de Lunas");
    logo1();
    logo();
    Partes part;
    Umovil sermovil;
    std::string mat, dni;
    char opcion, opcion2, opcion3, opcion4, opcion5, sino;
    bool trobat = false; // trobat2 = false;
    int i = 0, sin = 0;

    while (opcion != '0')
    {
        //opcion = menu1();
        opcion = menu(1);
        switch (opcion)
        {
        case '1':
            aperturar_parte(&part);
            break;
        case '2':
            consulta_de_poliza(&trobat, &part, &sin, dni, &i, mat, &opcion2);
            break;
        case '3':
            modificar_parte(&sino, &trobat, &part, &sin, dni, &i, mat, &opcion3);
            break;
        case '4':
            borrar_parte(&sino, &trobat, &part, &sin, dni, &i, mat, &opcion4);
            break;
        case '5':
            servicio_movil(&part, &sermovil, &opcion5);
            break;

        case '6':
            estadisticas(&part);
            break;

        case '0':
            cout << "            GRACIAS POR UTILIZAR LA APLICACION" << endl;
            system("pause");
            break;

        default:
            cout << "           Error: INTRODUZCA UNA OPCION CORRECTA !" << endl;
            cout << "         PULSA UNA TECLA PARA VOLVER AL MENU PRINCIPAL" << endl;
            getch();
            break;
        }
    }

}

void aperturar_parte(Partes *part)
{
    cout << "                 ---------------------------------------------------------------------\n";
    cout << "                            <<<<<<<<<<        APERTURAR PARTE        >>>>>>>>>>";
    cout << "\n                 ---------------------------------------------------------------------\n\n";

    leerinfo(part);
    introducir(part);
    system("pause");
}

void consulta_de_poliza(bool *trobat, Partes *part, int *sin, std::string dni, int *i, std::string mat, char *opcion2)
{
    cout << "               ---------------------------------------------------------------------\n";
    cout << "                         <<<<<<<<<<        CONSULTA DE POLIZA       >>>>>>>>>>";
    cout << "\n               ---------------------------------------------------------------------\n\n";

    while (*opcion2 != '0')
    {
        *opcion2 = menu2();
        switch (*opcion2)
        {
        case '1':
            leerinfo(part);
            cout << "       INTRODUCE MATRICULA: " << endl;
            cin >> mat;
            buscarfichaMAT(part, mat, trobat, i);
            mostrardatos(part, trobat, i);
            break;
        case '2':
            leerinfo(part);
            cout << "       INTRODUCE DNI DEL CONDUCTOR: " << endl;
            cin >> dni;
            buscarfichaDNI(part, dni, trobat, i);
            mostrardatos(part, trobat, i);
            break;
        case '3':
            leerinfo(part);
            cout << "       INTRODUCE EL NUM. DE SINIESTRO: " << endl;
            cin >> *sin;
            buscarfichaSINI(part, sin, trobat, i);
            mostrardatos(part, trobat, i);

        case '0':
            break;

        default:
            cout << "           Error: INTRODUZCA UNA OPCION CORRECTA !" << endl;
        }
        *opcion2 = '9';

        cout << "         PULSA UNA TECLA PARA VOLVER AL MENU PRINCIPAL" << endl;

        getch();
        break;
    }
}

void modificar_parte(char *sino, bool *trobat, Partes *part, int *sin, std::string dni, int *i, std::string mat, char *opcion3)
{
    cout << "                  ---------------------------------------------------------------------\n";
    cout << "                           <<<<<<<<<<        MODIFICAR PARTE        >>>>>>>>>>";
    cout << "\n                ---------------------------------------------------------------------\n\n";

    while (*opcion3 != '0')
    {
        *opcion3 = menu2();
        switch (*opcion3)
        {
        case '1':
            leerinfo(part);
            cout << "       INTRODUCE MATRICULA: " << endl;
            cin >> mat;
            buscarfichaMAT(part, mat, trobat, i);
            mostrardatos(part, trobat, i);
            system("pause");
            if (*trobat)
            {
                cout << "Desea modificar los datos? (S/N)";
                cin >> *sino;
                if (*sino == 'S' || *sino == 's')
                    modificardatos(part, trobat, i);
                else
                    cout << "No se modificara ningun dato.";
            }

            break;
        case '2':
            leerinfo(part);
            cout << "       INTRODUCE DNI DEL CONDUCTOR: " << endl;
            cin >> dni;
            buscarfichaDNI(part, dni, trobat, i);
            mostrardatos(part, trobat, i);
            system("pause");
            if (*trobat)
            {
                cout << "Desea modificar los datos? (S/N)";
                cin >> *sino;
                if (*sino == 'S' || *sino == 's')
                    modificardatos(part, trobat, i);
                else
                    cout << "No se modificara ningun dato.";
            }
            break;
        case '3':
            leerinfo(part);
            cout << "       INTRODUCE EL NUM. DE SINIESTRO: " << endl;
            cin >> *sin;
            buscarfichaSINI(part, sin, trobat, i);
            mostrardatos(part, trobat, i);
            system("pause");
            if (*trobat)
            {
                cout << "Desea modificar los datos? (S/N)";
                cin >> *sino;
                if (*sino == 'S' || *sino == 's')
                    modificardatos(part, trobat, i);
                else
                    cout << "No se modificara ningun dato.";
            }
        case '0':
            break;

        default:
            cout << "           Error: INTRODUZCA UNA OPCION CORRECTA !" << endl;
        }

        *opcion3 = '9';

        break;
    }
}

void borrar_parte(char *sino, bool *trobat, Partes *part, int *sin, std::string dni, int *i, std::string mat, char *opcion4)
{
    cout << "                  ---------------------------------------------------------------------\n";
    cout << "                            <<<<<<<<<<        BORRAR PARTE       >>>>>>>>>>";
    cout << "\n                 ---------------------------------------------------------------------\n\n";
    while (*opcion4 != '0')
    {
        *opcion4 = menu2();
        switch (*opcion4)
        {
        case '1':
            leerinfo(part);
            cout << "       INTRODUCE MATRICULA: " << endl;
            cin >> mat;
            buscarfichaMAT(part, mat, trobat, i);
            mostrardatos(part, trobat, i);
            if (*trobat)
            {
                cout << "Desea borrar los datos? (S/N)";
                cin >> *sino;
                if (*sino == 'S' || *sino == 's')
                {
                    borrardatos(part, *i);
                }
                else
                    cout << "No se borraran datos.";
            }
            system("pause");

            break;
        case '2':
            leerinfo(part);
            cout << "       INTRODUCE DNI DEL CONDUCTOR: " << endl;
            cin >> dni;
            buscarfichaDNI(part, dni, trobat, i);
            mostrardatos(part, trobat, i);
            if (*trobat)
            {
                cout << "Desea borrar los datos? (S/N)";
                cin >> *sino;
                if (*sino == 'S' || *sino == 's')
                {
                    borrardatos(part, *i);
                }
                else
                    cout << "No se borraran datos.";
            }
            system("pause");
            break;
        case '3':
            leerinfo(part);
            cout << "       INTRODUCE EL NUM. DE SINIESTRO: " << endl;
            cin >> *sin;
            buscarfichaSINI(part, sin, trobat, i);
            mostrardatos(part, trobat, i);
            if (*trobat)
            {
                cout << "Desea borrar los datos? (S/N)";
                cin >> *sino;
                if (*sino == 'S' || *sino == 's')
                {
                    borrardatos(part, *i);
                }
                else
                    cout << "No se borraran datos.";
            }
            system("pause");
        case '0':
            break;

        default:
            cout << "           Error: INTRODUZCA UNA OPCION CORRECTA !" << endl;
        }
        *opcion4 = '9';
        cout << "         PULSA UNA TECLA PARA VOLVER AL MENU PRINCIPAL" << endl;
        getch();
        break;
    }
}

void servicio_movil(Partes *part, Umovil *sermovil, char *opcion5)
{

    cout << "                 ---------------------------------------------------------------------\n";
    cout << "                            <<<<<<<<<<        SERVICIO MOVIL        >>>>>>>>>>";
    cout << "\n                 ---------------------------------------------------------------------\n\n";
    leerinfo(part);
    leerinfoSM(sermovil);
    cout << sermovil->nmovil;
    cout << endl;
    cout << endl;
    mostrarSM(part, sermovil);

    while (*opcion5 != '0')
    {
        *opcion5 = menu3();
        switch (*opcion5)
        {
        case '1':
            leerinfo(part);
            leerinfoSM(sermovil);
            SMasignado(part, sermovil);

            break;
        case '2':
            leerinfo(part);
            leerinfoSM(sermovil);
            mostrarSM(part, sermovil);
            modificarSM(sermovil);
            break;
        case '3':
            leerinfo(part);
            leerinfoSM(sermovil);
            mostrarSM(part, sermovil);
            borrarSM(part, sermovil);

        case '0':
            break;

        default:
            cout << "           Error: INTRODUZCA UNA OPCION CORRECTA !" << endl;
        }
        *opcion5 = '9';
        cout << "         PULSA UNA TECLA PARA VOLVER AL MENU PRINCIPAL" << endl;
        getch();
        break;
    }
}

void estadisticas(Partes *part)
{
    cout << "                 ---------------------------------------------------------------------\n";
    cout << "                            <<<<<<<<<<        ESTADISTICAS        >>>>>>>>>>";
    cout << "\n                 ---------------------------------------------------------------------\n\n";
    leerinfo(part);
    estadistica(part);
    system("pause");
}