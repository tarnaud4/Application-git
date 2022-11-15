//Pendu

/*
On peut ptet separer les cas lettre deja dite / lettre pas dans le mot avec juste un tableau en plus de lettres dites
J'ai rajouté un fichier texte avec tous les mots valides au scrabble, ça peut faire une banque plus vaste si c'est aléatoire genre
Et on pourrait alors choisir la longueur du mot, en triant cette immense liste (j'y songerai)
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void trouvemot(char* str);
int nombremot();

void pendu(){
    
    char mot[20] = "";
    char motc[20] = "";
    int lettretrouve = 0 ;
    int i;
    char lettrechoisie;
    int taille = 0;
    int nbessai = 10;
    int marque = 0;
    int choix = 1;
    int choixbis;
    
    do{
        nbessai = 10;
        
        printf("--------------------------------------------\n\n Choisir un mode de jeu : \n\n 1. Donner le mot\n\n 2. Mot aleatoire  \n\n Mon choix : ");
        scanf("%d", &choixbis);

        if (choixbis == 2){
            trouvemot(mot); //trouve aléatoirement notre mot parmis la banque de mot
        }
        if (choixbis == 1){
            printf("\n\nDonne le mot a trouver (met une lettre en plus a la fin du mot)  : ");
            scanf("%s", mot);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        }
        taille = strlen(mot) - 1;
            
        for( i = 0; i < taille; i++ ){
            motc[i] = '*';
        }
        
        printf("\n Nous cherchons un mot de la forme %s (ce mot fait %d lettres)\n", motc, taille);

        do{
            printf("\n ---------------------------------------------\n");
            printf("\n Quelle lettre as-tu choisie ?");
            scanf(" %c", &lettrechoisie);
            marque = 0;
            for (i = 0; i < taille; i++){
                if(lettrechoisie == mot[i] && motc[i] == '*'){
                    lettretrouve++;
                    motc[i] = mot[i];
                    marque = 1;
                }
            }
            if (marque == 1){
                printf("\nJuste ! il te reste %d essai(s)", nbessai);
            }
            else{
                printf("\nFaux ! la lettre n'est pas dans le mot, ou deja proposee auparavant, il te reste %d essai(s)", nbessai);
                nbessai--;
            }
            printf("\n\n Etat du mot : %s",motc);
            

        }while(lettretrouve != taille && nbessai >= 0);

        if (lettretrouve == taille){
            printf("\n ---------------------------------------------\n\n\n                   Victoire !\n\n\n ---------------------------------------------\n");
        }
        
        else {
            printf("\n ---------------------------------------------\n\n\n    Perdu ! Le mot etait : %s\n\n\n ---------------------------------------------\n",mot);
        }

        printf("\n\n Rejouer ? (0 = non, 1 (ou autre) = oui) : ");
        scanf("%d", &choix);
        lettretrouve = 0;

    }while(choix != 0);

    



}

void trouvemot(mot){

    char* tab = mot;
    FILE*  fichier = NULL; //ajout d'un fichier
    fichier = fopen("datapendu.txt", "r");//ouverture du fichier data pendu en lecture

    srand( time(NULL) );//Initialisation de srand
    int nb = nombremot();
    int ialeatoire = rand() % nb;
    int i = 0;
    char caractere;
    
    if (fichier == NULL){
        printf("Problème lors de l'ouverture data");
    }
    else{
        
        do{
            caractere = fgetc(fichier);
            if (caractere == ' '){
                i++;                
            }
        }while(i<ialeatoire);

        i = 0;
        
        do{
            caractere = fgetc(fichier);
            tab[i] = caractere;
            i++;
        }while( caractere != ' ');


    }
}

int nombremot(){
    FILE*  fichier = NULL; //ajout d'un fichier
    fichier = fopen("datapendu.txt", "r");//ouverture du fichier data pendu en lecture
    int nbmot = 0;
    char caractereactuel;
    do {
        caractereactuel = fgetc(fichier);
        if (caractereactuel == ' '){
            nbmot++;
        }
        
    }while (caractereactuel != EOF);

    fclose(fichier);

    return nbmot;
}

