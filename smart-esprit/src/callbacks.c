#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "reclamation.h"
#include "hebergement.h"
#include"fonctin.h"
#include "event.h"
#include "fnction.h"
#include <string.h>
#include <time.h>





void
on_button2_login_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *lb,*username,*password,*authen,*tech,*foyer,*resto,*window4,*reclam,*event,*Admin;


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
tech=create_Espace_technicien ();
gtk_widget_show(tech);  
} 
if(trouve==2)
{
foyer=create_foyer();

   

gtk_widget_destroy(authen);
gtk_widget_show(foyer);
 
}
if(trouve==3)
{

gtk_widget_destroy(authen);
resto=create_resto();

gtk_widget_show(resto);  
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
reclam=create_reclam();
gtk_widget_show(reclam);
 
}

if(trouve==6)
{


gtk_widget_destroy(authen);
event = create_event ();
gtk_widget_show (event); 
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

//Ahmed 
int xg;
int tg[4]={0,0,0,0};
int xgg;
int tgg[4]={0,0,0,0};
int xy[]={0,0,0,0},sy;




void
on_button16_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget*No,*Pr,*Ac,*ci,*Nt,*windowsup,*se,*jour,*mois,*annee,*labelnom,*labelprenom,*labelresp,*labelcin,*labelnt;
reclamation o ; 


int i=0, longueurChaine = 0;
char chaine[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int b=1;
No = lookup_widget (button,"entry14");
Pr = lookup_widget (button,"entry15");
ci = lookup_widget (button,"entry16");
Nt = lookup_widget (button,"entry17");
jour = lookup_widget (button,"spinbutton2");
mois = lookup_widget (button,"spinbutton3");
annee = lookup_widget (button,"spinbutton4");
se = lookup_widget (button,"combobox35");




strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(No)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(Pr)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.messageRecla,gtk_entry_get_text(GTK_ENTRY(Nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.resp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(o.sui,"en-cours");



 
    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            o.id[i] = chaine[rand()%longueurChaine];
        }
labelnom=lookup_widget(button,"label360");
labelprenom=lookup_widget(button,"label358");
labelresp=lookup_widget(button,"label361");
labelcin=lookup_widget(button,"label364");
labelnt=lookup_widget(button,"label352");



// controle saisie
if(strcmp(o.NOM,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelnom),"saisir NOM !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"");
}

if(strcmp(o.Prenom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"saisir prénom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"");
}


if(strcmp(o.resp,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelresp),"saisir Service !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelresp),"");
}

if(strcmp(o.CIN,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"saisir CIN !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"");
}

if(strcmp(o.messageRecla,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"saisir votre réclamation !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"");
}




if(b==1){
Ajouter_ch( o);
}

//mise a jour treeview
 GtkWidget* p=lookup_widget(button,"treeview2");
affi_ch(p,"reclamation.txt");

gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button,"notebook1")));

}


void
on_button19_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{


GtkButton *dd,*lb;

char idd[20];
FILE *F;
int x=-1;
char NOM[20];
char resp[20];
char Prenom[20];
char CIN[20];
char id[20];
char jour[20];
char mois[20];
char annee[20];
char messageRecla[20];
char sui[20];
lb = lookup_widget (button,"label387");
dd = lookup_widget (button,"entry23");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("reclamation.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s \n",id,NOM,Prenom,CIN,resp,messageRecla,jour,mois,annee,sui) != EOF)
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
    supp_ch(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");/* code */
}

//mise a jour treeview
 GtkButton* p=lookup_widget(button,"treeview2");
affi_ch(p,"reclamation.txt");
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button,"notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button,"notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button,"notebook1")));
}


void
on_button17_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{


GtkButton *dd,*Nm,*Pnom,*cin,*resp1,*Jour,*Mois,*mes,*Annee,*lb;
GtkCalendar *ca;
guint d,m,y;
char id[20];
char NOM[20];
char Prenom[20];
char resp[20];
char CIN[20];
char messageRecla[20];
char jour[20];
char mois[20];
char annee[20];
char sui[20];
char idd[20];
reclamation o ;
int x=-1;
FILE *F;

dd = lookup_widget (button,"entry18");
Nm = lookup_widget(button, "entry19");
Pnom = lookup_widget(button, "entry20");
resp1 = lookup_widget(button, "combobox36");
cin = lookup_widget (button,"entry21");
mes = lookup_widget(button, "entry22");
lb = lookup_widget(button, "label383");
ca=lookup_widget (button,"calendar1");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("reclamation.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s\n",id,NOM,Prenom,CIN,resp,messageRecla,jour,mois,annee,sui) != EOF)
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
gtk_entry_set_text(GTK_LABEL(Nm),"");
gtk_entry_set_text(GTK_LABEL(Pnom),"");
gtk_label_set_text(GTK_LABEL(resp1),"");
gtk_entry_set_text(GTK_LABEL(cin),"");
gtk_entry_set_text(GTK_LABEL(mes),"");
}else
{
    reclamation o = rechercher_reclamation(idd);
    gtk_label_set_text(GTK_LABEL(lb),"avec succées");


gtk_entry_set_text(GTK_LABEL(Nm),o.NOM);
gtk_entry_set_text(GTK_LABEL(Pnom),o.Prenom);
gtk_label_set_text(GTK_LABEL(resp1),o.resp);
gtk_entry_set_text(GTK_LABEL(cin),o.CIN);
gtk_entry_set_text(GTK_LABEL(mes),o.messageRecla);
d=o.dt_ns.jour;
m=o.dt_ns.mois;
y=o.dt_ns.annee;
m=m-1;
gtk_calendar_select_month(GTK_CALENDAR(ca),m,y);
gtk_calendar_select_day(GTK_CALENDAR(ca),d);


}

}


