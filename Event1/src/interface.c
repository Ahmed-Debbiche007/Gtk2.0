/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_Gestion_Event (void)
{
  GtkWidget *Gestion_Event;
  GtkWidget *fixed5;
  GtkWidget *label100;
  GtkWidget *image62;
  GtkWidget *Facebook;
  GtkWidget *image64;
  GtkWidget *youtube;
  GtkWidget *image65;
  GtkWidget *Instagram;
  GtkWidget *image63;
  GtkWidget *notebook1;
  GtkWidget *fixed10;
  GtkWidget *entry6;
  GtkWidget *entry7;
  GtkWidget *entry9;
  GtkObject *spinbutton33_adj;
  GtkWidget *spinbutton33;
  GtkWidget *label264;
  GtkWidget *label265;
  GtkWidget *radiobutton2;
  GSList *radiobutton2_group = NULL;
  GtkWidget *checkbutton2;
  GtkWidget *radiobutton1;
  GtkWidget *checkbutton1;
  GtkWidget *label270;
  GtkWidget *label271;
  GtkWidget *label272;
  GtkWidget *calendar1;
  GtkWidget *label263;
  GtkWidget *ajout_nb;
  GtkWidget *alignment9;
  GtkWidget *hbox9;
  GtkWidget *image9;
  GtkWidget *label32;
  GtkWidget *ok_nb;
  GtkWidget *alignment58;
  GtkWidget *hbox58;
  GtkWidget *image61;
  GtkWidget *label233;
  GtkWidget *label266;
  GtkWidget *label267;
  GtkWidget *label269;
  GtkWidget *label268;
  GtkWidget *label273;
  GtkWidget *combobox3;
  GtkWidget *Ajouter;
  GtkWidget *fixed9;
  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *entry3;
  GtkWidget *entry5;
  GtkObject *spinbutton35_adj;
  GtkWidget *spinbutton35;
  GtkWidget *label26;
  GtkWidget *label24;
  GtkWidget *label25;
  GtkWidget *label23;
  GtkWidget *label229;
  GtkWidget *label19;
  GtkWidget *label22;
  GtkWidget *Modif_nb;
  GtkWidget *alignment7;
  GtkWidget *hbox7;
  GtkWidget *image7;
  GtkWidget *label16;
  GtkWidget *rech_nb;
  GtkWidget *alignment6;
  GtkWidget *hbox6;
  GtkWidget *image6;
  GtkWidget *label15;
  GtkWidget *supp_nb;
  GtkWidget *alignment8;
  GtkWidget *hbox8;
  GtkWidget *image8;
  GtkWidget *label17;
  GtkWidget *label18;
  GtkWidget *label228;
  GtkWidget *label20;
  GtkWidget *label21;
  GtkWidget *label14;
  GtkWidget *combobox2;
  GtkWidget *s_m_r;
  GtkWidget *fixed7;
  GtkWidget *fixed8;
  GtkWidget *treeview1;
  GtkWidget *label234;
  GtkWidget *label11;
  GtkWidget *supp_tree_nb;
  GtkWidget *alignment48;
  GtkWidget *hbox48;
  GtkWidget *image48;
  GtkWidget *label208;
  GtkWidget *actu_nb;
  GtkWidget *alignment52;
  GtkWidget *hbox52;
  GtkWidget *image55;
  GtkWidget *label212;
  GtkWidget *affi_nb;
  GtkWidget *alignment4;
  GtkWidget *hbox4;
  GtkWidget *image4;
  GtkWidget *label12;
  GtkWidget *label274;
  GtkWidget *Afichier_;

  Gestion_Event = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Gestion_Event), _("Gestion Event"));

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (Gestion_Event), fixed5);

  label100 = gtk_label_new (_("<b><u><span color='blue'>  Bienvenue dans l'espace Reponsable Evennements  </span></u></b>"));
  gtk_widget_show (label100);
  gtk_fixed_put (GTK_FIXED (fixed5), label100, 184, 176);
  gtk_widget_set_size_request (label100, 400, 24);
  gtk_label_set_use_markup (GTK_LABEL (label100), TRUE);

  image62 = create_pixmap (Gestion_Event, "organisation-evenement-grand-public.jpg");
  gtk_widget_show (image62);
  gtk_fixed_put (GTK_FIXED (fixed5), image62, 0, 0);
  gtk_widget_set_size_request (image62, 1064, 168);

  Facebook = gtk_button_new ();
  gtk_widget_show (Facebook);
  gtk_fixed_put (GTK_FIXED (fixed5), Facebook, 784, 200);
  gtk_widget_set_size_request (Facebook, 49, 40);

  image64 = create_pixmap (Gestion_Event, "button-facebookfinal.svg");
  gtk_widget_show (image64);
  gtk_container_add (GTK_CONTAINER (Facebook), image64);

  youtube = gtk_button_new ();
  gtk_widget_show (youtube);
  gtk_fixed_put (GTK_FIXED (fixed5), youtube, 840, 200);
  gtk_widget_set_size_request (youtube, 59, 36);

  image65 = create_pixmap (Gestion_Event, "youtube.png");
  gtk_widget_show (image65);
  gtk_container_add (GTK_CONTAINER (youtube), image65);

  Instagram = gtk_button_new ();
  gtk_widget_show (Instagram);
  gtk_fixed_put (GTK_FIXED (fixed5), Instagram, 720, 192);
  gtk_widget_set_size_request (Instagram, 54, 40);

  image63 = create_pixmap (Gestion_Event, "aaaaaaaaaaa.png");
  gtk_widget_show (image63);
  gtk_container_add (GTK_CONTAINER (Instagram), image63);

  notebook1 = gtk_notebook_new ();
  gtk_widget_show (notebook1);
  gtk_fixed_put (GTK_FIXED (fixed5), notebook1, 8, 216);
  gtk_widget_set_size_request (notebook1, 968, 656);

  fixed10 = gtk_fixed_new ();
  gtk_widget_show (fixed10);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed10);

  entry6 = gtk_entry_new ();
  gtk_widget_show (entry6);
  gtk_fixed_put (GTK_FIXED (fixed10), entry6, 416, 120);
  gtk_widget_set_size_request (entry6, 248, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry6), 8226);

  entry7 = gtk_entry_new ();
  gtk_widget_show (entry7);
  gtk_fixed_put (GTK_FIXED (fixed10), entry7, 416, 256);
  gtk_widget_set_size_request (entry7, 248, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry7), 8226);

  entry9 = gtk_entry_new ();
  gtk_widget_show (entry9);
  gtk_fixed_put (GTK_FIXED (fixed10), entry9, 416, 384);
  gtk_widget_set_size_request (entry9, 248, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry9), 8226);

  spinbutton33_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton33 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton33_adj), 1, 0);
  gtk_widget_show (spinbutton33);
  gtk_fixed_put (GTK_FIXED (fixed10), spinbutton33, 416, 184);
  gtk_widget_set_size_request (spinbutton33, 60, 27);

  label264 = gtk_label_new ("");
  gtk_widget_show (label264);
  gtk_fixed_put (GTK_FIXED (fixed10), label264, 688, 256);
  gtk_widget_set_size_request (label264, 240, 32);

  label265 = gtk_label_new ("");
  gtk_widget_show (label265);
  gtk_fixed_put (GTK_FIXED (fixed10), label265, 680, 384);
  gtk_widget_set_size_request (label265, 264, 32);

  radiobutton2 = gtk_radio_button_new_with_mnemonic (NULL, _("Mode nuit"));
  gtk_widget_show (radiobutton2);
  gtk_fixed_put (GTK_FIXED (fixed10), radiobutton2, 480, 512);
  gtk_widget_set_size_request (radiobutton2, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton2), radiobutton2_group);
  radiobutton2_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton2));

  checkbutton2 = gtk_check_button_new_with_mnemonic (_("Groupe A"));
  gtk_widget_show (checkbutton2);
  gtk_fixed_put (GTK_FIXED (fixed10), checkbutton2, 264, 584);
  gtk_widget_set_size_request (checkbutton2, 208, 24);

  radiobutton1 = gtk_radio_button_new_with_mnemonic (NULL, _("Mode jour"));
  gtk_widget_show (radiobutton1);
  gtk_fixed_put (GTK_FIXED (fixed10), radiobutton1, 264, 512);
  gtk_widget_set_size_request (radiobutton1, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton1), radiobutton2_group);
  radiobutton2_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton1));

  checkbutton1 = gtk_check_button_new_with_mnemonic (_("Groupe B"));
  gtk_widget_show (checkbutton1);
  gtk_fixed_put (GTK_FIXED (fixed10), checkbutton1, 480, 584);
  gtk_widget_set_size_request (checkbutton1, 240, 24);

  label270 = gtk_label_new (_("<b><span color='black'>  Date  </span></b>"));
  gtk_widget_show (label270);
  gtk_fixed_put (GTK_FIXED (fixed10), label270, 216, 392);
  gtk_widget_set_size_request (label270, 184, 32);
  gtk_label_set_use_markup (GTK_LABEL (label270), TRUE);

  label271 = gtk_label_new (_("<b><span color='black'>  Mode de travail  :</span></b>"));
  gtk_widget_show (label271);
  gtk_fixed_put (GTK_FIXED (fixed10), label271, 104, 472);
  gtk_widget_set_size_request (label271, 184, 40);
  gtk_label_set_use_markup (GTK_LABEL (label271), TRUE);

  label272 = gtk_label_new (_("<b><span color='black'>  Groupe de Travail  :</span></b>"));
  gtk_widget_show (label272);
  gtk_fixed_put (GTK_FIXED (fixed10), label272, 104, 552);
  gtk_widget_set_size_request (label272, 176, 32);
  gtk_label_set_use_markup (GTK_LABEL (label272), TRUE);

  calendar1 = gtk_calendar_new ();
  gtk_widget_show (calendar1);
  gtk_fixed_put (GTK_FIXED (fixed10), calendar1, 32, 24);
  gtk_widget_set_size_request (calendar1, 162, 186);
  gtk_calendar_display_options (GTK_CALENDAR (calendar1),
                                GTK_CALENDAR_SHOW_HEADING
                                | GTK_CALENDAR_SHOW_DAY_NAMES);

  label263 = gtk_label_new ("");
  gtk_widget_show (label263);
  gtk_fixed_put (GTK_FIXED (fixed10), label263, 696, 120);
  gtk_widget_set_size_request (label263, 256, 32);

  ajout_nb = gtk_button_new ();
  gtk_widget_show (ajout_nb);
  gtk_fixed_put (GTK_FIXED (fixed10), ajout_nb, 776, 440);
  gtk_widget_set_size_request (ajout_nb, 96, 37);

  alignment9 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment9);
  gtk_container_add (GTK_CONTAINER (ajout_nb), alignment9);

  hbox9 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox9);
  gtk_container_add (GTK_CONTAINER (alignment9), hbox9);

  image9 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image9);
  gtk_box_pack_start (GTK_BOX (hbox9), image9, FALSE, FALSE, 0);

  label32 = gtk_label_new_with_mnemonic (_("Ajouter"));
  gtk_widget_show (label32);
  gtk_box_pack_start (GTK_BOX (hbox9), label32, FALSE, FALSE, 0);

  ok_nb = gtk_button_new ();
  gtk_widget_show (ok_nb);
  gtk_fixed_put (GTK_FIXED (fixed10), ok_nb, 648, 544);
  gtk_widget_set_size_request (ok_nb, 96, 40);

  alignment58 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment58);
  gtk_container_add (GTK_CONTAINER (ok_nb), alignment58);

  hbox58 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox58);
  gtk_container_add (GTK_CONTAINER (alignment58), hbox58);

  image61 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image61);
  gtk_box_pack_start (GTK_BOX (hbox58), image61, FALSE, FALSE, 0);

  label233 = gtk_label_new_with_mnemonic (_("OK"));
  gtk_widget_show (label233);
  gtk_box_pack_start (GTK_BOX (hbox58), label233, FALSE, FALSE, 0);

  label266 = gtk_label_new (_("<b><span color='Black'> Nom de l'event  </span></b>"));
  gtk_widget_show (label266);
  gtk_fixed_put (GTK_FIXED (fixed10), label266, 200, 120);
  gtk_widget_set_size_request (label266, 240, 32);
  gtk_label_set_use_markup (GTK_LABEL (label266), TRUE);

  label267 = gtk_label_new (_("<b><span color='black'>  Nombre de l'evennement </span></b>"));
  gtk_widget_show (label267);
  gtk_fixed_put (GTK_FIXED (fixed10), label267, 216, 184);
  gtk_widget_set_size_request (label267, 200, 32);
  gtk_label_set_use_markup (GTK_LABEL (label267), TRUE);

  label269 = gtk_label_new (_("<b><span color='black'>     Lieu  </span></b>"));
  gtk_widget_show (label269);
  gtk_fixed_put (GTK_FIXED (fixed10), label269, 248, 312);
  gtk_widget_set_size_request (label269, 152, 32);
  gtk_label_set_use_markup (GTK_LABEL (label269), TRUE);

  label268 = gtk_label_new (_("<b><span color='black'> Association/club  </span></b>"));
  gtk_widget_show (label268);
  gtk_fixed_put (GTK_FIXED (fixed10), label268, 216, 256);
  gtk_widget_set_size_request (label268, 184, 32);
  gtk_label_set_use_markup (GTK_LABEL (label268), TRUE);

  label273 = gtk_label_new (_("<b><span color='red'>  Ajouter un Service  </span></b>"));
  gtk_widget_show (label273);
  gtk_fixed_put (GTK_FIXED (fixed10), label273, 344, 56);
  gtk_widget_set_size_request (label273, 216, 32);
  gtk_label_set_use_markup (GTK_LABEL (label273), TRUE);

  combobox3 = gtk_combo_box_new_text ();
  gtk_widget_show (combobox3);
  gtk_fixed_put (GTK_FIXED (fixed10), combobox3, 416, 312);
  gtk_widget_set_size_request (combobox3, 248, 40);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox3), _("blocA"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox3), _("blocB"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox3), _("blocC"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox3), _("terrain"));

  Ajouter = gtk_label_new (_("<b><span color='green'>  Ajouter  </span></b>"));
  gtk_widget_show (Ajouter);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 0), Ajouter);
  gtk_label_set_use_markup (GTK_LABEL (Ajouter), TRUE);

  fixed9 = gtk_fixed_new ();
  gtk_widget_show (fixed9);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed9);

  entry1 = gtk_entry_new ();
  gtk_widget_show (entry1);
  gtk_fixed_put (GTK_FIXED (fixed9), entry1, 152, 48);
  gtk_widget_set_size_request (entry1, 184, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry1), 8226);

  entry2 = gtk_entry_new ();
  gtk_widget_show (entry2);
  gtk_fixed_put (GTK_FIXED (fixed9), entry2, 544, 128);
  gtk_widget_set_size_request (entry2, 176, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry2), 8226);

  entry3 = gtk_entry_new ();
  gtk_widget_show (entry3);
  gtk_fixed_put (GTK_FIXED (fixed9), entry3, 544, 296);
  gtk_widget_set_size_request (entry3, 176, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry3), 8226);

  entry5 = gtk_entry_new ();
  gtk_widget_show (entry5);
  gtk_fixed_put (GTK_FIXED (fixed9), entry5, 544, 496);
  gtk_widget_set_size_request (entry5, 176, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry5), 8226);

  spinbutton35_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton35 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton35_adj), 1, 0);
  gtk_widget_show (spinbutton35);
  gtk_fixed_put (GTK_FIXED (fixed9), spinbutton35, 544, 224);
  gtk_widget_set_size_request (spinbutton35, 60, 27);

  label26 = gtk_label_new ("");
  gtk_widget_show (label26);
  gtk_fixed_put (GTK_FIXED (fixed9), label26, 240, 496);
  gtk_widget_set_size_request (label26, 312, 32);

  label24 = gtk_label_new ("");
  gtk_widget_show (label24);
  gtk_fixed_put (GTK_FIXED (fixed9), label24, 216, 296);
  gtk_widget_set_size_request (label24, 328, 40);

  label25 = gtk_label_new ("");
  gtk_widget_show (label25);
  gtk_fixed_put (GTK_FIXED (fixed9), label25, 184, 400);
  gtk_widget_set_size_request (label25, 368, 40);

  label23 = gtk_label_new ("");
  gtk_widget_show (label23);
  gtk_fixed_put (GTK_FIXED (fixed9), label23, 232, 128);
  gtk_widget_set_size_request (label23, 296, 32);

  label229 = gtk_label_new ("");
  gtk_widget_show (label229);
  gtk_fixed_put (GTK_FIXED (fixed9), label229, 192, 216);
  gtk_widget_set_size_request (label229, 344, 40);

  label19 = gtk_label_new ("");
  gtk_widget_show (label19);
  gtk_fixed_put (GTK_FIXED (fixed9), label19, 152, 88);
  gtk_widget_set_size_request (label19, 184, 40);

  label22 = gtk_label_new (_("date :"));
  gtk_widget_show (label22);
  gtk_fixed_put (GTK_FIXED (fixed9), label22, 40, 488);
  gtk_widget_set_size_request (label22, 216, 32);

  Modif_nb = gtk_button_new ();
  gtk_widget_show (Modif_nb);
  gtk_fixed_put (GTK_FIXED (fixed9), Modif_nb, 496, 40);
  gtk_widget_set_size_request (Modif_nb, 96, 40);

  alignment7 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment7);
  gtk_container_add (GTK_CONTAINER (Modif_nb), alignment7);

  hbox7 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox7);
  gtk_container_add (GTK_CONTAINER (alignment7), hbox7);

  image7 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image7);
  gtk_box_pack_start (GTK_BOX (hbox7), image7, FALSE, FALSE, 0);

  label16 = gtk_label_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (label16);
  gtk_box_pack_start (GTK_BOX (hbox7), label16, FALSE, FALSE, 0);

  rech_nb = gtk_button_new ();
  gtk_widget_show (rech_nb);
  gtk_fixed_put (GTK_FIXED (fixed9), rech_nb, 360, 40);
  gtk_widget_set_size_request (rech_nb, 112, 40);

  alignment6 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment6);
  gtk_container_add (GTK_CONTAINER (rech_nb), alignment6);

  hbox6 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox6);
  gtk_container_add (GTK_CONTAINER (alignment6), hbox6);

  image6 = gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image6);
  gtk_box_pack_start (GTK_BOX (hbox6), image6, FALSE, FALSE, 0);

  label15 = gtk_label_new_with_mnemonic (_("Rechercher"));
  gtk_widget_show (label15);
  gtk_box_pack_start (GTK_BOX (hbox6), label15, FALSE, FALSE, 0);

  supp_nb = gtk_button_new ();
  gtk_widget_show (supp_nb);
  gtk_fixed_put (GTK_FIXED (fixed9), supp_nb, 616, 40);
  gtk_widget_set_size_request (supp_nb, 104, 40);

  alignment8 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment8);
  gtk_container_add (GTK_CONTAINER (supp_nb), alignment8);

  hbox8 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox8);
  gtk_container_add (GTK_CONTAINER (alignment8), hbox8);

  image8 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image8);
  gtk_box_pack_start (GTK_BOX (hbox8), image8, FALSE, FALSE, 0);

  label17 = gtk_label_new_with_mnemonic (_("Supprimer"));
  gtk_widget_show (label17);
  gtk_box_pack_start (GTK_BOX (hbox8), label17, FALSE, FALSE, 0);

  label18 = gtk_label_new (_("Nom de l'evennement :"));
  gtk_widget_show (label18);
  gtk_fixed_put (GTK_FIXED (fixed9), label18, 24, 128);
  gtk_widget_set_size_request (label18, 208, 32);

  label228 = gtk_label_new (_("Nombre de personne "));
  gtk_widget_show (label228);
  gtk_fixed_put (GTK_FIXED (fixed9), label228, 48, 224);
  gtk_widget_set_size_request (label228, 160, 32);

  label20 = gtk_label_new (_("Association/Club"));
  gtk_widget_show (label20);
  gtk_fixed_put (GTK_FIXED (fixed9), label20, 48, 304);
  gtk_widget_set_size_request (label20, 192, 32);

  label21 = gtk_label_new (_("Lieu"));
  gtk_widget_show (label21);
  gtk_fixed_put (GTK_FIXED (fixed9), label21, 40, 400);
  gtk_widget_set_size_request (label21, 168, 32);

  label14 = gtk_label_new (_("ID:"));
  gtk_widget_show (label14);
  gtk_fixed_put (GTK_FIXED (fixed9), label14, 16, 48);
  gtk_widget_set_size_request (label14, 120, 32);

  combobox2 = gtk_combo_box_new_text ();
  gtk_widget_show (combobox2);
  gtk_fixed_put (GTK_FIXED (fixed9), combobox2, 544, 400);
  gtk_widget_set_size_request (combobox2, 176, 32);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("blocA"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("blocB"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("blocC"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Terrain"));

  s_m_r = gtk_label_new (_("<b><span color='green'>  Supprimer / Modifier / Rechercher  </span></b>"));
  gtk_widget_show (s_m_r);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 1), s_m_r);
  gtk_label_set_use_markup (GTK_LABEL (s_m_r), TRUE);

  fixed7 = gtk_fixed_new ();
  gtk_widget_show (fixed7);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed7);

  fixed8 = gtk_fixed_new ();
  gtk_widget_show (fixed8);
  gtk_fixed_put (GTK_FIXED (fixed7), fixed8, 56, 136);
  gtk_widget_set_size_request (fixed8, 50, 50);

  treeview1 = gtk_tree_view_new ();
  gtk_widget_show (treeview1);
  gtk_fixed_put (GTK_FIXED (fixed7), treeview1, 16, 32);
  gtk_widget_set_size_request (treeview1, 560, 512);

  label234 = gtk_label_new ("");
  gtk_widget_show (label234);
  gtk_fixed_put (GTK_FIXED (fixed7), label234, 608, 360);
  gtk_widget_set_size_request (label234, 328, 232);

  label11 = gtk_label_new ("");
  gtk_widget_show (label11);
  gtk_fixed_put (GTK_FIXED (fixed7), label11, 624, 80);
  gtk_widget_set_size_request (label11, 296, 144);

  supp_tree_nb = gtk_button_new ();
  gtk_widget_show (supp_tree_nb);
  gtk_fixed_put (GTK_FIXED (fixed7), supp_tree_nb, 288, 568);
  gtk_widget_set_size_request (supp_tree_nb, 128, 48);

  alignment48 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment48);
  gtk_container_add (GTK_CONTAINER (supp_tree_nb), alignment48);

  hbox48 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox48);
  gtk_container_add (GTK_CONTAINER (alignment48), hbox48);

  image48 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image48);
  gtk_box_pack_start (GTK_BOX (hbox48), image48, FALSE, FALSE, 0);

  label208 = gtk_label_new_with_mnemonic (_("Supprimer"));
  gtk_widget_show (label208);
  gtk_box_pack_start (GTK_BOX (hbox48), label208, FALSE, FALSE, 0);

  actu_nb = gtk_button_new ();
  gtk_widget_show (actu_nb);
  gtk_fixed_put (GTK_FIXED (fixed7), actu_nb, 424, 568);
  gtk_widget_set_size_request (actu_nb, 152, 48);

  alignment52 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment52);
  gtk_container_add (GTK_CONTAINER (actu_nb), alignment52);

  hbox52 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox52);
  gtk_container_add (GTK_CONTAINER (alignment52), hbox52);

  image55 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image55);
  gtk_box_pack_start (GTK_BOX (hbox52), image55, FALSE, FALSE, 0);

  label212 = gtk_label_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (label212);
  gtk_box_pack_start (GTK_BOX (hbox52), label212, FALSE, FALSE, 0);

  affi_nb = gtk_button_new ();
  gtk_widget_show (affi_nb);
  gtk_fixed_put (GTK_FIXED (fixed7), affi_nb, 720, 256);
  gtk_widget_set_size_request (affi_nb, 104, 56);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (affi_nb), alignment4);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox4);

  image4 = gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox4), image4, FALSE, FALSE, 0);

  label12 = gtk_label_new_with_mnemonic (_("Affichier"));
  gtk_widget_show (label12);
  gtk_box_pack_start (GTK_BOX (hbox4), label12, FALSE, FALSE, 0);

  label274 = gtk_label_new (_("Afficher le capteur deffectueux"));
  gtk_widget_show (label274);
  gtk_fixed_put (GTK_FIXED (fixed7), label274, 648, 176);
  gtk_widget_set_size_request (label274, 240, 105);

  Afichier_ = gtk_label_new (_("<b><span color='green'>  Afficher  </span></b>"));
  gtk_widget_show (Afichier_);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 2), Afichier_);
  gtk_label_set_use_markup (GTK_LABEL (Afichier_), TRUE);

  g_signal_connect ((gpointer) Facebook, "clicked",
                    G_CALLBACK (on_Facebook_clicked),
                    NULL);
  g_signal_connect ((gpointer) youtube, "clicked",
                    G_CALLBACK (on_youtube_clicked),
                    NULL);
  g_signal_connect ((gpointer) Instagram, "clicked",
                    G_CALLBACK (on_Instagram_clicked),
                    NULL);
  g_signal_connect ((gpointer) radiobutton2, "toggled",
                    G_CALLBACK (on_radiobutton2_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbutton2, "toggled",
                    G_CALLBACK (on_checkbutton2_toggled),
                    NULL);
  g_signal_connect ((gpointer) radiobutton1, "toggled",
                    G_CALLBACK (on_radiobutton1_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbutton1, "toggled",
                    G_CALLBACK (on_checkbutton1_toggled),
                    NULL);
  g_signal_connect ((gpointer) ajout_nb, "clicked",
                    G_CALLBACK (on_ajout_nb_clicked),
                    NULL);
  g_signal_connect ((gpointer) ok_nb, "clicked",
                    G_CALLBACK (on_ok_nb_clicked),
                    NULL);
  g_signal_connect ((gpointer) Modif_nb, "clicked",
                    G_CALLBACK (on_Modif_nb_clicked),
                    NULL);
  g_signal_connect ((gpointer) rech_nb, "clicked",
                    G_CALLBACK (on_rech_nb_clicked),
                    NULL);
  g_signal_connect ((gpointer) supp_nb, "clicked",
                    G_CALLBACK (on_supp_nb_clicked),
                    NULL);
  g_signal_connect ((gpointer) supp_tree_nb, "clicked",
                    G_CALLBACK (on_supp_tree_nb_clicked),
                    NULL);
  g_signal_connect ((gpointer) actu_nb, "clicked",
                    G_CALLBACK (on_actu_nb_clicked),
                    NULL);
  g_signal_connect ((gpointer) affi_nb, "clicked",
                    G_CALLBACK (on_affi_nb_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Gestion_Event, Gestion_Event, "Gestion_Event");
  GLADE_HOOKUP_OBJECT (Gestion_Event, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label100, "label100");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image62, "image62");
  GLADE_HOOKUP_OBJECT (Gestion_Event, Facebook, "Facebook");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image64, "image64");
  GLADE_HOOKUP_OBJECT (Gestion_Event, youtube, "youtube");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image65, "image65");
  GLADE_HOOKUP_OBJECT (Gestion_Event, Instagram, "Instagram");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image63, "image63");
  GLADE_HOOKUP_OBJECT (Gestion_Event, notebook1, "notebook1");
  GLADE_HOOKUP_OBJECT (Gestion_Event, fixed10, "fixed10");
  GLADE_HOOKUP_OBJECT (Gestion_Event, entry6, "entry6");
  GLADE_HOOKUP_OBJECT (Gestion_Event, entry7, "entry7");
  GLADE_HOOKUP_OBJECT (Gestion_Event, entry9, "entry9");
  GLADE_HOOKUP_OBJECT (Gestion_Event, spinbutton33, "spinbutton33");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label264, "label264");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label265, "label265");
  GLADE_HOOKUP_OBJECT (Gestion_Event, radiobutton2, "radiobutton2");
  GLADE_HOOKUP_OBJECT (Gestion_Event, checkbutton2, "checkbutton2");
  GLADE_HOOKUP_OBJECT (Gestion_Event, radiobutton1, "radiobutton1");
  GLADE_HOOKUP_OBJECT (Gestion_Event, checkbutton1, "checkbutton1");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label270, "label270");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label271, "label271");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label272, "label272");
  GLADE_HOOKUP_OBJECT (Gestion_Event, calendar1, "calendar1");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label263, "label263");
  GLADE_HOOKUP_OBJECT (Gestion_Event, ajout_nb, "ajout_nb");
  GLADE_HOOKUP_OBJECT (Gestion_Event, alignment9, "alignment9");
  GLADE_HOOKUP_OBJECT (Gestion_Event, hbox9, "hbox9");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image9, "image9");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label32, "label32");
  GLADE_HOOKUP_OBJECT (Gestion_Event, ok_nb, "ok_nb");
  GLADE_HOOKUP_OBJECT (Gestion_Event, alignment58, "alignment58");
  GLADE_HOOKUP_OBJECT (Gestion_Event, hbox58, "hbox58");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image61, "image61");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label233, "label233");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label266, "label266");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label267, "label267");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label269, "label269");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label268, "label268");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label273, "label273");
  GLADE_HOOKUP_OBJECT (Gestion_Event, combobox3, "combobox3");
  GLADE_HOOKUP_OBJECT (Gestion_Event, Ajouter, "Ajouter");
  GLADE_HOOKUP_OBJECT (Gestion_Event, fixed9, "fixed9");
  GLADE_HOOKUP_OBJECT (Gestion_Event, entry1, "entry1");
  GLADE_HOOKUP_OBJECT (Gestion_Event, entry2, "entry2");
  GLADE_HOOKUP_OBJECT (Gestion_Event, entry3, "entry3");
  GLADE_HOOKUP_OBJECT (Gestion_Event, entry5, "entry5");
  GLADE_HOOKUP_OBJECT (Gestion_Event, spinbutton35, "spinbutton35");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label26, "label26");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label24, "label24");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label25, "label25");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label23, "label23");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label229, "label229");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label19, "label19");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label22, "label22");
  GLADE_HOOKUP_OBJECT (Gestion_Event, Modif_nb, "Modif_nb");
  GLADE_HOOKUP_OBJECT (Gestion_Event, alignment7, "alignment7");
  GLADE_HOOKUP_OBJECT (Gestion_Event, hbox7, "hbox7");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image7, "image7");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label16, "label16");
  GLADE_HOOKUP_OBJECT (Gestion_Event, rech_nb, "rech_nb");
  GLADE_HOOKUP_OBJECT (Gestion_Event, alignment6, "alignment6");
  GLADE_HOOKUP_OBJECT (Gestion_Event, hbox6, "hbox6");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image6, "image6");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label15, "label15");
  GLADE_HOOKUP_OBJECT (Gestion_Event, supp_nb, "supp_nb");
  GLADE_HOOKUP_OBJECT (Gestion_Event, alignment8, "alignment8");
  GLADE_HOOKUP_OBJECT (Gestion_Event, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image8, "image8");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label17, "label17");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label18, "label18");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label228, "label228");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label20, "label20");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label21, "label21");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label14, "label14");
  GLADE_HOOKUP_OBJECT (Gestion_Event, combobox2, "combobox2");
  GLADE_HOOKUP_OBJECT (Gestion_Event, s_m_r, "s_m_r");
  GLADE_HOOKUP_OBJECT (Gestion_Event, fixed7, "fixed7");
  GLADE_HOOKUP_OBJECT (Gestion_Event, fixed8, "fixed8");
  GLADE_HOOKUP_OBJECT (Gestion_Event, treeview1, "treeview1");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label234, "label234");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label11, "label11");
  GLADE_HOOKUP_OBJECT (Gestion_Event, supp_tree_nb, "supp_tree_nb");
  GLADE_HOOKUP_OBJECT (Gestion_Event, alignment48, "alignment48");
  GLADE_HOOKUP_OBJECT (Gestion_Event, hbox48, "hbox48");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image48, "image48");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label208, "label208");
  GLADE_HOOKUP_OBJECT (Gestion_Event, actu_nb, "actu_nb");
  GLADE_HOOKUP_OBJECT (Gestion_Event, alignment52, "alignment52");
  GLADE_HOOKUP_OBJECT (Gestion_Event, hbox52, "hbox52");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image55, "image55");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label212, "label212");
  GLADE_HOOKUP_OBJECT (Gestion_Event, affi_nb, "affi_nb");
  GLADE_HOOKUP_OBJECT (Gestion_Event, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (Gestion_Event, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (Gestion_Event, image4, "image4");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label12, "label12");
  GLADE_HOOKUP_OBJECT (Gestion_Event, label274, "label274");
  GLADE_HOOKUP_OBJECT (Gestion_Event, Afichier_, "Afichier_");

  return Gestion_Event;
}

