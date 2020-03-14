#ifdef __linux__
#include <iostream>
#include <string>
#include <sstream>
#include <fstream> // ifstream ofstream
#include "linux_adapter.h"
#elif _WIN32
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#else
#endif

#include "acc_prim_y_seg_nivel.h"


void leerinfoSM(Umovil *serv)
{
    std::ifstream fin2("smovil.txt");
    int y = 0;
    while (!fin2.eof())
    {
        fin2 >> serv->tmovil[y].fechasm.dia >> serv->tmovil[y].fechasm.mes >> serv->tmovil[y].fechasm.anyo >> serv->tmovil[y].matricula;
        y++;
    }
    serv->nmovil = y;
    fin2.close();
}

void leerinfo(Partes *part)
{
    std::ifstream fin("partes.txt");
    int y = 0;
    while (!fin.eof())
    {
        fin >> part->Conductores[y].siniestro >> part->Conductores[y].nomcon.Nombre >> part->Conductores[y].nomcon.ape1 >>
            part->Conductores[y].nomcon.ape2 >> part->Conductores[y].dnicon >> part->Conductores[y].matcoche >>
            part->Conductores[y].dicon.Poblacion >> part->Conductores[y].dicon.calle >> part->Conductores[y].email >>
            part->Coches.coches[y].marca >> part->Coches.coches[y].modelo >> part->Coches.coches[y].color >>
            part->Coches.coches[y].matcoche >> part->Coches.coches[y].dnicon >> part->Coches.coches[y].anyo >>
            part->Coches.coches[y].siniestro >> part->Coches.coches[y].danyo >> part->Coches.coches[y].fechasin.dia >>
            part->Coches.coches[y].fechasin.mes >> part->Coches.coches[y].fechasin.anyo >> part->Coches.coches[y].SM;
        y++;
    }
    part->nPartes = y;
    fin.close();
}

void escribirinfo(Partes *part)
{
    int i = 0;
    std::ofstream fout("partes.txt");

    while (i != part->nPartes - 1)
    {
        fout << part->Conductores[i].siniestro;
        fout << " ";
        fout << part->Conductores[i].nomcon.Nombre;
        fout << " ";
        fout << part->Conductores[i].nomcon.ape1;
        fout << " ";
        fout << part->Conductores[i].nomcon.ape2;
        fout << " ";
        fout << part->Conductores[i].dnicon;
        fout << " ";
        fout << part->Conductores[i].matcoche;
        fout << " ";
        fout << part->Conductores[i].dicon.Poblacion;
        fout << " ";
        fout << part->Conductores[i].dicon.calle;
        fout << " ";
        fout << part->Conductores[i].email;
        fout << " ";
        fout << part->Coches.coches[i].marca;
        fout << " ";
        fout << part->Coches.coches[i].modelo;
        fout << " ";
        fout << part->Coches.coches[i].color;
        fout << " ";
        fout << part->Coches.coches[i].matcoche;
        fout << " ";
        fout << part->Coches.coches[i].dnicon;
        fout << " ";
        fout << part->Coches.coches[i].anyo;
        fout << " ";
        fout << part->Coches.coches[i].siniestro;
        fout << " ";
        fout << part->Coches.coches[i].danyo;
        fout << " ";
        fout << part->Coches.coches[i].fechasin.dia;
        fout << " ";
        fout << part->Coches.coches[i].fechasin.mes;
        fout << " ";
        fout << part->Coches.coches[i].fechasin.anyo;
        fout << " ";
        fout << part->Coches.coches[i].SM;
        fout << std::endl;

        i++;
    }
    fout.close();
}

void escribirinfoSM(Umovil *serv)
{
    int i = 0;
    std::ofstream fout2("smovil.txt");

    while (i != serv->nmovil - 1)
    {
        fout2 << serv->tmovil[i].fechasm.dia;
        fout2 << " ";
        fout2 << serv->tmovil[i].fechasm.mes;
        fout2 << " ";
        fout2 << serv->tmovil[i].fechasm.anyo;
        fout2 << " ";
        fout2 << serv->tmovil[i].matricula;
        fout2 << std::endl;

        i++;
    }
    fout2.close();
}

