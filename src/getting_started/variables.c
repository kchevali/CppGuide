/*
  ---------------------------------------------------------------------
  Title: Variables and Statements
  Developer:Kevin Chevalier
  Labels:variables, statements, constants, assignment_operator(=)
  Difficulty:Easy
  ---------------------------------------------------------------------

  =====================================================================
  Description
  =====================================================================
    Statements are general executable code and the result may be stored in a variable.

  =====================================================================
  Notes
  =====================================================================
  - Statements are code that are evaluated to a certain value.
  - These values have different data types depending on the kind of value it is (numbers, text, and more...).
  - A variable is a container of a value and the data type of the container must match the value.
  - The assignment operator (aka '=') is used to store a value into a variable.
  - A variable must be declared before it can be assigned to.
  - Syntax:

        // Declare a variable - determine the type and name for a new variable (only done once).
        dataType name;

        // Assign variable - provide a new value for an existing variable.
        name = value.

        // Declare and assign variable.
        data_type variable_name = value;

  - The statement may be a constant, variable or a function.
  - This includes chained calculations with operations, such as '+' for numbers.
  - Statements and variables are case sensitive.
  - Scope is the lifetime of a variables in that it will only exist in a certain part of your code based on the '{}' that it was created in.
  - Every variable in the same scope must have a unique name.

*/

#include <stdio.h>

int main() {
  // Examples

  // Declare a variable with a value of 5.
  int x = 5;
  printf("x = %d\n", x);

  // Change the value of x to 10.
  x = 10;
  printf("x = %d\n", x);

  // Not allowed since y was not declared yet.
  // y = 20;

  // The value is x is stored in y (as a copy and a change in y won't change x).
  int y = x;
  printf("y = %d\n", y);

  // The result of mathematical operations can be stored in variables.
  int sum = 2 * x + y;
  printf("sum = %d\n", sum);

  // Not allowed since sum was already created.
  //   int sum = 0;

  // Outputting links for further learning.
  printf("\n\n*Learn more*\n============\n-Functions: src/getting_started/function.c\n-Data Types: src/getting_started/datatypes.c\n-Other Operators: src/fundamentals/operators.c\n-Scope: src/fundamentals/scope.c\n");
}