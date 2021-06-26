#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Login.h"
#include "capteur.h"
#include "client.h"
#include "ouvrier.h"
#include "absenteisme.h"
#include "treeviewp.h"
#include "planter.h"
#include "dossier.h"
#include "repiquage.h"
#include "emplois.h"
#include "message.h"
#include "reun.h"
#include "afficher.h"
/*
void
on_nom_changed                         (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_prenom_changed                      (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_cin_changed                         (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_mail_changed                        (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_num_changed                         (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_afficher_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifaj_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_rechercher_client_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_client_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton_femmemodif_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_hommemodif_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button_modifier_Accueil_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ajout_accueil_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_afficher_accueil_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_samarentry8_changed                 (GtkEditable     *editable,
                                        gpointer         user_data)
{

}
*/
int x;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_button_ajouter_capteur_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	Capteur c;
	GtkWidget *verif_serie_ajout_capteur;
	GtkWidget *verif_nom_ajout_capteur;
	GtkWidget *verif_type_ajout_capteur;
	GtkWidget *verif_marque_ajout_capteur;
	GtkWidget *verif_date_achat_ajout_capteur;
	
	int b=1;
	GtkWidget *existe;
	GtkWidget *succes;


        GtkWidget *combobox1,*entry_marque;
	GtkWidget *spin_jour,*spin_mois,*spin_annee;
	GtkWidget *entry_nom,*combo_type,*entry_serie;
	GtkWidget *label,*wid_ajout;
	spin_jour=lookup_widget(objet_graphique, "spin_jour_capteur");
	spin_mois=lookup_widget(objet_graphique, "spin_mois_capteur");
	spin_annee=lookup_widget(objet_graphique, "spin_annee_capteur");
	entry_nom=lookup_widget(objet_graphique,"entry_nom_capteur");
	entry_marque=lookup_widget(objet_graphique,"entry_marque_capteur");
	entry_serie=lookup_widget(objet_graphique,"entry_serie_capteur");
	combo_type=lookup_widget(objet_graphique, "combo_type_capteur");
	wid_ajout=lookup_widget(objet_graphique,"ajout_capteur");

	verif_serie_ajout_capteur=lookup_widget(objet_graphique,"verif_serie_ajout_capteur");
	verif_nom_ajout_capteur=lookup_widget(objet_graphique,"verif_nom_ajout_capteur");
	verif_type_ajout_capteur=lookup_widget(objet_graphique,"verif_type_ajout_capteur");
	verif_marque_ajout_capteur=lookup_widget(objet_graphique,"verif_marque_ajout_capteur");
	verif_date_achat_ajout_capteur=lookup_widget(objet_graphique,"verif_date_achat_ajout_capteur");


	
	strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom)));
	strcpy(c.serie,gtk_entry_get_text(GTK_ENTRY(entry_serie)));
	strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(entry_marque)));
	
	c.date_achat.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin_jour));
	c.date_achat.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin_mois));
	c.date_achat.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin_annee));
	
	strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo_type)));

	label=lookup_widget(objet_graphique, "capteur_ajoute");
	ajouter_capteur(c);
	gtk_widget_destroy(wid_ajout);
//controle saisie
	
	if(strcmp(c.serie,"")==0){
		  gtk_widget_show (verif_serie_ajout_capteur);
	b=0;
	}
	else {
		  gtk_widget_hide(verif_serie_ajout_capteur);
}

	if(strcmp(c.nom,"")==0){
		  gtk_widget_show (verif_nom_ajout_capteur);
	b=0;
	}
	else {
		  gtk_widget_hide(verif_nom_ajout_capteur);
	}
	if(strcmp(c.type,"")==0){
		  gtk_widget_show (verif_type_ajout_capteur);
	b=0;
	}
	else {
		  gtk_widget_hide(verif_type_ajout_capteur);
	}
	if(strcmp(c.marque,"")==0){
		  gtk_widget_show (verif_marque_ajout_capteur);
	b=0;
	}
	else {
		  gtk_widget_hide(verif_marque_ajout_capteur);
	}

}

void on_button_modifier_capteur_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{Capteur c;
	GtkWidget* output,*entry_serie,*entry_nom,*jour,*mois,*annee,*combobox1,*entry_marque ;
	char rech_serie[20];
	GSList *List;
	GtkWidget *radioButtondef,*radioButtonindef;
	radioButtondef=lookup_widget(objet_graphique,"radiobutton_defectueux_modif");
	radioButtonindef=lookup_widget(objet_graphique,"radiobutton_indefectueux_modif");
	List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radioButtondef));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
		strcpy(c.etat,gtk_button_get_label(GTK_BUTTON(List->data)));
	else{
		List = g_slist_next(List);
		strcpy(c.etat,gtk_button_get_label(GTK_BUTTON(List->data)));}   
		            
	//associer les objets avec des variables
	entry_serie=lookup_widget(objet_graphique, "entry_serie_modif");
	entry_nom=lookup_widget(objet_graphique, "entry_nom_modif");
	entry_marque=lookup_widget(objet_graphique, "entry_marque_modif");
	jour=lookup_widget(objet_graphique, "spinbutton_jour_modif");
	mois=lookup_widget(objet_graphique, "spinbutton_mois_modif");
	annee=lookup_widget(objet_graphique, "spinbutton_annee_modif");
	combobox1=lookup_widget(objet_graphique, "combobox_modifier_capteur");

	//recuperer les variables
	strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	c.date_achat.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
	c.date_achat.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
	c.date_achat.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
	strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entry_nom)));
	strcpy(c.serie,gtk_entry_get_text(GTK_ENTRY(entry_serie)));
	strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(entry_marque)));
	GtkWidget *label_serie;
	
	label_serie=lookup_widget(objet_graphique,"ancien_serie");
	strcpy(rech_serie,gtk_label_get_text(label_serie));
	modifier_capteur(rech_serie,c);

}



void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
  {x=1;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
  {x=2;}
}


void
on_treeview1A_row_activated             (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
/*GtkTreeIter iter;

gchar *nom,*type,*etat,*serie;
Date date_achat;
gint *jour,*mois,*annee;
Capteur c;

GtkTreeModel *model = gtk_tree_view_get_model(treeview1);

	if (gtk_tree_model_get_iter(model, &iter,path))
	{   
     //obtention des valeurs de la ligne selectionnee
     
     gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0, &serie, 1 , &nom, 2, &type, 3, &etat, 4, &jour, 5, &mois, 6, &annee, -1);
     //copie des valeurs dans la variable c de type capteur pour le passer a la fonction de suppression
     	strcpy(c.serie,serie);
	strcpy(c.nom,nom);
	strcpy(c.type,type);
	strcpy(c.etat,etat);
	strcpy(c.date_achat.jour,jour);
	strcpy(c.date_achat.mois,mois);
	strcpy(c.date_achat.annee,annee);
     //appel de la fonction de suppression
    supprimer_capteur(
 serie[20] );
    //lise a jour de l'affichage de la treeview
    afficher_capteur(treeview1);
 	 }*/
}




void on_treeview_capt_ouvrier_row_activated             (GtkTreeView     *treeview_capt_ouvrier,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *serie,*nom, *type,*etat;
gint *jour,*mois,*annee;
Date date_achat;
Capteur c;

GtkTreeModel *model = gtk_tree_view_get_model(treeview_capt_ouvrier);

	if (gtk_tree_model_get_iter(model, &iter,path))
	{   
     //obtention des valeurs de la ligne selectionnee
     
     gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0, &serie, 1 , &nom, 2, &type, 3, &etat, 4, &jour, 5, &mois, 6, &annee, -1);
     //copie des valeurs dans la variable c de type capteur pour le passer a la fonction de suppression
     	strcpy(c.serie,serie);
	strcpy(c.nom,nom);
	strcpy(c.type,type);
	strcpy(c.etat,etat);
	strcpy(c.date_achat.jour,jour);
	strcpy(c.date_achat.mois,mois);
	strcpy(c.date_achat.annee,annee);
     //appel de la fonction de suppression
       supprimer_capteur(serie[20] );

    //lise a jour de l'affichage de la treeview
    afficher_capteur(treeview_capt_ouvrier);
 	 }
}

void
on_button_afficher_admin_clicked       (GtkWidget       *objet,    // le contenu de trevieu2 dans treview1
                                        gpointer         user_data)
{
GtkWidget *ajout_capteur;
GtkWidget *Afficher_capteur;
GtkWidget *treeview1;

treeview1=lookup_widget(objet,"treeview_capteur_admin");
afficher_capteur2(treeview1);
}


void
on_button_ajouter_ouvrier_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
Capteur c;
GSList *List;
GtkWidget *input1, *input2 ,*input3, *input4 ,*input5 ,*input6 ,*input7;
GtkWidget *ajout_capteur;

ajout_capteur=lookup_widget(objet,"ajout_capteur");
ajout_capteur=create_ajout_capteur();
gtk_widget_show(ajout_capteur);

/*
input1=lookup_widget(objet,"serie");
input2=lookup_widget(objet,"nom");
input3=lookup_widget(objet,"type");
input4=lookup_widget(objet,"etat");
input5=lookup_widget(objet,"jour");
input6=lookup_widget(objet,"mois");
input7=lookup_widget(objet,"annee");

strcpy(c.serie,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.type,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.etat,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.date_achat.jour,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.date_achat.mois,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(c.date_achat.annee,gtk_entry_get_text(GTK_ENTRY(input7)));

ajouter_capteur(c);*/
}


void
on_button_supprimer_ouvrier_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f;
	GtkWidget *fenetre_supprimer,*entry_serie;
	char get_serie[20];
	char nom[20],serie[20],type[20],etat[20],serie2[20];
	int jour,mois,annee;
	entry_serie=lookup_widget(button,"entry_ref_capt_ouvrier");
        strcpy(serie,gtk_entry_get_text(entry_serie));
	g_print("%s\n",serie);
        supprimer_capteur(serie );
}


void
on_button_modifier_ouvrier_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	FILE *f;
	GtkWidget *fenetre_modifier,*entry_serie;
	char get_serie[20];
	char nom[20],serie[20],type[20],etat[20],serie2[20],marque[20],date[20];
	int jour,mois,annee;
	
	entry_serie=lookup_widget(button,"entry_ref_capt_ouvrier");
	int test=0;
	f=fopen("capteur.txt","r");
	
	
	while (fscanf(f,"%s %s %s %s %d %d %d %s\n",nom,serie,type,marque,&jour,&mois,&annee,etat)!=EOF)
	{
		if (strcmp(gtk_entry_get_text(GTK_ENTRY(entry_serie)),serie)==0)
			{test=1;break;}
	}
	fclose(f);

	if (test==1){
		
		fenetre_modifier=lookup_widget(button,"modifier_capteur");
		fenetre_modifier=create_modifier_capteur();
               
		gtk_widget_show(fenetre_modifier);
		GtkWidget *label_serie,*label_nom,*label_type,*label_marque,*label_date,*label_etat;
		label_serie=lookup_widget(fenetre_modifier,"ancien_serie");
		label_nom=lookup_widget(fenetre_modifier,"ancien_nom");
		label_type=lookup_widget(fenetre_modifier,"ancien_type");
		label_marque=lookup_widget(fenetre_modifier,"ancienne_marque");
		label_date=lookup_widget(fenetre_modifier,"ancienne_date");
		label_etat=lookup_widget(fenetre_modifier,"ancien_etat");
		gtk_label_set_text(GTK_LABEL(label_serie),serie);
		gtk_label_set_text(GTK_LABEL(label_nom),nom);	
		gtk_label_set_text(GTK_LABEL(label_type),type);
		gtk_label_set_text(GTK_LABEL(label_marque),marque);
		sprintf(date,"%d/%d/%d",jour,mois,annee);
		gtk_label_set_text(GTK_LABEL(label_date),date);
		gtk_label_set_text(GTK_LABEL(label_etat),etat);
		
	}
	else return ;


	
}


void
on_button_afficher_ouvrier_clicked     (GtkWidget       *objet,    
                                        gpointer         user_data)
{
GtkWidget *ajout_capteur;
GtkWidget *affichage_admin;
GtkWidget *treeview_capt_ouvrier,*treeview1;
treeview1=lookup_widget(objet,"treeview_capt_ouvrier");
afficher_capteur(treeview1);
}



void
on_treeview_valeurs_alarmante_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


}

/*
void
on_button_afficher_val_al_clicked      (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *capteurs_valeurs;

capteurs_valeurs=lookup_widget(objet,"capteurs_valeurs");
capteurs_valeurs=create_capteurs_valeurs();
	gtk_widget_show(capteurs_valeurs);

}
*/

void
on_treeview_capt_def_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}



void
on_button_ajout_valeur_capt_ouvr_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *valeurs_capt;
	valeurs_capt=lookup_widget(button,"valeurs_capt");
	valeurs_capt=create_valeurs_capt();
	gtk_widget_show(valeurs_capt);
}


void
on_button_valeur_alarmante_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *window_numero_alarmante ,*treeview1 , *treeview_capt_ouvrier ;
	window_numero_alarmante=lookup_widget(button,"window_numero_alarmante");
	window_numero_alarmante=create_window_numero_alarmante();
	gtk_widget_show(window_numero_alarmante);

treeview1=lookup_widget(window_numero_alarmante,"treeviewtemper");
treeview_capt_ouvrier=lookup_widget(window_numero_alarmante,"treeviewhumidite");

capteurhorsintertemp(treeview1); 
capteurhorsinterhumid(treeview_capt_ouvrier); 
}

/*
void on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *marque_capteur_def ,*treeview ;
int m ; 
	marque_capteur_def=lookup_widget(button,"marque_capteur_def");
	marque_capteur_def=create_marque_capteur_def();
	gtk_widget_show(marque_capteur_def);
treeview=lookup_widget(marque_capteur_def,"treeviewcaptdef");

defaillance() ;
m=max(); 
afficherCapt(treeview,m) ; 
}*/




void
on_button_verifier_valeur_capteur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *entry_serie,*entry_valeur;
	char serie[30],valeur[30];
	entry_serie=lookup_widget(button,"entry_serie");
	entry_valeur=lookup_widget(button,"entry_valeur");
	strcpy(serie,gtk_entry_get_text(entry_serie));
	strcpy(valeur,gtk_entry_get_text(entry_valeur));
	ajouter_valeur(serie,atoi(valeur));
}


void
on_button_retour_numero_alarmante_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *window_numero_alarmante;
	window_numero_alarmante=lookup_widget(button,"window_numero_alarmante");
	gtk_widget_destroy(window_numero_alarmante);
}


void
on_button_retour_val_alarmante_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *capteurs_valeurs;
	capteurs_valeurs=lookup_widget(button,"capteurs_valeurs");
	gtk_widget_destroy(capteurs_valeurs);
}


void
on_button_retour_valeur_capteur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *valeurs_capt;
	valeurs_capt=lookup_widget(button,"valeurs_capt");
	gtk_widget_destroy(valeurs_capt);
}


void
on_button_retour_max_def_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *marque_capteur_def;
	marque_capteur_def=lookup_widget(button,"marque_capteur_def");
	gtk_widget_destroy(marque_capteur_def);
}


void
on_button_afficher_val_al_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview;
	treeview=lookup_widget(button,"treeview_valeurs");
	affiche_valeur(treeview);
}


void
on_button_afficher_valeur_cap_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *capteurs_valeurs;
	capteurs_valeurs=lookup_widget(button,"capteurs_valeurs");
	capteurs_valeurs=create_capteurs_valeurs();
	gtk_widget_show(capteurs_valeurs);
}
void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c ;
GSList *List;

GtkWidget *label_verif_cin_client;
GtkWidget *label_verif_nom_client;
GtkWidget *label_verif_prenom_client;
GtkWidget *label_verif_mail_client;
GtkWidget *label_verif_num_client;

GtkWidget *input1, *input2, *input3, *input4 ,*input5,*input6,*input7,*input8;
char sexe[20];
int b=1;
int jour,mois,annee;
GtkWidget *existe;
GtkWidget* success;
GtkWidget *fenetre_ajout;
GtkWidget *radiobutton_homme,*radiobutton_femme;

	radiobutton_homme=lookup_widget(objet,"radiobutton5Client");
	radiobutton_femme=lookup_widget(objet,"radiobutton4Client");
	List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton_homme));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
	strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));	
	else{
		List = g_slist_next(List);
		strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));
}
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
input1=lookup_widget(objet,"cin");
input2=lookup_widget(objet,"nom");
input3=lookup_widget(objet,"prenom");
input4=lookup_widget(objet,"mail");
input5=lookup_widget(objet,"num");
input6=lookup_widget(objet,"spinbutton8Client");
input7=lookup_widget(objet,"spinbutton9Client");
input8=lookup_widget(objet,"spinbutton10Client");
g_print("1");
label_verif_cin_client=lookup_widget(objet,"label_verif_cin_client");
label_verif_nom_client=lookup_widget(objet,"label_verif_nom_client");
label_verif_prenom_client=lookup_widget(objet,"label_verif_prenom_client");
label_verif_mail_client=lookup_widget(objet,"label_verif_mail_client");
label_verif_num_client=lookup_widget(objet,"label_verif_num_client");
g_print("2");
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.mail,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.num,gtk_entry_get_text(GTK_ENTRY(input5)));
g_print("3");
strcpy(c.sexe,sexe);
existe=lookup_widget(objet,"label_existeclient");
success=lookup_widget(objet,"label_succesclient");
gtk_widget_hide (success);
//controle de saisie
if(strcmp(c.cin,"")==0){
		  gtk_widget_show (label_verif_cin_client);
b=0;
}
else {
		  gtk_widget_hide(label_verif_cin_client);
}

if(strcmp(c.nom,"")==0){
		  gtk_widget_show (label_verif_nom_client);
b=0;
}
else {
		  gtk_widget_hide(label_verif_nom_client);
}
if(strcmp(c.prenom,"")==0){
		  gtk_widget_show (label_verif_prenom_client);
b=0;
}
else {
		  gtk_widget_hide(label_verif_prenom_client);
}
if(strcmp(c.mail,"")==0){
		  gtk_widget_show (label_verif_mail_client);
b=0;
}
else {
		  gtk_widget_hide(label_verif_mail_client);
}
if(strcmp(c.num,"")==0){
		  gtk_widget_show (label_verif_num_client);
b=0;
}
else {
		  gtk_widget_hide(label_verif_num_client);
}

if(b==1){

        if(exist_client(c.cin)==1)
        {
		gtk_widget_show (existe);
        }
        else {g_print("4");
		gtk_widget_hide (existe);
		jour=gtk_spin_button_get_value_as_int(input6);
		mois=gtk_spin_button_get_value_as_int(input7);
		annee=gtk_spin_button_get_value_as_int(input8);
		g_print("5");
                ajouter_client(c,jour,mois,annee);
		gtk_widget_show (success);
 
       }

}
}

//////////////////////////////////////////////////////////////////////////////////////////


void
on_afficher_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_ajout;
	GtkWidget *Afficher_client;
	GtkWidget *treeview1;

	fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
        gtk_widget_destroy(fenetre_ajout);
	Afficher_client=lookup_widget(objet,"Afficher_client");
	Afficher_client=create_Afficher_client();
	gtk_widget_show(Afficher_client);
	treeview1=lookup_widget(Afficher_client,"treeview1Client");
        afficher_client(treeview1,0);

}
//////////////////////////////////////////////////////////////////////////////////


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
	gchar* cin;
	gchar* nom;
	gchar* prenom;
	gchar* num;
	gchar* mail;	
	gchar* sexe;
	gchar* date;
	client c;
	 int x;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
//obtention des valeurs à partir de la ligne selectionné
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,1,&nom,2,&prenom,3,&num,4,&mail,5,&sexe,6,&date -1);
//copier les valeurs dans la variable c de type client
strcpy(c.cin,cin);
strcpy(c.nom,nom);
strcpy(c.prenom,prenom);
strcpy(c.num,num);
strcpy(c.mail,mail);
strcpy(c.sexe,sexe);
//appel de la fonction suppression
g_print("1");
supprimer_client(c);
g_print("2");
//mise à jour de l'affichage de treeview
afficher_client(treeview,0);
g_print("3");
}




}


void
on_rechercher_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{





}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_retour_clicked                      (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Afficher_client, *fenetre_ajout;
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
gtk_widget_destroy(fenetre_ajout);
Afficher_client=create_Afficher_client();
gtk_widget_show(Afficher_client);

}

///////////////////////////////////////////////////////////////////////////////////////////////////
void
on_modifier_clicked                    (GtkButton      *objet,
                                        gpointer         user_data)
{
client c ;
GSList *List;
GtkWidget *input1, *input2, *input3, *input4 ,*input5, *modificationclient, *clientexistant;
GtkWidget *labelmodifnom,*labelmodifprenom,*labelmodifcin,*labelmodifmail,*labelmodifnum;
char sexe[20];
int b=1;
g_print("1");
GtkWidget *radiobutton_hommemodif,*radiobutton_femmemodif;
	radiobutton_hommemodif=lookup_widget(objet,"radiobutton7Client");
	radiobutton_femmemodif=lookup_widget(objet,"radiobutton6Client");
	List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton_hommemodif));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
	strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));	
	else{
		List = g_slist_next(List);
		strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));
}
g_print("2");
input1=lookup_widget(objet,"entry_nom_modifier");
input2=lookup_widget(objet,"entry_prenom_modifier");
input3=lookup_widget(objet,"entry_cin_modifier");
input4=lookup_widget(objet,"entry_mail_modifier");
input5=lookup_widget(objet,"entry_num_modifier");
labelmodifnom=lookup_widget(objet,"labelmodifnom");
labelmodifprenom=lookup_widget(objet,"labelmodifprenom");
labelmodifcin=lookup_widget(objet,"labelmodifcin");
labelmodifmail=lookup_widget(objet,"labelmodifmail");
labelmodifnum=lookup_widget(objet,"labelmodifnum");
modificationclient=lookup_widget(objet,"modificationclient");
clientexistant=lookup_widget(objet,"clientexistant");
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.mail,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.num,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.sexe,sexe);
g_print("3");
if(strcmp(c.cin,"")==0){
		  gtk_widget_show (labelmodifcin);
b=0;
}
else {
		  gtk_widget_hide(labelmodifcin);
}

if(strcmp(c.nom,"")==0){
		  gtk_widget_show (labelmodifnom);
b=0;
}
else {
		  gtk_widget_hide(labelmodifnom);
}
if(strcmp(c.prenom,"")==0){
		  gtk_widget_show (labelmodifprenom);
b=0;
}
else {
		  gtk_widget_hide(labelmodifprenom);
}
if(strcmp(c.mail,"")==0){
		  gtk_widget_show (labelmodifmail);
b=0;
}
else {
		  gtk_widget_hide(labelmodifmail);
}
if(strcmp(c.num,"")==0){
		  gtk_widget_show (labelmodifnum);
b=0;
}
else {
		  gtk_widget_hide(labelmodifnum);
}

g_print("4");

if(b==1){

        if(exist_client(c.cin)==1)
        {g_print("5");
				  Modifier_client(c);g_print("6");
				  gtk_widget_show (modificationclient);
        }
        else {g_print("7");
						  gtk_widget_hide (modificationclient);g_print("8");
               

						  gtk_widget_show (clientexistant);g_print("9");
        }

}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////:

void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


}


void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


}


void
on_radiobutton_femmemodif_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


}


void
on_radiobutton_hommemodif_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_modifaj_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{

	GtkWidget *fenetre_ajout;
	GtkWidget *Modifier_client;

	fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
        gtk_widget_destroy(fenetre_ajout);
	//GtkWidget Afficher_client;
	Modifier_client=lookup_widget(objet,"Modifier_client");
	Modifier_client=create_Modifier_client();
	gtk_widget_show(Modifier_client);




}


void
on_retour_client_clicked               (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *Modifier_client;
Modifier_client=lookup_widget(objet,"Modifier_client");
gtk_widget_destroy(Modifier_client);
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);

}

