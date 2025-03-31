#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED

#define PAUSE system("pause");
#define CLS system("cls");

#define N 10
#define SALTO 4

#include <fstream>      //fstream
#include <iostream>     //cin, cout

#include <cstring>      //strcpy
#include <iomanip>      // Necesario para setw(), left, right
#include <cstdlib>      // Para rand() y srand()
#include <ctime>        // Para time()

using namespace std;

const int TAM_CADENA = 30;
typedef char cadena[TAM_CADENA];

#endif // COMUN_H_INCLUDED

/*                                                          lectura   escritura
    open( char* nombreFichero, ios_base::openmode modo )    ios::in | ios::out | ios::binary |ios::app | ios::trunc
    fail()
    eof()
    close()
    read( char* destino, int cantidadBytes )
    write( char* origen, int cantidadBytes )
    seekg( streamoff desplazamiento, seekdir pos )      ios::beg, ios::cur, ios::end    lectura
    seekp( streamoff desplazamiento, seekdir pos )      ios::beg, ios::cur, ios::end    escritura
*/
