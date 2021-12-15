#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdbool.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "hebergement.h"


void
on_button_1_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj_hebergement, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
aj_hebergement=lookup_widget(objet,"aj_hebergement");
aj_hebergement=create_aj_hebergement();

gtk_widget_show(aj_hebergement);
}


void
on_button_2_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod_hebergement, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
mod_hebergement=lookup_widget(objet,"mod_hebergement");
mod_hebergement=create_mod_hebergement();

gtk_widget_show(mod_hebergement);
}


void
on_button_3_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_hebergement, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
af_hebergement=lookup_widget(objet,"af_hebergement");
af_hebergement=create_af_hebergement();

gtk_widget_show(af_hebergement);

treeview=lookup_widget(af_hebergement,"treeview_hebergement");

afficher_hebergement(treeview,"hebergement.txt");
}


void
on_button_4_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_alarme, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
af_alarme=lookup_widget(objet,"af_alarme");
af_alarme=create_af_alarme();

gtk_widget_show(af_alarme);

treeview=lookup_widget(af_alarme,"treeview_alarme");

afficher_alarme(treeview,"alarme.txt");
}


void
on_button_af_alarme_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_alarme;


af_alarme=lookup_widget(objet,"af_alarme");

gtk_widget_destroy(af_alarme);
af_alarme=lookup_widget(objet,"af_alarme");
af_alarme=create_af_alarme();

gtk_widget_show(af_alarme);

treeview=lookup_widget(af_alarme,"treeview_alarme");

afficher_alarme(treeview,"alarme.txt");
}


void
on_treeview_hebergement_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
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
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af_hebergement;


af_hebergement=lookup_widget(objet,"af_hebergement");

gtk_widget_destroy(af_hebergement);
af_hebergement=lookup_widget(objet,"af_hebergement");
af_hebergement=create_af_hebergement();

gtk_widget_show(af_hebergement);

treeview=lookup_widget(af_hebergement,"treeview_hebergement");

afficher_hebergement(treeview,"hebergement.txt");
}


void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *mod7, *bloc1, *bloc2, *bloc3, *pInfo;
etudiant e;
int c;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
bloc1=lookup_widget(objet,"modA");
bloc2=lookup_widget(objet,"modB");
bloc3=lookup_widget(objet,"modC");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod6=lookup_widget(objet,"mod6");
mod7=lookup_widget(objet,"mod7");
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
	break;
	}
}


void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod5, *mod6, *mod7, *pInfo, *bloc1, *bloc2, *bloc3;
etudiant p;
int a=0;
char ch[20];
FILE *f;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
bloc1=lookup_widget(objet,"modA");
bloc2=lookup_widget(objet,"modB");
bloc3=lookup_widget(objet,"modC");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
mod6=lookup_widget(objet,"mod6");
mod7=lookup_widget(objet,"mod7");
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
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj6, *aj7, *bloc1, *bloc2, *bloc3;
GtkCalendar *ajc;
etudiant e;
int c;
guint day, month, year;
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
ajc=lookup_widget(objet,"ajc");
bloc1=lookup_widget(objet,"ajA");
bloc2=lookup_widget(objet,"ajB");
bloc3=lookup_widget(objet,"ajC");
aj4=lookup_widget(objet,"aj4");
aj5=lookup_widget(objet,"aj5");
aj6=lookup_widget(objet,"aj6");
aj7=lookup_widget(objet,"aj7");
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
}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *recherche, *dashboard_hebergement;


dashboard_hebergement=lookup_widget(objet,"dashboard_hebergement");

//gtk_widget_destroy(dashboard_hebergement);
recherche=lookup_widget(objet,"recherche");
recherche=create_recherche();

gtk_widget_show(recherche);
}


void
on_chercher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *r9, *pInfo;
char date_naissance[20], tel[20], num[5];
r1=lookup_widget(objet,"r1");
r2=lookup_widget(objet,"r2");
r3=lookup_widget(objet,"r3");
r4=lookup_widget(objet,"r4");
r5=lookup_widget(objet,"r5");
r6=lookup_widget(objet,"r6");
r7=lookup_widget(objet,"r7");
r8=lookup_widget(objet,"r8");
r9=lookup_widget(objet,"r9");
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

