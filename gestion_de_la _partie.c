/*
jeu boggle réaliser dans le cadre du projet C à l'ENSIAS par :
Fouad Bouarourou
Younes Al Morabit 
Tous droits réservés 
*/
#include "boggle.h"
/*
Nouvelle partie
*/
void new_game(void)
{
	joueur *j1=malloc(sizeof(joueur));
	joueur *j2=malloc(sizeof(joueur));
	char mot[30];
	char T[N][N];
	j1=creation_jou(1);
	j2=creation_jou(2);
	genere_grille(T);
	time_t reference=(time(NULL));
	system("clear");
	while(time(NULL) - reference < 180)
	{
		afficher_grille(T);
		printf("\n\n                        [ VOUS AVEZ 3 MINUTES MR %s ]\n\n                        [ ENTREZ '0' SI VOUS VOULEZ QUITTER ]\n\n                        [ DONNEZ UN MOT EN MAJUSCULE QUI SE TROUVE DANS LA GRILLE ] : ",j1->pseudo);
		scanf("%s",mot);
		if(!strcmp(mot,"0"))
		{
			break;
		}
		else
		{
			if((exist(T,mot))&&(exist_mot(mot)))
			{
				printf("\n\n                        [ LE MOT DONNE EST VALIDE ]");
				j1->mots=addtab(j1->mots,mot);
			}
			else
			{
				printf("\n\n                        [ LE MOT DONNE N'EST PAS VALIDE ]");
			}
		}
	}
	printf("\n\n                        [ FIN DE LA PARTIE POUR LE JOUEUR %s ]\n                        [ ENTREZ N'IMPORTE QUEL MOT POUR PASSER AU JOUEUR %s ]\n",j1->pseudo,j2->pseudo);
	scanf("%s",mot);
	time_t ref=(time(NULL));
	system("clear");
	while(time(NULL) - ref < 180)
	{
		afficher_grille(T);
		printf("\n\n                        [ VOUS AVEZ 3 MINUTES MR %s ]\n\n                        [ ENTREZ '0' SI VOUS VOULEZ QUITTER ]\n\n                        [ DONNEZ UN MOT EN MAJUSCULE QUI SE TROUVE DANS LA GRILLE ] : ",j2->pseudo);
		scanf("%s",mot);
		if(!strcmp(mot,"0"))
		{
			break;
		}
		else
		{
			if((exist(T,mot))&&(exist_mot(mot)))
			{
				printf("\n\n                        [ LE MOT DONNE EST VALIDE ]");
				j2->mots=addtab(j2->mots,mot);
			}
			else
			{
				printf("\n\n                        [ LE MOT DONNE N'EST PAS VALIDE ]");
			}
		}
	}
	printf("\n\n                        [ FIN DE LA PARTIE POUR LE JOUEUR %s ]\n                        [ ENTREZ N'IMPORTE QUEL MOT POUR CONTINUER ]\n",j2->pseudo);
	scanf("%s",mot);
	no_double(&j1->mots,&j2->mots);
	displaytab2(j1,j2);
	printf("\n\n                        [ ENTREZ N'IMPORTE QUEL MOT POUR AVOIR LES SCORES ]\n");
	scanf("%s",mot);
	j1->score=scoring(j1,j1->mots);
	j2->score=scoring(j2,j2->mots);
	dispscore(j1,j2);
	printf("\n\n                        [ ENTREZ N'IMPORTE QUEL MOT POUR SAVGARDER LES RESULTATS ]\n");
	scanf("%s",mot);
	FILE *fic1=sauvgarder(j1);
	FILE *fic2=sauvgarder(j2);
	menu5(j1,j2);
}
/*
partie avec des joueurs chargées
*/
void old_game(joueur *j1,joueur *j2)
{
	char mot[30];
	char T[N][N];
	genere_grille(T);
	time_t reference=(time(NULL));
	system("clear");
	while(time(NULL) - reference < 180)
	{
		afficher_grille(T);
		printf("\n\n                        [ VOUS AVEZ 3 MINUTES MR %s ]\n\n                        [ ENTREZ '0' SI VOUS VOULEZ QUITTER ]\n\n                        [ DONNEZ UN MOT EN MAJUSCULE QUI SE TROUVE DANS LA GRILLE ] : ",j1->pseudo);
		scanf("%s",mot);
		if(!strcmp(mot,"0"))
		{
			break;
		}
		else
		{
			if((exist(T,mot))&&(exist_mot(mot)))
			{
				printf("\n\n                        [ LE MOT DONNE EST VALIDE ]");
				j1->mots=addtab(j1->mots,mot);
			}
			else
			{
				printf("\n\n                        [ LE MOT DONNE N'EST PAS VALIDE ]");
			}
		}
	}
	printf("\n\n                        [ FIN DE LA PARTIE POUR LE JOUEUR %s ]\n                        [ ENTREZ N'IMPORTE QUEL MOT POUR PASSER AU JOUEUR %s ]\n",j1->pseudo,j2->pseudo);
	scanf("%s",mot);
	time_t ref=(time(NULL));
	system("clear");
	while(time(NULL) - ref < 180)
	{
		afficher_grille(T);
		printf("\n\n                        [ VOUS AVEZ 3 MINUTES MR %s ]\n\n                        [ ENTREZ '0' SI VOUS VOULEZ QUITTER ]\n\n                        [ DONNEZ UN MOT EN MAJUSCULE QUI SE TROUVE DANS LA GRILLE ] : ",j2->pseudo);
		scanf("%s",mot);
		if(!strcmp(mot,"0"))
		{
			break;
		}
		else
		{
			if((exist(T,mot))&&(exist_mot(mot)))
			{
				printf("\n\n                        [ LE MOT DONNE EST VALIDE ]");
				j2->mots=addtab(j2->mots,mot);
			}
			else
			{
				printf("\n\n                        [ LE MOT DONNE N'EST PAS VALIDE ]");
			}
		}
	}
	printf("\n\n                        [ FIN DE LA PARTIE POUR LE JOUEUR %s ]\n                        [ ENTREZ N'IMPORTE QUEL MOT POUR CONTINUER ]\n",j2->pseudo);
	scanf("%s",mot);
	no_double(&j1->mots,&j2->mots);
	displaytab2(j1,j2);
	printf("\n\n                        [ ENTREZ N'IMPORTE QUEL MOT POUR AVOIR LES SCORES ]\n");
	scanf("%s",mot);
	j1->score=scoring(j1,j1->mots);
	j2->score=scoring(j2,j2->mots);
	dispscore(j1,j2);
	printf("\n\n                        [ ENTREZ N'IMPORTE QUEL MOT POUR SAVGARDER LES RESULTATS ET RETOURNER AU MENU PRINCIPAL ]\n");
	scanf("%s",mot);
	FILE *fic1=sauvgarder(j1);
	FILE *fic2=sauvgarder(j2);
	menu5(j1,j2);
}
/*
gestion du menu 1
*/
void menu1(void)
{
	joueur *j1=malloc(sizeof(joueur));
	joueur *j2=malloc(sizeof(joueur));
	char b;
	sousmenu1();
	scanf("%c",&b);
	switch(b)
	{
		case '1':
			new_game();
			break;
		case '2':
			menu();
			break;
		case '3':
			j1=charger_joueur(1);                                     
			j2=charger_joueur(2);
			old_game(j1,j2);
			break;
		default :
			menu1();
	}
}
/*
gestion du menu 2
*/
void menu2(void)
{
	char b;
	sousmenu2();
	scanf("%c",&b);
	switch(b)
	{
		case '1' :
			menu();
			break;
		default :
			menu2();
	}
}
/*
gestion du menu 3
*/
void menu3(void)
{
	char b;
	sousmenu3();
	scanf("%c",&b);
	switch(b)
	{
		case '1' :
			menu();
			break;
		default :
			menu3();
	}
}
/*
gestion du menu 4
*/
void menu4(void)
{
	char b;
	sousmenu4();
	scanf("%c",&b);
	switch(b)
	{
		case '1':
			exit(EXIT_SUCCESS);
			break;
		case '2':
			menu();
			break;
		default :
			menu4();
	}
}
/*
gestion d'une partie
*/
void menu(void)
{
	char a;
	affichage_mp();
	scanf("%c",&a);
	switch(a)
	{
		case '1':
			menu1();
			break;
		case '2':
			menu2();
			break;
		case '3':
			menu3();
			break;
		case '4':
			menu4();
			break;
		default :
			menu();
	}
}
/*
gestion du menu d'après jeu
*/
void menu5(joueur *j1,joueur *j2)
{
	char a;
	sousmenu5();
	scanf("%c",&a);
	switch(a)
	{
		case '1':
			old_game(j1,j2);
			break;
		case '2':
			menu();
			break;
		default :
			menu5(j1,j2);
	}
}