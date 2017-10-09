#ifndef DEF_ENSEMBLE
#define DEF_ENSEMBLE

/**
 * \file ensemble.h
 * \brief  bibliothèques de fonction de manipulation des ensembles
 * \author Hetzlen Julien, Rabu Titouan
 * \version 1.0
 * \date 21 avril 2015
 * 
 */


/**
 * \struct couple
 * \brief Définition du type couple 
 * 
 * Cette structure contient deux entiers x, y qui correspondent aux deux nombres d'un couple.
 *  
 */
typedef struct
{
	int x ;
	int y ;
}couple ;


/**
 * \struct ens
 * \brief Définition du type ensemble
 * 
 * Cette structure contient un couple et un pointeur vers le couple suivant pour former
 * la liste chaînée correspondant à l'ensemble des couples.
 *  
 */
typedef struct str_ensemble
{
	couple c ;
	struct str_ensemble* suiv ;
}*ens;

/**
 * \fn couple InitCouple(int x,int y)
 * \brief Fonction de création d'un nouveau couple
 *
 * \param [in] int x qui sera la coordonnée x du couple
 * \param [in] int y qui sera la coordonnée y du couple
 * \return [out] couple c retourne un couple initialisé
 * 
 */
couple InitCouple(int x,int y) ;


/**
 * \fn ens EnsAlloc() 
 * \brief Fonction de création d'un nouvel ensemble d'un élément
 *
 * \param -
 * \return [out] ens e Retourne un ensemble
 * 
 */
ens EnsAlloc() ;


/**
 * \fn ens EnsFree(ens e) 
 * \brief Fonction de désallocation d'un ensemble
 *
 * \param [in] ens e paramètre qui sera désalloué dans la fonction
 * \return [out] ens e retourne un ensemble vide 
 * 
 */
ens EnsFree(ens e) ;


/**
 * \fn int EnsEstVide(ens e) 
 * \brief Fonction de vérification de vacuité d'un ensemble
 *
 * \param [in] ens e paramètre qui fera l'objet du test
 * \return [out] int retourne un booléen "1" si vrai "0" si faux
 * 
 */
int EnsEstVide(ens e) ;


/**
 * \fn ens EnsAjoute(ens e, couple a) 
 * \brief Fonction d'ajout d'un couple à un ensemble
 *
 * \param [in] ens e paramètre qui est l'ensemble où le couple sera ajouté
 * \param [in] couple a paramètre qui sera ajouté à l'ensemble
 * \return [out] ens e retourne l'ensemble avec le nouvel élément
 * 
 */
ens EnsAjoute(ens e, couple a) ;


/**
 * \fn ens EnsSuppr(ens e,couple d)
 * \brief Fonction de suppression du couple d'un ensemble envoyés en paramètre
 *
 * \param [in] ens e paramètre qui est l'ensemble où le couple sera supprimmé
 * \param [in] couple a paramètre qui sera supprimé de l'ensemble
 * \return [out] ens e retourne l'ensemble sans le couple à supprimer
 * 
 */
ens EnsSuppr(ens e,couple d) ;


/**
 * \fn int EnsEstDans(ens e, couple d)
 * \brief Fonction qui vérifie si un couple est bien présent dans l'ensemble
 *
 * \param [in] ens e paramètre qui est l'ensemble que l'on va tester
 * \param [in] couple a paramètre qui sera uttilisé pour le test
 * \return [out] int retourne un booléen "1" si vrai "0" si faux
 * 
 */
int EnsEstDans(ens e, couple d) ;


/**
 * \fn int EnsTaille(ens e)
 * \brief Fonction qui calcule le nombre d'éléments d'un ensemble
 *
 * \param [in] ens e paramètre dont la taille sera calculée
 * \return [out] int i retourne un entier qui sera le nombre d'éléments de l'ensemble
 * 
 */
int EnsTaille(ens e) ;


/**
 * \fn ens EnsTirage(ens* e)
 * \brief Fonction qui choisit aléatoirement un couple dans l'ensemble, le renvoie et le supprime de l'ensemble
 *
 * \param [in] ens e paramètre qui est l'ensemble dans lequel un effectue un tirage
 * \return [out] couple d retourne le couple tiré
 * 
 */
couple EnsTirage(ens* e) ;

#endif
