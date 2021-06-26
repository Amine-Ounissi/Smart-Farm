#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "treeviewp.h"


void afficherp (GtkWidget *treeview1)
{
  GtkTreeViewColumn   *column;
  GtkCellRenderer     *renderer;
  GtkListStore  *store;
  GtkTreeIter    iter;
char nom[20];
char code[10];
char type[20];
char dateplantation[20];

char etat[20];
char stock[20];

 
FILE *f;
store=NULL;
store=gtk_tree_view_get_model(treeview1);
if (store==NULL)
{
   renderer = gtk_cell_renderer_text_new ();
   column=gtk_tree_view_column_new_with_attributes ("Nom",renderer,"text", NomP,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

   renderer = gtk_cell_renderer_text_new ();
   column=gtk_tree_view_column_new_with_attributes ("Code",renderer,"text", Code,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

   renderer = gtk_cell_renderer_text_new ();
   column=gtk_tree_view_column_new_with_attributes ("Type",renderer,"text", Type,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

   renderer = gtk_cell_renderer_text_new ();
   column=gtk_tree_view_column_new_with_attributes ("DatePlantation",renderer,"text", DatePlantation,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

   renderer = gtk_cell_renderer_text_new ();
   column=gtk_tree_view_column_new_with_attributes ("Etat",renderer,"text", Etat,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

   renderer = gtk_cell_renderer_text_new ();
   column=gtk_tree_view_column_new_with_attributes ("Stock",renderer,"text",Stock ,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);


   store = gtk_list_store_new (COLUMN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
   f=fopen("plante.txt","r");
   if (f!=NULL)
{
     while (fscanf(f,"%s %s %s %s %s %s\n",nom,code,type,dateplantation,etat,stock)!=EOF)
{
     	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NomP,nom,Code,code,Type,type,DatePlantation ,dateplantation,Etat,etat,Stock,  stock,-1);
}
fclose(f);
}
   gtk_tree_view_set_model (GTK_TREE_VIEW (treeview1),GTK_TREE_MODEL (store));
   g_object_unref (store);
}
}
