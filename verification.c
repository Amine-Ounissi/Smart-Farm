#include "verification.h"
#include "callbacks.h"
#include <gtk/gtk.h>
void TirerPar(char tirer_par[20]);
void get_max_date(char *min_date[20]);
int verif_entry_date(int j,int taille_jour,char mois[20],int a,int taille_annee);
void changer_name(char boucle[10],char name[10]);
void tri_tab(long T[],int T2[],int n);
void get_mois2(int mois,char *mois_char)
{
	if (mois==1) strcpy(mois_char,"Janvier");
	if (mois==2) strcpy(mois_char,"Fevrier");
	if (mois==3) strcpy(mois_char,"Mars");
	if (mois==4) strcpy(mois_char,"April");
	if (mois==5) strcpy(mois_char,"Mai");
	if (mois==6) strcpy(mois_char,"Juin");
	if (mois==7) strcpy(mois_char,"Juillet");
	if (mois==8) strcpy(mois_char,"Aout");
	if (mois==9) strcpy(mois_char,"Semptembre");
	if (mois==10) strcpy(mois_char,"Octobre");
	if (mois==11) strcpy(mois_char,"Novembre");
	if (mois==12) strcpy(mois_char,"Decembre");
}

int verif_boucle(char ch[],int a)
{
	int i,age;
	char name[20],boucle[20],sexe[20],date[20],sante[20];
	for (i=0;i<strlen(ch);i++)
	{
		if ((ch[i]<48)||(ch[i]>57))
			return 0;
	
	}
	if (strcmp(ch,"")==0)
		return 0;
	if (a==1){
		FILE *f;
		f=fopen("troupeau.txt","a+");	
		f=fopen("troupeau.txt","r");
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
			if (strcmp(boucle,ch)==0)
				return 0;
	}
		
	
return 1;		
}

void TirerPar(char tirer_par[20])
{
	FILE* f,*f2;
	int age;
	char name[20],boucle[20],sexe[20],date[20],sante[20];
	if (strcmp(tirer_par,"Name")==0){
		f=fopen("troupeau.txt","r");
		f2=fopen("Name.txt","a+");
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
			if (strcmp(name,"Brebi")==0)	
				fprintf(f2,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);
		fclose(f);
		f=fopen("troupeau.txt","r");
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
			if (strcmp(name,"Mouton")==0)	
				fprintf(f2,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);
		fclose(f);
		f=fopen("troupeau.txt","r");
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
			if (strcmp(name,"Vache")==0)	
				fprintf(f2,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);
		fclose(f);
		f=fopen("troupeau.txt","r");
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF)
			if (strcmp(name,"Veau")==0)	
				fprintf(f2,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);
		fclose(f);
		fclose(f2);
	}
	else if (strcmp(tirer_par,"Sexe")==0){
		f=fopen("troupeau.txt","r");
		f2=fopen("Sexe.txt","a+");
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF){
			if (strcmp(sexe,"Femelle")==0)	
				fprintf(f2,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);}
		fclose(f);
		f=fopen("troupeau.txt","r");
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF){
			if (strcmp(sexe,"Male")==0)	
				fprintf(f2,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);}
		fclose(f);
		fclose(f2);}
	else if (strcmp(tirer_par,"Sante")==0){	
		f=fopen("troupeau.txt","r");
		f2=fopen("Sante.txt","a+");
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF){
			if (strcmp(sante,"Bonne")==0)	
				fprintf(f2,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);}
		fclose(f);
		f=fopen("troupeau.txt","r");
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF){
			if (strcmp(sante,"Malade")==0)	
				fprintf(f2,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);}
		fclose(f);
		fclose(f2);}
	else if (strcmp(tirer_par,"Date naissance")==0){
				
		char date2[20],*jour[3],*mois[20],*annee[5];;
		int i=0,tab2[200],a,m,j;
		long tab[200];
		FILE *f,*f2;
		f=fopen("troupeau.txt","r");					
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF){
			
			strcpy(date2,date);
			get_date(&jour,&mois,&annee,date2);
			a=atoi(annee);
			m=get_mois(mois);
			j=atoi(jour);
			tab[i]=a*10000+m*100+j;
			tab2[i]=atoi(boucle);
			i++;
		}
		fclose(f);
		
		tri_tab(tab,tab2,i);
		f2=fopen("Date naissance.txt","a+");
		j=0;
		while (i!=j){
			f=fopen("troupeau.txt","r");
			while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF){
				if (atoi(boucle)==tab2[j])					
					fprintf(f2,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);
			}fclose(f);
		j++;}
		fclose(f2);	
	}
	else if (strcmp(tirer_par,"Boucle")==0){
		char date2[20],*jour[3],*mois[20],*annee[5];;
		int i=0,tab2[200],a,m,j;
		long tab[200];
		FILE *f,*f2;
		f=fopen("troupeau.txt","r");					
		while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF){
			tab[i]=atoi(boucle);
			i++;
		}
		fclose(f);
		tri_tab(tab,tab2,i);
		f2=fopen("Boucle.txt","a+");
		j=0;
		while (i!=j){
			f=fopen("troupeau.txt","r");
			while (fscanf(f,"%s %s %s %s %s\n",name,boucle,sexe,date,sante)!=EOF){
				if (atoi(boucle)==tab[j])					
					fprintf(f2,"%s %s %s %s %s\n",name,boucle,sexe,date,sante);
			}fclose(f);
		j++;}
		fclose(f2);
	}
}

