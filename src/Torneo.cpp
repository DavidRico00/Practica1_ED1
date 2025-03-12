#include "Torneo.h"

Torneo::Torneo()
{

}

Torneo::~Torneo()
{

}

int Torneo::getNumGolfistas()               {return numGolfistas;}
void Torneo::setNumGolfistas(int n)         {numGolfistas = n;}
void Torneo::getNomTorneo(cadena nombre)    {strcpy(nombre, nomTorneo);}
void Torneo::setNomTorneo(cadena nombre)    {strcpy(nomTorneo, nombre);}
void Torneo::getNomFichero(cadena nombre)   {strcpy(nombre, nomFichero);}
void Torneo::setNomFichero(cadena nombre)   {strcpy(nomFichero, nombre);}

void Torneo::CrearFichero(char nombreFichero[])
{
    /*El m�todo crearFichero del objeto Torneo ser� el m�todo en el que se debe crear el fichero
    para comenzar a inscribir jugadores o abrir el fichero ya creado para seguir inscribiendo
    jugadores o gestionar las inscripciones (mostrarlas, modificarlas, eliminarles), as� como
    simular la celebraci�n del torneo y mostrar los resultados del torneo. Si el fichero
    nombrefichero no existe se procede a crear el fichero vac�o (asignando y guardando el valor
    de 0 para el n�mero de Golfistas). Si el fichero existe se abre para poder gestionarlo.*/

    setNomTorneo(nombreFichero);
    setNomFichero(nombreFichero);
    strcat(nomFichero, ".dat");

    fichero.open(nomFichero, ios::binary | ios::in);
    if(fichero.fail())
    {
        numGolfistas = 0;
        fichero.close();
        fichero.open(nomFichero, ios::binary | ios::out);
        if(!fichero.fail())
            fichero.write((char*)&numGolfistas, sizeof(int));
    }
    else
    {
        fichero.read((char*)&numGolfistas, sizeof(int));
    }
    fichero.close();
}

void Torneo::mostrar(float hdcp)
{
    /*El m�todo mostrar se encarga de mostrar por pantalla los datos de todas las inscripciones de
    un determinado torneo que tengan el mismo h�ndicap pasado por par�metro. Si el valor pasado
    es -1 se mostrar� por pantalla la informaci�n de todos los golfistas del fichero.*/

    if(numGolfistas == 0)
    {
        cout<<"No hay golfistas para mostrar";
        PAUSE; CLS;
        return;
    }

    fichero.open(nomFichero, ios::binary | ios::in);
    if(!fichero.fail())
    {
        Golfista golfista;
        bool mostrarCab = true;
        fichero.seekg(sizeof(int), ios::beg);
        for(int i=0;i<numGolfistas;i++)
        {
            fichero.read((char*)&golfista, sizeof(Golfista));
            if(hdcp == -1 || hdcp!=-1 && hdcp==golfista.handicap)
            {
                mostrarGolfista(&golfista, mostrarCab);
                mostrarCab=false;
            }
        }
    }

    if(fichero.fail())
        fichero.clear();

    fichero.close();
}

Golfista Torneo::consultar(int posicion)
{
    /*El m�todo consultar devuelve el golfista cuya posici�n se pasa por par�metro. La posici�n
    del primer golfista en el fichero es la 1.*/
}

int Torneo::buscar(cadena licencia)
{
    /*El m�todo buscar devuelve la posici�n en el fichero del golfista cuya licencia se pasa como
    par�metro, si se encuentra, y en caso contrario devuelve el valor -1, para indicar que no existe
    ning�n golfista con esa licencia en el fichero.*/
}

void Torneo::insertar(Golfista g)
{
    /*El m�todo insertar realiza la inserci�n de los datos de un nuevo golfista, teniendo en cuenta
    que los golfistas deben continuar en el fichero ordenados por h�ndicap, de menor a mayor.
    Habr� que controlar que no se insertan golfistas con la misma licencia de los ya inscritos en
    un mismo torneo.*/
}

void Torneo::modificar(Golfista c, int posicion)
{
    /*El m�todo modificar se encarga de actualizar los datos de un golfista ya inscrito. Se pasar�n
    los nuevos datos del golfista y la posici�n donde se encuentra. Si el golfista pasado no
    estuviera inscrito en el torneo, se mostrar�a un mensaje indic�ndolo. Nota: No se admite en
    la modificaci�n cambiar el h�ndicap del golfista.*/
}

void Torneo::eliminar(int posicion)
{
    /*El m�todo eliminar realiza la eliminaci�n de los datos del golfista cuya posici�n se pasa por
    par�metro. Si la posici�n no existe, se mostrar�a un mensaje de error. Para eliminar una
    inscripci�n de un golfista del fichero, se desplazan una posici�n a la izquierda todas las
    inscripciones a continuaci�n de la eliminada (para no dejar huecos).*/
}

void Torneo::Clasificar()
{
    /*El m�todo Clasificacion se encarga de realizar una simulaci�n de la celebraci�n del torneo
    con los golfistas que se han inscrito. Su detalle se explica m�s adelante. Este m�todo simular�
    la celebraci�n del torneo y mostrar� por pantalla la clasificaci�n final con los datos de los
    golfistas, junto con el n�mero de golpes y los resultados obtenidos.*/
}

void Torneo::mostrarGolfista(Golfista *g, bool cabecera)
{
    if (cabecera) {
        cout << setw(13) << left << "LICENCIA"
             << setw(6) << left << "HCP"
             << setw(15) << left << "NOMBRE"
             << setw(15) << left << "APELLIDOS"
             << setw(8) << left << "GOLPES"
             << setw(9) << left << "RESULTADO" << endl;

        cout << string(67, '-') << endl;
    }

    cout << setw(13) << left << g->licencia
         << setw(6) << left << g->handicap
         << setw(15) << left << g->nombre
         << setw(15) << left << g->apellidos
         << setw(8) << left << g->golpes
         << setw(9) << left << g->resultado << endl;
}

