#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"fonction.h"
#include<gtk/gtk.h>
enum
{	
	REF,
	NAME,
	TYPE,
	QUANT,
	ETAT,
	COLUMNS};
enum
{
	HISTORY,
	COLUMN};
enum
{	
	REFS,
	NAMES,
	TYPES,
	QUANTS,
	ETATS,
	COLUMNSS};


//////////////////////////////////////////////////////////////////////////////////////////////////
void addproduct(product p){
FILE* f=NULL;
FILE* t=NULL;
char buffer[500];
f=fopen("product.txt","a+");
fprintf(f,"%s %s %s %f %s\n",p.ref,p.name,p.type,p.quant,p.etat);
fclose(f);
t=fopen("historique.txt","a+");
time_t timer;
    time(&timer);
    sprintf(buffer,"un_ajout_du_produit_%s_a_ete_fait_a:%s",p.name,ctime(&timer)); 
    fprintf(t,"%s\n",buffer); 
fclose(t);   
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void affichage(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char ref [30];
	char name [30];
	char type[30];
	float quant ;
	char etat [30];
	store=NULL;

    FILE *f;

    store=gtk_tree_view_get_model(liste);
    if(store==NULL)
    {
    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",REF,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NAME,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANT,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    store=gtk_list_store_new (COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_STRING);
    f=fopen("product.txt","r");
    if(f==NULL)
    {
        return;
    }
    else
    {f=fopen("product.txt","a+");
            while(fscanf(f,"%s %s %s %f %s\n",ref,name,type,&quant,etat)!=EOF)
	    {
	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store,&iter,REF,ref,NAME,name,TYPE,type,QUANT,quant,ETAT,etat,-1);
	    }
        fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
    g_object_unref(store);
    }
}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void vider(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char ref [30];
	char name [30];
	char type[30];
	float quant ;
	char etat [30];
	store=NULL;

    FILE* f;

    store=gtk_tree_view_get_model(liste);
    if(store==NULL)
    {
    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",REFS,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NAMES,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPES,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANTS,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETATS,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
    }
    store=gtk_list_store_new (COLUMNSS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_STRING);
    gtk_list_store_append(store, &iter);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deleteproduct(char name[] ){



FILE*f=NULL;
FILE*f1=NULL;
FILE* t=NULL;
product p ;
char buffer[200];
f=fopen("product.txt","r");
f1=fopen("temp.txt","w+");
while(fscanf(f,"%s %s %s %f %s\n",p.ref,p.name,p.type,&p.quant,p.etat)!=EOF){
if(strcmp(name,p.name)!=0)fprintf(f1,"%s %s %s %f %s\n",p.ref,p.name,p.type,p.quant,p.etat);
}
fclose(f);
fclose(f1);
remove("product.txt");
rename("temp.txt","product.txt");
t=fopen("historique.txt","a+");
time_t timer;
    time(&timer);
    sprintf(buffer,"une_suppression_du_produit_%s_a_ete_faite_a:%s",name,ctime(&timer)); 
    fprintf(t,"%s\n",buffer); 
fclose(t);   

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int searchproduct(char  name[]){
FILE*f=NULL;
product p;
int i;
f=fopen("product.txt","r");
while(fscanf(f,"%s %s %s %f %s \n",p.ref,p.name,p.type,&p.quant,p.etat)!=EOF)
{
if(strcmp(name,p.name)==0)
{i=1;
fclose(f);
return i;}
}
fclose(f);
i=0;
return i;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







void affichagehis(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char history[200];
	store=NULL;

    FILE* g;

    store=gtk_tree_view_get_model(liste);
    if(store==NULL)
    {
    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("history",renderer,"text",HISTORY,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    

    store=gtk_list_store_new (COLUMN,G_TYPE_STRING);
    
    
    g=fopen("historique.txt","a+");
            while(fscanf(g,"%s",history)!=EOF)
	    {
	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store,&iter,HISTORY,history,-1);
	    }
    fclose(g);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
    g_object_unref(store);
   } 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


void updateproduct(product q){

char buffer[500];
FILE*f=NULL;
FILE*f1=NULL;
FILE* t=NULL;
product p ;

f=fopen("product.txt","r");

f1=fopen("temp.txt","w+");
while(fscanf(f,"%s %s %s %f %s\n",p.ref,p.name,p.type,&p.quant,p.etat)!=EOF){
if( strcmp(p.name,q.name)!=0)

fprintf(f1,"%s %s %s %f %s \n",p.ref,p.name,p.type,p.quant,p.etat);

else

fprintf(f1,"%s %s %s %f %s \n",q.ref,p.name,q.type,q.quant,q.etat);


}

fclose(f);
fclose(f1);

remove("product.txt");
rename("temp.txt","product.txt");
t=fopen("historique.txt","a+");
time_t timer;
    time(&timer);
    sprintf(buffer,"une_modification_du_produit_%s_a_ete_fait_a:%s",q.name,ctime(&timer)); 
    fprintf(t,"%s\n",buffer); 
fclose(t);   
}

//////////////////////////////////////////////////////////////////////////////////////////////



void commander()    
{  
    char *URL;   
    URL = "xdg-open http://google.com";
    system(URL);   
    
}

////////////////////////////////////////////////////////////////////////////////////////////////

void rupture(){
FILE*f=NULL;
FILE*f1=NULL;
FILE* rup=NULL;
product p;
rup=fopen("rupture.txt","a+");
fclose(rup);
f=fopen("product.txt","r");
f1=fopen("placement.txt","w+");

while(fscanf(f,"%s %s %s %f %s\n",p.ref,p.name,p.type,&p.quant,p.etat)!=EOF){
if( strcmp(p.etat,"EPUISE")==0)
{
fprintf(f1,"%s %s %s %f %s \n",p.ref,p.name,p.type,p.quant,p.etat);
}}
fclose(f);
fclose(f1);

remove("rupture.txt");
rename("placement.txt","rupture.txt");




}
////////////////////////////////////////////////////////////////////////////////////////////////
void affichagerup(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char ref [30];
	char name [30];
	char type[30];
	float quant ;
	char etat [30];
	store=NULL;

    FILE *f;

    store=gtk_tree_view_get_model(liste);
    if(store==NULL)
    {
    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",REF,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NAME,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANT,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    store=gtk_list_store_new (COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_STRING);
    f=fopen("rupture.txt","r");
    if(f==NULL)
    {
        return;
    }
    else
    {f=fopen("rupture.txt","a+");
            while(fscanf(f,"%s %s %s %f %s\n",ref,name,type,&quant,etat)!=EOF)
	    {
	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store,&iter,REF,ref,NAME,name,TYPE,type,QUANT,quant,ETAT,etat,-1);
	    }
        fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
    g_object_unref(store);
    }
}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void resetcommand(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char ref [30];
	char name [30];
	char type[30];
	float quant ;
	char etat [30];
	store=NULL;

    FILE *f;

    store=gtk_tree_view_get_model(liste);
    if(store==NULL)
    {
    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",REF,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NAME,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANT,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

    store=gtk_list_store_new (COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_STRING);
    f=fopen("reset.txt","r");
    if(f==NULL)
    {
        return;
    }
    else
    {f=fopen("reset.txt","a+");
            while(fscanf(f,"%s %s %s %f %s\n",ref,name,type,&quant,etat)!=EOF)
	    {
	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store,&iter,REF,ref,NAME,name,TYPE,type,QUANT,quant,ETAT,etat,-1);
	    }
        fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
    g_object_unref(store);
    }
}}




