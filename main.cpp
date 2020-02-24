#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;
const int pmax=100;

/* ESTRUCTURAS Y TABLAS */

struct Nombre{
    string Nombre,ape1,ape2;};
struct Fecha{
    int dia, mes, anyo;};
struct Direccion{
    int CP;
    string Poblacion, calle;};
struct Coche{
    string marca,modelo,color;
    string matcoche;
    string dnicon;
    int anyo,siniestro;
    Fecha fechasin;
    char danyo;
    bool SM;
};
struct Conductor{
    string email;
    Direccion dicon;
    string matcoche;
    Nombre nomcon;
    string dnicon;
    int siniestro;};
struct SM{
    Fecha fechasm;
    string matricula;
};

typedef SM SerMov[pmax];
typedef Conductor tCon[pmax];
typedef Coche tCoche[pmax];

struct tCondu{
  tCon coches;
  int nCondu;};
struct tCoch{
  tCoche coches;
  int nCoches;};
struct Partes{
    tCon Conductores;
    tCoch Coches;
    int nPartes;};
struct Umovil{
SerMov tmovil;
int nmovil;
};


/* ACCIONES QUE NO FORMAN PARTE DEL TEMARIO*/
void camcolor(int x){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);}
void logo1(){
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
camcolor(14);cout <<"                                       #####";camcolor(12) ;cout <<" ###### ##### ############ "<<endl;
camcolor(14);cout <<"                                     # #####";camcolor(12) ;cout <<" ###### ##### ########### " <<endl;
camcolor(14);cout <<"                                    ## #####";camcolor(12) ;cout <<" ###### ##### ##########  " <<endl;
camcolor(14);cout <<"                                   ### #####";camcolor(12) ;cout <<" ###### ##### #########   " <<endl;
camcolor(14);cout <<"                                  #### #####";camcolor(12) ;cout <<" ###### ##### ########    " <<endl;
camcolor(14);cout <<"                                 ##### #####";camcolor(12) ;cout <<" ###### ##### #######     " <<endl;
camcolor(14);cout <<"                                ###### #####";camcolor(12) ;cout <<" ###### ##### ######      " <<endl;
camcolor(14);cout <<"                               ####### #####";camcolor(12) ;cout <<" ###### ##### #####       " <<endl;
camcolor(14);cout <<"                              ######## #####";camcolor(12) ;cout <<" ###### ##### ####        " <<endl;
camcolor(14);cout <<"                             ######### #####";camcolor(12) ;cout <<" ###### ##### ###         " <<endl;
camcolor(14);cout <<"                            ########## #####";camcolor(12) ;cout <<" ###### ##### ##          " <<endl;
camcolor(14);cout <<"                           ########### #####";camcolor(12) ;cout <<" ###### ##### #          " <<endl;
}
void logo(){
    camcolor(12);
cout <<endl;
cout <<endl;
cout <<endl;
cout <<"              ######    ###     ######     ######  ##         ###     #####     #####" <<endl;
cout <<"             #######    ###     #######   #######  ##         ###    #######   #######" <<endl;
cout <<"             ##   ###  #####    ##    ##  ##   ### ##        #####  ###   ### ###   ###" <<endl;
cout <<"            ##        ##   ##   ##    ## ##        ##       ##   ##  ###       ###" <<endl;
cout <<"            ##        ##   ##   ##    ## ##        ##       ##   ##   ###       ###" <<endl;
cout <<"            ##        ##   ##   ##   ### ##    ### ##       ##   ##    ###       ###" <<endl;
cout <<"            ##        ##   ##   ######   ##  ##### ##       ##   ##     ###       ###" <<endl;
cout <<"            ##        ##   ##   #####    ##     ## ##       ##   ##      ###       ###" <<endl;
cout <<"            ##        #######   ##  ##   ##     ## ##       #######       ###       ###" <<endl;
cout <<"            ###       ##   ##   ##   ##  ###    ## ##       #######        ##        ##" <<endl;
cout <<"             ###  ### ##   ##   ##    ##  ###  ### ##       ##   ##  ###  ###  ###  ###" <<endl;
cout <<"             ####### ###   ###  ##    ##  #######  ######  ###    ##  ######    ######" <<endl;
cout <<"               ###  ####   #######    ###   ###    ###### ####    ####  ###       ###" <<endl;}
void gotoxy(int x,int y){
 HANDLE consola; COORD posicion;
 consola = GetStdHandle(STD_OUTPUT_HANDLE);
 posicion.X= x; posicion.Y= y;
 SetConsoleCursorPosition(consola, posicion);
}

