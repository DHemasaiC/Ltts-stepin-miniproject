/**
 * @file project_code.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include<stdlib.h>
//function prototypes
void Board_Display();
int checkposition(int,int);
void checkForWin();

//global variables
char game_board[ 8 ], playerWon = ' ';

int present_player = 0;

int main() {

    int index, position;    

    for(index = 0; index < 9; index++) game_board[ index ] = ' ';

    Board_Display();

    while(playerWon == ' ') {

       printf("\n%c\n", playerWon);

       if(present_player == 0 || present_player == 1) {

          printf("\nPlayer X\n");    
          printf("Enter an available square (1..9)");
          scanf("%d", &position);   

          if(checkposition(position, present_player) == 1)  {
 
             present_player = 1;
   
          } else {

             present_player = 2;
          }

       } else {

          printf("\nPlayer 0\n");
          printf("Enter an available square (1..9)");
          scanf("%d", &position);   


          if(checkposition(position, present_player) == 1)  {
 
             present_player = 2;
   
          } else {

             present_player = 1;
          }

       } 

       Board_Display();
       checkForWin();

    }//end for loop

 
   return (0);
};

void Board_Display() {

     system("cls");
     printf("\t|\t|\n");
     printf("%c\t|%c\t|%c\n", game_board[0], game_board[1], game_board[2]);
     printf("--------|-------|--------\n");
     printf("\t|\t|\n");
     printf("%c\t|%c\t|%c\n", game_board[3], game_board[4], game_board[5]);
     printf("--------|-------|--------\n");
     printf("%c\t|%c\t|%c\n", game_board[6], game_board[7], game_board[8]);
     printf("\t|\t|\n");
};

int checkposition(int position, int player) {

     if((player == 0 || player == 1) && game_board[position-1] == ' ') {

         game_board[ position - 1 ] = 'X';

         return 0;
     }

     else if(game_board[position-1] == ' ' && player == 2) {

          game_board[position-1] = 'O';

          return 0;

     } else 

       return 1;  
     
}

void checkForWin() {

     int index, 
         countforposition = 0;
 
     if(game_board[ 0 ] == 'X' && game_board[ 1 ] == 'X' && game_board[ 2 ] == 'X') {

        playerWon = 'X';

     } else if(game_board[ 3 ] == 'X' && game_board[ 4 ] == 'X' && game_board[ 5 ] == 'X') {

        playerWon = 'X';

     } else if(game_board[ 6 ] == 'X' && game_board[ 7 ] == 'X' && game_board[ 8 ] == 'X') {

        playerWon = 'X';

     } else if(game_board[ 0 ] == 'X' && game_board[ 3 ] == 'X' && game_board[ 6 ] == 'X') {

        playerWon = 'X';

     } else if(game_board[ 1 ] == 'X' && game_board[ 4 ] == 'X' && game_board[ 7 ] == 'X') {

        playerWon = 'X';

     } else if(game_board[ 2 ] == 'X' && game_board[ 5 ] == 'X' && game_board[ 8 ] == 'X') {

        playerWon = 'X';

     } else 

     if(game_board[ 0 ] == 'O' && game_board[ 1 ] == 'O' && game_board[ 2 ] == 'O') {

        playerWon = 'O';

     } else if(game_board[ 3 ] == 'O' && game_board[ 4 ] == 'O' && game_board[ 5 ] == 'O') {

        playerWon = 'O';

     } else if(game_board[ 6 ] == 'O' && game_board[ 7 ] == 'O' && game_board[ 8 ] == 'O') {

        playerWon = 'O';

     } else if(game_board[ 0 ] == 'O' && game_board[ 3 ] == 'O' && game_board[ 6 ] == 'O') {

        playerWon = 'O';

     } else if(game_board[ 1 ] == 'O' && game_board[ 4 ] == 'O' && game_board[ 7 ] == 'O') {

        playerWon = 'O';

     } else if(game_board[ 2 ] == 'O' && game_board[ 5 ] == 'O' && game_board[ 8 ] == 'O') {

        playerWon = 'O';

    }     

     //for diagonals
     if(game_board[ 0 ] == 'X' && game_board[ 4 ] == 'X' && game_board[ 8 ] == 'X') {

        playerWon = 'X';

     } else if(game_board[ 2 ] == 'X' && game_board[ 4 ] == 'X' && game_board[ 6 ] == 'X') {

        playerWon = 'X';
     }


     if(game_board[ 0 ] == 'O' && game_board[ 4 ] == 'O' && game_board[ 8 ] == 'O') {

        playerWon = 'O';

     } else if(game_board[ 2 ] == 'O' && game_board[ 4 ] == 'O' && game_board[ 6 ] == 'O') {

        playerWon = 'O';
     }


     if(playerWon == 'X') {

        printf("\nX WON\n");
        return; 
     }


     if(playerWon == 'O') {

        printf("\nO WON\n");
        return; 
     }


     for(index = 0; index < 9; index++) 
         if(game_board[index] != ' ') 
               countforposition++;
 
     if(countforposition == 9) {

        playerWon = 'C';
        printf("\nDRAW GAME\n");
        return;
     } 
     
}
