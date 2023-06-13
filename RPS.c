#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int player_two_global_var =
    0; // This has to be a global variable because it stores a randomized number
       // which is generated within a function, which means it would be
       // undeclared when the function is called upon.


char player_one_output();

char player_two_output(int player_two);

int players_choice_comparison(char p1_choice, char p2_choice,
                              int *p1_points_ptr, int *p2_points_ptr);

void score_comparison(int p1_score, int p2_score, int *repeat_var2,
                      int win_amt);


int zero;

int main() {
  srand(time(NULL));
  int win_amount; // How many wins a player can have until someone wins
  int repeat_var = 1;
  int player_two_repeat =
      1; // part of code which helps to make sure user enters 1 or 2 to choose
         // computer or person to play against
  int player_one_score;
  int player_two_score;
  int player_two; // the variable that allows users to play against a computer
                  // or another person
  char player_one_choice;
  char player_two_choice;
  
printf("\n\n");
                                                                                                       
printf("@@@@@@@   @@@@@@@    @@@@@@                    @@@@@@@@@@    @@@@@@   @@@@@@@   @@@@@@@@  \n");
printf("@@@@@@@@  @@@@@@@@  @@@@@@@                    @@@@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@ \n");
printf("@@!  @@@  @@!  @@@  !@@             @@!        @@! @@! @@!  @@!  @@@  @@!  @@@  @@! \n" );      
printf("!@!  @!@  !@!  @!@  !@!             !@!        !@! !@! !@!  !@!  @!@  !@!  @!@  !@! \n");    
printf("@!@!!@!   @!@@!@!   !!@@!!       @!@!@!@!@     @!! !!@ @!@  @!@  !@!  @!@!!@!   @!!!:! \n" );  
printf("!!@!@!    !!@!!!     !!@!!!      !!!@!@!!!     !@!   ! !@!  !@!  !!!  !!@!@!    !!!!!:\n" );   
printf("!!: :!!   !!:            !:!        !!:        !!:     !!:  !!:  !!!  !!: :!!   !!:  \n" );   
printf(":!:  !:!  :!:           !:!         :!:        :!:     :!:  :!:  !:!  :!:  !:!  :!: \n" );     
printf("::   :::   ::       :::: ::                    :::     ::   ::::: ::  ::   :::   :: :::: \n" );
printf(" :   : :   :        :: : :                      :      :     : :  :    :   : :  : :: :: \n"  );   
  
printf("\n\n");


  printf("Welcome to RocK 🪨, Paper 📄, Scissors ✂️  plus MORE! \n\n");
  /*k*/ printf("RULES\n\n");
  /*k*/ printf("1) To start you will enter the amount of points one must "
               "achieve to be labeled the WINNER! \n");
  /*k*/ printf(
      "2) Select 1 to play against a friend or 2 to play against the CPU. \n");
  /*k*/ printf("3) R = rock, P = paper, S = scissors, T = take, M = match, Z = zero, OR...\n");
  /*k*/ printf("**************************\n\n");

  printf("Enter the amount of points needed to claim VICTORY!");
  scanf(" %d", &win_amount);

  while (repeat_var == 1) {
    player_one_score = 0;
    player_two_score = 0;
    player_two;
    player_one_choice = '0';
    player_two_choice = '0';

    while (player_two_repeat == 1) { // makes sure user enters a valid number
      printf("1. Human\n2. Computer\nPlease enter 1 or 2 : ");
      scanf(" %d", &player_two);
      if ((player_two == 1) || (player_two == 2)) {
        player_two_repeat = 0;
      } else {
        printf("\e[1;1H\e[2J");
        printf("ERROR: PLEASE ENTER 1 OR 2\n");
        sleep(1);
      }
    }
    while ((player_one_score < win_amount) && (player_two_score < win_amount)) {
      player_one_choice =
          player_one_output(); // calls on function (player_one_choice)
      player_two_choice = player_two_output(
          player_two); // calls on function (player_two_choice)

      printf("Player 1 : %c\nPlayer 2 : %c\n", player_one_choice,
             player_two_choice); // prints both choices so players can compare
      players_choice_comparison(
          player_one_choice, player_two_choice, &player_one_score,
          &player_two_score); // compares players choices and increases the
                              // winners points or prints 'tie'

      printf("Player 1 score : %d\nPlayer 2 score : %d\n\n", player_one_score,
             player_two_score);
      score_comparison(player_one_score, player_two_score, &repeat_var,
                       win_amount); // checks to see if there is a winner yet

      if (repeat_var == 2) {
        break;
      }
    }
  }
  return 0;
}