/* ACCIONES DE PRIMER NIVEL Y DE SEGUNDO NIVEL */
void leerinfoSM(Umovil & serv){
    ifstream fin2("smovil.txt");
    int y=0;
    while (!fin2.eof() ){
       fin2>> serv.tmovil[y].fechasm.dia
       >> serv.tmovil[y].fechasm.mes
       >> serv.tmovil[y].fechasm.anyo
       >> serv.tmovil[y].matricula;
       y++;
    }
        serv.nmovil=y;
        fin2.close();
};
void leerinfo(Partes& part){
    ifstream fin("partes.txt");
    int y=0;
    while (!fin.eof() ){
       fin>>part.Conductores[y].siniestro
       >> part.Conductores[y].nomcon.Nombre
       >> part.Conductores[y].nomcon.ape1
       >> part.Conductores[y].nomcon.ape2
       >> part.Conductores[y].dnicon
       >> part.Conductores[y].matcoche
       >> part.Conductores[y].dicon.Poblacion
       >> part.Conductores[y].dicon.calle
       >> part.Conductores[y].email
       >> part.Coches.coches[y].marca
       >> part.Coches.coches[y].modelo
       >> part.Coches.coches[y].color
       >> part.Coches.coches[y].matcoche
       >> part.Coches.coches[y].dnicon
       >> part.Coches.coches[y].anyo
       >> part.Coches.coches[y].siniestro
       >> part.Coches.coches[y].danyo
       >> part.Coches.coches[y].fechasin.dia
       >> part.Coches.coches[y].fechasin.mes
       >> part.Coches.coches[y].fechasin.anyo
       >> part.Coches.coches[y].SM;
       y++;
    }
        part.nPartes=y;
        fin.close();
};
void escribirinfo(Partes& part){
    int i=0;
    ofstream fout("partes.txt");

 	    while(i!=part.nPartes-1){
 		fout <<part.Conductores[i].siniestro;
 		fout <<" ";
 		fout <<part.Conductores[i].nomcon.Nombre;
 		fout <<" ";
 		fout <<part.Conductores[i].nomcon.ape1;
 		fout <<" ";
 		fout <<part.Conductores[i].nomcon.ape2;
 		fout <<" ";
 		fout <<part.Conductores[i].dnicon;
 		fout <<" ";
 		fout <<part.Conductores[i].matcoche;
 		fout <<" ";
 		fout <<part.Conductores[i].dicon.Poblacion;
 		fout <<" ";
 		fout <<part.Conductores[i].dicon.calle;
 		fout <<" ";
 		fout <<part.Conductores[i].email;
 		fout <<" ";
 		fout <<part.Coches.coches[i].marca;
 		fout <<" ";
 		fout <<part.Coches.coches[i].modelo;
 		fout <<" ";
 		fout <<part.Coches.coches[i].color;
 		fout <<" ";
 		fout <<part.Coches.coches[i].matcoche;
 		fout <<" ";
 		fout <<part.Coches.coches[i].dnicon;
 		fout <<" ";
 		fout <<part.Coches.coches[i].anyo;
 		fout <<" ";
 		fout <<part.Coches.coches[i].siniestro;
 		fout <<" ";
 		fout <<part.Coches.coches[i].danyo;
 		fout <<" ";
 		fout <<part.Coches.coches[i].fechasin.dia;
 		fout <<" ";
 		fout <<part.Coches.coches[i].fechasin.mes;
 		fout <<" ";
 		fout <<part.Coches.coches[i].fechasin.anyo;
 		fout <<" ";
 		fout <<part.Coches.coches[i].SM;
 		fout <<endl;


 		i++;
 	}
 	fout.close();
}
void escribirinfoSM(Umovil& serv){
    int i=0;
    ofstream fout2("smovil.txt");

 	    while(i!= serv.nmovil-1){
 		fout2 <<serv.tmovil[i].fechasm.dia;
 		fout2 <<" ";
 		fout2 <<serv.tmovil[i].fechasm.mes;
 		fout2 <<" ";
 		fout2 <<serv.tmovil[i].fechasm.anyo;
 		fout2 <<" ";
 		fout2 <<serv.tmovil[i].matricula;
 		fout2 <<endl;


 		i++;
 	}
 	fout2.close();
}
void sobreescribirinfo(Partes& part){
    ofstream fout("partes.txt");
    int i=0;
    while (i!=part.nPartes-2)
 	{
 		fout <<part.Conductores[i].siniestro;
 		fout <<" ";
 		fout <<part.Conductores[i].nomcon.Nombre;
 		fout <<" ";
 		fout <<part.Conductores[i].nomcon.ape1;
 		fout <<" ";
 		fout <<part.Conductores[i].nomcon.ape2;
 		fout <<" ";
 		fout <<part.Conductores[i].dnicon;
 		fout <<" ";
 		fout <<part.Conductores[i].matcoche;
 		fout <<" ";
 		fout <<part.Conductores[i].dicon.Poblacion;
 		fout <<" ";
 		fout <<part.Conductores[i].dicon.calle;
 		fout <<" ";
 		fout <<part.Conductores[i].email;
 		fout <<" ";
 		fout <<part.Coches.coches[i].marca;
 		fout <<" ";
 		fout <<part.Coches.coches[i].modelo;
 		fout <<" ";
 		fout <<part.Coches.coches[i].color;
 		fout <<" ";
 		fout <<part.Coches.coches[i].matcoche;
 		fout <<" ";
 		fout <<part.Coches.coches[i].dnicon;
 		fout <<" ";
 		fout <<part.Coches.coches[i].anyo;
 		fout <<" ";
 		fout <<part.Coches.coches[i].siniestro;
 		fout <<" ";
 		fout <<part.Coches.coches[i].danyo;
 		fout <<" ";
 		fout <<part.Coches.coches[i].fechasin.dia;
 		fout <<" ";
 		fout <<part.Coches.coches[i].fechasin.mes;
 		fout <<" ";
 		fout <<part.Coches.coches[i].fechasin.anyo;
 		fout <<" ";
 		fout <<part.Coches.coches[i].SM;
 		fout <<endl;

        cout << "SE HAN BORRADO LOS DATOS SELECCIONADOS!"<< endl;
 		i++;
 	}
 	fout.close();
}
void buscarfichaMAT( Partes part,string mat, bool &trobat , int&i){
int y=0;
trobat=false;
    while( y < part.nPartes && !trobat) {
                if(mat == part.Coches.coches[y].matcoche){i=y; trobat=true;}
                else y++;}}
