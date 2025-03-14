#include "Comun.h"
#include "Torneo.h"

int menuClubDeGolf(int numTorneos);
int menuTorneo(cadena nombre, int numGolfistas);

int main()
{
    Torneo torneos[N];
    int numTorneos = 0, opcMCG;

    fstream fTorneo("TORNEOS.DAT", ios::binary | ios::in);
    if(fTorneo.fail())
    {
        fTorneo.close();
        fTorneo.open("TORNEOS.dat", ios::binary | ios::out);
        fTorneo.close();
    }
    else
    {
        //Leer fichero TORNEOS.DAT
    }
    fTorneo.close();

    do
    {
        opcMCG = menuClubDeGolf(numTorneos);
        switch(opcMCG)
        {
        case 1:
        {

        }
        break;

        case 2:
        {

        }
        break;

        case 3:
        {
            cadena nT;
            cout<<"\nIntroduzca el nombre del fichero: ";
            cin>>nT;

            torneos[0].CrearFichero(nT);
            int opcMT = menuTorneo(nT, torneos[0].getNumGolfistas());
        }
        break;

        case 4:
        {
            cout<<"\nSaliendo..."<<endl;
        }
        break;
        }
    }
    while(opcMCG != 4);

    return 0;
}

int menuClubDeGolf(int numTorneos)
{
    int opcion;

    do
    {
        CLS;
        cout<<"CLUB DE GOLF\n---------------------\nTorneos: "<<numTorneos<<endl;
        cout<<"\n\t1. Listado Torneos Abiertos\n\t2. Alta Torneo\n\t3. Elegir Torneo\n\t4. Salir\n"<<endl;
        cout<<"Indique la opcion deseada: ";
        cin>>opcion;
        if(opcion<0 || opcion>4)
        {
            cout<<"Opcion no valida, intentelo de nuevo\n\n";
            PAUSE;
        }
    }
    while(opcion<0 || opcion>4);

    return opcion;
}

int menuTorneo(cadena nombre, int numGolfistas)
{
    int opcion;

    do
    {
        CLS;
        cout<<"Torneo "<<nombre<<"\n---------------------\nNumero de golfistas: "<<numGolfistas<<endl;
        cout<<"\n\t1. Consulta de inscripciones\n\t2. Inscripcion al Torneo\n\t3. Busqueda de una inscripcion\n\t4. Modificar datos de una inscripcion"<<endl;
        cout<<"\t5. Eliminar una inscripcion\n\t7. Mostrar Resultados del Torneo\n\t7. Salir\n"<<endl;
        cout<<"Indique la opcion deseada: ";
        cin>>opcion;
        if(opcion<0 || opcion>7)
        {
            cout<<"Opcion no valida, intentelo de nuevo\n\n";
            PAUSE;
        }
    }
    while(opcion<0 || opcion>7);

    return opcion;
}

