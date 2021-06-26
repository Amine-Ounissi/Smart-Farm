#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "emplois.h"


void save_emplois(ddat in)
{
		ddat o,x;
	FILE *f,*f1,*f2;
	int test=-1;
	int found=-1;
	
	f=fopen("emplois.txt","a+");
	if (f!=NULL)
	{
	while (fscanf(f," %s %s %s \n",o.jour,o.mois,o.annee) != EOF)
		{
			if((strcmp(in.jour,o.jour)==0)&&(strcmp(in.mois,o.mois)==0)&&(strcmp(in.annee,o.annee)==0))
                        {     
				found=1;
			}
		}
		if(found!=1){   
				fprintf(f,"%s %s %s %sh%s\n",in.jour,in.mois,in.annee,in.heure,in.minute);
				fclose(f);
				return(1);
		}
		return (0);
}
}

enum
{
	JOUR1,
	MOIS1,
	ANNEE1,
	HEURE1,	
        COLUMNS1
};

enum
{
	JOUR,
	MOIS,
	ANNEE,
	HEURE,	
        COLUMNS
};



void affiche_travail(GtkWidget *treeview12)
{
ddat d;

GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


store=NULL;

FILE *f;
FILE *f1;



store = gtk_tree_view_get_model(treeview12);

	if(store==NULL)
	{
		
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Heure",renderer,"text",HEURE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12),column);
	
	}
	char heure[10];
store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	f=fopen("emplois.txt","r");
	
	if(f!=NULL)
	{
 		

              while((fscanf(f,"%s %s %s %s\n",d.jour,d.mois,d.annee,heure)!=EOF))
		{
			
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,JOUR,d.jour,MOIS,d.mois,ANNEE,d.annee,HEURE,heure,-1);
		}
		
		fclose(f);
        }
		gtk_tree_view_set_model (GTK_TREE_VIEW (treeview12),  GTK_TREE_MODEL (store));
    		g_object_unref (store);		
}
	



void affiche_emplois(GtkWidget *treeview2)
{
ddat d;

GtkListStore *store;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;


store=NULL;

FILE *f;
FILE *f1;



store = gtk_tree_view_get_model(treeview2);

	if(store==NULL)
	{
		
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR1,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS1,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE1,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Heure",renderer,"text",HEURE1,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview2),column);
	
	}
	char heure[10];
store = gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	
	f=fopen("emplois.txt","r");
	
	if(f!=NULL)
	{
 		

              while((fscanf(f,"%s %s %s %s\n",d.jour,d.mois,d.annee,heure)!=EOF))
		{
			
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,JOUR1,d.jour,MOIS1,d.mois,ANNEE1,d.annee,HEURE1,heure,-1);
		}
		
		fclose(f);
        }
		gtk_tree_view_set_model (GTK_TREE_VIEW (treeview2),  GTK_TREE_MODEL (store));
    		g_object_unref (store);		
}
	