void introducir(Partes& part){
    string mat;
    bool trobat;
    int i;
    char sino,sino2;
    cout << "Introduce matricula del parte que deseas aperturar: ";
    cin >> mat;
    buscarfichaMAT(part,mat,trobat,i);
    if (trobat) {
        cout << "Esta matricula ya se encuentra en el sistema. Mostrar datos? (S/N)";
        cin >> sino;
        cout <<endl;
        cout <<endl;
        if (sino=='S' || sino== 's'){cout <<endl;
                cout <<endl;
                cout <<"                DATOS DEL CONDUCTOR"<< endl;
                cout <<"                -------------------"<<endl;
                cout <<endl;
                cout <<"                Num. de Siniestro:  ";camcolor(11) ;cout <<part.Conductores[i].siniestro <<endl;
                cout <<endl;
                camcolor(14); cout <<"                Nombre Completo:    ";camcolor(11) ;cout <<part.Conductores[i].nomcon.Nombre<< part.Conductores[i].nomcon.ape1 << part.Conductores[i].nomcon.ape2 <<endl;
                cout <<endl;
                camcolor(14); cout <<"                DNI:                " ;camcolor(11) ;cout <<part.Conductores[i].dnicon <<endl;
                cout <<endl;
                camcolor(14); cout <<"                Vehiculos:          ";camcolor(11) ;cout <<part.Conductores[i].matcoche<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Direccion:          " ;camcolor(11) ;cout << part.Conductores[i].dicon.Poblacion;camcolor(14); cout<<"  Calle  ";camcolor(11) ;cout <<part.Conductores[i].dicon.calle<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Correo electronico: ";camcolor(11) ;cout << part.Conductores[i].email <<endl;
                cout <<endl;
                cout <<endl;
                cout <<endl;
                camcolor(14); cout <<"                DATOS DEL VEHICULO" <<endl;
                camcolor(14); cout <<"                ------------------"<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Marca,modelo,color: ";camcolor(11) ;cout << part.Coches.coches[i].marca<<"   " <<part.Coches.coches[i].modelo <<"   " <<part.Coches.coches[i].color<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Anyo de matr.:      ";camcolor(11) ;cout << part.Coches.coches[i].anyo<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Matricula:          ";camcolor(11) ;cout << part.Coches.coches[i].matcoche<<endl;
                cout <<endl;
                camcolor(14); cout <<"                DNI propietario:    ";camcolor(11) ;cout << part.Coches.coches[i].dnicon<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Sin. asociados:     ";camcolor(11) ;cout << part.Coches.coches[i].siniestro<<endl;
                cout <<endl;
                cout <<endl;
                cout <<endl;
                camcolor(14); cout <<"                DATOS DEL SINIESTRO" <<endl;
                camcolor(14); cout <<"                ------------------"<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Numero de siniestro: ";camcolor(11) ;cout << part.Coches.coches[i].siniestro<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Danyos del vehiculo: ";camcolor(11) ;cout << part.Coches.coches[i].danyo<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Fecha de ocurrencia: ";camcolor(11) ;cout << part.Coches.coches[i].fechasin.dia<<"/" <<part.Coches.coches[i].fechasin.mes << "/" << part.Coches.coches[i].fechasin.anyo << endl;
                cout <<endl;
                camcolor(14); cout <<"                Servicio movil (1:Si,0:No): ";camcolor(11);cout <<part.Coches.coches[i].SM<<endl;
                cout <<endl;
                cout <<endl;
                cout <<endl;}
            else if (sino=='N' || sino=='n') cout << "SI DESEAS MODIFICAR LA FICHA, UTILIZA LA OPCION 3 DEL MENU!"<< endl;
            else if(sino!='N' && sino !='n' && sino!='S' && sino!= 's') cout << "Caracter incorrecto.";
            cout <<endl;
            cout <<endl;
            }
        else {
            cout <<endl;
            cout << "Matricula no encontrada en el sistema."<<endl;
            cout <<endl;
            cout <<" Desea abrir nueva ficha de CONDUCTOR y VEHICULO?(S/N)"<<endl;
            cin >> sino2;
            if (sino2=='S'||sino2=='s'){
                    cout <<endl;
                    cout <<endl;
                      cout <<endl;

                cout <<endl;
                cout << endl;
                        cout << "                                                  TABLA DE DANYOS";
                        cout << endl;
                        cout << endl;
                        cout << "                                  \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4"<< endl;
                        cout << "                                  \4                                       " << "\4" << endl;
                        cout << "                                  \4         P: PARABRISAS                 " << "\4" << endl;
                        cout << "                                  \4         R: REPARACION DE IMPACTO      " << "\4" << endl;
                        cout << "                                  \4         T: LUNETA TRASERA             " << "\4" << endl;
                        cout << "                                  \4         L: CRISTAL LATERAL            " << "\4" << endl;
                        cout << "                                  \4         S: TECHO SOLAR                " << "\4" << endl;
                        cout << "                                  \4                                       " << "\4" << endl;
                        cout << "                                  \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4"<< endl;
                        cout << endl;
                        cout << endl;

                    cout <<"                NUEVA FICHA"<< endl;
                cout <<"                -------------------"<<endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout <<"            DATOS DEL SINIESTRO"<< endl;
                cout <<endl;
                cout << endl;
                cout << "INTRODUCE DANYOS DEL VEHICULO: "; camcolor(11); cin >> part.Coches.coches[part.nPartes-1].danyo;
                camcolor(14);cout << "INTRODUCE DIA DE OCURRENCIA: ";camcolor(11);cin >> part.Coches.coches[part.nPartes-1].fechasin.dia;
                camcolor(14);cout << "INTRODUCE MES DE OCURRENCIA: ";camcolor(11);cin >> part.Coches.coches[part.nPartes-1].fechasin.mes;
                camcolor(14);cout << "INTRODUCE ANYO DE OCURRENCIA: ";camcolor(11);cin >> part.Coches.coches[part.nPartes-1].fechasin.anyo;
                cout << endl;
                camcolor(14);
                cout <<endl;
                cout <<"            DATOS DEL CONDUCTOR"<< endl;
                cout <<endl;
                cout <<endl;
                cout << "INTRODUCE NOMBRE DEL CONDUCTOR: "; camcolor(11); cin >> part.Conductores[part.nPartes-1].nomcon.Nombre;
                camcolor(14);cout << "INTRODUCE PRIMER APELLIDO1 DEL CONDUCTOR: "; camcolor(11); cin >> part.Conductores[part.nPartes-1].nomcon.ape1;
                camcolor(14);cout << "INTRODUCE SEGUNDO APELLIDO DEL CONDUCTOR: "; camcolor(11); cin >> part.Conductores[part.nPartes-1].nomcon.ape2;
                camcolor(14);cout << "INTRODUCE DNI DEL CONDUCTOR: "; camcolor(11); cin >> part.Conductores[part.nPartes-1].dnicon;
                camcolor(14);cout << "INTRODUCE POBLACION DEL CONDUCTOR: "; camcolor(11); cin >> part.Conductores[part.nPartes-1].dicon.Poblacion;
                camcolor(14);cout << "INTRODUCE CALLE (Sin espacios) DEL CONDUCTOR: ";camcolor(11);  cin >> part.Conductores[part.nPartes-1].dicon.calle;
                camcolor(14);cout << "INTRODUCE E-MAIL DEL CONDUCTOR: ";camcolor(11);  cin >> part.Conductores[part.nPartes-1].email;
                camcolor(14);cout <<endl;
                cout <<endl;
                cout <<"            DATOS DEL VEHICULO"<< endl;
                cout <<endl;
                cout <<endl;
                cout << "INTRODUCE MARCA DEL VEHICULO: "; camcolor(11); cin >> part.Coches.coches[part.nPartes-1].marca;
                camcolor(14); cout << "INTRODUCE MODELO DEL VEHICULO: ";camcolor(11);  cin >> part.Coches.coches[part.nPartes-1].modelo;
                camcolor(14);cout << "INTRODUCE COLOR DEL VEHICULO: "; camcolor(11); cin >> part.Coches.coches[part.nPartes-1].color;
                camcolor(14);cout << "INTRODUCE ANYO DE MATRICULACION DEL VEHICULO: ";camcolor(11);  cin >> part.Coches.coches[part.nPartes-1].anyo;
                camcolor(14);cout << "CLIENE SOLICITA UNIDAD MOVIL?(1:SI,0:No): ";camcolor(11);  cin >> part.Coches.coches[part.nPartes-1].SM;
                camcolor(14);cout <<endl;
                part.Conductores[part.nPartes-1].matcoche=mat;
                part.Coches.coches[part.nPartes-1].matcoche=mat;
                part.Coches.coches[part.nPartes-1].dnicon=part.Conductores[part.nPartes-1].dnicon;
                part.Conductores[part.nPartes-1].siniestro=part.Conductores[part.nPartes-2].siniestro+1;
                part.Coches.coches[part.nPartes-1].siniestro=part.Coches.coches[part.nPartes-2].siniestro+1;
                part.nPartes++;
                escribirinfo(part);
                camcolor(14);cout << "SE HAN INTRODUCIDO LOS DATOS EN EL SISTEMA! El num. de siniestro es el: ";camcolor(11);cout << part.Conductores[part.nPartes-2].siniestro<< endl;
                system ("pause");
                }

            }

}
void mostrardatos(Partes part,bool trobat,int i){
if (trobat){

                cout <<endl;
                cout <<endl;
                cout <<"                DATOS DEL CONDUCTOR"<< endl;
                cout <<"                -------------------"<<endl;
                cout <<endl;
                cout <<"                Num. de Siniestro:  ";camcolor(11) ;cout <<part.Conductores[i].siniestro <<endl;
                cout <<endl;
                camcolor(14); cout <<"                Nombre Completo:    ";camcolor(11) ;cout <<part.Conductores[i].nomcon.Nombre<< "  " <<part.Conductores[i].nomcon.ape1 <<"  " << part.Conductores[i].nomcon.ape2 <<endl;
                cout <<endl;
                camcolor(14); cout <<"                DNI:                " ;camcolor(11) ;cout <<part.Conductores[i].dnicon <<endl;
                cout <<endl;
                camcolor(14); cout <<"                Vehiculos:          ";camcolor(11) ;cout <<part.Conductores[i].matcoche<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Direccion:          " ;camcolor(11) ;cout << part.Conductores[i].dicon.Poblacion;camcolor(14); cout<<"  Calle  ";camcolor(11) ;cout <<part.Conductores[i].dicon.calle<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Correo electronico: ";camcolor(11) ;cout << part.Conductores[i].email <<endl;
                cout <<endl;
                cout <<endl;
                cout <<endl;
                camcolor(14); cout <<"                DATOS DEL VEHICULO" <<endl;
                camcolor(14); cout <<"                ------------------"<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Marca,modelo,color: ";camcolor(11) ;cout << part.Coches.coches[i].marca<<"   " <<part.Coches.coches[i].modelo <<"   " <<part.Coches.coches[i].color<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Anyo de matr.:      ";camcolor(11) ;cout << part.Coches.coches[i].anyo<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Matricula:          ";camcolor(11) ;cout << part.Coches.coches[i].matcoche<<endl;
                cout <<endl;
                camcolor(14); cout <<"                DNI propietario:    ";camcolor(11) ;cout << part.Coches.coches[i].dnicon<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Sin. asociados:     ";camcolor(11) ;cout << part.Coches.coches[i].siniestro<<endl;
                cout <<endl;
                cout <<endl;
                cout <<endl;
                camcolor(14); cout <<"                DATOS DEL SINIESTRO" <<endl;
                camcolor(14); cout <<"                ------------------"<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Numero de siniestro: ";camcolor(11) ;cout << part.Coches.coches[i].siniestro<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Danyos del vehiculo: ";camcolor(11) ;cout << part.Coches.coches[i].danyo<<endl;
                cout <<endl;
                camcolor(14); cout <<"                Fecha de ocurrencia: ";camcolor(11) ;cout << part.Coches.coches[i].fechasin.dia<<"/" <<part.Coches.coches[i].fechasin.mes << "/" << part.Coches.coches[i].fechasin.anyo << endl;
                cout <<endl;
                camcolor(14); cout <<"                Servicio movil (1:Si,0:No): ";camcolor(11);cout <<part.Coches.coches[i].SM<<endl;
                cout <<endl;
                camcolor(14);
               }

                    else cout << "           LA MATRICULA INTRODUCIDA NO FIGURA!" << endl;}
