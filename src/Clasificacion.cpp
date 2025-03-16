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
    /*El m�todo anadirjugador a�ade la estructura Jugador pasada como par�metro a la tabla de
    elementos del objeto Clasificaci�n. Si dicha tabla estuviera llena habr� que redimensionar la
    tabla a un tama�o igual al anterior + SALTO (siendo SALTO una constante definida en el
    programa, con valor de 4, con el prop�sito de no tener que redimensionar la tabla con cada
    inserci�n, sino cada �SALTO� inserciones).*/

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
    /*El m�todo eliminar, eliminar� de la tabla din�mica el Jugador que ocupe la posici�n i, pasada
    como par�metro, en la tabla.*/

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
    /*El m�todo consultar permite obtener el Jugador que se encuentre en la tabla din�mica en la
    posici�n pasada.*/

    if(n<0 || n>Jugadores)
        cout<<"\nLa posicion pasada esta fuera de los limites"<<endl;
    else
        return elementos[n-1];
}

bool Clasificacion::vacio()
{
    /*El m�todo vacio devuelve verdadero si la tabla din�mica elementos est� vac�a o falso en caso
    contrario.*/

    return Jugadores==0;
}

int Clasificacion::numjugadores()
{
    /*El m�todo numjugadores devuelve el n�mero de jugadores en la tabla elementos.*/

    return Jugadores;
}

void ordenar()
{
    /*El m�todo ordenar ordena la tabla din�mica elementos por el algoritmo burbuja.*/
}
