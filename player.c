// add the needed C libraries below
#include <stdbool.h> // bool, true, false
#include <stdlib.h> // rand

// look at the file below for the definition of the direction type
// pacman.h must not be modified!
#include "pacman.h"

// ascii characters used for drawing levels
extern const char PACMAN; // ascii used for pacman
extern const char WALL; // ascii used for the walls
extern const char PATH; // ascii used for the explored paths
extern const char DOOR; // ascii used for the ghosts' door
extern const char VIRGIN_PATH; // ascii used for the unexplored paths
extern const char ENERGY; // ascii used for the energizers
extern const char GHOST1; // ascii used for the ghost 1
extern const char GHOST2; // ascii used for the ghost 2
extern const char GHOST3; // ascii used for the ghost 3
extern const char GHOST4; // ascii used for the ghost 4

// reward (in points) when eating dots/energizers 
extern const int VIRGIN_PATH_SCORE; // reward for eating a dot
extern const int ENERGY_SCORE; // reward for eating an energizer

// put the student names below (mandatory)
const char * binome="ALLANIC Victor, ARNAUD Thomas";

// put the prototypes of your additional functions/procedures below

#include <stdio.h> // printf
#include <time.h> // time(NULL)

void cases_accessibles(int *, int, int, int, int, char * * ); // Ne surtout pas aller dans un mur
void dernier_coup(int *, direction); // Eviter de retourner d'où l'on vient
void fantomes_proches(int *, int, int, int, int, char * *, bool); // Fuir les fantômes les plus proches ou les poursuivre selon l'invincibilité de pacman, en ligne
void grains_proches(int *, int, int, int, int, char * *); // Aller vers les grains les plus proches , en ligne
void indice_meilleure_direction(int *, int *); // Déterminer la meilleure direction après avoir fini d'analyser l'état de la carte via les procédures précédentes
void choix_direction(direction *, int ); // Rentrer cette direction dans la variable d

// change the pacman function below to build your own player
// your new pacman function can use as many additional functions/procedures as needed; put the code of these functions/procedures *AFTER* the pacman function
direction pacman(
		 char * * map, // the map as a dynamic array of strings, ie of arrays of chars
		 int xsize, // number of columns of the map
		 int ysize, // number of lines of the map
		 int x, // x-position of pacman in the map
		 int y, // y-position of pacman in the map
		 direction lastdirection, // last move made by pacman (see pacman.h for the direction type; lastdirection value is -1 at the beginning of the game
		 bool energy, // is pacman in energy mode? 
		 int remainingenergymoderounds // number of remaining rounds in energy mode, if energy mode is true
		 ) {
  direction d; // the direction to return

  int directions[4] = {0, 0, 0, 0}; //tableau de compteurs chaque direction {NORTH, EAST, SOUTH, WEST}
  int indice_max; //pour l'indice de la meilleure direction du tableau directions
  
  cases_accessibles(directions, x, y, xsize, ysize, map); 
  dernier_coup(directions, lastdirection); 
  fantomes_proches(directions, x, y, xsize, ysize, map, energy); 
  grains_proches(directions, x, y, xsize, ysize, map);
  indice_meilleure_direction(directions, &indice_max); 
  choix_direction(&d, indice_max); 

  return d; // answer to the game engine
}

// the code of your additional functions/procedures must be put below

void cases_accessibles(
     int* tab, // tableau des compteurs pour chaque direction {NORTH, EAST, SOUTH, WEST}
     int x, // position x de pacman sur la carte
     int y, // position y de pacman sur la carte
     int xsize, // nombre de colonnes de la carte
     int ysize, // nombre de lignes de la carte
     char ** map // la carte en tant que tableau dynamique de caractères
     ) { 
  
  //Case accessible au nord ?
  if(y == 0 || (y>0 && map[y - 1][x] != WALL && map[y - 1][x] != DOOR)) tab[0] = 100;
  
  //Case accessible à l'est ?
  if(x == xsize - 1 || (x < xsize - 1 && map[y][x + 1] != WALL && map[y][x + 1] != DOOR)) tab[1] = 100;
  
  //Case accessible au sud ?
  if(y == ysize - 1 || (y < ysize - 1 && map[y + 1][x] != WALL && map[y + 1][x] != DOOR)) tab[2] = 100;
  
  //Case accessible à l'ouest ?
  if(x == 0 || (x > 0 && map[y][x - 1] != WALL && map[y][x - 1] != DOOR)) tab[3] = 100; 
}

