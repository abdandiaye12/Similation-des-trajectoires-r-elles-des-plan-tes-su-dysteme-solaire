#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./ressources/fonctions.h"
#include "./ressources/vecteurs.h"
#include "./ressources/constantes.h"

int main(){
    //on crée une variable pour la Terre qui reste à 1 si la somme des energies reste constante :
    int Eterre = 1;

    printf("\n-----------\n");
    //Définition des planètes :
    Planete Terre;
    initTerre(&Terre);
    initPlanete(&Terre);
    calcul_energie(&Terre);

    Planete Mars;
    initMars(&Mars);
    initPlanete(&Mars);
    calcul_energie(&Mars);

    Planete Venus;
    initVenus(&Venus);
    initPlanete(&Venus);
    calcul_energie(&Venus);

    printf("Tests de fonctions :\n");
    vecteursTest();

    printf("\nDonnées de planètes :\n\n");

    printf("Vitesse de la terre au périhélie : %e m/s\n", vector_norme(Terre.vitesse));
    printf("Energie potentielle de la terre au perihélie : %e J\n", Terre.energie_potentielle);
    printf("Energie cinétique de la terre au perihélie : %e J\n\n", Terre.energie_cinetique);
    printf("Energie TOTALE de la terre au perihélie : %e J\n", Terre.energie);
    
    // printf("-----------\n");

    // printf("Vitesse de Mars au périhélie : %e m/s\n", vector_norme(Mars.vitesse));   
    // printf("Energie potentielle de Mars au perihélie : %e J\n", Mars.energie_potentielle);
    // printf("Energie cinétique de Mars au perihélie : %e J\n", Mars.energie_cinetique);
    // printf("Energie TOTALE de Mars au perihélie : %e J\n", Mars.energie);

    // printf("-----------\n");

    // printf("Vitesse de Vénus au périhélie : %e m/s\n", vector_norme(Venus.vitesse));   
    // printf("Energie potentielle de Vénus au perihélie : %e J\n", Venus.energie_potentielle);
    // printf("Energie cinétique de Vénus au perihélie : %e J\n", Venus.energie_cinetique);
    // printf("Energie TOTALE de Vénus au perihélie : %e J\n", Venus.energie);

    FILE *trajectoires =fopen("trajectoires.json", "w"); //Ouverture du json en mode écriture
    
    fprintf(trajectoires, "{\"Terre\" : [\n");
    for(int i = 0; i < PAS_Terre; i++){

        calcul_energie(&Terre);         //calcul de l'energie de la terre avant d'avoir avancé d'un pas
        double energieTerre1 = Terre.energie;
        
        calcul_acceleration(&Terre);
        calcul_vitesse(&Terre);
        calcul_position(&Terre);
        calcul_energie(&Terre);

        calcul_energie(&Terre);         //calcul de l'energie de la terre après avoir avancé d'un pas
        
        if(energieTerre1 != Terre.energie){ // si l'energie n'est pas constante alors on passe notre variable a 0
            Eterre = 0;
        }

        
        //Ecriture dans le fichier Json au format demandé avec position et vitesse sur chaque vecteur

        if (i == PAS_Terre-1)
            fprintf(trajectoires, "[[%e, %e, %e],[%e, %e, %e], %d]],\n", Terre.position.x, Terre.position.y, Terre.position.z, Terre.vitesse.x, Terre.vitesse.y, Terre.vitesse.z, i);
        else
            fprintf(trajectoires, "[[%e, %e, %e],[%e, %e, %e], %d],\n", Terre.position.x, Terre.position.y, Terre.position.z, Terre.vitesse.x, Terre.vitesse.y, Terre.vitesse.z, i);
    }

    fprintf(trajectoires, "\"Mars\" : [\n");
    for(int i = 0; i < PAS_Mars; i++){
        
        calcul_acceleration(&Mars);
        calcul_vitesse(&Mars);
        calcul_position(&Mars);
        
        if (i == PAS_Mars-1)
            fprintf(trajectoires, "[[%e, %e, %e],[%e, %e, %e], %d]],\n", Mars.position.x, Mars.position.y, Mars.position.z, Mars.vitesse.x, Mars.vitesse.y, Mars.vitesse.z, i);
        else
            fprintf(trajectoires, "[[%e, %e, %e],[%e, %e, %e], %d],\n", Mars.position.x, Mars.position.y, Mars.position.z, Mars.vitesse.x, Mars.vitesse.y, Mars.vitesse.z, i);
    }

    fprintf(trajectoires, "\"Venus\" : [\n");
    for(int i = 0; i < PAS_Venus; i++){
        
        calcul_acceleration(&Venus);
        calcul_vitesse(&Venus);
        calcul_position(&Venus);
        
        if (i == PAS_Venus-1)
            fprintf(trajectoires, "[[%e, %e, %e],[%e, %e, %e], %d]]}\n", Venus.position.x, Venus.position.y, Venus.position.z, Venus.vitesse.x, Venus.vitesse.y, Venus.vitesse.z, i);
        else
            fprintf(trajectoires, "[[%e, %e, %e],[%e, %e, %e], %d],\n", Venus.position.x, Venus.position.y, Venus.position.z, Venus.vitesse.x, Venus.vitesse.y, Venus.vitesse.z, i);
    }
    
    fclose(trajectoires);

    //condition pour vérifier si l'énergie a été constante sur tout le long de son mouvement :
    
    printf("Energie TOTALE de la terre finale : %e\n\n", Terre.energie);
    if(Eterre == 1){
        printf("L'énergie de la Terre est bien constante, notre calcul est donc vrai.\n");
    }else{
        printf("L'énergie de la Terre n'a pas été constante, notre calcul n'est donc pas vérifié.\n");
    }
}