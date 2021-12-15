
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "event.h"
#include <string.h>
#include <time.h>

#include <stdio.h>



void ajouter_nb(eve A)
{
    FILE *F=NULL;

F=fopen("event.txt","a");
if(F!=NULL)
{

    fprintf(F,"%s %s %s %s %s %d\n",A.id,A.lieu,A.event,A.ing,A. date,A.nb);
    fclose(F);
    

}

}
void supp_nb(char id[])
{
  
   FILE *F, *FW;
  eve D ;
  
F = fopen ("event.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {


  while (fscanf (F, "%s %s %s %s %s %d ",D.id,D.lieu,D.event,D.ing,D. date,&D.nb) == 6)
    if (strcmp (D.id, id) != 0)
      fprintf (FW, "%s %s %s %s %s %d \n", D.id,D.lieu,D.event,D.ing,D. date,D.nb);
}
  fclose (F);
  fclose (FW);
remove("event.txt");
rename("tr.txt", "event.txt");




}
eve rech_nb(char id[])
{
char ch;
FILE *F;
  eve Q;
  eve A;
  
F = fopen ("event.txt", "r");


  if (F!=NULL)
{
  while (fscanf (F, "%s %s %s %s %s %d ", Q.id,Q.lieu,Q.event,Q.ing,Q. date, &Q.nb) != EOF)
    if (strcmp (Q.id, id) == 0)
        {
        strcpy(A.lieu,Q.lieu);
        strcpy(A.event,Q.event);
        strcpy(A.ing,Q.ing);
        strcpy(A.date,Q.date);
	
        }

  }
  return (A);
  fclose (F);  
}



void modi_nb(char id [] , eve U) 
{
   FILE *F, *FW;
  eve c; 
  
F = fopen ("event.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL)) 
{
  while (fscanf (F, "%s %s  %s %s %s %d",c.id,c.lieu,c.event,c.ing,c. date,&c.nb) ==6)
	
    if (strcmp (c.id, id) == 0)
     {

fprintf (FW, "%s %s %s %s %s %d\n",id,U.lieu,U.event,U.ing,U. date,U.nb);

     }
     else
     {

       fprintf (FW, "%s %s %s %s %s %d \n", c.id,c.lieu,c.event,c.ing,c. date,c.nb);
     }
}    

  fclose (F);
  fclose (FW);
remove("event.txt");
rename("tr.txt", "event.txt");

}
void afficher_nb (GtkWidget *treeview1, char*l )

{
GtkListStore *adstore;/*creation du modele de lieu liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;


	char id[30];
	char lieu[30];
	char nb[30];
	char event[30];
	char ing[30];
	char date[30];


        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s \n",id,lieu,event,ing,date,nb)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,lieu,
                            2,event,
                            3,ing,
                            4,date,
			    5,nb,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Nom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Association",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Lieu",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NBre personnes",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);

	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}
