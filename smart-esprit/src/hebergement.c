#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hebergement.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	ID,
	NOM_COMPLET,
	DATE_NAISSANCE,
	BLOC,
	CHAMBRE,
	NUM,
	TEL,
	EMAIL,
	COLUMNS
};

enum
{
	TYPE,
	ETAGE,
	DATE,
	TEMPS,
	COLUMNS1
};

void ajouter_hebergement(etudiant e, char *fname){
GtkWidget *pQuestion, *pInfo;
FILE *f;
int b=0;
gpointer user_data;
etudiant p;
f=fopen(fname,"a+");
if(f!=NULL)
{	while(fscanf(f,"%d %s %s %d %d %d %s %d %d %d %s\n",&(p.id),p.prenom,p.nom,&(p.d.j),&(p.d.m),&(p.d.a),p.bloc,&(p.chambre),&(p.n),&(p.tel),p.email)!=EOF)
	{	
		if(e.id==p.id)
		b++;
	}
	if(b==0){
	fprintf(f,"%d %s %s %d %d %d %s %d %d %d %s\n",e.id,e.prenom,e.nom,e.d.j,e.d.m,e.d.a,e.bloc,e.chambre,e.n,e.tel,e.email);
	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Etudiant ajouté avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);

	break;
	}
	}
	if(b!=0){
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Etudiant déja existant !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);

	break;
	}
	}
	fclose(f);
}
}

void modifier_hebergement(etudiant e, char *fname){
etudiant p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%d %s %s %d %d %d %s %d %d %d %s\n",&(p.id),p.prenom,p.nom,&(p.d.j),&(p.d.m),&(p.d.a),p.bloc,&(p.chambre),&(p.n),&(p.tel),p.email)!=EOF)
	{
		if(p.id!=e.id)
			fprintf(g,"%d %s %s %d %d %d %s %d %d %d %s\n",p.id,p.prenom,p.nom,p.d.j,p.d.m,p.d.a,p.bloc,p.chambre,p.n,p.tel,p.email);
		else
			fprintf(g,"%d %s %s %d %d %d %s %d %d %d %s\n",p.id,e.prenom,e.nom,p.d.j,p.d.m,p.d.a,e.bloc,e.chambre,e.n,e.tel,e.email);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Etudiant modifié avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

void afficher_hebergement(GtkWidget *liste, char *fname)
{
etudiant p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar date_naissance[50], nom_complet[50], chambre[20];
FILE *f;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",ID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Nom complet", renderer,"text",NOM_COMPLET, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_resizable(column,TRUE);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Date d'hébérgement", renderer,"text",DATE_NAISSANCE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Bloc", renderer,"text",BLOC, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Chambre", renderer,"text",CHAMBRE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Num chambre", renderer,"text",NUM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Tel", renderer,"text",TEL, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Email", renderer,"text",EMAIL, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);


store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);
f=fopen(fname,"r");
if(f!=NULL)

{ f = fopen(fname,"a+");
		while(fscanf(f,"%d %s %s %d %d %d %s %d %d %d %s\n",&(p.id),p.prenom,p.nom,&(p.d.j),&(p.d.m),&(p.d.a),p.bloc,&(p.chambre),&(p.n),&(p.tel),p.email)!=EOF)
	{
sprintf(date_naissance,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
sprintf(chambre,p.chambre==1?"Individuelle":p.chambre==2?"Double":"Triple");
sprintf(nom_complet,"%s %s",p.prenom, p.nom);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,NOM_COMPLET,nom_complet,DATE_NAISSANCE,date_naissance,BLOC,p.bloc,CHAMBRE,chambre,NUM,p.n,TEL,p.tel,EMAIL,p.email,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}

void supprimer_hebergement(etudiant e, char *fname)
{
etudiant p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%d %s %s %d %d %d %s %d %d %d %s\n",&(p.id),p.prenom,p.nom,&(p.d.j),&(p.d.m),&(p.d.a),p.bloc,&(p.chambre),&(p.n),&(p.tel),p.email)!=EOF)
	{
		if(p.id!=e.id)
			fprintf(g,"%d %s %s %d %d %d %s %d %d %d %s\n",p.id,p.prenom,p.nom,p.d.j,p.d.m,p.d.a,p.bloc,p.chambre,p.n,p.tel,p.email);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Etudiant supprimé avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

void afficher_alarme(GtkWidget *liste, char *fname)
{
alarme a;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar date[20], temps[10], type[20];
FILE *f;
time_t t;
time(&t);


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Type", renderer,"text",TYPE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Etage", renderer,"text",ETAGE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_resizable(column,TRUE);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Date", renderer,"text",DATE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Temps", renderer,"text",TEMPS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

store=gtk_list_store_new(COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen(fname,"r");
if(f!=NULL)

{ f = fopen(fname,"a+");
		while(fscanf(f,"%d %s %d %d %d %d %d\n",&(a.type),a.etage,&(a.d.j),&(a.d.m),&(a.d.a),&(a.h),&(a.m))!=EOF)
	{
if(a.h<6&&a.h>=0){
sprintf(type,a.type==0?"Mouvement":"Fumée");
sprintf(date,"%d/%d/%d",a.d.j,a.d.m,a.d.a);
sprintf(temps,"%d:%d",a.h,a.m);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE,type,ETAGE,a.etage,DATE,date,TEMPS,temps,-1);
	}
}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

etudiant chercher_hebergement(int id, char *fname){
etudiant p, e;
FILE *f;
f=fopen(fname,"r");
if(f!=NULL){
	while(fscanf(f,"%d %s %s %d %d %d %s %d %d %d %s\n",&(p.id),p.prenom,p.nom,&(p.d.j),&(p.d.m),&(p.d.a),p.bloc,&(p.chambre),&(p.n),&(p.tel),p.email)!=EOF)
	{
		if(p.id==id)
			return p;
	}
	fclose(f);
}
e.id=-1;
return e;
}
