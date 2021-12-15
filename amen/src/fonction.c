#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fonction.h"




capteur T[5000];
int n=0;




enum
{
	EID,
	ETYPE,
	EPOSITION,
	EETAT,
	EVALEUR,
	COLUMNS,
};

void afficher(GtkWidget* liste){

	int i;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", EID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("TYPE", renderer, "text", ETYPE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("POSITION", renderer, "text", EPOSITION, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ETAT", renderer, "text", EETAT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("VALEUR", renderer, "text", EVALEUR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	for(i=0;i<n;i++)
	{
	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store, &iter, EID, T[i].id, ETYPE, T[i].type, EPOSITION, T[i].position, EETAT, T[i].etat, EVALEUR, T[i].valeur,-1);
	}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}

void afftrouver(GtkWidget* liste, int i){



	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", EID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("TYPE", renderer, "text", ETYPE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("POSITION", renderer, "text", EPOSITION, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ETAT", renderer, "text", EETAT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("VALEUR", renderer, "text", EVALEUR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();

	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store, &iter, EID, T[i].id, ETYPE, T[i].type, EPOSITION, T[i].position, EETAT, T[i].etat, EVALEUR, T[i].valeur,-1);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}

void viderliste(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", EID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("TYPE", renderer, "text", ETYPE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("POSITION", renderer, "text", EPOSITION, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ETAT", renderer, "text", EETAT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("VALEUR", renderer, "text", EVALEUR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	

	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		gtk_list_store_append(store, &iter);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
}


int nospace(char s[])
{
int i=0;
  do{
    if(s[i]==' '){return 0;}
    i++;
  }while (s[i]!='\0') ;
  return 1;
}

void ajout(capteur x){
    T[n]=x;
    n++;
}




int isalphabet(char t[]){
  int i=0,k;
  do{
    k=t[i];
    if(((k<97)||(k>122))&&((k<65)||(k>90))){return 0;}
    i++;
  }while (t[i]!='\0') ;
  return 1;
}

int isid (char t[]){
  int i=0;
  for(i=0;i<n;i++)
  {
      if(strcmp(t,T[i].id)==0)
      {
          return i;
      }
  }
  return -1;
}

int isint(char t[])
{
    int i=0;
  while (t[i]!='\0'){
    if((t[i]<'0')||(t[i]>'9')){printf("%d not integer\n",i);return 0;}
    i++;
  }
  return 1;
}

int supprimer(char id[])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(strcmp(id,T[i].id)==0)
        {
            for(j=i;j<n;j++)
            {
                T[j]=T[j+1];


            }
            n--; return 1;
        }
    }
    return 0;
}



int modifier( capteur x)
{
	char temp[30];
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(x.id,T[i].id)==0)
        {
	T[i]=x;
            return 1;
        }
    }
    return 0;
}





int filesave()
{
    int i;
    FILE *f;
    f=fopen("capteur.txt","w+");
    if(f==NULL){ return 0;}
    for(i=0;i<n;i++)
    {
        fprintf(f,"%s %s %s %s %s\n",T[i].id,T[i].type,T[i].position,T[i].etat,T[i].valeur);
    }
    fclose(f);
    return 1;

}
int fileload()
{
    n=0;
    FILE *f=NULL;
    f=fopen("capteur.txt","r+");
    if(f==NULL){ return 0;}
    while(fscanf(f,"%s %s %s %s %s\n",T[n].id,T[n].type,T[n].position,T[n].etat,T[n].valeur)!=EOF){
        n++;
    }
    fclose(f);
    return 1;

}
