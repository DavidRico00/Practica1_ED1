#include "Torneo.h"

Torneo::Torneo()
{

}

Torneo::~Torneo()
{

}

void Torneo::CrearFichero(char nombreFichero[])
{
    strcpy(nomFichero, nombreFichero);

    fichero.open(nomFichero, ios::binary | ios::in);
    if(fichero.fail())
    {
        numGolfistas = 0;
        fichero.close();
        fichero.open(nomFichero, ios::binary | ios::out);
        if(!fichero.fail())
        {
            fichero.write((char*)&numGolfistas, sizeof(int));
            cout<<"Dime un nombre para el torneo: ";
            cin>>nomTorneo;
            fichero.write(nomTorneo, sizeof(cadena));
        }
    }
    else
    {
        fichero.read((char*)&numGolfistas, sizeof(int));
        fichero.read(nomTorneo, sizeof(cadena));
    }
}
