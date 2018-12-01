/*
jeu boggle réaliser dans le cadre du projet C à l'ENSIAS par :
Fouad Bouarourou
Younes Al Morabit 
Tous droits réservés 
*/
#include "boggle.h"
/*
affichage du menu principal du jeu
*/
void affichage_mp(void)
{
	system("clear");
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::                                          BOGGLE                                           ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::1-NOUVELLE PARTIE                                                           2-RÉGLES DU JEU::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::3-CRÉDITS                                                                  4-QUITTER LE JEU::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
}
/*
sous-menu partie deux joueurs
*/
void sousmenu1(void)
{
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::                                        NOUVELLE PARTIE                                    ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::1-NOUVEAU JOUEURS                                               2-RETOUR AU MENU PRINCIPALE::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::                                     3-CHARGER DES JOUEURS                                 ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
}
/*
sous-menu régles du jeu
*/
void sousmenu2(void)
{
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::                                        RÉGLES DU JEU                                      ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::Regles de base                                                                             ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::Dans une limite de temps de 3 minutes, vous devez trouver un maximum de mots en formant des::\n");
	printf("                       ::chaines de  lettres contigues. Plus le mot est long, plus les points qu'il vous rapporte   ::\n");
	printf("                       ::sont importants.                                                                           ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::Vous pouvez passer d'une lettre a la suivante sitee directement a gauche, a droite,en haut ::\n");
	printf("                       ::, en bas, ou sur l'une des quatre cases diagonales.                                        ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::     Une lettre ne peut pas etre utilisee plus d'une fois pour un meme mot.                ::\n");
	printf("                       ::     Seuls les mots de trois lettres ou plus comptent.                                     ::\n");
	printf("                       ::     Les accents ne sont pas importants. E peut etre utilise comme E, E, E, etc.           ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::Decompte des points                                                                        ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::Le decompte des points s'effectue apres que le temps de jeu de 3 minutes se soit ecoule.   ::\n");
	printf("                       ::Chacun des mots que vous avez trouves vous rapporte des points, selon le bareme suivant :  ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::     Mot de 3 ou 4 lettres : 1 point                                                       ::\n");
	printf("                       ::     Mot de 5 lettres : 2 points                                                           ::\n");
	printf("                       ::     Mot de 6 lettres : 3 points                                                           ::\n");
	printf("                       ::     Mot de 7 lettres : 5 points                                                           ::\n");
	printf("                       ::     Mot de 8 lettres ou plus : 11 points                                                  ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::Les points s'ajoutent a ceux des manches precedentes. Vous pouvez fixer vous-meme la fin de::\n");
	printf("                       ::la partie, soit lors qu'un objectif de point est atteint, soit apres un certain nombre de  ::\n");
	printf("                       ::manches. Le gagnant est le joueur ayant le plus de points !                                ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::                                                                 1-RETOUR AU MENU PRINCIPAL::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
}
/*
sous-menu crédits
*/
void sousmenu3(void)
{
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::                                           CRÉDITS                                         ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::Jeu boggle realise en langage C dans le cadre d'un projet a  l'Ecole  National  Superieure ::\n");
	printf("                       ::d'Informatique  et  d'Analyse  des  Systemes  (ENSIAS)  par deux etudiants de l'ecole :    ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::              Bouarourou Fouad                             Al Morabit Younes               ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::Encadres par :                                                                             ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::                                        Mme ElFkihi Sanaa                                  ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::                                                                       Tout droits reserves::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::                                                                 1-RETOUR AU MENU PRINCIPAL::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
}
/*
sous-menu pour quitter le jeu
*/
void sousmenu4(void)
{
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::                                VOULEZ-VOUS QUITTER LE JEU ?                               ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::1-OUI                                                                                 2-NON::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
}
/*
sous-menu pour continuer à jouer
*/
void sousmenu5(void)
{
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::                                   QUE VOULEZ-VOUS FAIRE ?                                 ::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       ::1-REJOURE                                                     2-RETOURNER AU MENU PRINCIPAL::\n");
	printf("                       ::                                                                                           ::\n");
	printf("                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
}