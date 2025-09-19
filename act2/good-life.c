/// http://www.dreamincode.net/forums/topic/55572-conways-game-of-life/
/// downloaded by copy-paste on 8/19/2015 and modified to use an infinite loop
/// and have different Rule functions.
///
/// This code needs serious work in these areas:
/// <ol>
/// <li>  syntax: there are a number of warnings that cause errors.
/// </li>
/// <li>  semantics: the game algorithm implementation is incorrect.
/// </li>
/// <li>  design: the implementation needs function and value refactoring.
/// </li>
/// <li>  style: formatting is poor; the mix of TAB and spaces indentation
/// needs correction, and spacing between tokens is inconsistent.
/// The course style puts the '{' at the end of the function header, not
/// on a line of its own. You should make the formatting consistent.
/// </li>
/// <li>  documentation: documentation is non-existent except for this block.
/// </li> @author Jack Dudley
/// </ol>
///

#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
#define GENERATIONS 50
void header(void) {
   printf("\n\t..Welcome to the Game of life..\n");
}

void survival_rule(int size, char life[][size]) { // fix 4, removed unused x and y params
   int row, col;
   for(row = 0; row<SIZE; row++) {
      for(col = 0; col<SIZE; col++) {
         int neighbors = calculate_neighbors(row, col, life);
         if(neighbors == 2 || neighbors == 3) {
            life[row][col] = '*'; // fix 2: uses == instead of = operator, doesn't assign a value to the array. fixed.
         }
      }
   }
   return;
}

void birth_rule(int size, char life[][size]) { // fix 3 removed unused params x and y
   int row, col;
   for(row = 0; row<SIZE; row++) {
      for(col = 0; col<SIZE; col++) {
         int neighbors = calculate_neighbors(row, col, life);
         if(neighbors == 3){
            life[row][col] = '*'; // fix 2: uses == instead of = operator, doesn't assign a value to the array. fixed.
         }
      }
   }
   return;
}

int calculate_neighbors(int row, int col, char life[][SIZE]) {
   int neighbors = 0;
   if(life[row][col] == ' ') {
      int up = (row-1 + SIZE) % SIZE;
      int down = (row+1 + SIZE) % SIZE;
      int left = (col-1 + SIZE) % SIZE;
      int right = (col+1 + SIZE) % SIZE;
      if(life[up][col] == '*')
         neighbors++;
      if(life[up][right] == '*')
         neighbors++;
      if(life[row][right] == '*')
         neighbors++;
      if(life[down][right] == '*')
         neighbors++;
      if(life[down][col] == '*')
         neighbors++;
      if(life[down][left] == '*')
         neighbors++;
      if(life[row][left] == '*')
         neighbors++;
      if(life[up][left] == '*')
         neighbors++;
   }
   return neighbors;
}


int main(int argc, char *args[]) {
   char life[SIZE][SIZE];
   int orgs; // fix 4 removed unused variable gens
   int i, row, col; // fix 4 removed unused variable a, b
   int count = 0;
   // fix 4 removed unused variable ans
   if (argc != 2) { 
      return 1; 
   }
   header();

   // convert command line argument to an int
   orgs = strtol( args[1], NULL, 10 );

   srand( 31 );

   for(i = 0; i<orgs; i++) {
      row = rand();
      row %= SIZE;
      col = rand();
      col %= SIZE;
      life[row][col] = '*'; // fix 2: uses == instead of = operator, doesn't assign a value to the array. fixed.
   }

   for(row = 0; row<SIZE; row++) {
      for(col = 0; col<SIZE; col++) {
         if(life[row][col] != '*') {
            life[row][col] = ' '; // fix 2: uses == instead of = operator, doesn't assign a value to the array. fixed.
         }
      }
   }

   for(row = 0; row<SIZE; row++) {
      for(col = 0; col<SIZE; col++) {
         printf("%c", life[row][col]); // fix 1: changed %s to %c because the array is a character array
      }
      puts(" ");
   }

   for (int i = 1; i<=GENERATIONS; i++) {
      birth_rule(SIZE, life); // fix 5 fixed function call to not use unused vars
      survival_rule(SIZE, life); // fix 5 fixed function call to not use unused vars
      for(row = 0; row<SIZE; row++) {
         for(col = 0; col<SIZE; col++) {
            printf("%c", life[row][col]); // fix 1: changed %s to %c because the array is a character array
         }
         puts(" ");
      }
      printf("\ngeneration: %d\n", count);
      count++;
   }
   return 0;
}

