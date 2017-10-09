#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "fct_laby.h"

/**
 * \file fct_laby.c
 * \brief  détails de manipulation de labyrinthe
 * \author Hetzlen Julien, Rabu Titouan
 * \version 1.0
 * \date 21 avril 2015
 * 
 */

extern int balea;
extern int vlg;			// visualisation de la construction du labyrinthe ou visualisation de la recherche d'un chemin
extern int vcc ;		// visualisation des cases constructibles
extern int svm ;		// activation de la sauvegarde (activer si un nom de fichier est en argument
extern int a ; 			//largeur matrice
extern int b ; 			//hauteur matrice
extern int c ;			//largeur fenêtre
extern int d;			//hauteur fenêtre
extern int pix ;		//taille pixel
extern char nomfile[100] ;	//nom du fichier dans lequels il faut sauvegarder le labyyrinthe

void Optlaby(int argc,char** argv)		
{
	int i;
	if(argc<1)
		return ;
	for(i=1;i<argc;i++)
	{
		if(argv[i][0]=='-'&& argv[i][1]=='a')		//option pour avoir un entrer et une sortie placée aléatoirement dans le labyrinthe
			balea=1 ;
		if(argv[i][0]=='-'&& argv[i][1]=='v')		//visualisation construction labyrinthe ou chemin
			vlg=1 ;
		if(argv[i][0]=='-'&& argv[i][1]=='d')		//visualisation des cases constructibles
		{
			vlg=1 ;
			vcc=1 ;
		}
		if(argv[i][0]=='-'&& argv[i][1]=='l')		//largeur matrice
		{
			a=atoi(argv[i+1]) ;
			i++ ;
		}
		if(argv[i][0]=='-'&& argv[i][1]=='h')		//hauteur matrice
		{
			b=atoi(argv[i+1]) ;
			i++ ;
		}
		if(argv[i][0]!='-' && (argv[i][0]<='0' || argv[i][0]>='9'))	//sauvegarde de la matrice
		{
			strcpy(nomfile,argv[i]) ;
			svm=1 ;
		}
	}
	return ;
}

void temporisation(double sec)			//fonction pour faire une eventuelle temporisation dans la vitesse d'affichage
{
    clock_t tempo;
    tempo = (sec * CLOCKS_PER_SEC) + clock();
    while(tempo > clock()) ;
}

 // ********************************* //
 /*		     fct affichage            */
 // ********************************* //
 
void TailleMatScreen()				//détermine la taille de la fenêtre et des pixels en fonction de la hauteur/largeur de la matrice
{	
	if(a>1000)
	{
		a=1000 ;
		c=a ;
	}
	if(b>800)
	{
		b=800 ;
		d=b ;
	}
	if(a<=200 && b<=160)
		pix=5 ;
	if(a<=100 && b<=80)
		pix=10 ;
	int i;
	for(i=3;i>0;i--)
	{
		c=pix*a ;
		d=pix*b ;
		if(c>1000|| d>800)
		{
			pix--;
		}				
	}
	
}

void AffCarre(int x,int y)			//affiche un carré de pixels
{
	int i,j ;
	for(i=0;i<pix;i++)
	{
		for(j=0;j<pix;j++)
		{
			putpixel(x+i,y+j) ;
		}
	}	
}

void AffCaseCst(ens e,matrice m)   //affiche les cases constructibles
{
	int i ;
	ens tmp=e ;
	setcolor(newcolor(0,1,0));
	for(i=0;i<EnsTaille(e); i++)
	{
		AffCarre((tmp->c.x)*pix,(tmp->c.y)*pix);
		tmp=tmp->suiv ;
	}
	setcolor(newcolor(0,0,0));
	refresh();
}	

void AffChem(ens e,matrice m) //affiche un chemin 
{
	int i ;
	ens tmp=e ;
	setcolor(newcolor(0,1,0));
	for(i=0;i<EnsTaille(e); i++)
	{
		AffCarre((tmp->c.x)*pix,(tmp->c.y)*pix);
		tmp=tmp->suiv ;
	}
	setcolor(newcolor(0,0,0));
	refresh();
}

void AffMat(matrice m)			//afffiche le labyrinthe
{
	int i,j ;
	for(i=0;i<m->l;i++)
	{
		for(j=0;j<m->h;j++)
		{
			if(m->t[i][j]==1)
			AffCarre(i*pix,j*pix);
		}
	}
	refresh();
}

