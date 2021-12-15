#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agent.h"

calcul[5]={0,0,0,0,0};char so[50];
char sup[100],id[10];Etudiant E;

void
on_Valider_auth_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principale, *Authentification;
Authentification=lookup_widget(objet,"Authentification");
gtk_widget_destroy(Authentification);
principale=lookup_widget(objet,"principale");
principale=create_principale();
gtk_widget_show (principale);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* identifiant;
gchar* classe;
gchar* chambre;
gchar* sexe;
gchar* date;
Etudiant E;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path));
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&identifiant,3,&classe,4,&chambre,5,&sexe,6,&date,-1);
strcpy(E.nom,nom);
strcpy(E.prenom,prenom);
strcpy(E.identifiant,identifiant);
strcpy(E.classe,classe);
strcpy(E.chambre,chambre);
strcpy(E.sexe,sexe);
strcpy(E.date.jour,date);
strcpy(E.date.mois,date);
strcpy(E.date.annee,date);
supprimer(identifiant);

afficher_etudiant(treeview);
}

}


void
on_button_recherche_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *principale, *Recherche;
principale=lookup_widget(objet,"principale");
gtk_widget_destroy(principale);
Recherche=lookup_widget(objet,"Recherche");
Recherche=create_Recherche();
gtk_widget_show (Recherche);
}


void
on_button_calcul_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *principale, *Calcul;
principale=lookup_widget(objet,"principale");
gtk_widget_destroy(principale);
Calcul=lookup_widget(objet,"Calcul");
Calcul=create_Calcul();
gtk_widget_show (Calcul);
}


void
on_button_Affichage_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1,*principale;
principale=lookup_widget(button,"principale");
treeview1=lookup_widget(button,"treeview1");
principale = create_principale ();
gtk_widget_show (principale);
gtk_widget_destroy(principale);
afficher_etudiant(treeview1);
}




void
on_button_modification_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principale, *Modification;
principale=lookup_widget(objet,"principale");
gtk_widget_destroy(principale);
Modification=lookup_widget(objet,"Modification");
Modification=create_Modification();
gtk_widget_show (Modification);
}


void
on_button_Ajout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principale, *Ajout;
principale=lookup_widget(objet,"principale");
gtk_widget_destroy(principale);
Ajout=lookup_widget(objet,"Ajout");
Ajout=create_Ajout();
gtk_widget_show (Ajout);
}


void
on_radiobutton_m_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 Etudiant E;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(E.sexe,"M");
}


void
on_radiobutton_f_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 Etudiant E;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(E.sexe,"F");
}


void
on_button_ajouter_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
Etudiant E;
DATE date;
GtkWidget *input1,*input2,*input3,*input4,*input5,*jour,*mois,*annee,*input6,*input7;
GtkWidget *Ajout;GtkWidget *output;
char text1[100]="Etudiant ajouté";
char text2[40]="Identifiant Incorrecte";
char text3[40]=" Champ Vide!";

Ajout=lookup_widget(objet, "Ajout");

input1 = lookup_widget(objet, "entry_nomajout") ;
input2= lookup_widget(objet, "entry_prenomajout") ;
input3= lookup_widget(objet, "entry_chambreajout");
input4=lookup_widget(objet, "entry_id");
input5= lookup_widget(objet, "combobox_classe");
input6=	lookup_widget(objet, "radiobutton_f");
input7=	lookup_widget(objet, "radiobutton_m");
jour=lookup_widget(objet, "spinbutton_ajout");
mois=lookup_widget(objet, "spinbutton_mois");
annee= lookup_widget(objet, "spinbutton_annee");

strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(E.identifiant,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(E.chambre,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(E.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input6)))
strcpy(E.sexe,"F");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input7)))
strcpy(E.sexe,"M");
 
E.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
E.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
E.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
output=lookup_widget(objet,"labelajout");
if (strlen(E.identifiant)==10 && strlen(E.nom)!=0 && strlen(E.prenom)!=0 && strlen(E.chambre)!=0 && strlen(E.classe)!=0 && strlen(E.sexe)!=0){
ajouter_edudiant(E);
gtk_label_set_text(GTK_LABEL(output),text1);}
else if (strlen(E.identifiant)!=10){
gtk_label_set_text(GTK_LABEL(output),text2);}
else if (strlen(E.nom)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E.prenom)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E.chambre)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E.classe)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E.sexe)==0)
gtk_label_set_text(GTK_LABEL(output),text3);



}


void
on_button_retour_ajout_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Ajout,*principale;
 GtkWidget*treeview1;

Ajout=lookup_widget(objet,"Ajout");
gtk_widget_destroy(Ajout);

principale = create_principale ();
gtk_widget_show (principale);


treeview1=lookup_widget(principale,"treeview1");

afficher_etudiant(treeview1);
}