void
on_button18_clicked                     (GtkButton       *button_graphique,
                                        gpointer         user_data)
{
GtkWidget *no,*pr,*ci,*nt,*se,*jour,*mois,*annee,*dd;
GtkCalendar *ca;
reclamation o;
char id[20];
guint d,m,y;


dd = lookup_widget (button_graphique,"entry18");
no = lookup_widget (button_graphique,"entry19");
pr = lookup_widget (button_graphique,"entry20");
se = lookup_widget (button_graphique,"combobox36");
ci = lookup_widget (button_graphique,"entry21");
nt = lookup_widget (button_graphique,"entry22");
ca = lookup_widget (button_graphique,"calendar1");

gtk_calendar_get_date(GTK_CALENDAR(ca),&y,&m,&d);
m=m+1;

strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));

strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(no)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(pr)));
strcpy(o.resp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.messageRecla,gtk_entry_get_text(GTK_ENTRY(nt)));
o.dt_ns.jour=d;
o.dt_ns.mois=m;
o.dt_ns.annee=y;
strcpy(o.sui,"en-cours");
modi_ch(id,o);

//mise a jour treeview
 GtkWidget* p=lookup_widget(button_graphique,"treeview2");
affi_ch(p,"reclamation.txt");
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button_graphique,"notebook1")));
gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(button_graphique,"notebook1")));
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{ 

GtkTreeModel     *model,*labe;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(button,"treeview2");
	gchar *CIN;
        gchar *NOM;
        gchar *Prenom;
        gchar *sui;
        gchar *messageRecla;
        gchar *jour;
	gchar *mois;
	gchar *annee;
	gchar *resp;
	guint d,m,y;
	GtkCalendar *ca;
	ca = lookup_widget (button,"calendar1");
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
	
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&NOM,2,&Prenom,4,&CIN,3,&resp,5,&messageRecla,6,&jour,7,&mois,8,&annee,9,&sui,-1);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry18")),id);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry19")),NOM);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry20")),Prenom);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry21")),CIN);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry22")),messageRecla);
 d=(int)jour;
 m=(int)mois;
 y=(int)annee;
 gtk_calendar_select_month(GTK_CALENDAR(ca),m,y);
 gtk_calendar_select_day(GTK_CALENDAR(ca),d);


		//gtk_widget_show(lookup_widget(objet,"modifier_ch"));//afficher le bouton modifier
                gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button,"notebook1")));
		gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(button,"notebook1")));



labe = lookup_widget(button, "label361");
gtk_label_set_text(GTK_LABEL(labe),resp);




         
}
//mise a jour treeview

affi_ad_ch(p,"reclamation.txt");
}







void
on_button10_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{  GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(button,"treeview2");;
        
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_ch( id);// supprimer la ligne du fichier
}

}
int x;
int q;

void
on_radiobutton1_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;} 

}


void
on_radiobutton2_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;} 


}


void
on_checkbutton1_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


 if (gtk_toggle_button_get_active(togglebutton)) 

   {q=1;}    

}


void
on_checkbutton2_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(togglebutton)) 
  {q=0;}  

}


void
on_button15_clicked                 (GtkButton       *objet,
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
 if (q==0)
 strcat(ch3," Groupe B "); 
if(q==1)
 strcat (ch3,"  Groupe A");
strcat(ch3,ch1);
strcat(ch3,ch2);
output = lookup_widget(objet, "label356");

gtk_label_set_text(GTK_LABEL(output),ch3);





}


void
on_button7_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *fenetre_reclam, *auth;
fenetre_reclam = lookup_widget(button,"reclam");
gtk_widget_destroy(fenetre_reclam);
auth=create_auth();
gtk_widget_show(auth);


}





void
on_button9_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.facebook.com/");
}


void
on_button8_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.instagram.com/");
}



 //Aymen

product p;

int z=1;
int w=1;
int m=1;
/*void
on_buttonaddresto_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{product p;


GtkWidget *nom, *ref, *quant, *type, *msg,*check;
nom=lookup_widget(button,"entry24");
ref=lookup_widget(button,"entry25");
quant=lookup_widget(button,"spinbutton5");
type=lookup_widget(button,"combobox37");
msg=lookup_widget(button,"label398");
check=lookup_widget(button,"checkbutton3");
strcpy(p.ref,gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(p.name,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));  
p.quant=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(quant));
if (z==1) strcpy(p.etat,"ENSTOCK");
if(z==2) strcpy(p.etat,"EPUISE");
if((strcmp(p.name,"")==0)||(strcmp(p.ref,"")==0)||(strcmp(p.type,"")==0)||(m!=2))
gtk_label_set_text(GTK_LABEL(msg),"VERIFIER VOS DONNEES");
else
{addproduct(p);
m=1;
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(check),FALSE);
gtk_label_set_text(GTK_LABEL(msg),"Succes de l'ajout");}

}
*/

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
z=1;
}


void
on_radiobutton3_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
z=2;
}

