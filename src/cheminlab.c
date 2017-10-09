#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fct_laby.h"
#include "constante.h"


/**
\mainpage
* 	Projet Structure de données et algorithmes\n
* 	Génération de labyrinthe aléatoire et recherche de chemin vers la sortie d'un labyrinthe\n
* 															Hetzlen Julien et Titouan Rabu\n
*	Cette documentation contient les différentes fonctions de ces deux programmes, détaille comment les utilisées et égalament leurs utilités
* 		

*/




/**
 * \file cheminlab.c
 * \brief  détails des fonctions de création de chemin
 * \author Hetzlen Julien, Rabu Titouan
 * \version 1.0
 * \date 21 avril 2015
 * 
 */


int main(int argc,char **argv)
{
	Optlaby(argc,argv) ;
	srand(time(NULL));
	matrice m=MatLit(nomfile) ;
	a=m->l ;
	b=m->h ;
	TailleMatScreen() ; 
	initgraph(c,d);	
	couple dep,fin ;
	dep=InitCouple(0,1);
	fin=InitCouple(m->l-2,m->h-1);
	ens chem=NULL ;
	ens casevis=NULL ;
	chem=EnsAjoute(chem,dep);
	casevis=EnsAjoute(casevis,dep);
	dep.x=1;
	chem=EnsAjoute(chem,dep);
	casevis=EnsAjoute(casevis,dep);
	casevis=EnsembleDepInv(m,casevis) ;
	dep.x--;
    chem=ConstrChem(m,casevis,chem,fin,dep) ;
    if(vlg!=1)
		AffChem(chem,m) ;
		AffMat(m) ;
	waitgraph();
	closegraph();
	EnsFree(chem);
	EnsFree(casevis);
	MatFree(m) ;   
	return 0;
}

