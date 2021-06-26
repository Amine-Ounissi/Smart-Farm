#include "callbacks.h"
#include "Troupeau.h"
#include <string.h>
void supprimer_animal_malade(char a[20]);
enum
{
	ENAME,
	EBOUCLE,
	ESEXE,
	EDATE,
	EAGE,
	ESANTE,
	COLUMNS,
};

//*******************************************************************************************************************************************************************
void get_date(char *jour[2],char *mois[10],char *annee[4],char ch[20])
{
	int len = strlen(ch);
  char d[] = "/";
  char *p = strtok(ch,d);
 int a=1;
  while(p != NULL)
  {if (a==1)
        strcpy(jour,p);
   if (a==2)
        strcpy(mois,p);
   if (a==3)
        strcpy(annee,p);
    p = strtok(NULL, d);
   a++;
  }
  
  
}
//*******************************************************************************************************************************************************************

int existe(char boucle[10],FILE *f)
{
	char nom2[30],boucle2[30],date2[30],sante2[30],date3[30],sexe2[30];
	while (fscanf(f,"%s %s %s %s %s\n",nom2,boucle2,sexe2,date2,sante2)!=EOF){
		if (strcmp(boucle2,boucle)==0)
			return 1;}
	return 0;
}


//*******************************************************************************************************************************************************************
int get_mois(char mois[20])
{
	if (strcmp(mois,"Janvier")==0) return 1;
	if (strcmp(mois,"Fevrier")==0) return 2;
	if (strcmp(mois,"Mars")==0) return 3;
	if (strcmp(mois,"April")==0) return 4;
	if (strcmp(mois,"Mai")==0) return 5;
	if (strcmp(mois,"Juin")==0) return 6;
	if (strcmp(mois,"Juillet")==0) return 7;
	if (strcmp(mois,"Aout")==0) return 8;
	if (strcmp(mois,"Semptembre")==0) return 9;
	if (strcmp(mois,"Octobre")==0) return 10;
	if (strcmp(mois,"Novembre")==0) return 11;
	if (strcmp(mois,"Decembre")==0) return 12;
}
//*******************************************************************************************************************************************************************
int get_age(char date[20])
{
	int a,m,j,age,d;
	long n,n_actuel;
	char *jour[3],*mois[20],*annee[5];
	get_date(&jour,&mois,&annee,date);
	a=atoi(annee);
	m=get_mois(mois);
	j=atoi(jour);
	n=a*10000+m*100+j;
	time_t t = time(NULL);
 	struct tm tm = *localtime(&t);
	n_actuel=(tm.tm_year+1900)*10000+tm.tm_mon*100+tm.tm_mday;
	d=n_actuel-n;
	d=d/10000;
	if (d>(tm.tm_year+1900-a))
		return  ;
	else  return (tm.tm_year+1900-a);
}
//*******************************************************************************************************************************************************************
long date_long(char ch[20])
{
	int a,m,j,age,d;
	char *jour[3],*mois[20],*annee[5];
	get_date(&jour,&mois,&annee,ch);
	a=atoi(annee);
	m=get_mois(mois);
	j=atoi(jour);
	return (a*10000+m*100+j);
}





//*******************************************************************************************************************************************************************
void ajouter_animal(Troupeau animal)
{
    FILE* f;
    int age;
    char name[30],sexe[30],sante[30],date[20]="",date2[20],boucle[20],jour[2],mois[20],annee[10];
    sprintf(date,"%s/%s/%s",animal.date_naissance.jour,animal.date_naissance.mois,animal.date_naissance.annee);
    strcpy(date2,date);
    f=fopen("troupeau.txt","a+");
    if (f!=NULL)
    {
	age=get_age(date2);
    	fprintf(f,"%s %s %s %s %s\n",animal.name,animal.boucle,animal.sexe,date,animal.sante);
    }   
    fclose(f);
}

