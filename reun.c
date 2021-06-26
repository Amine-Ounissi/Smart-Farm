 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reun.h"

#include <gtk/gtk.h>
#include <support.h>


enum
{
  ID_REUN,
  DATE,
 
  DESC,
  COLUMNS
};


int reun_add(GtkWidget *validate){
  int r = -2;
  
  GtkWidget *entry51;
  GtkWidget *button91;
  GtkWidget *spinbutton1;
  GtkWidget *spinbutton2;
  GtkWidget *spinbutton3;
  GtkWidget *agenda;
  GtkWidget *spinbutton4;
 GtkWidget *spinbutton5;

  reun new_reun;

  agenda = lookup_widget(validate,"agenda");
  
  entry51 = lookup_widget(agenda,"entry51");
  spinbutton1 = lookup_widget(agenda,"spinbutton1");
  spinbutton2 = lookup_widget(agenda,"spinbutton2");
  spinbutton3 = lookup_widget(agenda,"spinbutton3");
  spinbutton4 = lookup_widget(agenda,"spinbutton4");
  spinbutton5 = lookup_widget(agenda,"spinbutton5");

  char formatedDesc[150];
  strcpy(formatedDesc,gtk_entry_get_text(GTK_ENTRY(entry51)));
  replaceSpace(formatedDesc);
  strcpy(new_reun.ID_reun,"default");
  sprintf(new_reun.ID_reun, "%d", reun_generateID());
  new_reun.jj = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton1));
  new_reun.mm = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton2));
  new_reun.aaaa = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton3));
  
  new_reun.role_staff = 3; 
  strcpy(new_reun.desc,formatedDesc);
    FILE* f;
    f = fopen("reunion.txt","a+");
    if (f != NULL){
      fprintf(f,"%s %d/%d/%d %d %s\n", new_reun.ID_reun,new_reun.jj, new_reun.mm, new_reun.aaaa,  new_reun.role_staff, new_reun.desc);
      fclose(f);
      r=0;
  }
  else
  { r = -1;
    printf("ERROR : Failed to open file reunion.txt !");
  }
  
  return r;
};

void reun_show(GtkWidget *liste){
  GtkCellRenderer *renderer;
  	GtkTreeViewColumn *column;
  	GtkTreeIter    iter;
  	GtkListStore *store;

  	char id_reun [15];
  	char date [25];	
    int role_staff;
    char desc[60];
    store=NULL;

    FILE *f;

  	store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
  	if (store==NULL)
  	{

      renderer = gtk_cell_renderer_text_new ();
  		column = gtk_tree_view_column_new_with_attributes("ID reun", renderer, "text",ID_REUN, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

  		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",DATE, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

  		
  		renderer = gtk_cell_renderer_text_new ();
  		column = gtk_tree_view_column_new_with_attributes("Description", renderer, "text",DESC, NULL);
  		gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column);

  	}


  	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING);

  	f = fopen("reunion.txt", "r");

  	if(f==NULL)
  	{

  		return;
  	}
  	else

  	{ f = fopen("reunion.txt", "a+");
                while(fscanf(f,"%s %s %d %s \n",id_reun, date, &role_staff, desc)!=EOF)
  		{
  	gtk_list_store_append (store, &iter);
  	gtk_list_store_set (store, &iter, ID_REUN, id_reun, DATE, date,DESC,desc, -1);
  		}
  		fclose(f);
    	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
      g_object_unref (store);
  	}
};


void reun_update(GtkWidget *validate){
FILE  *old, *new;
reun to_keep;
reun update;


GtkWidget *entry51;
GtkWidget *entry52;
GtkWidget *button91;
GtkWidget *spinbutton1;
GtkWidget *spinbutton2;
GtkWidget *spinbutton3;
GtkWidget *agenda;

agenda = lookup_widget(validate,"agenda");

entry51 = lookup_widget(agenda,"entry51");
entry52 = lookup_widget(agenda,"entry52");
spinbutton1 = lookup_widget(agenda,"spinbutton1");
spinbutton2 = lookup_widget(agenda,"spinbutton2");
spinbutton3 = lookup_widget(agenda,"spinbutton3");

char formatedDesc[150];
strcpy(formatedDesc,gtk_entry_get_text(GTK_ENTRY(entry51)));
replaceSpace(formatedDesc);

strcpy(update.ID_reun,gtk_entry_get_text(GTK_ENTRY(entry52)));

update.jj = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton1));
update.mm = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton2));
update.aaaa = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spinbutton3));

update.role_staff = 3; //CURRENT_USER.ROLE
strcpy(update.desc,formatedDesc);