void dernier_coup(
     int*tab, // tableau des compteurs pour chaque direction {NORTH, EAST, SOUTH, WEST}
     direction derniercoup // variable contenant la direction du dernier déplacement de pacman
     ) {
  switch (derniercoup) {
  case NORTH :
    //tab[0] += 1;
    tab[2] -= 1;
    break;
  case EAST :
    //tab[1] += 1;
    tab[3] -= 1;
    break;
  case SOUTH :
    //tab[2] += 1;
    tab[0] -= 1;
    break;
  case WEST :
    //tab[3] += 1;
    tab[1] -= 1;
    break;
  }
}

void fantomes_proches(
     int* tab, // tableau des compteurs pour chaque direction {NORTH, EAST, SOUTH, WEST}
     int x, // position x de pacman sur la carte
     int y, // position y de pacman sur la carte
     int xsize, // nombre de colonnes de la carte
     int ysize, // nombre de lignes de la carte
     char ** map, // la carte en tant que tableau dynamique de caractères
     bool energy // pacman est-il invincible ?
     ) {
  
  int px = x;
  int py = y;

  //Fantôme au nord ?
  while(map[py][px] != WALL && py != 0){
    if (map[py][px] == GHOST1 || map[py][px] == GHOST2 || map[py][px] == GHOST3 || map[py][px] == GHOST1 ){
      if (energy) tab[0] += 10 - (y - py) ;
      else tab[0] -= 10 - (y - py) ;
      break;
    }
    py -= 1;

  }
  py = y;

  //Fantôme a l'est ?
  while(map[py][px] != WALL && px != xsize - 1){
    if (map[py][px] == GHOST1 || map[py][px] == GHOST2 || map[py][px] == GHOST3 || map[py][px] == GHOST1  ){
      if (energy) tab[1] += 10- (px-x) ;
      else tab[1] -= 10 - (px -x) ;
      break;
    }
    px += 1;
  }
  px = x;
  
  //Fantôme au sud ?
  while(map[py][px] != WALL && py != ysize - 1){
    if (map[py][px] == GHOST1 || map[py][px] == GHOST2 || map[py][px] == GHOST3 || map[py][px] == GHOST1  ){
      if (energy) tab[2] += 10 - (py-y) ;
      else tab[2] -= 10 - (py-y) ;
      break;
    }
    py += 1;
  }
  py = y;

  //Fantôme a l'ouest ?
  while(map[py][px] != WALL && px != 0){
    if (map[py][px] == GHOST1 || map[py][px] == GHOST2 || map[py][px] == GHOST3 || map[py][px] == GHOST1 ){
      if (energy) tab[3] +=10 - (x-px)  ;
      else tab[3] -= 10 -(x-px) ;
      break;
    }
    px -= 1;
  }
  px = x;

  //Fantôme diagonale nord est
  if(map[y - 1][x + 1] == GHOST1 || map[y - 1][x + 1] == GHOST2 || map[y - 1][x + 1] == GHOST3 || map[y - 1][x + 1] == GHOST4) {
    tab[0] -= 8;
    tab[1] -= 8;
  }
  //Fantôme diagonale sud est
  if(map[y + 1][x + 1] == GHOST1 || map[y + 1][x + 1] == GHOST2 || map[y + 1][x + 1] == GHOST3 || map[y + 1][x + 1] == GHOST4) {
    tab[1] -= 8;
    tab[2] -= 8;
  }
  //Fantôme diagonale sud ouest
  if(map[y + 1][x - 1] == GHOST1 || map[y + 1][x - 1] == GHOST2 || map[y + 1][x - 1] == GHOST3 || map[y + 1][x - 1] == GHOST4) {
    tab[2] -= 8;
    tab[3] -= 8;
  }
  //Fantôme diagonale nord ouest
  if(map[y - 1][x - 1] == GHOST1 || map[y - 1][x - 1] == GHOST2 || map[y - 1][x - 1] == GHOST3 || map[y - 1][x - 1] == GHOST4) {
    tab[3] -= 8;
    tab[0] -= 8;
  }
}

