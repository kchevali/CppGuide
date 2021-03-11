/*
  ---------------------------------------------------------------------
  Title: Branching
  Developer:Kevin Chevalier
  Labels: if, else, else if, conditonals
  Difficulty:Easy
  ---------------------------------------------------------------------

  =====================================================================
  Description
  =====================================================================
    Branching is changing the order of the code being executed based on conditions.

  =====================================================================
  Notes
  =====================================================================
  - This program will look at the branching statements: 'if', 'else if' and 'else'.
  - The condition of the statement is a boolean.
  - These branching statements are chained together.
  - Syntax:

        // X,Y,Z are boolean statements.
        if(X) {
            // CODE A - run if X is true.
        } else if(Y) {
            // CODE B - run if X is false and Y is true.
        } else if(Z) {
            // CODE C - run if X and Y are false and Z is true.
        } else {
            // CODE D - run if X, Y, and Z are false.
        }

  - 'if': the statement is true -> run code (required; always used first; only once).
  - 'else if': the previous statements are not true but this one is -> run code (optional; used second; multiple allowed).
  - 'else': the previous statements are not true -> run code (optional; used last; only once).
  - Branching is similar to loops, where conditions are used determine how many times to run the code.
  - Switch statements function similar to branching, but compares a single statement to several cases.

*/

#include <stdbool.h>
#include <stdio.h>

int main() {
  // Examples

  // When the condition equals 'true', the following code A within '{}' will run.
  if (true) {
    printf("A - RUNS\n");
  }

  // The condition is false, so the code B will not run.
  if (false) {
    printf("B - NO\n");
  }

  // This is a chain of branching statements.
  // The first statement is true so C will run and D will not.
  if (true) {
    printf("C - RUNS\n");
  } else {
    printf("D - NO\n");
  }

  // Weather Example
  int temperature = 80;  // Feel free to change this number.
  printf("The temperature %d is ", temperature);

  // Check if the temperature variable is greater or equal to 90.
  // If it is then it will execute ONLY the first statement.
  // If it is NOT then it will check the next statement.
  if (temperature >= 90) {
    printf("HOT\n");

    // Check if the temperature variable is less than 65.
    // If it is then it will execute ONLY the second statement.
    // If it is NOT then move on to the next statement.
  } else if (temperature < 65) {
    printf("CHILLY\n");

    // If none of the previous statements are true than the temperture must be between [65, 90).
  } else {
    printf("PERFECT\n");
  }

  // Outputting links for further learning.
  printf("\n\n*Learn more*\n============\n-Loops: src/getting_started/loops.cpp\n-Switch: src/fundamentals/switch.c\n-Scope: src/fundamentals/scope.c\n");
}