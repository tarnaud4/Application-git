#include <stdio.h>
#include <stdlib.h>
#include "puissance4.c"
#include "message.c"
#include "lire.c"
#include "justeprix.c"
#include "pendu.c"
#include "morpion.c"
#include "sinscrire.c"
#include "seconnecter.c"

int main(){
    int choix=1;
    while (choix!=0){ // Pour revenir au menu a la fin de chaque jeux.

    /* Rajoute ton jeu au print*/
        printf("\n---------------------\n");
        printf("A quoi voulez vous jouer ? \n\n 1. Morpion \n 2. Puissance4\n 3. Juste Prix\n 4. Pendu\n\n 11. Envoyer un message\n 12. Lire les messages \n\n 21. Inscription\n 22. Connexion \n\n  0. STOP \n\nMon choix : ");        scanf("%d",&choix);

    /* Rajoute un case au switch*/
        switch(choix) {

        case 1 :
            printf("\n Choix 1 : Morpion\n\n");
            morpion();
            break;
        
        case 2 :
            printf("\n Choix 2 : Puissance4\n");
            puissance4();
            break;
        
        case 3:
            printf("\n Choix 3 : Juste Prix\n");
            justeprix();
            break;

        case 4:
            printf("\n Choix 4 : Pendu\n");
            pendu();
            break;
        
        
        
        case 11:
            printf("\n Choix 11 : Envoyer un message\n");
            message();
            break;

        case 12:
            printf("\n Choix 12 : Lire les messages\n");
            lire();
            break;

        case 21:
            printf("\n Choix 22 : Inscription\n");
            sinscrire();    
            break;
        
    
        case 22:
            printf("\n Choix 22 : Connexion\n");
            seconnecter();
            break;
        }

    }
    return 0;
        
}