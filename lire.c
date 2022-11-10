#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lire(){

    FILE*  fichier = NULL;
    fichier = fopen("data.txt", "r");
    char ligne[300];
    char nom[20];
    char prenom[20];
    int age;
    char message[200];
    int taille;
    int touche;
    
    while (fgets(ligne, 300, fichier) != NULL) {
        taille = strlen(ligne);
        ligne[taille]='\n';
        ligne[taille+1]='\0';
        sscanf(ligne,"%s %s %d %[^\n]uhhhh", prenom,nom,&age,message);
        printf("\nMessage de %s %s (%d ans) : %s\n", prenom, nom, age, message ); 
    }
 
    fclose(fichier);

}