void sobreescribirinfo(Partes *part)
{
    std::ofstream fout("partes.txt");
    int i = 0;
    while (i != part->nPartes - 2)
    {
        fout << part->Conductores[i].siniestro;
        fout << " ";
        fout << part->Conductores[i].nomcon.Nombre;
        fout << " ";
        fout << part->Conductores[i].nomcon.ape1;
        fout << " ";
        fout << part->Conductores[i].nomcon.ape2;
        fout << " ";
        fout << part->Conductores[i].dnicon;
        fout << " ";
        fout << part->Conductores[i].matcoche;
        fout << " ";
        fout << part->Conductores[i].dicon.Poblacion;
        fout << " ";
        fout << part->Conductores[i].dicon.calle;
        fout << " ";
        fout << part->Conductores[i].email;
        fout << " ";
        fout << part->Coches.coches[i].marca;
        fout << " ";
        fout << part->Coches.coches[i].modelo;
        fout << " ";
        fout << part->Coches.coches[i].color;
        fout << " ";
        fout << part->Coches.coches[i].matcoche;
        fout << " ";
        fout << part->Coches.coches[i].dnicon;
        fout << " ";
        fout << part->Coches.coches[i].anyo;
        fout << " ";
        fout << part->Coches.coches[i].siniestro;
        fout << " ";
        fout << part->Coches.coches[i].danyo;
        fout << " ";
        fout << part->Coches.coches[i].fechasin.dia;
        fout << " ";
        fout << part->Coches.coches[i].fechasin.mes;
        fout << " ";
        fout << part->Coches.coches[i].fechasin.anyo;
        fout << " ";
        fout << part->Coches.coches[i].SM;
        fout << std::endl;

        std::cout << "SE HAN BORRADO LOS DATOS SELECCIONADOS!" << std::endl;
        i++;
    }
    fout.close();
}

void buscarfichaMAT(Partes *part, std::string mat, bool *trobat, int *i)
{
    int y = 0;
    *trobat = false;
    while (y < part->nPartes && !*trobat)
    {
        if (mat == part->Coches.coches[y].matcoche)
        {
            *i = y;
            *trobat = true;
        }
        else
            y++;
    }
}

