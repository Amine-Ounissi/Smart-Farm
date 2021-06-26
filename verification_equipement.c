#include "verification_equipement.h"
int get_utiliser(char utiliser[20])
{
	if (strcmp("A01",utiliser)==0) return 0;
	if (strcmp("A02",utiliser)==0) return 1;
	if (strcmp("A03",utiliser)==0) return 2;
	if (strcmp("B01",utiliser)==0) return 3;	
	if (strcmp("B02",utiliser)==0) return 4;
	if (strcmp("B03",utiliser)==0) return 5;
	if (strcmp("C01",utiliser)==0) return 6;
	if (strcmp("C02",utiliser)==0) return 7;
	if (strcmp("C03",utiliser)==0) return 8;
	if (strcmp("D01",utiliser)==0) return 9;
	if (strcmp("D02",utiliser)==0) return 10;
	if (strcmp("D03",utiliser)==0) return 11;
}
int existe_equi(char serie2[10],FILE *f)
{	char date[20],nom[20],made[20],utiliser[20],etat[20],serie[20];
	while (fscanf(f,"%s %s %s %s %s %s\n",nom,serie,made,date,utiliser,etat)!=EOF){
		if (strcmp(serie,serie2)==0)
			return 1;}
	
	return 0;
}

int verif_serie(char ch[20],int a)
{
	int i,b=1;
	char date[20];
	for (i=0;i<strlen(ch);i++)
	{
		if (((ch[i]<48)||(ch[i]>57))&&((ch[i]<65)||(ch[i]>90))&&((ch[i]<97)||(ch[i]>122)))
			return 1;}
	if (strcmp(ch,"")==0)
		return 1;
	if (a==1){
		FILE *f;
		f=fopen("equipement.txt","r");
		while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat)!=EOF){
			if (strcmp(e.serie,ch)==0){
				return 1;}}
		fclose(f);
	}
return 0;		
}
int find_var(FILE *f3,char var2[30])
{
	char var[30],serie[30];
	if (f3!=NULL)
		while (fscanf(f3,"%s %s\n",var,serie)!=EOF)
			if (strcmp(var,var2)==0){
				return 1;}
	return 0;
}

void get_max_var(FILE *f3,char *var_max[30])
{
	char var[30];
	FILE *f4;
	strcpy(var_max,"z");
	while (fscanf(f3,"%s %s\n",var,e.serie)!=EOF)
		if (strcmp(var_max,var)>0)
			strcpy(var_max,var);
	fclose(f3);
	f3=fopen("tmp.txt","a+");
	f4=fopen("tmp2.txt","a+");
	while (fscanf(f3,"%s %s\n",var,e.serie)!=EOF)
		if (strcmp(var_max,var)!=0)
			fprintf(f4,"%s %s\n",var,e.serie);
	fclose(f3);
	fclose(f4);
	remove("tmp.txt");
	rename("tmp2.txt","tmp.txt");
}

void TirerParEqui(char tirer_par[20])
{
	FILE* f,*f2,*f3;
	
	if (strcmp(tirer_par,"Date")!=0){
		char *var_max[30],date[30],var[30];
		f=fopen("equipement.txt","r");
		if (strcmp(tirer_par,"Nom")==0) f2=fopen("Nom.txt","a+");
			else{   if (strcmp(tirer_par,"S\303\251rie")==0) f2=fopen("S\303\251rie.txt","a+");
				else{   if (strcmp(tirer_par,"Made in")==0) f2=fopen("Made in.txt","a+");
					else{   if (strcmp(tirer_par,"Utiliser dans")==0) f2=fopen("Utiliser dans.txt","a+");
						else if (strcmp(tirer_par,"Etat")==0) f2=fopen("Etat.txt","a+");}}}
		int n=0,i=0;
		while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat)!=EOF){
			if (strcmp(tirer_par,"Nom")==0) strcpy(var,e.nom);
			else{   if (strcmp(tirer_par,"S\303\251rie")==0) strcpy(var,e.serie);
				else{   if (strcmp(tirer_par,"Made in")==0) strcpy(var,e.made);
					else{   if (strcmp(tirer_par,"Utiliser dans")==0) strcpy(var,e.utiliser);
						else if (strcmp(tirer_par,"Etat")==0) strcpy(var,e.etat);}}}
			f3=fopen("tmp.txt","a+");
			if (find_var(f3,var)==0){
				n++;
				fprintf(f3,"%s %s\n",var,e.serie);
				fclose(f3);}
			else fclose(f3);
		}
		fclose(f);
		while (n!=i){
			f=fopen("equipement.txt","r");
			i++;
			f3=fopen("tmp.txt","a+");
			get_max_var(f3,var_max);
			while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat)!=EOF){
				if (strcmp(tirer_par,"Nom")==0) strcpy(var,e.nom);
				else{   if (strcmp(tirer_par,"S\303\251rie")==0) strcpy(var,e.serie);
					else{   if (strcmp(tirer_par,"Made in")==0) strcpy(var,e.made);
						else{   if (strcmp(tirer_par,"Utiliser dans")==0) strcpy(var,e.utiliser);
							else if (strcmp(tirer_par,"Etat")==0) strcpy(var,e.etat);}}}
				if (strcmp(var_max,var)==0){
					fprintf(f2,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat);}
			}
			fclose(f);
		}
		fclose(f2);
		remove("tmp.txt");		
	}
	/*else {
		char date2[20],*jour[3],*mois[20],*annee[5];;
		int i=0,tab2[200],a,m,j;
		long tab[200];
		FILE *f,*f2;
		f=fopen("equipement.txt","r");					
		while (fscanf(f,"%s %s %s %s %s %s\n",e.nom,e.serie,e.made,date,e.utiliser,e.etat)!=EOF){
			strcpy(date2,date);
			get_date(&jour,&mois,&annee,date2);
			a=atoi(annee);
			m=atoi(mois);
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
	}*/
	/*else if (strcmp(tirer_par,"Sexe")==0){
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
	}*/
}