/*
void
on_buttondisplayresto_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *treeview1;


treeview1=lookup_widget(button,"treeview3");
affichage(treeview1);


}


void
on_refreshstock_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *agentresto,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"agentresto");
agentresto=create_agentresto();

gtk_widget_show(agentresto);

gtk_widget_hide(w1);

treeview1=lookup_widget(agentresto,"treeview3");
affichage(treeview1);

}


void
on_treeview3_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{	





}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_buttonsearchresto_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{char n[50],h[50],r[50],type[50],etat[50];
int x;
float quant;
product q;
GtkWidget *noma, *msgg,*ref,*typee,*quantt,*epuise,*enstock,*warr;
noma=lookup_widget(button,"entry26");
msgg=lookup_widget(button,"label409");
ref=lookup_widget(button,"entry27");
typee=lookup_widget(button,"combobox38");
quantt=lookup_widget(button,"spinbutton6");
epuise=lookup_widget(button,"radiobutton5");
enstock=lookup_widget(button,"radiobutton6");
warr=lookup_widget(button,"label410");


strcpy(h,gtk_entry_get_text(GTK_ENTRY(noma)));
x=searchproduct(h);
if (x==0) {
gtk_label_set_text(GTK_LABEL(msgg),"produit introuvable");
gtk_label_set_text(GTK_LABEL(warr)," ");}
if (x==1) {//product searchinfo(q,h);
gtk_label_set_text(GTK_LABEL(msgg),"produit existe");
gtk_label_set_text(GTK_LABEL(warr)," ");
//gtk_entry_set_text(GTK_ENTRY(ref),"test");
///strcpy(r,q.ref);
////////////////////////////////////
product p;
FILE*f=NULL;
f=fopen("product.txt","r");
while(fscanf(f,"%s %s %s %f %s \n",p.ref,p.name,p.type,&p.quant,p.etat)!=EOF)
{
if(strcmp(h,p.name)==0)
{
strcpy(n,p.name);
strcpy(r,p.ref);
strcpy(type,p.type);
quant=p.quant;
strcpy(etat,p.etat);
fclose(f);

}

}

//////////////////////////////////////
char matrice[7][50]={"viandesrouges","legumes","fruits","viandesblanches","produitlaitier","pates"};
gtk_entry_set_text(GTK_ENTRY(ref),r);

gtk_spin_button_set_value(quantt,quant);
int i=0;
while((i<6) && (strcmp(type,matrice[i])!=0))
i++;
	
gtk_combo_box_set_active(GTK_COMBO_BOX(typee),i);

/////////radio
if(strcmp(etat,"ENSTOCK")==0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(enstock),TRUE);
if(strcmp(etat,"EPUISE")==0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(epuise),TRUE);

//closure of if x=1!!!!!!!
}






}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_buttonhistory_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *treeview2;


treeview2=lookup_widget(button,"treeview4");
affichagehis(treeview2);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_buttoneditresto_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{product q;

char h[50],n[50];
int x;
GtkWidget *nomb, *refb, *quantb, *typeb, *war,*msggg;
nomb=lookup_widget(button,"entry26");
war=lookup_widget(button,"label410");
refb=lookup_widget(button,"entry27");
typeb=lookup_widget(button,"combobox38");
quantb=lookup_widget(button,"spinbutton6");
msggg=lookup_widget(button,"label409");
strcpy(h,gtk_entry_get_text(GTK_ENTRY(nomb)));
x=searchproduct(h);
if (x==0){ 
gtk_label_set_text(GTK_LABEL(war),"impossible de modifier produit inexistant");
gtk_label_set_text(GTK_LABEL(msggg),"  ");
}
if (x==1) 
{
strcpy(q.name,gtk_entry_get_text(GTK_ENTRY(nomb)));
strcpy(q.ref,gtk_entry_get_text(GTK_ENTRY(refb)));
strcpy(q.name,gtk_entry_get_text(GTK_ENTRY(nomb)));
strcpy(q.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(typeb)));  
q.quant=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(quantb));
if (w==1) strcpy(q.etat,"ENSTOCK");
if(w==2) strcpy(q.etat,"EPUISE");
updateproduct(q);
gtk_label_set_text(GTK_LABEL(war),"succes de modification");


///////////////finx==1
}

////////////////finvoid
}
*/

void
on_radiobutton5_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
w=2;

}


void
on_radiobutton6_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
w=1;

}

/*
void
on_buttonsuppresto_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{GtkTreeModel *model;
	GtkTreeSelection *selection;
	GtkTreeIter iter;
	GtkWidget *treeview1;
	gchar* name;
	gchar* ref;
	gchar* type;
	float quant;
	gchar* etat;
	product p;

	treeview1=lookup_widget(button,"treeview3");
	selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview1));
	if(gtk_tree_selection_get_selected(selection,&model,&iter))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0,&ref, 1,&name, 2,&type, 3,&quant, 4,&etat, -1);
	gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
	strcpy(p.ref,ref);
		strcpy(p.name,name);
		strcpy(p.type,type);
		p.quant=quant;
		strcpy(p.etat,etat);
	deleteproduct(name);
}

}


void
on_buttonepuise_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *treeview12;


treeview12=lookup_widget(button,"treeview5");
rupture();
affichagerup(treeview12);


}
*/
/*
void
on_buttonac2_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *agentresto,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"agentresto");
agentresto=create_agentresto();

gtk_widget_show(agentresto);

gtk_widget_hide(w1);

treeview1=lookup_widget(agentresto,"treeview501");
rupture();
affichagerup(treeview1);

}


void
on_buttoncommand_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{commander();

}
*/

