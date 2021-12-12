#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
GtkTreeSelection *selection1;
GtkWidget *gestion ,*fenetre_Modifier;
capteur e;
int x=0 ,y=0;
void
on_buttonOk_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
capteur c;

GtkWidget *entryNom, *entryMarque, *entryReference, *entryType ,*min  ,*max;
GtkWidget *fenetre_ajouter;
fenetre_ajouter=lookup_widget(objet_graphique,"fenetre_Ajouter");


entryNom=lookup_widget(objet_graphique,"entryNom");
entryMarque=lookup_widget(objet_graphique,"entryMarque");
entryReference=lookup_widget(objet_graphique,"entryReference");
min=lookup_widget(objet_graphique,"spinbuttonmin");
max=lookup_widget(objet_graphique,"spinbuttonmax");


 strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entryNom) ) );
 strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(entryMarque) ) );
 strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(entryReference) ) );
 if (x==1){
strcpy(c.type,"temperature");}
else 
if (x==2){
strcpy(c.type,"humidite");}
 c.min = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
 c.max = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(max));


ajouter_capteur(c);
GtkWidget *gestion;
gestion = create_gestion_capteur ();
  gtk_widget_show (gestion);
gtk_widget_destroy(fenetre_ajouter);
}


void
on_buttonAnnuler_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *gestion;
gestion = create_gestion_capteur ();
  gtk_widget_show (gestion);
GtkWidget *ajouter;
ajouter=lookup_widget(button,"fenetre_ajouter");
gtk_widget_destroy(ajouter);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{	
        gchar *reference;
        gchar *nom;
        gchar *type;
        gchar *marque;
        gint  *min;
	gint  *max;
	capteur c;
      
       GtkTreeIter iter;
	
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &nom, 1, &marque,2,&reference,3,&type,4,&min,5,&max,-1);
	strcpy(e.reference,reference);
	strcpy(e.nom,nom);
	strcpy(e.marque,marque);  
	
	}

}


void
on_buttonAfficher_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
capteur c;
GtkWidget *afficher;

  afficher=lookup_widget(objet_graphique,"gestion_capteur");
afficher_capteur(lookup_widget(afficher,"treeview1"),"fichier.txt");
}


void
on_buttonModifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *capteur;
capteur=lookup_widget(button,"gestion_capteur");
gtk_widget_destroy(capteur);
GtkWidget *modifier;

modifier = create_fenetre_Modifier ();

  gtk_widget_show (modifier);
GtkWidget* msgRef=lookup_widget(modifier,"label34");
gtk_label_set_text(GTK_LABEL(msgRef),e.reference);
                gtk_widget_show(msgRef);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"entryNom1")),e.nom);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"entryMarque1")),e.marque);
if (strcmp(e.type,"temperature")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (lookup_widget(modifier,"radiobutton3")),TRUE);
}
else if (strcmp(e.type,"humidite")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (lookup_widget(modifier,"radiobutton4")),TRUE);
}

}


void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *capteur;
capteur=lookup_widget(button,"gestion_capteur");
gtk_widget_destroy(capteur);
GtkWidget *ajouter;
ajouter = create_fenetre_Ajouter ();
  gtk_widget_show (ajouter);
}


void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
 char r[30];


strcpy(r,e.reference);
	supprimer_capteur(r);
GtkWidget *confirmesupprimer;
confirmesupprimer=lookup_widget(button,"gestion_capteur");

afficher_capteur(lookup_widget(button,"treeview1"),"fichier.txt");
}




void
on_button_alarmentes_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *accueil;
accueil=lookup_widget(button,"gestion_capteur");
gtk_widget_destroy(accueil);
GtkWidget *alarmente;
alarmente = create_fenetre_Alarmente ();
  gtk_widget_show (alarmente);
}


void
on_button_accueil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *waccueil;
waccueil=lookup_widget(button,"fenetre_Accueil");
gtk_widget_destroy(waccueil);
GtkWidget *capteur;
capteur = create_gestion_capteur ();
  gtk_widget_show (capteur);
}


void
on_buttonAnnuler1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier;
modifier=lookup_widget(button,"fenetre_Modifier");
gtk_widget_destroy(modifier);
GtkWidget *gestion;
gestion = create_gestion_capteur ();
  gtk_widget_show (gestion);
}


void
on_button_retour2_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *alarmente;
alarmente=lookup_widget(button,"fenetre_Alarmente");
gtk_widget_destroy(alarmente);
GtkWidget *wacceuil;
wacceuil = create_gestion_capteur();
  gtk_widget_show (wacceuil);
}


void
on_button_Retour_gestion_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestion_capteur;
GtkWidget *wacceuil;
gestion_capteur = lookup_widget(button,"gestion_capteur");
 gtk_widget_destroy (gestion_capteur);


wacceuil = create_fenetre_Accueil ();
  gtk_widget_show (wacceuil);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}




void
on_buttonRechercher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelreference;
GtkWidget *nbResultat;
GtkWidget *message;
char reference[30];
char chnb[30];
int flag=0,nb;  
entry=lookup_widget(objet,"entry10");
labelreference=lookup_widget(objet,"label28");
p1=lookup_widget(objet,"treeview1");
strcpy(reference,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(reference,"")==0){
  gtk_widget_show (labelreference);flag=0;
}else{
flag=1;
gtk_widget_hide (labelreference);}

if(flag==0)
    {return;
    }
    else
    {

nb=Cherchercapteur(p1,"fichier.txt",reference);
// afficher le nombre de resultats obtenue par la recherche */

sprintf(chnb,"%d",nb);        //conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine




}
}


void
on_buttonOk1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

      capteur c;

GtkWidget *entryNom, *entryMarque, *entryReference, *entryType ,*min ,*max;



entryNom=lookup_widget(button,"entryNom1");
entryMarque=lookup_widget(button,"entryMarque1");
//entryReference=lookup_widget(objet_graphique,"entryReference");
min=lookup_widget(button,"spinbuttonmin1");
max=lookup_widget(button,"spinbuttonmax1");

strcpy(c.reference,e.reference);
 strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entryNom) ) );
 strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(entryMarque) ) );
 //strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(entryReference) ) );
 if (y==1){
strcpy(c.type,"temperature");}
else 
if (y==2){
strcpy(c.type,"humidite");}
 c.min = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
 c.max = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(max));


     modifier_capteur(c);

GtkWidget *capteur;
GtkWidget *modifier;
modifier=lookup_widget(button,"fenetre_Modifier");
gtk_widget_destroy(modifier);

capteur = create_gestion_capteur ();
  gtk_widget_show (capteur);
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}


}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;}


}


void
on_buttonalarmente_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
int nb;
char chnb[30];
GtkWidget *nbResultat,*message,*window1=lookup_widget(GTK_WIDGET(button),"fenetre_Alarmente");
GtkWidget *p1=lookup_widget(window1,"treeview2");
nb=chercher_c(p1,"temperature.txt");
sprintf(chnb,"%d",nb);//conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
//nbResultat=lookup_widget(window1,"entry82");
//message=lookup_widget(window1,"label316");
//gtk_entry_set_text(GTK_ENTRY(nbResultat),chnb);
//gtk_widget_show (message);
//gtk_widget_show (nbResultat);
}