// Functions below
char player_one_output() {
  char player_one_choice;
  int continue_var1 = 0;
  while (continue_var1 == 0) {
    printf("Player 1: Please enter R, P, or S or an alternative option: ");
    scanf(" %c", &player_one_choice);
    player_one_choice = toupper(player_one_choice);
    if ((player_one_choice == 'R') || (player_one_choice == 'P') ||
        (player_one_choice == 'S') || (player_one_choice == 'M') || (player_one_choice == 'Z') || (player_one_choice == 'F') || (player_one_choice == 'T')) {
      continue_var1 = 1;
    } else {
      printf("INVALID INPUT!!! \n");
    }
  }
  printf("\e[1;1H\e[2J");
  return player_one_choice;
}

char player_two_output(int player_two) {
  int temp;
  int tempory_rand_num;
  int repeat_var = 0;
  char player_two_choice;
  int continue_var2 = 0;

  if (player_two == 1) {
    while (continue_var2 == 0) {
      printf("Player 2: Please enter R, P, S, or an alternative option: ");
      scanf(" %c", &player_two_choice);
      player_two_choice = toupper(player_two_choice);
      if ((player_two_choice == 'R') || (player_two_choice == 'P') ||
          (player_two_choice == 'S') || (player_two_choice == 'M') || (player_two_choice == 'Z') || (player_two_choice == 'F') ||(player_two_choice == 'T')) {
        continue_var2 = 1;
      } else {
        printf("Invalid Input : \n");
      }
    }
  } else if (player_two == 2) {

    while (repeat_var ==
           0) { // makes sure different random numbers are generated each time
      tempory_rand_num = rand();

      if (tempory_rand_num == player_two_global_var) {
        tempory_rand_num = rand();
      } else {
        repeat_var = 1;
      }
    }
    player_two_global_var = temp;
    temp = tempory_rand_num % 3;

    if (temp == 0) {
      player_two_choice = 'R';
    } else if (temp == 1) {
      player_two_choice = 'P';
    } else if (temp == 2) {
      player_two_choice = 'S';
    }
  }
  printf("\e[1;1H\e[2J");
  return player_two_choice;
}