GtkWidget*
create_captDeff (void)
{
  GtkWidget *captDeff;
  GtkWidget *fixed11;
  GtkWidget *labelCapt;
  GtkWidget *button1;

  captDeff = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (captDeff), _("window1"));

  fixed11 = gtk_fixed_new ();
  gtk_widget_show (fixed11);
  gtk_container_add (GTK_CONTAINER (captDeff), fixed11);

  labelCapt = gtk_label_new ("");
  gtk_widget_show (labelCapt);
  gtk_fixed_put (GTK_FIXED (fixed11), labelCapt, 96, 152);
  gtk_widget_set_size_request (labelCapt, 200, 45);

  button1 = gtk_button_new_with_mnemonic (_("Le capteur le plus deffectueux est"));
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed11), button1, 40, 40);
  gtk_widget_set_size_request (button1, 300, 50);

  g_signal_connect ((gpointer) button1, "clicked",
                    G_CALLBACK (on_button1_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (captDeff, captDeff, "captDeff");
  GLADE_HOOKUP_OBJECT (captDeff, fixed11, "fixed11");
  GLADE_HOOKUP_OBJECT (captDeff, labelCapt, "labelCapt");
  GLADE_HOOKUP_OBJECT (captDeff, button1, "button1");

  return captDeff;
}
