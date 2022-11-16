#include<stdio.h>
#include<stdlib.h>

void sinscrire(){
    char nom[15];
    char prenom[15];
    char age[15];
    char identifiant[15];
    char motdepasse[15];

    printf("\n\n ------- INSCRIPTION --------\n\n");
    printf("\nNOM : ");
    scanf("%s", nom);
    printf("\nPRENOM : ");
    scanf("%s", prenom);
    printf("\nAGE : ");
    scanf("%s", age);
    printf("\nIDENTIFIANT : ");
    scanf("%s", identifiant);
    printf("\nMOT DE PASSE : ");
    scanf("%s", motdepasse);    

    printf("%s %s %s %s %s",nom, prenom, age, identifiant, motdepasse);

    FILE*  fichier = NULL;
    fichier = fopen("datautilisateurs.txt", "a");

    if (fichier != NULL){
        fprintf(fichier, "\n%s %s %s %s %s", nom, prenom, age, identifiant, motdepasse);
        fclose(fichier);
        printf("\n L'inscripition s'est bien deroulee.\n");
    }

    else{
        printf("\nProblème lors de l'ouverture du fichier.\n");
    }





    
}