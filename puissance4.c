//Puissance 4

#include<stdio.h>
#include<stdlib.h>

void initialise(char A[6][7] );
void affiche(char A[6][7]);
int detecte(char joueur, int i, int j, char A[6][7]);
int pose (char joueur, int j, char A[6][7]);

void puissance4(){
    int v;
    char j1 = 'X';
    char j2 = '0';
    int nbcoup = 0;
    int coupj;
    int coupi;
    char G[6][7];
    initialise(G);
    affiche(G);
    while(nbcoup <= 7 * 6 || v != 1){
        printf("\n joueur 1, ou veux-tu jouer ? : ");
        scanf("%d", &coupj);
        coupi = pose(j1, coupj,G);
        v = detecte(j1, coupi, coupj, G);
        nbcoup++ ;
        affiche(G);
        if (v == 1){
            printf("\n -------------------- \n\n LE JOUEUR 1 GAGNE ! \n\n -------------------- \n");
            break;
        }
        printf("\n joueur 2, ou veux-tu jouer ? : ");
        scanf("%d", &coupj);
        coupi = pose(j2, coupj, G);
        v = detecte(j2, coupi, coupj, G);
        nbcoup++ ;
        affiche(G);
        if (v == 1){
            printf("\n -------------------- \n\n LE JOUEUR 2 GAGNE ! \n\n -------------------- \n");
            break;
        }
    }    
    if (v = 0){
            printf("\n -------------------- \n\n PERSONNE NE GAGNE ! \n\n -------------------- \n");
      
    }
}

void initialise(char A[6][7]){
    int i;
    int j;
    for (i = 0; i < 6; i++){
        for (j = 0; j < 7; j++){
            A[i][j] = '.';
        }
    }
}

void affiche(char A[6][7]){
    int i;
    int j;
    printf("\n || PUISSANCE 4 DE THOMAS || \n\n     ");
    for (i = 0; i < 6; i++){
        for (j = 0; j < 7 ; j++){
            printf("%c  ", A[i][j]);
        }
        printf("\n     ");
    }    
    printf("--------------------\n C:  0  1  2  3  4  5  6");
}

int detecte(char joueur, int i, int j, char A[6][7]){
    int v = 0;
    //3 gauche
    if (j-3 >= 0 && A[i][j-1]==joueur && A[i][j-2]==joueur && A[i][j-3]==joueur ){
        v = 1;
    }
    //2 gauche 1droite
    if (j-2 >= 0 && j+1 <=6 && A[i][j+1]==joueur && A[i][j-1]==joueur && A[i][j-2]==joueur ){
        v = 1;
    }
    //1 gauche 2 droite
    if (j-1 >= 0 && j+2 <=6 && A[i][j+2]==joueur && A[i][j+1]==joueur && A[i][j-1]==joueur ){
        v = 1;
    }
    //3 droite
    if (j+3 <=6 && A[i][j+3]==joueur && A[i][j+2]==joueur && A[i][j+1]==joueur ){
        v = 1;
    }
    //3 haut
    if (i-3 >= 0 && A[i-1][j]==joueur && A[i-2][j]==joueur && A[i-3][j]==joueur ){
        v = 1;
    }
    //2haut 1bas
    if (i-2 >= 0 && i+1 <= 5 && A[i-1][j]==joueur && A[i-2][j]==joueur && A[i+1][j]==joueur ){
        v = 1;
    }
    //1haut 2bas
    if (i-1 >= 0 && i+2 <= 5 && A[i-1][j]==joueur && A[i+2][j]==joueur && A[i+1][j]==joueur ){
        v = 1;
    }
    //3 bas 
    if (i+3 <= 5 && A[i+1][j]==joueur && A[i+2][j]==joueur && A[i+3][j]==joueur ){
        v = 1;
    }
    //Diag montante 3gauche 
    if (j-3>=0 && i+3<=5 && A[i+1][j-1]==joueur && A[i+2][j-2]==joueur  && A[i+3][j-3]==joueur ){
        v = 1;
    }
    //Diag montante 2gauche 1 droite
    if (j-2>=0 && i+2<=5 && j+1<=6 && i-1>= 0 && A[i+1][j-1]==joueur && A[i+2][j-2]==joueur  && A[i-1][j+1]==joueur ){
        v = 1;
    }
    //Diag montante 1gauche 2droite
    if (j-1>=0 && i+1<=5 && j+2<=6 && i-2>= 0 && A[i+1][j-1]==joueur && A[i-2][j+2]==joueur  && A[i-1][j+1]==joueur ){
        v = 1;
    }
    //diag montante 3droite
    if (j+3<=6 && i-3>= 0 && A[i-3][j+3]==joueur && A[i-2][j+2]==joueur  && A[i-1][j+1]==joueur ){
        v = 1;
    }
    //Diag descendente 3gauche 
    if (j-3>=0 && i-3>=0 && A[i-1][j-1]==joueur && A[i-2][j-2]==joueur && A[i-3][j-3]==joueur){
        v = 1;
    }
    //Diag descendente 2gauche 1 droite
    if (j-2>=0 && i-2>=0 && j+1 <= 6 && i+1 <= 5 && A[i-1][j-1]==joueur && A[i-2][j-2]==joueur && A[i+1][j+1]==joueur){
        v = 1;
    }
    //Diag descendente 1gauche 2droite
    if (j-1>=0 && i-1>=0 && j+2 <= 6 && i+2 <= 5 && A[i-1][j-1]==joueur && A[i+2][j+2]==joueur && A[i+1][j+1]==joueur){
        v = 1;
    }
    //diag descendente 3droite
    if (j+3 <= 6 && i+3 <= 5 && A[i+3][j+3]==joueur && A[i+2][j+2]==joueur && A[i+1][j+1]==joueur){
        v = 1;
    }
    return v;
}

int pose(char joueur, int j, char A[6][7]){
    int p = 0;
    while (A[5-p][j] != '.'){
        p++;
    }
    A[5-p][j] = joueur;
    return (5-p);
}