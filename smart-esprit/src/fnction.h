#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <gtk/gtk.h>



typedef struct {
char id[20];
char type[20];
char position[20];
char etat[20];
char valeur[20]
}capteur;

typedef struct {
int idx;
int val;
int jour;
int heure;
}capteurx;



void afficher(GtkWidget* liste);
void afftrouver(GtkWidget* liste, int i);
void viderliste(GtkWidget *liste);
int nospace(char s[]);
void ajout( capteur x );
int isalphabet(char t[]);
int isid(char t[]);
int isint(char t[]);
int supprimer(char id[]);
int modifier(capteur x);
int recherche( char id[]);
int fileload();
int filesave();

#endif