void borrardatos(Partes&part, int y){

        while (y!=part.nPartes+1){

            part.Conductores[y].siniestro=part.Conductores[y+1].siniestro;
            part.Conductores[y].nomcon.Nombre=part.Conductores[y+1].nomcon.Nombre;
            part.Conductores[y].nomcon.ape1=part.Conductores[y+1].nomcon.ape1;
            part.Conductores[y].nomcon.ape2=part.Conductores[y+1].nomcon.ape2;
            part.Conductores[y].dnicon=part.Conductores[y+1].dnicon;
            part.Conductores[y].matcoche=part.Conductores[y+1].matcoche;
            part.Conductores[y].dicon.Poblacion=part.Conductores[y+1].dicon.Poblacion;
            part.Conductores[y].dicon.calle=part.Conductores[y+1].dicon.calle;
            part.Conductores[y].email=part.Conductores[y+1].email;
            part.Coches.coches[y].marca=part.Conductores[y+1].siniestro;
            part.Coches.coches[y].modelo=part.Coches.coches[y+1].modelo;
            part.Coches.coches[y].color=part.Coches.coches[y+1].color;
            part.Coches.coches[y].matcoche=part.Coches.coches[y+1].matcoche;
            part.Coches.coches[y].dnicon=part.Coches.coches[y+1].dnicon;
            part.Coches.coches[y].anyo=part.Coches.coches[y+1].anyo;
            part.Coches.coches[y].siniestro=part.Coches.coches[y+1].siniestro;
            part.Coches.coches[y].danyo=part.Coches.coches[y+1].danyo;
            part.Coches.coches[y].fechasin.dia=part.Coches.coches[y+1].fechasin.dia;
            part.Coches.coches[y].fechasin.mes=part.Coches.coches[y+1].fechasin.mes;
            part.Coches.coches[y].fechasin.anyo=part.Coches.coches[y+1].fechasin.anyo;
            part.Coches.coches[y].SM=part.Coches.coches[y+1].SM;
       y++;



        }

    sobreescribirinfo(part);
}
void buscarfichaDNI( Partes part,string dni, bool&trobat,int&i){
int y=0;
trobat=false;
    while( y < part.nPartes && !trobat) {
                if(dni == part.Coches.coches[y].dnicon){i=y; trobat=true;}
                else y++;}}
void buscarfichaSINI( Partes part,int sini, bool &trobat , int&i){
int y=0;
trobat=false;
    while( y < part.nPartes && !trobat) {
                if(sini == part.Coches.coches[y].siniestro){i=y; trobat=true;}
                else y++;}}
