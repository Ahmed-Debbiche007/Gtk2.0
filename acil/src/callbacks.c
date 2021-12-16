#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fonction.h"
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include"support.h"

int x=2;
int y=0,t=0,y2=0,y3=0;;



void
on_radiobutton1_petit_dejuner_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
	x=1;

}


void
on_radiobutton2_dejeuner_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
	x=2;

}


void
on_radiobutton3_dinner_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	x=3;
}


void
on_checkbutton1_ajouter_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if( gtk_toggle_button_get_active( togglebutton))
y=1;

}

void
on_checkbutton1_supprimer_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
y2=1;
}

void
on_checkbutton2_modifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
y3=1;
}




//button ajouter

void
on_button1_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
nut n;
int x1,x2,x3,x4;
char texte2[50]="";
char texte4[50]="";
char texte3[50]="",texte5[50]="",texte6[50]="", texte7[50]="";
char repas[50];
char entree1[50];
char platprincipal1[50];
char dessert1[50];
char boisson1[50];

FILE *f=NULL;
GtkWidget* id;
GtkWidget* plat,*entree,*platprincipal,*dessert,*boisson;
GtkWidget* qt_e;
GtkWidget* qt_p;
GtkWidget* qt_d;
GtkWidget* qt_b;
GtkWidget* windownut;
GtkWidget* output,*output2,*output3,*output5,*output6,*output7;
GtkWidget*jour;//spinbuttun pour le choix du jour
GtkWidget*mois;//spinbuttun pour le choix du mois
GtkWidget*annee;//spinbuttun pour le choix du annee
GtkWidget*combobox1;



id=  lookup_widget(objet, "entry11");
plat=  lookup_widget(objet, "entry1_menu");
qt_e= lookup_widget(objet, "entry17_entree");
qt_p= lookup_widget(objet, "entry14_platprincipal");
qt_d= lookup_widget(objet, "entry16_dessert");
qt_b= lookup_widget(objet, "entry15_boisson");

strcpy(n.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(n.plats,gtk_entry_get_text(GTK_ENTRY(plat)));
strcpy(n.entree,gtk_entry_get_text(GTK_ENTRY(qt_e)));
strcpy(n.platprincipal,gtk_entry_get_text(GTK_ENTRY(qt_p)));
strcpy(n.boisson,gtk_entry_get_text(GTK_ENTRY(qt_b)));
strcpy(n.dessert,gtk_entry_get_text(GTK_ENTRY(qt_d)));

//associe les objet avec des variable
jour=lookup_widget(objet,"jour");
mois=lookup_widget(objet,"mois");
annee=lookup_widget(objet,"annee");


n.d.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
n.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
n.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

combobox1=lookup_widget(objet,"combobox1");
strcpy(n.menu,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

if (x==1)
	strcpy(n.repas,"petitdejeuner");
if (x==2)
	strcpy(n.repas,"dejeuner");
if (x==3)
	strcpy(n.repas,"dinner");



t=verif(n.id);

entree=  lookup_widget(objet, "entry17_entree");
strcpy(entree1,gtk_entry_get_text(GTK_ENTRY(entree)));


platprincipal=  lookup_widget(objet, "entry14_platprincipal");
strcpy(platprincipal1,gtk_entry_get_text(GTK_ENTRY(platprincipal)));


dessert=  lookup_widget(objet, "entry16_dessert");
strcpy(dessert1,gtk_entry_get_text(GTK_ENTRY(dessert)));



boisson=  lookup_widget(objet, "entry15_boisson");
strcpy(boisson1,gtk_entry_get_text(GTK_ENTRY(boisson)));




if((y==1)&&(t==0)&&(x1==0)&&(x2==0)&&(x3==0)&&(x4==0)){
sprintf(texte3,"ajout avec succes");
output=lookup_widget(objet, "label86_message");
gtk_label_set_text(GTK_LABEL(output),texte3);

ajouter( n);
}
/*sprintf(texte4,"");
output2=lookup_widget(objet, "controle_calorie");
gtk_label_set_text(GTK_LABEL(output2),texte4);

sprintf(texte5,"");
output5=lookup_widget(objet, "controle_proteine");
gtk_label_set_text(GTK_LABEL(output5),texte5);

sprintf(texte6,"");
output6=lookup_widget(objet, "controle_lipide");
gtk_label_set_text(GTK_LABEL(output6),texte6);

sprintf(texte7,"");
output7=lookup_widget(objet, "controle_glucide");
gtk_label_set_text(GTK_LABEL(output7),texte7);

sprintf(texte2,"");
output3=lookup_widget(objet, "label90");
gtk_label_set_text(GTK_LABEL(output3),texte2);




}
else
{
sprintf(texte3,"erreur d'ajout");
output=lookup_widget(objet, "label86_message");
gtk_label_set_text(GTK_LABEL(output),texte3);

}


if(x1==1)
{
sprintf(texte4,"calorie est un entier!");
output2=lookup_widget(objet, "controle_calorie");
gtk_label_set_text(GTK_LABEL(output2),texte4);
}

if(x2==1)
{
sprintf(texte5,"proteine est un entier!");
output5=lookup_widget(objet, "controle_proteine");
gtk_label_set_text(GTK_LABEL(output5),texte5);
}



if(x3==1)
{
sprintf(texte6,"lipide est un entier!");
output6=lookup_widget(objet, "controle_lipide");
gtk_label_set_text(GTK_LABEL(output6),texte6);
}

if(x4==1)
{
sprintf(texte7,"glucide est un entier!");
output7=lookup_widget(objet, "controle_glucide");
gtk_label_set_text(GTK_LABEL(output7),texte7);
}



if(t==1)
{
sprintf(texte2,"l'id existe déja!");
output3=lookup_widget(objet, "label90");
gtk_label_set_text(GTK_LABEL(output3),texte2);
}
*/


}
//button afficher
void
on_button4_recherche_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nutritionniste;
GtkWidget *treeview3;
treeview3=lookup_widget(button,"treeview3");
afficher_menu(treeview3);

}
//button supprimer
void
on_button3_supprimer_clicked           (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget* output;
char texte3[50]="";
nut n;
GtkTreeModel *model;
GtkTreeSelection *selection;
GtkTreeIter iter;
GtkWidget *p=lookup_widget(objet,"treeview3");
gchar *id;
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
if(gtk_tree_selection_get_selected(selection,&model,&iter)&&(y2==1))
{
gtk_tree_model_get(model,&iter,0,&id,-1);
gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
supprimer(id);
sprintf(texte3,"supprimé avec succée");
output=lookup_widget(objet, "label89_supprimer");
gtk_label_set_text(GTK_LABEL(output),texte3);
}
else
{
sprintf(texte3,"erreur de suppresion");
output=lookup_widget(objet, "label89_supprimer");
gtk_label_set_text(GTK_LABEL(output),texte3);
}

}






