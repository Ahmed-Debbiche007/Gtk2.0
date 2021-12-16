#include <gtk/gtk.h>


void
on_button1_ajouter_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton1_petit_dejuner_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_dejeuner_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_dinner_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_ajouter_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button2_modifier_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button4_recherche_clicked           (GtkButton      *button,
                                        gpointer         user_data);

void
on_button3_supprimer_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button5_actualiser_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_checkbutton1_supprimer_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button4_chercher_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_checkbutton2_modifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
