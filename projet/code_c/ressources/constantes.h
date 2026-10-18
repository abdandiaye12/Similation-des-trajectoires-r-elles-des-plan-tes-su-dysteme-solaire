//Nombre de points à générer : (pour mettre pile poil un tour complet par planete et alléger le fichier json)
#define PAS_Terre 730*3
#define PAS_Mars 1374*3
#define PAS_Venus 450*3

//Nombre de temps entre chaque point (secondes) :
#define DT 43200/3//86400

//Constantes astronomiques :
#define G 6.67408e-11
#define MASSE_SOLEIL 1.9885e+30

//Constantes Terre :
#define EXCENTRICITE_TERRE 0.0167
#define DEMIAXE_TERRE 1.496e+11
#define MASSE_TERRE 5.97e+24
#define PERIHELIE_TERRE 1.47e+11

//Constantes Mars :
#define EXCENTRICITE_MARS 0.093
#define DEMIAXE_MARS 2.279e+11
#define MASSE_MARS 6.417e+23
#define PERIHELIE_MARS 2.066e+11

//Constantes Venus :
#define EXCENTRICITE_VENUS 0.00677
#define DEMIAXE_VENUS 1.082e+11
#define MASSE_VENUS 4.867e+24
#define PERIHELIE_VENUS 1.074e+11