void
on_rechercher_client_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *recherche_client,*treeview;
	recherche_client=lookup_widget(button,"entry_recherche_client");
	treeview=lookup_widget(button,"treeview1Client");
	strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(recherche_client)));
	rechercher_client(c.cin);
	afficher_client(treeview,1);
}


void
on_nom2_changed                         (GtkEditable     *editable,
                                        gpointer         user_data)
{
	GtkWidget *entry_nom,*verif;
	entry_nom=lookup_widget(editable,"nom");
	verif=lookup_widget(editable,"label_verif_nom_client");
	strcpy(c.nom,gtk_entry_get_text(entry_nom));
	char nom[20];
	int test=1;
	int i ;
	for (i=0;i<strlen(c.nom);i++)
	{
		if (((c.nom[i]<65)||(c.nom[i]>90))||((c.nom[i]<97)||(c.nom[i]>122)))
			{test=0;break;}
	
	}
		
	
	
	if ((strcmp(c.nom,"")==0)||(test==0))
		gtk_widget_show(verif);
	else gtk_widget_hide(verif);
}


void
on_prenom_changed                      (GtkEditable     *editable,
                                        gpointer         user_data)
{
	GtkWidget *entry_prenom,*verif;
	entry_prenom=lookup_widget(editable,"prenom");
	verif=lookup_widget(editable,"label_verif_prenom_client");
	strcpy(c.prenom,gtk_entry_get_text(entry_prenom));
	char prenom[10];
	int test=1;
	int i;
	for (i=0;i<strlen(c.prenom);i++)
	{
		if (((c.prenom[i]<65)||(c.prenom[i]>90))||((c.prenom[i]<97)||(c.prenom[i]>122)))
			{test=0;break;}
	
	}
		
	
	
	if ((strcmp(c.prenom,"")==0)||(test==0))
		gtk_widget_show(verif);
	else gtk_widget_hide(verif);
}


void
on_cin_changed                         (GtkEditable     *editable,
                                        gpointer         user_data)
{
GtkWidget *entry_cin,*verif;
	entry_cin=lookup_widget(editable,"cin");
	
	verif=lookup_widget(editable,"label_verif_cin_client");
	strcpy(c.cin,gtk_entry_get_text(entry_cin));
	
	char cin[10];
        int test=1;
	int i;
	for (i=0;i<strlen(c.cin);i++)
	{
		if ((c.cin[i]<48)||(c.cin[i]>57))
			{test=0;break;}
	
	}
		
	//g_print("%d\n",test);
	
	if ((strlen(c.cin)!=8)||(test==0))
		gtk_widget_show(verif);
	else gtk_widget_hide(verif);
}



void
on_mail_changed                        (GtkEditable     *editable,
                                        gpointer         user_data)
{
	GtkWidget *entry_mail;
	char mail[30];
	char *token;
	const char a[2] = "@";
	entry_mail=lookup_widget(editable,"mail");
	strcpy(mail,gtk_entry_get_text(entry_mail));
	
	/*if 
		gtk_widget_show(verif);
	else gtk_widget_hide(verif);*/
}


void
on_num_changed                         (GtkEditable     *editable,
                                        gpointer         user_data)
{
	client c;
	GtkWidget *entry_num,*verif;
	entry_num=lookup_widget(editable,"num");
	
	verif=lookup_widget(editable,"label_verif_num_client");
	strcpy(c.num,gtk_entry_get_text(entry_num));
	
	char num[10];
        int test=1;
	int i;
	for (i=0;i<strlen(c.num);i++)
	{
		if ((c.num[i]<48)||(c.num[i]>57))
			{test=0;break;}
	
	}
		
	//g_print("%d\n",test);
	
	if ((strlen(c.num)!=8)||(test==0))
		gtk_widget_show(verif);
	else gtk_widget_hide(verif);

}


void
on_button_ajout_accueil_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *Afficher_client;
Afficher_client=lookup_widget(objet,"Afficher_client");
gtk_widget_destroy(Afficher_client);
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);

}


void
on_button_modifier_Accueil_clicked     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Modifier_client, *Gestion_client;
Gestion_client=lookup_widget(objet,"Gestion_client");
gtk_widget_destroy(Gestion_client);
Modifier_client=create_Modifier_client();
gtk_widget_show(Modifier_client);

}


void
on_button_afficher_accueil_clicked     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Afficher_client, *Gestion_client;
Gestion_client=lookup_widget(objet,"Gestion_client");
gtk_widget_destroy(Gestion_client);
Afficher_client=create_Afficher_client();
gtk_widget_show(Afficher_client);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int x=1;
/*
void
on_Gestion_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GestionOuvriers,*Acceuil;
    GestionOuvriers=lookup_widget(button,"GestionOuvriers");
    Acceuil=lookup_widget(button,"Acceuil");
    gtk_widget_hide(Acceuil);
 GestionOuvriers = create_GestionOuvriers();
 gtk_widget_show(GestionOuvriers);
}*/

/*********************************************************************************************************************************************/

void
on_samarretour1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *espace_admin,*GestionOuvriers;
 GestionOuvriers=lookup_widget(button,"GestionOuvriers");
 gtk_widget_destroy(GestionOuvriers);
 espace_admin = create_espace_admin();
 gtk_widget_show(espace_admin);
}
/*********************************************************************************************************************************************/
void
on_logout1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GestionOuvriers;
 GestionOuvriers=lookup_widget(button,"GestionOuvriers");
 gtk_widget_hide(GestionOuvriers);
}
/*********************************************************************************************************************************************/

void
on_ModifierOuvrier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GestionOuvriers,*ModifierOuvrier;
 GestionOuvriers=lookup_widget(button,"GestionOuvriers");
 ModifierOuvrier=lookup_widget(button,"ModifierOuvrier");
 gtk_widget_hide(GestionOuvriers);
 ModifierOuvrier = create_ModifierOuvrier();
 gtk_widget_show(ModifierOuvrier);
}

/*********************************************************************************************************************************************/
void
on_AjouterOuvrier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GestionOuvriers,*AjouterOuvrier;
GestionOuvriers=lookup_widget(button,"GestionOuvriers");
AjouterOuvrier=lookup_widget(button,"AjouterOuvrier");
gtk_widget_hide(GestionOuvriers);
AjouterOuvrier=create_AjouterOuvrier();
gtk_widget_show(AjouterOuvrier);
}

/*********************************************************************************************************************************************/
void
on_RechercherOuvrier_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GestionOuvriers,*entrycinouvrier,*treeviewrech,*outputMsg,*inexistantt,*res,*msgsupp;
   int verif;
   char ch[9];  
GestionOuvriers=lookup_widget(button,"GestionOuvriers");
entrycinouvrier=lookup_widget(button,"entrycinouvrier");
treeviewrech=lookup_widget(button,"treeviewrech");
inexistantt=lookup_widget(button,"labelb29");
msgsupp=lookup_widget(button,"msgsupp");
//res=lookup_widget(button,"res");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entrycinouvrier)));
verif=exist_ouvrier(ch);
switch(verif)   
{
    case 0:  
    {  // gtk_widget_hide (res);
	gtk_widget_hide (msgsupp);
	gtk_widget_show (inexistantt);

    }
    break;
    case 1:
   
    {g_print("%s",ch);  
	rechercher_ouvrier(treeviewrech, ch);
       remove(treeviewrech);
	gtk_widget_hide (inexistantt);
	gtk_widget_hide (msgsupp);
	//gtk_widget_show (res);
       
      }
    break; 
    break;}
}


/*********************************************************************************************************************************************/
void
on_samarretour2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AjouterOuvrier,*GestionOuvriers;
 AjouterOuvrier=lookup_widget(button,"AjouterOuvrier");
 GestionOuvriers=lookup_widget(button,"GestionOuvriers");
 gtk_widget_hide(AjouterOuvrier);
 GestionOuvriers = create_GestionOuvriers();
 gtk_widget_show(GestionOuvriers);
}
/*********************************************************************************************************************************************/

void
on_logout2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AjouterOuvrier;
 AjouterOuvrier=lookup_widget(button,"AjouterOuvrier");

 gtk_widget_hide(AjouterOuvrier);
}

/*********************************************************************************************************************************************/
void
on_logout3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ModifierOuvrier;
 ModifierOuvrier=lookup_widget(button,"ModifierOuvrier");
 gtk_widget_hide(ModifierOuvrier);
}

/*********************************************************************************************************************************************/
void
on_samarretour3_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ModifierOuvrier,*GestionOuvriers;
 ModifierOuvrier=lookup_widget(button,"ModifierOuvrier");
 GestionOuvriers=lookup_widget(button,"GestionOuvriers");
 gtk_widget_hide(ModifierOuvrier);
 GestionOuvriers = create_GestionOuvriers();
 gtk_widget_show(GestionOuvriers);
}



/*********************************************************************************************************************************************/
void
on_Refresh_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeviewrech;
treeviewrech=lookup_widget(button,"treeviewrech");
afficher_ouvrier(treeviewrech);
}
/*********************************************************************************************************************************************/

void
on_AjouterOuvrier1_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

infoouvrier o;
Date naissance;
GSList *List;
GtkWidget *AjouterOuvrier;
GtkWidget *entryCin,*entryNom,*entryPrenom,*entryadr,*entryNumtel,*entrynumabs;
GtkWidget *jour,*mois,*annee,*spinbuttonnbre;
GtkWidget *labelCin,*labelnom,*labelprenom,*labeladr,*labelnumtel,*labelnumabs;
GtkWidget *existe,* successs;
GtkWidget *radiobutton_homme,*radiobutton_femme;
char sexe[10];
int b=1;
char cin[9];
char nom[20];
char prenom[20];
int test=1;
int i;

	
	radiobutton_homme=lookup_widget(button,"radiobutton1");
	radiobutton_femme=lookup_widget(button,"radiobutton2");
	List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton_homme));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
	strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));	
	else{
		List = g_slist_next(List);
		strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));}
AjouterOuvrier=lookup_widget(button,"AjouterOuvrier");
entryCin=lookup_widget(button,"samarentry7");
entryNom=lookup_widget(button,"samarentry8");
entryPrenom=lookup_widget(button,"samarentry9");
jour=lookup_widget(button,"samarspinbutton1");
mois=lookup_widget(button,"samarspinbutton2");
annee=lookup_widget(button,"samarspinbutton3");
entryadr=lookup_widget(button,"samarentry11");
entryNumtel=lookup_widget(button,"samarentry12");
entrynumabs=lookup_widget(button,"entrynumabs");
spinbuttonnbre=lookup_widget(button,"spinbuttonnbre");

labelCin=lookup_widget(button,"samarlabel1");
labelnom=lookup_widget(button,"samarlabel2");
labelprenom=lookup_widget(button,"samarlabel3");
labeladr=lookup_widget(button,"samarlabel4");
labelnumtel=lookup_widget(button,"samarlabel5");
labelnumabs=lookup_widget(button,"samarlabel6");


existe=lookup_widget(button,"samarlabelexist");
successs=lookup_widget(button,"samarlabelsuccesss");
        strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(entryCin) ) );
        strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(entryNom) ) );
        strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(entryPrenom) ) );
	strcpy(o.sexe,sexe);
	o.naissance.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
	o.naissance.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
	o.naissance.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee));
        strcpy(o.adr,gtk_entry_get_text(GTK_ENTRY(entryadr) ) );
        strcpy(o.numtel,gtk_entry_get_text(GTK_ENTRY(entryNumtel) ) );
	o.nbre_abs=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbuttonnbre));

// controle saisie
if(strcmp(o.cin,"")==0){
		  gtk_widget_show (labelCin);
		  b=0;
}
else {
		  gtk_widget_hide(labelCin);
}

if(strcmp(o.nom,"")==0){
		  gtk_widget_show (labelnom);
		  b=0;
}
else {
		  gtk_widget_hide(labelnom);
}
if(strcmp(o.prenom,"")==0){
		  gtk_widget_show (labelprenom);
		  b=0;
}
else {
		  gtk_widget_hide(labelprenom);
}
if(strcmp(o.adr,"")==0){
		  gtk_widget_show (labeladr);
		  b=0;
}
else {
		  gtk_widget_hide(labeladr);
}
if(strcmp(o.numtel,"")==0){
		  gtk_widget_show (labelnumtel);
		  b=0;
}
else {
		  gtk_widget_hide(labelnumtel);
}
////////cntrl cin/////
/*for (i=0;i<strlen(o.cin);i++)
	{
		if ((o.cin[i]<48)||(o.cin[i]>57))
			{test=0;break;}
	
	}
		
	//g_print("%d\n",test);
	
	if ((strlen(o.cin)!=8)||(test==0))
		{gtk_widget_show(labelCin);
		 b=0;}
	else gtk_widget_hide(labelCin);*/
/////cntrl nom/////
/*for (i=0;i<strlen(o.nom);i++)
	{if (((o.nom[i]<65)||(o.nom[i]>90))||((o.nom[i]<97)||(o.nom[i]>122)))
			{test=0;break;}
	
	}
if ((strcmp(o.nom,"")==0)||(test==0))
{gtk_widget_show(labelnom);
b=0;}
else gtk_widget_hide(labelnom);*/
/////cntrl prenom/////

if(b==1){ if(exist_ouvrier(o.cin)==1)
        {gtk_widget_hide (successs); 
	 gtk_widget_show (existe);}
        else {  gtk_widget_hide (existe);
                gtk_widget_show (successs);
                 ajouter_ouvrier(o);}

}
}
/*********************************************************************************************************************************************/

void
on_AfficherOuvrier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GestionOuvriers,*treeviewrech;
infoouvrier o;
GestionOuvriers=lookup_widget(button,"GestionOuvriers");
treeviewrech=lookup_widget(GestionOuvriers,"treeviewrech");
afficher_ouvrier(treeviewrech);
}

/*********************************************************************************************************************************************/
void
on_ModifierOuvrier1_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *ModifierOuvrier;
GSList *List;
GtkWidget *entryCin,*entryNom,*entryPrenom,*entryadr,*entryNumtel;
GtkWidget *jour,*mois,*annee,*nbr;
GtkWidget *labelCin,*labelnom,*labelprenom,*labeladr,*labelnumtel;
GtkWidget *succeed,*inexist;
GtkWidget *radiobutton_homme,*radiobutton_femme;
infoouvrier o;
char sexe[10];
int b=1;
	radiobutton_homme=lookup_widget(button,"radiobutton3");
	radiobutton_femme=lookup_widget(button,"radiobutton4");
	List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton_homme));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
	strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));	
	else{
		List = g_slist_next(List);
		strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));}
ModifierOuvrier=lookup_widget(button,"ModifierOuvrier");
entryCin=lookup_widget(button,"entrymodifcin");
entryNom=lookup_widget(button,"entrymodifnom");
entryPrenom=lookup_widget(button,"entrymodifprenom");
jour=lookup_widget(button,"spinbutton4");
mois=lookup_widget(button,"spinbutton5");
annee=lookup_widget(button,"spinbutton6");
entryadr=lookup_widget(button,"entrymodifadresse");
entryNumtel=lookup_widget(button,"entrymodifnumtel");
nbr=lookup_widget(button,"spinbutton7");

labelCin=lookup_widget(button,"samarlabel77");
labelnom=lookup_widget(button,"samarlabel877");
labelprenom=lookup_widget(button,"samarlabel79");
labeladr=lookup_widget(button,"samarlabel81");
labelnumtel=lookup_widget(button,"samarlabel83");
succeed=lookup_widget(button,"modifsucceed");
inexist=lookup_widget(button,"cininexist");
	strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(entryCin) ) );
        strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(entryNom) ) );
        strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(entryPrenom) ) );
	strcpy(o.sexe,sexe);
	o.naissance.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
	o.naissance.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
	o.naissance.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee));
        strcpy(o.adr,gtk_entry_get_text(GTK_ENTRY(entryadr) ) );
        strcpy(o.numtel,gtk_entry_get_text(GTK_ENTRY(entryNumtel) ) );
	o.nbre_abs=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nbr));
gtk_widget_hide (succeed);
gtk_widget_hide (inexist);
// controle saisie
if(strcmp(o.cin,"")==0){
		  gtk_widget_show (labelCin);
		  b=0;
}
else {
		  gtk_widget_hide(labelCin);
}

if(strcmp(o.nom,"")==0){
		  gtk_widget_show (labelnom);
		  b=0;
}
else {
		  gtk_widget_hide(labelnom);
}
if(strcmp(o.prenom,"")==0){
		  gtk_widget_show (labelprenom);
		  b=0;
}
else {
		  gtk_widget_hide(labelprenom);
}
if(strcmp(o.adr,"")==0){
		  gtk_widget_show (labeladr);
		  b=0;
}
else {
		  gtk_widget_hide(labeladr);
}
if(strcmp(o.numtel,"")==0){
		  gtk_widget_show (labelnumtel);
		  b=0;
}
else {
		  gtk_widget_hide(labelnumtel);
}

if(b==1){
        if(exist_ouvrier(o.cin)==1)
        {  modifier_ouvrier(o);
	 gtk_widget_show (succeed);			  
        }
        else {  gtk_widget_hide (succeed);
              gtk_widget_show (inexist); }

}
}


/*********************************************************************************************************************************************/

void
on_SupprimerOuvrier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entrycinouvrier,*inexistantt,*msgsupp,*label,*res;
infoouvrier o;
char cin[9];
entrycinouvrier=lookup_widget(button,"entrycinouvrier");
inexistantt=lookup_widget(button,"labelb29");
label=lookup_widget(button,"label50cin");
msgsupp=lookup_widget(button,"msgsupp");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(entrycinouvrier)));

if(exist_ouvrier(cin)==1)
 {gtk_widget_hide (inexistantt);
 gtk_widget_hide (label);			
supprimer_ouvrier(cin);
gtk_widget_show (msgsupp); }
else if(strcmp(o.cin,"")==0){gtk_widget_hide (inexistantt);
				gtk_widget_hide (msgsupp);
				gtk_widget_show (label);}
else { 
		gtk_widget_hide (label);
		gtk_widget_hide (msgsupp);
		gtk_widget_show (inexistantt);}

}
/*********************************************************************************************************************************************/

void
on_Absenteisme_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GestionOuvriers,*AjouterAbsence;
    GestionOuvriers=lookup_widget(button,"GestionOuvriers");
    AjouterAbsence=lookup_widget(button,"AjouterAbsence");
    gtk_widget_hide(GestionOuvriers);
 AjouterAbsence = create_AjouterAbsence();
 gtk_widget_show(AjouterAbsence);
}

/*********************************************************************************************************************************************/
void
on_samradiobutton6_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){x=0;}
}

/*********************************************************************************************************************************************/
void
on_samradiobutton5_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){x=1;}
}

/*********************************************************************************************************************************************/
void
on_Enregistrer_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GSList *List;
GtkWidget *AjouterAbsence,*AfficherAbsence,*entrycinabss;
GtkWidget *labelabssamarcin,*pointagesucceeded,*pointagefailed;
GtkWidget *jourr,*moiss,*anneee;
pointage p;
Datee;
entrycinabss=lookup_widget(button,"entrycinabss");
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(entrycinabss)));

jourr=lookup_widget(button, "spinbutton8s");
moiss=lookup_widget(button, "spinbutton9s");
anneee=lookup_widget(button, "spinbutton10s");

p.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourr));
p.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moiss));
p.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneee));


if(x==1)
{p.present=1;}

else 
{p.present=0;}
labelabssamarcin=lookup_widget(button,"labelabssamarcin");
pointagesucceeded=lookup_widget(button,"pointagesucceeded");
pointagefailed=lookup_widget(button,"pointagefailed");
enregristrer_absence (p);



if(strcmp(p.cin,"")==0){
		  gtk_widget_hide (pointagesucceeded);
		  gtk_widget_show (labelabssamarcin);
		  
}

else {
		  gtk_widget_hide(labelabssamarcin);
		  gtk_widget_show (pointagesucceeded);}

}
/*********************************************************************************************************************************************/
void
on_AfficherAbs_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AjouterAbsence,*AfficherAbsence,*treeviewabs;
AjouterAbsence=lookup_widget(button,"AjouterAbsence");
gtk_widget_hide(AjouterAbsence);
AfficherAbsence = create_AfficherAbsence();
gtk_widget_show (AfficherAbsence);
treeviewabs=lookup_widget(AfficherAbsence,"treeviewabs");
afficher_absence(treeviewabs);
}
/*********************************************************************************************************************************************/

void
on_treeviewabs_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* cin;
	gint* jour,*mois,*annee,*present;
	pointage p;
	
GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,1,&jour,2,&mois,3,&annee,4,&present, -1);
strcpy(p.cin,cin);
p.date.jour=jour;
p.date.mois=mois;
p.date.annee=annee;
p.present=present;
g_print("%d %d %d %d\n",p.date.jour,p.date.mois,p.date.annee,p.present);
supprimer_absence(p);
afficher_absence(treeview);
}
}

/*********************************************************************************************************************************************/
void
on_Taux0_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AjouterAbsence,*Taux;
 AjouterAbsence=lookup_widget(button,"AjouterAbsence");
 Taux=lookup_widget(button,"Taux");
 gtk_widget_hide(AjouterAbsence);
 Taux = create_Taux();
 gtk_widget_show(Taux);
}

/*********************************************************************************************************************************************/
void
on_Tauxabs_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Taux;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *sortiem;
GtkWidget *ta;
GtkWidget *pourcent ;
int mm;
int aa;
pointage p;
int tauxpresence=0;
char tauxtxt[200];
double absence;
double i=0;
float tauxabsence;
FILE *f=NULL;
mois=lookup_widget(button, "spinbutton4s");
annee=lookup_widget(button, "spinbutton5s");
mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
sortiem=lookup_widget(button, "label35ss");
ta=lookup_widget(button, "label38ss");
pourcent=lookup_widget(button, "label39ss");

    f=fopen("absences.txt","r");
    if(f!=NULL)
    {
        while((fscanf(f, "%s %d %d %d %d",p.cin,&p.date.jour,&p.date.mois,&p.date.annee,&p.present)!=EOF))

{
if((p.date.mois==mm)&&(p.date.annee==aa))

{
i++;
tauxpresence=tauxpresence+p.present;
}
}
fclose(f);
}
absence=i-tauxpresence;
tauxabsence=(absence/i)*100;

sprintf(tauxtxt,"%.2f",tauxabsence);
gtk_label_set_text(GTK_LABEL(ta),"Le taux d`absence est :");
gtk_label_set_text(GTK_LABEL(pourcent),"%");
gtk_label_set_text(GTK_LABEL(sortiem),tauxtxt);

return 0;

}

/*********************************************************************************************************************************************/
void
on_RetourP_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AjouterAbsence,*AfficherAbsence;
 AjouterAbsence=lookup_widget(button,"AjouterAbsence");
 AfficherAbsence=lookup_widget(button,"AfficherAbsence");
 gtk_widget_hide(AfficherAbsence);
 AjouterAbsence = create_AjouterAbsence();
 gtk_widget_show(AjouterAbsence);
}

/*********************************************************************************************************************************************/
void
on_logoutP_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AfficherAbsence;
 AfficherAbsence=lookup_widget(button,"AfficherAbsence");
 gtk_widget_hide(AfficherAbsence);
}

/*********************************************************************************************************************************************/
void
on_retourtaux_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Taux,*AjouterAbsence;
 AjouterAbsence=lookup_widget(button,"AjouterAbsence");
 Taux=lookup_widget(button,"Taux");
 gtk_widget_hide(Taux);
 AjouterAbsence = create_AjouterAbsence();
 gtk_widget_show(AjouterAbsence);
}

/*********************************************************************************************************************************************/
void
on_logouttaux_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Taux;
 Taux=lookup_widget(button,"Taux");
 gtk_widget_hide(Taux);
}

