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

int calculate_neighbors(int row, int col, int size, char life[][size]) {
   int neighbors = 0;
   int up = (row-1 + size) % size;
   int down = (row+1 + size) % size;
   int left = (col-1 + size) % size;
   int right = (col+1 + size) % size;
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
   return neighbors;
}

void birth_survival_rules(int size, char life[][size]) { // fix 4, removed unused x and y params
   int row, col;
   char rules_array[size][size];
   for(int i = 0; i<size; i++) {
      for(int c = 0; c<size; c++) {
         rules_array[i][c] = life[i][c];
      }
   }
   for(row = 0; row<size; row++) {
      for(col = 0; col<size; col++) {
         int neighbors = calculate_neighbors(row, col, size, life);
         if(life[row][col] == ' ') {
            if(neighbors == 3) {
               rules_array[row][col] = '*';
            }
         } else {
            if(!(neighbors == 2 || neighbors == 3)) {
               rules_array[row][col] = ' '; // fix 2: uses == instead of = operator, doesn't assign a value to the array. fixed.
            }
         }
      }
   }
   return;
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

