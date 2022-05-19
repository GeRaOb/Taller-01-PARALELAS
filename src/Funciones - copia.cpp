#include "Funciones.h"
#define NOTAS "pruebas.csv"
#define MAX 5
using namespace std;

string Estudiante[MAX][13];
int length;

void leerdatos() {
    ifstream archivo(NOTAS);
    string linea;
    char delimitador = ';';
    int i = 0;
    getline(archivo, linea); //Salto de linea inicial
    while(getline(archivo, linea)) { // Entran así -> "Token de estudiante";"Pregunta 1";"Pregunta 2";"[...]"
                cout<<linea<<endl;
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
        // Ingresar datos en matriz
        Estudiante[i][0] = Token;
        Estudiante[i][1] = P1;
        Estudiante[i][2] = P2;
        Estudiante[i][3] = P3;
        Estudiante[i][4] = P4;
        Estudiante[i][5] = P5;
        Estudiante[i][6] = P6;
        Estudiante[i][7] = P7;
        Estudiante[i][8] = P8;
        Estudiante[i][9] = P9;
        Estudiante[i][10] = P10;
        Estudiante[i][11] = P11;
        Estudiante[i][12] = P12;
        //Correccion

        for(int n = 1; n > 0 && n < 13; n++)
        {
            if(Estudiante[i][n]==Respuestas[n-1])
            {
                correctas++;
                puntaje+=0.50;
            }
            if(Estudiante[i][n]=="-")
            {
                omitidas++;
            }
            else
            {
                incorrectas++;
                puntaje-=0.12;
            }
        }

        Estudiante[i][13] = to_string(correctas);
        Estudiante[i][14] = to_string(incorrectas);
        Estudiante[i][15] = to_string(omitidas);
        if(puntaje<0)
        {
            puntaje=0;
        }
        Estudiante[i][16] = to_string(puntaje);
        Estudiante[i][17] = to_string(1+puntaje);

                        // Imprimir
        cout << endl << "========" << "[" << i << "]" <<"========" << endl;
        cout << "Token " << Estudiante[i][0] << endl;
        cout << "P1 " << Estudiante[i][1] << endl;
        cout << "P2 " << Estudiante[i][2] << endl;
        cout << "P3 " << Estudiante[i][3] << endl;
        cout << "P4 " << Estudiante[i][4] << endl;
        cout << "P5 " << Estudiante[i][5]  << endl;
        cout << "P6 " << Estudiante[i][6] << endl;
        cout << "P7 " << Estudiante[i][7] << endl;
        cout << "P8 " << Estudiante[i][8] << endl;
        cout << "P9 " << Estudiante[i][9] << endl;
        cout << "P10 " << Estudiante[i][10] << endl;
        cout << "P11 " << Estudiante[i][11] << endl;
        cout << "P12 " << Estudiante[i][12] << endl;
        cout << "Correctas " << Estudiante[i][13] << endl;
        cout << "Incorrectas " << Estudiante[i][14] << endl;
        cout << "Omitidas " << Estudiante[i][15] << endl;
        cout << "Puntaje " << Estudiante[i][16] << endl;
        cout << "Nota " << Estudiante[i][17] << endl;

        i++;
    }
    cout<<"Llegada";
	length = i; // Obtener la cantidad de datos
    archivo.close();
}
void crearCSV() { // Correccion Pruebas
    ofstream archivo("Correccion.csv");
    archivo << "identificador;correctas;incorrectas;omitidas;puntaje;nota";
    for(int i = 0; i < MAX; i++) {
        archivo << "\"" << Estudiante[i][0] << "\"" << ";"; //Token Estudiante
        archivo << "\"" << Estudiante[i][13] << "\"" << ";"; //Correctas
        archivo << "\"" << Estudiante[i][14] << "\"" << ";"; //Incorrectas
        archivo << "\"" << Estudiante[i][15] << "\"" << ";"; //Omitidas
        archivo << "\"" << Estudiante[i][16] << "\"" << ";"; //Puntaje
        archivo << "\"" << Estudiante[i][17] << "\"" << ";"; //Nota
    }
    archivo.close();
}
