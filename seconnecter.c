#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int ouvre(char***);
//void affiche( char**, int);
void requete(char*, char*);
int stregale(char*, char*);

void seconnecter(){
  char** tab;
  int taille;
  char idutilisateur[15];
  char mdputilisateur[15];
  int k;

  char nomligne[15];
  char prenomligne[15];
  int age;
  char idligne[15];
  char mdpligne[15];

  int connecte = 0;
  int l;

  

  taille = ouvre(&tab);
  //affiche(tab, taille);
  //printf("%s", tab[0]);
  do{
    requete(idutilisateur, mdputilisateur);
    for(k=0; k<taille; k++){
        sscanf(tab[k],"%s %s %d %s %s", &nomligne, &prenomligne, &age, &idligne, &mdpligne);
        //printf("%s, %s \n", idutilisateur, idligne);
        //printf("%d",connecte);
        if( stregale(idligne, idutilisateur) == 0 && stregale(mdpligne,mdputilisateur) == 0){
          l = k;
        connecte = 1;
        }
      }

      if (connecte == 1){
        sscanf(tab[l],"%s %s %d %s %s", &nomligne, &prenomligne, &age, &idligne, &mdpligne);
        printf("\nVous etes connecte %s %s\n", nomligne, prenomligne);

      }
      else{
        printf("\nMot de passe ou nom d'utilisateur incorrect, reessayez\n");
      }

      printf("\n\n----------------------------------------------------------------\n\n");
  }while(connecte != 1);
}

  
	 
int ouvre(char***tab){
  FILE* F;
  int nblignes=0;
  char ligne[81];
  F = fopen("datautilisateurs.txt", "r");
  *tab = NULL;
  if (F == NULL){
    printf("Problème lors de louverture\n");
  }
  else{
    while(feof(F) == false){

      //printf("%s",tab[i]);
      //printf("%s", ligne);
      fgets(ligne, 80, F);
      //printf("%s\n",ligne);
      nblignes += 1;
      //printf("%d\n", nblignes);
      
      *tab = realloc(*tab , nblignes * sizeof(char*));
      
      (*tab)[nblignes-1] = malloc(strlen(ligne) * sizeof(char));
      strcpy( (*tab)[nblignes-1], ligne);

    }
  }
  fclose(F);

  return nblignes;
    
  
}

/*void affiche(char** tab,int taille){
  int i;
  for (i = 0; i<taille-1; i++){
    printf("%s",tab[i]);
  }
}
*/

void requete(char* id, char* mdp){
  printf("\n\nID : ");
  scanf("%s", id);
  printf("Mot de passe : ");
  scanf("%s",mdp);

}
	    
int stregale(char* str1, char*str2){
  int k;
  int res = 0;
  if(strlen(str1) != strlen(str2)){
    res = 1;

  }
  for(k=0; k<strlen(str1); k++){
    if(str1[k] != str2[k]){
      res = 1;
    }
  }
  //printf("%d\n",res);
  return res;
}
  
