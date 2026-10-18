#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./ressources/vecteurs.h"

Vector vector_addition(Vector v1, Vector v2) {// addition de deux vexteurs
    Vector v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;

    return v3;
}

Vector vector_soustraction(Vector v1 , Vector v2) {
    Vector v3;
    v3.x = v1.x - v2.x;
    v3.y = v1.y - v2.y;
    v3.z = v1.z - v2.z;

    return v3;
}

Vector vector_multiplication(Vector v1 , double k) {
    Vector v2;
    v2.x = v1.x * k;
    v2.y = v1.y * k;
    v2.z = v1.z * k;

    return v2;
}

double vector_norme(Vector v1) {
    return sqrt((v1.x* v1.x) + (v1.y* v1.y) + (v1.z* v1.z));
}

void vecteursTest(){
    Vector v1 = {1.0, 2.0, 3.0};
    Vector v2 = {3.0, 1.0, 5.0};
    Vector result = vector_addition(v1, v2);
    printf("v = {%lf , %lf, %lf} \n", result.x, result.y, result.z);
}
