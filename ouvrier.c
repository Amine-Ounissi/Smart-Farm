#include "callbacks.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "ouvrier.h"
#include <gtk/gtk.h>


enum
{  
	CIN,
	NOM,
	PRENOM,
	SEXE,
	JOUR,
	MOIS,
	ANNEE,
	ADR,
	NUMTEL,
	NBR,
	
	COLUMNS,
};

//verifier ouvrier
int verifier_cin(char CIN[])
{infoouvrier o;
FILE *f;
int test = 0 ;
f=fopen("ouvriers.txt","r+");
if (f!=NULL)
    {
      while(fscanf(f,"%s %s %s %s %d %d %d %s %s %d\n",o.cin,o.nom,o.prenom,o.sexe,&o.naissance.jour,&o.naissance.mois,&o.naissance.annee,o.adr,o.numtel,&o.nbre_abs)!=EOF)
       { g_print("%s\n",o.cin);
         g_print("%s\n",CIN);
         if(strcmp(o.cin,CIN)==0)
         {
             test=1 ;
             return test;
         }
       }
    }
fclose(f);

return test;
}

/******exist ouvrier****/


int exist_ouvrier(char*cin){
infoouvrier o;
FILE*f=NULL;
f=fopen("ouvriers.txt","r");
while(fscanf(f,"%s %s %s %d %d %d %s %s %d\n",o.cin,o.nom,o.prenom,&o.naissance.jour,&o.naissance.mois,&o.naissance.annee,o.adr,o.numtel,&o.nbre_abs)!=EOF){
if(strcmp(o.cin,cin)==0)return 1;//cin existe
}
fclose(f);  
return 0;
}


/************Ajouter ouvrier***********/

void ajouter_ouvrier(infoouvrier o ){
//Date naissance;
FILE*f;//=NULL;
f=fopen("ouvriers.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %s %d %d %d %s %s %d\n",o.cin,o.nom,o.prenom,o.sexe,o.naissance.jour,o.naissance.mois,o.naissance.annee,o.adr,o.numtel,o.nbre_abs);
fclose(f);

}
/******afficher ouvrier*******/
void afficher_ouvrier(GtkWidget *liste)
{GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
char cin[9];
char nom[20];
char prenom[20];
char sexe[10];
char jour[5];
char mois[5];
char annee[7];
char adr[100];
char numtel[9];
char nbre_abs[2];
infoouvrier o;


store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
 	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" cin",renderer, "text",CIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text",PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" sexe",renderer, "text",SEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour naissance",renderer, "text",JOUR,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mois naissance",renderer, "text",MOIS,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" annee naissance",renderer, "text",ANNEE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" adresse",renderer, "text",ADR,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" numtel",renderer, "text",NUMTEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nombre absences",renderer, "text",NBR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	

	store=gtk_list_store_new(10,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("ouvriers.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("ouvriers.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",cin,nom,prenom,sexe,jour,mois,annee,adr,numtel,nbre_abs)!=EOF)
	{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,SEXE,sexe,JOUR,jour,MOIS,mois,ANNEE,annee,ADR,adr,NUMTEL,numtel,NBR,nbre_abs,-1);
	}
	fclose(f);}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
}
}
/**********Modifier ouvrier********/
void modifier_ouvrier(infoouvrier o)
{
   FILE* f ;
    FILE* f1;
    
    
    char cin[9],nom[20],prenom[20],sexe[10],adr[100],numtel[9];
    int jour;
    int mois;
    int annee;
    int nbre_abs;
    
    f=fopen("ouvriers.txt","r");
    f1=fopen("ancien.txt","a+");
    
        while (fscanf(f,"%s %s %s %s %d %d %d %s %s %d\n",cin,nom,prenom,sexe,&jour,&mois,&annee,adr,numtel,&nbre_abs)!=EOF)
        {
                if (strcmp(cin,o.cin)!=0)
                {
                 
                    fprintf(f1,"%s %s %s %s %d %d %d %s %s %d \n",cin,nom,prenom,sexe,jour,mois,annee,adr,numtel,nbre_abs);
                }
                else
                   fprintf(f1,"%s %s %s %s %d %d %d %s %s %d\n",o.cin,o.nom,o.prenom,o.sexe,o.naissance.jour,o.naissance.mois,o.naissance.annee,o.adr,o.numtel,o.nbre_abs);
        }
    
    fclose(f);
    fclose(f1);
    remove("ouvriers.txt");
    rename("ancien.txt","ouvriers.txt");
}
    