void AffMat2(matrice m)			//affiche le labyrinthe dans la console
{
	int i,j ;
	for(i=0;i<m->l;i++)
	{
		for(j=0;j<m->h;j++)
		{
			if(m->t[i][j])
				printf("0");
			else
				printf(" ");
		}
		printf("\n");
	}
}

 // ********************************* //
 /*		fct creation labyrinthe       */
 // ********************************* //
  
void InitMurBord(matrice m)			//initialise les bord de la matrice avec l'entrée en haut a gauche est la sortie en bas à droite
{
	int i;
	for (i=0;i<m->l;i++)
		m->t[i][0] = 1 ;
	for (i=0;i<m->h;i++)
		m->t[0][i] = 1 ;
	for (i=0;i<m->l;i++)
		m->t[i][m->h-1] = 1;
	for (i=0;i<m->h;i++)
		m->t[m->l-1][i] = 1; 
}
  
 void InitBord(matrice m)  // initialise les bord avec une entree et une sortie fixe
{
	InitMurBord(m) ;
	m->t[0][1]=0;
	m->t[m->l-2][m->h-1]=0;
}	

 void InitBordAlea(matrice m)  // initialise les bord avec une entree et une sortie aleatoire 
{
	int alea = rand()%4 ;
	int alea2 ;
	InitMurBord(m) ;
	switch(alea)
	{
		case 0:
			alea2=rand()%(m->l-2);
			m->t[alea2+1][0]=0 ;
			break ;
		case 1:
			alea2=rand()%(m->h-2);
			m->t[m->l-1][alea2+1]=0 ;
			break ;
		case 2:
			alea2=rand()%(m->l-2);
			m->t[alea2+1][m->h-1]=0 ;
			break ;
		case 3:
			alea2=rand()%(m->h-2);
			m->t[0][alea2+1]=0 ;
			break ;
	}
	int temp=alea;
	while(alea==temp)
	{alea = rand()%4 ;}
	switch(alea)
	{
		case 0:
			alea2=rand()%(m->l-2);
			m->t[alea2+1][0]=0 ;
			break ;
		case 1:
			alea2=rand()%(m->h-2);
			m->t[m->l-1][alea2+1]=0 ;
			break ;
		case 2:
			alea2=rand()%(m->l-2);
			m->t[alea2+1][m->h-1]=0 ;
			break ;
		case 3:
			alea2=rand()%(m->h-2);
			m->t[0][alea2+1]=0 ;
			break ;
	}
}

couple GenCoupleAlea(matrice m)		//génére un couple aléatoire
{
	couple c;
	c.x=(rand()%(m->l-2))+1 ;
	c.y=(rand()%(m->h-2))+1 ;
	return c ;
}

ens GenEnsAlea(matrice m, int n)		//génére un ensensemble de couple aléatoire
{
	ens e=NULL;
	couple c;
	int i=0;
	while(i<n)
	{
		c =GenCoupleAlea(m) ;
		if(!(EnsEstDans(e,c)))
			{
				e=EnsAjoute(e,c) ;
				i++;
			}
	}
	return e ;
}

matrice GenMurGraine(matrice m, couple graine)   //génére un mur aléatoirement autour d'un graine
{
	couple mur;
	mur.x=0;
	mur.y=0;
	while( (mur.x==0 && mur.y==0) || MatVal(m,(mur.x+graine.x),(mur.y+graine.y)) || ( (mur.x+graine.x==0) || (mur.x+graine.x==m->l-1) || (mur.y+graine.y==0) || (mur.y+graine.y==m->h-1) ) )
	{
		mur.x=(rand()%3)-1;
		mur.y=(rand()%3)-1;
	}
	MatSet(m,1,mur.x+graine.x,mur.y+graine.y);
	return m;
}
		
matrice GenMurAllGraines(matrice m, ens e) //génére tout les murs a coté des graines
{
	int taille=EnsTaille(e);
	int i;
	ens tmp = e;
	for(i=0;i<taille;i++)
	{
		m=GenMurGraine(m,tmp->c);
		tmp=tmp->suiv;
	}
	return m;
}

int CheckOppoN(couple graine, matrice m)
{
	return !(MatVal(m,graine.x-1,graine.y) + MatVal(m,graine.x-1,graine.y+1) + MatVal(m,graine.x,graine.y+1) + MatVal(m,graine.x+1,graine.y+1) + MatVal(m,graine.x+1,graine.y) );
}

