#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include <string.h>
#include <time.h>





void
on_button2_login_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *lb,*username,*password,*authen,*window1,*window2,*window3,*window4,*window5,*window6,*Admin;


char user[20];
char pasw[20];
int trouve=0;
int x=-1;


lb = lookup_widget (button,"label314");
username = lookup_widget (button,"us");
password = lookup_widget (button,"Pw");
strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw,gtk_entry_get_text(GTK_ENTRY(password)));
FILE *f=NULL;
util t;
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
 while(fscanf(f,"%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Num,t.Cin)!=EOF)
{
if((strcmp(t.User,user)==0)&&(strcmp(t.Pass,pasw)==0))
{
x=1;
}

}
if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"compte n'existe pas ");
}else
{
   trouve=verif(user,pasw); 
    
}



fclose(f);
}



authen=lookup_widget(button,"auth");


if(trouve==1)
{
    

gtk_widget_destroy(authen);
window1=create_window1();
gtk_widget_show(window1);  
} 
if(trouve==2)
{
window2=create_window2();

   

gtk_widget_destroy(authen);
gtk_widget_show(window2);
 
}
if(trouve==3)
{

gtk_widget_destroy(authen);
window3=create_window3();

gtk_widget_show(window3);  
}
if(trouve==4)
{

gtk_widget_destroy(authen);
Admin=create_Admin();
gtk_widget_show(Admin);  
}
if(trouve==5)
{

gtk_widget_destroy(authen);
window5=create_window5();
gtk_widget_show(window5);
 
}

if(trouve==6)
{
GtkWidget* Gestion_window6;

gtk_widget_destroy(authen);
Gestion_window6 = create_window6 ();
gtk_widget_show (Gestion_window6); 
}



}


void
on_ajoutyo_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ath,*fenetre_insc,*success;
success=lookup_widget(objet,"label261");
fenetre_ath=lookup_widget(objet,"auth");
gtk_widget_destroy(fenetre_ath);
fenetre_insc=create_inscription();
gtk_widget_show(fenetre_insc);
gtk_widget_hide(success);
}


void
on_button1_ajoutyo_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ath,*fenetre_insc;
GtkWidget *use,*nom,*prenom,*pass,*choix,*num,*cin;
GtkWidget *labelCin,*labelnom,*labelprenom,*labelpass,*labeluser,*labeltel,*success;
int b=1;

labelCin=lookup_widget(objet,"label260");
labelnom=lookup_widget(objet,"label255");
labelprenom=lookup_widget(objet,"label256");
labelpass=lookup_widget(objet,"label258");
labeluser=lookup_widget(objet,"label257");
labeltel=lookup_widget(objet,"label259");




util t;


nom = lookup_widget (objet,"nom");
prenom = lookup_widget (objet,"prenom");
use = lookup_widget (objet,"user");
pass = lookup_widget (objet,"Pass");
choix = lookup_widget (objet,"combobox33");
num = lookup_widget (objet,"num");
cin = lookup_widget (objet,"cin");



strcpy(t.Nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(t.Prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(t.User,gtk_entry_get_text(GTK_ENTRY(use)));
strcpy(t.Pass,gtk_entry_get_text(GTK_ENTRY(pass)));
strcpy(t.Num,gtk_entry_get_text(GTK_ENTRY(num)));
strcpy(t.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(t.Choix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix)));




 



// controle saisie
if(strcmp(t.Cin,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelCin),"saisir cin !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelCin),"");
}

if(strcmp(t.Nom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"saisir nom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"");
}
if(strcmp(t.Prenom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"saisir prenom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"");
}

if(strcmp(t.Num,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labeltel),"saisir Num tel !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeltel),"");
}

if(strcmp(t.User,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labeluser),"saisir username !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeluser),"");
}


if(strcmp(t.Pass,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelpass),"saisir password !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelpass),"");
}



if(b==1){
        
ajouter(t);


fenetre_insc=lookup_widget(objet,"inscription");
gtk_widget_destroy(fenetre_insc);
fenetre_ath=create_auth();
gtk_widget_show(fenetre_ath);

        }

}


void
on_quit_ad_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_auth,*fenetre_admin;

fenetre_admin=lookup_widget(button,"Admin");
gtk_widget_destroy(fenetre_admin);
fenetre_auth=create_auth();
gtk_widget_show(fenetre_auth);
}

void
on_auth_youtube_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.youtube.com/");
}