//*******************************************************************************************************************************************************************
void modifier_animal(Troupeau animal,char date[20],char boucle1[20])
{
	FILE *f,*f2,*f3;
	char name2[30],sexe2[30],sante2[30],date2[20],boucle2[20];
	char maladie1[2],maladie2[2],maladie3[2],maladie4[2];
	int test=0;
	f=fopen("troupeau.txt","r");
	f2=fopen("tmp.txt","a+");
	if (strcmp(animal.sante,"Malade")==0){
		f3=fopen("troupeau_malade.txt","a+");
		
		while (fscanf(f3,"%s %s %s %s %s %s\n",name2,boucle2,maladie1,maladie2,maladie3,maladie4)!=EOF)
			if (strcmp(boucle2,boucle1)==0)
				test=1;
		if (test==0)
			fprintf(f3,"%s %s %s %s %s %s\n",animal.name,animal.boucle,"-","-","-","-");
		fclose(f3);}
				

		
	while (fscanf(f,"%s %s %s %s %s\n",name2,boucle2,sexe2,date2,sante2)!=EOF)
	{
		if (strcmp(boucle2,boucle1)==0)
			fprintf(f2,"%s %s %s %s %s\n",animal.name,animal.boucle,animal.sexe,date,animal.sante);
		else 
			fprintf(f2,"%s %s %s %s %s\n",name2,boucle2,sexe2,date2,sante2);
	}
	fclose(f);
	fclose(f2);
	remove("troupeau.txt");
	rename("tmp.txt","troupeau.txt");
}
//*******************************************************************************************************************************************************************
void nombre_animal(int tab[5][5])
{
	tab[0][0]=0;tab[0][1]=0;tab[0][2]=0;tab[0][3]=0;tab[0][4]=0;
	tab[1][0]=0;tab[1][1]=0;tab[1][2]=0;tab[1][3]=0;tab[1][4]=0;
	tab[2][0]=0;tab[2][1]=0;tab[2][2]=0;tab[2][3]=0;tab[2][4]=0;
	tab[3][0]=0;tab[3][1]=0;tab[3][2]=0;tab[3][3]=0;tab[3][4]=0;
	tab[4][0]=0;tab[4][1]=0;tab[4][2]=0;tab[4][3]=0;tab[4][4]=0;
	FILE *f,*f2;
	char name[30],sexe[30],sante[30],date[20],boucle[20],animal_name[20],none[20];
	int i=0;
	f=fopen("troupeau.txt","r");
	

		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
		{
			if ((strcmp(sexe,"Male")==0)&&(strcmp(name,"Vache")==0)){
				tab[0][0]+=1;
				tab[0][4]+=1;
				tab[4][0]+=1;}
			else if ((strcmp(sexe,"Femelle")==0)&&(strcmp(name,"Vache")==0)){
				tab[1][0]+=1;
				tab[1][4]+=1;
				tab[4][0]+=1;}
			if ((strcmp(sexe,"Male")==0)&&(strcmp(name,"Mouton")==0)){
				tab[0][1]+=1;
				tab[0][4]+=1;
				tab[4][1]+=1;}
			else if ((strcmp(sexe,"Femelle")==0)&&(strcmp(name,"Mouton")==0)){
				tab[1][1]+=1;
				tab[1][4]+=1;
				tab[4][1]+=1;}
			if ((strcmp(sexe,"Male")==0)&&(strcmp(name,"Veau")==0)){
				tab[0][2]+=1;
				tab[0][4]+=1;
				tab[4][2]+=1;}
			else if ((strcmp(sexe,"Femelle")==0)&&(strcmp(name,"Veau")==0)){
				tab[1][2]+=1;
				tab[1][4]+=1;
				tab[4][2]+=1;}
			if ((strcmp(sexe,"Male")==0)&&(strcmp(name,"Brebi")==0)){
				tab[0][3]+=1;
				tab[0][4]+=1;
				tab[4][3]+=1;}
			else if ((strcmp(sexe,"Femelle")==0)&&(strcmp(name,"Brebi")==0)){
				tab[1][3]+=1;
				tab[1][4]+=1;
				tab[4][3]+=1;}

			if ((strcmp(sante,"Bonne")==0)&&(strcmp(name,"Vache")==0)){
				tab[2][0]+=1;
				tab[2][4]+=1;
				}
			else if ((strcmp(sante,"Malade")==0)&&(strcmp(name,"Vache")==0)){
				tab[3][0]+=1;
				tab[3][4]+=1;
				}
			if ((strcmp(sante,"Bonne")==0)&&(strcmp(name,"Mouton")==0)){
				tab[2][1]+=1;
				tab[2][4]+=1;
				}
			else if ((strcmp(sante,"Malade")==0)&&(strcmp(name,"Mouton")==0)){
				tab[3][1]+=1;
				tab[3][4]+=1;
				}
			if ((strcmp(sante,"Bonne")==0)&&(strcmp(name,"Veau")==0)){
				tab[2][2]+=1;
				tab[2][4]+=1;
				}
			else if ((strcmp(sante,"Malade")==0)&&(strcmp(name,"Veau")==0)){
				tab[3][2]+=1;
				tab[3][4]+=1;
				}
			if ((strcmp(sante,"Bonne")==0)&&(strcmp(name,"Brebi")==0)){
				tab[2][3]+=1;
				tab[2][4]+=1;
				}
			else if ((strcmp(sante,"Malade")==0)&&(strcmp(name,"Brebi")==0)){
				tab[3][3]+=1;
				tab[3][4]+=1;
				}
		}
		
	tab[4][4]=tab[4][0]+tab[4][1]+tab[4][2]+tab[4][3];
	fclose(f);
}


