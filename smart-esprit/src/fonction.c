#include "fonction.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"



GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;

int verif(char log[],char Pw[])
{
int trouve=-1;
FILE *f=NULL;
util t;
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
 while(fscanf(f,"%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Num,t.Cin)!=EOF)
{
if((strcmp(t.User,log)==0)&&(strcmp(t.Pass,Pw)==0))
{
if(strcmp(t.Choix,"Technicien")==0)
trouve=1;
else if(strcmp(t.Choix,"Agent_Foyer")==0)
trouve=2;
else if(strcmp(t.Choix,"Agent_Restaurant")==0)
trouve=3;
else if(strcmp(t.Choix,"Admin")==0)
trouve=4;
else if(strcmp(t.Choix,"Etudiant")==0)
trouve=5;
else if(strcmp(t.Choix,"Agent_Evenement")==0)
trouve=6;

}

}
fclose(f);
}
return (trouve);
}

void ajouter(util t)
{
    FILE *f=NULL;

f=fopen("utilisateur.txt","a");
if(f!=NULL)
{

    fprintf(f,"%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Num,t.Cin);
    fclose(f);
    

}


}

void affi_listUser(GtkWidget* treeviewAffiListUser,char*l)
{
FILE *F;


char Nom[20];
char Prenom[20];
char User[20];
char Pass[20];
char Choix[20];
char Num[20];
char Cin[20];


        /* Creation du modele */
        adstore = gtk_list_store_new(7,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,			
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING
                                     		);
        /* Insertion des elements */
        F=fopen(l,"r");
while(fscanf(F,"%s %s %s %s %s %s %s \n",Nom,Prenom,User,Pass,Choix,Num,Cin)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,Nom,
                            1,Prenom,	
                            2,User,
                            3,Pass,
                            4,Choix,
                            5,Num,
                            6,Cin,
                            -1);}
        fclose(F);

	/* Creation de la 1ere colonne */

	{
	
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Nom",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Prenom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("User",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);
       

       /* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("password",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);


            /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("choix",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);



           /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NUMTL",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Cin",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewAffiListUser), adcolumn);

	

	}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeviewAffiListUser),
                                  GTK_TREE_MODEL(adstore)  );

}

void supp_tree(char Cin[])
{

   FILE *F,*FW;
  util t;
  
F = fopen ("utilisateur.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {
  while (fscanf (F,"%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Num,t.Cin) != EOF)
    if (strcmp (t.Cin,Cin) != 0)
      fprintf (FW,"%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Num,t.Cin);
  fclose (F);
  fclose (FW);
remove("utilisateur.txt");
rename("tr.txt", "utilisateur.txt");
}
}

util chercher_util(char id[]){
util q, o;
FILE *f;
f=fopen("utilisateur.txt","r");
if(f!=NULL){

	while(fscanf(f,"%s %s %s %s %s %s %s \n",q.Nom,q.Prenom,q.User,q.Pass,q.Choix,q.Num,q.Cin)!=EOF)
	
	if(strcmp(q.Cin,id)==0){

	strcpy(o.Nom,q.Nom);
        strcpy(o.Prenom,q.Prenom);
        strcpy(o.User,q.User);
	strcpy(o.Pass,q.Pass);
	strcpy(o.Choix,q.Choix);
	strcpy(o.Num,q.Num);
	strcpy(o.Cin,q.Cin);

	}
	return o;
	fclose(f);
}
}





void modi_tree(char Cin[],util o)
{


  util t;
  
   FILE *F, *FW;
  
  
F = fopen ("utilisateur.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {


  while (fscanf (F, "%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Num,t.Cin) != EOF)
    if (strcmp (t.Cin,Cin) == 0)
     {
fprintf (FW, "%s %s %s %s %s %s %s\n",o.Nom,o.Prenom,o.User,o.Pass,o.Choix,o.Num,Cin);

     }
     else
     {
       fprintf (FW, "%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Num,t.Cin);
     }
     

     
     

  fclose (F);
  fclose (FW);
remove("utilisateur.txt");
rename("tr.txt", "utilisateur.txt");

}


}



void afficherListEtudiant(GtkWidget* treeview1)
{
FILE *F;

niveaux A ;



        /* Creation du modele */
        adstore = gtk_list_store_new(5,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,			
                                     G_TYPE_STRING,
                                     G_TYPE_STRING
                                     		);
        /* Insertion des elements */
        F=fopen("niveaux.txt","r");
while(fscanf(F,"%s %s %s %s %s \n",A.id,A.niveau,A.vaccin,A.sexe,A.abonement)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,A.id,
                            1,A.niveau,	
                            2,A.vaccin,
                            3,A.sexe,
                            4,A.abonement,
                            -1);}
        fclose(F);

	/* Creation de la 1ere colonne */

	{
	
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("id",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("niveau",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("vaccin",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
       

       /* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("sexe",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


            /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("abonement",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




	}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}

void ajouterE(niveaux A)

{
FILE *f;
f=fopen("niveaux.txt","a+");
	if(f!=NULL)
	{
	 fprintf(f," %s %s %s %s %s \n",A.id,A.niveau,A.vaccin,A.sexe,A.abonement);
	 fclose(f);
	}


}