/*********************************************************************************************************************************************/
void
on_retourabss_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AjouterAbsence,*GestionOuvriers;
 AjouterAbsence=lookup_widget(button,"AjouterAbsence");
 GestionOuvriers=lookup_widget(button,"GestionOuvriers");
 gtk_widget_hide(AjouterAbsence);
 GestionOuvriers = create_GestionOuvriers();
 gtk_widget_show(GestionOuvriers);
}

/*********************************************************************************************************************************************/
void
on_logoutabss_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *AjouterAbsence;
 AjouterAbsence=lookup_widget(button,"AjouterAbsence");
 gtk_widget_hide(AjouterAbsence);
}

/*********************************************************************************************************************************************/
void
on_Meilleur_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
int x=0 ; 

GtkWidget *GestionOuvriers,*treeviewrech,*meil;
infoouvrier o;

GestionOuvriers=lookup_widget(button,"GestionOuvriers");
meil=create_windowMeilleur();

treeviewrech=lookup_widget(meil,"treeviewmeillouv");

gtk_widget_show(meil);
x=nbm(); 
MeilleurOuv(treeviewrech,x);
}

/*********************************************************************************************************************************************/
void
on_Meilleur1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}

/*********************************************************************************************************************************************/
void
on_logoutm_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowMeilleur;
 windowMeilleur=lookup_widget(button,"windowMeilleur");
 gtk_widget_hide(windowMeilleur);
}
/*********************************************************************************************************************************************/
void
on_nom_changed                         (GtkEditable     *editable,
                                        gpointer         user_data)
{	infoouvrier o;
	GtkWidget *entryNom,*verif;
	entryNom=lookup_widget(editable,"samarentry8");
	verif=lookup_widget(editable,"samarlabel2");
	strcpy(o.nom,gtk_entry_get_text(entryNom));
	char nom[20];
	int test=1;
	int i ;
	for (i=0;i<strlen(nom);i++)
	{
		if (((nom[i]<65)||(nom[i]>90))||((nom[i]<97)||(nom[i]>122)))
			{test=0;break;}
	
	}
		
	
	
	if ((strcmp(nom,"")==0)||(test==0))
		gtk_widget_show(verif);
	else gtk_widget_hide(verif);
}

/*********************************************************************************************************************************************/


void
on_samarentry7_changed                 (GtkEditable     *editable,
                                        gpointer         user_data)
{int b=1;
infoouvrier o ;
	GtkWidget *entryCin,*labelCin;
	entryCin=lookup_widget(editable,"samarentry7");
	
	labelCin=lookup_widget(editable,"samarlabel1");
	//strcpy(o.cin,gtk_entry_get_text(entryCin));
	
	char cin[9];
        int test=1;
	int i;
	for (i=0;i<strlen(o.cin);i++)
	{
		if ((o.cin[i]<48)||(o.cin[i]>57))
			{test=0;break;}
	
	}
		
	//g_print("%d\n",test);
	
	if ((strlen(o.cin)!=8)||(test==0))
		{gtk_widget_show(labelCin);
		 b=0;}
	else gtk_widget_hide(labelCin);
}


void
on_samarentry8_changed                 (GtkEditable     *editable,
                                        gpointer         user_data)
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







void
on_buttonStartSmartFarm_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Page_Accueil,*Start;
	Start=lookup_widget(button,"Start");
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
	gtk_widget_destroy(Start);
}

int tend;
void
on_buttonOuvrierSmartFarm_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Identifier,*Page_Accueil;
	Page_Accueil=lookup_widget(button,"Page_Accueil");
	Identifier=create_Identifier();
	gtk_widget_show(Identifier);
	gtk_widget_destroy(Page_Accueil);
	tend=2;
}


void
on_button13SmartFarm_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}


void
on_buttonAdminSmartFarm_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Identifier,*Page_Accueil;
	Page_Accueil=lookup_widget(button,"Page_Accueil");
	Identifier=create_Identifier();
	gtk_widget_show(Identifier);
	gtk_widget_destroy(Page_Accueil);
	tend=1;
}


void
on_buttonQuitter2SmartFarm_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonRetourSmartFarm_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonConnecterSmartFarm_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button14SmartFarm_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *entry1,*entry2;
	char identifiant[20],mot[20];
	entry1=lookup_widget(button,"entry1SmartFarm");
	entry2=lookup_widget(button,"entry2SmartFarm");
	strcpy(identifiant,gtk_entry_get_text(entry1));
	strcpy(mot,gtk_entry_get_text(entry2));
	if (Login(identifiant,mot,tend)==1){
		GtkWidget *espace_admin,*Identifier;
		Identifier=lookup_widget(button,"Identifier");
		espace_admin=create_espace_admin();
		gtk_widget_show(espace_admin);
		gtk_widget_destroy(Identifier);}
	else if (Login(identifiant,mot,tend)==2){
		GtkWidget *espace_ouvrier,*Identifier;
		Identifier=lookup_widget(button,"Identifier");
		espace_ouvrier=create_espace_ouvrier();
		gtk_widget_show(espace_ouvrier);
		gtk_widget_destroy(Identifier);}
	else {
		GtkWidget *label;
		label=lookup_widget(button,"label69SmartFarm");
		gtk_widget_show(label);}
}


void
on_button15SmartFarm_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button16SmartFarm_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}


gboolean
on_button15SmartFarm_button_press_event
                                        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
  GtkWidget *entry;
  entry=lookup_widget(widget,"entry2SmartFarm");
  gtk_entry_set_visibility (GTK_ENTRY (entry), TRUE);
  return FALSE;
}


gboolean
on_button15SmartFarm_button_release_event
                                        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
  GtkWidget *entry;
  entry=lookup_widget(widget,"entry2SmartFarm");
  gtk_entry_set_visibility (GTK_ENTRY (entry), FALSE);
  return FALSE;
}


gboolean
on_entry1SmartFarm_button_press_event  (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
  GtkWidget *entry;
  entry=lookup_widget(widget,"entry1SmartFarm");
  if (strcmp(gtk_entry_get_text(entry),"Identifiant")==0)
        gtk_entry_set_text(entry,"");
  GtkWidget *label;
  label=lookup_widget(widget,"label69SmartFarm");
  if (gtk_widget_get_visible(label))
	gtk_widget_set_visible(label,FALSE);
  return FALSE;
}

gboolean
on_entry2SmartFarm_button_press_event  (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
  GtkWidget *entry;
  entry=lookup_widget(widget,"entry2SmartFarm");
  if (strcmp(gtk_entry_get_text(entry),"Mot de passe")==0){
        gtk_entry_set_text(entry,"");
	gtk_entry_set_visibility (GTK_ENTRY (entry), FALSE);}
  GtkWidget *label;
  label=lookup_widget(widget,"label69SmartFarm");
  if (gtk_widget_get_visible(label))
	gtk_widget_set_visible(label,FALSE);
  return FALSE;
}


void
on_button17SmartFarm_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Page_Accueil,*Identifier;
	Identifier=lookup_widget(button,"Identifier");
	gtk_widget_destroy(Identifier);
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
	
}


void
on_buttonGestionCapteurSmartFarm_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *afficher_capteur,*espace_ouvrier;
	espace_ouvrier=lookup_widget(button,"espace_ouvrier");
	gtk_widget_destroy(espace_ouvrier);
	afficher_capteur=create_afficher_capteur();
	gtk_widget_show(afficher_capteur);
}


void
on_buttonGestionEquipementSmartFarm_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionEquipements,*espace_ouvrier;
	espace_ouvrier=lookup_widget(button,"espace_ouvrier");
	gtk_widget_destroy(espace_ouvrier);
	GestionEquipements=create_GestionEquipements();
	gtk_widget_show(GestionEquipements);
}


void
on_buttonGestionCalendrierSmartFarm_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_agriculteur,*espace_ouvrier;
	espace_ouvrier=lookup_widget(button,"espace_ouvrier");
	gtk_widget_destroy(espace_ouvrier);
	espace_agriculteur=create_espace_agriculteur();
	gtk_widget_show(espace_agriculteur);
}


void
on_buttonGestionTroupeauxSmartFarm_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionTroupeaux,*espace_ouvrier;
	espace_ouvrier=lookup_widget(button,"espace_ouvrier");
	gtk_widget_destroy(espace_ouvrier);
	GestionTroupeaux=create_GestionTroupeaux();
	gtk_widget_show(GestionTroupeaux);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int x,y;
//*******************************************************************************************************************************************************************AjouterTroupeau
void
on_buttonAjouterTroupeau_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget* WindowAjouter,*windows;
	WindowAjouter=create_Ajout_animal ();
	gtk_widget_show(WindowAjouter);
}
//*******************************************************************************************************************************************************************ajouter_animal2
void
on_button_ajouter_animal2_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
	struct Troupeau animal ; 
	GtkWidget *Name,*Boucle,*Jour,*Mois,*Annee,*Sexe,*Sante,*windowAjouter,*combo_entry_name,*combo_entry_jour;
	GtkWidget *combo_entry_mois,*combo_entry_annee,*popup,*combo_entry_sante,*calendar;
	GtkWidget *verif_name,*verif_boucle,*verif_date,*verif_sante;
	GSList *List;
	char sexe[30];
	int jour,mois,annee;
	GtkWidget *radioButtonMale,*radioButtonFemelle;
	radioButtonMale=lookup_widget(objet,"radiobutton_male");
	radioButtonFemelle=lookup_widget(objet,"radiobutton_femelle");
	List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radioButtonMale));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
		strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));
	else{
		List = g_slist_next(List);
		strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));}

	char name[30],boucle[30],sante[30],date[30]="",*mois_char[20];
	Name=lookup_widget(objet,"entry_name_animal");		
	Boucle=lookup_widget(objet,"entry_boucle_animal");
	Sante=lookup_widget(objet,"entry_sante_animal");
	calendar=lookup_widget(objet,"calendarTroupeau");
	combo_entry_name = GTK_COMBO (Name)->entry;
	combo_entry_sante = GTK_COMBO (Sante)->entry;
	strcpy(animal.boucle,gtk_entry_get_text(GTK_ENTRY(Boucle)));
	strcpy(animal.sexe,sexe);
	strcpy(animal.name,gtk_entry_get_text(GTK_ENTRY(combo_entry_name)));
	gtk_calendar_get_date (calendar,&annee,&mois,&jour);
	mois ++ ;
	get_mois2(mois,mois_char);
	g_print("%s\n",mois_char);
	sprintf(animal.date_naissance.jour,"%d",jour);
	strcpy(animal.date_naissance.mois,mois_char);
	sprintf(animal.date_naissance.annee,"%d",annee);
	strcpy(animal.sante,gtk_entry_get_text(GTK_ENTRY(combo_entry_sante)));
	int test=1;	
	verif_name=lookup_widget(objet,"valide_name_ajout");
	verif_boucle=lookup_widget(objet,"label621Troupeaux");
	verif_date=lookup_widget(objet,"label627");
	verif_sante=lookup_widget(objet,"label628");
	if ((gtk_widget_get_visible(verif_name)==FALSE)&&(gtk_widget_get_visible(verif_boucle)==FALSE)&&(gtk_widget_get_visible(verif_date)==FALSE)&&(gtk_widget_get_visible(verif_sante)==FALSE))
	{	
		GtkWidget *maladie1,*maladie2,*maladie3,*maladie4;
		maladie1=lookup_widget(objet,"maladie1");
		maladie2=lookup_widget(objet,"maladie2");
		maladie3=lookup_widget(objet,"maladie3");
		maladie4=lookup_widget(objet,"maladie4");
		if (strcmp(animal.sante,"Malade")==0)
			ajouter_animal_malade(animal,maladie1,maladie2,maladie3,maladie4);
		windowAjouter=lookup_widget(objet,"Ajout_animal");
		gtk_widget_destroy(windowAjouter);
		ajouter_animal(animal);
		popup=lookup_widget(objet,"AjoutTermineAnimal");
		popup=create_AjoutTermineAnimal();
		gtk_widget_show(popup);
	}
}
//*******************************************************************************************************************************************************************SupprimerTroupeau
void
on_buttonSupprimerTroupeau_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* windowSupprimer,*entry_boucle;
	GtkWidget* Name,*Sexe,*Boucle,*Date,*Sante;
	entry_boucle=lookup_widget(button,"entry_boucle");
	FILE* f;
	char name[30],boucle[30],sexe[30],date[30],sante[30],name2[30],boucle2[30],sexe2[30],date2[30],sante2[30],ch[10];
	int test=1,i,age;
	strcpy(ch,gtk_entry_get_text(GTK_WIDGET(entry_boucle)));
	f=fopen("troupeau.txt","r+"); 
	if (f!=NULL)
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
		{	
			if (strcmp(ch,boucle)==0){
				test=0;
				strcpy(name2,name);strcpy(boucle2,boucle);strcpy(sexe2,sexe);strcpy(date2,date);strcpy(sante2,sante);}
		}
	if (test==0)
		test=1;
	else test=0;
	fclose(f);
	if ((strcmp("",ch)!=0)&&(verif_boucle(ch,0)==1)&&(test==1)){
		windowSupprimer=create_Supprimer_animal();
		gtk_widget_show(windowSupprimer);
		Name=lookup_widget(windowSupprimer,"label_name_animal2");
		Sexe=lookup_widget(windowSupprimer,"label_sexe_animal2");
		Boucle=lookup_widget(windowSupprimer,"label_boucle_animal2");
		Date=lookup_widget(windowSupprimer,"label_date_animal2");
		Sante=lookup_widget(windowSupprimer,"label_sante_animal2");
		gtk_label_set_text(GTK_LABEL(Name),name2);
		gtk_label_set_text(GTK_LABEL(Sexe),sexe2);
		gtk_label_set_text(GTK_LABEL(Date),date2);
		gtk_label_set_text(GTK_LABEL(Boucle),boucle2);
		gtk_label_set_text(GTK_LABEL(Sante),sante2);
	}
	
}

//*******************************************************************************************************************************************************************buttonAnnulerSuppresion
void
on_buttonAnnulerSuppresion_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* windowSupprimer;
	windowSupprimer=lookup_widget(button,"Supprimer_animal");
	gtk_widget_destroy(windowSupprimer);
}
//*******************************************************************************************************************************************************************button_supprimer_animal2
void
on_button_supprimer_animal2_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Boucle,*popup;
	char supp_boucle[20];
	Boucle=lookup_widget(button,"label_boucle_animal2");
	strcpy(supp_boucle,gtk_label_get_text(GTK_LABEL(Boucle)));
	supprimer_animal(supp_boucle);	
	popup=lookup_widget(button,"SuppresionTermineAnimal");
	popup=create_SuppresionTermineAnimal();
	gtk_widget_show(popup);
	
	on_buttonAnnulerSuppresion_clicked(button,user_data);

}
//*******************************************************************************************************************************************************************
void
on_entry_boucle_animal_changed         (GtkEditable     *editable,
                                        gpointer         user_data)
{

	GtkWidget* entry_boucle_animal,*label,*label2;
	entry_boucle_animal=lookup_widget(editable,"entry_boucle_animal");
	
	label=lookup_widget(editable,"label621Troupeaux");
	if (verif_boucle(gtk_entry_get_text(entry_boucle_animal),1)==0)
		{	
			gtk_widget_show(label);
		 }
else {gtk_widget_hide(label);

}
}

//*******************************************************************************************************************************************************************
void
on_button_annuler_ajout_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* windowAjouter,*windows;
	windowAjouter=lookup_widget(button,"Ajout_animal");
	gtk_widget_destroy(windowAjouter);
}

//*******************************************************************************************************************************************************************
void
on_Actualiser_tree_view_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview1,*combo_tirer_par,*combo_entry_tirer_par;
	char tirer_par[20];
	combo_tirer_par=lookup_widget(objet,"comboTirerPar");
	combo_entry_tirer_par = GTK_COMBO (combo_tirer_par)->entry;
	strcpy(tirer_par,gtk_entry_get_text(GTK_ENTRY(combo_entry_tirer_par)));
	treeview1=lookup_widget(objet,"treeview_troupeau");
	afficher_animal(treeview1,"",tirer_par);
}

//*******************************************************************************************************************************************************************
void
on_button119_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
	
}

//*******************************************************************************************************************************************************************
void
on_buttonModifier2_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
	struct Troupeau animal ; 

	GtkWidget *Name,*Boucle,*Jour,*Mois,*Annee,*Sexe,*Sante,*calendar;
	GtkWidget *windowAjouter,*combo_entry_name,*combo_entry_jour,*combo_entry_sante;
	GtkWidget *combo_entry_mois,*combo_entry_annee,*boucle_prec,*popup,*label_boucle_animal3;
	GtkWidget *verif_name,*verif_boucle,*verif_date,*verif_sante;
	GSList *List;
	char sexe[30];
	int age,jour,mois,annee;
	label_boucle_animal3=lookup_widget(objet,"label_boucle_animal3");
	GtkWidget *radioButtonMale,*radioButtonFemelle;
	radioButtonMale=lookup_widget(objet,"radioButtonMaleModifier");
	radioButtonFemelle=lookup_widget(objet,"radioButtonFemelleModifier");
	List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radioButtonMale));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
		strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));
	else{
		List = g_slist_next(List);
		strcpy(sexe,gtk_button_get_label(GTK_BUTTON(List->data)));}

	char name[30],boucle[30],sante[30],date[30]="",boucle3[30],date1[30],*mois_char[30];
	Name=lookup_widget(objet,"comboModifierName");
	Boucle=lookup_widget(objet,"entryModifierBoucle");
	Sante=lookup_widget(objet,"comboModifierSante");
	calendar=lookup_widget(objet,"calendarTroupeau2");
	combo_entry_name = GTK_COMBO (Name)->entry;
	combo_entry_sante = GTK_COMBO (Sante)->entry;

	strcpy(animal.boucle,gtk_entry_get_text(GTK_ENTRY(Boucle)));
	strcpy(animal.sexe,sexe);
	strcpy(animal.name,gtk_entry_get_text(GTK_ENTRY(combo_entry_name)));
	gtk_calendar_get_date (calendar,&annee,&mois,&jour);
	mois ++ ;
	get_mois2(mois,mois_char);
	sprintf(animal.date_naissance.jour,"%d",jour);
	strcpy(animal.date_naissance.mois,mois_char);
	sprintf(animal.date_naissance.annee,"%d",annee);
	strcpy(animal.sante,gtk_entry_get_text(GTK_ENTRY(combo_entry_sante)));
	int test=1;	
	FILE* f;
	f=fopen("troupeau.txt","r");
	while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF){
		if (strcmp(animal.boucle,boucle)==0) test=0;}
	fclose(f);
	verif_name=lookup_widget(objet,"valide_name_modif");
	verif_boucle=lookup_widget(objet,"label698");
	verif_date=lookup_widget(objet,"label700");
	verif_sante=lookup_widget(objet,"label701");
	
	if ((gtk_widget_get_visible(verif_name)==FALSE)&&(gtk_widget_get_visible(verif_boucle)==FALSE)&&(gtk_widget_get_visible(verif_date)==FALSE)&&(gtk_widget_get_visible(verif_sante)==FALSE)){	
		
		GtkWidget *maladie1,*maladie2,*maladie3,*maladie4,*labelSante;
		maladie1=lookup_widget(objet,"maladie1_2");
		maladie2=lookup_widget(objet,"maladie2_2");
		maladie3=lookup_widget(objet,"maladie3_2");
		maladie4=lookup_widget(objet,"maladie4_2");
		labelSante=lookup_widget(objet,"label_sante_animal3");
		if ((strcmp(animal.sante,"Malade")==0)&&(strcmp(gtk_label_get_text(labelSante),"Malade")==0))	
			modifier_animal_malade(animal,maladie1,maladie2,maladie3,maladie4);
		else if (strcmp(animal.sante,"Malade")==0)
			ajouter_animal_malade(animal,maladie1,maladie2,maladie3,maladie4);
		else if (strcmp(animal.sante,"Bonne")==0)
			supprimer_animal_malade(animal.boucle);
		windowAjouter=lookup_widget(objet,"Modifier_animal");
		strcpy(boucle3,gtk_label_get_text(GTK_LABEL(label_boucle_animal3)));
		sprintf(date1,"%s/%s/%s",animal.date_naissance.jour,animal.date_naissance.mois,animal.date_naissance.annee);
		modifier_animal(animal,date1,boucle3);
		gtk_widget_destroy(windowAjouter);
		popup=lookup_widget(objet,"ModificationTermineAnimal");
		popup=create_ModificationTermineAnimal();
		gtk_widget_show(popup);
	}
	

}

//*******************************************************************************************************************************************************************
void on_buttonModifier_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget* windowModifier,*entry_boucle,*labelName,*labelSexe,*labelDate,*labelSante,*labelBoucle,*entryName,*combo_entry_sante;
	GtkWidget *entrySexe,*entryBoucle,*entryJour,*entryMois,*entryAnnee,*entrySante,*combo_entry_name,*combo_entry_jour,*combo_entry_mois,*combo_entry_annee;
	GtkWidget* Name,*Sexe,*Boucle,*Date,*Sante;
	entry_boucle=lookup_widget(objet,"entry_boucle");
	FILE* f;
	char name[30],boucle[30],sexe[30],date[30],sante[30],name2[30],boucle2[30],sexe2[30],date2[30],sante2[30],ch[10];
	int test=1,i,age;
	strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entry_boucle)));
	f=fopen("troupeau.txt","r+"); 
	if (f!=NULL)
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
		{	
			if (strcmp(ch,boucle)==0){
				test=0;
				strcpy(name2,name);strcpy(boucle2,boucle);strcpy(sexe2,sexe);strcpy(date2,date);strcpy(sante2,sante);}
		}
	if (test==0) test=1;
	else test=0;
	
	fclose(f);
	if ((strcmp("",ch)!=0)&&(verif_boucle(ch,0)==1)&&(test==1)){
		windowModifier=create_Modifier_animal();
		gtk_widget_show(windowModifier);
		labelName=lookup_widget(windowModifier,"label_name_animal3");
		labelSexe=lookup_widget(windowModifier,"label_sexe_animal3");
		labelBoucle=lookup_widget(windowModifier,"label_boucle_animal3");
		labelDate=lookup_widget(windowModifier,"label_date_animal3");
		labelSante=lookup_widget(windowModifier,"label_sante_animal3");
		entryName=lookup_widget(windowModifier,"comboModifierName");
		entrySexe=lookup_widget(windowModifier,"label_sexe_animal3");
		entryBoucle=lookup_widget(windowModifier,"entryModifierBoucle");
		entrySante=lookup_widget(windowModifier,"comboModifierSante");
		combo_entry_name = GTK_COMBO (entryName)->entry;
		combo_entry_sante = GTK_COMBO (entrySante)->entry;
		gtk_label_set_text(GTK_LABEL(labelName),name2);
		gtk_label_set_text(GTK_LABEL(labelSexe),sexe2);
		gtk_label_set_text(GTK_LABEL(labelDate),date2);
		gtk_label_set_text(GTK_LABEL(labelBoucle),boucle2);
		gtk_label_set_text(GTK_LABEL(labelSante),sante2);
		
		gtk_entry_set_text(GTK_ENTRY(combo_entry_name),name2);
		gtk_entry_set_text(GTK_ENTRY(entryBoucle),boucle2);
		gtk_entry_set_text(GTK_ENTRY(combo_entry_sante),sante2);
GtkWidget *radioButtonMale,*radioButtonFemelle;
	/*radioButtonMale=lookup_widget(objet,"radioButtonMaleModifier");
	radioButtonFemelle=lookup_widget(objet,"radioButtonFemelleModifier");
	GSList *List;
	List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radioButtonMale));
	
	if(strcmp(sexe2,"Femelle")==0)
		gtk_button_get_label(GTK_BUTTON(List->data));
	else{
		//List = g_slist_next(List);
		gtk_button_get_label(GTK_BUTTON(List->data));}*/
	char *jour[3],*mois[10],*annee[5];
	get_date(&jour,&mois,&annee,date2);
 
	
}
}
//*******************************************************************************************************************************************************************
void
on_AnnulerModifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* windowModifier;
	windowModifier=lookup_widget(button,"Modifier_animal");
	gtk_widget_destroy(windowModifier);
}

