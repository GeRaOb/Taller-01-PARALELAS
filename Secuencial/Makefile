all: Funcion.o main
$(info *******************************************************)
$(info Programa creado por: German Ramirez y Mauricio Quiroz)
$(info *******************************************************)

Funcion.o: Funcion.h Funcion.cpp pruebas.csv
	g++ -Wall -g3 -c Funcion.cpp

main: main.cpp Funcion.o pruebas.csv
	g++ -Wall -g3 -o main main.cpp Funcion.o

.PHONY: clean
clean:
	rm -fr *.o main