void introducir(Partes *part)
{
    std::string mat;
    bool trobat;
    int i;
    char sino, sino2;
    std::cout << "Introduce matricula del parte que deseas aperturar: ";
    std::cin >> mat;
    buscarfichaMAT(part, mat, &trobat, &i);
    if (trobat)
    {
        std::cout << "Esta matricula ya se encuentra en el sistema. Mostrar datos? (S/N)";
        std::cin >> sino;
        std::cout << std::endl;
        std::cout << std::endl;
        if (sino == 'S' || sino == 's')
        {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "                DATOS DEL CONDUCTOR" << std::endl;
            std::cout << "                -------------------" << std::endl;
            std::cout << std::endl;
            std::cout << "                Num. de Siniestro:  ";
            //camcolor(11);
            std::cout << part->Conductores[i].siniestro << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Nombre Completo:    ";
            //camcolor(11);
            std::cout << part->Conductores[i].nomcon.Nombre << part->Conductores[i].nomcon.ape1 << part->Conductores[i].nomcon.ape2 << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                DNI:                ";
            //camcolor(11);
            std::cout << part->Conductores[i].dnicon << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Vehiculos:          ";
            //camcolor(11);
            std::cout << part->Conductores[i].matcoche << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Direccion:          ";
            //camcolor(11);
            std::cout << part->Conductores[i].dicon.Poblacion;
            //camcolor(14);
            std::cout << "  Calle  ";
            //camcolor(11);
            std::cout << part->Conductores[i].dicon.calle << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Correo electronico: ";
            //camcolor(11);
            std::cout << part->Conductores[i].email << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                DATOS DEL VEHICULO" << std::endl;
            //camcolor(14);
            std::cout << "                ------------------" << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Marca,modelo,color: ";
            //camcolor(11);
            std::cout << part->Coches.coches[i].marca << "   " << part->Coches.coches[i].modelo << "   " << part->Coches.coches[i].color << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Anyo de matr.:      ";
            //camcolor(11);
            std::cout << part->Coches.coches[i].anyo << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Matricula:          ";
            //camcolor(11);
            std::cout << part->Coches.coches[i].matcoche << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                DNI propietario:    ";
            //camcolor(11);
            std::cout << part->Coches.coches[i].dnicon << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Sin. asociados:     ";
            //camcolor(11);
            std::cout << part->Coches.coches[i].siniestro << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                DATOS DEL SINIESTRO" << std::endl;
            //camcolor(14);
            std::cout << "                ------------------" << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Numero de siniestro: ";
            //camcolor(11);
            std::cout << part->Coches.coches[i].siniestro << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Danyos del vehiculo: ";
            //camcolor(11);
            std::cout << part->Coches.coches[i].danyo << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Fecha de ocurrencia: ";
            //camcolor(11);
            std::cout << part->Coches.coches[i].fechasin.dia << "/" << part->Coches.coches[i].fechasin.mes << "/" << part->Coches.coches[i].fechasin.anyo << std::endl;
            std::cout << std::endl;
            //camcolor(14);
            std::cout << "                Servicio movil (1:Si,0:No): ";
            //camcolor(11);
            std::cout << part->Coches.coches[i].SM << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
        }
        else if (sino == 'N' || sino == 'n')
            std::cout << "SI DESEAS MODIFICAR LA FICHA, UTILIZA LA OPCION 3 DEL MENU!" << std::endl;
        else if (sino != 'N' && sino != 'n' && sino != 'S' && sino != 's')
            std::cout << "Caracter incorrecto.";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Matricula no encontrada en el sistema." << std::endl;
        std::cout << std::endl;
        std::cout << " Desea abrir nueva ficha de CONDUCTOR y VEHICULO?(S/N)" << std::endl;
        std::cin >> sino2;
        if (sino2 == 'S' || sino2 == 's')
        {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "                                                  TABLA DE DANYOS";
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "                                  \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4" << std::endl;
            std::cout << "                                  \4                                       "
                      << "\4" << std::endl;
            std::cout << "                                  \4         P: PARABRISAS                 "
                      << "\4" << std::endl;
            std::cout << "                                  \4         R: REPARACION DE IMPACTO      "
                      << "\4" << std::endl;
            std::cout << "                                  \4         T: LUNETA TRASERA             "
                      << "\4" << std::endl;
            std::cout << "                                  \4         L: CRISTAL LATERAL            "
                      << "\4" << std::endl;
            std::cout << "                                  \4         S: TECHO SOLAR                "
                      << "\4" << std::endl;
            std::cout << "                                  \4                                       "
                      << "\4" << std::endl;
            std::cout << "                                  \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << "                NUEVA FICHA" << std::endl;
            std::cout << "                -------------------" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "            DATOS DEL SINIESTRO" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "INTRODUCE DANYOS DEL VEHICULO: ";
            ////camcolor(11);
            std::cin >> part->Coches.coches[part->nPartes - 1].danyo;
            ////camcolor(14);
            std::cout << "INTRODUCE DIA DE OCURRENCIA: ";
            ////camcolor(11);
            std::cin >> part->Coches.coches[part->nPartes - 1].fechasin.dia;
            ////camcolor(14);
            std::cout << "INTRODUCE MES DE OCURRENCIA: ";
            ////camcolor(11);
            std::cin >> part->Coches.coches[part->nPartes - 1].fechasin.mes;
            ////camcolor(14);
            std::cout << "INTRODUCE ANYO DE OCURRENCIA: ";
            ////camcolor(11);
            std::cin >> part->Coches.coches[part->nPartes - 1].fechasin.anyo;
            std::cout << std::endl;
            ////camcolor(14);
            std::cout << std::endl;
            std::cout << "            DATOS DEL CONDUCTOR" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "INTRODUCE NOMBRE DEL CONDUCTOR: ";
            ////camcolor(11);
            std::cin >> part->Conductores[part->nPartes - 1].nomcon.Nombre;
            ////camcolor(14);
            std::cout << "INTRODUCE PRIMER APELLIDO1 DEL CONDUCTOR: ";
            ////camcolor(11);
            std::cin >> part->Conductores[part->nPartes - 1].nomcon.ape1;
            ////camcolor(14);
            std::cout << "INTRODUCE SEGUNDO APELLIDO DEL CONDUCTOR: ";
            ////camcolor(11);
            std::cin >> part->Conductores[part->nPartes - 1].nomcon.ape2;
            ////camcolor(14);
            std::cout << "INTRODUCE DNI DEL CONDUCTOR: ";
            ////camcolor(11);
            std::cin >> part->Conductores[part->nPartes - 1].dnicon;
            ////camcolor(14);
            std::cout << "INTRODUCE POBLACION DEL CONDUCTOR: ";
            ////camcolor(11);
            std::cin >> part->Conductores[part->nPartes - 1].dicon.Poblacion;
            ////camcolor(14);
            std::cout << "INTRODUCE CALLE (Sin espacios) DEL CONDUCTOR: ";
            ////camcolor(11);
            std::cin >> part->Conductores[part->nPartes - 1].dicon.calle;
            ////camcolor(14);
            std::cout << "INTRODUCE E-MAIL DEL CONDUCTOR: ";
            ////camcolor(11);
            std::cin >> part->Conductores[part->nPartes - 1].email;
            ////camcolor(14);
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "            DATOS DEL VEHICULO" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "INTRODUCE MARCA DEL VEHICULO: ";
            ////camcolor(11);
            std::cin >> part->Coches.coches[part->nPartes - 1].marca;
            ////camcolor(14);
            std::cout << "INTRODUCE MODELO DEL VEHICULO: ";
            ////camcolor(11);
            std::cin >> part->Coches.coches[part->nPartes - 1].modelo;
            ////camcolor(14);
            std::cout << "INTRODUCE COLOR DEL VEHICULO: ";
            ////camcolor(11);
            std::cin >> part->Coches.coches[part->nPartes - 1].color;
            ////camcolor(14);
            std::cout << "INTRODUCE ANYO DE MATRICULACION DEL VEHICULO: ";
            ////camcolor(11);
            std::cin >> part->Coches.coches[part->nPartes - 1].anyo;
            ////camcolor(14);
            std::cout << "CLIENE SOLICITA UNIDAD MOVIL?(1:SI,0:No): ";
            ////camcolor(11);
            std::cin >> part->Coches.coches[part->nPartes - 1].SM;
            ////camcolor(14);
            std::cout << std::endl;
            part->Conductores[part->nPartes - 1].matcoche = mat;
            part->Coches.coches[part->nPartes - 1].matcoche = mat;
            part->Coches.coches[part->nPartes - 1].dnicon = part->Conductores[part->nPartes - 1].dnicon;
            part->Conductores[part->nPartes - 1].siniestro = part->Conductores[part->nPartes - 2].siniestro + 1;
            part->Coches.coches[part->nPartes - 1].siniestro = part->Coches.coches[part->nPartes - 2].siniestro + 1;
            part->nPartes++;
            escribirinfo(part);
            ////camcolor(14);
            std::cout << "SE HAN INTRODUCIDO LOS DATOS EN EL SISTEMA! El num. de siniestro es el: ";
            ////camcolor(11);
            std::cout << part->Conductores[part->nPartes - 2].siniestro << std::endl;
            system("pause");
        }
    }
}