void
on_checkbutton3_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
m=2;

}










void
on_button29_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *agentresto,*w1;
GtkWidget *treeview1;

w1=lookup_widget(button,"resto");
agentresto=create_resto();

gtk_widget_show(agentresto);
gtk_widget_hide(w1);


treeview1=lookup_widget(agentresto,"treeview3");
affichage(treeview1);
/*GtkWidget *agentresto,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet,"agentresto");
agentresto=create_agentresto();

gtk_widget_show(agentresto);

gtk_widget_hide(w1);

treeview1=lookup_widget(agentresto,"treeview3");
affichage(treeview1);*/
}


void
on_button21_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *treeview1;


treeview1=lookup_widget(button,"treeview3");
affichage(treeview1);

}


void
on_button22_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkTreeModel *model;
	GtkTreeSelection *selection;
	GtkTreeIter iter;
	GtkWidget *treeview1;
	gchar* name;
	gchar* ref;
	gchar* type;
	float quant;
	gchar* etat;
	product p;

	treeview1=lookup_widget(button,"treeview3");
	selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview1));
	if(gtk_tree_selection_get_selected(selection,&model,&iter))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0,&ref, 1,&name, 2,&type, 3,&quant, 4,&etat, -1);
	gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
	strcpy(p.ref,ref);
		strcpy(p.name,name);
		strcpy(p.type,type);
		p.quant=quant;
		strcpy(p.etat,etat);
	deleteproduct(name);
}


}


void
on_button23_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{product p;


GtkWidget *nom, *ref, *quant, *type, *msg,*check;
nom=lookup_widget(button,"entry24");
ref=lookup_widget(button,"entry25");
quant=lookup_widget(button,"spinbutton5");
type=lookup_widget(button,"combobox37");
msg=lookup_widget(button,"label398");
check=lookup_widget(button,"checkbutton3");
strcpy(p.ref,gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(p.name,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));  
p.quant=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(quant));
if (z==1) strcpy(p.etat,"ENSTOCK");
if(z==2) strcpy(p.etat,"EPUISE");
if((strcmp(p.name,"")==0)||(strcmp(p.ref,"")==0)||(strcmp(p.type,"")==0)||(m!=2))
gtk_label_set_text(GTK_LABEL(msg),"VERIFIER VOS DONNEES");
else
{addproduct(p);
m=1;
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(check),FALSE);
gtk_label_set_text(GTK_LABEL(msg),"Succes de l'ajout");}

}


void
on_button24_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *treeview2;


treeview2=lookup_widget(button,"treeview4");
affichagehis(treeview2);

}


void
on_button26_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{char n[50],h[50],r[50],type[50],etat[50];
int x;
float quant;
product q;
GtkWidget *noma, *msgg,*ref,*typee,*quantt,*epuise,*enstock,*warr;
noma=lookup_widget(button,"entry26");
msgg=lookup_widget(button,"label409");
ref=lookup_widget(button,"entry27");
typee=lookup_widget(button,"combobox38");
quantt=lookup_widget(button,"spinbutton6");
epuise=lookup_widget(button,"radiobutton5");
enstock=lookup_widget(button,"radiobutton6");
warr=lookup_widget(button,"label410");


strcpy(h,gtk_entry_get_text(GTK_ENTRY(noma)));
x=searchproduct(h);
if (x==0) {
gtk_label_set_text(GTK_LABEL(msgg),"produit introuvable");
gtk_label_set_text(GTK_LABEL(warr)," ");}
if (x==1) {//product searchinfo(q,h);
gtk_label_set_text(GTK_LABEL(msgg),"produit existe");
gtk_label_set_text(GTK_LABEL(warr)," ");}
//gtk_entry_set_text(GTK_ENTRY(ref),"test");
///strcpy(r,q.ref);
////////////////////////////////////
product p;
FILE*f=NULL;
f=fopen("product.txt","r");
while(fscanf(f,"%s %s %s %f %s \n",p.ref,p.name,p.type,&p.quant,p.etat)!=EOF)
{
if(strcmp(h,p.name)==0)
{
strcpy(n,p.name);
strcpy(r,p.ref);
strcpy(type,p.type);
quant=p.quant;
strcpy(etat,p.etat);
fclose(f);

}

}

//////////////////////////////////////
char matrice[7][50]={"viandesrouges","legumes","fruits","viandesblanches","produitlaitier","pates"};
gtk_entry_set_text(GTK_ENTRY(ref),r);

gtk_spin_button_set_value(quantt,quant);
int i=0;
while((i<6) && (strcmp(type,matrice[i])!=0))
i++;
	
gtk_combo_box_set_active(GTK_COMBO_BOX(typee),i);

/////////radio
if(strcmp(etat,"ENSTOCK")==0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(enstock),TRUE);
if(strcmp(etat,"EPUISE")==0)
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(epuise),TRUE);

//closure of if x=1!!!!!!!

}


