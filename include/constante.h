#ifndef DEF_CONSTANTE
#define DEF_CONSTANTE

/**
 * \file constante.h
 * \brief  bibliothèque qui contient les variables globales (pour les options et la taille de la matrice)
 * \author Hetzlen Julien, Rabu Titouan
 * \version 1.0
 * \date 21 avril 2015
 * 
 */

#define N 3
#define K 3
#define WIDTH_MAT 300
#define HEIGHT_MAT 200
#define WIDTH_SCREEN 900
#define HEIGHT_SCREEN 600


/**
 * \brief Variable globale correspondante à l'option pour générer une sortie et une entrée aléatoire
 * 
 */

int balea=0 ;

/**
 * \brief Variable globale correspondante à l'option de visualisation (de chemin ou de labyrinthe)
 * 
 */

int vlg=0 ;

/**
 * \brief Variable globale correspondante à l'option de visualisation des cases constructibles
 * 
 */

int vcc=0 ;

/**
 * \brief Variable globale correspondante à la sauvegarde du labyrinthe dans un fichier
 * 
 */

int svm=0 ;

/**
 * \brief Variable globale correspondante à la taille de la matrice
 * 
 */

int a=WIDTH_MAT ;

/**
 * \brief Variable globale correspondante à la taille de la matrice
 * 
 */

int b=HEIGHT_MAT ;

/**
 * \brief Variable globale correspondante à la taille de la fenêtre
 * 
 */

int c=WIDTH_SCREEN ;

/**
 * \brief Variable globale correspondante à la taille de la fenêtre
 * 
 */

int d=HEIGHT_SCREEN ;

/**
 * \brief Variable globale correspondante à la taille d'un pixel
 * 
 */

int pix=K ;

/**
 * \brief Variable globale correspondante à la taille maximal des noms de fichier
 * 
 */

char nomfile[100] ;


#endif
