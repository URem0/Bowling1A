#include "fonctions.h"

void messageAccueil()
{
    printf("Bienvenue au Bowlin'Ensea ! \n");
}

void initJoueur(JOUEUR J)
{
	for (int i=0; i<10;i++)
	{
		J[i]=-1;
		J[10]=0;
	}
}

void Tour(JOUEUR J,LANCERS L, int n)
{
	int score1;
	score1 = rand() % 11;
	L[2*n]=score1;
	if (score1==10)
	{
		printf("Strike !\n");
		J[n]=666;
		L[2*n+1]=-1;
	}
	else
	{
		int score2;
		score2= rand() % (11-score1);;
        L[2*n+1]=score2;
		if (score2 +score1==10)
		{
			printf("Spare !\n");
			J[n]=999;	
		}
		else 
		{
			J[n]=score1+score2;	
	    }
    }
}

void Tour_Final(JOUEUR J, LANCERS L)
{
	if(L[19]==-1)
	{
		int score1;
		score1 = rand() % 11;
		L[20]=score1;
		if (score1==10)
		{
			printf("Strike ENCORE !\n");
			L[21]=-1;
			int score1_bis;
			score1_bis = rand() % 11;
			if (score1_bis==10)
				printf("DOUBLE STRIKE !!\n");
			L[22]=score1_bis;
			J[9]=20+L[22];
			J[10]=J[10]+J[9];
		}
	}
	else
	{
		int score2;
		score2= rand() % 11;;
		if (score2==10)
				printf("STRIKE !!\n");
        L[20]=score2;
        J[9]=10+L[20];
		J[10]=J[10]+J[9];
    }
}

void afficheTableau(JOUEUR J)
{
	for (int i=0; i<11;i++)
	{
		printf("| ");
		if (J[i]==666)
		{
            printf(" X");
		}
		else if (J[i]==999)
		{
            printf(" /");
		}
		else if (J[i]==-1)
		{
			printf("  ");	
		}	
        else if (J[i]>=10)
        {
            printf("%d",J[i]);
		}
		else
        {
            printf(" %d",J[i]);
		}
		printf("  ");
	}
	printf("|\n");
}

void afficheTableau_bis(LANCERS L)
{
	for (int i=0; i<20;i++)
	{
		printf("|");
		if (L[i]==-1)
		{
			printf("  ");	
		}	
        else if (L[i]==10)
        {
            printf("%d",L[i]);
		}
		else
        {
            printf(" %d",L[i]);
		}
	}
	printf("|\n");
}
int Calcul(JOUEUR J, LANCERS L)
{
	int score=0;
	for (int k=0; k<10; k++)
	{
        if (J[k]==666)
        {
		    if((L[2*(k+1)]!= -1)&&(L[2*(k+1)+1]!=-1))
		    {
				score=score+10+L[2*(k+1)]+L[2*(k+1)+1];
				J[k]=10+L[2*(k+1)]+L[2*(k+1)+1];
			}
			else if((L[2*(k+1)]!= -1)&&(L[2*(k+1)+1]==-1))
			{
				if(L[2*(k+2)]!= -1)
				{
					score=score+20+L[2*(k+2)];
					J[k]=20+L[2*(k+2)];
				}
			}
			
		}       
		else if(J[k]==999)
		{
			if(L[2*(k+1)]!= -1)
			{
				score=score+10+L[2*(k+1)];
				J[k]=10+L[2*(k+1)];
			}
		}
		else if(J[k]!=-1)
		{
			score=score+J[k];
		}
    }
	J[10]=score;
	return score;
}

void messageFin(JOUEUR J1,JOUEUR J2, char *joueur_1,char *joueur_2)
{
	if (J1[10]<J2[10])
	{
		printf("Le vainqueur est: ");printf("%s ! \n",joueur_2);
	}
	else if (J1[10]>J2[10])
	{
		printf("Le vainqueur est: ");printf("%s ! \n",joueur_1);
	}
	else
		printf("Egalité. \n");
	printf("Passez une bonne journée\n");
}

void Partie(JOUEUR J1,LANCERS L1,JOUEUR J2, LANCERS L2,char *joueur_1,char *joueur_2)
{
    for (int i = 0; i<10;i++)
    {
	    printf("Tour numéro %d \n",i);
	    int reponse1;
	    printf("Au tour de");printf(" %s",joueur_1);printf(", Afin de lancer la balle, entrez un nombre. \n");
        scanf("%d",&reponse1);
        Tour(J1,L1, i);
        Calcul(J1,L1);
		afficheTableau(J1);
		afficheTableau_bis(L1);
        int reponse2;
        printf("Au tour de");printf(" %s",joueur_2);printf(", Afin de lancer la balle, entrez un nombre. \n");
        scanf("%d",&reponse2);
        Tour(J2,L2,i);
        Calcul(J2,L2);
        afficheTableau(J2);
        afficheTableau_bis(L2);       
	}
	if (J1[9]==999)
	{
		printf("%s a droit à un lancer supplémentaire. \n",joueur_1);
		printf("Afin de lancer la balle, entrez un nombre. \n");
		int reponse3;
		scanf("%d",&reponse3);
		Tour_Final(J1,L1);
		Calcul(J1,L1);
		afficheTableau(J1);
		afficheTableau_bis(L1);
	}
	if (J1[9]==666)
	{
		printf("%s a droit à 2 lancers supplémentaires. \n",joueur_1);
		printf("Afin de lancer les 2 balles, entrez un nombre. \n");
		int reponse4;
		scanf("%d",&reponse4);
		Tour_Final(J1,L1);
		Calcul(J1,L1);
		afficheTableau(J1);
		afficheTableau_bis(L1);
	}
	if (J2[9]==999)
	{
		printf("%s a droit à un lancer supplémentaire. \n",joueur_2);
		printf("Afin de lancer la balle, entrez un nombre. \n");
		int reponse5;
		scanf("%d",&reponse5);
		Tour_Final(J2,L2);
		Calcul(J2,L2);
		afficheTableau(J2);
		afficheTableau_bis(L2);
	}
	if (J2[9]==666)
	{
		printf("%s a droit à 2 lancers supplémentaires. \n",joueur_2);
		printf("Afin de lancer les 2 balles, entrez un nombre. \n");
		int reponse6;
		scanf("%d",&reponse6);
		Tour_Final(J2,L2);
		Calcul(J2,L2);
		afficheTableau(J2);
		afficheTableau_bis(L2);
	}	
}

void initLancer( LANCERS L)
{
	for (int i=0; i<21;i++)
	{
		L[i]=-1;
	}
}

