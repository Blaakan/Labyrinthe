#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "constante.h"
#include "graph.h"
#include "fct_laby.h"

/**
 * \file genlaby.c
 * \brief  détails des fonctions de création de labyrinthe
 * \author Hetzlen Julien, Rabu Titouan
 * \version 1.0
 * \date 21 avril 2015
 * 
 */

int main(int args,char **argc)
{
	Optlaby(args,argc);
	TailleMatScreen() ;
	srand(time(NULL));
	matrice m=MatAlloc(a,b);
	initgraph(c,d);
	if(balea)
	{
		InitBordAlea(m);
	}
	else
	{
		InitBord(m);
	}
	ConstrLaby(m,N) ;
	if(vlg!=1)
		AffMat(m) ;
	waitgraph();
	closegraph();
	if(svm)
		MatSauve(m,nomfile) ;
	MatFree(m) ;
	return 0 ;
}


















