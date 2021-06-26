#include "callbacks.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "planter.h"
#include <gtk/gtk.h>

enum
{
nom,
code,
type,
dateplantation,
etat,
stock,
COLUMN
};

int  ajouterp(plante p)
{
  int test;
  FILE*f;
plante a;
  f=fopen("plante.txt","a+");
  if (f!=NULL)
{
    while (fscanf(f,"%s %s %s %s %s %s \n ",a.nom, a.code , a.type , a.dateplantation , a.etat , a.stock)!=EOF)
 {        
        if((strcmp(a.code,p.code)==0))
            {
 		test=1;
                 return 1 ;
	    }
}
}
  if (test==0)
{
  fprintf(f,"%s %s %s %s %s %s \n ",p.nom, p.code , p.type , p.dateplantation , p.etat , p.stock);
  fclose(f);
 return 0;
}

}
void supprimerp(char code[] ,int test)
{

plante a ;
FILE*f;
FILE*g;
if (test==1)
{
g=NULL;
f=fopen("plante.txt","r");
g=fopen("reserve.txt","w");
if (f!=NULL)
{

while (fscanf(f,"%s %s %s %s %s %s \n ",a.nom, a.code , a.type , a.dateplantation, a.etat , a.stock)!=EOF)
 {

            if(strcmp(a.code,code)!=0)
            {
                fprintf(g,"%s %s %s %s %s %s \n ",a.nom, a.code , a.type , a.dateplantation , a.etat , a.stock);
                
        }
        


    }

    fclose(g);
    fclose(f);

     remove("plante.txt");
     rename("reserve.txt","plante.txt");
}}
 
}

void modifierp(plante p)
{

plante a ;
FILE *f;
FILE *g;
f=fopen("plante.txt","r");
g=fopen("reserve.txt","w");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s  \n ",a.nom, a.code , a.type , a.dateplantation ,  a.etat , a.stock)!=EOF)
 {

             if(strcmp(a.code,p.code)!=0)
            {
                fprintf(g,"%s %s %s %s %s %s  \n ",a.nom, a.code , a.type , a.dateplantation , a.etat , a.stock);

            }
            else if (strcmp(a.code,p.code)==0)
           {   
               
               fprintf(g,"%s %s %s %s %s %s \n ",p.nom, p.code , p.type , p.dateplantation , p.etat , p.stock);
            }

              
        


    }

     fclose(g);
     fclose(f);

     remove("plante.txt");
     rename("reserve.txt","plante.txt");
     
}}
int chercherp (char code[])

{ int test;
  plante a;
  FILE*f;
  f=fopen("plante.txt","r");
   test=0;
   if (f!=NULL)
{ 
     while (fscanf(f,"%s %s %s %s %s %s \n ",a.nom, a.code , a.dateplantation , a.type , a.etat , a.stock)!=EOF)
{
            if (strcmp(a.code,code)==0)
{    
                 test=1;
                 break;
              
}
}
}
if (test==0)
{
  return 0;
}
else
{ return 1;
}
}
void modp (char nom[],char code[],char dateplantation[], char type[] , char etat[] , char stock[] )
{

  plante a;
  FILE*f;
  f=fopen("plante.txt","r");
   if (f!=NULL)
{ 
     while (fscanf(f,"%s %s %s %s %s %s  \n ",a.nom, a.code , a.type , a.dateplantation , a.etat , a.stock)!=EOF)
{
            if (strcmp(a.code,code)==0)
{              
                 strcpy(nom,a.nom);
                 strcpy(type,a.type);
                strcpy(type,a.type);
		strcpy(dateplantation,a.dateplantation);
		strcpy(etat,a.etat);
		strcpy(stock,a.stock);
		
}
}}}

/*void ajouteremplois(emplois e)
{
FILE *f;
f=fopen("emplois.txt","a+");
fprintf(f,"%s %s %s %s %s %s %s \n ",e.lundi, e.mardi , e.mercredi , e.jeudi , e.vendredi , e.samedi , e.dimanche);
fclose(f);
}*/

void ajoutermessage(message m)
{
FILE *f;
f=fopen("messageadmin.txt","a+");
fprintf(f,"%s %s %s  \n ",m.Date, m.envoyeur , m.message);
fclose(f);
}