void mostrardatos(Partes *part, bool *trobat, int *i)
{
    if (trobat)
    {

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "                DATOS DEL CONDUCTOR" << std::endl;
        std::cout << "                -------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "                Num. de Siniestro:  ";
        //camcolor(11);
        std::cout << part->Conductores[*i].siniestro << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Nombre Completo:    ";
        //camcolor(11);
        std::cout << part->Conductores[*i].nomcon.Nombre << "  " << part->Conductores[*i].nomcon.ape1 << "  " << part->Conductores[*i].nomcon.ape2 << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                DNI:                ";
        //camcolor(11);
        std::cout << part->Conductores[*i].dnicon << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Vehiculos:          ";
        //camcolor(11);
        std::cout << part->Conductores[*i].matcoche << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Direccion:          ";
        //camcolor(11);
        std::cout << part->Conductores[*i].dicon.Poblacion;
        //camcolor(14);
        std::cout << "  Calle  ";
        //camcolor(11);
        std::cout << part->Conductores[*i].dicon.calle << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Correo electronico: ";
        //camcolor(11);
        std::cout << part->Conductores[*i].email << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                DATOS DEL VEHICULO" << std::endl;
        //camcolor(14);
        std::cout << "                ------------------" << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Marca,modelo,color: ";
        //camcolor(11);
        std::cout << part->Coches.coches[*i].marca << "   " << part->Coches.coches[*i].modelo << "   " << part->Coches.coches[*i].color << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Anyo de matr.:      ";
        //camcolor(11);
        std::cout << part->Coches.coches[*i].anyo << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Matricula:          ";
        //camcolor(11);
        std::cout << part->Coches.coches[*i].matcoche << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                DNI propietario:    ";
        //camcolor(11);
        std::cout << part->Coches.coches[*i].dnicon << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Sin. asociados:     ";
        //camcolor(11);
        std::cout << part->Coches.coches[*i].siniestro << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                DATOS DEL SINIESTRO" << std::endl;
        //camcolor(14);
        std::cout << "                ------------------" << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Numero de siniestro: ";
        //camcolor(11);
        std::cout << part->Coches.coches[*i].siniestro << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Danyos del vehiculo: ";
        //camcolor(11);
        std::cout << part->Coches.coches[*i].danyo << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Fecha de ocurrencia: ";
        //camcolor(11);
        std::cout << part->Coches.coches[*i].fechasin.dia << "/" << part->Coches.coches[*i].fechasin.mes << "/" << part->Coches.coches[*i].fechasin.anyo << std::endl;
        std::cout << std::endl;
        //camcolor(14);
        std::cout << "                Servicio movil (1:Si,0:No): ";
        //camcolor(11);
        std::cout << part->Coches.coches[*i].SM << std::endl;
        std::cout << std::endl;
        //camcolor(14);
    }

    else
        std::cout << "           LA MATRICULA INTRODUCIDA NO FIGURA!" << std::endl;
}

