//#ifndef HEBERGEMENT_H_INCLUDED
//#define HEBERGEMENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include <string.h>
#include <time.h>

typedef struct datee {

    int j;
    int m;
    int a;

}datee;

typedef struct etudiant {

        int id;
        char prenom[20];
        char nom[20];
        datee d;
	char bloc[2];
        int chambre;
	int n;
        int tel;
        char email[50];

}etudiant;

typedef struct alarme {

        int type;         // 0 pour mouvement, 1 pour fumée
        char etage[10];
        datee d;
        int h;           //heure
        int m;           //minute

}alarme;


void ajouter_hebergement(etudiant e, char *fname);
void supprimer_hebergement(etudiant e, char *fname);
void afficher_hebergement(GtkWidget *liste, char *fname);
void modifier_hebergement(etudiant e, char *fname);
etudiant chercher_hebergement(int id, char *fname);
void afficher_alarme(GtkWidget *liste, char *fname);


//#endif