//*******************************************************************************************************************************************************************
void afficher_nombre_animal(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
	int age;
	FILE* f,*f1;
    char name[30],sexe[30],sante[30],date[20],boucle[20],none[20],total[20];
    store=NULL;
    store=gtk_tree_view_get_model(liste);
if (store==NULL){
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("				",renderer,"text",ENONE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("    Vache    ",renderer,"text",EVACHE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("    Mouton    ",renderer,"text",EMOUTON,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("    Veau    ",renderer,"text",EVEAU,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("    Brebi    ",renderer,"text",EBREBI,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("    Total   ",renderer,"text",ETOTAL,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    }

    store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);
    int tab[5][5];
    nombre_animal(tab);
    f=fopen("Animal_name.txt","r");
	if (f==NULL)
	{
		return;
	}
	else
	{
		int i=0;
		while (fscanf(f,"%s %s\n",name,none)!=EOF){
			sprintf(total,"=%d",tab[i][4]);
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ENONE,none,EVACHE,tab[i][0],EMOUTON,tab[i][1],EVEAU,tab[i][2],EBREBI,tab[i][3],ETOTAL,total,-1);
			i++;
		}
		sprintf(total,"=%d",tab[4][4]);
		gtk_list_store_append(store,&iter);
		gtk_list_store_set(store,&iter,ENONE,"Total du l'espéce",EVACHE,tab[4][0],EMOUTON,tab[4][1],EVEAU,tab[4][2],EBREBI,tab[4][3],ETOTAL,total,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);

}


//*******************************************************************************************************************************************************************

void afficher_animal(GtkWidget *liste,char boucle_rech[20],char tirer_par[20])
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
	int age;
	FILE* f,*f1;
    char name[30],sexe[30],sante[30],date[20],boucle[20],jour[10],mois[20],annee[20],date2[20];
    store=NULL;
    store=gtk_tree_view_get_model(liste);
if (store==NULL){
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("		Name		",renderer,"text",ENAME, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("		Boucle		",renderer,"text",EBOUCLE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("		Sexe		",renderer,"text",ESEXE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("		Date naissance		",renderer,"text",EDATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("		Age	",renderer,"text",EAGE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("		Santé	",renderer,"text",ESANTE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);
	f=fopen("troupeau.txt","r");    
	if (f!=NULL)
	goto loop;
}

else{	
loop:
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);

if (strcmp(tirer_par,"1")==0){
	f=fopen("recherche avance.txt","r");
		    if (f==NULL)
		    {
			return;
		    }
		    else
		    {
			while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
			{
				strcpy(date2,date);
				age=get_age(date2);
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ENAME, name ,EBOUCLE,boucle,ESEXE,sexe,EDATE,date,EAGE,age,ESANTE,sante,-1);
			}
		    }
		    fclose(f);
		    remove("recherche avance.txt");
		    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		    g_object_unref(store);
}
else if (strcmp(tirer_par,"")==0){
	f=fopen("troupeau.txt","r");
		    while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF){
			strcpy(date2,date);
				age=get_age(date2);
				if ((age>=3)&&(strcmp(name,"Veau")==0))
					changer_name(boucle,"Veau");
				if ((age<3)&&(strcmp(name,"Vache")==0))
					changer_name(boucle,"Vache");
				if ((age>=1)&&(strcmp(name,"Brebi")==0))
					changer_name(boucle,"Brebi");
				if ((age<1)&&(strcmp(name,"Mouton")==0))
					changer_name(boucle,"Mouton");}
		    fclose(f);
		    TirerPar("Boucle");
		    f=fopen("Boucle.txt","r");
		    if (f==NULL)
		    {
			return;
		    }
		    else
		    {	
			while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
			{
				strcpy(date2,date);
				age=get_age(date2);

				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ENAME, name ,EBOUCLE,boucle,ESEXE,sexe,EDATE,date,EAGE,age,ESANTE,sante,-1);
			}
		    }
		    fclose(f);
		    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		    g_object_unref(store);
			remove("Boucle.txt");}




else if (strcmp(boucle_rech,"")==0){
		    f=fopen("troupeau.txt","r");
		    while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF){
			strcpy(date2,date);
				age=get_age(date2);
				if ((age>=3)&&(strcmp(name,"Veau")==0))
					changer_name(boucle,"Veau");
				if ((age<3)&&(strcmp(name,"Vache")==0))
					changer_name(boucle,"Vache");
				if ((age>=1)&&(strcmp(name,"Brebi")==0))
					changer_name(boucle,"Brebi");
				if ((age<1)&&(strcmp(name,"Mouton")==0))
					changer_name(boucle,"Mouton");}
		    fclose(f);
		    TirerPar(tirer_par);
		    strcat(tirer_par,".txt");
		    f=fopen(tirer_par,"r");
		    if (f==NULL)
		    {
			return;
		    }
		    else
		    {	
			while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
			{
				strcpy(date2,date);
				age=get_age(date2);

				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ENAME, name ,EBOUCLE,boucle,ESEXE,sexe,EDATE,date,EAGE,age,ESANTE,sante,-1);
			}
		    }
		    fclose(f);
		
		    remove(tirer_par);
		    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		    g_object_unref(store);}
    else {
		   
	  	    f=fopen("troupeau.txt","r");
	 	    if (f==NULL)
	 	    {
		 	return;
		     }
	  	    else
		    {
			while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
			{
				if (strcmp(boucle,boucle_rech)==0){
					age=get_age(date2);
					gtk_list_store_append(store,&iter);
					gtk_list_store_set(store,&iter,ENAME, name ,EBOUCLE,boucle,ESEXE,sexe,EDATE,date,EAGE,age,ESANTE,sante,-1);}
			}
		    }
		    fclose(f);
		    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		    g_object_unref(store);
}}}
//*******************************************************************************************************************************************************************

void supprimer_animal(char a[20])
{
    FILE* f ;
    FILE* f2;
    FILE* f3;
    FILE* f4,*f5;
	int age;
    char name[30],sexe[30],sante[30],date[20],boucle[20],mal1[30],mal2[30],mal3[30],mal4[30];
    f=fopen("troupeau.txt","r+");
    f2=fopen("tmp.txt","a+");
    f3=fopen("corbeille_troupeau.txt","a+");
    f4=fopen("troupeau_malade.txt","a+");
    f5=fopen("tmp2.txt","a+");
    if (f!=NULL)
        while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
        {
                if (strcmp(a,boucle)!=0)
                   fprintf(f2,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);
		 
		else fprintf(f3,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);
        }
	while (fscanf(f4,"%s  %s  %s  %s  %s  %s\n",name,boucle,mal1,mal2,mal3,mal4)!=EOF)
        {
                if (strcmp(a,boucle)!=0)
			fprintf(f5,"%s  %s  %s  %s  %s  %s\n",name,boucle,mal1,mal2,mal3,mal4);
        }
    fclose(f);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    remove("troupeau.txt");
    rename("tmp.txt","troupeau.txt");
    remove("troupeau_malade.txt");
    rename("tmp2.txt","troupeau_malade.txt");
}


//*******************************************************************************************************************************************************************

void afficher_animal_malade(GtkWidget *liste)
{
GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char name[30],boucle[30],maladie1[30],maladie2[30],maladie3[30],maladie4[30],autre[30];
    store=NULL;
    store=gtk_tree_view_get_model(liste);
if (store==NULL){
    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("Name",renderer,"text",ENAME2, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("Boucle",renderer,"text",EBOUCLE2,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("  Coryza gangreneux  ",renderer,"text",EMAL1,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("  Fièvre catarrhale ovine  ",renderer,"text",EMAL2,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("  Infection par le virus BVD-MD  ",renderer,"text",EMAL3,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("  Maladies virales  ",renderer,"text",EMAL4,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    
    store=gtk_list_store_new(RCOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
   goto loop;
   }

else{	
loop:
store=gtk_list_store_new(RCOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

		    FILE* f;
		    f=fopen("troupeau_malade.txt","a+");
		    if (f==NULL)
		    {
			return;
		    }
		    else
		    {
			while (fscanf(f,"%s  %s  %s  %s  %s  %s  \n",name,boucle,maladie1,maladie2,maladie3,maladie4)!=EOF)
			{
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ENAME2,name,EBOUCLE2,boucle,EMAL1,maladie1,EMAL2,maladie2,EMAL3,maladie3,EMAL4,maladie4,-1);
			}
		    }
		    fclose(f);
		  
		    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		    g_object_unref(store);
}}
//*******************************************************************************************************************************************************************
void ajouter_animal_malade(Troupeau animal,GtkWidget *maladie1,GtkWidget *maladie2,GtkWidget *maladie3,GtkWidget *maladie4)
{
	FILE *f4;
	f4=fopen("troupeau_malade.txt","a+");
	fprintf(f4,"%s  ",animal.name);
	fprintf(f4,"%s  ",animal.boucle);
	if ( gtk_toggle_button_get_active(maladie1))
		fprintf(f4,"%s  ","X");
	else 	
		fprintf(f4,"%s  ","-");
	if ( gtk_toggle_button_get_active(maladie2))
		fprintf(f4,"%s  ","X");
	else 
		fprintf(f4,"%s  ","-");
	if ( gtk_toggle_button_get_active(maladie3))
		fprintf(f4,"%s  ","X");
	else 
		fprintf(f4,"%s  ","-");
	if ( gtk_toggle_button_get_active(maladie4))
		fprintf(f4,"%s  ","X");
	else 
		fprintf(f4,"%s  ","-");
	fprintf(f4,"\n");
	fclose(f4);
}
//*******************************************************************************************************************************************************************
void modifier_animal_malade(Troupeau animal,GtkWidget *maladie1,GtkWidget *maladie2,GtkWidget *maladie3,GtkWidget *maladie4)
{
	char malade1[20],malade2[20],malade3[20],malade4[20],name[20],boucle[20];
	
	FILE *f4,*f5;
	f4=fopen("troupeau_malade.txt","r");
	f5=fopen("tmp.txt","a+");
	while (fscanf(f4,"%s %s %s %s %s %s\n",name,boucle,malade1,malade2,malade3,malade4)!=EOF)
	{
		if (strcmp(boucle,animal.boucle)!=0)
			fprintf(f5,"%s %s %s %s %s %s\n",name,boucle,malade1,malade2,malade3,malade4);
		else {
			
				fprintf(f5,"%s ",animal.name);
			
				fprintf(f5,"%s ",animal.boucle);
			if ( gtk_toggle_button_get_active(maladie1))
				fprintf(f5,"%s ","X");
			else 
				fprintf(f5,"%s ","-");
			if ( gtk_toggle_button_get_active(maladie2))
				fprintf(f5,"%s ","X");
			else 
				fprintf(f5,"%s ","-");
			if ( gtk_toggle_button_get_active(maladie3))
				fprintf(f5,"%s ","X");
			else 
				fprintf(f5,"%s ","-");
			if ( gtk_toggle_button_get_active(maladie4))
				fprintf(f5,"%s","X");
			else 
				fprintf(f5,"%s","-");
			fprintf(f5,"\n");}
	}
	fclose(f4);fclose(f5);
	remove("troupeau_malade.txt");
	rename("tmp.txt","troupeau_malade.txt");
}
//*******************************************************************************************************************************************************************
void supprimer_animal_malade(char a[20])
{
    FILE* f4,*f2;
    int age;
    char name[30],sexe[30],sante[30],date[20],boucle[20],mal1[30],mal2[30],mal3[30],mal4[30];
    f2=fopen("tmp2.txt","a+");
    f4=fopen("troupeau_malade.txt","r");
    if (f4!=NULL)
	while (fscanf(f4,"%s %s %s %s %s %s\n",name,boucle,mal1,mal2,mal3,mal4)!=EOF)
        {
                if (strcmp(a,boucle)!=0)
			fprintf(f2,"%s %s %s %s %s %s\n",name,boucle,mal1,mal2,mal3,mal4);
        }
    fclose(f2);
    fclose(f4);
    remove("troupeau_malade.txt");
    rename("tmp2.txt","troupeau_malade.txt");
}