old = fopen("reunion.txt","a+");
new = fopen("reunion2.txt","a+");
if(old != NULL){
  while(fscanf(old,"%s %d/%d/%d  %d %s\n", to_keep.ID_reun, &to_keep.jj, &to_keep.mm, &to_keep.aaaa,  &to_keep.role_staff, to_keep.desc)!=EOF){
    if (strcmp(to_keep.ID_reun,update.ID_reun)!=0)
      fprintf(new,"%s %d/%d/%d  %d %s\n", to_keep.ID_reun, to_keep.jj, to_keep.mm, to_keep.aaaa,  to_keep.role_staff, to_keep.desc);
    else
      fprintf(new,"%s %d/%d/%d  %d %s\n", update.ID_reun, update.jj, update.mm, update.aaaa, update.role_staff, update.desc);

  }
  fclose(old);
  fclose(new);
  remove("reunion.txt");
  rename("reunion2.txt","reunion.txt");
}
else{
  printf("ERROR : Could not open file reunion.txt !");
    }
};



void reun_delete(char id[5]) {
  FILE  *old, *new;
  reun to_keep;
  old = fopen("reunion.txt","a+");
  new = fopen("reunion2.txt","a+");
  if(old != NULL){
    while(fscanf(old,"%s %d/%d/%d %d %s\n", to_keep.ID_reun, &to_keep.jj, &to_keep.mm, &to_keep.aaaa, &to_keep.role_staff, to_keep.desc)!=EOF){
      if (strcmp(to_keep.ID_reun,id)!=0)
        fprintf(new,"%s %d/%d/%d %d %s\n", to_keep.ID_reun, to_keep.jj, to_keep.mm, to_keep.aaaa, to_keep.role_staff, to_keep.desc);
    }
    fclose(old);
    fclose(new);
    remove("reunion.txt");
    rename("reunion2.txt","reunion.txt");
  }
  else{
    printf("ERROR : Could not open file reunion.txt !");
  }
};


int reun_generateID(){
  int id = 111;
  int id_reun;
  char date [15];

  int role_staff;
  char desc[150];

	FILE* f;
	f=fopen("reunion.txt", "r");
	if(f!=NULL)
	{

		  while(fscanf(f,"%d %s %d %s\n",&id_reun,date,&role_staff,desc)!=EOF)
		{
				id = id_reun + 13;
		}
	}else{
		printf("ERROR : Could not open file reunion.txt !\n");
	}
  return id;
}

void replaceSpace(char str[]){
  int n = strlen(str);
  int i;
  for(i=0; i<n; i++){
    if (str[i]==' ')
      str[i]='_';
  }
}

void reun_widget_add_show(GtkWidget *agenda){

  
  GtkWidget *label165;
  GtkWidget *label166;
  GtkWidget *label167;

  GtkWidget *entry51;
  GtkWidget *button91;
  GtkWidget *button94;
  GtkWidget *spinbutton1;
  GtkWidget *spinbutton2;
  GtkWidget *spinbutton3;
  GtkWidget *spinbutton4;
  GtkWidget *spinbutton5;
  
  label165 = lookup_widget(agenda,"label165");
  label166 = lookup_widget(agenda,"label166");
  label167 = lookup_widget(agenda,"label167");
  
  entry51 = lookup_widget(agenda,"entry51");
  button91 = lookup_widget(agenda,"button91");
  button94 = lookup_widget(agenda,"button94");
  spinbutton1 = lookup_widget(agenda,"spinbutton1");
  spinbutton2 = lookup_widget(agenda,"spinbutton2");
  spinbutton3 = lookup_widget(agenda,"spinbutton3");
  spinbutton4 = lookup_widget(agenda,"spinbutton4");
  spinbutton5 = lookup_widget(agenda,"spinbutton5");
 

 
  gtk_widget_show(label165);
  gtk_widget_show(label166);
  gtk_widget_show(label167);

  gtk_widget_show(entry51);
  gtk_widget_show(button91);
  gtk_widget_show(button94);
  gtk_widget_show(spinbutton1);
  gtk_widget_show(spinbutton2);
  gtk_widget_show(spinbutton3);
  gtk_widget_show(spinbutton4);
  gtk_widget_show(spinbutton5);
  
}

void reun_widget_delete_show(GtkWidget *agenda){

  GtkWidget *button168;
  GtkWidget *entry52;
  GtkWidget *button93;
  GtkWidget *button94;

  button168 = lookup_widget(agenda,"button168");
  entry52 = lookup_widget(agenda,"entry52");
  button93 = lookup_widget(agenda,"button93");
  button94 = lookup_widget(agenda,"button94");

  gtk_widget_show(button168);
  gtk_widget_show(entry52);
  gtk_widget_show(button93);
  gtk_widget_show(button94);
}