void
on_button25_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{product q;

char h[50],n[50];
int x;
GtkWidget *nomb, *refb, *quantb, *typeb, *war,*msggg;
nomb=lookup_widget(button,"entry26");
war=lookup_widget(button,"label410");
refb=lookup_widget(button,"entry27");
typeb=lookup_widget(button,"combobox38");
quantb=lookup_widget(button,"spinbutton6");
msggg=lookup_widget(button,"label409");
strcpy(h,gtk_entry_get_text(GTK_ENTRY(nomb)));
x=searchproduct(h);
if (x==0){ 
gtk_label_set_text(GTK_LABEL(war),"impossible de modifier produit inexistant");
gtk_label_set_text(GTK_LABEL(msggg),"  ");
}
if (x==1) 
{
strcpy(q.name,gtk_entry_get_text(GTK_ENTRY(nomb)));
strcpy(q.ref,gtk_entry_get_text(GTK_ENTRY(refb)));

strcpy(q.name,gtk_entry_get_text(GTK_ENTRY(nomb)));
strcpy(q.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(typeb))); 

q.quant=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(quantb));
if (w==1) strcpy(q.etat,"ENSTOCK");
if(w==2) strcpy(q.etat,"EPUISE");

updateproduct(q);
gtk_label_set_text(GTK_LABEL(war),"succes de modification");


///////////////finx==1
}

////////////////finvoid

}


void
on_button27_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *treeview12;


treeview12=lookup_widget(button,"treeview5");
rupture();
affichagerup(treeview12);

}


void
on_button28_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
commander();
}


void
on_button20_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	 
 GtkWidget *fenetre_resto, *auth;
fenetre_resto = lookup_widget(button,"resto");
gtk_widget_destroy(fenetre_resto);
auth=create_auth();
gtk_widget_show(auth);
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}





void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

//Dorra



void
on_button34_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *aj_hebergement, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
aj_hebergement=lookup_widget(objet,"aj_hebergement");
aj_hebergement=create_aj_hebergement();

gtk_widget_show(aj_hebergement);

}


void
on_button33_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *mod_hebergement, *dashboard_hebergement, *aj_heberge;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
mod_hebergement=lookup_widget(objet,"mod_hebergement");
mod_hebergement=create_mod_hebergement();

gtk_widget_show(mod_hebergement);

}


void
on_button32_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *treeview, *af_hebergement, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
af_hebergement=lookup_widget(objet,"af_hebergement");
af_hebergement=create_af_hebergement();

gtk_widget_show(af_hebergement);

treeview=lookup_widget(af_hebergement,"treeview_hebergement");

afficher_hebergement(treeview,"hebergement.txt");


}


void
on_button31_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *recherche, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
recherche=lookup_widget(objet,"recherche");
recherche=create_recherche();

gtk_widget_show(recherche);

}


void
on_button30_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *treeview, *af_alarme, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
af_alarme=lookup_widget(objet,"af_alarme");
af_alarme=create_af_alarme();

gtk_widget_show(af_alarme);

treeview=lookup_widget(af_alarme,"treeview10");

afficher_alarme(treeview,"alarme.txt");

}


void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button35_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *treeview, *af_alarme;


af_alarme=lookup_widget(objet,"af_alarme");

gtk_widget_destroy(af_alarme);
af_alarme=lookup_widget(objet,"af_alarme");
af_alarme=create_af_alarme();

gtk_widget_show(af_alarme);

treeview=lookup_widget(af_alarme,"treeview6");

afficher_alarme(treeview,"alarme.txt");

}


void
on_treeview7_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{GtkTreeIter iter;
	gint id;
	etudiant e;
	GtkWidget *pInfo;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	e.id=id; pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cet étudiant?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer_hebergement(e,"hebergement.txt");
	afficher_hebergement(treeview,"hebergement.txt");
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}

}


void
on_button36_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *treeview, *af_hebergement;


af_hebergement=lookup_widget(objet,"af_hebergement");

gtk_widget_destroy(af_hebergement);
af_hebergement=lookup_widget(objet,"af_hebergement");
af_hebergement=create_af_hebergement();

gtk_widget_show(af_hebergement);

treeview=lookup_widget(af_hebergement,"treeview7");

afficher_hebergement(treeview,"hebergement.txt");

}


void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton9_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button37_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *mod7, *bloc1, *bloc2, *bloc3, *pInfo, *mod_hebergement;
etudiant e;
int c;
mod1=lookup_widget(objet,"entry31");
mod2=lookup_widget(objet,"entry29");
mod3=lookup_widget(objet,"entry30");
bloc1=lookup_widget(objet,"radiobutton7");
bloc2=lookup_widget(objet,"radiobutton8");
bloc3=lookup_widget(objet,"radiobutton9");
mod4=lookup_widget(objet,"combobox39");
mod5=lookup_widget(objet,"entry28");
mod6=lookup_widget(objet,"entry32");
mod7=lookup_widget(objet,"spinbutton7");
e.id=atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(mod2)));
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(mod3)));
strcpy(e.bloc,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bloc1))==1?"A":gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bloc2))==1?"B":"C");
e.chambre=gtk_combo_box_get_active(GTK_COMBO_BOX(mod4))+1;
e.tel=atoi(gtk_entry_get_text(GTK_ENTRY(mod5)));
strcpy(e.email,gtk_entry_get_text(GTK_ENTRY(mod6)));
e.n=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mod7));
modifier_hebergement(e,"hebergement.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Etudiant modifié avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	mod_hebergement = lookup_widget (objet,"mod_hebergement");
	gtk_widget_destroy(mod_hebergement);
	break;
	}

}


