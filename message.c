# include "message.h"
#include <gtk/gtk.h>

void afficher_messageadmin(GtkWidget *treeview5)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter   iter;
	GtkListStore *store;
	char date[30],envoyeur[30],message[30];
	FILE *f; 
	store=NULL ;

	store=gtk_tree_view_get_model(treeview5);	
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Datee", renderer,"text",Datee2, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview5), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Envoyeur", renderer,"text",Envoyeur,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview5), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Message",renderer,"text",Message, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview5), column);					
	
	}
		store=gtk_list_store_new (COLUMN44, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


	f = fopen("messageadmin.txt","r");
	if(f ==NULL)
	{

		return;
	}		
	else
	{
		while(fscanf(f,"%s %s %s\n",date,envoyeur,message)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,Datee2,date,Envoyeur,envoyeur,Message,message,-1);
		}
		
		fclose(f);
	}
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview5), GTK_TREE_MODEL (store));
	
	g_object_unref (store);
	
}


void afficher_messageagriculteur(GtkWidget *treeview7)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter   iter;
	GtkListStore *store;
	char date1[30],envoyeur1[30],message1[30];
	FILE *f; 
	store=NULL ;

	store=gtk_tree_view_get_model(treeview7);	
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date2", renderer,"text",Date4, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview7), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Envoyeur1", renderer,"text",Envoyeur1,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview7), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Message1",renderer,"text",Message1, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview7), column);
						
			
	}
		store=gtk_list_store_new (COLUMN45, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


	f = fopen("messageagriculteur.txt","r");
	if(f ==NULL)
	{

		return;
	}		
	else
	{
		while(fscanf(f,"%s %s %s\n",date1,envoyeur1,message1)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,Date4,date1,Envoyeur1,envoyeur1,Message1,message1,-1);
		}
		
		fclose(f);
	}
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview7), GTK_TREE_MODEL (store));
	
	g_object_unref (store);
	
}




