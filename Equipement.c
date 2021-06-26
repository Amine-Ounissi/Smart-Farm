#include "callbacks.h"
#include "Equipement.h"
#include <string.h>

enum
{

ENOM,
ESERIE,
EMADE,
EDATE,
EUTILISER,
EETAT,
COLUMNS_EQUI,
};


void ajouter_equipement(Equipement e);
void modifier_equipement(Equipement e,char date[20],char serie1[20]);
void supprimer_equipement(char a[20],char raison[20]);

void ajouter_equipement(Equipement e)
{
    FILE* f;
    char nom[30],etat[30],made[30],date[20],date2[20],serie[20],jour[2],mois[20],annee[10];
    sprintf(date,"%s/%s/%s",e.date_achat.jour,e.date_achat.mois,e.date_achat.annee);
    f=fopen("equipement.txt","a+");
    if (f!=NULL)
    {
    	fprintf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat);
    }   
    fclose(f);
}

void modifier_equipement(Equipement e,char date2[20],char serie2[20])
{
	FILE *f,*f2;
	f=fopen("equipement.txt","r");
	f2=fopen("tmp.txt","a+");
	char nom[20],serie[20],made[20],date[20],utiliser[20],etat[20];
	while (fscanf(f,"%s %s %s %s %s %s\n",nom,serie,made,date,utiliser,etat)!=EOF){
		if (strcmp(e.serie,serie)==0)
			fprintf(f2,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date2,utiliser,e.etat);
		else fprintf(f2,"%s %s %s %s %s %s\n",nom,serie,made,date,utiliser,etat);
		}
	fclose(f);
	fclose(f2);
	remove("equipement.txt");
	rename("tmp.txt","equipement.txt");
}

void supprimer_equipement(char a[20],char raison[20])
{
    FILE* f ;
    FILE* f2;
    FILE* f3;
    char date[20],date2[60];
    f=fopen("equipement.txt","r+");
    f2=fopen("tmp.txt","a+");
    f3=fopen("corbeille_equipement.txt","a+");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date2,"%d/%d/%d-%d:%d:%d",(tm.tm_year+1900),tm.tm_mon,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec);
    while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat)!=EOF)
    {
         if (strcmp(a,e.serie)!=0)
              fprintf(f2,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat);
	 else fprintf(f3,"%s %s %s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat,raison,date2);
    }
    fclose(f);fclose(f2);fclose(f3);
    remove("equipement.txt");
    rename("tmp.txt","equipement.txt");
}
void afficher_equipement(GtkWidget *liste,char serie_rech[20],char tirer_par[20])
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
	int age;
	FILE* f,*f1;
    char nom[30],etat[30],made[30],date[20],serie[20],jour[10],mois[20],annee[20],date2[20];
    store=NULL;
    store=gtk_tree_view_get_model(liste);
if (store==NULL){
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("	Nom	",renderer,"text",ENOM, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("		Serie		",renderer,"text",ESERIE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("	Made in	  ",renderer,"text",EMADE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("		Date achat		",renderer,"text",EDATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("		Utiliser dans		",renderer,"text",EUTILISER,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("	Etat	",renderer,"text",EETAT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    store=gtk_list_store_new(COLUMNS_EQUI,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("equipement.txt","r");    
	if (f!=NULL)
	goto loop;
}

else{	
loop:
store=gtk_list_store_new(COLUMNS_EQUI,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

if (strcmp(tirer_par,"1")==0){
	f=fopen("recherche avance.txt","r");
		    if (f==NULL)
		    {
			return;
		    }
		    else
		    {
			while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat)!=EOF)
			{
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ENOM, e.nom ,ESERIE,e.serie,EMADE,e.made,EDATE,date,EUTILISER,e.utiliser,EETAT,e.etat,-1);
			}
		    }
		    fclose(f);
		    remove("recherche avance.txt");
		    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		    g_object_unref(store);
}
else if (strcmp(tirer_par,"")==0){
		TirerParEqui("Nom");
		    f=fopen("Nom.txt","r");
		    if (f==NULL)
		    {
			return;
		    }
		    else
		    {	
			while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat)!=EOF)
			{
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ENOM, e.nom ,ESERIE,e.serie,EMADE,e.made,EDATE,date,EUTILISER,e.utiliser,EETAT,e.etat,-1);
			}
		    }
		    fclose(f);
		
		    remove(tirer_par);
		    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		    g_object_unref(store);
}
else if (strcmp(serie_rech,"")==0){
		    TirerParEqui(tirer_par);
		    strcat(tirer_par,".txt");
		    f=fopen(tirer_par,"r");
		    if (f==NULL)
		    {
			return;
		    }
		    else
		    {	
			while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat)!=EOF)
			{
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ENOM, e.nom ,ESERIE,e.serie,EMADE,e.made,EDATE,date,EUTILISER,e.utiliser,EETAT,e.etat,-1);
			}
		    }
		    fclose(f);
		
		    remove(tirer_par);
		    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		    g_object_unref(store);}
    else {
		   
	  	    f=fopen("equipement.txt","r");
	 	    if (f==NULL)
	 	    {
		 	return;
		     }
	  	    else
		    {
			while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat)!=EOF)
			{
				if (strcmp(e.serie,serie_rech)==0){
					
					gtk_list_store_append(store,&iter);
					gtk_list_store_set(store,&iter,ENOM, e.nom ,ESERIE,e.serie,EMADE,e.made,EDATE,date,EUTILISER,e.utiliser,EETAT,e.etat,-1);}
			}
		    }
		    fclose(f);
		    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		    g_object_unref(store);
}}}