void borrardatos(Partes *part, int y)
{

    while (y != part->nPartes + 1)
    {

        part->Conductores[y].siniestro = part->Conductores[y + 1].siniestro;
        part->Conductores[y].nomcon.Nombre = part->Conductores[y + 1].nomcon.Nombre;
        part->Conductores[y].nomcon.ape1 = part->Conductores[y + 1].nomcon.ape1;
        part->Conductores[y].nomcon.ape2 = part->Conductores[y + 1].nomcon.ape2;
        part->Conductores[y].dnicon = part->Conductores[y + 1].dnicon;
        part->Conductores[y].matcoche = part->Conductores[y + 1].matcoche;
        part->Conductores[y].dicon.Poblacion = part->Conductores[y + 1].dicon.Poblacion;
        part->Conductores[y].dicon.calle = part->Conductores[y + 1].dicon.calle;
        part->Conductores[y].email = part->Conductores[y + 1].email;
        part->Coches.coches[y].marca = part->Conductores[y + 1].siniestro;
        part->Coches.coches[y].modelo = part->Coches.coches[y + 1].modelo;
        part->Coches.coches[y].color = part->Coches.coches[y + 1].color;
        part->Coches.coches[y].matcoche = part->Coches.coches[y + 1].matcoche;
        part->Coches.coches[y].dnicon = part->Coches.coches[y + 1].dnicon;
        part->Coches.coches[y].anyo = part->Coches.coches[y + 1].anyo;
        part->Coches.coches[y].siniestro = part->Coches.coches[y + 1].siniestro;
        part->Coches.coches[y].danyo = part->Coches.coches[y + 1].danyo;
        part->Coches.coches[y].fechasin.dia = part->Coches.coches[y + 1].fechasin.dia;
        part->Coches.coches[y].fechasin.mes = part->Coches.coches[y + 1].fechasin.mes;
        part->Coches.coches[y].fechasin.anyo = part->Coches.coches[y + 1].fechasin.anyo;
        part->Coches.coches[y].SM = part->Coches.coches[y + 1].SM;
        y++;
    }

    sobreescribirinfo(part);
}

void buscarfichaDNI(Partes *part, std::string dni, bool *trobat, int *i)
{
    int y = 0;
    *trobat = false;
    while (y < part->nPartes && !*trobat)
    {
        if (dni == part->Coches.coches[y].dnicon)
        {
            *i = y;
            *trobat = true;
        }
        else
            y++;
    }
}

void buscarfichaSINI(Partes *part, int *sini, bool *trobat, int *i)
{
    int y = 0;
    *trobat = false;
    while (y < part->nPartes && !*trobat)
    {
        if (*sini == part->Coches.coches[y].siniestro)
        {
            *i = y;
            *trobat = true;
        }
        else
            y++;
    }
}

