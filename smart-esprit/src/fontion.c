#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fontion.h"
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "support.h"

nut n;
enum
{
	EID1,
	EREPAS1,
	EMENU1,
	EPLATS1,
	EPLATPRINCIPAL1,
	EDESSERT1,
	EBOISSON1,
	EENTREE1,
	EJOUR1,
	EMOIS1,
	EANNEE1,
	COLUMNS1
};
enum
{
	EID,
	EREPAS,
	EMENU,
	EPLATS,
	EPLATPRINCIPAL,
	EDESSERT,
	EBOISSON,
	EENTREE,
	EJOUR,
	EMOIS,
	EANNEE,
	COLUMNS
};

void ajoutr(nut n)
{
    FILE* f=NULL;
    f=fopen("nutrition.txt","a+");    
    fprintf(f,"%s %s %s %s %s %s %s %s %d %d %d\n",n.id,n.repas,n.menu,n.plats,n.platprincipal,n.dessert,n.boisson,n.entree,n.d.jour,n.d.mois,n.d.annee  );
    fclose(f); 

    
}
void afficher_menu(GtkWidget *liste )
{	nut n;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	FILE *f;

	
	store=NULL;
	
	store=gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
	

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("repas",renderer,"text",EREPAS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	
	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("menu",renderer,"text",EMENU,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	
	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("plats",renderer,"text",EPLATS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
	

	
	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("Plat principal",renderer,"text",EPLATPRINCIPAL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("dessert",renderer,"text",EDESSERT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("boisson",renderer,"text",EBOISSON,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("entrée",renderer,"text",EENTREE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("jour",renderer,"text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("mois",renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("annee",renderer,"text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
		
	
	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);	

	f=fopen("nutrition.txt","r");
	if(f==NULL)
	
		printf("erreur ");
	
	else
	{
	f=fopen("nutrition.txt","a+");
	while((fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d",n.id,n.repas,n.menu,n.plats,n.platprincipal,n.dessert,n.boisson,n.entree,&n.d.jour,&n.d.mois,&n.d.annee ))!=EOF)
	{
	
		
		gtk_list_store_append (store,&iter);
		gtk_list_store_set (store,&iter,EID,n.id,EREPAS,n.repas,EPLATS,n.plats,EMENU,n.menu,EPLATPRINCIPAL,n.platprincipal,EDESSERT,n.dessert,EBOISSON,n.boisson,EENTREE,n.entree,EJOUR,n.d.jour,EMOIS,n.d.mois,EANNEE,n.d.annee,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	
}
}
}


void actu(GtkWidget *liste )

{

nut n;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	FILE *f;
	store=NULL;
	
	store=gtk_tree_view_get_model(liste);

	if(store==NULL)
	{
	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
	

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("repas",renderer,"text",EREPAS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	
	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("menu",renderer,"text",EMENU,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	
	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("plats",renderer,"text",EPLATS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
	

	
	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("Plat principal",renderer,"text",EPLATPRINCIPAL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("dessert",renderer,"text",EDESSERT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("boisson",renderer,"text",EBOISSON,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("entée",renderer,"text",EENTREE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("jour",renderer,"text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("mois",renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes ("annee",renderer,"text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

}

store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
//g_object_unref(store);
}




//supprimer

void supprimr (char id[]){
FILE*f=NULL;
FILE*f1=NULL;
f=fopen("nutrition.txt","r");
f1=fopen("ancien.txt","w+");
while(fscanf(f," %s %s %s %s %s %s %s %s %d %d %d ",n.id,n.repas,n.menu,n.plats,n.platprincipal,n.dessert,n.boisson,n.entree,&n.d.jour,&n.d.mois,&n.d.annee)!=EOF){
if(strcmp(id,n.id)!=0 )
fprintf(f1," %s %s %s %s %s %s %s %s %d %d %d \n ",n.id,n.repas,n.menu,n.plats,n.platprincipal,n.dessert,n.boisson,n.entree,n.d.jour,n.d.mois,n.d.annee);
}
fclose(f);
fclose(f1);
remove("nutrition.txt");
rename("ancien.txt","nutrition.txt");
}


//modifier

void modifir(char id[], nut n1 )
{ 
nut n;
FILE *f=NULL;
FILE*f1=NULL;
f=fopen("nutrition.txt","r");
f1=fopen("ancien.txt","w");
if (f!=NULL)
{
while (fscanf(f," %s %s %s %s %s %s %s %s %d %d %d",n.id,n.repas,n.menu,n.plats,n.platprincipal,n.dessert,n.boisson,n.entree,&n.d.jour,&n.d.mois,&n.d.annee)==11)

if (strcmp(id,n.id)==0)
{
fprintf(f1," %s %s %s %s %s %s %s %s %d %d %d\n",id,n.repas,n.menu,n1.plats,n1.platprincipal,n1.dessert,n1.boisson,n1.entree,n.d.jour,n.d.mois,n.d.annee) ;
}
else
{       
fprintf(f1," %s %s %s %s %s %s %s %s %d %d %d\n",n.id,n.repas,n.menu,n.plats,n.platprincipal,n.dessert,n.boisson,n.entree,n.d.jour,n.d.mois,n.d.annee);
}
}

fclose(f);
fclose(f1);
remove("nutrition.txt");
rename("ancien.txt","nutrition.txt");
}


//verif
int verf(char id[])
{
    int test=0;
    FILE*f=NULL;
    nut n ;
    f=fopen("nutrition.txt","r");
    while ((fscanf(f," %s %s %s %s %s %s %s %s %d %d %d ",n.id,n.repas,n.menu,n.plats,n.platprincipal,n.dessert,n.boisson,n.entree,&n.d.jour,&n.d.mois,&n.d.annee )!=EOF)&&(test==0)){
            if(strcmp(id,n.id)==0)
            {
                test=1;
            }

    }
    return test;
}



//chercher
void cherchr(char repas[],nut n){
FILE*f=NULL;
FILE* f1=NULL;
char plats[20];
remove("repas.txt");
f=fopen("nutrition.txt","r");
f1=fopen("repas.txt","a+"); 
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d",n.id,n.repas,n.menu,n.plats,n.platprincipal,n.dessert,n.boisson,n.entree,&n.d.jour,&n.d.mois,&n.d.annee)!=EOF){
if(strcmp(repas,n.repas)==0)
fprintf(f1,"%s %s %s %s %s %s %s %s %d %d %d\n",n.id,n.repas,n.menu,n.plats,n.platprincipal,n.dessert,n.boisson,n.entree,n.d.jour,n.d.mois,n.d.annee);
}
}
fclose(f1);
fclose(f);
}

void afficher_repas(GtkWidget *liste )
{	nut n;
	GtkCellRenderer *renderer1;
	GtkTreeViewColumn *column1;
	GtkTreeIter iter1;
	GtkListStore *store1;
	FILE *f ;

	store1=NULL;
	
	store1=gtk_tree_view_get_model(liste);

	if(store1==NULL)
	{
	renderer1=gtk_cell_renderer_text_new ();
	column1=gtk_tree_view_column_new_with_attributes ("id",renderer1,"text",EID1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column1);
	

	renderer1=gtk_cell_renderer_text_new ();
	column1=gtk_tree_view_column_new_with_attributes ("repas",renderer1,"text",EREPAS1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column1);

	
	renderer1=gtk_cell_renderer_text_new ();
	column1=gtk_tree_view_column_new_with_attributes ("menu",renderer1,"text",EMENU1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column1);

	
	renderer1=gtk_cell_renderer_text_new ();
	column1=gtk_tree_view_column_new_with_attributes ("plats",renderer1,"text",EPLATS1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column1);
	

	
	renderer1=gtk_cell_renderer_text_new ();
	column1=gtk_tree_view_column_new_with_attributes ("Plat principal",renderer1,"text",EPLATPRINCIPAL1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column1);


	renderer1=gtk_cell_renderer_text_new ();
	column1=gtk_tree_view_column_new_with_attributes ("dessert",renderer1,"text",EDESSERT1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column1);


	renderer1=gtk_cell_renderer_text_new ();
	column1=gtk_tree_view_column_new_with_attributes ("boisson",renderer1,"text",EBOISSON1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column1);

	renderer1=gtk_cell_renderer_text_new ();
	column1=gtk_tree_view_column_new_with_attributes ("entrée",renderer1,"text",EENTREE1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column1);

	renderer1=gtk_cell_renderer_text_new ();
	column1=gtk_tree_view_column_new_with_attributes ("jour",renderer1,"text",EJOUR1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column1);

	renderer1=gtk_cell_renderer_text_new ();
	column1=gtk_tree_view_column_new_with_attributes ("mois",renderer1,"text",EMOIS1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column1);

	renderer1=gtk_cell_renderer_text_new ();
	column1=gtk_tree_view_column_new_with_attributes ("annee",renderer1,"text",EANNEE1,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column1);
		
	
	store1=gtk_list_store_new (COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);	

	f=fopen("repas.txt","r");
	if(f==NULL)
	
		printf("erreur ");
	
	else
	{
	f=fopen("repas.txt","a+");
	while((fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d",n.id,n.repas,n.menu,n.plats,n.platprincipal,n.dessert,n.boisson,n.entree,&n.d.jour,&n.d.mois,&n.d.annee ))!=EOF)
	{
	
		
		gtk_list_store_append (store1,&iter1);
		gtk_list_store_set (store1,&iter1,EID1,n.id,EREPAS1,n.repas,EPLATS1,n.plats,EMENU1,n.menu,EPLATPRINCIPAL1,n.platprincipal,EDESSERT1,n.dessert,EBOISSON1,n.boisson,EENTREE1,n.entree,EJOUR1,n.d.jour,EMOIS1,n.d.mois,EANNEE1,n.d.annee,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store1));
	g_object_unref(store1);
	
}
}
}


/*int controle(char ch[])

{
int len,i=0,x,test=0;
len = strlen(ch);

for(i=0;i<len;i++)
{
    if(isdigit(ch[i])==0)
    {
        test=1;
    }

}
return test;

}


*/


