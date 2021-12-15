#include<gtk/gtk.h>
typedef struct 
{
char id[30];
char lieu[30];
char event[30];
char ing[30];
char date[30];
int nb;
}eve ;

void ajouter_nb(eve A);
void supp_nb(char id[]);
eve rech_nb(char id[]);
void modi_nb(char id[], eve U);
void afficher_nb (GtkWidget *treeview1 ,char *l);
void afficher_ad_nb (GtkWidget *treeview1, char*l );
