# include<stdio.h>
# include<stdlib.h>
# include "dossier.h"
#include "planter.h"
#include <gtk/gtk.h>
#include<string.h>
enum
{
nom2,
code2,
type2,
dateplantation2,
etat2,
stock2,
COLUMN
};

enum
{
ID_REUN1,
DATE1,
DESC1,
COLUMN26
};
void ajouter_dossier (dossier doss1)
{
	
	FILE *f=NULL;
	f=fopen("dossier.txt","a+");
      
	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %s %s %s \n",doss1.num,doss1.nom,doss1.type,doss1.date,doss1.temperature,doss1.lieu);
		
	
        }
fclose(f);
}

void ajouter_msgadmin(contact cont1)

{	
	FILE *f=NULL;
	f=fopen("msgadmin.txt","a+");
	if(f!=NULL)
	{

		fprintf(f,"%s %s %s \n",cont1.date1,cont1.envoyeur,cont1.message);	
              		
	}

fclose(f);

}
int verifier_dossier(char num[10])
{
	
	int test=0;
	dossier doss1;
	FILE *f=NULL;
	f=fopen("dossier.txt","a+");
	f=fopen("dossier.txt","r");
        
	if(f!=NULL)
	{
		while (fscanf(f,"%s %s %s %s %s %s  \n",doss1.num,doss1.nom,doss1.type,doss1.date,doss1.temperature,doss1.lieu)!=EOF)
		{
			if(strcmp(num,doss1.num)==0)
			{
				test=1;
				break;
			}
                  
		}
		fclose(f);
		return(test);
	}						
}


int verifier_plante(char code[10])

{	
	int test=0;
	plante1 b;
	FILE *f=NULL;	
	f=fopen("plante.txt","r");
	
	if(f!=NULL)
	{
		while (fscanf(f,"%s %s %s %s %s %s \n",b.nom2,b.code2,b.type2,b.dateplantation2,b.etat2,b.stock2)!=EOF)
		{
			if(strcmp(code,b.code2)==0)
			{
				test=1;
				break;
			}
			
		}

		fclose(f);
		return(test);

	}
}





void supprimer_dossier(char num[10])

{
	dossier doss1;
	FILE *f;
	FILE *f2;
	f=fopen("dossier.txt","r");
	f2=fopen("dossier1.txt","a+");
	if(f==NULL)
	{
		printf("erreur d'ouverture du fichier");
		return;
	}
	while (fscanf(f,"%s %s %s %s %s %s \n",doss1.num,doss1.nom,doss1.type,doss1.date,doss1.temperature,doss1.lieu)!=EOF)
	{
		if(strcmp(num,doss1.num)!=0)
		{
			fprintf(f2,"%s %s %s %s %s %s \n",doss1.num,doss1.nom,doss1.type,doss1.date,doss1.temperature,doss1.lieu);			
		}
	}
	fclose(f2);
	fclose(f);		   					
	remove("dossier.txt");
	rename("dossier1.txt","dossier.txt");
	 	   	
}

void modifier_dossier(char *num[],char nom[],char type[],char date[],char temperature[],char lieu[])

{

	dossier doss1;

	FILE *f=NULL;

	FILE *f1=NULL;

	f=fopen("dossier.txt","r");

	f1=fopen("dossier1.txt","a+");

	if (f!=NULL)

	{

	while (fscanf(f,"%s %s %s %s %s %s \n",doss1.num,doss1.nom,doss1.type,doss1.date,doss1.temperature,doss1.lieu)!=EOF)

	{

		

		if(strcmp(doss1.num,num)!=0)

		{

			fprintf(f1,"%s %s %s %s %s %s \n",doss1.num,doss1.nom,doss1.type,doss1.date,doss1.temperature,doss1.lieu);



		}

		else

		{

			fprintf(f1,"%s %s %s %s %s %s \n",num,nom,type,date,temperature,lieu);

		}

	}

	fclose(f1);

	fclose(f);

	remove("dossier.txt");
	rename("dossier1.txt","dossier.txt");

	

	}

}



