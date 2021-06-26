#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
# include "callbacks.h"
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include"client.h"
# include <gtk/gtk.h>

enum
{  
	CIN,
	NOM,
	PRENOM,
	NUM,
	MAIL,
	SEXE,
	DATE5,
	COLUMNS,
};
 void ajouter_client(client c,int jour,int mois,int annee)
{

    FILE* f; 
    f=fopen("client.txt","a+");
    fprintf(f,"%s %s %s %s %s %s %d %d %d\n",c.cin,c.nom,c.prenom,c.sexe,c.mail,c.num,jour,mois,annee);
    fclose(f);
 }   
////////////////////////////////////////////////////////////////////////////////////


int exist_client(char *cin)
{
	FILE*f=NULL;
	client c;
	int jour,mois,annee;
	f=fopen("client.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",c.cin,c.nom,c.prenom,c.sexe,c.mail,c.num,&jour,&mois,&annee)!=EOF){
		if(strcmp(c.cin,cin)==0)
			return 1;
	}
	fclose(f);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
void Modifier_client(client c)
{
     FILE* f ;
    FILE* f2;
    char nom[20],prenom[20],mail[20],num[10],cin[10],sexe[10];
    f=fopen("client.txt","r+");
    f2=fopen("tmp.txt","a+");
    int jour,mois,annee;
    
        while (fscanf(f,"%s %s %s %s %s %s %d %d %d\n",cin,nom,prenom,sexe,mail,num,&jour,&mois,&annee)!=EOF)
        {
                if (strcmp(cin,c.cin)!=0)
                {
                 
                    fprintf(f2,"%s %s %s %s %s %s %d %d %d\n",cin,nom,prenom,sexe,mail,num,jour,mois,annee);
                }
                else
                   fprintf(f2,"%s %s %s %s %s %s %d %d %d\n",c.cin,c.nom,c.prenom,c.sexe,c.mail,c.num,jour,mois,annee);
        }
    
    fclose(f);
    fclose(f2);
    remove("client.txt");
    rename("tmp.txt","client.txt");
}
/////////////////////////////////////////////////////////////////////////////////////////

void afficher_client(GtkWidget *liste,int a)
{
GtkCellRenderer *renderer;//afficher de la cellule (cellule contient un text,image,cases à cocher...)
GtkTreeViewColumn *column ;//visualisation des colonnes
GtkTreeIter iter ;//permet de savoir a quelle endroit nous nous positionnons dans la liste,la création d'un nouvelle ligne va donner une nouvelle position dont nous avons besoin pour entrer les données
GtkListStore *store ; //création d'un modèle de type liste
char nom[10];
char prenom[10];
char cin[10];
char mail[40];
char num[10];
char sexe[10];
store=NULL;
FILE *f;
char date[20];
int jour,mois,annee;
store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
	renderer=gtk_cell_renderer_text_new(); //cellule contient du texte
	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);//création une colonne avec un text
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);//associer la colonne à l'afficheur (GtkTreeview)

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mail",renderer,"text",MAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("num",renderer,"text",NUM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Date inscription",renderer,"text",DATE5,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
	goto loop;}
else {
//la liste contient 5 colonnes de type chaine de caractère
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
loop:
	if (a==0){
		
		f=fopen("client.txt","r");
		if(f==NULL)
		{
		return;
		}
		else
		{
			f=fopen("client.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",cin,nom,prenom,sexe,mail,num,&jour,&mois,&annee)!=EOF)
			{
				sprintf(date,"%d/%d/%d",jour,mois,annee);
				gtk_list_store_append(store,&iter);//itérateur parent permet d'ajouter une ligne enfant a une ligne d'un 									    GtkTreestore
				gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,SEXE,sexe,MAIL,mail,NUM,num,DATE5,date, -1);
			}
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
	else {
		
		f=fopen("client.txt","r");
		if(f==NULL)
		{
		return;
		}
		else
		{
			f=fopen("client.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",cin,nom,prenom,sexe,mail,num,&jour,&mois,&annee)!=EOF)
			{
				if (strcmp(cin,c.cin)==0){
					sprintf(date,"%d/%d/%d",jour,mois,annee);		
					gtk_list_store_append(store,&iter);
					gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,SEXE,sexe,MAIL,mail,NUM,num,DATE5,date -1);}
			}
		}
	
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);}
}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void supprimer_client(client c)
{
client c2 ;
int jour,mois,annee;
FILE *f, *g ;
	f=fopen("client.txt","r");
	g=fopen("client2.txt","w");
	if(f==NULL || g==NULL)
	return;
        else
{
	while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",c2.cin,c2.nom,c2.prenom,c2.sexe,c2.mail,c2.num,&jour,&mois,&annee)!=EOF)
{
	if(strcmp(c.cin,c2.cin)!=0)
fprintf(g,"%s %s %s %s %s %s %d %d %d\n",c2.cin,c2.nom,c2.prenom,c2.sexe,c2.mail,c2.num,jour,mois,annee);
}
fclose(f);
fclose(g);
remove("client.txt");
rename("client2.txt","client.txt");
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rechercher_client(char ch[10])
{
	FILE* f;
	char nom[10],prenom[10],cin[10],mail[40],num[10],sexe[10];
	f=fopen("client.txt","r");
	while (fscanf(f,"%s %s %s %s %s %s\n",cin,nom,prenom,sexe,mail,num)!=EOF)
	{
		if (strcmp(cin,ch)==0){
			strcpy(c.nom,nom);
			strcpy(c.prenom,prenom);
			strcpy(c.sexe,sexe);
			strcpy(c.mail,mail);
			strcpy(c.num,num);}
	}
}