void modificardatos(Partes&part,bool trobat,int i){
        char dat;
      if (trobat){      cout << endl;
                        cout << endl;
                        cout << "                               DATOS MODIFICABLES";
                        cout << endl;
                        cout << endl;
                        cout << "               \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4"<< endl;
                        cout << "               \4                                       " << "\4" << endl;
                        cout << "               \4         N: Nombre                     " << "\4" << endl;
                        cout << "               \4         D: DNI                        " << "\4" << endl;
                        cout << "               \4         M: Matricula                  " << "\4" << endl;
                        cout << "               \4         P: Direccion                  " << "\4" << endl;
                        cout << "               \4         C: E-mail                     " << "\4" << endl;
                        cout << "               \4         S: Marca,modelo,color         " << "\4" << endl;
                        cout << "               \4         A: Anyo de matriculacion      " << "\4" << endl;
                        cout << "               \4         X: Danyos del siniestro       " << "\4" << endl;
                        cout << "               \4         Y: Fecha del siniestro        " << "\4" << endl;
                        cout << "               \4         Z: Servicio Movil             " << "\4" << endl;
                        cout << "               \4         T: TODOS LOS DATOS            " << "\4" << endl;
                        cout << "               \4                                       " << "\4" << endl;
                        cout << "               \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4"<< endl;
                        cout << endl;
                        cout << endl;
                        cout << " Introduzca el dato que desea modificar: "; cin >> dat;
                        cout <<endl;

                        if(dat=='T'||dat=='t'){

                cout <<"                MODIFICAR FICHA"<< endl;
                cout <<"                -------------------"<<endl;
                cout <<endl;
                cout <<endl;
                cout <<"DATOS DEL CONDUCTOR"<< endl;
                cout <<endl;
                cout << "INTRODUCE NOMBRE DEL CONDUCTOR: "; cin >> part.Conductores[i].nomcon.Nombre;
                cout <<endl;
                cout << "INTRODUCE PRIMER APELLIDO1 DEL CONDUCTOR: "; cin >> part.Conductores[i].nomcon.ape1;
                cout <<endl;
                cout << "INTRODUCE SEGUNDO APELLIDO DEL CONDUCTOR: "; cin >> part.Conductores[i].nomcon.ape2;
                cout <<endl;
                cout << "INTRODUCE DNI DEL CONDUCTOR: "; cin >> part.Conductores[i].dnicon;
                cout <<endl;
                cout << "INTRODUCE POBLACION DEL CONDUCTOR: "; cin >> part.Conductores[i].dicon.Poblacion;
                cout <<endl;
                cout << "INTRODUCE CALLE (Sin espacios) DEL CONDUCTOR: "; cin >> part.Conductores[i].dicon.calle;
                cout <<endl;
                cout << "INTRODUCE E-MAIL DEL CONDUCTOR: "; cin >> part.Conductores[i].email;
                cout <<endl;
                cout <<endl;
                cout <<"DATOS DEL VEHICULO"<< endl;
                cout <<endl;
                cout << "INTRODUCE MATRICULA DEL VEHICULO: "; cin >> part.Coches.coches[i].matcoche;
                cout <<endl;
                cout << "INTRODUCE MARCA DEL VEHICULO: "; cin >> part.Coches.coches[i].marca;
                cout <<endl;
                cout << "INTRODUCE MODELO DEL VEHICULO: "; cin >> part.Coches.coches[i].modelo;
                cout <<endl;
                cout << "INTRODUCE COLOR DEL VEHICULO: "; cin >> part.Coches.coches[i].color;
                cout <<endl;
                cout << "INTRODUCE ANYO DE MATRICULACION DEL VEHICULO: "; cin >> part.Coches.coches[i].anyo;
                cout <<endl;
                cout <<endl;
                cout <<"DATOS DEL SINIESTRO"<< endl;
                cout <<endl;
                cout << "INTRODUCE DANYOS DEL VEHICULO: "; cin >> part.Coches.coches[i].danyo;
                cout <<endl;
                cout << "INTRODUCE FECHA DE OCURRENCIA: "; cin >> part.Coches.coches[i].fechasin.dia;cout<< "/"; cin>> part.Coches.coches[i].fechasin.mes; cout << "/";cin>> part.Coches.coches[i].fechasin.anyo;
                cout <<endl;
                cout << "INTRODUCE SI SOLICITA UNIDAD MOVIL (1:SI,0:NO): "; cin >> part.Coches.coches[i].SM;
                part.Conductores[i].matcoche=part.Coches.coches[i].matcoche;
                part.Coches.coches[i].dnicon=part.Conductores[i].dnicon;
                }
                            else if(dat=='N'||dat=='n') {
                                    cout << "INTRODUCE NOMBRE DEL CONDUCTOR: "; cin >> part.Conductores[i].nomcon.Nombre;
                                    cout <<endl;
                                    cout << "INTRODUCE PRIMER APELLIDO1 DEL CONDUCTOR: "; cin >> part.Conductores[i].nomcon.ape1;
                                    cout <<endl;
                                    cout << "INTRODUCE SEGUNDO APELLIDO DEL CONDUCTOR: "; cin >> part.Conductores[i].nomcon.ape2;}
                                else if (dat=='D'||dat=='d'){
                                        cout << "INTRODUCE DNI DEL CONDUCTOR: "; cin >> part.Conductores[i].dnicon;
                                        part.Coches.coches[i].dnicon=part.Conductores[i].dnicon;}
                                    else if (dat=='M'||dat=='m'){
                                            cout << "INTRODUCE MATRICULA DEL VEHICULO: "; cin >> part.Coches.coches[i].matcoche;
                                            part.Conductores[i].matcoche=part.Coches.coches[i].matcoche;}
                                        else if (dat=='P'||dat=='p'){
                                                cout << "INTRODUCE POBLACION DEL CONDUCTOR: "; cin >> part.Conductores[i].dicon.Poblacion;
                                                cout <<endl;
                                                cout << "INTRODUCE CALLE (Sin espacios) DEL CONDUCTOR: "; cin >> part.Conductores[i].dicon.calle;}
                                            else if(dat=='C'||dat=='c'){
                                                    cout << "INTRODUCE E-MAIL DEL CONDUCTOR: "; cin >> part.Conductores[i].email;}
                                                else if(dat=='S'||dat=='s'){
                                                        cout << "INTRODUCE MARCA DEL VEHICULO: "; cin >> part.Coches.coches[i].marca;
                                                        cout <<endl;
                                                        cout << "INTRODUCE MODELO DEL VEHICULO: "; cin >> part.Coches.coches[i].modelo;
                                                        cout <<endl;
                                                        cout << "INTRODUCE COLOR DEL VEHICULO: "; cin >> part.Coches.coches[i].color;}
                                                    else if(dat=='A'||dat=='a'){
                                                            cout << "INTRODUCE ANYO DE MATRICULACION DEL VEHICULO: "; cin >> part.Coches.coches[i].anyo;}
                                                            else if(dat=='X'||dat=='x'){
                                                                cout << "INTRODUCE DANYOS DEL VEHICULO: "; cin >> part.Coches.coches[i].danyo;}
                                                                else if(dat=='Y'||dat=='y'){
                                                                    cout << "INTRODUCE FECHA DE OCURRENCIA: "; cin >> part.Coches.coches[i].fechasin.dia;cout<< " / "; cin>> part.Coches.coches[i].fechasin.mes; cout << " / ";cin>> part.Coches.coches[i].fechasin.anyo;}
                                                                         else if(dat=='Z'||dat=='z'){
                                                                            cout << "INTRODUCE SI SE SOLICITA UNIDAD MOVIL (1:SI,0:NO): "; cin >> part.Coches.coches[i].SM;}

        escribirinfo(part);
        cout << "Los datos se han modificado correctamente!"<<endl;
        cout << endl;
        system ("pause");
        }
        else cout << "No se modificara ningun dato.";
}
void estadistica(Partes&part){
    int i=0,PB=0,Lun=0,Lat=0,Tec=0,Repa=0,total=0,x=0,y=0,anyo1,anyo2;
    char sino;
    while (i<part.nPartes){
        if(part.Coches.coches[i].danyo == 'P') PB++;
            else if(part.Coches.coches[i].danyo == 'T') Lun++;
                else if(part.Coches.coches[i].danyo == 'R') Repa++;
                    else if(part.Coches.coches[i].danyo == 'L') Lat++;
                        else if(part.Coches.coches[i].danyo == 'S') Tec++;
     i++;
    }

    total=PB+Lun+Lat+Tec+Repa;
    cout << endl;
    cout << endl;
    cout << "El total de siniestros registrados es : " << total;
    cout << endl;
    cout << "Total de Parabrisas: " << PB << endl;
    cout << "Total de Lunetas: " << Lun << endl;
    cout << "Total de Cristales laterales: " << Repa << endl;
    cout << "Total de Reparaciones de impacto: " << Lat << endl;
    cout << "Total de Techos solares: " << Tec << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "       VALORES REPRESENTATIVOS"<< endl;
    cout << endl;
    cout << "               PB:  ";
    while (x<PB) {camcolor (11); cout << "#" ;x++;}
    cout << endl;
    x=0;
    camcolor (14);
    cout << "               Rep: ";
    while (x<Repa) {camcolor (11); cout << "#" ;x++;}
    cout << endl;
    x=0;
    camcolor (14);
    cout << "               Lun: ";
    while (x<Lun) {camcolor (11); cout << "#" ;x++;}
    cout << endl;
    x=0;
    camcolor (14);
    cout << "               Lat: ";
    while (x<Lat) {camcolor (11); cout << "#" ;x++;}
    cout << endl;
    x=0;
    camcolor (14);
    cout << "               Tec: ";
    while (x<Tec) {camcolor (11); cout << "#" ;x++;}
    x=0;
    cout << endl;
    cout << endl;
    cout << "Desea filtrar los datos por anyo? (S: Si, N: Regresar)" << endl;
    cin >> sino;
    if (sino=='S'||sino=='s'){

        cout << "Introduzca DESDE que anyo desea filtrar: "; camcolor(11); cin >> anyo1;camcolor(14);
        cout << "Introduzca HASTA que anyo desea filtrar: "; camcolor(11); cin >> anyo2;camcolor(14);
    i=0;
    PB=0;Lun=0;Repa=0;Lat=0;Tec=0;
        while (i<part.nPartes){

          if(part.Coches.coches[i].fechasin.anyo <= anyo2 &&  part.Coches.coches[i].fechasin.anyo >= anyo1 ) {

                                if(part.Coches.coches[i].danyo == 'P') PB++;
                                    else if(part.Coches.coches[i].danyo == 'T') Lun++;
                                        else if(part.Coches.coches[i].danyo == 'R') Repa++;
                                            else if(part.Coches.coches[i].danyo == 'L') Lat++;
                                                else if(part.Coches.coches[i].danyo == 'S') Tec++;

                                    }
                        i++;



          }
         total=PB+Lun+Lat+Tec+Repa;
                    cout << endl;
                    cout << endl;
                    cout << "El total de siniestros registrados es : " << total;
                    cout << endl;
                    cout << "Total de Parabrisas: " << PB << endl;
                    cout << "Total de Lunetas: " << Lun << endl;
                    cout << "Total de Cristales laterales: " << Repa << endl;
                    cout << "Total de Reparaciones de impacto: " << Lat << endl;
                    cout << "Total de Techos solares: " << Tec << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "       VALORES REPRESENTATIVOS"<< endl;
                    cout << endl;
                    cout << "               PB:  ";
                    while (x<PB) {camcolor (11); cout << "#" ;x++;}
                    cout << endl;
                    x=0;
                    camcolor (14);
                    cout << "               Rep: ";
                    while (x<Repa) {camcolor (11); cout << "#" ;x++;}
                    cout << endl;
                    x=0;
                    camcolor (14);
                    cout << "               Lun: ";
                    while (x<Lun) {camcolor (11); cout << "#" ;x++;}
                    cout << endl;
                    x=0;
                    camcolor (14);
                    cout << "               Lat: ";
                    while (x<Lat) {camcolor (11); cout << "#" ;x++;}
                    cout << endl;
                    x=0;
                    camcolor (14);
                    cout << "               Tec: ";
                    while (x<Tec) {camcolor (11); cout << "#" ;x++;}
                    x=0;
                    cout << endl;
                    cout << endl;
        }
    }
