#include"newcow.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
#define NB_ETATS 3
#define NB_ENTREES 11
#define LG_MAX_SORTIE 128
 
#define liferocks 0
#define lifesucks 1
#define byebyelife 2
 
typedef int etat ;
 
long generer_entier(long borne_plus) {
    static int seme = 0;
    if (!seme) {
        srandom(getpid());
        seme = 1;
    }
    return random() % borne_plus;
}
 
void update() {
    printf ("\033[H\033[J") ;
}
 
etat etat_initial() {
    return liferocks ;
}

int est_final(etat E) {
    return E == byebyelife ;
}

int lire_entree(char stock) {
char entree ;
    printf("Veuillez choisir une quantité de nourriture entre 0 et %d : \n", stock) ;
    scanf("%c",&entree) ;
    while (((entree < '0') || (entree > stock+'0')) && (entree != '-')) {
        printf("Vous devez choisir au minimum 0 unité de nourriture, dans dépasser ce qu'il vous reste en stock (%d) : \n",stock) ;
        scanf("%c", &entree) ;
        }
    if (entree == '-') {
        affiche_vache("00","  ",6,2,"Adieux ....") ;
        exit(-1) ;
    }
    return entree-'0' ;
}
 
int transition [3][11] = {
    {2,1,1,1,0,0,0,1,1,1,2},
    {2,1,1,1,0,0,0,1,1,1,2},
    {2,1,1,1,0,0,0,1,1,1,2}};

void simule_automate() {
    int etat_courant, etat_suivant, entree ;
    entree = 0 ;
    long entier_alea ;
    int pos_neg ;
    char stock = 5 ;
    int digestion ;
    int fitness=5 ;
    int lunchfood ;
    int crop ;
    long score = 0 ;
 
    etat_courant = etat_initial() ;
    affiche_vache("00","  ",4,2,"Bienvenue !") ;
    while (etat_courant != byebyelife) {
        lunchfood = lire_entree(stock) ;
        digestion = -(generer_entier(4)) ; //random entre -3 et 0
        fitness = (fitness + lunchfood) + digestion ;
        while ((fitness < 0) || (fitness > ('9'-'0'+1))){ // faut transformer le char en int pour pouvoir le comparer à 10
            if (fitness == 1 && lunchfood == 0) {
				affiche_vache("00","  ",6,2,"Adieux ....") ;
				exit(-1) ;
			}
			digestion = -(generer_entier(4)) ; // random entre -3 et 0
            fitness = (fitness + lunchfood) + digestion ;
        }
        etat_suivant = transition[etat_courant][fitness] ;
        etat_courant = etat_suivant ;
        update() ;
        if (etat_courant == byebyelife) {
            affiche_vache("XX", "  ", 4, 2, "C’est la fin.") ; //affiche vache morte
            printf("Oh non, votre vache nous a quitté !\n") ;
            printf("Votre score a été de : %ld\n", score) ;
            exit(-1) ;
        }
        if (etat_courant == lifesucks){
            affiche_vache("@@", "  ", fitness, 2, "Je me sens pas très bien …") ; //affiche vache malade  òó óò
        }
        if (etat_courant == liferocks){
            affiche_vache("00", "u ", fitness, 2, "Tout vas bien !") ; //affiche vache normale
        }
       
        pos_neg = generer_entier(100) ; // pour choisir un nombre positif ou négatif
        if(pos_neg >= 50){
            pos_neg = 1 ;
        }
        else {
            pos_neg = -1 ;
        }
        crop = generer_entier(4)*pos_neg ; // random entre -3 et 3
        printf("Crop : %d\n",crop) ;
        stock = (stock - lunchfood) + crop ;
 
        if (stock > 10) {
            stock = 10;
        }
        else if (stock < 0) {
            stock = 0;
        }
 
        score++ ;
    }
    printf("Votre score a été de : %ld\n", score);
}
 
int main() {
    simule_automate() ;
return 0 ;
}