void supprimer_ouvrier(char cin[])
{
FILE *f,*f1;
infoouvrier o;

f=fopen("ouvriers.txt","r");
f1=fopen("ancien.txt","w");
 if ((f!=NULL))
{
while(fscanf(f,"%s %s %s %s %d %d %d %s %s %d\n",o.cin,o.nom,o.prenom,o.sexe,&o.naissance.jour,&o.naissance.mois,&o.naissance.annee,o.adr,o.numtel,&o.nbre_abs)!=EOF)
{
if(strcmp(cin,o.cin)!=0)
{
fprintf(f1,"%s %s %s %s %d %d %d %s %s %d\n",o.cin,o.nom,o.prenom,o.sexe,o.naissance.jour,o.naissance.mois,o.naissance.annee,o.adr,o.numtel,o.nbre_abs);
}
}
fclose(f) ;
fclose(f1);


remove("ouvriers.txt");
rename("ancien.txt","ouvriers.txt");
}
}

//Rechercher ouvrier//

void rechercher_ouvrier(GtkWidget *liste, char ch[])

{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char cin[9];
	char nom[20];
	char prenom[20];
	char sexe[10];
	char jour[5];
	char mois[5];
	char annee[7];
	char adr[100];
	char numtel[9];
	char nbre_abs[2];
	infoouvrier o;
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" cin",renderer, "text",CIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text",PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" sexe",renderer, "text",SEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour naissance",renderer, "text",JOUR,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mois naissance",renderer, "text",MOIS,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" annee naissance",renderer, "text",ANNEE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" adresse",renderer, "text",ADR,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" numtel",renderer, "text",NUMTEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nombre absences",renderer, "text",NBR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, 		G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("ouvriers.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("ouvriers.txt","a+");
	 	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",cin,nom,prenom,sexe,jour,mois,annee,adr,numtel,nbre_abs)!=EOF)
	          	{
            if(strcmp(cin,ch)==0)                						  
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,SEXE,sexe,JOUR,jour,MOIS,mois,ANNEE,annee,ADR,adr,NUMTEL,numtel,NBR,nbre_abs,-1);
		}
                 }
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
}
/*********************************************************************************************************************************************/
enum
{  
	CINM,
	NOMM,
	PRENOMM,
	SEXEM,
	JOURM,
	MOISM,
	ANNEEM,
	ADRM,
	NUMTELM,
	NBRM,
	COLUMNSM
};
void MeilleurOuv(GtkWidget *liste , int x)
{GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
char cin[9];
char nom[20];
char prenom[20];
char sexe[10];
char jour[5];
char mois[5];
char annee[7];
char adr[100];
char numtel[9];
int nbre_abs;
infoouvrier o;


store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
 	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" cin",renderer, "text",CINM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOMM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text",PRENOMM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" sexe",renderer, "text",SEXEM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour naissance",renderer, "text",JOURM,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mois naissance",renderer, "text",MOISM,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" annee naissance",renderer, "text",ANNEEM,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" adresse",renderer, "text",ADRM,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" numtel",renderer, "text",NUMTELM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nombre absences",renderer, "text",NBRM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	

	store=gtk_list_store_new(COLUMNSM,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);

f = fopen("ouvriers.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("ouvriers.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %d\n",cin,nom,prenom,sexe,jour,mois,annee,adr,numtel,&nbre_abs)!=EOF)
	{
 	if (nbre_abs==x) {
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,CINM,cin,NOMM,nom,PRENOMM,prenom,SEXEM,sexe,JOURM,jour,MOISM,mois,ANNEEM,annee,ADRM,adr,NUMTELM,numtel,NBRM,nbre_abs,-1);
	}
	}
	fclose(f);}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
}
}




int nbm()
{


char cin[9];
char nom[20];
char prenom[20];
char sexe[10];
char jour[5];
char mois[5];
char annee[7];
char adr[100];
char numtel[9];
int nbre_abs;
int x=1000 ; 

FILE *f;

f=fopen("ouvriers.txt","a+");
  if (f!=NULL)
	{
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %d\n",cin,nom,prenom,sexe,jour,mois,annee,adr,numtel,&nbre_abs)!=EOF)
	{
          if (x>nbre_abs) { x=nbre_abs ; } 
	}
	}
fclose(f); 
return x ; 
}
