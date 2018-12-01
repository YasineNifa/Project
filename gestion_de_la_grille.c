/*
jeu boggle réaliser dans le cadre du projet C à l'ENSIAS par :
Fouad Bouarourou
Younes Al Morabit 
Tous droits réservés 
*/
#include "boggle.h"
/*
lancement d'un seul dé
*/
char lance(char *d)
{
	int i=0,m;
	char c;
	m=strlen(d);
	srand(time(NULL));
	i = rand() % (m);
	c=d[i];
	return c;
}
/*
génération d'une grille
*/
void genere_grille(char R[N][N])
{
	int i,j,k=0;
	char *T[M]={"ETUKNO","EVGTIN","IELRUW","RECALS","ENTDOS","OFXRIA","NAVEDZ","DECAMP","EIOATA","GLENYU","BMAQJO","TLIBRA","EHIFSE","SPULTE","AIMSOR","ENHRIS"};

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			R[i][j]=lance(T[k]);
			k++;
		}
	}
}
/*
affichage d'une grille
*/
void afficher_grille(char T[N][N])
{
	int i , j;
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	for(i=0;i<N;i++)
	{
		
		printf("                                                         ::::::::::::::::::::::::::::::\n");
		printf("                                                         ::     ::     ::     ::     ::\n");
		printf("                                                         :");
		for(j=0;j<N;j++)
		{
			printf(":  %c  :",T[i][j]);
		}
		printf(":");
		printf("\n                                                         ::     ::     ::     ::     ::\n");
	}
	
	printf("                                                         ::::::::::::::::::::::::::::::\n");
	printf("\n\n\n");
}
