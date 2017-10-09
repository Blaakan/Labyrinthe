#ifndef DEF_FCT_LABY
#define DEF_FCT_LABY

/**
 * \file fct_laby.h
 * \brief  bibliothèques de fonction de créations et d'affichage de labyrinthe
 * \author Hetzlen Julien, Rabu Titouan
 * \version 1.0
 * \date 9 mai 2015
 * 
 */

#include "graph.h"
#include "ensemble.h"
#include "matrice.h"

/* fonction secondaire */

/**
 * \fn void Optlaby(int args,char** argc)
 * \brief  Fonction qui modifie les variable globale en fonction des paramètres rentrés
 *
 * \param [in] int args Le nombre d'arguments rentrés à l'exécution
 * \param [in] char** argc La liste des arguments rentrés à l'exécution
 * \return -
 * 
 */
void Optlaby(int args,char** argc) ;

/**
 * \fn void temporisation(double sec)
 * \brief Fonction de temporisation pour ralentir l'exécution du programme
 *
 * \param [in] double sec Nombre de secondes à attendre
 * \return -
 * 
 */
void temporisation(double sec) ;

/* affichage */

/**
 * \fn void TailleMatScreen()
 * \brief Fonction qui modifie la taille de la fenêtre et des pixels en fonction des variables globales qui définissent la taille de la matrice
 *
 * \param - 
 * \return - 
 * 
 */
void TailleMatScreen() ;

/**
 * \fn void AffCarre(int x, int y)
 * \brief Fonction qui affiche un carré noir d'un pixel qui correspond à un mur à des coordonnées x y
 *
 * \param [in] int x Première coordonnée du pixel
 * \param [in] int y Deuxième coordonnée du pixel
 * \return -
 * 
 */
void AffCarre(int x,int y);

/**
 * \fn void AffCaseCst(ens e, matrice m)
 * \brief Fonction qui affiche un carré vert d'un pixel qui correspond à une case constructible à des coordonnées x y
 *
 * \param [in] int x Première coordonnée du pixel
 * \param [in] int y Deuxième coordonnée du pixel
 * \return -
 * 
 */
void AffCaseCst(ens e,matrice m) ;

/**
 * \fn void AffChem(ens e,matrice m)
 * \brief Fonction qui affiche en vert le chemin pour sortir du labyrinthe
 *
 * \param [in] ens e La liste des cases par lesquelles passe le chemin
 * \param [in] matrice m Matrice dans laquelle le chemin se dessine
 * \return -
 * 
 */
void AffChem(ens e,matrice m) ;

/**
 * \fn void AffMat(matrice m)
 * \brief Fonction qui affiche une matrice avec les fonctions graphiques : les murs en noir, le reste en blanc
 *
 * \param [in] matrice m La matrice à afficher
 * \return -
 * 
 */
void AffMat(matrice m);

/**
 * \fn void AffMat2(matrice m)
 * \brief Fonction qui écrit dans le terminal le contenu d'une matrice : "0" pour un mur, " " pour le reste
 *
 * \param [in] matrice m La matrice à afficher
 * \return -
 * 
 */
void AffMat2(matrice m) ;

/*generation laby */

/**
 * \fn void InitMurBord(matrice m)
 * \brief Fonction qui créé des murs sur tous les bords de la matrice
 *
 * \param [in] matrice m La matrice dans laquelle on veut ajouter les murs sur les bords
 * \return -
 * 
 */
void InitMurBord(matrice m) ;

/**
 * \fn void InitBord(matrice m)
 * \brief Appelle InitMurBord pour créer des murs sur les bords, et créé en plus l'entrée en haut à gauche et la sortie en bas à droite
 *
 * \param [in] matrice m La matrice à initialiser
 * \return [out] 
 * 
 */
void InitBord(matrice m) ;

/**
 * \fn void InitBordAlea(matrice m)
 * \brief Fonction qui initialise les bords du layrinthe avec une entrée et une sortie aléatoire
 *
 * \param [in] matrice m Matrice à initialiser
 * \return -
 * 
 */
void InitBordAlea(matrice m) ;

/**
 * \fn couple GenCoupleAlea(matrice m)
 * \brief Fonction qui crée aléatoirement un couple à partir des coordonnées contenues dans la matrice
 *
 * \param [in] matrice m Matrice dans laquelle on va chercher les coordonnées aléatoirement
 * \return [out] couple c Couple généré aléatoirement
 * 
 */
