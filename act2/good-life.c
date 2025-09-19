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

void header(void) {
   printf("\n\t..Welcome to the Game of life..\n");
}

void survival_rule(int size, char life[][size]) { // fix 4, removed unused x and y params
   int row, col;
   int neighbors = 0;
   for(row = 1; row<19; row++) {
      for(col = 1; col<19; col++) {
         if(&life[row][col]== "*") {
            if(life[row - 1][col - 1] == '*')
               ++neighbors;
            if(life[row - 1][col] == '*')
               ++neighbors;
            if(life[row - 1][col + 1] == '*')
               ++neighbors;
            if(life[row][col - 1] == '*')
               ++neighbors;
            if(life[row][col + 1] == '*')
               ++neighbors;
            if(life[row + 1][col - 1] == '*')
               ++neighbors;
            if(life[row + 1][col] == '*')
               ++neighbors;
            if(life[row + 1][col + 1] == '*')
               ++neighbors;
            if(neighbors == 2 || neighbors == 3) {
               life[row][col] = '*'; // fix 2: uses == instead of = operator, doesn't assign a value to the array. fixed.
            }
         }
      }
   }
   return;
}

void birth_rule(int size, char life[][size]) { // fix 3 removed unused params x and y
   int row, col;
   int neighbors = 0;
   for(row = 1; row<19; row++) {
      for(col = 1; col<19; col++) {
         if(&life[row][col]== " ") {
            if(life[row - 1][col - 1] == '*')
               neighbors++;
            if(life[row - 1][col] == '*')
               neighbors++;
            if(life[row - 1][col + 1] == '*')
               neighbors++;
            if(life[row][col - 1] == '*')
               neighbors++;
            if(life[row][col + 1] == '*')
               neighbors++;
            if(life[row + 1][col - 1] == '*')
               neighbors++;
            if(life[row + 1][col] == '*')
               neighbors++;
            if(life[row + 1][col + 1] == '*')
               neighbors++;
            if(neighbors == 3){
               life[row][col] = '*'; // fix 2: uses == instead of = operator, doesn't assign a value to the array. fixed.
            }
         }
      }
   }
   return;
}


int main(int argc, char *args[]) {
   char life[20][20];
   int orgs; // fix 4 removed unused variable gens
   int i, row, col; // fix 4 removed unused variable a, b
   int count = 0;
   int x = 19;
   int y = 19;
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
      row %= 20;
      col = rand();
      col %= 20;
      life[row][col] = '*'; // fix 2: uses == instead of = operator, doesn't assign a value to the array. fixed.
   }

   for(row = 0; row<20; row++) {
      for(col = 0; col<20; col++) {
         if(life[row][col] != '*') {
            life[row][col] = ' '; // fix 2: uses == instead of = operator, doesn't assign a value to the array. fixed.
         }
      }
   }

   for(row = 0; row<20; row++) {
      for(col = 0; col<20; col++) {
         printf("%c", life[row][col]); // fix 1: changed %s to %c because the array is a character array
      }
      puts(" ");
   }

   for (int i = 1; i<=51; i++) {
      birth_rule(20, life); // fix 5 fixed function call to not use unused vars
      survival_rule(20, life); // fix 5 fixed function call to not use unused vars
      for(row = 0; row<20; row++) {
         for(col = 0; col<20; col++) {
            printf("%c", life[row][col]); // fix 1: changed %s to %c because the array is a character array
         }
         puts(" ");
      }
      printf("\ngeneration: %d\n", count);
      count++;
   }
   return 0;
}

