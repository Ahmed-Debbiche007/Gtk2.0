#include <gtk/gtk.h>
int m,k;

typedef struct
{
    int jour;
    int mois;
    int annee;

}Date;

typedef struct 
{ 
char id[200] ; 
char NOM[200];
char Prenom[200];
char CIN[200];
char sui[200];
char messageRecla[200];
char resp[200];
Date dt_ns;

}reclamation;

void Ajouter_ch(reclamation o);
void supp_ch(char id[]);
void modi_ch(char id[],reclamation o);
reclamation rechercher_reclamation(char id[]);
void affi_ch(GtkWidget* treeview1,char*l);
void affi_ad_ch(GtkWidget* treeview1,char*l);
 




/////////////////////////////////
void chang_background(GtkWidget *widget, int w, int h, const gchar *path);
