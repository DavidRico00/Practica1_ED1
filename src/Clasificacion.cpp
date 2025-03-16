#include "Clasificacion.h"

Clasificacion::Clasificacion()
{
    Jugadores = 0;
    tamano = 0;
}

Clasificacion::~Clasificacion()
{
    delete[] elementos;
    elementos = NULL;
}

void Clasificacion::anadirjugador(Jugador a)
{
    /*El método anadirjugador añade la estructura Jugador pasada como parámetro a la tabla de
    elementos del objeto Clasificación. Si dicha tabla estuviera llena habrá que redimensionar la
    tabla a un tamaño igual al anterior + SALTO (siendo SALTO una constante definida en el
    programa, con valor de 4, con el propósito de no tener que redimensionar la tabla con cada
    inserción, sino cada “SALTO” inserciones).*/

    if(tamano==0)
    {
        elementos = new Jugador[SALTO];
        tamano += SALTO;
    }
    else if(tamano==Jugadores)
    {
        Jugador* aux = new Jugador[tamano+SALTO];

        for(int i=0; i<Jugadores; i++)
            aux[i] = elementos[i];

        delete[] elementos;
        elementos = aux;
        aux = NULL;

        tamano += SALTO;
    }

    elementos[Jugadores] = a;
    Jugadores++;
}

void Clasificacion::eliminar(int i)
{
    /*El método eliminar, eliminará de la tabla dinámica el Jugador que ocupe la posición i, pasada
    como parámetro, en la tabla.*/

    if(i<0 || i>Jugadores)
        cout<<"\nLa posicion pasada esta fuera de los limites"<<endl;
    else
    {
        for(int j=i; j<Jugadores-1; j++)
            elementos[j] = elementos[j+1];

        Jugadores--;
    }
}

Jugador Clasificacion::consultar(int n)
{
    /*El método consultar permite obtener el Jugador que se encuentre en la tabla dinámica en la
    posición pasada.*/

    if(n<0 || n>Jugadores)
        cout<<"\nLa posicion pasada esta fuera de los limites"<<endl;
    else
        return elementos[n-1];
}

bool Clasificacion::vacio()
{
    /*El método vacio devuelve verdadero si la tabla dinámica elementos está vacía o falso en caso
    contrario.*/

    return Jugadores==0;
}

int Clasificacion::numjugadores()
{
    /*El método numjugadores devuelve el número de jugadores en la tabla elementos.*/

    return Jugadores;
}

void ordenar()
{
    /*El método ordenar ordena la tabla dinámica elementos por el algoritmo burbuja.*/
}