void grain_proches(
     int* tab, // tableau des compteurs pour chaque direction {NORTH, EAST, SOUTH, WEST}
     int x, // position x de pacman sur la carte
     int y, // position y de pacman sur la carte
     int xsize, // nombre de colonnes de la carte
     int ysize, // nombre de lignes de la carte
     char ** map // la carte en tant que tableau dynamique de caractères
     ) {
    
  int px = x;
  int py = y;

  //Grain au nord ?
  while(map[py][px] != WALL && py != 0){
    if (map[py][px] == VIRGIN_PATH || map[py][px] == ENERGY) {
      tab[0] += 10 - (y - py);
      break;
    }
    py -= 1;
  }
  py = y;

  //Grain à l'est ?
  while(map[py][px] != WALL && px != xsize - 1){
    if (map[py][px] == VIRGIN_PATH || map[py][px] == ENERGY) {
      tab[1] += 10 - (px -x);
      break;
    }
    px += 1;
  }
  px = x;
  
  //Grain au sud ?
  while(map[py][px] != WALL && py != ysize - 1){
    if (map[py][px] == VIRGIN_PATH || map[py][px] == ENERGY) {
      tab[2] += 10 - (py-y);
      break;
    }
    py += 1;
  }
  py = y;

  //Grain à l'ouest ?
  while(map[py][px] != WALL && px != 0){
    if (map[py][px] == VIRGIN_PATH || map[py][px] == ENERGY) {
      tab[3] += 10 -(x-px);
      break;
    }
    px -= 1;
  }
  px = x;

  //Grain diagonale nord est
  if(map[y - 1][x + 1] == VIRGIN_PATH || map[y - 1][x + 1] == ENERGY) {
    tab[0] += 8;
    tab[1] += 8;
  }
  //Grain diagonale sud est
  if(map[y + 1][x + 1] == VIRGIN_PATH || map[y + 1][x + 1] == ENERGY) {
    tab[1] += 8;
    tab[2] += 8;
  }
  //Grain diagonale sud ouest
  if(map[y + 1][x - 1] == VIRGIN_PATH || map[y + 1][x - 1] == ENERGY) {
    tab[2] += 8;
    tab[3] += 8;
  }
  //Grain diagonale nord ouest
  if(map[y - 1][x - 1] == VIRGIN_PATH || map[y - 1][x - 1] == ENERGY) {
    tab[3] += 8;
    tab[0] += 8;
  }
}

void indice_meilleure_direction(
     int* tab, // tableau des compteurs pour chaque direction {NORTH, EAST, SOUTH, WEST}
     int* pos_indice_max // adresse de l'indice du tableau directions correspondant au meilleur choix, que l'on va déterminer ici.
     ) {
  
  int m = 0;
  int k = 0;
  srand (time(NULL));

  for (k = 0; k < 4; k++) {

    if (tab[k] > m) {
      m = tab[k];
      *pos_indice_max = k;
    }

    else if (tab[k] == m && rand() % 2 == 0) {
      m = tab[k];
      *pos_indice_max = k;
    }
  
  }

}

void choix_direction(
     direction* adresse_d, // variable d de type direction que l'on va renvoyer à la fin du programme.
     int im // indice du tableau directions correspondant au meilleur choix
     ) {

  direction TAB[4] = {NORTH, EAST, SOUTH, WEST};
  *adresse_d = TAB[im];

}
 
