#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include <time.h>
#include "event.h"


void
on_affi_nb_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *capt;

  capt = create_captDeff ();
  gtk_widget_show(capt);
 
}



void
on_actu_nb_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview1");
	gchar *lieu;
        gchar *event;
        gchar *etat;
        gchar *date;
  	gchar *nb;
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&lieu,2,&event,3,&etat,4,&date,5,&nb,-1);
  
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry1")),id);

GtkWidget *dd,*lieu,*event,*ing,*date,*ty,*se,*da,*po;

	dd = lookup_widget (objet,"entry1");
	lieu = lookup_widget(objet,"label23");
	event = lookup_widget(objet,"label24");
	ing = lookup_widget(objet, "label25");
	date = lookup_widget(objet, "label26");

	ty = lookup_widget (objet,"entry2");
	se = lookup_widget (objet,"entry3");
	da = lookup_widget (objet,"combobox2");
	po = lookup_widget (objet,"entry5");

	strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
	eve A= rech_nb(id);

	gtk_label_set_text(GTK_LABEL(lieu),A.lieu);
	gtk_label_set_text(GTK_LABEL(event),A.event);
	gtk_label_set_text(GTK_LABEL(ing),A.ing);
	gtk_label_set_text(GTK_LABEL(date),A.date);

	gtk_entry_set_text(GTK_LABEL(ty),A.lieu);
	gtk_entry_set_text(GTK_LABEL(se),A.event);
	gtk_label_set_text(GTK_LABEL(da),A.ing);
	gtk_entry_set_text(GTK_LABEL(po),A.date);
			
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook1")));//redirection vers la page precedente
}

//mise a jour treeview
afficher_nb(p ,"event.txt");

}

void
on_rech_nb_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{


///////////////////////////////////////////

GtkWidget *dd,*lieu,*event,*ing,*date,*ty,*se,*da,*po,*lb;
char idd[20];

int x=-1;
char lieu1[20];
char event1[20];
char date1[20];
char nb1[20];
char id[20];
char ing1[20];

FILE *F;
dd = lookup_widget (button,"entry1");
lieu = lookup_widget(button, "label23");
event = lookup_widget(button, "label24");
ing = lookup_widget(button, "label25");
date = lookup_widget(button, "label26");
lb= lookup_widget(button, "label19");

ty = lookup_widget (button,"entry2");
se = lookup_widget (button,"entry3");
da = lookup_widget (button,"combobox2");
po = lookup_widget (button,"entry5");




strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("event.txt", "r");

/////////////////////////////////////////////
if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s \n",id,lieu1,event1,ing1,date1,nb1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
   gtk_label_set_text(GTK_LABEL(ty),"");
gtk_label_set_text(GTK_LABEL(se),"");
gtk_label_set_text(GTK_LABEL(dd),"");
gtk_entry_set_text(GTK_LABEL(po),"");
}else
{
    eve A= rech_nb(idd);
    gtk_label_set_text(GTK_LABEL(lb),"1 trouve");/* code */
gtk_label_set_text(GTK_LABEL(lieu),A.lieu);
gtk_label_set_text(GTK_LABEL(event),A.event);
gtk_label_set_text(GTK_LABEL(ing),A.ing);
gtk_label_set_text(GTK_LABEL(date),A.date);


gtk_entry_set_text(GTK_LABEL(ty),A.lieu);
gtk_entry_set_text(GTK_LABEL(se),A.event);
gtk_label_set_text(GTK_LABEL(da),A.ing);
gtk_entry_set_text(GTK_LABEL(po),A.date);
}



}


void
on_Modif_nb_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*ty,*se,*da,*po,*nb,*lb;
int v=-1;
char id[20];
char idd[20];
char lieu1[20];
char event1[20];
char ing1[20];
char date1[20];
char nb1[20];
eve U ;

dd = lookup_widget (objet_graphique,"entry1");
ty = lookup_widget (objet_graphique,"entry2");
se = lookup_widget (objet_graphique,"entry3");
da = lookup_widget (objet_graphique,"combobox2");
po = lookup_widget (objet_graphique,"entry5");
nb = lookup_widget (objet_graphique,"spinbutton35");
lb = lookup_widget (objet_graphique,"label19");

FILE *F;
//////////////////////////////////////////////////////////////////////////////////
F = fopen ("event.txt", "r");