void
on_auth_facebook_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.facebook.com/");
}


void
on_auth_instagram_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.instagram.com/");
}


void
on_treeviewAffiListUser_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonAffiUser_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

 GtkWidget* p=lookup_widget(objet,"treeviewAffiListUser");
 affi_listUser(p,"utilisateur.txt");
}


void
on_buttonSupprimeryo_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeviewAffiListUser");
        
        gchar *Nom;
	gchar *Prenom;
	gchar *User;
	gchar *Pass;
	gchar *Choix;
	gchar *Num;
	gchar *Cin;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&Nom,1,&Prenom,2,&User,3,&Pass,4,&Choix,5,&Num,6,&Cin,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_tree(Cin);// supprimer la ligne du fichier
}

}


void
on_buttonValideryo_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *no,*pr,*ci,*us,*pass,*Role,*dd,*cin;
util o;
char Cin[20];



dd = lookup_widget (objet_graphique,"entry6");
no = lookup_widget (objet_graphique,"entry1");
pr = lookup_widget (objet_graphique,"entry2");
Role = lookup_widget (objet_graphique,"combobox34");
cin = lookup_widget (objet_graphique,"entry5");
us = lookup_widget (objet_graphique,"entry3");
pass = lookup_widget (objet_graphique,"entry4");



strcpy(o.Num,gtk_entry_get_text(GTK_ENTRY(dd)));//
strcpy(o.Nom,gtk_entry_get_text(GTK_ENTRY(no)));//
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(pr)));//
strcpy(o.Choix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Role)));//
strcpy(Cin,gtk_entry_get_text(GTK_ENTRY(cin)));//
strcpy(o.User,gtk_entry_get_text(GTK_ENTRY(us)));//
strcpy(o.Pass,gtk_entry_get_text(GTK_ENTRY(pass)));//
modi_tree(Cin,o);//

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeviewAffiListUser");
affi_listUser(p,"utilisateur.txt");
}


void
on_buttonModifieryo_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{ 

GtkTreeModel     *model,*labe;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
         GtkWidget* p=lookup_widget(objet_graphique,"treeviewAffiListUser");
        gchar *Nom;
	gchar *Prenom;
	gchar *User;
	gchar *Pass;
	gchar *Choix;
	gchar *Num;
	gchar *Cin;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&Nom,1,&Prenom,2,&User,3,&Pass,4,&Choix,5,&Num,6,&Cin,-1);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry1")),Nom);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry2")),Prenom);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry3")),User);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry4")),Pass);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry5")),Cin);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry6")),Num);







         
}
//mise a jour treeview


affi_listUser(p,"utilisateur.txt");
}



void
on_button_calculEtudiant_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*nb;


char niveau[20];

ty = lookup_widget (objet_graphique,"entry7");
nb = lookup_widget(objet_graphique, "spinbutton1");

strcpy(niveau,gtk_entry_get_text(GTK_ENTRY(ty)));
 FILE* F;

niveaux n;
int nb1=0;


F=fopen("niveaux.txt","r");
if(F!=NULL)
{
    
    while(fscanf(F, "%s %s %s %s %s\n",n.id,n.niveau,n.vaccin,n.sexe,n.abonement)==5)
    {
      if(strcmp(n.niveau,niveau)==0)
      nb1++;
    }
fclose(F); 
}

