#include "Comun.h"
#include "Torneo.h"

int menuClubDeGolf(int numTorneos);
int menuTorneo(cadena nombre, int numGolfistas);
void implementacionMenuTorneo(Torneo* torneo, cadena nombreTorneo);

int main()
{
    Torneo torneos[N];
    int numTorneos = 0;

    fstream fTorneo("TORNEOS.dat", ios::binary | ios::in);
    fTorneo.seekg(0, ios::beg);
    if(!fTorneo.fail())
    {
        cadena nombre;
        Torneo aux;

        while(!fTorneo.eof())
        {
            fTorneo.read((char*)&aux, sizeof(Torneo));
            aux.getNomTorneo(nombre);
            if(!fTorneo.eof())
            {
                torneos[numTorneos].CrearFichero(nombre);
                numTorneos++;
            }
        }

    }
    else
    {
        fTorneo.close();
        fTorneo.open("TORNEOS.dat", ios::binary | ios::out);

        torneos[numTorneos].CrearFichero("AUDI");
        fTorneo.write((char*)&torneos[numTorneos], sizeof(Torneo));
        numTorneos++;

        torneos[numTorneos].CrearFichero("IBM");
        fTorneo.write((char*)&torneos[numTorneos], sizeof(Torneo));
        numTorneos++;

        torneos[numTorneos].CrearFichero("SONY");
        fTorneo.write((char*)&torneos[numTorneos], sizeof(Torneo));
        numTorneos++;
    }

    fTorneo.close();

    int opcMCG;
    do
    {
        opcMCG = menuClubDeGolf(numTorneos);
        switch(opcMCG)
        {
        case 1:
        {
            if(numTorneos==0)
                cout<<"\nNo hay ningun torneo para mostrar"<<endl;
            else
            {
                cout<<endl;
                cadena aux;

                for(int i=0; i<numTorneos; i++)
                {
                    torneos[i].getNomTorneo(aux);
                    cout<<"Nombre del Torneo: "<<aux<<"\nNumero de Golfistas inscritos: "<<torneos[i].getNumGolfistas()<<"\n\n";
                }
            }
            PAUSE;
        }
        break;

        case 2:
        {
            if(numTorneos==N)
                cout<<"\nNo se pueden crear mas torneos"<<endl;
            else
            {
                cadena nomT;
                cout<<"\nDime el nombre del torneo: ";
                cin>>nomT;

                torneos[numTorneos].CrearFichero(nomT);
                numTorneos++;

                fTorneo.open("TORNEOS.dat", ios::binary | ios::out | ios::app);
                fTorneo.seekp(0, ios::end);
                fTorneo.write((char*)&torneos[numTorneos-1], sizeof(Torneo));
                fTorneo.close();

                cout<<"Nuevo torneo creado con exito"<<endl;
                PAUSE;
            }
        }
        break;

        case 3:
        {
            if(numTorneos==0)
                cout<<"\nNo hay ningun torneo para mostrar"<<endl;
            else
            {
                CLS;
                cout<<"TORNEOS\n"<<endl;

                cadena nomTorneo;
                for(int i=0; i<numTorneos; i++)
                {
                    torneos[i].getNomTorneo(nomTorneo);
                    cout<<i+1<<". "<<nomTorneo<<endl;
                }

                int opcTorneo;
                do
                {
                    cout<<"\nElija torneo: ";
                    cin>>opcTorneo;
                }
                while(opcTorneo<1 || opcTorneo>numTorneos);

                torneos[opcTorneo-1].getNomTorneo(nomTorneo);
                implementacionMenuTorneo(&torneos[opcTorneo-1], nomTorneo);
            }
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

void implementacionMenuTorneo(Torneo* torneo, cadena nombreTorneo)
{
    int opcMT;
    do
    {
        opcMT = menuTorneo(nombreTorneo, torneo->getNumGolfistas());

        switch(opcMT)
        {
        case 1:
        {
            cout<<"\nDime el handicap  de los golfistas que desea ver, en caso de querer ver todos escriba -1: ";
            float hdcp;
            cin>>hdcp;

            torneo->mostrar(hdcp);
            cout<<endl;

        }
        break;

        case 2:
        {
            cadena nombre, apellidos, licencia;
            Golfista golfista;

            golfista.golpes=0;
            golfista.resultado=0;

            cout<<"\nIntroduzca el nombre: ";
            cin>>golfista.nombre;
            cout<<"Introduzca el apellido: ";
            cin>>golfista.apellidos;
            cout<<"Introduzca la licencia: ";
            cin>>golfista.licencia;
            cout<<"Introduzca el handicap: ";
            cin>>golfista.handicap;

            torneo->insertar(golfista);
        }
        break;

        case 3:
        {
            cadena licencia;
            cout<<"\nDime la licencia del golfista a buscar: ";
            cin>>licencia;

            int posicion = torneo->buscar(licencia);
            if(posicion == -1)
                cout<<"\nNo existe ningun golfista con esa licencia"<<endl;
            else
            {
                cout<<endl;
                Golfista g = torneo->consultar(posicion);
                torneo->mostrarGolfista(&g, true, posicion);
                cout<<endl;
            }
        }
        break;

        case 4:
        {
            cadena licencia;
            cout<<"\nDime la licencia del golfista a modificar: ";
            cin>>licencia;

            int posicion = torneo->buscar(licencia);
            if(posicion == -1)
                cout<<"\nNo existe ningun golfista con esa licencia"<<endl;
            else
            {
                Golfista newGol;

                newGol = torneo->consultar(posicion);
                torneo->mostrarGolfista(&newGol, true, posicion);

                cout<<"\nDime el nuevo nombre: ";
                cin>>newGol.nombre;
                cout<<"Dime el nuevo apellido: ";
                cin>>newGol.apellidos;
                cout<<"Dime la nueva licencia: ";
                cin>>newGol.licencia;

                torneo->modificar(newGol, posicion);
            }
        }
        break;

        case 5:
        {
            cadena licencia;
            cout<<"\nDime la licencia del golfista a eliminar: ";
            cin>>licencia;

            int pos = torneo->buscar(licencia);
            if(pos != -1)
            {
                torneo->eliminar(pos);
            }
            else
                cout<<"\nNo existe ningun golfista con esa licencia"<<endl;
        }
        break;

        case 6:
        {

        }
        break;

        case 7:
        {
            cout<<"\nVolviendo al menu principal...\n"<<endl;
        }
        break;
        }

        PAUSE;
    }
    while(opcMT != 7);
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
        if(opcion<1 || opcion>4)
        {
            cout<<"Opcion no valida, intentelo de nuevo\n\n";
            PAUSE;
        }
    }
    while(opcion<1 || opcion>4);

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
        cout<<"\t5. Eliminar una inscripcion\n\t6. Mostrar Resultados del Torneo\n\t7. Salir\n"<<endl;
        cout<<"Indique la opcion deseada: ";
        cin>>opcion;
        if(opcion<1 || opcion>7)
        {
            cout<<"Opcion no valida, intentelo de nuevo\n\n";
            PAUSE;
        }
    }
    while(opcion<1 || opcion>7);

    return opcion;
}

