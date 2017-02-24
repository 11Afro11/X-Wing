# fichero Makefile
#
# nombre del fichero ejecutable
#

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INC = include

NAME=XWING

TARGETS= XWING

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -I$(INC) -I.
CXXFLAGS=  -g -I$(INC) -I.

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#

LDFLAGS=  -lGLU -lGL -lglut



# definicion del compilador
#
CC = g++

# definicion de objetos
#
HEADERS = $(addprefix $(INC)/, escena.h ejes.h Objeto3D.h Colors.h file_ply_stl.h Ply.h ObjetoDeRevolucion.h Body.h Wing.h XWing.h R2D2.h)
OBJECTS= $(addprefix $(OBJ)/, escena.o ejes.o Nave.o Objeto3D.o file_ply_stl.o Ply.o ObjetoDeRevolucion.o Body.o Wing.o XWing.o R2D2.o)
# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : $(OBJECTS)
	$(CC) -o $@ $(CXXFLAGS) $(OBJECTS) $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

#
#
clean:
	-rm -f $(OBJ)/* $(BIN)/*
	-rm XWING
	-rm ./*.zip

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *

zip:
	zip -l $(NAME).zip  ./* src/*.cc include/*.h ./$(NAME).mak
