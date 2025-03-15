#ifndef CLASIFICACION_H
#define CLASIFICACION_H

#include "Comun.h"

struct Jugador {
    int indice;
	int resultado;
};

class Clasificacion
{
private:
    Jugador *elementos; //elementos de la tabla
    int Jugadores;
    int tamano;
public:
    Clasificacion(); // constructor de la clase
    ~Clasificacion();
    void anadirjugador(Jugador a);
    void eliminar(int i);
    Jugador consultar(int n);//Devuelve la estructura en esa posicion
    bool vacio();
    int numjugadores();
    void ordenar();
};

#endif // CLASIFICACION_H