//*******************************************************************************************************************************************************************
void
on_AjoutTermineAnimal2_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *popup;
	popup=lookup_widget(button,"AjoutTermineAnimal");
	gtk_widget_destroy(popup);
}

//*******************************************************************************************************************************************************************

void
on_buttonRechercherAnimal_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* entry_boucle_rech;
	GtkWidget *treeview1;
	char boucle_rech[20];
	entry_boucle_rech=lookup_widget(button,"entryBoucleRechercherAnimal");
	strcpy(boucle_rech,gtk_entry_get_text(GTK_ENTRY(entry_boucle_rech)));
	if (strcmp(boucle_rech,"")==0)
		return;	
	treeview1=lookup_widget(button,"treeview_troupeau");
	afficher_animal(treeview1,boucle_rech,"Name");
}

//*******************************************************************************************************************************************************************
void
on_treeview_troupeau_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint *age;
	gchar *name,*boucle,*sexe,*date,*sante;
	GtkWidget* Name,*Sexe,*Boucle,*Age,*Date,*Sante,*Maladies,*Fiche_animal;
	char age2[4],maladies[100],malade1[30],malade2[30],malade3[30],malade4[30];
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&name,1,&boucle,2,&sexe,3,&date,4,&age,5,&sante,-1);
		Fiche_animal=create_Fiche_animal ();
		gtk_widget_show(Fiche_animal);
		Name=lookup_widget(Fiche_animal,"info_name_animal");
		Sexe=lookup_widget(Fiche_animal,"info_sexe_animal");
		Boucle=lookup_widget(Fiche_animal,"info_boucle_animal");
		Date=lookup_widget(Fiche_animal,"info_date_animal");
		Age=lookup_widget(Fiche_animal,"info_age_animal");
		Sante=lookup_widget(Fiche_animal,"info_sante_animal");
		Maladies=lookup_widget(Fiche_animal,"info_maladies_animal");
		gtk_label_set_text(GTK_LABEL(Name),name);
		gtk_label_set_text(GTK_LABEL(Sexe),sexe);
		gtk_label_set_text(GTK_LABEL(Date),date);
		gtk_label_set_text(GTK_LABEL(Boucle),boucle);
		sprintf(age2,"%d",age);
		gtk_label_set_text(GTK_LABEL(Age),age2);
		gtk_label_set_text(GTK_LABEL(Sante),sante);
		if (strcmp(sante,"Malade")==0){
			FILE *f;
			f=fopen("troupeau_malade.txt","r+");
			strcpy(maladies,"");
			while (fscanf(f,"%s %s %s %s %s %s\n",animal.name,animal.boucle,malade1,malade2,malade3,malade4)!=EOF){
				if (strcmp(animal.boucle,boucle)==0){
					if (strcmp(malade1,"-")!=0) strcat(maladies,"*Coryza gangreneux\n");
					if (strcmp(malade2,"-")!=0) strcat(maladies,"*Fièvre catarrhale ovine\n");
					if (strcmp(malade3,"-")!=0) strcat(maladies,"*Infection par le virus BVD-MD\n");
					if (strcmp(malade4,"-")!=0) strcat(maladies,"*Maladies virales");
			}}
		fclose(f);
		gtk_label_set_text(GTK_LABEL(Maladies),maladies);
		}
	}
}
//*******************************************************************************************************************************************************************
void
on_maladies_toggled(GtkToggleButton *togglebutton,gpointer user_data)
{
	GtkWidget* maladies,*maladie1,*maladie2,*maladie3,*maladie4,*fixed83,*Sante,*combo_entry_sante;
	maladies=lookup_widget(togglebutton,"maladies");
	fixed83=lookup_widget(togglebutton,"fixed83");
	Sante=lookup_widget(togglebutton,"entry_sante_animal");
	combo_entry_sante = GTK_COMBO (Sante)->entry;
	strcpy(animal.sante,gtk_entry_get_text(GTK_ENTRY(combo_entry_sante)));	
	
	maladie1=lookup_widget(togglebutton,"maladie1");
	maladie2=lookup_widget(togglebutton,"maladie2");
	maladie3=lookup_widget(togglebutton,"maladie3");
	maladie4=lookup_widget(togglebutton,"maladie4");

	if(( gtk_toggle_button_get_active(maladies))&&(strcmp(animal.sante,"Malade")==0)) {	
		gtk_widget_show(maladie1);
		gtk_widget_show(maladie2);
		gtk_widget_show(maladie3);
		gtk_widget_show(maladie4);}
	else if(( gtk_toggle_button_get_active(maladies)==FALSE)||(strcmp(animal.sante,"Bonne")==0)){
		gtk_widget_hide(maladie1);
		gtk_widget_hide(maladie2);
		gtk_widget_hide(maladie3);
		gtk_widget_hide(maladie4);}
}

//*******************************************************************************************************************************************************************
void
on_combo_entry2_changed                (GtkEditable     *editable,
                                        gpointer         user_data)
{
	GtkWidget* valide_name_ajout,*entry_name_animal,*entry;
	valide_name_ajout=lookup_widget(editable,"valide_name_ajout");
	entry_name_animal=lookup_widget(editable,"entry_name_animal");
	entry= GTK_COMBO (entry_name_animal)->entry;
	if ((strcmp(gtk_entry_get_text(GTK_ENTRY(entry)),"Brebi")==0)||(strcmp(gtk_entry_get_text(GTK_ENTRY(entry)),"Veau")==0))
		gtk_widget_hide(valide_name_ajout);
	else gtk_widget_show(valide_name_ajout);
		
}

//*******************************************************************************************************************************************************************
void
on_buttonActualisrMalade_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}
//*******************************************************************************************************************************************************************

void
on_buttonActualiserMalade_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview1;	
	treeview1=lookup_widget(button,"treeview_malade");
	afficher_animal_malade(treeview1);
}
//*******************************************************************************************************************************************************************

void
on_treeview_troupeau_columns_changed   (GtkTreeView     *treeview,
                                        gpointer         user_data)
{
	/*GtkTreeIter iter;
	gchar *name,*boucle,*sexe,*date,*sante;
	
	GtkWidget* Actualiser_tree_view;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&name,1,&boucle,2,&sexe,3,&date,4,&sante,-1);
		strcpy(animal.boucle,boucle);
		supprimer_animal(animal.boucle);
			afficher_animal(treeview,"","Name");
	}*/
}

//*******************************************************************************************************************************************************************
void
on_combo_entry_tirer_par_changed       (GtkEditable     *editable,
                                        gpointer         user_data)
{
	GtkWidget *treeview1,*combo_tirer_par,*combo_entry_tirer_par,*button;
	char tirer_par[20];
	combo_tirer_par=lookup_widget(editable,"comboTirerPar");
	combo_entry_tirer_par = GTK_COMBO (combo_tirer_par)->entry;
	strcpy(tirer_par,gtk_entry_get_text(GTK_ENTRY(combo_entry_tirer_par)));
	treeview1=lookup_widget(editable,"treeview_troupeau");
	button=lookup_widget(editable,"Actualiser_tree_view");
	if ((strcmp(tirer_par,"Name")==0)||(strcmp(tirer_par,"Sante")==0)||(strcmp(tirer_par,"Sexe")==0)||(strcmp(tirer_par,"Boucle")==0)||(strcmp(tirer_par,"Date naissance")==0))
		on_Actualiser_tree_view_clicked (button,user_data);
}


gboolean
on_treeview_troupeau_select_all        (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return FALSE;
}

//*******************************************************************************************************************************************************************
void
on_treeview_troupeau_row_expanded      (GtkTreeView     *treeview,
                                        GtkTreeIter     *iter,
                                        GtkTreePath     *path,
                                        gpointer         user_data)
{
}

//*******************************************************************************************************************************************************************
void
on_treeview_troupeau_row_collapsed     (GtkTreeView     *treeview,
                                        GtkTreeIter     *iter,
                                        GtkTreePath     *path,
                                        gpointer         user_data)
{
}

//*******************************************************************************************************************************************************************
void
on_entry250_editing_done               (GtkCellEditable *celleditable,
                                        gpointer         user_data)
{
	/*GtkWidget *entry;
		entry=lookup_widget(treeview,"entry250");

		
	gtk_widget_hide(entry);*/
}


gboolean
on_entry250_key_press_event            (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data)
{/*
 gtk_widget_hide(widget);
return FALSE;*/
}

//*******************************************************************************************************************************************************************
void
on_entry250_insert_text                (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data)
{
	/*
gtk_cell_renderer_set_visible (GtkCellRenderer *cell,
                               gboolean visible);
	if (strcmp("+",new_text)==0)
		gtk_widget_hide(editable);*/
}

//*******************************************************************************************************************************************************************
void
on_combo_entry_name_ajout_changed      (GtkEditable     *editable,
                                        gpointer         user_data)
{
	char entry[10];
	GtkWidget *verif;
	verif=lookup_widget(editable,"valide_name_ajout");
	strcpy(entry,gtk_entry_get_text(editable));
	if ((strcmp(entry,"Veau")==0)||(strcmp(entry,"Brebi")==0))
		gtk_widget_hide(verif);
	else gtk_widget_show(verif);
}


//*******************************************************************************************************************************************************************
void
on_combo_entry_sante_verif_changed     (GtkEditable     *editable,
                                        gpointer         user_data)
{
	char entry[10];
	GtkWidget *verif;
	verif=lookup_widget(editable,"label628");
	strcpy(entry,gtk_entry_get_text(editable));
	if ((strcmp(entry,"Bonne")==0)||(strcmp(entry,"Malade")==0))
		gtk_widget_hide(verif);
	else gtk_widget_show(verif);
	
GtkWidget *maladie1,*maladie2,*maladie3,*maladie4;

maladie1=lookup_widget(editable,"maladie1");
	maladie2=lookup_widget(editable,"maladie2");
	maladie3=lookup_widget(editable,"maladie3");
	maladie4=lookup_widget(editable,"maladie4");
	if (strcmp(entry,"Bonne")==0){
		gtk_widget_hide(maladie1);
		gtk_widget_hide(maladie2);
		gtk_widget_hide(maladie3);
		gtk_widget_hide(maladie4);}
}

//*******************************************************************************************************************************************************************

void
on_entryModifierBoucle_changed         (GtkEditable     *editable,
                                        gpointer         user_data)
{
	GtkWidget* entryModifierBoucle,*label,*label2,*label486,*entry;
	entryModifierBoucle=lookup_widget(editable,"entryModifierBoucle");
	
	label=lookup_widget(editable,"label698");
	label486=lookup_widget(editable,"label_boucle_animal3");
	entry=lookup_widget(editable,"entryModifierBoucle");
	char ch[10],ch2[10];
	strcpy(ch,gtk_label_get_text(GTK_LABEL(label486)));
	strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(entry)));

	
	if ((verif_boucle(gtk_entry_get_text(entryModifierBoucle),1)==0)&&(strcmp(ch,ch2)!=0))
			gtk_widget_show(label);
	else gtk_widget_hide(label);


}
//*******************************************************************************************************************************************************************

void
on_entry_mois_modif_changed            (GtkEditable     *editable,
                                        gpointer         user_data)
{
	int j,a;
	char entry[20];
	
	GtkWidget *verif,*jour,*annee,*mois;
	verif=lookup_widget(editable,"label700");
	mois=lookup_widget(editable,"entry_mois_modif");
	annee=lookup_widget(editable,"entry_annee_modif");
	jour=lookup_widget(editable,"entry_jour_modif");
	j=atoi(gtk_entry_get_text(jour));
	a=atoi(gtk_entry_get_text(annee));
	strcpy(entry,gtk_entry_get_text(GTK_ENTRY(mois)));
	if (verif_entry_date(j,strlen(gtk_entry_get_text(jour)),entry,a,strlen(gtk_entry_get_text(annee)))==0)
		gtk_widget_hide(verif);
	else gtk_widget_show(verif);
}

//*******************************************************************************************************************************************************************
void
on_entry_jour_modif_changed            (GtkEditable     *editable,
                                        gpointer         user_data)
{
	int j,a;
	char entry[20];
	
	GtkWidget *verif,*jour,*annee,*mois;
	verif=lookup_widget(editable,"label700");
	mois=lookup_widget(editable,"entry_mois_modif");
	annee=lookup_widget(editable,"entry_annee_modif");
	jour=lookup_widget(editable,"entry_jour_modif");
	j=atoi(gtk_entry_get_text(jour));
	a=atoi(gtk_entry_get_text(annee));
	strcpy(entry,gtk_entry_get_text(GTK_ENTRY(mois)));
	if (verif_entry_date(j,strlen(gtk_entry_get_text(jour)),entry,a,strlen(gtk_entry_get_text(annee)))==0)
		gtk_widget_hide(verif);
	else gtk_widget_show(verif);
}

//*******************************************************************************************************************************************************************
void
on_entry_annee_modif_changed           (GtkEditable     *editable,
                                        gpointer         user_data)
{
	int j,a;
	char entry[20];
	
	GtkWidget *verif,*jour,*annee,*mois;
	verif=lookup_widget(editable,"label700");
	mois=lookup_widget(editable,"entry_mois_modif");
	annee=lookup_widget(editable,"entry_annee_modif");
	jour=lookup_widget(editable,"entry_jour_modif");
	j=atoi(gtk_entry_get_text(jour));
	a=atoi(gtk_entry_get_text(annee));
	strcpy(entry,gtk_entry_get_text(GTK_ENTRY(mois)));
	if (verif_entry_date(j,strlen(gtk_entry_get_text(jour)),entry,a,strlen(gtk_entry_get_text(annee)))==0)
		gtk_widget_hide(verif);
	else gtk_widget_show(verif);
}

//*******************************************************************************************************************************************************************
void
on_entry_name_modif_changed            (GtkEditable     *editable,
                                        gpointer         user_data)
{
	char entry[10];
	GtkWidget *verif;
	verif=lookup_widget(editable,"valide_name_modif");
	strcpy(entry,gtk_entry_get_text(editable));
	if ((strcmp(entry,"Veau")==0)||(strcmp(entry,"Brebi")==0)||(strcmp(entry,"Mouton")==0)||(strcmp(entry,"Vache")==0))
		gtk_widget_hide(verif);
	else gtk_widget_show(verif);
}

//*******************************************************************************************************************************************************************
void
on_entry_sante_modif_changed           (GtkEditable     *editable,
                                        gpointer         user_data)
{
	char entry[10];
	GtkWidget *verif;
	verif=lookup_widget(editable,"label701");
	strcpy(entry,gtk_entry_get_text(editable));
	if ((strcmp(entry,"Bonne")==0)||(strcmp(entry,"Malade")==0))
		gtk_widget_hide(verif);
	else gtk_widget_show(verif);
	
	GtkWidget *maladie1,*maladie2,*maladie3,*maladie4;

	maladie1=lookup_widget(editable,"maladie1_2");
	maladie2=lookup_widget(editable,"maladie2_2");
	maladie3=lookup_widget(editable,"maladie3_2");
	maladie4=lookup_widget(editable,"maladie4_2");
	if (strcmp(entry,"Bonne")==0){
		gtk_widget_hide(maladie1);
		gtk_widget_hide(maladie2);
		gtk_widget_hide(maladie3);
		gtk_widget_hide(maladie4);}
}

//*******************************************************************************************************************************************************************
void
on_maladies2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	GtkWidget* maladies,*maladie1,*maladie2,*maladie3,*maladie4,*Sante,*combo_entry_sante;
	maladies=lookup_widget(togglebutton,"maladies2");
	Sante=lookup_widget(togglebutton,"comboModifierSante");
	combo_entry_sante = GTK_COMBO (Sante)->entry;
	strcpy(animal.sante,gtk_entry_get_text(GTK_ENTRY(combo_entry_sante)));	
	
	maladie1=lookup_widget(togglebutton,"maladie1_2");
	maladie2=lookup_widget(togglebutton,"maladie2_2");
	maladie3=lookup_widget(togglebutton,"maladie3_2");
	maladie4=lookup_widget(togglebutton,"maladie4_2");

	if(( gtk_toggle_button_get_active(maladies))&&(strcmp(animal.sante,"Malade")==0)) {	
		gtk_widget_show(maladie1);
		gtk_widget_show(maladie2);
		gtk_widget_show(maladie3);
		gtk_widget_show(maladie4);}
	else if(( gtk_toggle_button_get_active(maladies)==FALSE)||(strcmp(animal.sante,"Bonne")==0)){
		gtk_widget_hide(maladie1);
		gtk_widget_hide(maladie2);
		gtk_widget_hide(maladie3);
		gtk_widget_hide(maladie4);}
}
//*******************************************************************************************************************************************************************

void
on_button_recherche_avance_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *rech_avance,*buttonRechercherAnimal,*Actualiser_tree_view,*comboTirerPar,*buttonAjouterTroupeau,*buttonSupprimerTroupeau,*buttonModifier,*Nombre_troupeau1;
	rech_avance=lookup_widget(button,"layout2Troupeaux");
	buttonRechercherAnimal=lookup_widget(button,"buttonRechercherAnimal");
	Actualiser_tree_view=lookup_widget(button,"Actualiser_tree_view");
	comboTirerPar=lookup_widget(button,"comboTirerPar");
	buttonAjouterTroupeau=lookup_widget(button,"buttonAjouterTroupeau");
	buttonSupprimerTroupeau=lookup_widget(button,"buttonSupprimerTroupeau");
	buttonModifier=lookup_widget(button,"buttonModifier");
	Nombre_troupeau1=lookup_widget(button,"Nombre_troupeau1");
	if (gtk_widget_get_visible(rech_avance))
		{gtk_widget_hide(rech_avance);
		gtk_widget_set_sensitive(buttonRechercherAnimal,TRUE);
		gtk_widget_set_sensitive(Actualiser_tree_view,TRUE);
		gtk_widget_set_sensitive(comboTirerPar,TRUE);
		gtk_widget_set_sensitive(buttonAjouterTroupeau,TRUE);
		gtk_widget_set_sensitive(buttonSupprimerTroupeau,TRUE);
		gtk_widget_set_sensitive(buttonModifier,TRUE);
		gtk_widget_set_sensitive(Nombre_troupeau1,TRUE);}
	else {
		gtk_widget_show(rech_avance);
		gtk_widget_set_sensitive(buttonRechercherAnimal,FALSE);
		gtk_widget_set_sensitive(Actualiser_tree_view,FALSE);
		gtk_widget_set_sensitive(comboTirerPar,FALSE);
		gtk_widget_set_sensitive(buttonAjouterTroupeau,FALSE);
		gtk_widget_set_sensitive(buttonSupprimerTroupeau,FALSE);
		gtk_widget_set_sensitive(buttonModifier,FALSE);
		gtk_widget_set_sensitive(Nombre_troupeau1,FALSE);
	}
}

//*******************************************************************************************************************************************************************
void
on_checkbutton_nom_avance_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	GtkWidget *mouton,*brebi,*veau,*vache;
	mouton=lookup_widget(togglebutton,"radio_mouton_avance");
	brebi=lookup_widget(togglebutton,"radio_brebi_avance");
	veau=lookup_widget(togglebutton,"radio_veau_avance");
	vache=lookup_widget(togglebutton,"radio_vache_avance");
	if ( gtk_toggle_button_get_active(togglebutton)){
		gtk_widget_show(mouton);gtk_widget_show(brebi);gtk_widget_show(veau);gtk_widget_show(vache);}
	else {gtk_widget_hide(mouton);gtk_widget_hide(brebi);gtk_widget_hide(veau);gtk_widget_hide(vache);}
		
}

//*******************************************************************************************************************************************************************
void
on_checkbutton_date_avance_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	GtkWidget *jour,*jour2,*mois,*mois2,*annee,*annee2,*label1,*label2;
	jour=lookup_widget(togglebutton,"spin_jour_avance");
	jour2=lookup_widget(togglebutton,"spin_jour2_avance");
	mois=lookup_widget(togglebutton,"spin_mois_avance");
	mois2=lookup_widget(togglebutton,"spin_mois2_avance");
	annee=lookup_widget(togglebutton,"spin_annee_avance");
	annee2=lookup_widget(togglebutton,"spin_annee2_avance");
	label1=lookup_widget(togglebutton,"label_date1_avance");
	label2=lookup_widget(togglebutton,"label_date2_avance");
	if ( gtk_toggle_button_get_active(togglebutton)){
		gtk_widget_show(jour);gtk_widget_show(jour2);gtk_widget_show(mois);gtk_widget_show(mois2);
		gtk_widget_show(annee);gtk_widget_show(annee2);gtk_widget_show(label1);gtk_widget_show(label2);}
	else {gtk_widget_hide(jour);gtk_widget_hide(jour2);gtk_widget_hide(mois);gtk_widget_hide(mois2);
		gtk_widget_hide(annee);gtk_widget_hide(annee2);gtk_widget_hide(label1);gtk_widget_hide(label2);}
}

//*******************************************************************************************************************************************************************
void
on_checkbutton_sexe_avance_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	GtkWidget *male,*femelle;
	male=lookup_widget(togglebutton,"radio_male_avance");
	femelle=lookup_widget(togglebutton,"radio_femelle_avance");
	if ( gtk_toggle_button_get_active(togglebutton)){
		gtk_widget_show(male);gtk_widget_show(femelle);}
	else {gtk_widget_hide(male);gtk_widget_hide(femelle);}
}

//*******************************************************************************************************************************************************************
void
on_checkbutton_sante_avance_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	GtkWidget *bonne,*malade;
	bonne=lookup_widget(togglebutton,"radio_bonne_avance");
	malade=lookup_widget(togglebutton,"radio_malade_avance");
	if ( gtk_toggle_button_get_active(togglebutton)){
		gtk_widget_show(bonne);gtk_widget_show(malade);}
	else {gtk_widget_hide(bonne);gtk_widget_hide(malade);}
}