void reun_widget_edit_show(GtkWidget *agenda){

  GtkWidget *button92;

  button92 = lookup_widget(agenda,"button92");

  gtk_widget_show(button92);

  
  GtkWidget *button165;
  GtkWidget *button166;
  GtkWidget *button167;
  GtkWidget *button168;
 
  GtkWidget *entry51;
  GtkWidget *entry52;
  GtkWidget *spinbutton1;
  GtkWidget *spinbutton2;
  GtkWidget *spinbutton3;
  GtkWidget *spinbutton4;
  GtkWidget *spinbutton5;

  GtkWidget *button94;

  
  button165 = lookup_widget(agenda,"button165");
  button166 = lookup_widget(agenda,"button166");
  button167 = lookup_widget(agenda,"button167");
  button168 = lookup_widget(agenda,"button168");
 
  entry51 = lookup_widget(agenda,"entry51");
  entry52 = lookup_widget(agenda,"entry52");
  spinbutton1 = lookup_widget(agenda,"spinbutton1");
  spinbutton2 = lookup_widget(agenda,"spinbutton2");
  spinbutton3 = lookup_widget(agenda,"spinbutton3");
  spinbutton4 = lookup_widget(agenda,"spinbutton4");
  spinbutton5 = lookup_widget(agenda,"spinbutton5");
  
  button94 = lookup_widget(agenda,"button94");

 
  gtk_widget_show(button165);
  gtk_widget_show(button166);
  gtk_widget_show(button167);
  gtk_widget_show(button168);
 
  gtk_widget_show(entry51);
  gtk_widget_show(entry52);
  gtk_widget_show(spinbutton1);
  gtk_widget_show(spinbutton2);
  gtk_widget_show(spinbutton3);
  gtk_widget_show(spinbutton4);
  gtk_widget_show(spinbutton5);
 
  gtk_widget_show(button94);
}

void reun_widget_hide_all(GtkWidget *agenda){

 
  GtkWidget *button165;
  GtkWidget *button166;
  GtkWidget *button167;
  GtkWidget *button168;

  GtkWidget *spinbutton1;
  GtkWidget *spinbutton2;
  GtkWidget *spinbutton3;
  GtkWidget *spinbutton4;
  GtkWidget *spinbutton5;

 
  GtkWidget *entry51;
  GtkWidget *entry52;

  GtkWidget *button91;
  GtkWidget *button94;
  GtkWidget *button93;
  GtkWidget *button92;


  
  button165 = lookup_widget(agenda,"button165");
  button166 = lookup_widget(agenda,"button166");
  button167 = lookup_widget(agenda,"button167");
  button168 = lookup_widget(agenda,"button168");

  spinbutton1 = lookup_widget(agenda,"spinbutton1");
  spinbutton2 = lookup_widget(agenda,"spinbutton2");
  spinbutton3 = lookup_widget(agenda,"spinbutton3");
  spinbutton4 = lookup_widget(agenda,"spinbutton4");
  spinbutton5 = lookup_widget(agenda,"spinbutton5");

  
  entry51 = lookup_widget(agenda,"entry51");
  entry52 = lookup_widget(agenda,"entry52");

  button91 = lookup_widget(agenda,"button91");
  button94 = lookup_widget(agenda,"button94");
  button93 = lookup_widget(agenda,"button93");
  button92 = lookup_widget(agenda,"button92");


  
  gtk_widget_hide(button165);
  gtk_widget_hide(button166);
  gtk_widget_hide(button167);
  gtk_widget_hide(button168);

  gtk_widget_hide(spinbutton1);
  gtk_widget_hide(spinbutton2);
  gtk_widget_hide(spinbutton3);
  gtk_widget_hide(spinbutton4);
  gtk_widget_hide(spinbutton5);

  
  gtk_widget_hide(entry51);
  gtk_widget_hide(entry52);

  gtk_widget_hide(button91);
  gtk_widget_hide(button94);
  gtk_widget_hide(button93);
  gtk_widget_hide(button92);
}

void set_mode(GtkWidget *window, int mode){
  GtkWidget *label;
  label = lookup_widget(window,"label171");
  char text[80];
  switch (mode){
    case 1:
      strcpy(text,"Ajouter une reunion :");
      break;

    case 2:
      strcpy(text,"Modifier une reunion :");
      break;

    case 3:
      strcpy(text,"Supprimer une reunion :");
      break;

    default:
      printf("ERROR while setting mode !");
      strcpy(text,"ERROR");
    }
    gtk_label_set_text(label,text);
  }



