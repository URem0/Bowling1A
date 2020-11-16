#include "fonctions.h"
#include <stdio.h>

int main(void){
	JOUEUR Joueur1;
	JOUEUR Joueur2;
	LANCERS Lancer1;
	LANCERS Lancer2;
	messageAccueil();
	char joueur_1[101],joueur_2[101];
	printf("Veuillez saisir vos pseudos :\n");
	scanf("%s\n",joueur_1);
	scanf("%s",joueur_2);
	initJoueur(Joueur1);
	initJoueur(Joueur2);
	initLancer(Lancer1);
	initLancer(Lancer2);
	afficheTableau(Joueur1);
	afficheTableau_bis(Lancer1);
	afficheTableau(Joueur2);
	afficheTableau_bis(Lancer2);
	Partie(Joueur1,Lancer1, Joueur2,Lancer2,joueur_1,joueur_2);
	Calcul(Joueur1, Lancer1);
	Calcul(Joueur2,Lancer2);
	printf("Résultat final:\n");
	afficheTableau(Joueur1);
	afficheTableau_bis(Lancer1);
	afficheTableau(Joueur2);
	afficheTableau_bis(Lancer2);
	messageFin(Joueur1,Joueur2,joueur_1,joueur_2);
	return 0;
}