//*******************************************************************************************************************************************************************
void
on_button_filtrer2_avance_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *nom,*mouton,*brebi,*vache,*veau;
	nom=lookup_widget(button,"checkbutton_nom_avance");
	mouton=lookup_widget(button,"radio_mouton_avance");
	brebi=lookup_widget(button,"radio_brebi_avance");
	veau=lookup_widget(button,"radio_veau_avance");
	vache=lookup_widget(button,"radio_vache_avance");

	GtkWidget *jour,*jour2,*mois,*mois2,*annee,*annee2,*label1,*label2,*date;
	date=lookup_widget(button,"checkbutton_date_avance");
	jour=lookup_widget(button,"spin_jour_avance");
	jour2=lookup_widget(button,"spin_jour2_avance");
	mois=lookup_widget(button,"spin_mois_avance");
	mois2=lookup_widget(button,"spin_mois2_avance");
	annee=lookup_widget(button,"spin_annee_avance");
	annee2=lookup_widget(button,"spin_annee2_avance");

	GtkWidget *male,*femelle,*sexe;
	sexe=lookup_widget(button,"checkbutton_sexe_avance");
	male=lookup_widget(button,"radio_male_avance");
	femelle=lookup_widget(button,"radio_femelle_avance");
	
	GtkWidget *bonne,*malade,*sante;
	sante=lookup_widget(button,"checkbutton_sante_avance");
	bonne=lookup_widget(button,"radio_bonne_avance");
	malade=lookup_widget(button,"radio_malade_avance");
	FILE *f,*f6,*f1,*f2,*f3,*f4;
	f=fopen("troupeau.txt","r");
	f1=fopen("date.txt","a+");
	f2=fopen("nom.txt","a+");
	f3=fopen("sante.txt","a+");
	f4=fopen("sexe.txt","a+");
	char nom2[30],boucle2[30],date2[30],sante2[30],date3[30],sexe2[30];
	char nom_animal[20],sexe_animal[20],sante_animal[20];
	int i,j_debut,m_debut,a_debut,j_fin,m_fin,a_fin;
	long d,fin,l;
	while (fscanf(f,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2)!=EOF){
		fprintf(f1,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2);
		fprintf(f2,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2);
		fprintf(f3,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2);
		fprintf(f4,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2);}
	fclose(f);fclose(f1);fclose(f2);fclose(f3);fclose(f4);

	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(nom))){
		remove("nom.txt");
		f=fopen("troupeau.txt","r");
		f2=fopen("nom.txt","a+");		
		GSList *List;
		List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (mouton));
		for (i=0;i<4;i++){
			if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
				strcpy(nom_animal,gtk_button_get_label(GTK_BUTTON(List->data)));
			else if (i!=3)
				List = g_slist_next(List);}
		while (fscanf(f,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2)!=EOF)
			if (strcmp(nom_animal,nom2)==0)
				fprintf(f2,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2);
		fclose(f);		
		fclose(f2);
	}
	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date))){
		remove("date.txt");
		f=fopen("troupeau.txt","r");
		f1=fopen("date.txt","a+");
		j_debut=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
		m_debut=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
		a_debut=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
		j_fin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour2));
		m_fin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois2));
		a_fin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee2));
		d=a_debut*10000+m_debut*100+j_debut;
		fin=a_fin*10000+m_fin*100+j_fin;
		while (fscanf(f,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2)!=EOF){
			strcpy(date3,date2);			
			l=date_long(date3);
			if ((l>=d)&&(l<=fin))
				fprintf(f1,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2);}
		fclose(f);		
		fclose(f1);
	}
	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(sexe))){
		remove("sexe.txt");		
		f=fopen("troupeau.txt","r");
		f4=fopen("sexe.txt","a+");		
		GSList *List;
		List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (male));
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
			strcpy(sexe_animal,gtk_button_get_label(GTK_BUTTON(List->data)));
		else {
			List = g_slist_next(List);
			strcpy(sexe_animal,gtk_button_get_label(GTK_BUTTON(List->data)));}
		while (fscanf(f,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2)!=EOF)
			if (strcmp(sexe_animal,sexe2)==0)
				fprintf(f4,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2);
		fclose(f);
		fclose(f4);
	}
	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(sante))){
		remove("sante.txt");
		f=fopen("troupeau.txt","r");
		f3=fopen("sante.txt","a+");		
		GSList *List;
		List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (malade));
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
			strcpy(sante_animal,gtk_button_get_label(GTK_BUTTON(List->data)));
		else {
			List = g_slist_next(List);
			strcpy(sante_animal,gtk_button_get_label(GTK_BUTTON(List->data)));}
		while (fscanf(f,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2)!=EOF)
			if (strcmp(sante_animal,sante2)==0)
				fprintf(f3,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2);
		fclose(f);
		fclose(f3);
	}
	f=fopen("troupeau.txt","r");
	
	f6=fopen("recherche avance.txt","a+");
	while (fscanf(f,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2)!=EOF){
		f1=fopen("date.txt","r");
		f2=fopen("nom.txt","r");
		f3=fopen("sante.txt","r");
		f4=fopen("sexe.txt","r");
		if ((existe(boucle2,f1)==1)&&(existe(boucle2,f2)==1)&&(existe(boucle2,f3)==1)&&(existe(boucle2,f4)==1)){
			fprintf(f6,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2);
			fclose(f1);fclose(f2);fclose(f3);fclose(f4);}
	}
	fclose(f);fclose(f6);
	remove("sante.txt");remove("sexe.txt");remove("nom.txt");remove("date.txt");
	GtkWidget *avance;
	avance=lookup_widget(button,"Recherche_avance_troupeau");
	
	GtkWidget *treeview1,*rech_avance;
	rech_avance=lookup_widget(button,"layout2Troupeaux");
	gtk_widget_hide(rech_avance);
	treeview1=lookup_widget(button,"treeview_troupeau");
	afficher_animal(treeview1,"","1");
	GtkWidget *buttonRechercherAnimal,*Actualiser_tree_view,*comboTirerPar,*buttonAjouterTroupeau,*buttonSupprimerTroupeau,*buttonModifier,*Nombre_troupeau1;
	Actualiser_tree_view=lookup_widget(button,"Actualiser_tree_view");
	buttonRechercherAnimal=lookup_widget(button,"buttonRechercherAnimal");
	comboTirerPar=lookup_widget(button,"comboTirerPar");
	buttonAjouterTroupeau=lookup_widget(button,"buttonAjouterTroupeau");
	buttonSupprimerTroupeau=lookup_widget(button,"buttonSupprimerTroupeau");
	buttonModifier=lookup_widget(button,"buttonModifier");
	Nombre_troupeau1=lookup_widget(button,"Nombre_troupeau1");
	
	gtk_widget_set_sensitive(buttonRechercherAnimal,TRUE);
	gtk_widget_set_sensitive(Actualiser_tree_view,TRUE);
	gtk_widget_set_sensitive(comboTirerPar,TRUE);
	gtk_widget_set_sensitive(buttonAjouterTroupeau,TRUE);
	gtk_widget_set_sensitive(buttonSupprimerTroupeau,TRUE);
	gtk_widget_set_sensitive(buttonModifier,TRUE);
	gtk_widget_set_sensitive(Nombre_troupeau1,TRUE);
	
}
//*******************************************************************************************************************************************************************
void
on_Nombre_troupeau1_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview,*fenetre;
	fenetre=lookup_widget(button,"nombre_troupeau");
	fenetre=create_nombre_troupeau();
	gtk_widget_show(fenetre);
	treeview=lookup_widget(fenetre,"treeview_nombre");
	afficher_nombre_animal(treeview);
}

//*******************************************************************************************************************************************************************
void
on_Retour_nombre_animal_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre;
	fenetre=lookup_widget(button,"nombre_troupeau");
	gtk_widget_destroy(fenetre);
}
//*******************************************************************************************************************************************************************


void
on_buttonAjouterEquipement_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* WindowAjouter;
	WindowAjouter=create_Ajout_equipement ();
	gtk_widget_show(WindowAjouter);
}


void
on_buttonSupprimerEquipement_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* windowSupprimer,*entry_serie;
	GtkWidget* Nom,*Serie,*Made,*Date,*Utiliser,*Etat,*label_raison,*raison;
	entry_serie=lookup_widget(button,"entry_serie");
	FILE* f;
	char supp_serie[20];
	char ch[30],nom[30],serie[30],utiliser[30],etat[30],made[30],date[30],nom2[30],serie2[30],utiliser2[30],etat2[30],made2[30],date2[30];
	int test=1,i,age;
	strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entry_serie)));
	f=fopen("equipement.txt","r+"); 
	while (fscanf(f,"%s %s %s %s %s %s\n",nom,serie,made,date,utiliser,etat)!=EOF)	
		if (strcmp(ch,serie)==0){
			test=0;
			strcpy(nom2,nom);strcpy(serie2,serie);strcpy(made2,made);strcpy(date2,date);strcpy(utiliser2,utiliser);strcpy(etat2,etat);}
		
	if (test==0) test=1;
	else test=0;
	fclose(f);
	if ((strcmp("",ch)!=0)&&(verif_serie(ch,1)==1)&&(test==1)){
		g_print("2");
		windowSupprimer=create_Supprimer_equipement();
		gtk_widget_show(windowSupprimer);
		Nom=lookup_widget(windowSupprimer,"label_nom_equipement2");
		Made=lookup_widget(windowSupprimer,"label_made_equipement2");
		Serie=lookup_widget(windowSupprimer,"label_serie_equipement2");
		Date=lookup_widget(windowSupprimer,"label_date_equipement2");
		Etat=lookup_widget(windowSupprimer,"label_etat_equipement2");
		Utiliser=lookup_widget(windowSupprimer,"label_utiliser_equipement2");
		gtk_label_set_text(GTK_LABEL(Nom),nom2);
		gtk_label_set_text(GTK_LABEL(Made),made2);
		gtk_label_set_text(GTK_LABEL(Date),date2);
		gtk_label_set_text(GTK_LABEL(Serie),serie2);
		gtk_label_set_text(GTK_LABEL(Utiliser),utiliser2);
		gtk_label_set_text(GTK_LABEL(Etat),etat2);
		raison=lookup_widget(windowSupprimer,"entry_raison_equipement");
		label_raison=lookup_widget(windowSupprimer,"label840");
		if (strcmp(gtk_label_get_text(Etat),"Defectueux")==0){
			gtk_widget_set_sensitive (raison,FALSE);
			gtk_widget_set_sensitive (label_raison,FALSE);}
	}
}

void
on_buttonModifierEquipement_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* windowModifier,*Serie,*labelNom,*labelEtat,*labelDate,*labelMade,*labelSerie,*labelUtiliser,*entryNom,*combo_entry_made;
	GtkWidget *entryEtat,*entrySerie,*entryJour,*entryMois,*entryAnnee,*entryMade,*entryUtiliser,*combo_entry_nom;
	//GtkWidget *Nom,*Etat,*Date,*Made;
	Serie=lookup_widget(button,"entry_serie");
	FILE* f;
	char nom[30],serie[30],etat[30],date[30],made[30],utiliser[30],nom2[30],serie2[30],etat2[30],date2[30],made2[30],utiliser2[30],ch[30];
	int test=0,i;
	strcpy(ch,gtk_entry_get_text(GTK_ENTRY(Serie)));
	f=fopen("equipement.txt","r"); 
	while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat)!=EOF)	
		if (strcmp(ch,e.serie)==0){
			test=1;break;}
	fclose(f);
	if ((strcmp("",ch)!=0)&&(verif_serie(ch,1)==1)&&(test==1)){
		windowModifier=create_Modifier_equipement();
		gtk_widget_show(windowModifier);
		labelNom=lookup_widget(windowModifier,"label_nom_equipement3");
		labelEtat=lookup_widget(windowModifier,"label_etat_equipement3");
		labelSerie=lookup_widget(windowModifier,"label_serie_equipement3");
		labelDate=lookup_widget(windowModifier,"label_date_equipement3");
		labelMade=lookup_widget(windowModifier,"label_made_equipement3");
		labelUtiliser=lookup_widget(windowModifier,"label_utiliser_equipement3");
		entryNom=lookup_widget(windowModifier,"entryModifierNom");
		entrySerie=lookup_widget(windowModifier,"entryModifierSerie");
		entryJour=lookup_widget(windowModifier,"spinModifierJour");
		entryMois=lookup_widget(windowModifier,"spinModifierMois");
		entryAnnee=lookup_widget(windowModifier,"spinModifierAnnee");
		entryMade=lookup_widget(windowModifier,"comboModifierMade");
		entryUtiliser=lookup_widget(windowModifier,"comboModifierUtiliser");
		combo_entry_made = GTK_COMBO (entryMade)->entry;
		gtk_label_set_text(GTK_LABEL(labelNom),e.nom);
		gtk_label_set_text(GTK_LABEL(labelEtat),e.etat);
		gtk_label_set_text(GTK_LABEL(labelDate),date);
		gtk_label_set_text(GTK_LABEL(labelSerie),e.serie);
		gtk_label_set_text(GTK_LABEL(labelMade),e.made);
		gtk_label_set_text(GTK_LABEL(labelUtiliser),e.utiliser);
		gtk_entry_set_text(GTK_ENTRY(entryNom),e.nom);
		gtk_entry_set_text(GTK_ENTRY(entrySerie),e.serie);
		gtk_entry_set_text(GTK_ENTRY(combo_entry_made),e.made);
		gtk_combo_box_set_active(entryUtiliser,get_utiliser(e.utiliser));
		char *jour[3],*mois[10],*annee[5];
		get_date(&jour,&mois,&annee,date);
		gtk_spin_button_set_value(entryJour,atoi(jour));
		gtk_spin_button_set_value(entryMois,atoi(mois));
		gtk_spin_button_set_value(entryAnnee,atoi(annee));
	}
}

void
on_Actualiser_tree_view_equipement_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview1,*combo_tirer_par,*combo_entry_tirer_par;
	char tirer_par[20];
	combo_tirer_par=lookup_widget(button,"comboTirerParEquipement");
	combo_entry_tirer_par = GTK_COMBO (combo_tirer_par)->entry;
	strcpy(tirer_par,gtk_entry_get_text(GTK_ENTRY(combo_entry_tirer_par)));
	treeview1=lookup_widget(button,"treeview_equipement");
	afficher_equipement(treeview1,"",tirer_par);
}


void
on_button_ajouter_equipement2_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
	struct Equipement e ; 
	GtkWidget* Nom,*Serie,*Made,*Date,*Utiliser,*Etat,*Jour,*Mois,*Annee,*windowAjouter,*combo_entry_name,*combo_entry_jour;
	GtkWidget *popup,*combo_entry_made;
	GtkWidget *verif_nom,*verif_made,*verif_utiliser,*verif_serie;
	GSList *List;
	char etat[30];
	GtkWidget *radioButtonDefectueux,*radioButtonIndefectueux;
	radioButtonDefectueux=lookup_widget(button,"radio_defectueux_equipement");
	radioButtonIndefectueux=lookup_widget(button,"radio_indefectueux_equipement");
	List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radioButtonDefectueux));g_print("1");
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
		strcpy(etat,gtk_button_get_label(GTK_BUTTON(List->data)));
	else{
		List = g_slist_next(List);
		strcpy(etat,gtk_button_get_label(GTK_BUTTON(List->data)));}

	char nom[30],serie[30],utiliser[30],made[30],date[30],jour[3],mois[3],annee[5];
	Nom=lookup_widget(button,"entry_nom_equipement");
	Made=lookup_widget(button,"entry_made_equipement");
	Serie=lookup_widget(button,"entry_serie_equipement");
	Utiliser=lookup_widget(button,"entry_utiliser_equipement");g_print("2");
	Jour=lookup_widget(button,"entry_jour_equipement");		
	Mois=lookup_widget(button,"entry_mois_equipement");		
	Annee=lookup_widget(button,"entry_annee_equipement");g_print("3");
	sprintf(jour,"%d",gtk_spin_button_get_value_as_int(Jour));
	sprintf(mois,"%d",gtk_spin_button_get_value_as_int(Mois));
	sprintf(annee,"%d",gtk_spin_button_get_value_as_int(Annee));g_print("4");
	combo_entry_made = GTK_COMBO (Made)->entry;g_print("4.1");
	strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(Nom)));g_print("4.2");
	strcpy(e.serie,gtk_entry_get_text(GTK_ENTRY(Serie)));g_print("4.3");
	strcpy(e.made,gtk_entry_get_text(GTK_ENTRY(combo_entry_made)));g_print("5");
	
	strcpy(e.date_achat.jour,jour);
	strcpy(e.date_achat.mois,mois);
	strcpy(e.date_achat.annee,annee);
	strcpy(e.utiliser,gtk_combo_box_get_active_text(Utiliser));g_print("6");
	strcpy(e.etat,etat);

	int test=1;	

	verif_nom=lookup_widget(button,"label796");
	verif_serie=lookup_widget(button,"label794");
	verif_made=lookup_widget(button,"label836");
	verif_utiliser=lookup_widget(button,"label837");g_print("7");
		
	//if ((gtk_widget_get_visible(verif_nom)==FALSE)&&(gtk_widget_get_visible(verif_serie)==FALSE)&&(gtk_widget_get_visible(verif_made)==FALSE)&&(gtk_widget_get_visible(verif_utiliser)==FALSE))
	//{	
		windowAjouter=lookup_widget(button,"Ajout_equipement");g_print("8");
		gtk_widget_destroy(windowAjouter);
		ajouter_equipement(e);
		popup=lookup_widget(button,"AjoutTermineAnimal");g_print("9");
		popup=create_AjoutTermineAnimal();
		gtk_widget_show(popup);g_print("10");
	//}
}


void
on_button_annuler_ajout_equipement_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* windowAjouter;
	windowAjouter=lookup_widget(button,"Ajout_equipement");
	gtk_widget_destroy(windowAjouter);
}


void
on_buttonModifierEquipement2_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Nom,*Serie,*Jour,*Mois,*Annee,*Made,*Utiliser;
	GtkWidget *windowAjouter;
	GtkWidget *popup,*label_serie_equipement3;
	GtkWidget *verif_name,*verif_boucle,*verif_date,*verif_sante;
	GSList *List;
	char etat[30];
	int jour,mois,annee;
	label_serie_equipement3=lookup_widget(button,"label_serie_equipement3");
	GtkWidget *radioButtonDefectueuxModifier,*radioButtonIndefectueuxModifier;
	radioButtonDefectueuxModifier=lookup_widget(button,"radioButtonDefectueuxModifier");
	radioButtonIndefectueuxModifier=lookup_widget(button,"radioButtonIndefectueuxModifier");
	List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (radioButtonDefectueuxModifier));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
		strcpy(etat,gtk_button_get_label(GTK_BUTTON(List->data)));
	else{
		List = g_slist_next(List);
		strcpy(etat,gtk_button_get_label(GTK_BUTTON(List->data)));}
	char nom[30],serie3[30],made[30],date[30],utiliser[30],*mois_char[30];
	Nom=lookup_widget(button,"entryModifierNom");
	Serie=lookup_widget(button,"entryModifierSerie");
	Made=lookup_widget(button,"entry_made_modif");
	Utiliser=lookup_widget(button,"comboModifierUtiliser");
	Jour=lookup_widget(button,"spinModifierJour");
	Mois=lookup_widget(button,"spinModifierMois");
	Annee=lookup_widget(button,"spinModifierAnnee");
	jour=gtk_spin_button_get_value_as_int(Jour);
	mois=gtk_spin_button_get_value_as_int(Mois);
	annee=gtk_spin_button_get_value_as_int(Annee);

	strcpy(e.serie,gtk_entry_get_text(GTK_ENTRY(Serie)));
	strcpy(e.etat,etat);
	strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(Nom)));
	
	sprintf(date,"%d/%d/%d",jour,mois,annee);
	strcpy(e.made,gtk_entry_get_text(GTK_ENTRY(Made)));
	int test=1;	
	FILE* f;
	
		windowAjouter=lookup_widget(button,"Modifier_equipement");
		strcpy(serie3,gtk_label_get_text(GTK_LABEL(label_serie_equipement3)));
		modifier_equipement(e,date,serie3);
		gtk_widget_destroy(windowAjouter);
		popup=lookup_widget(button,"ModificationTermineAnimal");
		popup=create_ModificationTermineAnimal();
		gtk_widget_show(popup);
}


void
on_AnnulerModifierEquipement_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* windowModifier;
	windowModifier=lookup_widget(button,"Modifier_equipement");
	gtk_widget_destroy(windowModifier);
}


void
on_buttonAnnulerSuppresionEquipement_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* windowSupprimer;
	windowSupprimer=lookup_widget(button,"Supprimer_equipement");
	gtk_widget_destroy(windowSupprimer);
}


void
on_button_supprimer_equipement2_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Serie,*popup,*Raison,*label_raison;
	char supp_serie[20],raison[20];
	Serie=lookup_widget(button,"label_serie_equipement2");
	Raison=lookup_widget(button,"entry_raison_equipement");
	label_raison=lookup_widget(button,"label840");
	if (gtk_widget_get_sensitive(Raison)==FALSE)
		strcpy(raison,"Defectueux");
	else strcpy(raison,gtk_entry_get_text(Raison));
	strcpy(supp_serie,gtk_label_get_text(GTK_LABEL(Serie)));
	if ((strcmp(raison,"")!=0)||(gtk_widget_get_sensitive(Raison)==FALSE)){	
		supprimer_equipement(supp_serie,raison);	
		popup=lookup_widget(button,"SuppresionTermineAnimal");
		popup=create_SuppresionTermineAnimal();
		gtk_widget_show(popup);
		on_buttonAnnulerSuppresionEquipement_clicked(button,user_data);}
}


void
on_buttonRechercherEquipement_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* entry_serie_rech;
	GtkWidget *treeview1;
	char serie_rech[20];
	entry_serie_rech=lookup_widget(button,"entrySerieRechercherEquipement");
	strcpy(serie_rech,gtk_entry_get_text(GTK_ENTRY(entry_serie_rech)));
	treeview1=lookup_widget(button,"treeview_equipement");
	if (strcmp(serie_rech,"")==0) return;
	afficher_equipement(treeview1,serie_rech,"Nom");
}


void
on_button_recherche_avance_equipement_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *rech_avance,*buttonRechercherEquipement,*Actualiser_tree_view_equipement,*comboTirerParEquipement,*buttonAjouterEquipement,*buttonSupprimerEquipement,*buttonModifierEquipement;
	rech_avance=lookup_widget(button,"layout3");
	buttonRechercherEquipement=lookup_widget(button,"buttonRechercherEquipement");
	Actualiser_tree_view_equipement=lookup_widget(button,"Actualiser_tree_view_equipement");
	comboTirerParEquipement=lookup_widget(button,"comboTirerParEquipement");
	buttonAjouterEquipement=lookup_widget(button,"buttonAjouterEquipement");
	buttonSupprimerEquipement=lookup_widget(button,"buttonSupprimerEquipement");
	buttonModifierEquipement=lookup_widget(button,"buttonModifierEquipement");
	if (gtk_widget_get_visible(rech_avance))
		{gtk_widget_hide(rech_avance);
		gtk_widget_set_sensitive(buttonRechercherEquipement,TRUE);
		gtk_widget_set_sensitive(Actualiser_tree_view_equipement,TRUE);
		gtk_widget_set_sensitive(comboTirerParEquipement,TRUE);
		gtk_widget_set_sensitive(buttonAjouterEquipement,TRUE);
		gtk_widget_set_sensitive(buttonSupprimerEquipement,TRUE);
		gtk_widget_set_sensitive(buttonModifierEquipement,TRUE);}
	else {
		gtk_widget_show(rech_avance);
		gtk_widget_set_sensitive(buttonRechercherEquipement,FALSE);
		gtk_widget_set_sensitive(Actualiser_tree_view_equipement,FALSE);
		gtk_widget_set_sensitive(comboTirerParEquipement,FALSE);
		gtk_widget_set_sensitive(buttonAjouterEquipement,FALSE);
		gtk_widget_set_sensitive(buttonSupprimerEquipement,FALSE);
		gtk_widget_set_sensitive(buttonModifierEquipement,FALSE);}
}


void
on_checkbutton_nom_avance_equipement_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	GtkWidget *combo;
	combo=lookup_widget(togglebutton,"combo_nom_avance_equipement");
	if ( gtk_toggle_button_get_active(togglebutton)){
		gtk_widget_show(combo);}
	else {gtk_widget_hide(combo);}
}


void
on_checkbutton_date_avance_equipement_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	GtkWidget *jour,*jour2,*mois,*mois2,*annee,*annee2,*label1,*label2;
	jour=lookup_widget(togglebutton,"spin_jour_avance_equipement");
	jour2=lookup_widget(togglebutton,"spin_jour2_avance_equipement");
	mois=lookup_widget(togglebutton,"spin_mois_avance_equipement");
	mois2=lookup_widget(togglebutton,"spin_mois2_avance_equipement");
	annee=lookup_widget(togglebutton,"spin_annee_avance_equipement");
	annee2=lookup_widget(togglebutton,"spin_annee2_avance_equipement");
	label1=lookup_widget(togglebutton,"label_date1_avance_equipement");
	label2=lookup_widget(togglebutton,"label_date2_avance_equipement");
	if ( gtk_toggle_button_get_active(togglebutton)){
		gtk_widget_show(jour);gtk_widget_show(jour2);gtk_widget_show(mois);gtk_widget_show(mois2);
		gtk_widget_show(annee);gtk_widget_show(annee2);gtk_widget_show(label1);gtk_widget_show(label2);}
	else {gtk_widget_hide(jour);gtk_widget_hide(jour2);gtk_widget_hide(mois);gtk_widget_hide(mois2);
		gtk_widget_hide(annee);gtk_widget_hide(annee2);gtk_widget_hide(label1);gtk_widget_hide(label2);}
}


