#ifndef DEF_MATRICE
#define DEF_MATRICE

/**
 * \file matrice.h
 * \brief  Bibliothèques de fonctions de manipulation de matrices
 * \author Hetzlen Julien, Rabu Titouan
 * \version 1.0
 * \date 21 avril 2015
 * 
 */
 
/**
 * \struct couple
 * \brief Définition du type matrice hxl 
 * 
 * Cette structure contient deux entiers h et l qui sont les dimmensions de la matrice
 * Le tableau à deux dimmensions t  représente la matrice à proprement parler 
 * 
 */
typedef struct str_matrice
{
	int** t ;
	int h ;
	int l ;	
}*matrice ;


/**
 * \fn matrice MatInit(matrice m) 
 * \brief Fonction d'initialisation d'une matrice
 *
 * \param [in] matrice m paramètre à initialiser
 * \return [out] matrice m retourne la matrice initalisée à "faux"
 * 
 */
matrice MatInit(matrice m) ;


/**
 * \fn matrice MatAlloc(int x, int y)
 * \brief Fonction de création d'une nouvelle matrice
 *
 * \param [in] int x paramètre qui va définir la taille de la matrice
 * \param [in] int y paramètre qui va définir la taille de la matrice
 * \return [out] matrice m retourne la matrice créée et initialisée 
 * 
 */
matrice MatAlloc(int x, int y) ;


/**
 * \fn matrice MatFree(matrice m)
 * \brief Fonction de désallocation d'une matrice
 *
 * \param [in] matrice m paramètre à désaloué
 * \return [out] matrice m retourne la matrice pointant sur NULL
 * 
 */
matrice MatFree(matrice m) ;


/**
 * \fn int MatVal(matrice m, int x, int y)
 * \brief Fonction qui récupère la valeur d'une case de la matrice
 *
 * \param [in] matrice c paramètre dans lequel la valeur est recherchée
 * \return [out] int retourne la valeur recherchée
 * 
 */
int MatVal(matrice m, int x, int y) ;


/**
 * \fn matrice MatSet(matrice m, int val, int x, int y)
 * \brief Fonction qui remplace la valeur dans une case [x,y] de la matrice
 *
 * \param [in] matrice c paramètre dans lequel la valeur va être remplacée
 * \param [in] int val paramètre qui est la valeur que l'on veut insérer dans la matrice
 * \param [in] int x paramètre qui est une des cooordonées où il faut placer la valeur (largeur)
 * \param [in] int y paramètre qui est une des cooordonées où il faut placer la valeur (hauteur)
 * \return [out] matrice m retourne la matrice avec sa nouvelle valeur aux coordonées [x,y]
 * 
 */
matrice MatSet(matrice m, int val, int x, int y) ;


/**
 * \fn void MatSauve(matrice m,char* nom_fichier)
 * \brief Fonction qui sauvegarde une matrice dans un fichier
 *
 * \param [in] matrice c paramètre qui va être sauvegardé dans un fichier
 * \param [in] char* nom_fichier paramètre qui est le nom du fichier dans lequel sauvegarder
 * \return -
 * 
 */
void MatSauve(matrice m,char* nom_fichier) ;


/**
 * \fn void MatLit(char* nom_fichier)
 * \brief Fonction qui lit une matrice dans un fichier
 *
 * \param [in] char* nom_fichier paramètre qui est le nom du fichier à charger 
 * \return [out] matrice m retourne la matrice qui était dans le fichier
 * 
 */
matrice MatLit(char* nom_fichier);

#endif
