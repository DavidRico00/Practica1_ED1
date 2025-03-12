#ifndef TORNEO_H
#define TORNEO_H

#include "Comun.h"

struct Golfista {
	cadena licencia;
	float handicap;
	cadena nombre;
	cadena apellidos;
	int golpes;
	int resultado;
};

class Torneo{
private:
    fstream fichero;
    int numGolfistas;
    cadena nomFichero;
    cadena nomTorneo;

public:
    ~Torneo();
    Torneo();
    inline int getNumGolfistas()                {return numGolfistas;}
    inline void putNumGolfistas(int n)          {numGolfistas = n;}
    inline void getNomTorneo(cadena nombre)     {strcpy(nombre, nomTorneo);}
    inline void putNomTorneo(cadena nombre)     {strcpy(nomFichero, nombre);}
    inline void getNomFichero(cadena nombre)    {strcpy(nombre, nomFichero);}
    inline void putNomFichero(cadena nombre)    {strcpy(nomFichero, nombre);}
    void CrearFichero(char nombreFichero[]);
    void mostrar(float hdcp);
    Golfista consultar(int posicion);
    int buscar(cadena licencia);
    void insertar(Golfista g);
    void modificar(Golfista c, int posicion);
    void eliminar(int posicion);
    void Clasificar();
};

#endif // TORNEO_H
