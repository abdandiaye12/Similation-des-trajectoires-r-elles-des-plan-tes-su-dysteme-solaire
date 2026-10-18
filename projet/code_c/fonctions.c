#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./ressources/fonctions.h"
#include "./ressources/vecteurs.h"
#include "./ressources/constantes.h"

void initTerre(Planete *p){
    p->excentricite = EXCENTRICITE_TERRE;
    p->demiAxe = DEMIAXE_TERRE;
    p->masse = MASSE_TERRE;
    p->perihelie = PERIHELIE_TERRE;
}

void initMars(Planete *p){
    p->excentricite = EXCENTRICITE_MARS;
    p->demiAxe = DEMIAXE_MARS;
    p->masse = MASSE_MARS;
    p->perihelie = PERIHELIE_MARS;
}

void initVenus(Planete *p){
    p->excentricite = EXCENTRICITE_VENUS;
    p->demiAxe = DEMIAXE_VENUS;
    p->masse = MASSE_VENUS;
    p->perihelie = PERIHELIE_VENUS;
}

void initPlanete(Planete *p){
    p->position.x = p->perihelie;
    p->position.y = 0.0;
    p->position.z = 0.0;
    
    double v_init = sqrt((G * MASSE_SOLEIL * (1 + p->excentricite)) / (p->demiAxe * (1 - p->excentricite)));
    p->vitesse.x = 0.0;
    p->vitesse.y = v_init;
    p->vitesse.z = 0.0;
}

void calcul_acceleration(Planete *p){
    double d = vector_norme(p->position);
    double ag = -(G * MASSE_SOLEIL) / (d*d*d);

    p->acceleration = vector_multiplication(p->position, ag);
}

void calcul_vitesse(Planete *p){
    p->vitesse = vector_addition(p->vitesse, vector_multiplication(p->acceleration, DT)); //formule d'Euler
}

void calcul_position(Planete *p){
    p->position = vector_addition(p->position, vector_multiplication(p->vitesse, DT)); //formule d'Euler
}

void calcul_energie(Planete *p){
    p->energie_potentielle = -(G * MASSE_SOLEIL * p->masse) / (vector_norme(p->position));
    p->energie_cinetique = 0.5 * p->masse * (pow(vector_norme(p->vitesse), 2));
    p->energie = p->energie_cinetique + p->energie_potentielle;
}
