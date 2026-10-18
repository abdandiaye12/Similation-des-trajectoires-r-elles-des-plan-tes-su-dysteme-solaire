#ifndef VECTEURS_H
#define VECTEURS_H

typedef struct Vector{
    double x, y, z;
}Vector;


Vector vector_addition(Vector v1, Vector v2);

Vector vector_soustraction(Vector v1 , Vector v2);

Vector vector_multiplication(Vector v1 , double k);

double vector_norme(Vector v1);

void vecteursTest();

#endif