#include "Funciones.h"
#include <omp.h>
#define NOTAS "pruebas.csv"
#define MAX 500000
using namespace std;
void leerdatos() {
    ifstream archivo(NOTAS);
    ofstream Correccion("Correccion.csv");
    string linea;
    char delimitador = ';';
    int i = 0;
    #pragma omp parallel
    {
        getline(archivo, linea); //Salto de linea inicial
        Correccion <<"\""<<"Token Estudiantes"<<"\""<<";"<<"\""<<"Correctas"<<"\""<<";"<<"\""<<"Incorrectas"<<"\""<<";"<<"\""<<"Omitidas"<<"\""<<";"<<"\""<<"Puntaje"<<"\""<<";"<<"\""<<"Nota"<<"\""<<";"<<endl;
        while(getline(archivo, linea) && i<MAX ) { // Entran as� -> "Token de estudiante";"Pregunta 1";"Pregunta 2";"[...]"
            stringstream stream(linea);  // Convertir cadena a stream
            string Token,P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12; // Variables para los datos del .csv
            int correctas=0;
            int incorrectas=0;
            int omitidas=0;
            float puntaje=0;
            string Respuestas[12]= {"A","E","C","B","B","D","A","B","E","C","B","D"};
            // Obtener los datos del .csv
            getline(stream, Token, delimitador);
            getline(stream, P1, delimitador);
            getline(stream, P2, delimitador);
            getline(stream, P3, delimitador);
            getline(stream, P4, delimitador);
            getline(stream, P5, delimitador);
            getline(stream, P6, delimitador);
            getline(stream, P7, delimitador);
            getline(stream, P8, delimitador);
            getline(stream, P9, delimitador);
            getline(stream, P10, delimitador);
            getline(stream, P11, delimitador);
            getline(stream, P12, delimitador);
            // Eliminar las comillas
            Token.erase(remove(Token.begin(), Token.end(), '\"'), Token.end());
            P1.erase(remove(P1.begin(), P1.end(), '\"'), P1.end());
            P2.erase(remove(P2.begin(), P2.end(), '\"'), P2.end());
            P3.erase(remove(P3.begin(), P3.end(), '\"'), P3.end());
            P4.erase(remove(P4.begin(), P4.end(), '\"'), P4.end());
            P5.erase(remove(P5.begin(), P5.end(), '\"'), P5.end());
            P6.erase(remove(P6.begin(), P6.end(), '\"'), P6.end());
            P7.erase(remove(P7.begin(), P7.end(), '\"'), P7.end());
            P8.erase(remove(P8.begin(), P8.end(), '\"'), P8.end());
            P9.erase(remove(P9.begin(), P9.end(), '\"'), P9.end());
            P10.erase(remove(P10.begin(), P10.end(), '\"'), P10.end());
            P11.erase(remove(P11.begin(), P11.end(), '\"'), P11.end());
            P12.erase(remove(P12.begin(), P12.end(), '\"'), P12.end());

            string Prueba[12]={P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12};

            #pragma omp for

                for(int Aux = 0; Aux < 12; Aux++) //Correccion de la prueba
                    {
                    if(Prueba[Aux]==Respuestas[Aux])
                        {
                            correctas++;
                            puntaje+=0.50;
                        }
                    else if(Prueba[Aux]=="-")
                        {
                            omitidas++;
                        }
                    else
                        {
                            incorrectas++;
                            puntaje-=0.12;
                        }
                    }
                Correccion << "\"" << Token << "\"" << ";"; //Token Estudiante
                Correccion << "\"" << to_string(correctas) << "\"" << ";"; //Correctas
                Correccion << "\"" << to_string(incorrectas) << "\"" << ";"; //Incorrectas
                Correccion << "\"" << to_string(omitidas) << "\"" << ";"; //Omitidas
                if(puntaje<0) //Corrige si el puntaje da menos que 0
                {
                    puntaje=1;
                }
                Correccion << "\"" << to_string(puntaje) << "\"" << ";"; //Puntaje

                if(i < MAX - 1)
                    {
                        Correccion << "\"" << to_string(1+puntaje) << "\"" << endl;
                    }
                else
                    {
                        Correccion << "\"" << to_string(ceil((puntaje+1) * 10.0) / 10.0) << "\"";
                    }
                i++;
        }
    }
        archivo.close();
        Correccion.close();

}