void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
nut n;
	GtkTreeIter iter;
	gchar* id;
	gchar*repas;
	gchar* menu;
	gchar* plats;
	gchar* platprincipal;
	gchar* dessert;
	gchar* boisson;
	gchar* entree;
	gchar *jour;
	gchar*mois;
	gchar *annee;
	char j[20];
	char m[20];
	char a[20];
	j=="n.jour";
	m=="n.mois";
	a=="n.annee";
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	//obtention de valeur de la ligne selectionne
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,id,1,repas,2,menu,3,plats,4,platprincipal,5,dessert,6,boisson,7,entree,8,jour,9,mois,10,annee);
	strcpy(n.id,id);
	strcpy(n.repas,repas);
	strcpy(n.menu,menu);
	strcpy(n.plats,plats);
	strcpy(n.platprincipal,platprincipal);
	strcpy(n.dessert,dessert);
	strcpy(n.boisson,boisson);
	strcpy(n.entree,entree);
	strcpy(j,jour);
	strcpy(m,mois);
	strcpy(a,annee);
	supprimer(id);
	//appelle a la fonction ajout
	afficher_menu(treeview);
	}

}
void
on_button5_actualiser_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *nutritionniste,*n1;
GtkWidget *treeview3;

n1=lookup_widget(objet,"nutritionniste");
nutritionniste=create_nutritionniste();

gtk_widget_show(nutritionniste);

gtk_widget_hide(n1);

treeview3=lookup_widget(nutritionniste,"treeview3");

afficher_menu(treeview3);



}

//modifier

void
on_button2_modifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
char texte3[50]="";
nut n;
GtkWidget* id2;
GtkWidget* plat;
GtkWidget* qt_e;
GtkWidget* qt_p;
GtkWidget* qt_d;
GtkWidget* qt_b;
GtkTreeModel *model;
GtkTreeSelection *selection;
GtkTreeIter iter;
GtkWidget *treeview3;
GtkWidget* output;
gchar *id;
char id1[20];
char idd[20];
char repas[20];
char menu[20];
char plats[20];
char  platrincipal[20];
char dessert[20];
char boisson[20];
char entree[20];
int jour,mois,annee;

treeview3=lookup_widget(objet,"treeview3");
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview3));
if(gtk_tree_selection_get_selected(selection,&model,&iter)&&(y3==1)) {
gtk_tree_model_get(model,&iter,0,&id,-1);
gtk_list_store_remove(GTK_LIST_STORE(model),&iter);

plat=  lookup_widget(objet, "entry1_plat");
qt_e= lookup_widget(objet, "entry2_entree");
qt_p= lookup_widget(objet, "entry3_platprincipal");
qt_d= lookup_widget(objet, "entry4_dessert");
qt_b= lookup_widget(objet, "entry5_boisson");

//strcpy(id2,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(n.plats,gtk_entry_get_text(GTK_ENTRY(plat)));
strcpy(n.entree,gtk_entry_get_text(GTK_ENTRY(qt_e)));
strcpy(n.platprincipal,gtk_entry_get_text(GTK_ENTRY(qt_p)));
strcpy(n.boisson,gtk_entry_get_text(GTK_ENTRY(qt_b)));
strcpy(n.dessert,gtk_entry_get_text(GTK_ENTRY(qt_d)));
modifier(id,n);
sprintf(texte3,"modification faite avec succée");
output=lookup_widget(objet, "label88_modification");
gtk_label_set_text(GTK_LABEL(output),texte3);

}
else
{
sprintf(texte3,"erreur de modification");
output=lookup_widget(objet, "label88_modification");
gtk_label_set_text(GTK_LABEL(output),texte3);
}


}








void
on_button4_chercher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *treeview2;
GtkWidget *repas;
char repas1[20];
nut n;
FILE *f;
repas=  lookup_widget(objet, "entry12");
strcpy(repas1,gtk_entry_get_text(GTK_ENTRY(repas)));
chercher(repas1,n);
treeview2=lookup_widget(objet,"treeview2");
afficher_repas(treeview2);

}



