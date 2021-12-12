#ifdef HAVE_CONFIG_H
#  include<config.h>
#endif



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "capteur.h"
#include <gtk/gtk.h>
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
int h ;






enum
{
      ENOM,
      EMARQUE,
      EREFERENCE,
      ETYPE,
      EMIN,
      EMAX,
      COLUMNS,
};



void ajouter_capteur(capteur c)
{
FILE* f;
f=fopen("fichier.txt","a+");
if(f!=NULL)
  { fprintf(f,"%s %s %s %s %d %d\n",c.nom,c.marque,c.reference,c.type,c.min,c.max);}
fclose(f);

}


void afficher_capteur(GtkWidget* treeview1,char*l)
{
GtkListStore *store;
capteur c;
store=NULL;
store=gtk_tree_view_get_model(treeview1);
        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %d %d\n",c.nom,c.marque,c.reference,c.type,&c.min,&c.max)!=EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,c.nom,
                            1,c.marque,
                            2,c.reference,
			    3,c.type,
                            4,c.min,
                            5,c.max,-1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(store==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MARQUE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("REFERENCE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
        /* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
        /* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MIN",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	

        /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MAX",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
        /* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}









void supprimer_capteur(char *reference)
{

FILE*f=NULL;
FILE*f1=NULL;
capteur c ;
f=fopen("fichier.txt","r");
f1=fopen("ancien.txt","w+");//mode lecture et ecriture 
while(fscanf(f,"%s %s %s %s %d %d\n",c.nom,c.marque,c.reference,c.type,&c.min,&c.max)!=EOF){
if(strcmp(reference,c.reference)!=0)fprintf(f1,"%s %s %s %s %d %d\n",c.nom,c.marque,c.reference,c.type,c.min,c.max);
}
fclose(f);
fclose(f1);
remove("fichier.txt");
rename("ancien.txt","fichier.txt");
}




int Cherchercapteur(GtkWidget* treeview1,char l[] ,char reference[])
{
GtkListStore *adstore ;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn ;/*visualisation des colonnes*/
GtkCellRenderer *cellad ;/*afficheur de cellule(text,image..)*/
FILE *f ;
capteur c ;
int nb=0;

        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %d %d\n",c.nom,c.marque,c.reference,c.type,&c.min,&c.max)!=EOF)
        {
	if( strcmp(reference,c.reference)==0){ nb++;
	GtkTreeIter pIter;
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,c.nom,
                            1,c.marque,
                            2,c.reference,
			    3,c.type,
                            4,c.min,
                            5,c.max,
                            -1);}
}
        fclose(f);

	/* Creation de la 1ere colonne */

	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MARQUE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("REFERENCE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MIN",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);

	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MAX",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}

///****************************************************************************************************************///
void modifier_capteur(capteur c){
FILE*f=NULL;
FILE*f1=NULL;
capteur ca ;
f=fopen("fichier.txt","r");
f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %d %d \n",ca.nom,ca.marque,ca.reference,ca.type,&ca.min,&ca.max)!=EOF){
if( strcmp(c.reference,ca.reference)==0)
{
fprintf(f1,"%s %s %s %s %d %d \n",c.nom,c.marque,c.reference,c.type,c.min,c.max);
}
else
{
fprintf(f1,"%s %s %s %s %d %d \n",ca.nom,ca.marque,ca.reference,ca.type,ca.min,ca.max);
}

}
fclose(f);
fclose(f1);
remove("fichier.txt");
rename("ancien.txt","fichier.txt");
}

/////////*****************************************************************/////
int chercher_c(GtkWidget* treeview2,char*l)
{

capteur c;
int nb=0;
float min=0;
float max=44;
        /* Creation du modele */
        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_FLOAT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %d %d %d %f\n",c.reference,&c.dt.jour,&c.dt.mois,&c.dt.annee,&c.valeur)!=EOF)
        {
if(c.valeur>=max || c.valeur<=min){nb++;
GtkTreeIter pIter;
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,c.reference,
                            1,c.dt.jour,
                            2,c.dt.mois,
                            3,c.dt.annee,
                            4,c.valeur,-1);}
}
        fclose(f);

/* Creation de la 1ere colonne */
if(h==0)
{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Reference",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);



/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Jour",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
/* Ajouter la 4emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Mois",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
/* Ajouter la 5emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

        /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Annee",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
/* Ajouter la 6emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);    
       
         /* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Valeur",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
/* Ajouter la 7emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);  

h++;}


  gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview2),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}
