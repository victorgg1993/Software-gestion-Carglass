#ifndef _linux_adapter_h_
#define _linux_adapter_h_

void getch();
void camcolor(int x);
void SetConsoleTitle(char *titulo);
void SetConsoleWindowInfo();
void SetConsoleScreenBufferSize();

#ifdef __linux__
template <class T>
inline std::string ToString(const T &t);
inline std::string gotoxy(const int &x, const int &y);

#elif _WIN32
void gotoxy(int x, int y);
#endif

void print_text_color(int color, char* text, int num_salts_linia);

#endif
