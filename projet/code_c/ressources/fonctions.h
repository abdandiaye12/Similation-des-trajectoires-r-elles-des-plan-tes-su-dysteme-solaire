#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "vecteurs.h"

// valeurs propres à chaque planète :
typedef struct {
    double excentricite;
    double demiAxe;
    double masse;
    double perihelie;

    double energie_cinetique;
    double energie_potentielle;
    double energie;
    
    Vector position;
    Vector vitesse;
    Vector acceleration;

}Planete;

void initTerre(Planete *p);

void initMars(Planete *p);

void initVenus(Planete *p);

void initPlanete(Planete *p);

void calcul_acceleration(Planete *p);

void calcul_vitesse(Planete *p);

void calcul_position(Planete *p);

void calcul_energie(Planete *p);

#endif