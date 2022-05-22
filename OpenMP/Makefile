all: Funciones.o main
$(info *******************************************************)
$(info Programa creado por: German Ramirez y Mauricio Quiroz)
$(info *******************************************************)

Funcion.o: Funciones.h omp.h Funciones.cpp pruebas.csv
	g++ -fopenmp -Wall -g3 -c Funciones.cpp

main: main.cpp Funciones.o pruebas.csv
	g++ -fopenmp -Wall -g3 -o main main.cpp Funciones.o

.PHONY: clean
clean:
	rm -fr *.o main
