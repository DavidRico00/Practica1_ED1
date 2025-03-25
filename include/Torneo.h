#ifndef TORNEO_H
#define TORNEO_H

#include "Comun.h"
#include "Clasificacion.h"

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
    Torneo();
    ~Torneo();
    int getNumGolfistas();
    void setNumGolfistas(int n);
    void getNomTorneo(cadena nombre);
    void setNomTorneo(cadena nombre);
    void getNomFichero(cadena nombre);
    void setNomFichero(cadena nombre);
    void CrearFichero(char nombreFichero[]);
    void mostrar(float hdcp);
    Golfista consultar(int posicion);
    int buscar(cadena licencia);
    void insertar(Golfista g);
    void modificar(Golfista g, int posicion);
    void eliminar(int posicion);
    void Clasificar();

    void mostrarGolfista(Golfista *g, bool cabecera, int pos);
    void mostrarDatosTorneo();
};

#endif // TORNEO_H