void
on_button38_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *mod7, *pInfo, *bloc1, *bloc2, *bloc3;
etudiant p;
int a=0;
char ch[20];
FILE *f;
mod1=lookup_widget(objet,"entry31");
mod2=lookup_widget(objet,"entry29");
mod3=lookup_widget(objet,"entry30");
bloc1=lookup_widget(objet,"radiobutton7");
bloc2=lookup_widget(objet,"radiobutton8");
bloc3=lookup_widget(objet,"radiobutton9");
mod4=lookup_widget(objet,"combobox39");
mod5=lookup_widget(objet,"entry28");
mod6=lookup_widget(objet,"entry32");
mod7=lookup_widget(objet,"sbinbutton7");
int id = atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
f = fopen("hebergement.txt","r");
if(f!=NULL){
while(fscanf(f,"%d %s %s %d %d %d %s %d %d %d %s\n",&(p.id),p.prenom,p.nom,&(p.d.j),&(p.d.m),&(p.d.a),p.bloc,&(p.chambre),&(p.n),&(p.tel),p.email)!=EOF)
	{
		if(p.id==id){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_entry_set_text(GTK_ENTRY(mod2),p.prenom);
gtk_entry_set_text(GTK_ENTRY(mod3),p.nom);
strcmp(p.bloc,"A")==0?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bloc1),TRUE):strcmp(p.bloc,"B")==0?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bloc2),TRUE):gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bloc3),TRUE);
gtk_combo_box_set_active(GTK_COMBO_BOX(mod4),p.chambre-1);
sprintf(ch,"%d",p.tel);
gtk_entry_set_text(GTK_ENTRY(mod5),ch);
gtk_entry_set_text(GTK_ENTRY(mod6),p.email);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mod7),p.n);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Etudiant introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}

}


void
on_treeview8_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button40_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *r9, *pInfo;
char date_naissance[20], tel[20], num[5];
r1=lookup_widget(objet,"entry33");
r2=lookup_widget(objet,"label455");
r3=lookup_widget(objet,"label442");
r4=lookup_widget(objet,"label443");
r5=lookup_widget(objet,"label444");
r6=lookup_widget(objet,"label445");
r7=lookup_widget(objet,"label446");
r8=lookup_widget(objet,"label450");
r9=lookup_widget(objet,"label453");
int id = atoi(gtk_entry_get_text(GTK_ENTRY(r1)));
etudiant p = chercher_hebergement(id,"hebergement.txt");
if (p.id==-1){
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"ID introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
else{
gtk_label_set_text(GTK_LABEL(r2),p.prenom);
gtk_label_set_text(GTK_LABEL(r3),p.nom);
sprintf(date_naissance,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
gtk_label_set_text(GTK_LABEL(r4),date_naissance);
gtk_label_set_text(GTK_LABEL(r5),p.bloc);
gtk_label_set_text(GTK_LABEL(r6),p.chambre==1?"Individuelle":p.chambre==2?"Double":"Triple");
sprintf(tel,"%d",p.tel);
gtk_label_set_text(GTK_LABEL(r7),tel);
gtk_label_set_text(GTK_LABEL(r8),p.email);
sprintf(num,"%d",p.n);
gtk_label_set_text(GTK_LABEL(r9),num);
}

}


void
on_button41_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj6, *aj7, *bloc1, *bloc2, *bloc3, *aj_hebergement;
GtkCalendar *ajc;
etudiant e;
int c;
guint day, month, year;
aj1=lookup_widget(objet,"entry38");
aj2=lookup_widget(objet,"entry35");
aj3=lookup_widget(objet,"entry36");
ajc=lookup_widget(objet,"calendar2");
bloc1=lookup_widget(objet,"radiobutton10");
bloc2=lookup_widget(objet,"radiobutton11");
bloc3=lookup_widget(objet,"radiobutton12");
aj4=lookup_widget(objet,"combobox40");
aj5=lookup_widget(objet,"entry34");
aj6=lookup_widget(objet,"entry37");
aj7=lookup_widget(objet,"spinbutton8");
e.id=atoi(gtk_entry_get_text(GTK_ENTRY(aj1)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(aj2)));
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(aj3)));
gtk_calendar_get_date(GTK_CALENDAR(ajc), &day, &month, &year);
e.d.j=year;
e.d.m=month+1;
e.d.a=day;
strcpy(e.bloc,gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bloc1))==1?"A":gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bloc2))==1?"B":"C");
c=gtk_combo_box_get_active(GTK_COMBO_BOX(aj4));
e.chambre = c==0?1:c==1?2:3;
e.n=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aj7));
e.tel=atoi(gtk_entry_get_text(GTK_ENTRY(aj5)));
strcpy(e.email,gtk_entry_get_text(GTK_ENTRY(aj6)));
ajouter_hebergement(e,"hebergement.txt");
	aj_hebergement = lookup_widget (objet,"aj_hebergement");
	gtk_widget_destroy(aj_hebergement);

}


void
on_button42_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget* auth, *foyer;
foyer=lookup_widget(button,"foyer");
gtk_widget_destroy(foyer);
auth = create_auth ();
gtk_widget_show (auth);

}


void
on_button43_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *af_alarme;
af_alarme=lookup_widget(button,"af_alarme");
gtk_widget_destroy(af_alarme);


}


void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *af_hebergement;
af_hebergement=lookup_widget(button,"af_hebergement");
gtk_widget_destroy(af_hebergement);


}


void
on_button45_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget  *recherche;
recherche=lookup_widget(button,"recherche");
gtk_widget_destroy(recherche);


}


//Ahmed_2
int x;
int r[2]={0,0};