void
on_checkbutton_made_avance_equipement_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	GtkWidget *combo;
	combo=lookup_widget(togglebutton,"combo_made_avance_equipement");
	if ( gtk_toggle_button_get_active(togglebutton)){
		gtk_widget_show(combo);}
	else {gtk_widget_hide(combo);}
}


void
on_checkbutton_utiliser_avance_equipement_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	GtkWidget *combo;
	combo=lookup_widget(togglebutton,"combo_utiliser_avance_equipement");
	if ( gtk_toggle_button_get_active(togglebutton)){
		gtk_widget_show(combo);}
	else {gtk_widget_hide(combo);}
}


void
on_checkbutton_etat_avance_equipement_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	GtkWidget *defectueux,*indefectueux;
	defectueux=lookup_widget(togglebutton,"radio_defectueux_avance_equipement");
	indefectueux=lookup_widget(togglebutton,"radio_indefectueux_avance_equipement");
	if ( gtk_toggle_button_get_active(togglebutton)){
		gtk_widget_show(defectueux);gtk_widget_show(indefectueux);}
	else {gtk_widget_hide(defectueux);gtk_widget_hide(indefectueux);}
}



void
on_button_filtrer2_avance_equipement_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	
	GtkWidget *combo_nom,*nom;
	nom=lookup_widget(button,"checkbutton_nom_avance_equipement");
	combo_nom=lookup_widget(button,"combo_nom_avance_equipement");

	GtkWidget *jour,*jour2,*mois,*mois2,*annee,*annee2,*label1,*label2,*date;
	date=lookup_widget(button,"checkbutton_date_avance_equipement");
	jour=lookup_widget(button,"spin_jour_avance_equipement");
	jour2=lookup_widget(button,"spin_jour2_avance_equipement");
	mois=lookup_widget(button,"spin_mois_avance_equipement");
	mois2=lookup_widget(button,"spin_mois2_avance_equipement");
	annee=lookup_widget(button,"spin_annee_avance_equipement");
	annee2=lookup_widget(button,"spin_annee2_avance_equipement");

	GtkWidget *combo_made,*made;
	made=lookup_widget(button,"checkbutton_made_avance_equipement");
	combo_made=lookup_widget(button,"combo_made_avance_equipement");
	
	GtkWidget *combo_utiliser=lookup_widget,*utiliser;
	utiliser=lookup_widget(button,"checkbutton_utiliser_avance_equipement");
	combo_utiliser=lookup_widget(button,"combo_utiliser_avance_equipement");

	GtkWidget *defectueux,*indefectueux,*etat;
	etat=lookup_widget(button,"checkbutton_etat_avance_equipement");
	defectueux=lookup_widget(button,"radio_defectueux_avance_equipement");
	indefectueux=lookup_widget(button,"radio_indefectueux_avance_equipement");
	FILE *f,*f6,*f1,*f2,*f3,*f4,*f5;
	f=fopen("equipement.txt","r");
	f1=fopen("nom.txt","a+");
	f2=fopen("date.txt","a+");
	f3=fopen("made.txt","a+");
	f4=fopen("utiliser.txt","a+");
	f5=fopen("etat.txt","a+");
	char date3[30],date2[30];
	char nom_equipement[20],date_equipement[20],made_equipement[20],utiliser_equipement[20],etat_equipement[20];
	int i,j_debut,m_debut,a_debut,j_fin,m_fin,a_fin;
	long d,fin,l;
	while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat)!=EOF){
		fprintf(f1,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat);
		fprintf(f2,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat);
		fprintf(f3,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat);
		fprintf(f4,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat);
		fprintf(f5,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat);}
	fclose(f);fclose(f1);fclose(f2);fclose(f3);fclose(f4);fclose(f5);

	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(nom))){
		GtkWidget *combo_entry_nom;
		remove("nom.txt");
		f=fopen("equipement.txt","r");
		f2=fopen("nom.txt","a+");		
		combo_entry_nom = GTK_COMBO (combo_nom)->entry;
		strcpy(nom_equipement,gtk_entry_get_text(combo_entry_nom));
		while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat)!=EOF)
			if (strcmp(nom_equipement,e.nom)==0)
				fprintf(f2,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat);
		fclose(f);		
		fclose(f2);
	}
	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date))){
		remove("date.txt");
		f=fopen("equipement.txt","r");
		f1=fopen("date.txt","a+");
		j_debut=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
		m_debut=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
		a_debut=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
		j_fin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour2));
		m_fin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois2));
		a_fin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee2));
		d=a_debut*10000+m_debut*100+j_debut;
		fin=a_fin*10000+m_fin*100+j_fin;
		while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat)!=EOF){
			strcpy(date3,date2);			
			l=date_long(date3);
			if ((l>=d)&&(l<=fin))
				fprintf(f1,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat);}
		fclose(f);		
		fclose(f1);
	}
	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(etat))){
		remove("etat.txt");		
		f=fopen("equipement.txt","r");
		f4=fopen("etat.txt","a+");		
		GSList *List;
		List= gtk_radio_button_get_group (GTK_RADIO_BUTTON (defectueux));
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(List->data)))
			strcpy(etat_equipement,gtk_button_get_label(GTK_BUTTON(List->data)));
		else {
			List = g_slist_next(List);
			strcpy(etat_equipement,gtk_button_get_label(GTK_BUTTON(List->data)));}
		while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat)!=EOF)
			if (strcmp(etat_equipement,e.etat)==0)
				fprintf(f4,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat);
		fclose(f);
		fclose(f4);
	}
	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(utiliser))){
		GtkWidget *combo_entry_utiliser;
		remove("utiliser.txt");
		f=fopen("equipement.txt","r");
		f3=fopen("utiliser.txt","a+");		
		combo_entry_utiliser = GTK_COMBO (combo_utiliser)->entry;
		strcpy(utiliser_equipement,gtk_entry_get_text(combo_entry_utiliser));
		while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat)!=EOF)
			if (strcmp(utiliser_equipement,e.utiliser)==0)
				fprintf(f3,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat);

		fclose(f);
		fclose(f3);
	}
	if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(made))){
		remove("made.txt");
		f=fopen("equipement.txt","r");
		f3=fopen("made.txt","a+");		
		strcpy(made_equipement,gtk_combo_box_get_active_text(combo_made));
		
		while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat)!=EOF)
			if (strcmp(made_equipement,e.made)==0)
				fprintf(f3,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat);
		fclose(f);
		fclose(f3);
	}
	f=fopen("equipement.txt","r");
	
	f6=fopen("recherche avance.txt","a+");
	while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat)!=EOF){
		f1=fopen("date.txt","r");
		f2=fopen("nom.txt","r");
		f3=fopen("utiliser.txt","r");
		f4=fopen("etat.txt","r");
		f5=fopen("made.txt","r");
		if ((existe_equi(e.serie,f1)==1)&&(existe_equi(e.serie,f2)==1)&&(existe_equi(e.serie,f3)==1)&&(existe_equi(e.serie,f4)==1)&&(existe_equi(e.serie,f5)==1)){
			fprintf(f6,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,e.utiliser,e.etat);
			fclose(f1);fclose(f2);fclose(f3);fclose(f4);fclose(f5);}
	}
	fclose(f);fclose(f6);
	remove("date.txt");remove("nom.txt");remove("utiliser.txt");remove("etat.txt");remove("made.txt");
	GtkWidget *treeview1,*rech_avance;
	rech_avance=lookup_widget(button,"layout3");
	gtk_widget_hide(rech_avance);
	treeview1=lookup_widget(button,"treeview_equipement");
	afficher_equipement(treeview1,"","1");
	GtkWidget *buttonRechercherEquipement,*Actualiser_tree_view_equipement,*comboTirerParEquipement,*buttonAjouterEquipement,*buttonSupprimerEquipement,*buttonModifierEquipement;
	Actualiser_tree_view_equipement=lookup_widget(button,"Actualiser_tree_view_equipement");
	buttonRechercherEquipement=lookup_widget(button,"buttonRechercherEquipement");
	comboTirerParEquipement=lookup_widget(button,"comboTirerParEquipement");
	buttonAjouterEquipement=lookup_widget(button,"buttonAjouterEquipement");
	buttonSupprimerEquipement=lookup_widget(button,"buttonSupprimerEquipement");
	buttonModifierEquipement=lookup_widget(button,"buttonModifierEquipement");
	
	gtk_widget_set_sensitive(buttonRechercherEquipement,TRUE);
	gtk_widget_set_sensitive(Actualiser_tree_view_equipement,TRUE);
	gtk_widget_set_sensitive(comboTirerParEquipement,TRUE);
	gtk_widget_set_sensitive(buttonAjouterEquipement,TRUE);
	gtk_widget_set_sensitive(buttonSupprimerEquipement,TRUE);
	gtk_widget_set_sensitive(buttonModifierEquipement,TRUE);
}

void
on_entryModifierSerie_changed          (GtkEditable     *editable,
                                        gpointer         user_data)
{
	GtkWidget *verif,*entry;
	char serie[20];
	verif=lookup_widget(editable,"label811");
	entry=lookup_widget(editable,"entryModifierSerie");
	strcpy(serie,gtk_entry_get_text(editable));
	if ((verif_serie(serie,1)==0)&&(strcmp(serie,gtk_entry_get_text(entry))!=0))
		gtk_widget_show(verif);
	else gtk_widget_hide(verif);
}


void
on_comboModifierUtiliser_changed       (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}

void
on_entry_made_modif_changed            (GtkEditable     *editable,
                                        gpointer         user_data)
{

}

gboolean
on_treeview_troupeau_button_press_event (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
	GtkTreePath *path;
	GtkTreeIter iter;
	int a;
	char ch[4];
	GtkWidget *menu,*fixed,*modifier1,*ajouter1,*supprimer1,*treeview;
        GdkEventMotion* e=(GdkEventMotion*)event;
        g_printf("Coordinates: (%u,%u)\n", (guint)e->x,(guint)e->y);
	
	GdkEvent * unionCompliquee = gtk_get_current_event();
	guint typeClic=(*unionCompliquee).button.button ;
	treeview=lookup_widget(widget,"treeview_troupeau");
    	
	menu=lookup_widget(widget,"menubar_troupeau");
	fixed=lookup_widget(widget,"fixed75Troupeaux");
	if((typeClic==3)&&(gtk_widget_get_visible(menu)==FALSE)){
		GtkTreeModel *model=gtk_tree_view_get_model(treeview);
		gtk_widget_show(menu);
		x=48+(guint)e->x;
		y=152+(guint)e->y;
		a=y-152;
		a=(a*10)/231;
		sprintf(ch,"%d",a);
		path=gtk_tree_path_new_from_string(ch);
		gtk_fixed_move (GTK_FIXED (fixed),menu,x,y);
		modifier1=lookup_widget(widget,"modifier1");
		supprimer1=lookup_widget(widget,"supprimer1");
		ajouter1=lookup_widget(widget,"ajouter1");
		if (gtk_tree_model_get_iter(model,&iter,path)==FALSE){
			gtk_widget_set_sensitive(ajouter1,TRUE);
			gtk_widget_set_sensitive(modifier1,FALSE);
			gtk_widget_set_sensitive(supprimer1,FALSE);}
		else {
			gtk_widget_set_sensitive(ajouter1,TRUE);
			gtk_widget_set_sensitive(modifier1,TRUE);
			gtk_widget_set_sensitive(supprimer1,TRUE);}
	}
	else if(( typeClic ==1)||(typeClic==3))
		gtk_widget_hide(menu);
	return FALSE;
}


void
on_ajouter1_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	GtkWidget* WindowAjouter,*windows;
	WindowAjouter=create_Ajout_animal ();
	gtk_widget_show(WindowAjouter);
	GtkWidget *menu;
	menu=lookup_widget(menuitem,"menubar_troupeau");
	gtk_widget_hide(menu);
}

void
on_modifier1_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	GtkTreePath *path;
	GtkTreeIter iter;
	int a;
	a=y-152;
	a=(a*10)/231;
	gint *age;
	GtkWidget* Actualiser_tree_view,*entry1,*entry2,*entry3,*entry4,*entry5,*entry6,*entry7,*fixed75,*treeview1,*treeview,*oui_modif_animal,*non_modif_animal;
	gchar *name,*boucle,*sexe,*date,*sante;
	
	char ch[4];
	gchar *first_name, *last_name, *tree_path_str;
	treeview=lookup_widget(menuitem,"treeview_troupeau");
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	
	sprintf(ch,"%d",a);
	path=gtk_tree_path_new_from_string(ch);
	tree_path_str = gtk_tree_path_to_string(path);
	oui_modif_animal=lookup_widget(menuitem,"oui_modif_animal");
	non_modif_animal=lookup_widget(menuitem,"non_modif_animal");
	entry1=lookup_widget(menuitem,"entry250");
	entry2=lookup_widget(menuitem,"entry251");
	entry3=lookup_widget(menuitem,"entry252");
	entry4=lookup_widget(menuitem,"entry253");
	entry5=lookup_widget(menuitem,"entry254");
	entry6=lookup_widget(menuitem,"entry255");
	entry7=lookup_widget(menuitem,"entry256");
	fixed75=lookup_widget(menuitem,"fixed75Troupeaux");
	GtkWidget *menu;
	menu=lookup_widget(treeview,"menubar_troupeau");
	if (gtk_tree_model_get_iter(model,&iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&name,1,&boucle,2,&sexe,3,&date,4,&age,5,&sante,-1);
		gint *m,*n;
		tree_path_str = gtk_tree_path_to_string(path);
		int path_int=atoi(tree_path_str);
		gtk_entry_set_text(entry1,name);
		gtk_entry_set_text(entry2,boucle);
		gtk_entry_set_text(entry7,boucle);
		gtk_entry_set_text(entry3,sexe);
		gtk_entry_set_text(entry4,date);
		gtk_entry_set_text(entry6,sante);

		n=152+23*path_int;
		gtk_fixed_move(GTK_FIXED (fixed75), oui_modif_animal,0,n);
		gtk_fixed_move(GTK_FIXED (fixed75), non_modif_animal,24,n);
		gtk_fixed_move(GTK_FIXED (fixed75), entry1,48,n);
		gtk_fixed_move(GTK_FIXED (fixed75), entry2,176,n);
		gtk_fixed_move(GTK_FIXED (fixed75), entry3,306,n);
		gtk_fixed_move(GTK_FIXED (fixed75), entry4,438,n);
		gtk_fixed_move(GTK_FIXED (fixed75), entry6,744,n);
		gtk_widget_show(oui_modif_animal);
		gtk_widget_show(non_modif_animal);
		gtk_widget_show(entry1);
		gtk_widget_show(entry2);
		gtk_widget_show(entry3);
		gtk_widget_show(entry4);
		gtk_widget_show(entry6);
		gtk_widget_set_sensitive(menu,FALSE);
	}
	gtk_widget_hide(menu);
}

void
on_supprimer1_activate                 (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	GtkTreePath *path;
	GtkTreeIter iter;
	int a;
	a=y-152;
	a=(a*10)/231;
	gint *age;
	GtkWidget* Actualiser_tree_view,*entry1,*entry2,*entry3,*entry4,*entry5,*entry6,*entry7,*fixed75,*treeview1,*treeview,*oui_modif_animal,*non_modif_animal;
	gchar *name,*boucle,*sexe,*date,*sante;
	
	char ch[4];
	gchar *first_name, *last_name, *tree_path_str;
	treeview=lookup_widget(menuitem,"treeview_troupeau");
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	
	sprintf(ch,"%d",a);
	path=gtk_tree_path_new_from_string(ch);
	tree_path_str = gtk_tree_path_to_string(path);

	if (gtk_tree_model_get_iter(model,&iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&name,1,&boucle,2,&sexe,3,&date,4,&age,5,&sante,-1);
		supprimer_animal(boucle);	
		}
	GtkWidget *menu;
	menu=lookup_widget(menuitem,"menubar_troupeau");
	gtk_widget_set_sensitive(menu,TRUE);
	gtk_widget_hide(menu);
	GtkWidget *button2;
	button2=lookup_widget(menuitem,"Actualiser_tree_view");
	on_Actualiser_tree_view_clicked (button2,user_data);
}


void
on_oui_modif_animal_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* Actualiser_tree_view,*entry1,*entry2,*entry3,*entry4,*entry5,*entry6,*entry7,*fixed75,*treeview1,*treeview,*oui_modif_animal,*non_modif_animal;
	char date1[30],boucle3[20];
	entry1=lookup_widget(button,"entry250");
	entry2=lookup_widget(button,"entry251");
	entry3=lookup_widget(button,"entry252");
	entry4=lookup_widget(button,"entry253");
	entry5=lookup_widget(button,"entry254");
	entry6=lookup_widget(button,"entry255");
	entry7=lookup_widget(button,"entry256");
	oui_modif_animal=lookup_widget(button,"oui_modif_animal");
	non_modif_animal=lookup_widget(button,"non_modif_animal");
	strcpy(animal.name,gtk_entry_get_text(entry1));
	strcpy(animal.boucle,gtk_entry_get_text(entry2));
	strcpy(animal.sexe,gtk_entry_get_text(entry3));
	strcpy(date1,gtk_entry_get_text(entry4));
	strcpy(animal.sante,gtk_entry_get_text(entry6));
	strcpy(boucle3,gtk_entry_get_text(entry7));
	if (verif_les_entry(animal.name,animal.boucle,boucle3,animal.sexe,date1,animal.sante)){
		modifier_animal(animal,date1,boucle3);
		if (strcmp(animal.sante,"Bonne")==0)
			supprimer_animal_malade(animal.boucle);
		gtk_widget_hide(entry1);
		gtk_widget_hide(entry2);
		gtk_widget_hide(entry3);
		gtk_widget_hide(entry4);
		gtk_widget_hide(entry5);
		gtk_widget_hide(entry6);
		gtk_widget_hide(oui_modif_animal);
		gtk_widget_hide(non_modif_animal);
		GtkWidget *menu;
		menu=lookup_widget(button,"menubar_troupeau");
		gtk_widget_set_sensitive(menu,TRUE);
		gtk_widget_hide(menu);
		GtkWidget *button2;
		button2=lookup_widget(button,"Actualiser_tree_view");
		on_Actualiser_tree_view_clicked (button2,user_data);}
}

void
on_non_modif_animal_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *entry1,*entry2,*entry3,*entry4,*entry5,*entry6,*entry7,*fixed75,*treeview1,*treeview,*oui_modif_animal,*non_modif_animal;
	oui_modif_animal=lookup_widget(button,"oui_modif_animal");
	non_modif_animal=lookup_widget(button,"non_modif_animal");
	entry1=lookup_widget(button,"entry250");
	entry2=lookup_widget(button,"entry251");
	entry3=lookup_widget(button,"entry252");
	entry4=lookup_widget(button,"entry253");
	entry5=lookup_widget(button,"entry254");
	entry6=lookup_widget(button,"entry255");
	entry7=lookup_widget(button,"entry256");
	gtk_widget_hide(entry1);
	gtk_widget_hide(entry2);
	gtk_widget_hide(entry3);
	gtk_widget_hide(entry4);
	gtk_widget_hide(entry5);
	gtk_widget_hide(entry6);
	gtk_widget_hide(oui_modif_animal);
	gtk_widget_hide(non_modif_animal);
	GtkWidget *menu;
	menu=lookup_widget(button,"menubar_troupeau");
	gtk_widget_set_sensitive(menu,TRUE);
	gtk_widget_hide(menu);
}


void
on_button_retour_fiche_animal_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* Fiche_animal;
	Fiche_animal=lookup_widget(button,"Fiche_animal");
	gtk_widget_destroy(Fiche_animal);
}

int a;
void
on_button_les_troupeaux_malades_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	a=2;
	GtkWidget* Les_animaux_malades,*GestionTroupeaux;
	GestionTroupeaux=lookup_widget(button,"GestionTroupeaux");
	gtk_widget_destroy(GestionTroupeaux);
	Les_animaux_malades=create_Les_animaux_malades();
	gtk_widget_show(Les_animaux_malades);
}


void
on_button_nombre_animaux_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview,*fenetre;
	fenetre=create_nombre_troupeau();
	gtk_widget_show(fenetre);
	treeview=lookup_widget(fenetre,"treeview_nombre");
	afficher_nombre_animal(treeview);
}


void
on_button_nouvelle_saisie_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	
	GtkWidget* Espace_ouvrier,*GestionTroupeaux;
	GestionTroupeaux=lookup_widget(button,"GestionTroupeaux");
	gtk_widget_destroy(GestionTroupeaux);
	Espace_ouvrier=create_Espace_ouvrier();
	gtk_widget_show(Espace_ouvrier);
}


void
on_buttonRetourAfficherTroupeaux_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* Espace_ouvrier,*GestionTroupeaux;
	Espace_ouvrier=lookup_widget(button,"Espace_ouvrier");
	gtk_widget_destroy(Espace_ouvrier);
	GestionTroupeaux=create_GestionTroupeaux();
	gtk_widget_show(GestionTroupeaux);
}


void
on_buttonRetourTroupeauMalade_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
	if (a==2){
		GtkWidget* Les_animaux_malades,*GestionTroupeaux;
		Les_animaux_malades=lookup_widget(button,"Les_animaux_malades");
		gtk_widget_destroy(Les_animaux_malades);
		GestionTroupeaux=create_GestionTroupeaux();
		gtk_widget_show(GestionTroupeaux);}
	else {
		GtkWidget* Les_animaux_malades,*Les_troupeaux_admin;
		Les_animaux_malades=lookup_widget(button,"Les_animaux_malades");
		gtk_widget_destroy(Les_animaux_malades);
		Les_troupeaux_admin=create_Les_troupeaux_admin();
		gtk_widget_show(Les_troupeaux_admin);}
}

/*
void
on_buttonAdminSmartFarm_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonOuvrierSmartFarm_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}
*/

void
on_buttonGestionOuvrier2SmartFarm_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *GestionOuvriers,*espace_admin;
	espace_admin=lookup_widget(button,"espace_admin");
	gtk_widget_destroy(espace_admin);
	GestionOuvriers=create_GestionOuvriers();
	gtk_widget_show(GestionOuvriers);
}


void
on_buttonGestionClient2SmartFarm_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Afficher_client,*espace_admin,*treeview1;
	espace_admin=lookup_widget(button,"espace_admin");
	gtk_widget_destroy(espace_admin);
	Afficher_client=create_Afficher_client();
	gtk_widget_show(Afficher_client);
	treeview1=lookup_widget(Afficher_client,"treeview1Client");
        afficher_client(treeview1,0);
}


void
on_buttonLesCapteursSmartFarm_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *affichage_admin,*espace_admin;
	espace_admin=lookup_widget(button,"espace_admin");
	gtk_widget_destroy(espace_admin);
	affichage_admin=create_affichage_admin();
	gtk_widget_show(affichage_admin);
}


void
on_buttonLesEquipements_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	
	GtkWidget *Les_equipements_admin,*espace_admin;
	espace_admin=lookup_widget(button,"espace_admin");
	gtk_widget_destroy(espace_admin);
	Les_equipements_admin=create_Les_equipements_admin();
	gtk_widget_show(Les_equipements_admin);
}


void
on_buttonLesTroupeaux_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Les_troupeaux_admin,*espace_admin;
	espace_admin=lookup_widget(button,"espace_admin");
	gtk_widget_destroy(espace_admin);
	Les_troupeaux_admin=create_Les_troupeaux_admin();
	gtk_widget_show(Les_troupeaux_admin);
}


void
on_buttonLaCalendrier_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	
	GtkWidget *espace_admin2,*espace_admin;
	espace_admin=lookup_widget(button,"espace_admin");
	gtk_widget_destroy(espace_admin);
	espace_admin2=create_espace_admin2();
	gtk_widget_show(espace_admin2);
}


