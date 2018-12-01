/*
jeu boggle réaliser dans le cadre du projet C à l'ENSIAS par :
Fouad Bouarourou
Younes Al Morabit 
Tous droits réservés 
*/
#include "boggle.h"

// empile les coordonees
pile* empiler(pile* first,cor* cod)
{
	pile* new=malloc(sizeof(pile));
	new->cord=malloc(sizeof(cor));
	new->cord->x=cod->x;
	new->cord->y=cod->y;
	new->next=first;
	first=new;
	return first;
}

pile* depiler(pile* first)
{
	if(first)
	{
		pile* p;
		p=first;
		first=first->next;
		free(p);
	}
	return first;
}


pile* parc(char matrix[N][N],char mot)
{
	pile* first=NULL;
	cor cord[16];
	int i,j,k=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{				
			if(matrix[i][j]==mot)
			{      
				cord[k].x=i;
				cord[k].y=j;
				first=empiler(first,&cord[k]);
				k++;
			}

		}
	}
	return first;
}

int exist_pile(pile* first,int x,int y)
{
	pile* p=first;
	while(p) 
	{
		if(p->cord->x==x && p->cord->y==y) 
			return 1;
		p=p->next;	
	}
	return 0;
}

pile* ajout_pile(pile* first,int x,int y)
{
	cor cod;
	cod.x=x;
	cod.y=y;
	first=empiler(first,&cod);
	return first;
}


void aff(pile* first)
{
	pile* p=first;
	while(p) 
	{
		printf("%d et %d \n",p->cord->x,p->cord->y);
		p=p->next;
	}
}


void probleme(char matrice[N][N],char mot[30],int i,int j,int k,pile* p)
{
	if(k==strlen(mot))
	{ 
		mot_trouver= 1;
	}
	if(3-i>0 && mot[k]==matrice[i+1][j] && exist_pile(p,i+1,j)==0)
	{
		p=ajout_pile(p,i+1,j);
		probleme(matrice,mot,i+1,j,k+1,p);
		p=depiler(p);	
	}
	if(3-i>0 && 3-j>0 && mot[k]==matrice[i+1][j+1] && exist_pile(p,i+1,j+1)==0 )
	{
		p=ajout_pile(p,i+1,j+1);
		probleme(matrice,mot,i+1,j+1,k+1,p);
		p=depiler(p);
	}																
	if(3-j>0 && mot[k]==matrice[i][j+1] && exist_pile(p,i,j+1)==0)
	{       	
		p=ajout_pile(p,i,j+1);
		probleme(matrice,mot,i,j+1,k+1,p);
		p=depiler(p);
	}
	if(i>0 && 3-j>0 && mot[k]==matrice[i-1][j+1] && exist_pile(p,i-1,j+1)==0)
	{
		p=ajout_pile(p,i-1,j+1);
		probleme(matrice,mot,i-1,j+1,k+1,p);
		p=depiler(p);
	}
	if(i>0  && mot[k]==matrice[i-1][j] && exist_pile(p,i-1,j)==0)
	{	
		p=ajout_pile(p,i-1,j);
		probleme(matrice,mot,i-1,j,k+1,p);
		p=depiler(p);
	}
	if(i>0 && j>0 && mot[k]==matrice[i-1][j-1] && exist_pile(p,i-1,j-1)==0)
	{
		p=ajout_pile(p,i-1,j-1);
		probleme(matrice,mot,i-1,j-1,k+1,p);
		p=depiler(p);
	}
	if(j>0 && mot[k]==matrice[i][j-1] && exist_pile(p,i,j-1)==0)
	{	
		p=ajout_pile(p,i,j-1);
		probleme(matrice,mot,i,j-1,k+1,p);
	    p=depiler(p);
	}
	if(3-i>0 && j>0 && mot[k]==matrice[i+1][j-1] && exist_pile(p,i+1,j-1)==0) 	 	
	{
		p=ajout_pile(p,i+1,j-1);
		probleme(matrice,mot,i+1,j-1,k+1,p);
		p=depiler(p);
	}
}

int exist(char matrice[N][N],char mot[30])
{
	mot_trouver=0;
	pile* pos=parc(matrice,mot[0]);
	pile* p=NULL;
	while(pos) 
	{       
		p=ajout_pile(p,pos->cord->x,pos->cord->y);
		probleme(matrice,mot,pos->cord->x,pos->cord->y,1,p);	
		pos=pos->next;
		p=NULL;
	}
	return mot_trouver;
}