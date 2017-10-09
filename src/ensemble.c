#include <stdlib.h>
#include <stdio.h>
#include "ensemble.h"

/**
 * \file ensemble.c
 * \brief  détails des fonctions de manipulation des ensembles
 * \author Hetzlen Julien, Rabu Titouan
 * \version 1.0
 * \date 21 avril 2015
 * 
 */

couple InitCouple(int x,int y)
{
	couple c;
	c.x=x ;
	c.y=y ;
	return c ;
}
ens EnsAlloc()   
{
	ens e ;
	e=malloc(sizeof(struct str_ensemble));	// reservation de la mémoire pour un maillon de la liste chainée
	e->suiv=NULL;   						// pointeur suivant initialiser sur NULL
	return e;
}

ens EnsFree(ens e)  
{
	ens tmp ;
	while(e!=NULL)
	{
		tmp=e ;				//stockage dans une variable tmp pour ne pas perdre l'adresse et pouvoir libéreer l'espace mémoire
		e=e->suiv ;
		free(tmp) ;			// libération de la mémoire
	}
	return e;				//renvoie toujours le pointeur NULL
}
	
int EnsEstVide(ens e) 
{
	return e==NULL ;
}


ens EnsAjoute(ens e,couple a) 
{
	ens tmp =EnsAlloc() ;		//réservation mémoire 
	tmp->c.x=a.x ;				// initialisation du maillon
	tmp->c.y=a.y ;
	
	if(EnsEstVide(e))
	{
		e=tmp ;					//le maillon = la liste si la liste est vide
	}
	else 
	{
		tmp->suiv=e ;			// ajout du maillon en tête de liste
		e=tmp ;
	}
	return e ;
}	

ens EnsSuppr(ens e,couple d)
{
	ens tmp = e ;
	if(tmp == NULL)
		return e ;							// si liste vide ne rien faire
	if ((e->c.x==d.x) && (e->c.y==d.y)) 	//si la tête est l'élément  a supprimer 
	{
		e=e->suiv ;							
		free(tmp);
	}
	else
	{
		while(tmp!= NULL)
		{
			if ((tmp->suiv->c.x==d.x) && (tmp->suiv->c.y==d.y))		
			{
				ens tmp2=tmp->suiv ;			//on stocke l'adresse de l'élément a supprimmer en mémoire
				tmp->suiv=tmp2->suiv ;			// on fais pointer le pointeur suivant sur celui situé après celui qui dois ce faire supprimer
				free(tmp2) ;					//libération de la mémoire
				return e ;
			}
			else 
				tmp=tmp->suiv ;					// éléments suivant
		}
	}
	return e ;
}
				
int EnsEstDans(ens e,couple d) 
{
	ens tmp = e ;
	if(EnsEstVide(tmp))
		return 0 ;				// chaine vide
	else
	{
		while(!EnsEstVide(tmp))
		{
			if ((tmp->c.x==d.x) && (tmp->c.y==d.y))
				{
					return 1 ;					// élément trouver
				}
			tmp=tmp->suiv ;						//élément suivant
		}
	}
	return 0 ;
}

int EnsTaille(ens e) 
{
	int i=0;
	ens tmp = e;
	for(i=0; tmp != NULL ; i++)	//i sera la taille de la liste
	{
		tmp=tmp->suiv ;			//parcours de la liste
	}
	return i ;
}

couple EnsTirage(ens *e) 
{
	couple d ;
	ens tmp = *e ;
	int i;
	int k = rand()%EnsTaille(*e)+1;	//nombre aléatoire entre 1 et la taille de la liste
	for(i=1;i<k;i++)
	{
		tmp=tmp->suiv ;				//parcours de la liste
	}
	d.x=tmp->c.x ;					//recupération du couple
	d.y=tmp->c.y ;
	*e=EnsSuppr(*e,d) ;				//suppression du couple
	return d ;
}

	
