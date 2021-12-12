


#include <gtk/gtk.h>

typedef struct{
char ref[50];
char name[50];
char type[50];
float quant;
char etat[50];
}product;


void addproduct(product p);
void deleteproduct(char name[] );
void updateproduct(product p1);
int searchproduct(char  name[]);
void historique();
void afficherone(char name[]);
void affichage(GtkWidget *liste);
void rupture();
void commander();
void vider(GtkWidget *liste);
void affichagehis(GtkWidget *liste);

void affichagerup(GtkWidget *liste);
void resetcommand(GtkWidget *liste);

