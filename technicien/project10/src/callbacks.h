#include <gtk/gtk.h>


void
on_buttonOk_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonAnnuler_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonAfficher_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonModifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data);


void
on_button_alarmentes_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_accueil_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAnnuler1_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour2_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Retour_gestion_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



void
on_buttonRechercher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonOk1_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonalarmente_clicked             (GtkButton       *button,
                                        gpointer         user_data);