void modificardatos(Partes *part, bool *trobat, int *i)
{
    char dat;

    if (*trobat)
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "                               DATOS MODIFICABLES";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "               \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4" << std::endl;
        std::cout << "               \4                                       "
                  << "\4" << std::endl;
        std::cout << "               \4         N: Nombre                     "
                  << "\4" << std::endl;
        std::cout << "               \4         D: DNI                        "
                  << "\4" << std::endl;
        std::cout << "               \4         M: Matricula                  "
                  << "\4" << std::endl;
        std::cout << "               \4         P: Direccion                  "
                  << "\4" << std::endl;
        std::cout << "               \4         C: E-mail                     "
                  << "\4" << std::endl;
        std::cout << "               \4         S: Marca,modelo,color         "
                  << "\4" << std::endl;
        std::cout << "               \4         A: Anyo de matriculacion      "
                  << "\4" << std::endl;
        std::cout << "               \4         X: Danyos del siniestro       "
                  << "\4" << std::endl;
        std::cout << "               \4         Y: Fecha del siniestro        "
                  << "\4" << std::endl;
        std::cout << "               \4         Z: Servicio Movil             "
                  << "\4" << std::endl;
        std::cout << "               \4         T: TODOS LOS DATOS            "
                  << "\4" << std::endl;
        std::cout << "               \4                                       "
                  << "\4" << std::endl;
        std::cout << "               \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << " Introduzca el dato que desea modificar: ";
        std::cin >> dat;
        std::cout << std::endl;

        if (dat == 'T' || dat == 't')
        {
            std::cout << "                MODIFICAR FICHA" << std::endl;
            std::cout << "                -------------------" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "DATOS DEL CONDUCTOR" << std::endl;
            std::cout << std::endl;
            std::cout << "INTRODUCE NOMBRE DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].nomcon.Nombre;
            std::cout << std::endl;
            std::cout << "INTRODUCE PRIMER APELLIDO1 DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].nomcon.ape1;
            std::cout << std::endl;
            std::cout << "INTRODUCE SEGUNDO APELLIDO DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].nomcon.ape2;
            std::cout << std::endl;
            std::cout << "INTRODUCE DNI DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].dnicon;
            std::cout << std::endl;
            std::cout << "INTRODUCE POBLACION DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].dicon.Poblacion;
            std::cout << std::endl;
            std::cout << "INTRODUCE CALLE (Sin espacios) DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].dicon.calle;
            std::cout << std::endl;
            std::cout << "INTRODUCE E-MAIL DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].email;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "DATOS DEL VEHICULO" << std::endl;
            std::cout << std::endl;
            std::cout << "INTRODUCE MATRICULA DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].matcoche;
            std::cout << std::endl;
            std::cout << "INTRODUCE MARCA DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].marca;
            std::cout << std::endl;
            std::cout << "INTRODUCE MODELO DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].modelo;
            std::cout << std::endl;
            std::cout << "INTRODUCE COLOR DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].color;
            std::cout << std::endl;
            std::cout << "INTRODUCE ANYO DE MATRICULACION DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].anyo;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "DATOS DEL SINIESTRO" << std::endl;
            std::cout << std::endl;
            std::cout << "INTRODUCE DANYOS DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].danyo;
            std::cout << std::endl;
            std::cout << "INTRODUCE FECHA DE OCURRENCIA: ";
            std::cin >> part->Coches.coches[*i].fechasin.dia;
            std::cout << "/";
            std::cin >> part->Coches.coches[*i].fechasin.mes;
            std::cout << "/";
            std::cin >> part->Coches.coches[*i].fechasin.anyo;
            std::cout << std::endl;
            std::cout << "INTRODUCE SI SOLICITA UNIDAD MOVIL (1:SI,0:NO): ";
            std::cin >> part->Coches.coches[*i].SM;
            part->Conductores[*i].matcoche = part->Coches.coches[*i].matcoche;
            part->Coches.coches[*i].dnicon = part->Conductores[*i].dnicon;
        }
        else if (dat == 'N' || dat == 'n')
        {
            std::cout << "INTRODUCE NOMBRE DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].nomcon.Nombre;
            std::cout << std::endl;
            std::cout << "INTRODUCE PRIMER APELLIDO1 DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].nomcon.ape1;
            std::cout << std::endl;
            std::cout << "INTRODUCE SEGUNDO APELLIDO DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].nomcon.ape2;
        }
        else if (dat == 'D' || dat == 'd')
        {
            std::cout << "INTRODUCE DNI DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].dnicon;
            part->Coches.coches[*i].dnicon = part->Conductores[*i].dnicon;
        }
        else if (dat == 'M' || dat == 'm')
        {
            std::cout << "INTRODUCE MATRICULA DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].matcoche;
            part->Conductores[*i].matcoche = part->Coches.coches[*i].matcoche;
        }
        else if (dat == 'P' || dat == 'p')
        {
            std::cout << "INTRODUCE POBLACION DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].dicon.Poblacion;
            std::cout << std::endl;
            std::cout << "INTRODUCE CALLE (Sin espacios) DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].dicon.calle;
        }
        else if (dat == 'C' || dat == 'c')
        {
            std::cout << "INTRODUCE E-MAIL DEL CONDUCTOR: ";
            std::cin >> part->Conductores[*i].email;
        }
        else if (dat == 'S' || dat == 's')
        {
            std::cout << "INTRODUCE MARCA DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].marca;
            std::cout << std::endl;
            std::cout << "INTRODUCE MODELO DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].modelo;
            std::cout << std::endl;
            std::cout << "INTRODUCE COLOR DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].color;
        }
        else if (dat == 'A' || dat == 'a')
        {
            std::cout << "INTRODUCE ANYO DE MATRICULACION DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].anyo;
        }
        else if (dat == 'X' || dat == 'x')
        {
            std::cout << "INTRODUCE DANYOS DEL VEHICULO: ";
            std::cin >> part->Coches.coches[*i].danyo;
        }
        else if (dat == 'Y' || dat == 'y')
        {
            std::cout << "INTRODUCE FECHA DE OCURRENCIA: ";
            std::cin >> part->Coches.coches[*i].fechasin.dia;
            std::cout << " / ";
            std::cin >> part->Coches.coches[*i].fechasin.mes;
            std::cout << " / ";
            std::cin >> part->Coches.coches[*i].fechasin.anyo;
        }
        else if (dat == 'Z' || dat == 'z')
        {
            std::cout << "INTRODUCE SI SE SOLICITA UNIDAD MOVIL (1:SI,0:NO): ";
            std::cin >> part->Coches.coches[*i].SM;
        }

        escribirinfo(part);
        std::cout << "Los datos se han modificado correctamente!" << std::endl;
        std::cout << std::endl;
        system("pause");
    }
    else
        std::cout << "No se modificara ningun dato.";
}