void
on_button48_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *ty,*se,*da,*po,*nb,*Ajouter,*labeldate,*labelmain,*labelty;
Ajouter=lookup_widget(objet_graphique,"Ajouter");
eve A ;
char id[30];
int i, longueurChaine = 0;
char chaine[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int b=1;

ty = lookup_widget (objet_graphique,"entry39");
se = lookup_widget (objet_graphique,"entry40");
da = lookup_widget (objet_graphique,"combobox41");
po = lookup_widget (objet_graphique,"entry41");
nb = lookup_widget (objet_graphique,"spinbutton9");


A.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));


strcpy(A.lieu,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(A.event,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(A.ing,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(A.date,gtk_entry_get_text(GTK_ENTRY(po)));

labelty=lookup_widget(objet_graphique,"label478");
labelmain=lookup_widget(objet_graphique,"label481");
labeldate=lookup_widget(objet_graphique,"label482");

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
 GtkWidget* p=lookup_widget(objet_graphique,"treeview8");
afficher_nb(p ,"event.txt");

}


void
on_button47_clicked                    (GtkButton       *button,
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
on_button51_clicked                    (GtkButton       *objet_graphique,
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

lb = lookup_widget (objet_graphique,"label485");
dd = lookup_widget (objet_graphique,"entry42");
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
on_button50_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *dd,*ty,*se,*da,*po,*nb,*lb;
int v=-1;
char id[20];
char idd[20];
char lieu1[20];
char event1[20];
char ing1[20];
char date1[20];
char nb1[20];
eve U ;

dd = lookup_widget (objet_graphique,"entry42");
ty = lookup_widget (objet_graphique,"entry43");
se = lookup_widget (objet_graphique,"entry44");
da = lookup_widget (objet_graphique,"combobox42");
po = lookup_widget (objet_graphique,"entry45");
nb = lookup_widget (objet_graphique,"spinbutton10");
lb = lookup_widget (objet_graphique,"label485");

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
 GtkWidget* p=lookup_widget(objet_graphique,"treeview8");
afficher_nb(p ,"event.txt");

}


void
on_button49_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *dd,*lieu,*event,*ing,*date,*ty,*se,*da,*po,*lb;
char idd[20];

int x=-1;
char lieu1[20];
char event1[20];
char date1[20];
char nb1[20];
char id[20];
char ing1[20];

FILE *F;
dd = lookup_widget (button,"entry42");
lieu = lookup_widget(button, "label495");
event = lookup_widget(button, "label497");
ing = lookup_widget(button, "label498");
date = lookup_widget(button, "label499");
lb= lookup_widget(button, "label485");

ty = lookup_widget (button,"entry43");
se = lookup_widget (button,"entry44");
da = lookup_widget (button,"combobox42");
po = lookup_widget (button,"entry45");




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
on_button54_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview8");
	gchar *lieu;
        gchar *event;
        gchar *etat;
        gchar *date;
  	gchar *nb;
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&lieu,2,&event,3,&etat,4,&date,5,&nb,-1);
  
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry42")),id);

GtkWidget *dd,*lieu,*event,*ing,*date,*ty,*se,*da,*po;

	dd = lookup_widget (objet,"entry42");
	lieu = lookup_widget(objet,"label495");
	event = lookup_widget(objet,"label497");
	ing = lookup_widget(objet, "label498");
	date = lookup_widget(objet, "label499");

	ty = lookup_widget (objet,"entry43");
	se = lookup_widget (objet,"entry44");
	da = lookup_widget (objet,"combobox42");
	po = lookup_widget (objet,"entry45");

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
			
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook3")));//redirection vers la page precedente
}

//mise a jour treeview
afficher_nb(p ,"event.txt");


}


void
on_button53_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview8");;

        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_nb( id);// supprimer la ligne du fichier
}
}





void
on_button46_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.instagram.com/");
}


void
on_button55_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.facebook.com/");
}


void
on_button56_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.youtube.com/");
}





void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton)) 

   {r[1]=1;}    
}


void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) 
  {r[0]=1;} 
}


void
on_radiobutton13_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;}
}


void
on_radiobutton14_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;} 
}


void
on_button58_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *fenetre_event, *auth;
fenetre_event = lookup_widget(button,"event");
gtk_widget_destroy(fenetre_event);
auth=create_auth();
gtk_widget_show(auth);
}

// Amen

int radio=1;
int v=0;
void
on_treeview9_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}




void
on_button65_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Ajouter_un_capteur();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_button64_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char x[100];
fileload();


GtkWidget * id, * inc, * inc2, *conf;

id = lookup_widget(button,"entry46");
inc = lookup_widget(button,"label511");
inc2 = lookup_widget(button,"label510");

strcpy(x, gtk_entry_get_text(GTK_ENTRY(id)));



if(isid(x)!=-1 && v==1){
supprimer(x);
filesave();
gtk_label_set_text(GTK_LABEL(inc), "succes.");
v=0;
}
if(isid(x)==-1 && v==1){
gtk_label_set_text(GTK_LABEL(inc), "capteur inexistant.");
v=0;
}
if (v==0);
{
gtk_label_set_text(GTK_LABEL(inc2), "confirmé la suppression");
v=1;
}
}


void
on_button63_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_modifier_un_capteur();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_button62_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
fileload();
  int i;
  char sid[30];
  GtkWidget *liste, *id;
  id=lookup_widget(button,"entry47");
  liste=lookup_widget(button,"treeview9");
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
on_button60_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_debit();
  gtk_widget_show(x);

}