void remplir1(char *nom[],char code[],char *dateplantation[])

{

	plante1 b;

	FILE *f;

	f=fopen("plante.txt","r");

	if(f!=NULL)

	{

		while(fscanf(f,"%s %s %s %s %s %s \n",b.nom2,b.code2,b.type2,b.dateplantation2,b.etat2,b.stock2)!=EOF)



		{

			if(strcmp(b.code2,code)==0)

			{

				strcpy(nom,b.nom2);

				strcpy(dateplantation,b.dateplantation2);

      			}

		}

	}

}





void modifications(char *num[],char nom[],char type[],char date[],char temperature[],char lieu[])

{

	dossier doss1;	
	FILE *f;	
	f=fopen("dossier.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s \n",doss1.num,doss1.nom,doss1.type,doss1.date,doss1.temperature,doss1.lieu)!=EOF)
		{
			if(strcmp(doss1.num,num)==0)

			{				
				{									
					strcpy(nom,doss1.nom);
					strcpy(type,doss1.type);
					strcpy(date,doss1.date);					
					strcpy(temperature,doss1.temperature);
					strcpy(lieu,doss1.lieu);

				}

			}
			
		}

	}

}

void save5(char code[])

{

FILE *f;

f=fopen("saves.txt","w");

fprintf(f,"%s",code);

fclose(f);

}

void unsave5(char code[])

{

FILE*f;

f=fopen("saves.txt","r");

fscanf(f,"%s\n",code);

fclose(f);

}



void afficher_dossier(GtkWidget *treeview3)

{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter   iter;
	GtkListStore *store;
	char num[10],nom[30],type[30],date[15],temperature[10],lieu[30];
	FILE *f;
	store=NULL ;
	store=gtk_tree_view_get_model(treeview3);	
	if (store==NULL)

	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Num", renderer,"text",Num, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview3), column);		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer,"text",Nom,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview3), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Typee",renderer,"text",Typee, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview3), column);			
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",Date3, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview3), column);			
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Temperature", renderer, "text",Temperature, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview3), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Lieu", renderer, "text",Lieu, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview3), column);	
	}

		store=gtk_list_store_new (COLUMN16, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING);
	f = fopen("dossier.txt","r");
	if(f ==NULL)

	{
		return;
	}		
	else
	{
		while(fscanf(f,"%s %s %s %s %s %s \n",num,nom,type,date,temperature,lieu)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,Num,num,Nom,nom,Typee,type,Date3,date,Temperature,temperature,Lieu,lieu,-1);
		}		
		fclose(f);
	}
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview3), GTK_TREE_MODEL (store));	
	g_object_unref (store);
	
}

void ajoutermessage1(message1 s)
{
FILE *f;
f=fopen("messageagriculteur.txt","a+");
fprintf(f,"%s %s %s  \n ",s.Date1, s.envoyeur1 , s.message1 );
fclose(f);
}

void afficher_reunion(GtkWidget *treeview11)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter   iter;
	GtkListStore *store;
	FILE *f; 
	char id_reun [15];
  	char date [25];	
        int role_staff;
        char desc[60];
        store=NULL;

	store=gtk_tree_view_get_model(treeview11);	
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID_REUN", renderer,"text",ID_REUN1, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date", renderer,"text",DATE1,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Description", renderer, "text",DESC1, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);
			
	
	}
		store=gtk_list_store_new (COLUMN26, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


	f = fopen("reunion.txt","r");
	if(f ==NULL)
	{

		return;
	}		
	else
	{
		while(fscanf(f,"%s %s %d %s \n",id_reun, date, &role_staff, desc)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,ID_REUN1, id_reun, DATE1, date,DESC1,desc,-1);
		}
		
		fclose(f);
	}
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview11), GTK_TREE_MODEL (store));
	
	g_object_unref (store);
	
}


