#Sanket Koirala 1002068130 Coding Assignment 4

SRC1 = Code4_1002068130.c
SRC2 = DrawTool.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)	
EXE = $(SRC1:.c=.e)

CFLAGS = -g

all : $(EXE)
 
$(EXE): $(OBJ1)	$(OBJ2)
	gcc $(CFLAGS) $(OBJ1)	$(OBJ2) -o $(EXE) 

$(OBJ1) : $(SRC1)
	gcc -c $(CFLAGS) $(SRC1)

$(OBJ2) : $(SRC2)
	gcc -c $(CFLAGS) $(SRC2)