void
on_button_retourmodif_clicked          (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *principale,*Modification,*treeview;
principale = create_principale ();
gtk_widget_show (principale);
Modification=lookup_widget(button,"Modification");
gtk_widget_destroy(Modification);
}


void
on_button_modif_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*jour,*mois,*annee;
GtkWidget *Modification,*output;
Etudiant E1;char text2[100]="Identifiant Incorrecte";char text1[100]="Modifié avec succès";char text3[100]="champ vide !";
DATE date;
Modification=lookup_widget(objet,"Modification");

input1 = lookup_widget(objet, "entrynomodif") ;
input2= lookup_widget(objet, "entryprenmodif") ;
input3= lookup_widget(objet, "entry_chambremodif");
input4=lookup_widget(objet, "entry_idmodif");
input5= lookup_widget(objet, "combobox_classemodif");
input6=	lookup_widget(objet, "radiobuttonfm");
input7=	lookup_widget(objet, "radiobutton_mm");
jour=lookup_widget(objet, "spinbuttonj");
mois=lookup_widget(objet, "spinbuttonm");
annee= lookup_widget(objet, "spinbuttona");

strcpy(E1.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(E1.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(E1.identifiant,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(E1.chambre,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(E1.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input6)))
strcpy(E1.sexe,"F");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input7)))
strcpy(E1.sexe,"M");
 
E1.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
E1.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
E1.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
output=lookup_widget(objet,"labelmodif");
if(strlen(E1.identifiant)==10 && strlen(E1.nom)!=0 && strlen(E1.prenom)!=0 && strlen(E1.chambre)!=0 && strlen(E1.classe)!=0 && strlen(E1.sexe)!=0){
gtk_label_set_text(GTK_LABEL(output),text1);
modifier(E1);
}
else if (strlen(E1.identifiant)!=10){
gtk_label_set_text(GTK_LABEL(output),text2);}
else if (strlen(E1.nom)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E1.prenom)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E1.chambre)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E1.classe)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E1.sexe)==0)
gtk_label_set_text(GTK_LABEL(output),text3);


}


void
on_checkbutton_d_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[1]=1;
}
else
{calcul[1]=0;}
}


void
on_checkbutton_t_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[2]=1;
}
else
{calcul[2]=0;
}
}


void
on_checkbutton_q_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[3]=1;}
else
{calcul[3]=0;}
}


void
on_checkbutton_c_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[4]=1;}
else
{calcul[4]=0;}

}


void
on_checkbutton_p_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[0]=1;
}
else
{calcul[0]=0;}
}


void
on_button_retourcalcul_clicked         (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *principale,*Calcul,*treeview;
principale = create_principale ();
gtk_widget_show (principale);
Calcul=lookup_widget(button,"Calcul");
gtk_widget_destroy(Calcul);
}


void
on_button_calculer_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *somme;
int sum;
somme = lookup_widget(button, "label_calcul_s") ;
sum=niveau(calcul,"etudiant.txt");
sprintf(so,"%d",sum);
gtk_label_set_text(GTK_LABEL(somme),so);
}

//button rechercher
void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	int x;
	GtkWidget *entry_idrecherche,*output,*principale,*treeview1;
	char IDENTIFIANT[40];char txt[100]="Etudiant trouvé !";char txt2[100]="Etudiant non trouvé !";char txt3[100]="Identifiant incorrecte";
	entry_idrecherche=lookup_widget(button,"entry_idrecherche");
	strcpy(IDENTIFIANT,gtk_entry_get_text(GTK_ENTRY(entry_idrecherche)));
	output=lookup_widget(button,"labeltrouve");
	x=recherche(E,IDENTIFIANT);
	if(x==1 && strlen(IDENTIFIANT)==10){
	gtk_label_set_text(GTK_LABEL(output),txt);}
	else if(strlen(IDENTIFIANT)!=10)
	gtk_label_set_text(GTK_LABEL(output),txt3);
	else
	gtk_label_set_text(GTK_LABEL(output),txt2);
	

	
}


void
on_button_retourrecherche_clicked      (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *principale,*Recherche,*treeview;
principale = create_principale ();
gtk_widget_show (principale);
Recherche=lookup_widget(button,"Recherche");
gtk_widget_destroy(Recherche);
}




void
on_Suppress_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
	char IDENTIFIANT[40];
	GtkWidget *entry_idsuppression;
	entry_idsuppression=lookup_widget(objet,"entry_idsuppression");
	strcpy(IDENTIFIANT,gtk_entry_get_text(GTK_ENTRY(entry_idsuppression)));
	supprimer(IDENTIFIANT);
}


void
on_radiobutton_mm_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
Etudiant E1;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(E1.sexe,"M");
}


void
on_radiobuttonfm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
Etudiant E1;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(E1.sexe,"F");
}

