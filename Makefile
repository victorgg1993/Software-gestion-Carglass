
NOM = main
EXTEN = cpp
SALIDA = carglass
CC = g++
FLAGS = -std=c++11
INC = -I ./inc
SRC =	./src/acc_prim_y_seg_nivel.cpp\
		./src/funciones.cpp\
		./src/linux_adapter.cpp\
		./src/logos.cpp\


all: 
	$(CC) $(INC) $(SRC) $(NOM).$(EXTEN) $(FLAGS) -o $(SALIDA)
	./$(SALIDA)
