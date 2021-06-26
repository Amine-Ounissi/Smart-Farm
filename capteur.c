#ifdef HAVE_config_H
# include <config.h>
#endif
#include "callbacks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>

#include "capteur.h"
enum
{
	ESERIE,
	ENOM,
	ETYPE,
	EETAT,
	EMARQUE,
	EJOUR,
	EMOIS,
	EANNEE,
	COLUMNS,

};
enum
{
	ESERIE1,
	ENOM1,
	ETYPE1,
	EETAT1,
	EMARQUE1,
	EJOUR1,
	EMOIS1,
	EANNEE1,
	COLUMNS1,

};

enum
{
	ESERIE2,
	ENOM2,
	ETYPE2,
	EVALEUR2,
	EMARQUE2,
	COLUMNS2,

};
enum
{
	ESERIE3,
	ENOM3,
	ETYPE3,
	EETAT3,
	EMARQUE3,
	EJOUR3,
	EMOIS3,
	EANNEE3,
	COLUMNS3,

};
/////////////////////////////////////////////
int exist_capteur(char *serie)
{
	FILE*f=NULL;
	Capteur c;
	f=fopen("capteur.txt","r");
	while(fscanf(f,"%s %s %s %s\n",c.serie,c.nom,c.type,c.marque)!=EOF){
		if(strcmp(c.serie,serie)==0)
			return 1;
	}
	fclose(f);
	return 0;
}

	
///////////////////////////////
void afficher_capteur2(GtkWidget *liste);
////////////////////////////////////////////////////
void afficher_capteur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	Capteur c;
	char serie[20];
	char nom[20]; //les variables ou placer le contenu des gtk_entry
	char type[20];
	char etat[20],marque[20];
	 Date date_achat;
	int jour;
	int mois;
	int annee;
	store=NULL;
        FILE *f;
	store=gtk_tree_view_get_model(liste);
       if (store==NULL)
       {

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("serie",renderer, "text",ESERIE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("nom",renderer, "text",ENOM,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("type",renderer, "text",ETYPE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("etat",renderer, "text",EETAT,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("marque",renderer, "text",EMARQUE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("jour",renderer, "text",EJOUR,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("mois",renderer, "text",EMOIS,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("annee",renderer, "text",EANNEE,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
  }
	store=gtk_list_store_new (COLUMNS ,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT, G_TYPE_INT);
       


	f=fopen("capteur.txt","r");
    if (f==NULL)
    {
    
   return;
    }
    else
   {
      f=fopen("capteur.txt","a+");
      while(fscanf(f,"%s %s %s %s %d %d %d %s\n",nom,serie,type,marque,&jour,&mois,&annee,etat)!=EOF)
      {
        gtk_list_store_append (store,&iter);
        gtk_list_store_set(store,&iter,ESERIE,serie,ENOM,nom,ETYPE,type,EETAT,etat,EMARQUE,marque,EJOUR,jour,EMOIS,mois,EANNEE,annee,-1);
      }
      fclose(f);
      gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
      g_object_unref (store);
 
    }
}


void afficher_capteur2(GtkWidget *liste)
{
	Capteur c;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char serie[20],marque[20];
	char nom[20]; //les variables ou placer le contenu des gtk_entry
	char type[20];
	char etat[20];
	 Date date_achat;
	int jour;
	int mois;
	int annee;
	store=NULL;
        FILE *f;
	store=gtk_tree_view_get_model(liste);
       if (store==NULL)
       {

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("serie",renderer, "text",ESERIE1,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("nom",renderer, "text",ENOM1,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("type",renderer, "text",ETYPE1,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("etat",renderer, "text",EETAT1,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("marque",renderer, "text",EMARQUE1,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("jour",renderer, "text",EJOUR1,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("mois",renderer, "text",EMOIS1,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("annee",renderer, "text",EANNEE1,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
  }
	store=gtk_list_store_new (COLUMNS1 ,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT, G_TYPE_INT);
       


	f=fopen("capteur.txt","r");
    if (f==NULL)
    {
    
   return;
    }
    else
   {
      f=fopen("capteur.txt","a+");
      while(fscanf(f,"%s %s %s %s %d %d %d %s\n",nom,serie,type,marque,&jour,&mois,&annee,etat)!=EOF)
      {
        gtk_list_store_append (store,&iter);
        gtk_list_store_set(store,&iter,ESERIE1,serie,ENOM1,nom,ETYPE1,type,EETAT1,etat,EMARQUE1,marque,EJOUR1,jour,EMOIS1,mois,EANNEE1,annee,-1);
      }
      fclose(f);
      gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
      g_object_unref (store);
 
    }
}
////////////////////////////////////////////////////
/*void rechercher_capteur()
{
FILE* f;
	char nom[20],type[10],etat[10];
	int serie,jour,mois,annee;
	f=fopen("capteur.txt","r");
	while (fscanf(f,"%d %s %s %s %d %d %d\n",serie,nom,type,etat,jour,mois,annee)!=EOF)
	{
		if (strcmp(serie,ch)==0){
			strcpy(c.nom,nom);
			strcpy(c.type,type);
			strcpy(c.etat,etat);
			strcpy(c.Date.jour,jour);
			strcpy(c.Date.mois,mois);
			strcpy(c.Date.annee,annee);
		}
	}
}*/
////////////////////////////////////////////////////*/
void ajouter_capteur(Capteur c)
{
int jour,mois,annee;
char nom[20],type[20],serie[20],etat[20];
char marque[20] ; 
int t=0 ; 
int def; 
FILE *f;
FILE *f1;

f=fopen("capteur.txt","a+");
f1=fopen("defect.txt","a+");
if (f!=NULL) 
{
	if (f1!=NULL) 
	{

	fprintf(f,"%s %s %s %s %d %d %d %s\n",c.nom,c.serie,c.type,c.marque,c.date_achat.jour,c.date_achat.mois,c.date_achat.annee,"indefectueux");

	while(fscanf(f1,"%s %d \n",marque,&def)!=EOF)
	{
	if (strcmp(marque,c.marque)==0) {t++;}
	}
if (t==0) {
	 fprintf(f1,"%s %d \n",c.marque,0);
	}
}
}
fclose(f1);
fclose(f);


}
////////////////////////////////////////////////////
void modifier_capteur(char serie[20],Capteur c )
{
    FILE* f,*f2;
    char nom[20],type[20],etat[20],serie2[20],marque[20];
    int jour,mois,annee;
    
    f=fopen("capteur.txt","r+");
    f2=fopen("tmp.txt","a+");
    if (f==EOF)
        return;
    else
    {
        while (fscanf(f,"%s %s %s %s %d %d %d %s\n",nom,serie2,type,marque,&jour,&mois,&annee,etat)!=EOF)
        {
                if (strcmp(serie,serie2)!=0)
                    fprintf(f2,"%s %s %s %s %d %d %d %s\n",nom,serie2,type,marque,jour,mois,annee,etat);
                else
                   fprintf(f2,"%s %s %s %s %d %d %d %s\n",c.nom,c.serie,c.type,marque,c.date_achat.jour,c.date_achat.mois,c.date_achat.annee,c.etat);
        }
    }
    fclose(f);
    fclose(f2);
    remove("capteur.txt");
    rename("tmp.txt","capteur.txt");

}
///////////////////////////////////////////////////
void supprimer_capteur(char serie[20] )
{
Capteur c2;
FILE *f,*g;
	f=fopen("capteur.txt","r");
	g=fopen("capteur2.txt","a+");
	if (f==NULL || g==NULL)
	{return;}
	else
	{
	
	while(fscanf(f,"%s %s %s %s %d %d %d %s\n",c2.nom,c2.serie,c2.type,c2.marque,&c2.date_achat.jour,&c2.date_achat.mois,&c2.date_achat.annee,c2.etat)!=EOF)
	{
	     if  (strcmp (serie,c2.serie)!=0) 

fprintf(g,"%s %s %s %s  %d %d %d %s\n",c2.nom,c2.serie,c2.type,c2.marque,c2.date_achat.jour,c2.date_achat.mois,c2.date_achat.annee,c2.etat);}
	
	fclose(f);
	fclose(g);
remove("capteur.txt");
rename("capteur2.txt","capteur.txt");
}
}

///////////////////////////////////////////////////

void valeurs_capteur_alarmante(char type[20])
{
/*char serie[20], nom[20], marque[20],etat[20];
int jour,mois,annee;
int tem,hum;
 FILE*f,*g;
 f=fopen("capteur.txt","r");
 g=fopen("alarmante.txt","w");
// h=fopen("panne.txt","w");
while(fscanf(f,"%s %s %s %s %s %d %d %d\n",serie,nom,type,marque,etat,jour,mois,annee)!=EOF)
 {

    tem=atoi(type);
    hum=atoi(type);
  

    if ((tem<30)&&(tem>=20))
    {
        
        fprintf(g," pas de valeurs alarmante %s\n",serie);
    }
    else  
    {
  
        fprintf(g,"c'est une valeur alarmante %s\n",serie);
        
    }
        if ((hum<70)&&(hum>=50))
    {
        
         fprintf(g," pas de valeurs alarmante %s\n",serie);
    }
    else 
    {
  
        fprintf(g," c'est une valeurs alarmante %s\n",serie);
   
    }
 }
fclose(f);
fclose(g);*/
}

/////////////////////////////////////////////////////////////////////
void affiche_valeur(GtkWidget *liste)
{Capteur c;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	 char serie[20], nom[20], type[20], marque[20];
	FILE *f,*f2;
	int valeur;
	store=NULL;
	//creat the colomns if they dont already exist
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		serie	",renderer, "text",ESERIE2,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		nom	",renderer, "text",ENOM2,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		type	",renderer, "text",ETYPE2,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		marque	",renderer, "text",EMARQUE2,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		valeur	",renderer, "text",EVALEUR2,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

  }
	store=gtk_list_store_new (COLUMNS2 ,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);
       
	f=fopen("capteur.txt", "r");
	
	if(f ==NULL)  {return;}
	else
	{
		while(fscanf(f,"%s %s %s %s %d %d %d %s\n",c.nom,c.serie,c.type,c.marque,&c.date_achat.jour,&c.date_achat.mois,&c.date_achat.annee,c.etat)!=EOF)
		{
			g_print("%s\n",c.serie);
			f2=fopen("valeur capteur.txt","r");
			while (fscanf(f2,"%s %d\n",serie,&valeur)!=EOF)
			{
				if (strcmp(serie,c.serie)==0){

					g_print("%s %s\n",serie,c.serie);
					gtk_list_store_append (store, &iter);
					gtk_list_store_set (store, &iter,ESERIE2,c.serie,ENOM2,c.nom,ETYPE2,c.type,EVALEUR2,valeur,EMARQUE2,c.marque,-1);}
			}
			fclose(f2);
		}
		fclose(f);
	}		
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}
//////////////////////////////////////////////////////////////////////////////
/*void capteur_defectueux(){

FILE* f;
FILE* f2;
char nom[20],serie[20],type[20],marque[20],etat[20];
int jour,mois,annee;
int i=0;
int tab[100];
f=fopen("capteur.txt","r+");
f2=fopen("marque.txt","r+");
 //while (fscanf(f2,"%s\n",marque)!=EOF)
	{while (fscanf(f,"%s %s %s %s %d %d %d %s\n",serie,nom,type,marque,etat,&jour,&mois,&annee)!=EOF)
		{if (strcmp(c.marque,marque)==0)&&(strcmp(etat,"defectueux")==0)  {
			tab[i]+=1;
				i++;}

fclose(f);
fclose(f2);
}
}
}*/
////////////////////////////////////////////////////////////////////////////////////

void ajouter_valeur(char serie[30],int valeur)
{Capteur c;
	FILE *f,*f2,*f3;
	f=fopen("capteur.txt","r");
	f2=fopen("valeur capteur.txt","r");
	f3=fopen("tmp.txt","a+");
	g_print("%.2f\n",valeur);
	int valeur2;
	while (fscanf(f2,"%s %d\n",c.serie,&valeur2)!=EOF)
		if (strcmp(c.serie,serie)!=0)
			fprintf(f3,"%s %d\n",c.serie,valeur2);
	fclose(f2);fclose(f3);
	remove("valeur capteur.txt");
	rename("tmp.txt","valeur capteur.txt");
	f2=fopen("valeur capteur.txt","a+");

	while(fscanf(f,"%s %s %s %s %d %d %d %s\n",c.nom,c.serie,c.type,c.marque,&c.date_achat.jour,&c.date_achat.mois,&c.date_achat.annee,c.etat)!=EOF)
		if (strcmp(c.serie,serie)==0)
			fprintf(f2,"%s %d\n",c.serie,valeur);
	fclose(f);fclose(f2);
}


int nbm2(char marque1[])
{Capteur c;

int jour,mois,annee;
char nom[20],type[20],serie[20],etat[20];
char marque[20] ; 
char m[20] ; 
int t=0 ; 
int def; 
int nb=0 ; 
FILE *f;
FILE *f1;
FILE *f2;

f=fopen("capteur.txt","r+");

if (f!=NULL) 
{
while(fscanf(f,"%s %s %s %s %d %d %d %s\n",c.nom,c.serie,c.type,c.marque,&c.date_achat.jour,&c.date_achat.mois,&c.date_achat.annee,etat)!=EOF)		
		{ 
	          
		if ((strcmp(marque1,c.marque)==0) && (strcmp(etat,"indefectueux")!=0)) {nb++ ;}	
		}
	}
fclose(f);
return nb ;
}

void defaillance () 
{
int jour,mois,annee;
char nom[20],type[20],serie[20],etat[20];
char marque[20] ; 
char m[20] ; 
int t=0 ; 
int def; 
int nb=0 ; 
FILE *f;
FILE *f1;
FILE *f2;

f=fopen("defect.txt","r+");
f1=fopen("defect1.txt","w+");
if (f!=NULL) 
{
	if (f1!=NULL) 
	{
	while(fscanf(f,"%s %d \n",marque,&def)!=EOF)		
		{
	          nb=nbm2(marque); 
		  fprintf(f1,"%s %d \n",marque,nb);
		}

	
	}
}

fclose(f1);
fclose(f);



}

int max()
{

char marque[20] ; 


FILE *f;

int def; 
int nb=0; 

f=fopen("defect1.txt","r+");
if (f!=NULL) 
{
	while(fscanf(f,"%s %d \n",marque,&def)!=EOF)		
		{
	          if (nb<def) nb=def ; 
		}
	
}

fclose(f);

return nb ; 
}


enum {
MARQ, 
NB,
COLUMNST
};

void afficherCapt(GtkWidget *liste , int m )
{


GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char marque[20];
int n ; 


store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Marque",render,"text",MARQ,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Nb",render,"text",NB,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNST,G_TYPE_STRING,G_TYPE_INT) ; 

f=fopen("defect1.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("defect1.txt","a+") ;
 while(fscanf(f,"%s %d \n" ,marque,&n)!=EOF) 
{
if (m==n){
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,MARQ,marque,NB,n,-1) ; 
}
}
fclose(f) ;} 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 

}
}


enum
{
	ESERIET,
	ENOMT,
	ETYPET,
	EVALEURT,
	EMARQUET,
	COLUMNST1,

};



void capteurhorsintertemp(GtkWidget *liste)
{	Capteur c;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	 char serie[20], nom[20], type[20], marque[20];
	FILE *f,*f2;
	int valeur;
	store=NULL;
	//creat the colomns if they dont already exist
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		serie	",renderer, "text",ESERIET,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		nom	",renderer, "text",ENOMT,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		type	",renderer, "text",ETYPET,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		marque	",renderer, "text",EMARQUET,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		valeur	",renderer, "text",EVALEURT,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

  }
	store=gtk_list_store_new (COLUMNST1 ,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);
       
	f=fopen("capteur.txt", "r");
	
	if(f ==NULL)  {return;}
	else
	{
		while(fscanf(f,"%s %s %s %s %d %d %d %s\n",c.nom,c.serie,c.type,c.marque,&c.date_achat.jour,&c.date_achat.mois,&c.date_achat.annee,c.etat)!=EOF)
		{
			g_print("%s\n",c.serie);
			f2=fopen("valeur capteur.txt","r");
			while (fscanf(f2,"%s %d\n",serie,&valeur)!=EOF)
			{
				if ((strcmp(serie,c.serie)==0) && (strcmp(c.type,"Temperature")==0) && ((valeur<20) || (valeur>40))) {

					gtk_list_store_append (store, &iter);
					gtk_list_store_set (store, &iter,ESERIET,c.serie,ENOMT,c.nom,ETYPET,c.type,EVALEURT,valeur,EMARQUET,c.marque,-1);}
			}
			fclose(f2);
		}
		fclose(f);
	}		
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}


enum
{
	ESERIEH,
	ENOMH,
	ETYPEH,
	EVALEURH,
	EMARQUEH,
	COLUMNSH1,

};
void capteurhorsinterhumid(GtkWidget *liste)
{Capteur c;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	 char serie[20], nom[20], type[20], marque[20];
	FILE *f,*f2;
	int valeur;
	store=NULL;
	//creat the colomns if they dont already exist
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{
    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		serie	",renderer, "text",ESERIEH,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		nom	",renderer, "text",ENOMH,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		type	",renderer, "text",ETYPEH,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		marque	",renderer, "text",EMARQUEH,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("		valeur	",renderer, "text",EVALEURH,NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

  }
	store=gtk_list_store_new (COLUMNSH1 ,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);
       
	f=fopen("capteur.txt", "r");
	
	if(f ==NULL)  {return;}
	else
	{
		while(fscanf(f,"%s %s %s %s %d %d %d %s\n",c.nom,c.serie,c.type,c.marque,&c.date_achat.jour,&c.date_achat.mois,&c.date_achat.annee,c.etat)!=EOF)
		{
			g_print("%s\n",c.serie);
			f2=fopen("valeur capteur.txt","r");
			while (fscanf(f2,"%s %d\n",serie,&valeur)!=EOF)
			{
				if ((strcmp(serie,c.serie)==0) && (strcmp(c.type,"Humidite")==0) && ((valeur>=50) && (valeur<=70))) {

					g_print("%s %s\n",serie,c.serie);
					gtk_list_store_append (store, &iter);
					gtk_list_store_set (store, &iter,ESERIEH,c.serie,ENOMH,c.nom,ETYPEH,c.type,EVALEURH,valeur,EMARQUEH,c.marque,-1);}
			}
			fclose(f2);
		}
		fclose(f);
	}		
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}





