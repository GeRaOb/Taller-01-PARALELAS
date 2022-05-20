CC = mpic++
CFLAGS = -g3 -Wall
MKDIR = mkdir -p

directorios: 
	$(MKDIR) build dist

main.o: main.cpp Funciones.cpp Funciones.h
	$(CFLAGS) -main.cpp -Funciones.cpp -Funciones.h -o build/main.o

all: clean main.o
	$(CC) $(CFLAGS) -o dist/programa build/main.o

clean:
	rm -fr *.o a.out programa dist build

.DEFAULT_GOAL := all