int CheckOppoS(couple graine, matrice m)
{
	return !(MatVal(m,graine.x-1,graine.y) + MatVal(m,graine.x-1,graine.y-1) + MatVal(m,graine.x,graine.y-1) + MatVal(m,graine.x+1,graine.y-1) + MatVal(m,graine.x+1,graine.y) );
}

int CheckOppoE(couple graine, matrice m)
{
	return !(MatVal(m,graine.x,graine.y-1) + MatVal(m,graine.x-1,graine.y-1) + MatVal(m,graine.x-1,graine.y) + MatVal(m,graine.x-1,graine.y+1) + MatVal(m,graine.x,graine.y+1) );
}

int CheckOppoO(couple graine, matrice m)
{
	return !(MatVal(m,graine.x,graine.y-1) + MatVal(m,graine.x+1,graine.y-1) + MatVal(m,graine.x+1,graine.y) + MatVal(m,graine.x+1,graine.y+1) + MatVal(m,graine.x,graine.y+1) );
}

int EstConstructible(matrice m, couple graine)	//vérification si une case est constructible
{
	if( (graine.x<=0) || (graine.y<=0) || (graine.x>=m->l-1) || (graine.y>=m->h-1) )
		return 0 ;
	if( MatVal(m,graine.x,graine.y)==1  )
		return 0 ;
	int cN = MatVal(m,graine.x,graine.y-1);
	int cS = MatVal(m,graine.x,graine.y+1);
	int cE = MatVal(m,graine.x+1,graine.y);
	int cO = MatVal(m,graine.x-1,graine.y);
	if (cN+cS+cE+cO != 1)
		return 0 ;
	else
		{
			if (cN) { return CheckOppoN(graine,m); }
			if (cS) { return CheckOppoS(graine,m); }
			if (cE) { return CheckOppoE(graine,m); }
			if (cO) { return CheckOppoO(graine,m); }
		}
	return 0;
}

ens CheckVois(matrice m,ens e,couple d)
{
	if(!(EnsEstDans(e,d)) && EstConstructible(m,d)) 	//si constructible et n'est pas deja dans l'ensemble on l'ajoute
	{
		e=EnsAjoute(e,d);
		return e ;	
	}
	if( !(EstConstructible(m,d)) && EnsEstDans(e,d) ) 	//si non constructible est présent dans l'ensemble on le supprime
	{
		if(vcc)							// si l'option de visualisation est activer on enleve remet les cases devenu non constrible en blanc
		{
			setcolor(newcolor(1,1,1));
			AffCarre(d.x*pix,d.y*pix) ;
			setcolor(newcolor(0,0,0)); 
		}
		e=EnsSuppr(e,d);
		return e ;	
	}
	return e ;
}

ens GetVois(matrice m,ens e, couple a) // on vérifie si les voisin d'un nouveau mur deviennent constructible ou ne le sont plus
{
	couple tmp=InitCouple(a.x-1,a.y-1);
	e=CheckVois(m,e,tmp);
	tmp=InitCouple(a.x,a.y-1);
	e=CheckVois(m,e,tmp);
	tmp=InitCouple(a.x+1,a.y-1);
	e=CheckVois(m,e,tmp);
	tmp=InitCouple(a.x-1,a.y);
	e=CheckVois(m,e,tmp);
	tmp=InitCouple(a.x+1,a.y);
	e=CheckVois(m,e,tmp);
	tmp=InitCouple(a.x-1,a.y+1);
	e=CheckVois(m,e,tmp);
	tmp=InitCouple(a.x,a.y+1);
	e=CheckVois(m,e,tmp);
	tmp=InitCouple(a.x+1,a.y+1);
	e=CheckVois(m,e,tmp);
	return e;
}

ens MurAllConstr(matrice m, ens Ensmur)			// on supprime de l'ensemble toute les case non constructible
{
	ens tmp = Ensmur;
	int k = EnsTaille(Ensmur);
	int i;
	for (i=0;i<k-1;i++)
	{
		if (  !(EstConstructible(m,tmp->c))  )
		{
			Ensmur=EnsSuppr(Ensmur,tmp->c);
		}
		tmp=tmp->suiv;
	}
	return Ensmur ;
}

ens Ensemblecase(matrice m,ens e)	//ajout des case constructible de la matrice dans l'enseble
{
	int i,j ;
	couple d ;
	for(i=1;i<m->l-1;i++)
	{
		d.x=i ;
		for(j=1;j<m->h-1;j++)
		{
			d.y=j ;
					
			if(!(EnsEstDans(e,d)) && (EstConstructible(m,d)))
			{
				e=EnsAjoute(e,d) ;
			}
		}
	}
	return e ;
}

