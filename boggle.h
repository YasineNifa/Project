/*
jeu boggle réaliser dans le cadre du projet C à l'ENSIAS par :
Fouad Bouarourou
Younes Al Morabit 
Tous droits réservés 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 4
#define M N*N
#define limite 4
/*
type booléen
*/
typedef enum
{
	false,
	true
}bool;
/*
structure de liste de mot
*/
typedef struct _tab
{
	char ch[30];
	struct _tab* next;
}tab;
/*
stucture du profil d'un joueur
*/
typedef struct joueur
{
	char pseudo[30];
	int partie;
	int score;
	tab *mots;
}joueur;
/*
structure de début d'un mot
*/
typedef struct deb
{
	char *mot;
	bool existe;
}deb;
/*
structure d'arbre de recherhe
*/
typedef struct arbre
{
	deb *m;
	struct arbre *gauche;
	struct arbre *droit;
}arbre;

typedef struct _cor
{
	int x;
	int y;
}cor;

typedef struct _pile
{
	cor* cord;
	struct _pile* next;
}pile;

int mot_trouver;
/*
prototype des fonctions
*/
char lance(char *d);
void genere_grille(char R[N][N]);
void afficher_grille(char T[N][N]);
void affichage_mp(void);
void sousmenu1(void);
void sousmenu2(void);
void sousmenu3(void);
void sousmenu4(void);
void sousmenu5(void);
void new_game(void);
void old_game(joueur *j1,joueur *j2);
void menu1(void);
void menu2(void);
void menu3(void);
void menu4(void);
void menu(void);
void menu5(joueur *j1,joueur *j2);
joueur *creation_jou(int i);
tab* addtab(tab* first,char word[30]);
tab* removetab(tab* first,char word[30]);
void no_double(tab** t,tab** s);
int exist_mot(char mot[30]);
tab* exist_tab(tab* first);
void displaytab(tab* first);
void displaytab2(joueur *J1,joueur *J2);
int scoring(joueur *j,tab *lm);
void dispscore(joueur *J1,joueur *J2);
FILE *sauvgarder(joueur *j);
joueur *charger(char nom[30]);
joueur *charger_joueur(int i);
pile* empiler(pile* first,cor* cod);
pile* depiler(pile* first);
pile* parc(char matrix[N][N],char mot);
int exist_pile(pile* first,int x,int y);
pile* ajout_pile(pile* first,int x,int y);
void aff(pile* first);
void probleme(char matrice[N][N],char mot[30],int i,int j,int k,pile* p);
int exist(char matrice[N][N],char mot[30]);