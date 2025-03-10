#include "Vector.h"

Vector::Vector()
{

}

Vector::~Vector()
{

}

void Vector::Burbuja(int inicio, int fin)
{
    int pos,ele;
    for (pos=inicio; pos<fin; pos++)
        for (ele=inicio+1; ele<fin ; ele++)
            if(celda[ele-1]>celda[ele])
                intercambiar(celda[ele-1],celda[ele]);//Función genérica que tendrá que ser implementada
}

void Vector::intercambiar(int a, int b)
{

}

