#include <gtk/gtk.h>
typedef struct {
    char Nom[20];
char Prenom[20];
char User[20];
char Pass[20];
char Choix[20];
char Num[20];
char Cin[20];
}util;

typedef struct {
char id[20];
char niveau[20];
char vaccin[20];
char sexe[20];
char  abonement[20];
}niveaux;

int verif(char log[], char Pw[]);
void ajouter(util t);
void affi_listUser(GtkWidget* treeviewAffiListUser,char*l);
void supp_tree(char Cin[]);
void modi_tree(char Cin[],util o);

void ajouterE(niveaux A);
void afficherListEtudiant (GtkWidget *liste );

util chercher_util(char id []);