void
on_button59_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
fileload();
GtkWidget *liste;
liste=lookup_widget(button,"treeview9");
afficher(liste);
}


void
on_button61_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_auth();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_button67_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
capteur x;
fileload();


GtkWidget * id, * type, * position, * etat, * valeur, * inc;


id = lookup_widget(button,"entry48");
type = lookup_widget(button,"comboboxentry1");
position = lookup_widget(button,"entry50");
etat = lookup_widget(button,"entry49");
valeur=lookup_widget(button,"spinbutton11");
inc = lookup_widget(button,"label528");

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
on_button66_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"Ajouter_un_capteur");
  gtk_widget_destroy(a);
}


void
on_button68_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
capteur x;
fileload();


GtkWidget * id, * type, * position, * etat, * valeur, * inc;
  

id = lookup_widget(button,"entry51");
type = lookup_widget(button,"comboboxentry2");
position = lookup_widget(button,"entry53");
etat = lookup_widget(button,"entry52");
inc = lookup_widget(button,"label542");
valeur=lookup_widget(button,"spinbutton12");

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
on_button69_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"modifier_un_capteur");
  gtk_widget_destroy(a);
}





void
on_button70_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"debit");
  gtk_widget_destroy(a);
}





void
on_checkbutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
v=1;
else
v=0;
}


void
on_button72_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Admin ();
  gtk_widget_show(x);
  a= lookup_widget(button,"dash");
  gtk_widget_destroy(a);
}


void
on_button79_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_dash ();
  gtk_widget_show(x);
  a= lookup_widget(button,"Admin");
  gtk_widget_destroy(a);
}




void
on_treeviewd_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treevieway_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ydash_clicked                       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *ty,*nb;


char niveau[20];

ty = lookup_widget (objet_graphique,"entry7");
nb = lookup_widget(objet_graphique, "button_calculEtudiant");

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
on_addash_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *eresp;

char id[20];
char NOM[20];
char Prenom[20];
char resp[20];
char CIN[20];
char messageRecla[20];
char jour[20];
char mois[20];
char annee[20];
char objet[20];
int nb1=0;
int nb2=0;

      
  FILE* F;

F=fopen("reclamation.txt","r");
if(F!=NULL)
{
    
    while(fscanf(F,"%s %s %s %s %s %s %s %s %s %s\n",id,NOM,Prenom,CIN,resp,messageRecla,jour,mois,annee,objet)!=EOF)
    {
        if((strcmp(resp,"Restauration")==0)){
        nb1++;
           }                                  
else
{ if((strcmp(resp,"Hebergement")==0)){
        nb2++;
           } 
 }
}

if(nb1>nb2){
    strcpy(resp,"Restauration");
}
else 
{ if (nb1<nb2){
    strcpy(resp,"Hebergement");
} else {strcpy(resp, "égaux");}}

fclose(F);
eresp = lookup_widget(button, "label347");
gtk_label_set_text(GTK_LABEL(eresp),resp);

}}


void
on_ddash_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *x;
  x=create_af_alarme ();
  gtk_widget_show(x);
}


void
on_aydash_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview12;


treeview12=lookup_widget(button,"treevieway");
rupture();
affichagerup(treeview12);

}


void
on_aydash2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
commander();
}


void
on_azdash_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *message;

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
message = lookup_widget(button, "label508");
gtk_label_set_text(GTK_LABEL(message),type);



}

}


void
on_treeview10_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button81_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *af_alarme;
af_alarme=lookup_widget(objet,"af_alarme");

gtk_widget_destroy(af_alarme);
}


void
on_button80_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_alarme;


af_alarme=lookup_widget(objet,"af_alarme");

gtk_widget_destroy(af_alarme);
af_alarme=lookup_widget(objet,"af_alarme");
af_alarme=create_af_alarme();

gtk_widget_show(af_alarme);

treeview=lookup_widget(af_alarme,"treeview10");

afficher_alarme(treeview,"alarme.txt");
}


void
on_buttonValider_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *no,*pr,*ci,*us,*pass,*Role,*dd,*cin;
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
on_button83_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *afflist;
  GtkTextView *aff;
 
  aff=lookup_widget(button,"textview2");

    capteurx S[5000];
	char debit[1000],msg[10000];
    int n=0,i;
    FILE *f=NULL;
    f=fopen("debit.txt","r");
    if(f==NULL){printf("error reading file");}
    while(fscanf(f,"%d %d %d %f\n",&S[n].jour,&S[n].heure,&S[n].etage,&S[n].debit)!=EOF){
        n++;
    }
    fclose(f);
	strcpy(msg,"");
    for(i=0;i<n;i++)
    {
        if(S[i].debit>30.00)
        {

        sprintf(debit,"Attention !! Le debit d'eau de l'étage %d est : %.2fL/s \n à %dh , le %d/11/2021\n\n",S[i].etage ,S[i].debit,S[i].heure,S[i].jour);
	strcat(msg,debit);
        }
    }
    
   
 GtkTextBuffer *buff;

buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(aff));
gtk_text_buffer_set_text(buff,msg,-1);
}


void
on_button82_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget  *a;

  a= lookup_widget(button,"debit");
  gtk_widget_destroy(a);
}


void
on_button84_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_debit();
  gtk_widget_show(x);
}

