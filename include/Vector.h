#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
private:
    int celda[2];                       //temporal
    void intercambiar(int a, int b);    //temporal
public:
    Vector();
    virtual ~Vector();
    void Burbuja(int inicio, int fin);
};

#endif // VECTOR_H