couple GenCoupleAlea(matrice m) ;

/**
 * \fn ens GenEnsAlea(matrice m, int n)
 * \brief Fonction qui Crée un ensemble de n graines générées aléatoirement dans la matrice m
 *
 * \param [in] matrice m Matrice dans laquelle on va générer des graines
 * \param [in] int n Nombre de graine à générer
 * \return [out] ens e L'ensemble des graines générées dans la matrice m
 * 
 */
ens GenEnsAlea(matrice m, int n) ;

/**
 * \fn matrice GenMurGraine(matrice m, couple graine)
 * \brief Fonction qui construit un mur aléatoirement autour d'une graine
 *
 * \param [in] matrice m Matrice dans laquelle se trouvent la graine
 * \param [in] couple graine Graine autour de laquelle on va générer un mur
 * \return [out] matrice m Matrice modifiée avec le mur construit
 * 
 */
matrice GenMurGraine(matrice m, couple graine) ;

/**
 * \fn matrice GenMurAllGraines(matrice m, ens e)
 * \brief Fonction qui génère les murs aléatoires autour de toutes les graines d'une matrice
 *
 * \param [in] matrice m Matrice dans laquelle on va générer les murs
 * \param [in] ens e Ensemble des graines de la matrice
 * \return [out] matrice m Retourne la matrice modifiée avec les murs construits
 * 
 */
matrice GenMurAllGraines(matrice m, ens e);

/**
 * \fn int CheckOppoN(couple graine,matrice m)
 * \brief Fonction qui vérifie les 5 cases opposées au mur quand ce dernier se trouve au nord
 *
 * \param [in] couple graine Case autour de laquelle on effectue les vérifications
 * \param [in] matrice m Matrice dans laquelle on vérifie les cases opposées
 * \return [out] int - Retourne un booléen qui dit si la case est constructible ou non
 * 
 */
int CheckOppoN(couple graine, matrice m);

/**
 * \fn int CheckOppoS(couple graine,matrice m)
 * \brief Fonction qui vérifie les 5 cases opposées au mur quand ce dernier se trouve au sud
 *
 * \param [in] couple graine Case autour de laquelle on effectue les vérifications
 * \param [in] matrice m Matrice dans laquelle on vérifie les cases opposées
 * \return [out] int - Retourne un booléen qui dit si la case est constructible ou non
 * 
 */
int CheckOppoS(couple graine, matrice m) ;

/**
 * \fn int CheckOppoE(couple graine,matrice m)
 * \brief Fonction qui vérifie les 5 cases opposées au mur quand ce dernier se trouve à l'est
 *
 * \param [in] couple graine Case autour de laquelle on effectue les vérifications
 * \param [in] matrice m Matrice dans laquelle on vérifie les cases opposées
 * \return [out] int - Retourne un booléen qui dit si la case est constructible ou non
 * 
 */
int CheckOppoE(couple graine, matrice m) ;

/**
 * \fn int CheckOppoO(couple graine,matrice m)
 * \brief Fonction qui vérifie les 5 cases opposées au mur quand ce dernier se trouve à l'ouest
 *
 * \param [in] couple graine Case autour de laquelle on effectue les vérifications
 * \param [in] matrice m Matrice dans laquelle on vérifie les cases opposées
 * \return [out] int - Retourne un booléen qui dit si la case est constructible ou non
 * 
 */
int CheckOppoO(couple graine, matrice m);

/**
 * \fn int EstConstructible(matrice m, couple graine)
 * \brief Fonction qui vérifie si une case est constructible
 *
 * \param [in] matrice m Matrice dans laquelle on vérifie si une case est constructible
 * \param [in] couple graine Case de la matrice que l'on vérifie
 * \return [out] int - retourne un booléen qui dit si la case est constructible ou non
 * 
 */
int EstConstructible(matrice m, couple graine) ;

/**
 * \fn ens CheckVois(matrice m,ens e,couple d)
 * \brief Fonction qui vérifie les voisin d'un case sur laquelle on vient de construire un mur
 * 		  On l'ajoute à l'ensemble e si elle est constructible et on l'affiche en vert si l'option est choisie
 * 		  On l'enlève de l'ensemble e si elle n'est pas constructible
 *
 * \param [in] matrice m Matrice dans laquelle on se déplace
 * \param [in] ens e L'ensemble des cases constructibles de la matrice
 * \param [in] couple d Coordonnées de la case dont on vérifie les voisins
 * \return [out] ens e L'ensemble avec les couples ajoutés/supprimés
 * 
 */