void mostrarSM(Partes part,Umovil&sermovil){
    int i=0,y=0;
    bool trobat=false;
    cout<<"                 SERVICIOS MOVILES GESTIONADOS";
    cout<<endl;
    cout<<endl;
    cout<<endl;
    while (i<part.nPartes){

        if (part.Coches.coches[i].SM){
            while (y<sermovil.nmovil){

                if(part.Coches.coches[i].SM&&sermovil.tmovil[y].matricula==part.Coches.coches[i].matcoche) {cout<<"                         "<<
                 sermovil.tmovil[y].matricula; camcolor(10);cout  << "--> ASIGNADO || Fecha: " << sermovil.tmovil[y].fechasm.dia
                <<"/"<<sermovil.tmovil[y].fechasm.mes<<"/"<<sermovil.tmovil[y].fechasm.anyo <<endl;camcolor(14);
                trobat=true;}
                y++;
                }
                y=0;

              // (part.Coches.coches[i].SM&&sermovil.tmovil[y].matricula!=part.Coches.coches[i].matcoche) {

            if(!trobat){cout<<"                         " <<part.Coches.coches[i].matcoche; camcolor(12);cout <<"--> NO ASIGNADO!"<<endl;camcolor(14);}
            }



        i++;
        trobat=false;}
    cout<<endl;
    cout<<endl;
    }
void SMasignado(Partes part, Umovil&sermovil){
    mostrarSM(part,sermovil);
    string mat;
    bool trobat=false,trobat2=false;
    int i=0,y=0,x=0;;
    cout << "A QUE MATRICULA DESEA ASIGNARLE FECHA DE SERVICIO: " << endl;
    cin >> mat;


   while (i<part.nPartes){
    if (mat==part.Coches.coches[i].matcoche) trobat=true;
    i++;}

   if(trobat) {while (y<sermovil.nmovil){
                if (mat==sermovil.tmovil[y].matricula) {
                        trobat2=true;
                        x=y;
                }y++;
   }}

        else if(!trobat){cout <<"La matricula no coincide."<<endl;}

   if(trobat2&&trobat){cout << mat; camcolor(10);cout  << "--> ASIGNADO || Fecha: "
    << sermovil.tmovil[x].fechasm.dia<<"/"<<sermovil.tmovil[x].fechasm.mes<<"/"<<sermovil.tmovil[x].fechasm.anyo <<endl;
    camcolor(14);}

        else if(!trobat2&&trobat){
            cout << "Introduce fecha de servicio: "; cin >>sermovil.tmovil[sermovil.nmovil-1].fechasm.dia>>sermovil.tmovil[sermovil.nmovil-1].fechasm.mes>>sermovil.tmovil[sermovil.nmovil-1].fechasm.anyo;
                sermovil.tmovil[sermovil.nmovil-1].matricula=mat;
                sermovil.nmovil++;
                camcolor(11); cout <<"        SE HA GESTIONADO EL SERVICIO CORRECTAMENTE!"<<endl;
                escribirinfoSM(sermovil);}

   }
