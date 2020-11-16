#include <stdio.h>
#include <stdlib.h>
#define SIZE 11
#define SIZE_BIS 24


typedef int JOUEUR[SIZE];
typedef int LANCERS[SIZE_BIS];

void messageAccueil();
void Tour(JOUEUR J, LANCERS L , int n);
void initJoueur(JOUEUR J);
void afficheTableau(JOUEUR J);
void afficheTableau_bis(LANCERS J);
int Calcul(JOUEUR J,LANCERS L);
void messageFin(JOUEUR J1,JOUEUR J2, char *joueur_1 , char *joueur_2);
void Partie(JOUEUR J1,LANCERS L1, JOUEUR J2, LANCERS L2,char *joueur_1 , char *joueur_2);
void initLancer(LANCERS L);
void Tour_Final(JOUEUR J, LANCERS L);

