# include "repiquage.h"
#include "planter.h"
#include <gtk/gtk.h>




void ajouterr(rep r)
{
FILE *f;
f=fopen("repiquage.txt","a+");
fprintf(f,"%s %s %s %s %s \n",r.code,r.nom,r.type,r.date,r.heure);
fclose(f);
}



 void supprimerr( char code1[])
{
int nb,j;
rep r;
rep tab[1000];
 nb=0;
 FILE *f;
 f=fopen("repiquage.txt","r");
  if (f!=NULL)
{
     while (fscanf(f,"%s %s %s %s %s \n",r.code,r.nom,r.type,r.date,r.heure)!=EOF)
{
    if (strcmp(r.code,code1)!=0)
{ 
   strcpy(tab[nb].code,r.code);
   strcpy(tab[nb].nom,r.nom); 
   strcpy(tab[nb].type,r.type);
   strcpy(tab[nb].date,r.date);
   strcpy(tab[nb].heure,r.heure);  
  nb++;
}
}
 fclose(f);}
f=fopen("repiquage.txt","w");
if (f!=NULL)
{
for (j=0;j<nb;j++)
{
fprintf(f,"%s %s %s %s %s \n",tab[j].code,tab[j].nom,tab[j].type,tab[j].date,tab[j].heure);
}
}
fclose(f);
}


void afficherr(GtkWidget *treeview8)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    *store;
	GtkListStore iter;
	 char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20];
 	
	FILE *f;
	
	store=NULL;
		
	store=gtk_tree_view_get_model(&treeview8);	
	if (store==NULL)
	{       renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Code", renderer,"text",Codea, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW(treeview8), column);	

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer,"text",Noma, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW(treeview8), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",Typea, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW(treeview8), column);
                

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",Datea, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview8), column);
			

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Heure", renderer, "text",Heurea, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview8), column);
	
	}
		store=gtk_list_store_new (COLUMNN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("repiquage.txt", "r");
	
	if(f !=NULL)
	{
	
		while(fscanf(f,"%s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,Codea,ch1,Noma,ch2,Typea,ch3,Datea,ch4,Heurea,ch5,-1);
		}
		
		fclose(f);
		
	}
		
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview8), GTK_TREE_MODEL (store));
	
	g_object_unref (store);
} 


void afficher_repiquage(GtkWidget *treeview9)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter   iter;
	GtkListStore *store;
	char codep[10],nomp[10],typep[10],datep[10] ,heures[8];
	FILE *f; 
	store=NULL ;

	store=gtk_tree_view_get_model(treeview9);	
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Codep", renderer,"text",Codep, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview9), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nomp", renderer,"text",Nomp,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview9), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Typep",renderer,"text",Typep, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview9), column);
			

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Datep", renderer, "text",Datep, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview9), column);
	


		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Heures", renderer, "text",Heures, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview9), column);
	


		
	
	}
		store=gtk_list_store_new (COLUMN19, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING,  G_TYPE_STRING);


	f = fopen("repiquage.txt","r");
	if(f ==NULL)
	{

		return;
	}		
	else
	{
		while(fscanf(f,"%s %s %s %s %s \n",codep,nomp,typep,datep,heures)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,Codep,codep,Nomp,nomp,Typep,typep,Datep,datep,Heures,heures,-1);
		}
		
		fclose(f);
	}
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview9), GTK_TREE_MODEL (store));
	
	g_object_unref (store);
	
}