void estadistica(Partes *part)
{
    int i = 0, PB = 0, Lun = 0, Lat = 0, Tec = 0, Repa = 0, total = 0, x = 0, y = 0, anyo1, anyo2;
    char sino;
    while (i < part->nPartes)
    {
        if (part->Coches.coches[i].danyo == 'P')
            PB++;
        else if (part->Coches.coches[i].danyo == 'T')
            Lun++;
        else if (part->Coches.coches[i].danyo == 'R')
            Repa++;
        else if (part->Coches.coches[i].danyo == 'L')
            Lat++;
        else if (part->Coches.coches[i].danyo == 'S')
            Tec++;
        i++;
    }

    total = PB + Lun + Lat + Tec + Repa;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "El total de siniestros registrados es : " << total;
    std::cout << std::endl;
    std::cout << "Total de Parabrisas: " << PB << std::endl;
    std::cout << "Total de Lunetas: " << Lun << std::endl;
    std::cout << "Total de Cristales laterales: " << Repa << std::endl;
    std::cout << "Total de Reparaciones de impacto: " << Lat << std::endl;
    std::cout << "Total de Techos solares: " << Tec << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "       VALORES REPRESENTATIVOS" << std::endl;
    std::cout << std::endl;
    std::cout << "               PB:  ";
    while (x < PB)
    {
        //camcolor(11);
        std::cout << "#";
        x++;
    }
    std::cout << std::endl;
    x = 0;
    //camcolor(14);
    std::cout << "               Rep: ";
    while (x < Repa)
    {
        //camcolor(11);
        std::cout << "#";
        x++;
    }
    std::cout << std::endl;
    x = 0;
    //camcolor(14);
    std::cout << "               Lun: ";
    while (x < Lun)
    {
        //camcolor(11);
        std::cout << "#";
        x++;
    }
    std::cout << std::endl;
    x = 0;
    //camcolor(14);
    std::cout << "               Lat: ";
    while (x < Lat)
    {
        //camcolor(11);
        std::cout << "#";
        x++;
    }
    std::cout << std::endl;
    x = 0;
    //camcolor(14);
    std::cout << "               Tec: ";
    while (x < Tec)
    {
        //camcolor(11);
        std::cout << "#";
        x++;
    }
    x = 0;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Desea filtrar los datos por anyo? (S: Si, N: Regresar)" << std::endl;
    std::cin >> sino;
    if (sino == 'S' || sino == 's')
    {

        std::cout << "Introduzca DESDE que anyo desea filtrar: ";
        //camcolor(11);
        std::cin >> anyo1;
        //camcolor(14);
        std::cout << "Introduzca HASTA que anyo desea filtrar: ";
        //camcolor(11);
        std::cin >> anyo2;
        //camcolor(14);
        i = 0;
        PB = 0;
        Lun = 0;
        Repa = 0;
        Lat = 0;
        Tec = 0;
        while (i < part->nPartes)
        {

            if (part->Coches.coches[i].fechasin.anyo <= anyo2 && part->Coches.coches[i].fechasin.anyo >= anyo1)
            {

                if (part->Coches.coches[i].danyo == 'P')
                    PB++;
                else if (part->Coches.coches[i].danyo == 'T')
                    Lun++;
                else if (part->Coches.coches[i].danyo == 'R')
                    Repa++;
                else if (part->Coches.coches[i].danyo == 'L')
                    Lat++;
                else if (part->Coches.coches[i].danyo == 'S')
                    Tec++;
            }
            i++;
        }
        total = PB + Lun + Lat + Tec + Repa;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "El total de siniestros registrados es : " << total;
        std::cout << std::endl;
        std::cout << "Total de Parabrisas: " << PB << std::endl;
        std::cout << "Total de Lunetas: " << Lun << std::endl;
        std::cout << "Total de Cristales laterales: " << Repa << std::endl;
        std::cout << "Total de Reparaciones de impacto: " << Lat << std::endl;
        std::cout << "Total de Techos solares: " << Tec << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "       VALORES REPRESENTATIVOS" << std::endl;
        std::cout << std::endl;
        std::cout << "               PB:  ";
        while (x < PB)
        {
            //camcolor(11);
            std::cout << "#";
            x++;
        }
        std::cout << std::endl;
        x = 0;
        //camcolor(14);
        std::cout << "               Rep: ";
        while (x < Repa)
        {
            //camcolor(11);
            std::cout << "#";
            x++;
        }
        std::cout << std::endl;
        x = 0;
        //camcolor(14);
        std::cout << "               Lun: ";
        while (x < Lun)
        {
            //camcolor(11);
            std::cout << "#";
            x++;
        }
        std::cout << std::endl;
        x = 0;
        //camcolor(14);
        std::cout << "               Lat: ";
        while (x < Lat)
        {
            //camcolor(11);
            std::cout << "#";
            x++;
        }
        std::cout << std::endl;
        x = 0;
        //camcolor(14);
        std::cout << "               Tec: ";
        while (x < Tec)
        {
            //camcolor(11);
            std::cout << "#";
            x++;
        }
        x = 0;
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

void mostrarSM(Partes *part, Umovil *sermovil)
{
    int i = 0, y = 0;
    bool trobat = false;
    std::cout << "                 SERVICIOS MOVILES GESTIONADOS";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    while (i < part->nPartes)
    {

        if (part->Coches.coches[i].SM)
        {
            while (y < sermovil->nmovil)
            {

                if (part->Coches.coches[i].SM && sermovil->tmovil[y].matricula == part->Coches.coches[i].matcoche)
                {
                    std::cout << "                         " << sermovil->tmovil[y].matricula;
                    //camcolor(10);
                    std::cout << "--> ASIGNADO || Fecha: " << sermovil->tmovil[y].fechasm.dia
                              << "/" << sermovil->tmovil[y].fechasm.mes << "/" << sermovil->tmovil[y].fechasm.anyo << std::endl;
                    //camcolor(14);
                    trobat = true;
                }
                y++;
            }
            y = 0;
            
            if (!trobat)
            {
                std::cout << "                         " << part->Coches.coches[i].matcoche;
                //camcolor(12);
                std::cout << "--> NO ASIGNADO!" << std::endl;
                //camcolor(14);
            }
        }

        i++;
        trobat = false;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void SMasignado(Partes *part, Umovil *sermovil)
{
    mostrarSM(part, sermovil);
    std::string mat;
    bool trobat = false, trobat2 = false;
    int i = 0, y = 0, x = 0;
    ;
    std::cout << "A QUE MATRICULA DESEA ASIGNARLE FECHA DE SERVICIO: " << std::endl;
    std::cin >> mat;

    while (i < part->nPartes)
    {
        if (mat == part->Coches.coches[i].matcoche)
            trobat = true;
        i++;
    }

    if (trobat)
    {
        while (y < sermovil->nmovil)
        {
            if (mat == sermovil->tmovil[y].matricula)
            {
                trobat2 = true;
                x = y;
            }
            y++;
        }
    }

    else if (!trobat)
    {
        std::cout << "La matricula no coincide." << std::endl;
    }

    if (trobat2 && trobat)
    {
        std::cout << mat;
        //camcolor(10);
        std::cout << "--> ASIGNADO || Fecha: "
                  << sermovil->tmovil[x].fechasm.dia << "/" << sermovil->tmovil[x].fechasm.mes << "/" << sermovil->tmovil[x].fechasm.anyo << std::endl;
        //camcolor(14);
    }

    else if (!trobat2 && trobat)
    {
        std::cout << "Introduce fecha de servicio: ";
        std::cin >> sermovil->tmovil[sermovil->nmovil - 1].fechasm.dia >> sermovil->tmovil[sermovil->nmovil - 1].fechasm.mes >> sermovil->tmovil[sermovil->nmovil - 1].fechasm.anyo;
        sermovil->tmovil[sermovil->nmovil - 1].matricula = mat;
        sermovil->nmovil++;
        //camcolor(11);
        std::cout << "        SE HA GESTIONADO EL SERVICIO CORRECTAMENTE!" << std::endl;
        escribirinfoSM(sermovil);
    }
}

void modificarSM(Umovil *sermovil)
{

    std::string mat;
    int i = 0;

    std::cout << "Que matricula desea modificar? " << std::endl;
    std::cin >> mat;
    std::cout << std::endl;
    while (i < sermovil->nmovil)
    {

        if (mat == sermovil->tmovil[i].matricula)
        {
            std::cout << "Introduce nueva fecha de servicio: ";
            std::cin >> sermovil->tmovil[i].fechasm.dia >> sermovil->tmovil[i].fechasm.mes >> sermovil->tmovil[i].fechasm.anyo;
            escribirinfoSM(sermovil);
        }

        i++;
    }
}

void borrarSM(Partes *part, Umovil *sermovil)
{
    std::string mat;
    char sino, sino2;
    bool trobat = false;
    int i = 0, y, i2 = 0;

    std::cout << "Que servicio desea anular? " << std::endl;
    std::cin >> mat;
    std::cout << std::endl;
    std::cout << "Para revertir la anulacion del servicio, debera volver a introducir los datos en <Modificar Poliza>, Esta seguro de que desea borrar el Servicio movil?(S:Si,N:No)" << std::endl;
    std::cin >> sino;
    if (sino == 'S' || sino == 's')
    {
        while (i < sermovil->nmovil)
        {

            if (mat == sermovil->tmovil[i].matricula)
            {
                y = i;
                trobat = true;
            }
            i++;
        }

        i = 0;

        if (trobat)
        {
            while (y < sermovil->nmovil)
            {

                sermovil->tmovil[y].matricula = sermovil->tmovil[y + 1].matricula;
                sermovil->tmovil[y].fechasm.dia = sermovil->tmovil[y + 1].fechasm.dia;
                sermovil->tmovil[y].fechasm.mes = sermovil->tmovil[y + 1].fechasm.mes;
                sermovil->tmovil[y].fechasm.anyo = sermovil->tmovil[y + 1].fechasm.anyo;

                escribirinfoSM(sermovil);

                y++;
            }
        }

        std::cout << "Desea anular tambien la peticion de Unidad Movil? (S:Si,N:No)" << std::endl;
        std::cin >> sino2;
        if (sino2 == 'S' || sino2 == 's')
        {
            while (i2 < part->nPartes)
            {
                if (mat == part->Coches.coches[i2].matcoche)
                {
                    part->Coches.coches[i2].SM = false;
                    escribirinfo(part);
                }
                i2++;
            }
        }

        else
        {
            //camcolor(11);
            std::cout << "Solo se ha anulado la fecha del servicio, queda pendiente de asignar nueva fecha." << std::endl;
            //camcolor(14);
        }
    }

    else
    {
        //camcolor(11);
        std::cout << "El servicio no se ha anulado." << std::endl;
        //camcolor(14);
    }
}
