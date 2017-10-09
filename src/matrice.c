#include <stdlib.h>
#include <stdio.h>
#include "matrice.h"

/**
 * \file mat.c
 * \brief  détails des fonctions de manipulation de matrice
 * \author Hetzlen Julien, Rabu Titouan
 * \version 1.0
 * \date 21 avril 2015
 * 
 */

matrice MatInit(matrice m)
{
	int i,j ;
	for(i=0;i < m->l; i++)
	{
		for(j=0;j<m->h;j++)
			m->t[i][j]=0 ;    //initialisation a faux
	}
	return m ;
}

matrice MatAlloc(int x, int y)
{
	int i ;
	matrice m=malloc(sizeof(struct str_matrice)) ;   //réservation de la mémoire
	m->l=x ;
	m->h=y ;
	m->t=(int**) malloc(x*sizeof(int*)); //allocation taille de la matrice (largeur)
	
	for(i=0;i<x;i++)
	{
		m->t[i]=(int*) malloc(y*sizeof(int)) ; // allocation taille de la matrice (hauteur)
	}
	return MatInit(m) ;
}

matrice MatFree(matrice m)
{
	int i ;
	for(i=0;i < m->l;i++)
	{
		free(m->t[i]) ;  //libération de la mémoire
	}
	free(m->t) ;
	free(m) ;
	m=NULL ;
	return m ;
}

int MatVal(matrice m, int x, int y) 
{
	return m->t[x][y] ;
}

matrice MatSet(matrice m, int val, int x, int y) 
{
	m->t[x][y] = val ;
	return m ;
}

void MatSauve(matrice m,char *nom_fichier)
{
	int i,j ;
	FILE *fp = fopen(nom_fichier,"w+") ;    //ouverture du fichier nom_grille
	fprintf(fp,"%d %d\n",m->l, m->h) ;
	for(i=0;i<m->h;i++)
	{
		for(j=0;j<m->l;j++)
		{
			fputc((m->t[j][i]+'0'),fp) ;
			fputc(' ',fp) ;
		}
		fputc('\n',fp) ;
	}
	fclose(fp) ;
}

matrice MatLit(char* nom_fichier)
{
	int a,b,i,j,k =0;
	FILE* fp = NULL ;
	fp=fopen(nom_fichier,"r") ;    //ouverture du fichier nom_grille
	if(fp==NULL)
	{	perror("error") ; exit(1) ;}
	fscanf(fp,"%4d %4d",&a,&b); //recuperation de la première ligne du fichier 
	matrice m=MatAlloc(a,b) ; //initialisation de la matrice 
	char line[2003] ;    //var tmp 
	fgets(line,2003,fp); 
	for(i=0;i<m->h;i++)
	{
		fgets(line,2003,fp);    //recupération de la matrice ligne par ligne dans le ficher
		for(j=0,k=0;j<m->l;j++,k+=2)
		{
			m->t[j][i]=line[k]-'0' ; 
		}
	}
	fclose(fp) ;
	return m ;
}

