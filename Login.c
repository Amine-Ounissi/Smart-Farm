#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Login.h"
int Login(char identifiant[20],char mot[20],int tend)
{
	FILE *f;
	int a;
	char entry1[20],entry2[20];
	if (tend==1){
		f=fopen("Login admin.txt","r");
		a=1;}
	else {
		f=fopen("Login ouvrier.txt","r");
		a=2;}
	g_print("%d",a);
	while (fscanf(f,"%s %s\n",entry1,entry2)!=EOF)
		if ((strcmp(identifiant,entry1)==0)&&(strcmp(mot,entry2)==0)){
			fclose(f);			
			return a;}
	fclose(f);	
	
	return 0;

}