ens CheckVois(matrice m,ens e,couple d);

/**
 * \fn ens GetVois(matrice m, ens e, couple a)
 * \brief Fonction qui supprime ou ajoute les cases voisines à celle que l'on vérifie à l'ensemble des cases constructibles
 *
 * \param [in] matrice m Matrice dans laquelle on se déplace
 * \param [in] ens e Ensemble des cases constructibles de la matrice
 * \param [in] couple a Coordonnées de la case dont on vérifie les voisins
 * \return [out] ens e L'ensemble des cases constructibles après vérification
 * 
 */
ens GetVois(matrice m,ens e, couple a) ;

/**
 * \fn ens MurAllConstr(matrice m, ens Ensmur)
 * \brief Fonction qui supprime de l'ensemble Ensmur les cases qui ne sont pas constructibles
 *
 * \param [in] matrice m Matrice dans laquelle on se déplace
 * \param [in] ens Ensmur L'ensemble des cases constructibles
 * \return [out] ens Ensmur Retourne l'ensemble précédent sans les cases non constructibles
 * 
 */
ens MurAllConstr(matrice m, ens Ensmur);

/**
 * \fn ens Ensemblecase(matrice m,ens e)
 * \brief Fonction qui ajoute à l'ensemble e l'ensemble des cases constructibles de la matrice m
 *
 * \param [in] matrice m Matrice dans laquelle on se déplace
 * \param [in] ens e L'ensemble des graines constructibles
 * \return [out] ens e L'ensemble des cases constructibles de la matrice m
 * 
 */
ens Ensemblecase(matrice m,ens e) ;

/**
 * \fn matrice ConstrLaby(matrice m, int n)
 * \brief Fonction qui construit un labyrinthe dans la matrice m
 *
 * \param [in] matrice m Matrice dans laquelle on va générer le labyrinthe
 * \param [in] int n Nombre de graines à générer dans la labyrinthe
 * \return [out] matrice m Retourne la matrice qui contient le labyrinthe
 * 
 */
matrice ConstrLaby(matrice m,int n) ;

/*recherche laby */

/**
 * \fn int DeplacementValide(matrice m,couple c)
 * \brief Fonction pour la génération du chemin qui vérifie si il peut continuer sur une case précise
 *
 * \param [in] matrice m Matrice qui contient le labyrinthe où on cherche le chemin
 * \param [in] couple c Case que l'on vérifie
 * \return [out] int - Un booléen qui dit si le déplacement est valide ou non
 * 
 */
int DeplacementValide(matrice m,couple c) ;

/**
 * \fn ens EnsembleDepInv(matrice m,ens caseinv)
 * \brief Fonction qui génère l'ensemble des cases d'une matrice où le déplacement n'est pas valide
 *
 * \param [in] matrice m Matrice depuis laquelle on génère l'ensemble
 * \param [in] ens caseinv Ensemble des cases où le déplacement n'est pas valide
 * \return [out] ens caseinv retourne l'ensemble des cases où le déplacement n'est pas valide
 * 
 */
ens EnsembleDepInv(matrice m,ens caseinv) ;

/**
 * \fn void DepAlea (ens *casevis,ens *chem)
 * \brief Fonction qui génère l'ensemble des cases du chemin
 *
 * \param [in] ens* casevis L'ensemble des cases visitées et des murs
 * \param [in] ens* chem Ensemble des cases qui composent le chemin
 * \return -
 * 
 */
void DepAlea (ens *casevis,ens *chem) ;

/**
 * \fn ens ConstrChem(matrice m, ens casevis, ens chem, couple fin, couple dep)
 * \brief Fonction qui construit le labyrinthe à partir d'une case d'entrée et jusqu'à une case de sortie
 *
 * \param [in] matrice m Matrice dans laquelle on cherche le chemin
 * \param [in] ens casevis L'ensemble des cases visitées par le chemin
 * \param [in] ens chem L'ensemble des cases du chemin
 * \param [in] couple fin Coordonnées de la case de sortie
 * \param [in] couple dep Coordonnées de la case de départ
 * \return [out] ens chem Retourne l'ensemble de couple qui correspond au chemin depuis l'entrée jusqu'à la sortie
 * 
 */
ens ConstrChem(matrice m,ens casevis,ens chem,couple fin,couple dep) ;

#endif
