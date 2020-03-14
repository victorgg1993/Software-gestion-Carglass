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
#include "linux_adapter.h"
#else
#endif

void logo1()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    //camcolor(14);
    std::cout << "                                       #####";
    //camcolor(12);
    std::cout << " ###### ##### ############ " << std::endl;
    //camcolor(14);
    std::cout << "                                     # #####";
    //camcolor(12);
    std::cout << " ###### ##### ########### " << std::endl;
    //camcolor(14);
    std::cout << "                                    ## #####";
    //camcolor(12);
    std::cout << " ###### ##### ##########  " << std::endl;
    //camcolor(14);
    std::cout << "                                   ### #####";
    //camcolor(12);
    std::cout << " ###### ##### #########   " << std::endl;
    //camcolor(14);
    std::cout << "                                  #### #####";
    //camcolor(12);
    std::cout << " ###### ##### ########    " << std::endl;
    //camcolor(14);
    std::cout << "                                 ##### #####";
    //camcolor(12);
    std::cout << " ###### ##### #######     " << std::endl;
    //camcolor(14);
    std::cout << "                                ###### #####";
    //camcolor(12);
    std::cout << " ###### ##### ######      " << std::endl;
    //camcolor(14);
    std::cout << "                               ####### #####";
    //camcolor(12);
    std::cout << " ###### ##### #####       " << std::endl;
    //camcolor(14);
    std::cout << "                              ######## #####";
    //camcolor(12);
    std::cout << " ###### ##### ####        " << std::endl;
    //camcolor(14);
    std::cout << "                             ######### #####";
    //camcolor(12);
    std::cout << " ###### ##### ###         " << std::endl;
    //camcolor(14);
    std::cout << "                            ########## #####";
    //camcolor(12);
    std::cout << " ###### ##### ##          " << std::endl;
    //camcolor(14);
    std::cout << "                           ########### #####";
    //camcolor(12);
    std::cout << " ###### ##### #          " << std::endl;
}

void logo()
{
    //camcolor(12);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "              ######    ###     ######     ######  ##         ###     #####     #####" << std::endl;
    std::cout << "             #######    ###     #######   #######  ##         ###    #######   #######" << std::endl;
    std::cout << "             ##   ###  #####    ##    ##  ##   ### ##        #####  ###   ### ###   ###" << std::endl;
    std::cout << "            ##        ##   ##   ##    ## ##        ##       ##   ##  ###       ###" << std::endl;
    std::cout << "            ##        ##   ##   ##    ## ##        ##       ##   ##   ###       ###" << std::endl;
    std::cout << "            ##        ##   ##   ##   ### ##    ### ##       ##   ##    ###       ###" << std::endl;
    std::cout << "            ##        ##   ##   ######   ##  ##### ##       ##   ##     ###       ###" << std::endl;
    std::cout << "            ##        ##   ##   #####    ##     ## ##       ##   ##      ###       ###" << std::endl;
    std::cout << "            ##        #######   ##  ##   ##     ## ##       #######       ###       ###" << std::endl;
    std::cout << "            ###       ##   ##   ##   ##  ###    ## ##       #######        ##        ##" << std::endl;
    std::cout << "             ###  ### ##   ##   ##    ##  ###  ### ##       ##   ##  ###  ###  ###  ###" << std::endl;
    std::cout << "             ####### ###   ###  ##    ##  #######  ######  ###    ##  ######    ######" << std::endl;
    std::cout << "               ###  ####   #######    ###   ###    ###### ####    ####  ###       ###" << std::endl;
}
