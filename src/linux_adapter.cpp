#include <iostream>
#include <string>
#include <sstream>

#include "linux_adapter.h"

#ifdef __linux__
void SetConsoleTitle(char *titulo)
{
    std::cout << "\033]0;" << titulo << "\007";
}

void SetConsoleWindowInfo()
{
}

void SetConsoleScreenBufferSize()
{
}

template <class T>
inline std::string ToString(const T &t)
{
    // cualquier cosa a string
    std::stringstream ss;
    ss << t;
    return ss.str();
}

inline std::string gotoxy(const int &x, const int &y)
{
    return "\33[" + ToString(x) + ";" + ToString(y) + "H";
}

void getch()
{
    int dummy;
    std::cin >> dummy;
}

void print_text_color(int color, char *text, int num_salts_linia)
{
    // colors: 11 = vermell, 14 = groc

    switch (color)
    {
    case 11:
        break;

    case 14:
        std::cout << "\033[0;33m" << text << "\033[0m";
        break;

    default:
        std::cout << text;
        break;
    }

    for (int i = 0; i < num_salts_linia; i++)
    {
        std::cout << std::endl;
    }
}

#elif _WIN32
void camcolor(int x)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

void gotoxy(int x, int y)
{
    HANDLE consola;
    COORD posicion;
    consola = GetStdHandle(STD_OUTPUT_HANDLE);
    posicion.X = x;
    posicion.Y = y;
    SetConsoleCursorPosition(consola, posicion);
}

void print_text_color(int color, char *text, int num_salts_linia)
{
    camcolor(color);
    std::cout << text;

    for (int i = 0; i < num_salts_linia; i++)
    {
        std::endl;
    }
}

#endif
