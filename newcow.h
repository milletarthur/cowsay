#include <stdio.h>
#include <string.h>
#include <unistd.h>


// Transforme la chaîne s en une chaîne contenant n fois le caractère c
void mult_carac(char *chaine,char c, int n);

void affiche_bulle(char *texte);

// Permet d'afficher la vache avec les paramètres donnés
void affiche_vache(char eyes[2], char tongue[2], int longueur, int hauteur, char *texte);
