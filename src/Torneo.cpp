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
    /*El método crearFichero del objeto Torneo será el método en el que se debe crear el fichero
    para comenzar a inscribir jugadores o abrir el fichero ya creado para seguir inscribiendo
    jugadores o gestionar las inscripciones (mostrarlas, modificarlas, eliminarles), así como
    simular la celebración del torneo y mostrar los resultados del torneo. Si el fichero
    nombrefichero no existe se procede a crear el fichero vacío (asignando y guardando el valor
    de 0 para el número de Golfistas). Si el fichero existe se abre para poder gestionarlo.*/

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
    /*El método mostrar se encarga de mostrar por pantalla los datos de todas las inscripciones de
    un determinado torneo que tengan el mismo hándicap pasado por parámetro. Si el valor pasado
    es -1 se mostrará por pantalla la información de todos los golfistas del fichero.*/

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
    /*El método consultar devuelve el golfista cuya posición se pasa por parámetro. La posición
    del primer golfista en el fichero es la 1.*/
}

int Torneo::buscar(cadena licencia)
{
    /*El método buscar devuelve la posición en el fichero del golfista cuya licencia se pasa como
    parámetro, si se encuentra, y en caso contrario devuelve el valor -1, para indicar que no existe
    ningún golfista con esa licencia en el fichero.*/
}

void Torneo::insertar(Golfista g)
{
    /*El método insertar realiza la inserción de los datos de un nuevo golfista, teniendo en cuenta
    que los golfistas deben continuar en el fichero ordenados por hándicap, de menor a mayor.
    Habrá que controlar que no se insertan golfistas con la misma licencia de los ya inscritos en
    un mismo torneo.*/
}

void Torneo::modificar(Golfista c, int posicion)
{
    /*El método modificar se encarga de actualizar los datos de un golfista ya inscrito. Se pasarán
    los nuevos datos del golfista y la posición donde se encuentra. Si el golfista pasado no
    estuviera inscrito en el torneo, se mostraría un mensaje indicándolo. Nota: No se admite en
    la modificación cambiar el hándicap del golfista.*/
}

void Torneo::eliminar(int posicion)
{
    /*El método eliminar realiza la eliminación de los datos del golfista cuya posición se pasa por
    parámetro. Si la posición no existe, se mostraría un mensaje de error. Para eliminar una
    inscripción de un golfista del fichero, se desplazan una posición a la izquierda todas las
    inscripciones a continuación de la eliminada (para no dejar huecos).*/
}

void Torneo::Clasificar()
{
    /*El método Clasificacion se encarga de realizar una simulación de la celebración del torneo
    con los golfistas que se han inscrito. Su detalle se explica más adelante. Este método simulará
    la celebración del torneo y mostrará por pantalla la clasificación final con los datos de los
    golfistas, junto con el número de golpes y los resultados obtenidos.*/
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

