
#include "callbacks.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "absenteisme.h"
#include "ouvrier.h"
#include <gtk/gtk.h>

enum
{  
	CIN,
	JOUR,
	MOIS,
	ANNEE,
	ABS,
	COLUMNS,
};

///////enregistrer absence////////

void enregristrer_absence(pointage p)
{
  FILE *f=NULL;
f=fopen("absences.txt","a+");
fprintf(f,"%s %d %d %d %d\n",p.cin,p.date.jour,p.date.mois,p.date.annee,p.present);
fclose(f);
}


/*********************************************************************************************************************************************/

///////afficher absence//////

 void afficher_absence(GtkWidget *liste)
{
	g_print("1");
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
char cin[20];

int jour,mois,annee,present;
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin",renderer, "text",CIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour absence",renderer, "text",JOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois absence",renderer, "text",MOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee absence",renderer, "text",ANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("presence",renderer, "text",ABS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	


}
	store=gtk_list_store_new(5,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
f = fopen("absences.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("absences.txt","a+");
	while(fscanf(f,"%s %d %d %d %d\n",cin,&jour,&mois,&annee,&present)!=EOF)
	{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,CIN,cin,JOUR,jour,MOIS,mois,ANNEE,annee,ABS,present,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
}
	
}
///////////supprimer absence//////////
void supprimer_absence(pointage p)
{
pointage p2;
FILE *f, *g ;
	f=fopen("absences.txt","r");
	g=fopen("tmpsupp.txt","w");
	if(f==NULL || g==NULL)
	return;
        else
{
	while(fscanf(f,"%s %d %d %d %d \n",p2.cin,&p2.date.jour,&p2.date.mois,&p2.date.annee,&p2.present)!=EOF)
{
	if(strcmp(p.cin,p2.cin)!=0|| p.date.jour!=p2.date.jour || p.date.mois!=p2.date.mois || p.date.annee!=p2.date.annee || p.present!=p2.present)
fprintf(g,"%s %d %d %d %d \n",p2.cin,p2.date.jour,p2.date.mois,p2.date.annee,p2.present);
}
fclose(f);
fclose(g);
remove("absences.txt");
rename("tmpsupp.txt","absences.txt");
}}

/******exist ouvrier****/
/*

int exist_ouvrier(char*cin){
infoouvrier o;
FILE*f=NULL;
f=fopen("ouvriers.txt","r");
while(fscanf(f,"%s %s %s %d %d %d %s %s %d\n",o.cin,o.nom,o.prenom,&o.naissance.jour,&o.naissance.mois,&o.naissance.annee,o.adr,o.numtel,&o.nbre_abs)!=EOF){
if(strcmp(o.cin,cin)==0)return 1;//cin existe
}
fclose(f);  
return 0;}*/
int exist_abs(char*cin)
{
infoouvrier o;
FILE*f=NULL;
f=fopen("ouvriers.txt","r");
while(fscanf(f,"%s %s %s %d %d %d %s %s %d\n",o.cin,o.nom,o.prenom,&o.naissance.jour,&o.naissance.mois,&o.naissance.annee,o.adr,o.numtel,&o.nbre_abs)!=EOF){
if(strcmp(o.cin,cin)==0)return 1;//cin existe
}
fclose(f);  
return 0;
}

