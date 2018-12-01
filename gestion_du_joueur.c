/*
jeu boggle réaliser dans le cadre du projet C à l'ENSIAS par :
Fouad Bouarourou
Younes Al Morabit 
Tous droits réservés 
*/
#include "boggle.h"
/*
création des joueurs
*/
joueur *creation_jou(int i)
{
	joueur *J;
	J=malloc(sizeof(joueur));
	system("clear");
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                              ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                                              ::[DONNEZ CE QUI SUIT POUR LE JOUEUR %d ] :                   ::\n",i);
	printf("                                              ::                                                            ::\n");
	printf("                                              ::[PSEUDO] : ");
	scanf("%s",J->pseudo);
	J->partie=1;
	J->score=0;
	J->mots=NULL;
	return J;
}
/*
ajout d'un mot à la liste du joueur 
*/
tab* addtab(tab* first,char word[30])
{
	tab* new=malloc(sizeof(tab));
	int p=0;
	tab* fr=first;
	while((fr))
	{
		if(strcmp(fr->ch,word)==0)
		{
			p=1;
		}
		fr=fr->next;
	}
	if(p==0)
	{
		strcpy(new->ch,word);
		new->next=first;
		first=new;
	}
	return first;
}
/*
suppression d'un mot de la liste du joueur
*/
tab* removetab(tab* first,char word[30])
{
	tab*  p; 
	tab*  q;
	if(!strcmp(first->ch,word)) 
	{       
        q=first;
		first=first->next;
		free(q);
		return first;
	}
	p=first; 
	while(p->next)
	{
		if(!strcmp(p->next->ch,word))
		{	
			q=p->next;
			p->next=q->next;
			free(q);
			return first;
		}
		p=p->next;
	}
	return first;
}
/*
élimination des mots en communs
*/
void no_double(tab** t,tab** s)
{
	tab* p=*t; 
	tab* q=*s; 
	tab* fr=NULL;
	while(p)
	{	
		q=*s;
		while(q)
		{
			if(!strcmp(p->ch,q->ch))
			{
				fr=addtab(fr,q->ch);
			}
			q=q->next;
		}
		p=p->next;
	}	
	p=fr;
	while(p) 
	{
		q=p;
		*s=removetab(*s,p->ch);
		*t=removetab(*t,p->ch);
		p=p->next;
		free(q);
	}
	//t=q;
}
/*
vérifie l'éxistance d'un mot dans le dico
*/
int exist_mot(char mot[30])
{        
	int i;
	FILE* dic=NULL;
    char chaine[30]="";
	dic = fopen("dico.txt","r");
	if(dic!=NULL)
	{                  
        while( fgets(chaine,30,dic))
        {
            i=strlen(chaine);
            chaine[i-2]='\0';
            if(!strcmp(chaine,mot)) 
            	return 1;   		    
      	    chaine[0]='\0';
        }			
 	  	return 0;               
	}
	fclose(dic);
}
/*
vérifie l'existance d'une liste dans le dico
*/
tab* exist_tab(tab* first)
{
	tab* p=first; 
	tab* q=NULL; 
	tab* f;
	while(p)
	{
        f=p;        
		if(exist_mot(p->ch)==1) 
			q=addtab(q,p->ch); 
		p=p->next;	
		free(f);						
	}
	return q;
}
/*
affichage de la liste d'un joueur
*/
void displaytab(tab* first)
{
	tab* p=first;
	while(p)
	{
		printf("                        ======<<<%s>>>======\n",p->ch);
        p=p->next;            
	}
}
/*
affichage de la liste des mots des deux joueurs
*/
void displaytab2(joueur *J1,joueur *J2)
{
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                        ======<<<LISTE DES MOTS DE %s>>>======\n\n",J1->pseudo);
	displaytab(J1->mots);
	printf("                        ======<<<LISTE DES MOTS DE %s>>>======\n\n",J2->pseudo);
	displaytab(J2->mots);
}
/*
gestion du score
*/
int scoring(joueur *j,tab *lm)
{
	int len,a;
	a=j->score;
	while(lm!=NULL)
	{
		len=strlen(lm->ch);
		switch(len)
		{
			case 0:
				a=a+0;
				break;
			case 1:
				a=a+0;
				break;
			case 2:
				a=a+0;
				break;
			case 3:
				a=a+1;
				break;
			case 4:
				a=a+1;
				break;
			case 5:
				a=a+2;
				break;
			case 6:
				a=a+3;
				break;
			case 7:
				a=a+5;
				break;
			default :
				a=a+11;
		}
		lm=lm->next;
	}
	return a;
}
/*
afiichage des scores
*/
void dispscore(joueur *J1,joueur *J2)
{
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                              ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                                              ::                                                            ::\n");
	printf("                                              :: SCORE DE %s    :   %d                            ::\n",J1->pseudo,J1->score);
	printf("                                              ::                                                            ::\n");
	printf("                                              :: SCORE DE %s    :   %d                            ::\n",J2->pseudo,J2->score);
	printf("                                              ::                                                            ::\n");
	printf("                                              ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}
/*
sauvgareder la partie d'un joueur
*/
FILE *sauvgarder(joueur *j)
{
	FILE *svg=fopen("svg.txt","w+");
	fprintf(svg,"%s\n%d\n%d\n",j->pseudo,j->partie,j->score);
	fclose(svg);
	rename("svg.txt",strcat(j->pseudo,".txt"));
	return svg;
}
/*
charger la partie d'un joueur
*/
joueur *charger(char nom[30])
{
	FILE *fic=fopen(strcat(nom,".txt"),"a+");
	joueur *j=malloc(sizeof(joueur));
	fscanf(fic,"%s %d %d",j->pseudo,&j->partie,&j->score);
	j->mots=NULL;
	return j;
}
/*
charger un ancien joueur
*/
joueur *charger_joueur(int i)
{
	joueur *j=malloc(sizeof(joueur));
	char pseudo[30];
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                              ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("                                              ::[DONNEZ CE QUI SUIT POUR LE JOUEUR DEJA SAUVGARDER %d ] :   ::\n",i);
	printf("                                              ::                                                            ::\n");
	printf("                                              ::[PSEUDO] : ");
	scanf("%s",pseudo);
	j=charger(pseudo);
	return j;
}