matrice ConstrLaby(matrice m,int n)
{
	couple d;
	ens e=GenEnsAlea(m,n) ;			//on génére les graine aléatoire
	m=GenMurAllGraines(m,e) ;
	e=MurAllConstr(m,e) ;			// on construit les mur
	e=Ensemblecase(m,e) ;
	while(!EnsEstVide(e))
	{
		if(vcc)						// on visualise les case constructibles du labyrinthe si l'option est activer
		{
			AffCaseCst(e,m) ;
		}
		d=EnsTirage(&e);			// on tire des couple aléatoirement dans l'ensemble des case constructible
		m->t[d.x][d.y]=1 ;			// on construit le mur
		e=GetVois(m,e,d);			// on enleve les éventuelle case devenu non constructible présente dans l'ensemmble
		if(vlg)
		{
			AffMat(m) ;					// on visualise la constructions du labyrinthe si l'option est activer
		}
	}
	return m;
}

 // ********************************* //
 /*		fct_ recherche chemin         */
 // ********************************* //
 
int DeplacementValide(matrice m,couple c)
{
	return !(MatVal(m,c.x,c.y)) ;    //deplacement valide si la matrice n'est pas un mur (!=1)
}

ens EnsembleDepInv(matrice m,ens caseinv) // met a jour l'ensemble des cases ou le chemin ne pourra pas passer (les murs)
{
	int i,j ;
	couple d ;
	for(i=0;i<m->l;i++)
	{
		d.x=i ;
		for(j=0;j<m->h;j++)
		{
			d.y=j ;		
			if(!DeplacementValide(m,d)) // si le déplacement n'est pas valide on l'ajoute dans l'ensemble
			{
				caseinv=EnsAjoute(caseinv,d) ;
			}
		}
	}
	return caseinv ;
}
	
void DepAlea (ens *casevis,ens *chem)
{
	couple casesuiv;
	ens tmp=*chem ;
	ens tmp2=NULL ;
	casesuiv.x=(tmp->c.x)-1;					// on met les quatre cases adjascentes dans un ensemble pour pouvoir les tirer aléatoirement
	casesuiv.y=(tmp->c.y);
	tmp2=EnsAjoute(tmp2,casesuiv);				
	casesuiv=InitCouple(tmp->c.x,tmp->c.y-1);	
	tmp2=EnsAjoute(tmp2,casesuiv);
	casesuiv=InitCouple(tmp->c.x+1,tmp->c.y);
	tmp2=EnsAjoute(tmp2,casesuiv);
	casesuiv=InitCouple(tmp->c.x,tmp->c.y+1);	
	tmp2=EnsAjoute(tmp2,casesuiv);
	casesuiv=InitCouple(1,1);
	while(EnsEstDans(*casevis,casesuiv) && !(EnsEstVide(tmp2)))
	{
			casesuiv=EnsTirage(&tmp2);					// tire au hasard une des quatre case adjascente 
	}
	if(tmp2==NULL && EnsEstDans(*casevis,casesuiv))		//si toute les case adjascente ont été tiré et qu'elle font partie de l'ensemble des cases deja visité ou non valide
	{
		if(vlg)											// si l'option de visualisation est activer
		{	
			setcolor(newcolor(1,1,1));
			AffCarre(tmp->c.x*pix,tmp->c.y*pix) ;		// la case supprimmer est réafficher en blanc car elle  n'appartient plus a l'ensemble
			setcolor(newcolor(0,0,0)); 
		}
		*chem=EnsSuppr(*chem,tmp->c);					// on supprimme la tête cela revien a revenir a la case précédente
	}
	else
	{
		*chem=EnsAjoute(*chem,casesuiv) ;				// si le couple tirer est un déplacement valide on l'ajoute au chemin et à l'ensemble des cases visitées
		*casevis=EnsAjoute(*casevis,casesuiv);
	}
	return ;
}

ens ConstrChem(matrice m,ens casevis,ens chem,couple fin,couple dep)
{
	while( (chem->c.x!=dep.x || chem->c.y!=dep.y) &&( chem->c.x!=fin.x || chem->c.y!=fin.y)) // on continue tant que l'on est pas retourner à la case départ ou à la fin du labyrinthe
	{
		DepAlea (&casevis,&chem) ;
		if(vlg)
		{
			AffChem(chem,m);		// si l'option  est activer on visualise la recherche du chemin
			AffMat(m) ;
		}
	}
	return chem;
}
