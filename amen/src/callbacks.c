#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include <string.h>
#include <stdio.h>

int radio=1;
int r=0;

void
on_gotoajoutercapt_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Ajouter_un_capteur();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_gotomodifiercapteur_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_modifier_un_capteur();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_afftouver_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload();
  int i;
  char sid[30];
  GtkWidget *liste, *id;
  id=lookup_widget(button,"gettrouver");
  liste=lookup_widget(button,"liste");
  strcpy(sid, gtk_entry_get_text(GTK_ENTRY(id)));

  i=isid(sid);
  if(i!=-1){
    viderliste(liste);
    afftrouver(liste, i);
  }
  else{
    viderliste(liste);
  }
}


void
on_affsupprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
char x[100];
fileload();


GtkWidget * id, * inc, * inc2, *conf;

id = lookup_widget(button,"affsupprimercapt");
inc = lookup_widget(button,"affsupperror");
inc2 = lookup_widget(button,"label59");

strcpy(x, gtk_entry_get_text(GTK_ENTRY(id)));



if(isid(x)!=-1 && r==1){
supprimer(x);
filesave();
gtk_label_set_text(GTK_LABEL(inc), "succes.");
r=0;
}
if(isid(x)==-1 && r==1){
gtk_label_set_text(GTK_LABEL(inc), "capteur inexistant.");
r=0;
}
if (r==0);
{
gtk_label_set_text(GTK_LABEL(inc2), "confirmé la suppression");
r=1;
}
}



void
on_ajoutervalider_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
capteur x;
fileload();


GtkWidget * id, * type, * position, * etat, * valeur, * inc;


id = lookup_widget(button,"ajouterid");
type = lookup_widget(button,"ajoutertype");
position = lookup_widget(button,"ajouterposition");
etat = lookup_widget(button,"ajouteretat");
valeur=lookup_widget(button,"spinbutton1");
inc = lookup_widget(button,"ajoutererror");

  char a[20];
  sprintf(a, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(valeur)));

strcpy(x.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(x.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(x.position, gtk_entry_get_text(GTK_ENTRY(position)));
strcpy(x.etat, gtk_entry_get_text(GTK_ENTRY(etat)));
strcpy(x.valeur, a);



if((isid(x.id)==-1)&&(isint(x.id)==1)&&(nospace(x.id)==1)&&(isalphabet(x.type)==1)&&(isalphabet(x.position)==1)&&(isint(x.etat)==1)&&(isint(x.valeur)==1)){
ajout(x);
filesave();
gtk_label_set_text(GTK_LABEL(inc), "Ajoute avec succes");
}
else{
gtk_label_set_text(GTK_LABEL(inc), "Vérifie vos données");
}
}
//Verifier vos données.

void
on_modifvalider_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
capteur x;
fileload();


GtkWidget * id, * type, * position, * etat, * valeur, * inc;
  

id = lookup_widget(button,"modifid");
type = lookup_widget(button,"modiftype");
position = lookup_widget(button,"modifposition");
etat = lookup_widget(button,"modifetat");
inc = lookup_widget(button,"affmodifiererror");
valeur=lookup_widget(button,"spinbutton2");

  char a[20];
  sprintf(a, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(valeur)));


strcpy(x.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(x.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(x.position, gtk_entry_get_text(GTK_ENTRY(position)));
strcpy(x.etat, gtk_entry_get_text(GTK_ENTRY(etat)));
strcpy(x.valeur, a);





if((isid(x.id)!=-1)&&(isint(x.id)==1)&&(nospace(x.id)==1)&&(isalphabet(x.type)==1)&&(isalphabet(x.position)==1)&&(isint(x.etat)==1)&&(isint(x.valeur)==1)){
modifier(x);
filesave();
gtk_label_set_text(GTK_LABEL(inc), "Modification affectuer avec succes");
}
else{
gtk_label_set_text(GTK_LABEL(inc), "Veuillez vérifier votre ID");
}
}


void
on_liste_row_activated                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_afficher_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
fileload();
GtkWidget *liste;
liste=lookup_widget(button,"liste");
afficher(liste);
}


void
on_gotoalarme_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_afficher_alarme();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_afficheralarme_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *afflist;
  GtkTextView *aff;
 
  aff=lookup_widget(button,"textview1");

    capteurx S[5000];
	char temp[1000],msg[10000];
    int n=0,i;
    FILE *f=NULL;
    f=fopen("fumee.txt","r");
    if(f==NULL){printf("error reading file");}
    while(fscanf(f,"%d %d %d %d\n",&S[n].jour,&S[n].heure,&S[n].idx,&S[n].val)!=EOF){
        n++;
    }
    fclose(f);
	strcpy(msg,"");
    for(i=0;i<n;i++)
    {
        if(S[i].val==1)
        {

        sprintf(temp,"le capteur de fumee avec ID: %d a detectee fumee. a heure %d , jour %d\n",S[i].idx,S[i].heure,S[i].jour);
	strcat(msg,temp);
        }
    }
    
    capteurx M[5000];
    n=0;
    FILE *fi=NULL;
    fi=fopen("mouvement.txt","r");
    if(fi==NULL){printf("error reading file");}
    while(fscanf(fi,"%d %d %d %d\n",&M[n].jour,&M[n].heure,&M[n].idx,&M[n].val)!=EOF){
        n++;
    }
    fclose(fi);
    for(i=0;i<n;i++)
    {
        if(M[i].val==1)
        {

                sprintf(temp,"le capteur de mouvement avec ID: %d a detectee movement. a heure %d , jour %d\n",M[i].idx,M[i].heure,M[i].jour);
		strcat(msg,temp);
        }
    }
 GtkTextBuffer *buff;

buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(aff));
gtk_text_buffer_set_text(buff,msg,-1);
}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *a,*togglebutton1,*togglebutton2;
if(radio==2)
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (togglebutton2),TRUE);
a= lookup_widget(button,"confirmation");
gtk_widget_destroy(a);
radio=1;}
else
{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebutton1),TRUE);
exit(1);
radio=2;}
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radio=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radio=2;
}





void
on_buttonsortie_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_confirmation ();
  gtk_widget_show(x);
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
r=1;
else
r=0;
}


void
on_buttonacc1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"Ajouter_un_capteur");
  gtk_widget_destroy(a);
}


void
on_buttonacc2_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"modifier_un_capteur");
  gtk_widget_destroy(a);
}


void
on_buttonacc3_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"afficher_alarme");
  gtk_widget_destroy(a);
}