gtk_spin_button_set_value(GTK_SPIN_BUTTON(nb),nb1);





}


void
on_buttonActualiseryo_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficherListEtudiant( p);
}


void
on_buttonEspaceAjouter_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouterEtudiant;
ajouterEtudiant = create_ajouterEtudiant ();
gtk_widget_show (ajouterEtudiant);
}

int x=0;
int t[2]={0,0};

void
on_radiobuttonFemelle_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=2;} 
else
x=0;
}


void
on_radiobuttonMale_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;} 
else
x=0;
}


void
on_checkbuttonFoyer_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton)) 

   {t[0]=1;} 
else 
{t[0]=0;} 

}


void
on_checkbuttonRestau_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton)) 

   {t[1]=1;} 
else 
{t[1]=0;}
}


void
on_buttonAjouterEtudiant_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *id,*niveau,*vaccin;

niveaux A ;


if (x==1) 
strcpy(A.sexe,"Male");
if(x==2)
strcpy(A.sexe,"Femelle");
if(x==0)
strcpy(A.sexe,"");

 if (t[0]==1)
 strcat(A.abonement,"Foyer"); 
if(t[1]==1)
 strcat (A.abonement,"Restau");
if(t[1]==0)
 strcpy (A.abonement,"");
if(t[0]==0)
 strcpy (A.abonement,"");






id = lookup_widget (objet,"entry8");
niveau = lookup_widget (objet,"entry12");
vaccin = lookup_widget (objet,"entry10");


strcpy(A.niveau,gtk_entry_get_text(GTK_ENTRY(niveau)));
strcpy(A.vaccin,gtk_entry_get_text(GTK_ENTRY(vaccin)));
strcpy(A.id,gtk_entry_get_text(GTK_ENTRY(id)));


ajouterE(A);
GtkWidget* p=lookup_widget(objet,"treeview1");
afficherListEtudiant( p);

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonRestau_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *etudiant;
etudiant = create_etudiant ();
gtk_widget_show (etudiant);
}








void
on_button7_chercheryosra_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *recherche, *admin;


admin=lookup_widget(objet,"admin");

//gtk_widget_destroy(admin);
recherche=lookup_widget(objet,"recherchee");
recherche=create_recherchee();

gtk_widget_show(recherche);

}


void
on_button8_chercher_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
util u;
int test=-1;
GtkWidget *r0, *r1, *r2, *r3, *r4, *r5 , *pInfo;
char Prenom[20], Nom[20], User[20],Choix[20], Num[20],id[20] ;
r0=lookup_widget(objet,"entry13");
r1=lookup_widget(objet,"label347_prenom");
r2=lookup_widget(objet,"label344_nom");
r3=lookup_widget(objet,"label345_username");
r4=lookup_widget(objet,"label346_role");
r5=lookup_widget(objet,"label343_tel");


strcpy(id ,(gtk_entry_get_text(GTK_ENTRY(r0))));
 u=chercher_util(id);
if (strcmp(u.Cin,id)==0){
test=1;
}
if(test=1){
gtk_label_set_text(GTK_LABEL(r1),u.Prenom);
gtk_label_set_text(GTK_LABEL(r2),u.Nom);
gtk_label_set_text(GTK_LABEL(r3),u.User);


sprintf(Num,"%s",u.Num);
gtk_label_set_text(GTK_LABEL(r5),Num);
gtk_label_set_text(GTK_LABEL(r4),u.Choix);

}
else{
gtk_label_set_text(GTK_LABEL(r1),"l'id n'existe pas");
gtk_label_set_text(GTK_LABEL(r2),"l'id n'existe pas");
gtk_label_set_text(GTK_LABEL(r3),"l'id n'existe pas");


sprintf(Num,"%s",u.Num);
gtk_label_set_text(GTK_LABEL(r4),"l'id n'existe pas");
gtk_label_set_text(GTK_LABEL(r5),"l'id n'existe pas");
}

}