void
on_buttonRetour12Troupeaux_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Les_troupeaux_admin,*espace_admin;
	Les_troupeaux_admin=lookup_widget(button,"Les_troupeaux_admin");
	gtk_widget_destroy(Les_troupeaux_admin);
	espace_admin=create_espace_admin();
	gtk_widget_show(espace_admin);
}


void
on_buttonDeconnecter13Troupeaux_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Les_troupeaux_admin,*Page_Accueil,*espace_admin,*espace_ouvrier;
	Les_troupeaux_admin=lookup_widget(button,"Les_troupeaux_admin");
	gtk_widget_destroy(Les_troupeaux_admin);
	espace_admin=lookup_widget(button,"espace_admin");
	gtk_widget_destroy(espace_admin);
	espace_ouvrier=lookup_widget(button,"espace_ouvrier");
	gtk_widget_destroy(espace_ouvrier);
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
}


void
on_Les_animaux_malades_admin_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	a=1;
	GtkWidget *Les_troupeaux_admin,*Les_animaux_malades;
	Les_troupeaux_admin=lookup_widget(button,"Les_troupeaux_admin");
	gtk_widget_destroy(Les_troupeaux_admin);
	Les_animaux_malades=create_Les_animaux_malades();
	gtk_widget_show(Les_animaux_malades);
}


void
on_buttonActualiser11Troupeaux_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview1;
	
	treeview1=lookup_widget(button,"treeview1TroupeauAdmin");
	afficher_animal(treeview1,"","");
}

/*
void
on_buttonRetour2SmartFarm_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}
*/

void
on_buttonQuitter3SmartFarm_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}




void
on_buttonQuitter4SmartFarm_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}


void
on_button11RetourTroupeau_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionTroupeaux,*espace_ouvrier;
	GestionTroupeaux=lookup_widget(button,"GestionTroupeaux");
	gtk_widget_destroy(GestionTroupeaux);
	espace_ouvrier=create_espace_ouvrier();
	gtk_widget_show(espace_ouvrier);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *espace_admin2,*ajouterp;
ajouterp=lookup_widget(button,"ajouterp");
 ajouterp = create_ajouterp();
  gtk_widget_show (ajouterp);
  espace_admin2=lookup_widget(button,"espace_admin2");
  gtk_widget_hide(espace_admin2);

}

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *chercherp,*espace_admin2;
chercherp=lookup_widget(button,"chercherp");
  chercherp = create_chercherp();
  gtk_widget_show (chercherp);
  espace_admin2=lookup_widget(button,"espace_admin2");
  gtk_widget_hide(espace_admin2);
}

void
on_button3_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *afficherp,*espace_admin2;
  afficherp= create_afficherp();
  gtk_widget_show (afficherp);
  espace_admin2=lookup_widget(button,"espace_admin2");
  gtk_widget_hide(espace_admin2);
}



void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *supprimerp,*espace_admin2;
  supprimerp = create_supprimerp ();
  gtk_widget_show (supprimerp);
  espace_admin2=lookup_widget(button,"espace_admin2");
  gtk_widget_hide(espace_admin2);
}



void
on_button5_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *espace_admin2;
  espace_admin2 = create_espace_admin2 ();
  gtk_widget_show (espace_admin2);
  espace_admin2=lookup_widget(button,"espace_admin2");
  gtk_widget_hide(espace_admin2);
}


//*******************************************************************************************************************************************************************



void
on_button6_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    int x;
           plante p;
        GtkWidget *input1, *input2,*input3, *input4, *input5,*input6;
        GtkWidget *output;
        
        input1=lookup_widget(button,"entry1");
        input2=lookup_widget(button,"entry2");
        input3=lookup_widget(button,"comboboxentry5");
        output=lookup_widget(button,"label15");
        input4=lookup_widget(button,"entry4");
	input5=lookup_widget(button,"entry5");
	input6=lookup_widget(button,"entry6");
  strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.code,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.type,gtk_combo_box_get_active_text(input3));
strcpy(p.dateplantation,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.etat,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.stock,gtk_entry_get_text(GTK_ENTRY(input6)));

        if ((strlen(p.code)==0)||(strlen(p.nom)==0)||(strlen(p.type)==0)||(strlen(p.dateplantation)==0)||(strlen(p.etat)==0)||(strlen(p.stock)==0))
{
       gtk_label_set_text(GTK_LABEL(output),"veuilez remplir toutes les cases");
}
else
{
        x=ajouterp(p);
        if (x==0)
       {
        gtk_label_set_text(GTK_LABEL(output),"ajout avec succés");
       }
       else if (x==1)
      {
       gtk_label_set_text(GTK_LABEL(output),"plante deja existante");
       }
}
}

void
on_button7_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *ajouterp,*espace_admin2;
  espace_admin2 = create_espace_admin2 ();
  gtk_widget_show (espace_admin2);
  ajouterp=lookup_widget(button,"ajouterp");
  gtk_widget_hide(ajouterp);
}


//*******************************************************************************************************************************************************************


void
on_button8_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  int x;
  char nom[20];
	char code[10];
	char dateplantation[10];
	char type[10];
	char etat[10];
	char stock[10];
  GtkWidget *input;
  GtkWidget *modifierp,*chercherp2;
  GtkWidget *output7;
  GtkWidget *output1,*output2,*output3,*output4,*output5,*output6;
  input=lookup_widget(button,"entry7");
  strcpy(code,gtk_entry_get_text(GTK_ENTRY(input)));
  output7=lookup_widget(button,"label19");
if ((strlen(code)==0))
{
       gtk_label_set_text(GTK_LABEL(output6),"veuillez remplir la case");
}
else
{
  x=chercherp(code);
 if (x==1)
{
  
  gtk_label_set_text(GTK_LABEL(output6)," ");
  modifierp = create_modifierp ();
  gtk_widget_show (modifierp);
  chercherp2=lookup_widget(button,"chercherp");
  gtk_widget_hide(chercherp2); 
  modp ( nom, code, type, dateplantation ,  etat ,  stock);

  output1=lookup_widget(modifierp,"entry248");
  output2=lookup_widget(modifierp,"entry249");
  output3=lookup_widget(modifierp,"entry250");
  output4=lookup_widget(modifierp,"entry251");
  output5=lookup_widget(modifierp,"entry252");
  output6=lookup_widget(modifierp,"entry253");
  
  
  gtk_entry_set_text(GTK_ENTRY(output1),nom );
  gtk_entry_set_text(GTK_ENTRY(output2),code);
  gtk_entry_set_text(GTK_ENTRY(output3),type);
  gtk_entry_set_text(GTK_ENTRY(output4),dateplantation);
  gtk_entry_set_text(GTK_ENTRY(output5),etat);
  gtk_entry_set_text(GTK_ENTRY(output6),stock );
 
  
  
}
else 
{
  
  gtk_label_set_text(GTK_LABEL(output7),"plante non existante");
}
}
}


void
on_button9_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *chercherp,*espace_admin2;
  espace_admin2 = create_espace_admin2 ();
  gtk_widget_show (espace_admin2);
  chercherp=lookup_widget(button,"chercherp");
  gtk_widget_hide(chercherp);
}



//*******************************************************************************************************************************************************************

void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    plante p;
   
   GtkWidget *output;
   GtkWidget *input1,*input2,*input3,*input4,*input5,*input6;
   input1=lookup_widget(button,"entry8");

        input2=lookup_widget(button,"entry9");
        output=lookup_widget(button,"label28");
        input3=lookup_widget(button,"comboboxentry6");
	input4=lookup_widget(button,"entry11");
	input5=lookup_widget(button,"entry12");
	input6=lookup_widget(button,"entry13");
        strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));

strcpy(p.code,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.dateplantation,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.type,gtk_combo_box_get_active_text(input3));
strcpy(p.etat,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.stock,gtk_entry_get_text(GTK_ENTRY(input6)));

        modifierp(p);
    if ((strlen(p.code)==0)||(strlen(p.nom)==0)||(strlen(p.dateplantation)==0)||(strlen(p.type)==0)||(strlen(p.etat)==0)||(strlen(p.stock)==0))
{
       gtk_label_set_text(GTK_LABEL(output),"veuilez remplir toutes les cases");
}
else
{
     gtk_label_set_text(GTK_LABEL(output),"modifié avec succés");
}
}


void
on_button12_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *modifierp,*chercherp;
  chercherp = create_chercherp ();
  gtk_widget_show (chercherp);
 modifierp=lookup_widget(button,"modifierp");
  gtk_widget_hide(modifierp);
}


void
on_button13_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *modifierp,*espace_admin2;
  espace_admin2 = create_espace_admin2 ();
  gtk_widget_show (espace_admin2);
 modifierp=lookup_widget(button,"modifierp");
  gtk_widget_hide(modifierp);
}



//*******************************************************************************************************************************************************************

void
on_button14_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
{ 

    char code[20];
  int x;
   GtkWidget *input;
   GtkWidget *output;
   input=lookup_widget(button,"entry14");
   strcpy(code,gtk_entry_get_text(GTK_ENTRY(input)));
   x=chercherp(code);
   output=lookup_widget(button,"label35");
 if ((strlen(code)==0))
{
       gtk_label_set_text(GTK_LABEL(output),"veuilez remplir la case");
}
else 
{
   if (x==1)
{
    supprimerp (code,x) ;
  gtk_label_set_text(GTK_LABEL(output),"plante supprimé"); 
}
else
{
  gtk_label_set_text(GTK_LABEL(output),"plante non existante");
}
}
}
}



void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *supprimerp,*espace_admin2;
  espace_admin2 = create_espace_admin2 ();
  gtk_widget_show (espace_admin2);
 supprimerp=lookup_widget(button,"supprimerp");
  gtk_widget_hide(supprimerp);
}




//*******************************************************************************************************************************************************************


void
on_button16_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *treeview1;
   
   treeview1=lookup_widget(button,"treeview1");
   afficherp (treeview1);
}


void
on_button17_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *afficherp,*espace_admin2;
  espace_admin2 = create_espace_admin2 ();
  gtk_widget_show (espace_admin2);
 afficherp=lookup_widget(button,"afficherp");
  gtk_widget_hide(afficherp);
}

//*******************************************************************************************************************************************************************

void

on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
        GtkWidget *espace_agriculteur;
	GtkWidget *emplois0;
	espace_agriculteur=lookup_widget(button,"espace_agriculteur");
	gtk_widget_destroy(espace_agriculteur);
	emplois0=create_emplois0();
	gtk_widget_show(emplois0);
}





void

on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
        GtkWidget *espace_agriculteur;
	GtkWidget *dossier0;
        GtkWidget *afficherp;
	espace_agriculteur=lookup_widget(button,"espace_agriculteur");
	gtk_widget_destroy(espace_agriculteur);
	dossier0=create_dossier0();
        afficherp=create_afficherp();
	gtk_widget_hide(espace_agriculteur);
	gtk_widget_show(dossier0);
        gtk_widget_show(afficherp);
}



void

on_button20_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
	GtkWidget *espace_agriculteur;
	GtkWidget *repiquage;
	espace_agriculteur=lookup_widget(button,"espace_agriculteur");
	gtk_widget_destroy(espace_agriculteur);
	repiquage=create_repiquage();
	gtk_widget_show(repiquage);
}



void

on_button21_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{

}





void

on_button22_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
        GtkWidget *espace_agriculteur;
	GtkWidget *messages;
	espace_agriculteur=lookup_widget(button,"espace_agriculteur");
	messages=lookup_widget(button,"messages");
	gtk_widget_destroy(espace_agriculteur);
	messages=create_messages();
	gtk_widget_show(messages);

}





void

on_button23_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
        GtkWidget *espace_agriculteur;
	GtkWidget *notifications;
	espace_agriculteur=lookup_widget(button,"espace_agriculteur");
	gtk_widget_destroy(espace_agriculteur);
	notifications=create_notifications();
        gtk_widget_hide(espace_agriculteur);
	gtk_widget_show(notifications);
}



void

on_button24_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
        GtkWidget *espace_agriculteur;
	espace_agriculteur=lookup_widget(button,"espace_agriculteur");
	gtk_widget_destroy(espace_agriculteur);
	espace_agriculteur=create_espace_agriculteur();
	gtk_widget_hide(espace_agriculteur);
	gtk_widget_show(espace_agriculteur);
}



//*******************************************************************************************************************************************************************



void

on_button25_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
   GtkWidget *treeview2;
   GtkWidget *emplois0;
   treeview2=lookup_widget(button,"treeview2");
   affiche_emplois (treeview2);
}





void

on_button26_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
  GtkWidget *emplois0,*espace_agriculteur;
  emplois0=lookup_widget(button,"emplois0");
  gtk_widget_destroy(emplois0);
  espace_agriculteur=lookup_widget(emplois0,"espace_agriculteur");
  espace_agriculteur = create_espace_agriculteur();
  gtk_widget_show(espace_agriculteur);

}

//*******************************************************************************************************************************************************************



void

on_button27_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
        GtkWidget *input;
	
	GtkWidget *output1;
	GtkWidget *output2;
        GtkWidget *output3;	
	GtkWidget *dossier0;
	GtkWidget *dossier1;
	char code[10];
	char *nom[10];
	char *date[10];
	int x1;
	input= lookup_widget(button,"entry15");
	output3=lookup_widget(button,"label54");
	strcpy(code,gtk_entry_get_text(GTK_ENTRY(input)));
	if((strlen(code)==0))

	{
		gtk_label_set_text(GTK_LABEL(output3),"veuillez remplir la case");
	}

	else
	{
		
		x1=verifier_plante(code);
		
		if(x1==1)

		{

			gtk_label_set_text(GTK_LABEL(output3),"plante trouvé ");
			save5(code);
			dossier1=create_dossier1();
			gtk_widget_show(dossier1);
			dossier0= lookup_widget(button,"dossier0");
			gtk_widget_destroy(dossier0);
			remplir1(nom,code,date);
			
			output1=lookup_widget(dossier1,"entry16");
			output2=lookup_widget(dossier1,"entry18");		
			gtk_entry_set_text(GTK_ENTRY(output1),nom);
			gtk_entry_set_text(GTK_ENTRY(output2),date);
		}
		else

		{
			gtk_label_set_text(GTK_LABEL(output3),"plante introuvable");

		}
      }
      
}



void

on_button28_clicked                   (GtkButton *button,
                                        gpointer         user_data)

{
	GtkWidget *dossier0;
	GtkWidget *dossier2a;
	dossier0= lookup_widget(button,"dossier0");
	gtk_widget_hide(dossier0);
	dossier2a=create_dossier2a();
	gtk_widget_show(dossier2a);
}





void

on_button29_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
        GtkWidget *dossier0;
	GtkWidget *dossier4;
	dossier0= lookup_widget(button,"dossier0");
	gtk_widget_hide(dossier0);
	dossier4=create_dossier4();
	gtk_widget_show(dossier4);
}





void

on_button30_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{

        GtkWidget *dossier0;
        GtkWidget *dossier3;
	dossier0=lookup_widget(button,"dossier0");
	gtk_widget_destroy(dossier0);
	dossier3=create_dossier3();
	gtk_widget_hide(dossier0);
	gtk_widget_show(dossier3);

}

 

void

on_button31_clicked                    (GtkButton       *button,
                                        gpointer         user_data)



{
        GtkWidget *espace_agriculteur;
	GtkWidget *dossier0;
	dossier0= lookup_widget(button,"dossier0");
	gtk_widget_hide(dossier0);
	espace_agriculteur=create_espace_agriculteur();
	gtk_widget_show(espace_agriculteur);

}


//*******************************************************************************************************************************************************************

void

on_button33_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
  GtkWidget *dossier1,*dossier0;
  dossier1=lookup_widget(button,"dossier1");
  gtk_widget_destroy(dossier1);
  dossier0=lookup_widget(dossier1,"dossier0");
  dossier0 = create_dossier0();
  gtk_widget_show(dossier0);

}


void

on_button32_clicked                   (GtkButton *button,
                                        gpointer         user_data)



{
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;	
	GtkWidget *input5;
	GtkWidget *input6;	
        GtkWidget *output1;	
	GtkWidget *dossier1;
	GtkWidget *combo_entry_input3,*combo_entry_input6;
	//dossier1=create_dossier1 ();
        
	dossier doss1;
	char code[10];
	int x1;
	input1= lookup_widget(button,"entry33");
	input2= lookup_widget(button,"entry16");
	input3= lookup_widget(button,"comboboxentry3");
	input4=lookup_widget(button,"entry18");
	input5=lookup_widget(button,"entry19");
	input6=lookup_widget(button,"comboboxentry1");	
	output1=lookup_widget(button,"label60");
	//unsave5(code);
	combo_entry_input3 = GTK_COMBO (input3)->entry;
	combo_entry_input6 = GTK_COMBO (input6)->entry;

	strcpy(doss1.num,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(doss1.nom,gtk_entry_get_text(GTK_ENTRY(input2)));

	strcpy(doss1.type,gtk_entry_get_text(combo_entry_input3));

	strcpy(doss1.date,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(doss1.temperature,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(doss1.lieu,gtk_entry_get_text(combo_entry_input6));
       if((strlen(doss1.num)==0))	
	{
		gtk_label_set_text(GTK_LABEL(output1),"veuillez remplir toutes les cases");
	}
	else if((strlen(doss1.nom)==0))
	{
		gtk_label_set_text(GTK_LABEL(output1),"veuillez remplir toutes les cases");
	}
	else if((strlen(doss1.type)==0))
	{
		gtk_label_set_text(GTK_LABEL(output1),"veuillez remplir toutes les cases");
	}
	else if((strlen(doss1.date)==0))
	{
		gtk_label_set_text(GTK_LABEL(output1),"veuillez remplir toutes les cases");
	}
	else if((strlen(doss1.temperature)==0))
	{
		gtk_label_set_text(GTK_LABEL(output1),"veuillez remplir toutes les cases");
	}
	else if((strlen(doss1.lieu)==0))
	{
		gtk_label_set_text(GTK_LABEL(output1),"veuillez remplir toutes les cases");
	}		  
	else 
	{
		x1=verifier_dossier(doss1.num);
             if(x1==0)
		{
			ajouter_dossier(doss1);
			gtk_label_set_text(GTK_LABEL(output1),"le dossier a été  ajouté");
			 	
			
		
		}
		else if(x1==1)
		{
			gtk_label_set_text(GTK_LABEL(output1),"dossier déja existant");
			
		}
	}
}

     

//*******************************************************************************************************************************************************************

void

on_button35_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
        GtkWidget *dossier0;
	GtkWidget *dossier2a;
	dossier2a= lookup_widget(button,"dossier2a");
	gtk_widget_hide(dossier2a);
	dossier0=create_dossier0();
	gtk_widget_show(dossier0);	
}





void

on_button34_clicked                    (GtkButton       *button,
                                       gpointer         user_data)

{
        GtkWidget *input;
	GtkWidget *output7;
	GtkWidget *output1;
	GtkWidget *output2;
 	GtkWidget *output3;
	GtkWidget *output4;
	GtkWidget *output5;
	GtkWidget *dossier2;
	GtkWidget *dossier2a;
	char num[15];
	char nom[15];
	char type[15];
	char date[15];
	char temperature[15];
	char lieu[15];
        char msg[20];
	int x1;
	input= lookup_widget(button,"entry20");
	output7=lookup_widget(button,"label64");
	strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));
	if((strlen(num)==0))
	{
		gtk_label_set_text(GTK_LABEL(output7),"veuillez remplir la case");
	}
	else

	{
		x1=verifier_dossier(num);
		if(x1==1)

		{
			gtk_label_set_text(GTK_LABEL(output7)," ");
			//save5(num);
			dossier2=create_dossier2();
			gtk_widget_show(dossier2);
			dossier2a= lookup_widget(button,"dossier2a");
			gtk_widget_hide(dossier2a);
			modifications(num,nom,type,date,temperature,lieu);
			output1=lookup_widget(dossier2,"entry21");
			output2=lookup_widget(dossier2,"comboboxentry4");
			output3=lookup_widget(dossier2,"entry23");
			output4=lookup_widget(dossier2,"entry24");
			output5=lookup_widget(dossier2,"comboboxentry2");			
			gtk_entry_set_text(GTK_ENTRY(output1),nom);
			gtk_combo_box_get_active_text(output2);
			gtk_entry_set_text(GTK_ENTRY(output3),date);
			gtk_entry_set_text(GTK_ENTRY(output4),temperature);
			gtk_combo_box_get_active_text(output5);

		}

		else

		{

			gtk_label_set_text(GTK_LABEL(output7),"dossier introuvable");			

		}
      }

}

//*******************************************************************************************************************************************************************

void

on_button59_clicked                    (GtkButton       *button,

                                        gpointer         user_data)

{
        GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;	
	GtkWidget *output;
	GtkWidget *dossier2;
	dossier2=create_dossier2();
	dossier doss1;
	char num[30];
	char nom[30];
	char type[30];
	char date[30];
	char temperature[30];
	char lieu[30];
        char msg[50];
	input1= lookup_widget(button,"entry21");
	input2= lookup_widget(button,"comboboxentry4");
	input3= lookup_widget(button,"entry23");
	input4= lookup_widget(button,"entry24");
	input5= lookup_widget(button,"comboboxentry2");
	output=lookup_widget(button,"label73");
	unsave5(num);
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(type,gtk_combo_box_get_active_text(input2));
	strcpy(date,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(temperature,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(lieu,gtk_combo_box_get_active_text(input5));
	modifier_dossier(num,nom,type,date,temperature,lieu);
	strcpy(msg,"modification a été  effectuée");
	gtk_label_set_text(GTK_LABEL(output),msg);
}







void

on_button60_clicked                    (GtkButton       *button,

                                        gpointer         user_data)

{
        GtkWidget *espace_agriculteur;
	GtkWidget *dossier2;
	dossier2= lookup_widget(button,"dossier2");
	gtk_widget_hide(dossier2);
	espace_agriculteur=create_espace_agriculteur();
	gtk_widget_show(espace_agriculteur);
}

//*********************************************************************************
//*******************************************************************************************************************************************************************
void

on_button38_clicked                    (GtkButton       *button,

                                        gpointer         user_data)

{
        GtkWidget *treeview3 ;	
	treeview3=lookup_widget(button,"treeview3");
	afficher_dossier(treeview3);

}





void

on_button39_clicked                    (GtkButton       *button,

                                        gpointer         user_data)

{

        GtkWidget *dossier0;
	GtkWidget *dossier3;
	dossier3= lookup_widget(button,"dossier3");
	gtk_widget_destroy(dossier3);
	dossier0=create_dossier0();
	gtk_widget_show(dossier0);

}



//*******************************************************************************************************************************************************************

void

on_button40_clicked                    (GtkButton       *button,

                                        gpointer         user_data)

{
        GtkWidget *input;
	GtkWidget *output;
	GtkWidget *dossier4;
	dossier4=create_dossier4();
	char num[10];
	char message[50];
	int x;
	input= lookup_widget(button,"entry25");
	output=lookup_widget(button,"label79");
	strcpy(num,gtk_entry_get_text(GTK_ENTRY(input)));
        x=verifier_dossier(num);
	if (x==1)

	{
	 	supprimer_dossier(num);
		strcpy(message,"suppression a été  effectuée");
	}

	else 

	{
		strcpy(message,"plante introuvable ");
	}
	gtk_label_set_text(GTK_LABEL(output),message);
}





void

on_button41_clicked                    (GtkButton       *button,

                                        gpointer         user_data)

{
	GtkWidget *dossier0;
	GtkWidget *dossier4;
	dossier4= lookup_widget(button,"dossier4");
	gtk_widget_hide(dossier4);
	dossier0=create_dossier0();
	gtk_widget_show(dossier0);

}
//*******************************************************************************************************************************************************************

void
on_button42_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        
}




void
on_button43_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_agriculteur;
	GtkWidget *repiquage;
	repiquage=lookup_widget(button,"repiquage");
	espace_agriculteur=lookup_widget(button,"espace_agriculteur");
	gtk_widget_hide(repiquage);
	espace_agriculteur=create_espace_agriculteur();
	gtk_widget_show(espace_agriculteur);

	
	
}


