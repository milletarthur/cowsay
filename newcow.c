#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "newcow.h"

void mult_carac(char *chaine,char c, int n) {                                       // Transforme la chaîne s en une chaîne contenant n fois le caractère c
    int i;
    for (i = 0; i < n; i++) {
        chaine[i] = c;
    }
    chaine[n] = '\0';
}

void affiche_bulle(char *texte) {
    int taille = strlen(texte);
    char underscores[taille + 2];
    mult_carac(underscores, '_', taille + 2);
    char dashes[taille + 2];
    mult_carac(dashes, '-', taille + 2);
    printf(" %s\n",underscores);
    printf("< %s >\n", texte);
    printf(" %s\n",dashes);
}



void affiche_vache(char eyes[2], char tongue[2], int longueur, int hauteur, char *texte) {                    // Permet d'afficher la vache avec les paramètres donnés
    affiche_bulle(texte);
    char underscores[longueur + 1];
    mult_carac(underscores,'_', longueur);
    char spaces[longueur + 1];
    mult_carac(spaces,' ', longueur);
    char dashes[longueur + 1];
    mult_carac(dashes,'-', longueur);
    printf("        \\   ^__^\n\
         \\  (%s)\\__%s_\n\
            (__)\\  %s )\\/\\\n\
",eyes,underscores,spaces);
    if (hauteur <= 2) {
        printf("             %s ||%sw |\n", tongue,dashes);
    }
    else {
        printf("             %s | %s  |\n",tongue,spaces);
    }
    for (int i=0; i<hauteur-3; i++) {
    printf("                |%s   |\n",spaces);
    }
    if (hauteur > 2) {
        printf("                ||%sw |\n",dashes);
    }
    printf("                ||%s ||\n", spaces);
}
