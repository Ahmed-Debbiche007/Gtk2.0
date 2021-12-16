#ifndef PROJET_H_INCLUDED
#define PROJET_H_INCLUDED
#include <gtk/gtk.h>
typedef struct date
{
    int jour;
    int mois;
    int annee;
}date;

typedef struct nut
{
    char id[20];
    char repas[20];
    char menu[20];
    char plats[20];
    char platprincipal[20];
    char dessert[20];
    char boisson[20];
    char entree[20];
    date d;


}nut;
typedef struct menu
{
    char jour[20];
    char temps[20];
    char val[20];


}menu;

void ajoutr(nut n);
void afficher_menu(GtkWidget *liste);
int verf(char id[]);
void actu(GtkWidget *liste );
void supprimr (char id[]);
void modifir(char id[], nut n1 );
void afficher_repas(GtkWidget *liste );
void cherchr(char repas[],nut n);
int controle(char ch[]);





#endif // PROJET_H_INCLUDED