void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button45_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button46_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	
}

void
on_button47_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button48_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button49_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button50_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button51_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *treeview5;
        GtkWidget *messages;	
	treeview5=lookup_widget(button,"treeview5");
	afficher_messageadmin(treeview5);
 
}


void
on_button52_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_agriculteur;
	GtkWidget *messages;
	messages=lookup_widget(button,"messages");
	gtk_widget_destroy(messages);
	espace_agriculteur=lookup_widget(messages,"espace_agriculteur");
	espace_agriculteur=create_espace_agriculteur();
	gtk_widget_show(espace_agriculteur);
}


void
on_button53_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{  
	GtkWidget *treeview6;	
	treeview6=lookup_widget(button,"treeview6");
	afficher_notification(treeview6);
}


void
on_button54_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{	
	GtkWidget *espace_agriculteur;
	GtkWidget *notifications;
	notifications=lookup_widget(button,"notifications");
	gtk_widget_destroy(notifications);
	espace_agriculteur=lookup_widget(notifications,"espace_agriculteur");
	espace_agriculteur=create_espace_agriculteur();
	gtk_widget_show(espace_agriculteur);

}


void
on_button55_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *messages1;
  	GtkWidget *messagesadmin;
	messages1= lookup_widget(button,"messages1");
	gtk_widget_hide(messages1);
	messagesadmin=create_messagesadmin();
	gtk_widget_show(messagesadmin); 
}


void
on_button56_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *messages;
	GtkWidget *messages1;
	messages1=lookup_widget(button,"messages1");
	gtk_widget_destroy(messages1);
	messages=lookup_widget(messages1,"messages");
	messages=create_messages();
	gtk_widget_show(messages);
}


void
on_button57_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{   
                GtkWidget *input1, *input2,*input3;
        GtkWidget *output;
        message1 s;
        input1=lookup_widget(button,"entry30");
        input2=lookup_widget(button,"entry31");
        input3=lookup_widget(button,"entry32");
        output=lookup_widget(button,"label104");
     
  strcpy(s.Date1,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(s.envoyeur1,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(s.message1,gtk_entry_get_text(GTK_ENTRY(input3)));
 

        if ((strlen(s.Date1)==0)||(strlen(s.envoyeur1)==0)||(strlen(s.message1)==0))
{
       gtk_label_set_text(GTK_LABEL(output),"veuilez remplir toutes les cases");
}
else
{
    ajoutermessage1(s);
    gtk_label_set_text(GTK_LABEL(output),"Message envoyé !");
}
}




void
on_button58_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *messages;
	GtkWidget *messagesadmin;
	messagesadmin=lookup_widget(button,"messagesadmin");
	gtk_widget_destroy(messagesadmin);
	messages=lookup_widget(messagesadmin,"messages");
	messages=create_messages();
	gtk_widget_show(messages);
}





void
on_button61_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *espace_admin2;
	GtkWidget *cont;
	espace_admin2= lookup_widget(button,"espace_admin2");
	gtk_widget_hide(espace_admin2);
	cont=create_cont();
	gtk_widget_show(cont);
}


void
on_button64_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *espace_admin2;
	GtkWidget *cont;
	cont= lookup_widget(button,"cont");
	gtk_widget_hide(cont);
	espace_admin2=create_espace_admin2();
	gtk_widget_show(espace_admin2);
}


void
on_button62_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
   
        GtkWidget *treeview7;	
        GtkWidget *cont;
	treeview7=lookup_widget(button,"treeview7");
	afficher_messageagriculteur(treeview7);
}


void
on_button63_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *cont;
	GtkWidget *messages2;
	cont=lookup_widget(button,"cont");
	messages2=lookup_widget(button,"messages2");
	gtk_widget_destroy(cont);
	messages2=create_messages2();
	gtk_widget_show(messages2);
}


void
on_button66_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *cont;
	GtkWidget *messages2;
	messages2=lookup_widget(button,"messages2");
	gtk_widget_destroy(messages2);
	cont=lookup_widget(messages2,"cont");
	cont=create_cont();
	gtk_widget_show(cont);
}


void
on_button65_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *messages2;
  	GtkWidget *messagesagriculteur;
	messages2= lookup_widget(button,"messages2");
	gtk_widget_hide(messages2);
	messagesagriculteur=create_messagesagriculteur();
	gtk_widget_show(messagesagriculteur); 
}


void
on_button68_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
   
        GtkWidget *cont;
	GtkWidget *messagesagriculteur;
	messagesagriculteur=lookup_widget(button,"messagesagriculteur");
	gtk_widget_destroy(messagesagriculteur);
	cont=lookup_widget(messagesagriculteur,"cont");
	cont=create_cont();
	gtk_widget_show(cont);
}


void
on_button67_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *input1, *input2,*input3;
        GtkWidget *output;
        message m;
        input1=lookup_widget(button,"entry35");
        input2=lookup_widget(button,"entry36");
        input3=lookup_widget(button,"entry37");
        output=lookup_widget(button,"label123");
       
  strcpy(m.Date,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(m.envoyeur,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(m.message,gtk_entry_get_text(GTK_ENTRY(input3)));


        if ((strlen(m.Date)==0)||(strlen(m.envoyeur)==0)||(strlen(m.message)==0))
{
       gtk_label_set_text(GTK_LABEL(output),"veuilez remplir toutes les cases");
}
else
{
   ajoutermessage(m);
    gtk_label_set_text(GTK_LABEL(output),"Message envoyé !");
}

}


void
on_button69_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{  
        GtkWidget *messages;
	GtkWidget *messages1;
	messages=lookup_widget(button,"messages");
	messages1=lookup_widget(button,"messages1");
	gtk_widget_destroy(messages);
	messages1=create_messages1();
	gtk_widget_show(messages1);
}


void
on_button70_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *espace_admin2,*emplois1;
    emplois1=lookup_widget(button,"emplois1");
    emplois1 = create_emplois1();
    gtk_widget_show (emplois1);
    espace_admin2=lookup_widget(button,"espace_admin2");
    gtk_widget_hide(espace_admin2);
}


void
on_button71_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{     
        
}
        


void
on_button72_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  
}


void
on_button73_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *ajouterrepiquage;
    GtkWidget *repiquage;
    ajouterrepiquage=create_ajouterrepiquage ();
    gtk_widget_show (ajouterrepiquage);
    repiquage=lookup_widget(button,"repiquage");
    gtk_widget_destroy (repiquage);
}


void
on_button75_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *afficherrepiquage;
        GtkWidget *repiquage;
        afficherrepiquage=create_afficherrepiquage ();
        gtk_widget_show (afficherrepiquage);
        repiquage=lookup_widget(button,"repiquage");
        gtk_widget_hide (repiquage);
}


void
on_button74_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *supprimerrepiquage;
       GtkWidget *repiquage;
       supprimerrepiquage=create_supprimerrepiquage ();
       gtk_widget_show (supprimerrepiquage);
       repiquage=lookup_widget(button,"repiquage");
       gtk_widget_hide (repiquage);
}


void
on_button76_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
                 GtkWidget *input1, *input2 , *input3, *input4, *input5;
                 GtkWidget *output;
                 rep r;
                 input1=lookup_widget(button,"entry45");
                 input2=lookup_widget(button,"entry46");
                 input3=lookup_widget(button,"entry47");
                 input4=lookup_widget(button,"entry48");
input5=lookup_widget(button,"entry49");
output=lookup_widget(button,"label150");
strcpy(r.code,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(r.type,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(r.date,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(r.heure,gtk_entry_get_text(GTK_ENTRY(input5)));
if ((strlen(r.nom)==0)||(strlen(r.type)==0)||(strlen(r.date)==0)||(strlen(r.heure)==0) ||(strlen(r.code)==0))
{
  gtk_label_set_text(GTK_LABEL(output),"veuilez remplir toutes les cases");
}
else
{
    ajouterr(r);
    gtk_label_set_text(GTK_LABEL(output),"Ajout du repiquage avec succés");
}
}


void
on_button77_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *ajouterrepiquage;
 GtkWidget *repiquage;
repiquage=create_repiquage ();
gtk_widget_show (repiquage);
ajouterrepiquage=lookup_widget(button,"ajouterrepiquage");
gtk_widget_destroy (ajouterrepiquage);
}


void
on_button78_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *input1;
    GtkWidget *output;
   char code1[20];
   input1=lookup_widget(button,"entry50");
   strcpy(code1,gtk_entry_get_text(GTK_ENTRY(input1)));
   output=lookup_widget(button,"label152");
   if ((strlen(code1)==0))
   {
   gtk_label_set_text(GTK_LABEL(output),"veuilez remplir la case");
   }
   else
   {
   supprimerr(code1);
   gtk_label_set_text(GTK_LABEL(output),"Repiquage supprimé"); 
   }
}


void
on_button79_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *supprimerrepiquage;
 GtkWidget *repiquage;
repiquage=create_repiquage ();
gtk_widget_show (repiquage);
supprimerrepiquage=lookup_widget(button,"supprimerrepiquage");
gtk_widget_destroy (supprimerrepiquage);
}


void
on_button81_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *afficherrepiquage;
     GtkWidget *repiquage;
     repiquage=create_repiquage ();
     gtk_widget_show (repiquage);
     afficherrepiquage=lookup_widget(button,"afficherrepiquage");
     gtk_widget_destroy (afficherrepiquage);
}


void
on_button80_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *treeview8;
        GtkWidget *afficherrepiquage;
        treeview8=lookup_widget(button,"treeview8");
        afficherr(treeview8);
}


void
on_button82_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *espace_admin2;
	GtkWidget *repiquage0;
	espace_admin2=lookup_widget(button,"espace_admin2");
	gtk_widget_destroy(espace_admin2);
	repiquage0=create_repiquage0();
	gtk_widget_hide(espace_admin2);
	gtk_widget_show(repiquage0);
}


void
on_button84_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *espace_admin2;
	GtkWidget *repiquage0;
	repiquage0= lookup_widget(button,"repiquage0");
	gtk_widget_hide(repiquage0);
	espace_admin2=create_espace_admin2();
	gtk_widget_show(espace_admin2);

}


void
on_button83_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *treeview9;	
	GtkWidget *repiquage0;
	treeview9=lookup_widget(button,"treeview9");
	afficher_repiquage(treeview9);

}


void
on_button95_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *espace_admin2;
  GtkWidget *agenda;
  espace_admin2 = lookup_widget(button,"espace_admin2");
  agenda = create_agenda();

  GtkWidget *treeview10;
  treeview10 = lookup_widget(agenda,"treeview10");
  reun_show(treeview10);
  reun_widget_hide_all(agenda);
  gtk_widget_show(agenda);
  gtk_widget_destroy(espace_admin2);
}


void
on_button86_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *espace_admin2;
  GtkWidget *agenda;

  agenda = lookup_widget(button,"agenda");
  espace_admin2 = create_espace_admin2();

  gtk_widget_destroy(agenda);
  gtk_widget_show(espace_admin2);
}


void
on_button88_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *agenda;
  GtkWidget *treeview10;
  agenda = lookup_widget(button,"agenda");
  treeview10 = lookup_widget(agenda,"treeview10");
  reun_show(treeview10);
}


void
on_button87_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *agenda;
 
  agenda = lookup_widget(button,"agenda");
  

   set_mode(agenda, 1);
  reun_widget_hide_all(agenda);
  reun_widget_add_show(agenda);
}


void
on_button89_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *agenda;
  
  agenda = lookup_widget(button,"agenda");
  

  set_mode(agenda, 2);
  reun_widget_hide_all(agenda);
  reun_widget_edit_show(agenda);
}


void
on_button90_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *agenda;
 agenda = lookup_widget(button,"agenda");

 set_mode(agenda, 3);
 reun_widget_hide_all(agenda);
 reun_widget_delete_show(agenda);
}


void
on_button93_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *entry;
  GtkWidget *treeview;
  entry = lookup_widget(button,"entry52");
  char input_id[5];
  strcpy(input_id,gtk_entry_get_text(GTK_ENTRY(entry)));
  reun_delete(input_id);
  treeview = lookup_widget(button,"treeview10");

  GtkWidget *dialog;
  dialog = create_dialog_admin_add_reun();
  GtkWidget *label;
  label = lookup_widget(dialog,"label170");
  gtk_label_set_text(GTK_LABEL(label),"Succès de la suppression de la réunion séléctionné !");
  gtk_widget_show(dialog);
  reun_show(treeview);
}


void
on_button92_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *label;
  GtkWidget *entry;
  GtkWidget *treeview;
  GtkWidget *dialog;

  entry = lookup_widget(button,"entry52");

  treeview = lookup_widget(button,"treeview10");

  reun_update(button);

  dialog = create_dialog_admin_add_reun();
  label = lookup_widget(dialog,"label170");
  gtk_label_set_text(GTK_LABEL(label),"Succès de la modification de la réunion séléctionné !");
  gtk_widget_show(dialog);

  reun_show(treeview);
}


void
on_button91_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    int success;
  char msg[60];
  success = reun_add(button);
  if(success == 0)
    strcpy(msg,"Succès de la création de la réunion !");
  else if (success == -1)
    strcpy(msg,"Erreur : Veuillez entrer une ID présente dans la liste !");
  else
    strcpy(msg,"INTERNAL ERROR : please try again");

  GtkWidget *dialog_admin_add_reun;
  GtkWidget *agenda;
  GtkWidget *treeview10;
  GtkWidget *label170;
  dialog_admin_add_reun =create_dialog_admin_add_reun();
  label170 = lookup_widget(dialog_admin_add_reun,"label170");
  gtk_label_set_text(GTK_LABEL(label170),msg);
  gtk_widget_show(dialog_admin_add_reun);
  agenda = lookup_widget(button,"agenda");
  treeview10 = lookup_widget(button,"treeview10");
  reun_show(treeview10);
}


void
on_button94_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *agenda;
  agenda = lookup_widget(button,"agenda");
  reun_widget_hide_all(agenda);
}


void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *dialog_admin_add_reun;
    dialog_admin_add_reun = lookup_widget(button,"dialog_admin_add_reun");
    gtk_widget_destroy(dialog_admin_add_reun);
}


void
on_button96_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
     
        GtkWidget *espace_agriculteur;
	GtkWidget *reunionagr;
	espace_agriculteur=lookup_widget(button,"espace_agriculteur");
	gtk_widget_destroy(espace_agriculteur);
	reunionagr=create_reunionagr();
	gtk_widget_hide(espace_agriculteur);
	gtk_widget_show(reunionagr);
}


void
on_button98_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *treeview11;	
	GtkWidget *reunionagr;
	treeview11=lookup_widget(button,"treeview11");
	afficher_reunion(treeview11);
}


void
on_button97_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *espace_agriculteur;
	GtkWidget *reunionagr;
	reunionagr= lookup_widget(button,"reunionagr");
	gtk_widget_hide(reunionagr);
	espace_agriculteur=create_espace_agriculteur();
	gtk_widget_show(espace_agriculteur);
}


void
on_menuitemagenda_activate             (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{       
       GtkWidget *emplois1;
       GtkWidget *agendawindow;
      // emplois1= lookup_widget(button,"emplois1");
       //gtk_widget_destroy(emplois1);
      agendawindow = create_agendawindow();
       
        gtk_widget_show(agendawindow);
          GtkWidget *calendar=lookup_widget(agendawindow,"calendar1");
        //save_emplois(calendar);
}


void
on_menuitemTravail_activate            (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{    

}

void
on_calendar1_day_selected_double_click (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
   /*GtkWidget *output;
      GtkWidget *agendawindow;                        
      GtkWidget *calendar1=lookup_widget(agendawindow,"calendar1");
     guint day ;
     guint month ;
     guint year ;                                
gtk_calendar_get_date(calendar,
			 &year, &month, &day);
       gchar *daydisplay;
       gchar *yeardisplay;
       gchar *monthdisplay;
daydisplay = g_strdup_printf("%d", day);  
    monthdisplay = g_strdup_printf("%d", month);  
    yeardisplay = g_strdup_printf("%d", year);  
    output=lookup_widget(calendar,"selecteddate");
     ddat in ; 
    //in.id= 1244;
    strcpy(in.annee,yeardisplay);
    strcpy(in.mois,monthdisplay);
    strcpy(in.jour,daydisplay);
	
  
if ((strlen(in.annee)==0)||(strlen(in.mois)==0)||(strlen(in.jour)==0))
{
    gtk_label_set_text(GTK_LABEL(output),"vous avez déja ajouté cet emplois");
}
else
{ 
  save_emplois(calendar,in);
  gtk_label_set_text(GTK_LABEL(output),"emplois ajouté avec succée");
}

*/
}


void
on_button99_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{     GtkWidget *output;                     
      GtkWidget *calendar=lookup_widget(button,"calendar1");
      ddat in ; 
	GtkWidget *spinbutton8Calendrier=lookup_widget(button,"spinbutton8Calendrier");
	GtkWidget *spinbutton9Calendrier=lookup_widget(button,"spinbutton9Calendrier");
     int jour,mois,annee,heure,minute ;                        
gtk_calendar_get_date(calendar,
			 &annee, &mois, &jour);
    heure=gtk_spin_button_get_value_as_int(spinbutton8Calendrier);
    minute=gtk_spin_button_get_value_as_int(spinbutton9Calendrier);
    sprintf(in.heure,"%d",heure);
    sprintf(in.minute,"%d",minute);
    output=lookup_widget(button,"selecteddate");
     
	mois ++ ;
    sprintf(in.annee,"%d",annee);
    sprintf(in.mois,"%d",mois);
    sprintf(in.jour,"%d",jour);

	
  
if ((strlen(in.annee)==0)||(strlen(in.mois)==0)||(strlen(in.jour)==0))
{
    gtk_label_set_text(GTK_LABEL(output),"vous avez déja ajouté cet emplois");
}
else
{ 
  save_emplois(in);
  gtk_label_set_text(GTK_LABEL(output),"emplois ajouté avec succée");
}

}



void
on_button101_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
       
    GtkWidget *treeview12;
   GtkWidget *emplois1;
   treeview12=lookup_widget(button,"treeview12");
   affiche_travail (treeview12);
}


void
on_button102_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *espace_admin2;
	GtkWidget *emplois1;
	emplois1= lookup_widget(button,"emplois1");
	gtk_widget_hide(emplois1);
	espace_admin2=create_espace_admin2();
	gtk_widget_show(espace_admin2);

}


void
on_button100_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *emplois1;
	GtkWidget *agendawindow;
	agendawindow= lookup_widget(button,"agendawindow");
	gtk_widget_hide(agendawindow);
	emplois1=create_emplois1();
	gtk_widget_show(emplois1);
}


void
on_button13defectueux_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *marque_capteur_def ,*treeview ;
int m ; 
	marque_capteur_def=lookup_widget(button,"marque_capteur_def");
	marque_capteur_def=create_marque_capteur_def();
	gtk_widget_show(marque_capteur_def);
treeview=lookup_widget(marque_capteur_def,"treeviewcaptdef");

defaillance() ;
m=max(); 
afficherCapt(treeview,m) ; 
}


void
on_retour20_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Afficher_client, *espace_admin;
	Afficher_client=lookup_widget(button,"Afficher_client");
	gtk_widget_destroy(Afficher_client);
	espace_admin=create_espace_admin();
	gtk_widget_show(espace_admin);
}


void
on_button103retourEquipement_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Les_equipements_admin, *espace_admin;
	Les_equipements_admin=lookup_widget(button,"Les_equipements_admin");
	gtk_widget_destroy(Les_equipements_admin);
	espace_admin=create_espace_admin();
	gtk_widget_show(espace_admin);
}


void
on_button106ActualiserEquipement_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview1;
	treeview1=lookup_widget(button,"treeview13Equipement");
	afficher_equipement(treeview1,"","");
}


void
on_button104DeconnecteEquipement_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Les_equipements_admin, *Page_Accueil;
	Les_equipements_admin=lookup_widget(button,"Les_equipements_admin");
	gtk_widget_destroy(Les_equipements_admin);
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
}


void
on_button104RetourCapteur_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *afficher_capteur, *espace_ouvrier;
	afficher_capteur=lookup_widget(button,"afficher_capteur");
	gtk_widget_destroy(afficher_capteur);
	espace_ouvrier=create_espace_ouvrier();
	gtk_widget_show(espace_ouvrier);
}


void
on_button103DeconnecterCapteur_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *afficher_capteur, *Page_Accueil;
	afficher_capteur=lookup_widget(button,"afficher_capteur");
	gtk_widget_destroy(afficher_capteur);
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
}


void
on_buttonRetourTroupeau_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espace_ouvrier, *GestionTroupeaux;
	Espace_ouvrier=lookup_widget(button,"Espace_ouvrier");
	gtk_widget_destroy(Espace_ouvrier);
	GestionTroupeaux=create_GestionTroupeaux();
	gtk_widget_show(GestionTroupeaux);
}


void
on_button107DeconnecteTroupeau_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espace_ouvrier, *Page_Accueil;
	Espace_ouvrier=lookup_widget(button,"Espace_ouvrier");
	gtk_widget_destroy(Espace_ouvrier);
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
}


void
on_button106RetourEquipement_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionEquipements, *espace_ouvrier;
	GestionEquipements=lookup_widget(button,"GestionEquipements");
	gtk_widget_destroy(GestionEquipements);
	espace_ouvrier=create_espace_ouvrier();
	gtk_widget_show(espace_ouvrier);
}


void
on_button105DeconnecteEquipement_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionEquipements, *Page_Accueil;
	GestionEquipements=lookup_widget(button,"GestionEquipements");
	gtk_widget_destroy(GestionEquipements);
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
}


void
on_button108DeconnecterOuvrier_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionOuvriers, *Page_Accueil;
	GestionOuvriers=lookup_widget(button,"GestionOuvriers");
	gtk_widget_destroy(GestionOuvriers);
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
}


void
on_button111RetourAgriculture_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *espace_agriculteur, *espace_ouvrier;
	espace_agriculteur=lookup_widget(button,"espace_agriculteur");
	gtk_widget_destroy(espace_agriculteur);
	espace_ouvrier=create_espace_ouvrier();
	gtk_widget_show(espace_ouvrier);
}


void
on_button110DeconnecterAgriculture_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *espace_agriculteur, *Page_Accueil;
	espace_agriculteur=lookup_widget(button,"espace_agriculteur");
	gtk_widget_destroy(espace_agriculteur);
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
}


void
on_button103DeconnecterTroupeaux_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionTroupeaux, *Page_Accueil;
	GestionTroupeaux=lookup_widget(button,"GestionTroupeaux");
	gtk_widget_destroy(GestionTroupeaux);
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
}


void
on_button105DeconnecterCapteur_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *affichage_admin, *Page_Accueil;
	affichage_admin=lookup_widget(button,"affichage_admin");
	gtk_widget_destroy(affichage_admin);
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
}


void
on_button104Retour2Capteur_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *affichage_admin, *espace_admin;
	affichage_admin=lookup_widget(button,"affichage_admin");
	gtk_widget_destroy(affichage_admin);
	espace_admin=create_espace_admin();
	gtk_widget_show(espace_admin);
}


void
on_button106RetourCalendrier_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *espace_admin2, *espace_admin;
	espace_admin2=lookup_widget(button,"espace_admin2");
	gtk_widget_destroy(espace_admin2);
	espace_admin=create_espace_admin();
	gtk_widget_show(espace_admin);
}


void
on_button107DeconnecterCalendrier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *espace_admin2, *Page_Accueil;
	espace_admin2=lookup_widget(button,"espace_admin2");
	gtk_widget_destroy(espace_admin2);
	Page_Accueil=create_Page_Accueil();
	gtk_widget_show(Page_Accueil);
}


void
on_combo_entry5_changed                (GtkEditable     *editable,
                                        gpointer         user_data)
{

}



