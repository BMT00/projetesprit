#include <gtk/gtk.h>


void
on_Valider_auth_clicked                (GtkWidget      *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_recherche_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_calcul_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_Affichage_clicked            (GtkButton       *button,
                                        gpointer         user_data);


void
on_button_modification_clicked         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_Ajout_clicked                (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_radiobutton_m_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_f_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ajouter_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retour_ajout_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retourmodif_clicked          (GtkWidget        *button,
                                        gpointer         user_data);

void
on_button_modif_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkbutton_d_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_t_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_q_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_c_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_p_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_retourcalcul_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_calculer_clicked             (GtkWidget        *button,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retourrecherche_clicked      (GtkWidget       *button,
                                        gpointer         user_data);


void
on_Suppress_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_radiobutton_mm_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