void modificarSM(Umovil&sermovil){

    string mat;
    int i=0;

    cout << "Que matricula desea modificar? "<<endl;
    cin>>mat;
    cout<<endl;
    while (i<sermovil.nmovil){

        if(mat==sermovil.tmovil[i].matricula) {
                cout << "Introduce nueva fecha de servicio: "; cin >>sermovil.tmovil[i].fechasm.dia>>sermovil.tmovil[i].fechasm.mes>>sermovil.tmovil[i].fechasm.anyo;
                escribirinfoSM(sermovil);}

    i++;


    }





}
void borrarSM(Partes&part, Umovil&sermovil){
    string mat;
    char sino,sino2;
    bool trobat=false;
    int i=0, y,i2=0;

    cout << "Que servicio desea anular? "<<endl;
    cin>>mat;
    cout<<endl;
    cout << "Para revertir la anulacion del servicio, debera volver a introducir los datos en <Modificar Poliza>, Esta seguro de que desea borrar el Servicio movil?(S:Si,N:No)"<<endl;
    cin>>sino;
    if(sino=='S'||sino=='s'){
    while (i<sermovil.nmovil){

        if(mat==sermovil.tmovil[i].matricula) { y=i; trobat=true;}
    i++;}

    i=0;

    if(trobat) {while (y<sermovil.nmovil){


                sermovil.tmovil[y].matricula=sermovil.tmovil[y+1].matricula;
                sermovil.tmovil[y].fechasm.dia=sermovil.tmovil[y+1].fechasm.dia;
                sermovil.tmovil[y].fechasm.mes=sermovil.tmovil[y+1].fechasm.mes;
                sermovil.tmovil[y].fechasm.anyo=sermovil.tmovil[y+1].fechasm.anyo;

                escribirinfoSM(sermovil);

                y++;}
    }

    cout <<"Desea anular tambien la peticion de Unidad Movil? (S:Si,N:No)"<<endl;
        cin>> sino2;
        if (sino2=='S'||sino2=='s'){while (i2<part.nPartes){
        if(mat==part.Coches.coches[i2].matcoche) {part.Coches.coches[i2].SM=false;
        escribirinfo(part);}
        i2++;
    }}

        else {camcolor(11); cout << "Solo se ha anulado la fecha del servicio, queda pendiente de asignar nueva fecha."<<endl;
        camcolor(14);}
    }

    else {camcolor(11);cout << "El servicio no se ha anulado."<<endl;
    camcolor(14);}
    }


/* FUNCIONES */

bool AjustarVentana(int Ancho, int Alto) {
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
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);

	return TRUE;
}
char menu(){
 char opcion=0; system("cls");
 logo1();
 logo();
 camcolor(14);
 cout << endl;
 cout << endl;
 cout << endl;
 cout<<"                                         MENU PRINCIPAL"<<endl;
 cout<<"                            ___________________________________________"<<endl;
 cout << endl;
 cout<<"                                      1 - APERTURAR PARTE"<<endl;
 cout << endl;
 cout<<"                                      2 - CONSULTA DE POLIZA"<<endl;
 cout << endl;
 cout<<"                                      3 - MODIFICAR PARTE"<<endl;
 cout << endl;
 cout<<"                                      4 - BORRAR PARTE"<<endl;
 cout << endl;
 cout<<"                                      5 - SERVICIO MOVIL"<<endl;
 cout << endl;
 cout<<"                                      6 - ESTADISTICAS"<<endl;
 cout << endl;
 cout<<"                                                                            0 - SALIR"<<endl;
 cout <<endl<< "            Elija una opcion: " ; cin>>opcion;
 system("cls");
 return opcion;
}
char menu2(){
 char opcion=0;
 //system("cls");
 camcolor(14);
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout<<"                                 BUSCAR DATOS       ";
                    cout<<"\n                       -------------------------------\n\n";
 cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 cout<<"                           1 - BUSCAR POR MATRICULA"<<endl;
 cout << endl;
 cout<<"                           2 - BUSCAR POR DNI DEL CONDUCTOR"<<endl;
 cout << endl;
 cout<<"                           3 - BUSCAR POR NUMERO DE SINIESTRO ASOCIADO"<<endl;
 cout << endl;
 cout << endl;
 cout<<"                                                                 0 - VOLVER AL MENU PRINCIPAL"<<endl;
 cout <<endl<< "            Elija una opcion: " ; cin>>opcion;
    system("cls");
 return opcion;
}
char menu3(){
 char opcion=0;
 //system("cls");
 camcolor(14);
                    cout << endl;
                    cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 cout << endl;
 cout<<"                           1 - ASIGNAR SERVICIO MOVIL"<<endl;
 cout << endl;
 cout<<"                           2 - MODIFICAR FECHA DE SERVICIO MOVIL"<<endl;
 cout << endl;
 cout<<"                           3 - BORRAR SERVICIO MOVIL"<<endl;
 cout << endl;
 cout << endl;
 cout<<"                                                                 0 - VOLVER AL MENU PRINCIPAL"<<endl;
 cout <<endl<< "            Elija una opcion: " ; cin>>opcion;
    system("cls");
 return opcion;
}
/* MAIN */