int players_choice_comparison(char p1_choice, char p2_choice,
                              int *p1_points_ptr, int *p2_points_ptr) {



  if (p1_choice == 'R') {
    if (p2_choice == 'R') {
      printf("Tie!\n");
    } else if (p2_choice == 'P') {
      printf("Player 2 Wins This Round!\n");
      *p2_points_ptr += 1;
    } else if (p2_choice == 'S') {
      printf("Player 1 Wins This Round!\n");
      *p1_points_ptr += 1;
    } else if (p2_choice == 'M') {
      printf("Player 2 has matched Player 1 points\n");
     *p2_points_ptr = *p1_points_ptr;
    }  else if (p2_choice == 'Z') {
      printf("Player 2 made Player 1 have zero points, ouch!\n");
      *p1_points_ptr = zero;
    } else if (p2_choice == 'F') {
      printf("Player 2 Wins This Round!\n");
      *p2_points_ptr += 1;
    } else if (p2_choice == 'T') {
      printf("Player 2 stole a point\n");
      *p2_points_ptr += 1;
      *p1_points_ptr -= 1;
    }
  } else if (p1_choice == 'P') {
    if (p2_choice == 'R') {
      printf("Player 1 Wins This Round!\n");
      *p1_points_ptr += 1;
    } else if (p2_choice == 'P') {
      printf("Tie!\n");
    } else if (p2_choice == 'S') {
      printf("Player 2 Wins This Round!\n");
      *p2_points_ptr += 1;
    } else if (p2_choice == 'M') {
      printf("Player 2 has matched Player 1 points\n");
      *p2_points_ptr = *p1_points_ptr;
    } else if (p2_choice == 'Z') {
      printf("Player 2 made Player 1 have zero points, ouch!\n");
      *p1_points_ptr = zero;
    }  else if (p2_choice == 'F') {
      printf("Player 2 Wins This Round!\n");
      *p2_points_ptr += 1;
    } else if (p2_choice == 'T') {
      printf("Player 2 stole a point\n");
      *p2_points_ptr += 1;
      *p1_points_ptr -= 1;
    }
  } else if (p1_choice == 'S') {
    if (p2_choice == 'R') {
      printf("Player 2 Wins This Round!\n");
      *p2_points_ptr += 1;
    } else if (p2_choice == 'P') {
      printf("Player 1 Wins This Round!\n");
      *p1_points_ptr += 1;
    } else if (p2_choice == 'S') {
      printf("Tie!\n");
    } else if (p2_choice == 'M') {
      printf("Player 2 has matched Player 1 points\n");
      *p2_points_ptr = *p1_points_ptr;
    }  else if (p2_choice == 'Z') {
      printf("Player 2 made Player 1 have zero points, ouch!\n");
      *p1_points_ptr = zero;
    } else if (p2_choice == 'F') {
      printf("Player 2 Wins This Round!\n");
      *p2_points_ptr += 1;
    } else if (p2_choice == 'T') {
      printf("Player 2 stole a point\n");
      *p2_points_ptr += 1;
      *p1_points_ptr -= 1;
      }
    } else if (p1_choice == 'T') {
    if (p2_choice == 'P') {
        printf("Player 1 stole a point!\n");
        *p1_points_ptr += 1; 
        *p2_points_ptr -= 1;
    } else if (p2_choice == 'R') {
        printf("Player 1 stole a point!\n");
        *p1_points_ptr += 1; 
        *p2_points_ptr -= 1;
    } else if (p2_choice == 'S') {
        printf("Player 1 stole a point!\n");
        *p1_points_ptr += 1; 
        *p2_points_ptr -= 1; 
    } else if (p2_choice == 'M') {
      printf("Oops taking and matching aren't allowed together!\n");
    }  else if (p2_choice == 'Z') {
      printf("Oops zero and taking aren't allowed together!\n");
    } else if (p2_choice == 'F') {
      printf("Player 2 Wins This Round!\n");
      *p2_points_ptr += 1;
    } else if (p2_choice == 'T') {
      printf("Tie!\n");
    }
  } else if (p1_choice == 'M') {
    if (p2_choice == 'P') {
      printf("Player 1 has matched Player 2 points\n");
      *p1_points_ptr = *p2_points_ptr;
      } else if (p2_choice == 'R') {
      printf("Player 1 has matched Player 2 points\n");
      *p1_points_ptr = *p2_points_ptr;
      } else if (p2_choice == 'S') {
      printf("Player 1 has matched Player 2 points\n");
      *p1_points_ptr = *p2_points_ptr;
      } else if (p2_choice == 'T') {
      printf("Oops taking and matching aren't allowed together!\n");
      }  else if (p2_choice == 'Z') {
      printf("Oops zero and matching aren't allowed together!\n");
    } else if (p2_choice == 'F') {
      printf("Player 2 Wins This Round!\n");
      *p2_points_ptr += 1;
    } else if (p2_choice == 'M') {
      printf("Tie\n");
      } 
    } else if (p1_choice == 'Z') {
    if (p2_choice == 'P') {
      printf("Player 1 made Player 2 have zero points, ouch!\n");
      *p2_points_ptr = zero;
      } else if (p2_choice == 'R') {
      printf("Player 1 made Player 2 have zero points, ouch!\n");
      *p2_points_ptr = zero;
      } else if (p2_choice == 'S') {
      printf("Player 1 made Player 2 have zero points, ouch!\n");
      *p2_points_ptr = zero;
      } else if (p2_choice == 'T') {
      printf("Oops zero and matching aren't allowed together!\n");
      }  else if (p2_choice == 'F') {
      printf("Player 2 Wins This Round\n!");
      *p2_points_ptr += 1;
      } else if (p2_choice == 'Z') {
      printf("Tie!\n");
    } else if (p2_choice == 'M') {
      printf("Oops zero and matching aren't allowed together!\n");
    } 
  }  else if (p1_choice == 'F') {
    if (p2_choice == 'P') {
      printf("Player 1 Wins This Round!\n");
      *p1_points_ptr += 1;
      } else if (p2_choice == 'R') {
      printf("Player 1 Wins This Round!\n");
      *p1_points_ptr += 1;
      } else if (p2_choice == 'S') {
      printf("Player 1 Wins This Round!\n");
      *p1_points_ptr += 1;
      } else if (p2_choice == 'T') {
      printf("Player 1 Wins This Round!\n");
      *p1_points_ptr += 1;
      }  else if (p2_choice == 'Z') {
      printf("Player 1 Wins This Round!\n");
     *p1_points_ptr += 1;
      }else if (p2_choice == 'M') {
      printf("Player 1 Wins This Round!\n");
      *p1_points_ptr += 1;
    } else if (p2_choice == 'F') {
      printf("Tie!\n");
    }
    }
  
  printf("\n**************************\n\n");
}

void score_comparison(int p1_score, int p2_score, int *repeat_var2,
                      int win_amt) {
  int temp;
  if (p1_score == win_amt) {
     printf("**************************\n\n");
    printf("Player One WINS!\n\n");
    printf("Would you like to play again\n");
    printf("1. Yes\n2. No\nPlease enter 1 or 2 : ");
    scanf(" %d", &temp);
  } else if (p2_score == win_amt) {
    printf("**************************\n\n");
    printf("Player Two WINS!\n\n");
    printf("Would you like to play again\n");
    printf("1. Yes\n2. No\nPlease enter 1 or 2 : ");
    scanf(" %d", &temp);
  }  
  *repeat_var2 = temp;
}
