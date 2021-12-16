
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdlib.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"
#include <stdio.h>
#include <string.h>
#include <time.h>







GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *F;

void affi_ch(GtkWidget* treeview1,char*l)
{

char id[20];
char NOM[20];
char Prenom[20];
char resp[20];
char jour[20];
char messageRecla[20];
char sui[20];
char CIN[20];
char mois[20];
char annee[20];


        /* Creation du modele */
        adstore = gtk_list_store_new(10,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,			
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        F=fopen(l,"r");
while(fscanf(F,"%s %s %s %s %s %s %s %s %s %s \n",id,NOM,Prenom,resp,CIN,messageRecla,jour,mois,annee,sui)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,NOM,
			    2,Prenom,	
                            3,CIN,
                            4,resp,
                            5,messageRecla,
                            6,jour,
                            7,mois,
                            8,annee,
                            9,sui,
                            -1);}
        fclose(F);

	/* Creation de la 1ere colonne */
if(m==0)
	{cellad = gtk_cell_renderer_text_new();
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

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Prenom",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
       



            /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CIN",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

   	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Service",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



           /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Message",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Jour",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Mois",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        /* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Annee",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        /* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Suivie",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);
	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	m++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}



void affi_ad_ch(GtkWidget* treeview1,char*l)
{

char id[20];
char NOM[20];
char Prenom[20];
char resp[20];
char jour[20];
char messageRecla[20];
char sui[20];
char CIN[20];
char mois[20];
char annee[20];


        /* Creation du modele */
        adstore = gtk_list_store_new(10,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,			
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        F=fopen(l,"r");
while(fscanf(F,"%s %s %s %s %s %s %s %s %s %s \n",id,NOM,Prenom,CIN,resp,messageRecla,jour,mois,annee,sui)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,NOM,
			    2,Prenom,	
                            3,CIN,
                            4,resp,
                            5,messageRecla,
                            6,jour,
                            7,mois,
                            8,annee,
                            9,sui,
                            -1);}
        fclose(F);

	/* Creation de la 1ere colonne */
if(k==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PRENOM",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



           /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CIN",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
       

       /* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Service",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



           /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Message",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MOIS",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        /* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ANNEE",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        /* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Suivie",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);
	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	k++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}













void Ajouter_ch(reclamation o)
{
    FILE *F=NULL;

F=fopen("reclamation.txt","a");
if(F!=NULL)
{

    fprintf(F,"%s %s %s %s %s %s %d %d %d %s \n",o.id,o.NOM,o.Prenom,o.CIN,o.resp,o.messageRecla,o.dt_ns.jour,o.dt_ns.mois,o.dt_ns.annee,      o.sui);
    fclose(F);
    

}
}
void supp_ch(char id[])
{

   FILE *F,*FW;
  reclamation o;
  
F = fopen ("reclamation.txt", "r");
FW = fopen ("or.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {
  while (fscanf (F,"%s %s %s %s %s %s %d %d %d %s \n",o.id,o.NOM,o.Prenom,o.CIN,o.resp,o.messageRecla,&o.dt_ns.jour,&o.dt_ns.mois,&o.dt_ns.annee,o.sui) != EOF)
    if (strcmp (o.id,id) != 0)
      fprintf (FW,"%s %s %s %s %s %s %d %d %d %s \n",o.id,o.NOM,o.Prenom,o.CIN,o.resp,o.messageRecla,o.dt_ns.jour,o.dt_ns.mois,o.dt_ns.annee,   o.sui);
  fclose (F);
  fclose (FW);
remove("reclamation.txt");
rename("or.txt", "reclamation.txt");
}


}

void modi_ch(char id[],reclamation o)
{


  reclamation c;
  
   FILE *F, *FW;
  
  
F = fopen ("reclamation.txt", "r");
FW = fopen ("or.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {


  while (fscanf (F, "%s %s %s %s %s %s %d %d %d %s\n",c.id,c.NOM,c.Prenom,c.CIN,c.resp,c.messageRecla,&c.dt_ns.jour,&c.dt_ns.mois,&c.dt_ns.annee, c.sui)!=EOF)
    if (strcmp (c.id, id) == 0)
     {
fprintf (FW, "%s %s %s %s %s %s %d %d %d %s\n",id,o.NOM,o.Prenom,o.CIN,o.resp,o.messageRecla,o.dt_ns.jour,o.dt_ns.mois,o.dt_ns.annee,o.sui);

     }
     else
     {
       fprintf (FW, "%s %s %s %s %s %s %d %d %d %s\n", c.id,c.NOM,c.Prenom,c.CIN,c.resp,c.messageRecla,c.dt_ns.jour,c.dt_ns.mois,c.dt_ns.annee,c.sui);
     }
     

     
     

  fclose (F);
  fclose (FW);
remove("reclamation.txt");
rename("or.txt", "reclamation.txt");

}


}







reclamation rechercher_reclamation(char id[])
{

FILE *F;
  reclamation q;
  reclamation o;
F = fopen ("reclamation.txt", "r");


  if (F!=NULL)
 {


    while (fscanf (F, "%s %s %s %s %s %s %d %d %d %s \n",q.id,q.NOM,q.Prenom,q.CIN,q.resp,q.messageRecla,&o.dt_ns.jour,&o.dt_ns.mois,&o.dt_ns.annee, q.sui)!=EOF)
    if (strcmp (q.id, id) == 0)
	{
        
	strcpy(o.NOM,q.NOM);
        strcpy(o.Prenom,q.Prenom);
        strcpy(o.resp,q.resp);
	strcpy(o.CIN,q.CIN);
	strcpy(o.sui,q.sui);
	strcpy(o.messageRecla,q.messageRecla);
        
    }
    
      return(o);

  fclose (F);
 }
}