/////////////////////////////////////////////
if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s  \n",id,lieu1,event1,ing1,date1,nb1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      v=1;
      } 
     } 
    
     fclose (F);
  }

    
    gtk_label_set_text(GTK_LABEL(lb),"1 trouve");/* code */

U.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
strcpy(U.lieu,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(U.event,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(U.ing,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(U.date,gtk_entry_get_text(GTK_ENTRY(po)));

modi_nb(id,U);

/////////////////////////////////////////////////////////////////////////////////




//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficher_nb(p ,"event.txt");
}


void
on_ajout_nb_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*se,*da,*po,*nb,*Ajouter,*labeldate,*labelmain,*labelty;
Ajouter=lookup_widget(objet_graphique,"Ajouter");
eve A ;
char id[30];
int i, longueurChaine = 0;
char chaine[] = "1a2z3e4r5t6y7u8i9opqsdfghjklmwxcvbn";
int b=1;

ty = lookup_widget (objet_graphique,"entry6");
se = lookup_widget (objet_graphique,"entry7");
da = lookup_widget (objet_graphique,"combobox3");
po = lookup_widget (objet_graphique,"entry9");
nb = lookup_widget (objet_graphique,"spinbutton33");


A.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));


strcpy(A.lieu,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(A.event,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(A.ing,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(A.date,gtk_entry_get_text(GTK_ENTRY(po)));

labelty=lookup_widget(objet_graphique,"label263");
labelmain=lookup_widget(objet_graphique,"label264");
labeldate=lookup_widget(objet_graphique,"label265");

    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }

 strcpy(A.id,id);

// controle saisie
if(strcmp(A.lieu,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelty),"saisir Chef !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelty),"");
}

if(strcmp(A.event,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"saisir Ingrédient !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"");
}


if(strcmp(A.date,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir date !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"");
}


if(b==1){

ajouter_nb(A);
}
//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficher_nb(p ,"event.txt");
}

void
on_supp_nb_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int x=-1;
char lieu[20];
char event[20];
char date[20];
char ing[20];
char id[20];
char nb [20];

lb = lookup_widget (objet_graphique,"label19");
dd = lookup_widget (objet_graphique,"entry1");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("event.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s \n",id,lieu,event,ing,date,nb) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_nb(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");/* code */
}


//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficher_nb(p ,"event.txt");
}




void
on_supp_tree_nb_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview1");;

        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_nb( id);// supprimer la ligne du fichier
}
}



int x;
int t[2]={0,0};

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton)) 

   {t[1]=1;}    
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) 
  {t[0]=1;}   
}


void
on_ok_nb_clicked                       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
char ch1[200]=" travaille en ";
char ch2[200]=" ";
char ch3[200]=" ";
if (x==1) 
strcpy(ch2," Mode jour ");
 else  
strcpy(ch2," Mode nuit ");
 if (t[0]==1)
 strcat(ch3," Groupe B "); 
if(t[1]==1)
 strcat (ch3,"  Groupe A");
strcat(ch3,ch1);
strcat(ch3,ch2);
output = lookup_widget(button, "label234");

gtk_label_set_text(GTK_LABEL(output),ch3);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;} 
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;} 
}








void
on_Facebook_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.facebook.com/");
}


void
on_youtube_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.youtube.com/");
}


void
on_Instagram_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.instagram.com/");
}




void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *message;

char jour[20];
char heure [20];
char type [20];
int temp;
int nb1=0;
int nb2=0;
int nb3=0;
int max,x,y;
      
  FILE* F;

F=fopen("temperature.txt","r");
if(F!=NULL)
{
    
    while(fscanf(F,"%s %s %s %d\n",jour,heure,type,&temp)!=EOF)
    {
        if((strcmp(type,"1")==0))
		if(temp<10 || temp>30){
        nb3++;
                     } 
        if((strcmp(type,"2")==0))
		if(temp<10 || temp>30){
        nb1++;
                     }                        
 if(strcmp(type,"3")==0)
{
		if(temp<10 || temp>30){
        nb2++;
                     }
 }

if(nb1>nb2)
x=nb1;
else
{
    x=nb2;
}

y=nb3;

if(x>y)
max=x;
else
{
    max=y;
}

if(max==nb1){
    strcpy(type,"capture 2");
}
if(max==nb2){
    strcpy(type,"capture 3");
}
if(max==nb3){
    strcpy(type,"capture 1");
}


////******************

}

fclose(F);
message = lookup_widget(button, "labelCapt");
gtk_label_set_text(GTK_LABEL(message),type);



}
}