int main (){

 AjustarVentana(100,60);
 SetConsoleTitle("Carglass� Servicio de Lunas");
 logo1();
 logo();
 Partes part;
 Umovil sermovil;
 string mat,dni;
 char opcion,opcion2,opcion3,opcion4,opcion5,sino;
 bool trobat=false, trobat2=false;
 int i=0,sin=0;

    while(opcion != '0'){
        opcion = menu();
    switch(opcion){
        case '1':
                    cout<<"                 ---------------------------------------------------------------------\n";
                    cout<<"                            <<<<<<<<<<        APERTURAR PARTE        >>>>>>>>>>";
                    cout<<"\n                 ---------------------------------------------------------------------\n\n";

                        leerinfo(part);
                        introducir(part);
                        system("pause");


        break;
        case '2':
                    cout<<"               ---------------------------------------------------------------------\n";
                    cout<<"                         <<<<<<<<<<        CONSULTA DE POLIZA       >>>>>>>>>>";
                    cout<<"\n               ---------------------------------------------------------------------\n\n";

                while (opcion2 != '0'){
                    opcion2=menu2();
                switch (opcion2){
                case '1':
                    leerinfo(part);
                    cout << "       INTRODUCE MATRICULA: "<< endl;
                    cin >> mat;
                    buscarfichaMAT(part,mat,trobat,i);
                    mostrardatos(part,trobat,i);
                break;
                case '2':
                    leerinfo(part);
                    cout << "       INTRODUCE DNI DEL CONDUCTOR: "<< endl;
                    cin >> dni;
                    buscarfichaDNI(part,dni,trobat,i);
                    mostrardatos(part,trobat,i);
                break;
                case '3':
                    leerinfo(part);
                    cout << "       INTRODUCE EL NUM. DE SINIESTRO: "<< endl;
                    cin >> sin;
                    buscarfichaSINI(part,sin,trobat,i);
                    mostrardatos(part,trobat,i);

                case '0':
                break;

                default: cout<< "           Error: INTRODUZCA UNA OPCION CORRECTA !"<<endl;
                }
                opcion2='9';


                cout<<"         PULSA UNA TECLA PARA VOLVER AL MENU PRINCIPAL"<<endl; getch();
                //system("pause");
                //system("cls");

                break;}

        break;
        case '3':   cout<<"                  ---------------------------------------------------------------------\n";
                    cout<<"                           <<<<<<<<<<        MODIFICAR PARTE        >>>>>>>>>>";
                    cout<<"\n                ---------------------------------------------------------------------\n\n";

            while (opcion3 != '0'){
                opcion3=menu2();
                switch (opcion3){
                case '1':
                    leerinfo(part);
                    cout << "       INTRODUCE MATRICULA: "<< endl;
                    cin >> mat;
                    buscarfichaMAT(part,mat,trobat,i);
                    mostrardatos(part,trobat,i);
                    system("pause");
                    if (trobat){
                        cout << "Desea modificar los datos? (S/N)";
                        cin >> sino;
                        if(sino=='S'||sino=='s') modificardatos(part,trobat,i);
                         else cout << "No se modificara ningun dato.";   }


                break;
                case '2':
                    leerinfo(part);
                    cout << "       INTRODUCE DNI DEL CONDUCTOR: "<< endl;
                    cin >> dni;
                    buscarfichaDNI(part,dni,trobat,i);
                    mostrardatos(part,trobat,i);
                    system("pause");
                   if (trobat){
                        cout << "Desea modificar los datos? (S/N)";
                        cin >> sino;
                        if(sino=='S'||sino=='s')modificardatos(part,trobat,i);
                          else cout << "No se modificara ningun dato."; }
                break;
                case '3':
                    leerinfo(part);
                    cout << "       INTRODUCE EL NUM. DE SINIESTRO: "<< endl;
                    cin >> sin;
                    buscarfichaSINI(part,sin,trobat,i);
                    mostrardatos(part,trobat,i);
                    system("pause");
                     if (trobat){
                        cout << "Desea modificar los datos? (S/N)";
                        cin >> sino;
                        if(sino=='S'||sino=='s')modificardatos(part,trobat,i);
                          else cout << "No se modificara ningun dato."; }
                case '0':
                break;

                default: cout<< "           Error: INTRODUZCA UNA OPCION CORRECTA !"<<endl;
                }

                opcion3='9';



                break;}

        break;
        case '4':   cout<<"                  ---------------------------------------------------------------------\n";
                    cout<<"                            <<<<<<<<<<        BORRAR PARTE       >>>>>>>>>>";
                    cout<<"\n                 ---------------------------------------------------------------------\n\n";
            while (opcion4 != '0'){
                opcion4=menu2();
                switch (opcion4){
                case '1':
                    leerinfo(part);
                    cout << "       INTRODUCE MATRICULA: "<< endl;
                    cin >> mat;
                    buscarfichaMAT(part,mat,trobat,i);
                    mostrardatos(part,trobat,i);
                    if (trobat){
                        cout << "Desea borrar los datos? (S/N)";
                        cin >> sino;
                        if(sino=='S'||sino=='s'){
                          borrardatos(part,i);}
                         else cout << "No se borraran datos.";
                         }
                         system("pause");


                break;
                case '2':
                    leerinfo(part);
                    cout << "       INTRODUCE DNI DEL CONDUCTOR: "<< endl;
                    cin >> dni;
                    buscarfichaDNI(part,dni,trobat,i);
                    mostrardatos(part,trobat,i);
                   if (trobat){
                        cout << "Desea borrar los datos? (S/N)";
                        cin >> sino;
                        if(sino=='S'||sino=='s'){
                          borrardatos(part,i);}
                          else cout << "No se borraran datos."; }
                          system("pause");
                break;
                case '3':
                    leerinfo(part);
                    cout << "       INTRODUCE EL NUM. DE SINIESTRO: "<< endl;
                    cin >> sin;
                    buscarfichaSINI(part,sin,trobat,i);
                    mostrardatos(part,trobat,i);
                     if (trobat){
                        cout << "Desea borrar los datos? (S/N)";
                        cin >> sino;
                        if(sino=='S'||sino=='s'){
                          borrardatos(part,i);}
                          else cout << "No se borraran datos."; }
                          system("pause");
                case '0':
                break;

                default: cout<< "           Error: INTRODUZCA UNA OPCION CORRECTA !"<<endl;
                }
                opcion4='9';
                cout<<"         PULSA UNA TECLA PARA VOLVER AL MENU PRINCIPAL"<<endl; getch();
               // system("pause");  system("cls");

                break;}


        break;
        case '5':
                    cout<<"                 ---------------------------------------------------------------------\n";
                    cout<<"                            <<<<<<<<<<        SERVICIO MOVIL        >>>>>>>>>>";
                    cout<<"\n                 ---------------------------------------------------------------------\n\n";
                    leerinfo(part);
                    leerinfoSM(sermovil);
                    cout << sermovil.nmovil;
                    cout<<endl;
                    cout<<endl;
                    mostrarSM(part,sermovil);

                while (opcion5 != '0'){
                opcion5=menu3();
                switch (opcion5){
                case '1':
                    leerinfo(part);
                    leerinfoSM(sermovil);
                    SMasignado(part,sermovil);

                break;
                case '2':
                    leerinfo(part);
                    leerinfoSM(sermovil);
                    mostrarSM(part,sermovil);
                    modificarSM(sermovil);
                break;
                case '3':
                    leerinfo(part);
                    leerinfoSM(sermovil);
                    mostrarSM(part,sermovil);
                    borrarSM(part,sermovil);

                case '0':
                break;

                default: cout<< "           Error: INTRODUZCA UNA OPCION CORRECTA !"<<endl;
                }
                opcion5='9';
                cout<<"         PULSA UNA TECLA PARA VOLVER AL MENU PRINCIPAL"<<endl; getch();
                break;}
        break;

        case '6':
                    cout<<"                 ---------------------------------------------------------------------\n";
                    cout<<"                            <<<<<<<<<<        ESTADISTICAS        >>>>>>>>>>";
                    cout<<"\n                 ---------------------------------------------------------------------\n\n";
                    leerinfo(part);
                    estadistica(part);
                    system("pause");
        break;


        case '0':
            cout<<"            GRACIAS POR UTILIZAR LA APLICACION" <<endl;
            system("pause");
        break;

        default:
            cout<< "           Error: INTRODUZCA UNA OPCION CORRECTA !"<<endl;
            cout<<"         PULSA UNA TECLA PARA VOLVER AL MENU PRINCIPAL"<<endl; getch();
        break;
        }


    }

}



