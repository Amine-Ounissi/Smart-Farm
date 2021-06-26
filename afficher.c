#include "afficher.h"
#include <gtk/gtk.h>

void afficher_notification(GtkWidget *treeview6)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter   iter;
	GtkListStore *store;
	char id[20];
	int valeur;
	/*char jour1[20];
	char mois1[20];
	char annee1[20];
	char valeur[20];*/
	
	
	
	FILE *f; 
	store=NULL ;	
	store=gtk_tree_view_get_model(GTK_TREE_VIEW(treeview6));	
	if (store==NULL)
{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Serie", renderer,"text",Id, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview6), column);	
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Valeur", renderer,"text",Valeur,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview6), column);


	store=gtk_list_store_new (COLUMN10, G_TYPE_STRING,G_TYPE_INT);
	
	
	f = fopen("valeur capteur.txt","r");
	
	if(f !=NULL)
{

	while(fscanf(f,"%s %d\n",id,&valeur)!=EOF)
{			
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,Id,id,Valeur,valeur,-1);
}
		
		fclose(f);
}
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview6), GTK_TREE_MODEL (store));
	g_object_unref (store);
	
}
}




