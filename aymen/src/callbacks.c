#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
product p;

int z=1;
int w=1;
int m=1;
void
on_buttonaddresto_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{product p;


GtkWidget *nom, *ref, *quant, *type, *msg,*check;
nom=lookup_widget(button,"entrynomadd");
ref=lookup_widget(button,"entryrefadd");
quant=lookup_widget(button,"spinquantadd");
type=lookup_widget(button,"comboboxtypeadd");
msg=lookup_widget(button,"msgadd");
check=lookup_widget(button,"checkbuttonresto");
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
on_radioenstock_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
z=1;
}


void
on_radioepuise_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
z=2;
}


void
on_buttondisplayresto_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *treeview1;


treeview1=lookup_widget(button,"treeview99");
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

treeview1=lookup_widget(agentresto,"treeview99");
affichage(treeview1);

}


void
on_treeview99_row_activated            (GtkTreeView     *treeview,
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
noma=lookup_widget(button,"searchrestoentry");
msgg=lookup_widget(button,"test");
ref=lookup_widget(button,"entryeditref");
typee=lookup_widget(button,"comboboxedittype");
quantt=lookup_widget(button,"spinbuttoneditquant");
epuise=lookup_widget(button,"radiobuttoneditepuise");
enstock=lookup_widget(button,"radiobuttoneditenstock");
warr=lookup_widget(button,"labelwarning");


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


treeview2=lookup_widget(button,"treeview500");
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
nomb=lookup_widget(button,"searchrestoentry");
war=lookup_widget(button,"labelwarning");
refb=lookup_widget(button,"entryeditref");
typeb=lookup_widget(button,"comboboxedittype");
quantb=lookup_widget(button,"spinbuttoneditquant");
msggg=lookup_widget(button,"test");
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
on_radiobuttoneditenstock_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
w=1;

}


void
on_radiobuttoneditepuise_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
w=2;

}


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

	treeview1=lookup_widget(button,"treeview99");
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


treeview12=lookup_widget(button,"treeview501");
rupture();
affichagerup(treeview12);


}


/*void
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

}*/


void
on_buttoncommand_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{commander();

}


void
on_checkbuttonresto_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
m=2;

}

