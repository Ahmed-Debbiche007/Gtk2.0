void
on_supp_ay_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int xs=-1;
char type[20];
char maintenance[20];
char date[20];
char etate[20];
char id[20];
char nb [20];

lb = lookup_widget (objet_graphique,"label19");
dd = lookup_widget (objet_graphique,"entry1");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("equipement.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s \n",id,type,maintenance,etate,date,nb) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      xs=1;
      } 
     } 
    
     fclose (F);
  }

if(xs==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_ay(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");/* code */
}


//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficher_ay(p ,"equipement.txt");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_rech_ay_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{


GtkWidget *dd,*type,*maintenance,*etate,*date,*ty,*se,*da,*po,*lb;
char idd[20];

int xr=-1;
char type1[20];
char maintenance1[20];
char date1[20];
char nb1[20];
char id[20];
char etate1[20];

FILE *F;
dd = lookup_widget (button,"entry1");
type = lookup_widget(button, "label23");
maintenance = lookup_widget(button, "label24");
etate = lookup_widget(button, "label25");
date = lookup_widget(button, "label26");
lb= lookup_widget(button, "label19");

ty = lookup_widget (button,"entry2");
se = lookup_widget (button,"entry3");
da = lookup_widget (button,"combobox2");
po = lookup_widget (button,"entry5");




strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("equipement.txt", "r");

if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s \n",id,type1,maintenance1,etate1,date1,nb1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      xr=1;
      } 
     } 
    
     fclose (F);
  }

if(xr==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
   gtk_label_set_text(GTK_LABEL(ty),"");
gtk_label_set_text(GTK_LABEL(se),"");
gtk_label_set_text(GTK_LABEL(dd),"");
gtk_entry_set_text(GTK_LABEL(po),"");
}else
{
    equip A= rech_ay(idd);
    gtk_label_set_text(GTK_LABEL(lb),"1 trouve");/* code */
gtk_label_set_text(GTK_LABEL(type),A.type);
gtk_label_set_text(GTK_LABEL(maintenance),A.maintenance);
gtk_label_set_text(GTK_LABEL(etate),A.etate);
gtk_label_set_text(GTK_LABEL(date),A.date);


gtk_entry_set_text(GTK_LABEL(ty),A.type);
gtk_entry_set_text(GTK_LABEL(se),A.maintenance);
gtk_label_set_text(GTK_LABEL(da),A.etate);
gtk_entry_set_text(GTK_LABEL(po),A.date);
}



}
//////////////////////////////////////////////////////////////////
void
on_Modi_ay_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*ty,*se,*da,*po,*nb,*lb;
int v=-1;
char id[20];
char idd[20];
char type1[20];
char maintenance1[20];
char etate1[20];
char date1[20];
char nb1[20];
equip U ;

dd = lookup_widget (objet_graphique,"entry1");
ty = lookup_widget (objet_graphique,"entry2");
se = lookup_widget (objet_graphique,"entry3");
da = lookup_widget (objet_graphique,"combobox2");
po = lookup_widget (objet_graphique,"entry5");
nb = lookup_widget (objet_graphique,"spinbutton35");
lb = lookup_widget (objet_graphique,"label19");

FILE *F;

F = fopen ("equipement.txt", "r");


if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s \n",id,type1,maintenance1,etate1,date1,nb1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      v=1;
      } 
     } 
    
     fclose (F);
  }

if(v==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
gtk_label_set_text(GTK_LABEL(ty),"");
gtk_label_set_text(GTK_LABEL(se),"");
gtk_label_set_text(GTK_LABEL(dd),"");
gtk_entry_set_text(GTK_LABEL(po),"");
}else
{
    
    gtk_label_set_text(GTK_LABEL(lb),"1 trouve");/* code */

U.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
strcpy(U.type,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(U.maintenance,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(U.etate,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(U.date,gtk_entry_get_text(GTK_ENTRY(po)));

modi_ay(id,U);
}

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficher_ay(p ,"equipement.txt");
}