void tri_tab(long T[],int T2[],int n)
{
    int i,j,min;
   long tampon;
    for (i=0;i<n-1;i++)
    {
         min=i ;
         for (j=i+1;j<n;j++)
            if (T[j]<T[min])
                min=j;

         tampon=T[i];
         T[i]=T[min];
         T[min]=tampon;
	tampon=T2[i];
         T2[i]=T2[min];
         T2[min]=tampon;
    }
}


int verif_entry_date(int j,int taille_jour,char mois[20],int a,int taille_annee)
{
	
	if (((j/10)<1)&&(taille_jour>1))
		return 1;
	if (((j/10)>=1)&&(taille_jour!=2))
		return 1;
	if ((j>31)||(j<1))
		return 1;

	if (taille_annee!=4)
		return 1;
	if ((a<2000)||(a>=2050))
		return 1;

	if ((strcmp(mois,"Janvier")!=0)&&(strcmp(mois,"Fevrier")!=0)&&(strcmp(mois,"Mars")!=0)&&(strcmp(mois,"April")!=0)&&(strcmp(mois,"Mai")!=0)&&(strcmp(mois,"Juin")!=0)&&(strcmp(mois,"Juillet")!=0)&&(strcmp(mois,"Septembre")!=0)&&(strcmp(mois,"Octobre")!=0)&&(strcmp(mois,"Novembre")!=0)&&(strcmp(mois,"Decembre")!=0))
		return 1;
	return 0;
}

void changer_name(char boucle[10],char name[10])
{
	FILE *f,*f2;
	char nom[20],boucle2[20],sexe[20],date[20],sante[20];
	if (strcmp(name,"Veau")==0){
		f=fopen("troupeau.txt","r");
		f2=fopen("tmp.txt","a+");
		while (fscanf(f,"%s %s %s %s %s\n",nom,boucle2,sexe,date,sante)!=EOF){
			if (strcmp(boucle2,boucle)!=0)
				fprintf(f2,"%s %s %s %s %s\n",nom,boucle2,sexe,date,sante);
			else fprintf(f2,"%s %s %s %s %s\n","Vache",boucle2,sexe,date,sante);}}
	else if (strcmp(name,"Vache")==0){
		f=fopen("troupeau.txt","r");
		f2=fopen("tmp.txt","a+");
		while (fscanf(f,"%s %s %s %s %s\n",nom,boucle2,sexe,date,sante)!=EOF){
			if (strcmp(boucle2,boucle)!=0)
				fprintf(f2,"%s %s %s %s %s\n",nom,boucle2,sexe,date,sante);
			else fprintf(f2,"%s %s %s %s %s\n","Veau",boucle2,sexe,date,sante);}}
	else if (strcmp(name,"Brebi")==0){
		f=fopen("troupeau.txt","r");
		f2=fopen("tmp.txt","a+");
		while (fscanf(f,"%s %s %s %s %s\n",nom,boucle2,sexe,date,sante)!=EOF){
			if (strcmp(boucle2,boucle)!=0)
				fprintf(f2,"%s %s %s %s %s\n",nom,boucle2,sexe,date,sante);
			else fprintf(f2,"%s %s %s %s %s\n","Mouton",boucle2,sexe,date,sante);}}
	else if (strcmp(name,"Vache")==0){
		f=fopen("troupeau.txt","r");
		f2=fopen("tmp.txt","a+");
		while (fscanf(f,"%s %s %s %s %s\n",nom,boucle2,sexe,date,sante)!=EOF){
			if (strcmp(boucle2,boucle)!=0)
				fprintf(f2,"%s %s %s %s %s\n",nom,boucle2,sexe,date,sante);
			else fprintf(f2,"%s %s %s %s %s\n","Brebi",boucle2,sexe,date,sante);}}
	fclose(f);fclose(f2);
	remove("troupeau.txt");
	rename("tmp.txt","troupeau.txt");


}
int verif_les_entry(char name1[20],char boucle1[20],char boucle2[20],char sexe1[20],char date1[20],char sante1[20])
{
	if ((strcmp(name1,"Veau")!=0)&&(strcmp(name1,"Brebi")!=0)&&(strcmp(name1,"Mouton")!=0)&&(strcmp(name1,"Vache")!=0))
		return 0;
	if ((strcmp(sante1,"Bonne")!=0)&&(strcmp(sante1,"Malade")!=0))
		return 0;
	if ((verif_boucle(boucle1,1)==0)&&(strcmp(boucle1,boucle2)!=0))
		return 0;
	if ((strcmp(sexe1,"Male")!=0)&&(strcmp(sexe1,"Femelle")!=0))
		return 0;
return 1;
}
