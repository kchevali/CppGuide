/*
  ---------------------------------------------------------------------
  Title: I/O in C
  Developer:Kevin Chevalier
  Labels: io
  Difficulty:Easy
  ---------------------------------------------------------------------

  =====================================================================
  Description
  =====================================================================
  This is an overview on how to do input/output for the console in C.

  =====================================================================
  Notes
  =====================================================================
  - The method for standard input and output are scanf() and printf().
  - They use format specifiers within strings to extract/insert data.
  - scanf() requires a pointer, so use the '&' to get a pointer for your variable.
  - IO uses escape sequences for special characters: new line is '\n'.
  - C IO is faster and more structured than C++ IO.

  *******************************************************
  * Format Specifiers
  *******************************************************
  * %d    |    int        |   integer
  *******************************************************
  * %lf   |    double     |   decimal
  *******************************************************
  * %lld  |    long long  |   big integer
  *******************************************************
  * %c    |    char       |   letter/digit/symbol
  *******************************************************
  * %s    |    string     |   text
  *******************************************************

*/

#include <stdio.h>

int main() {
  // Examples.
  printf("Please enter two integer numbers:");  // Shown to the user.
  int a, b;
  // Use '&' to get a pointer to a and b.
  scanf("%d%d", &a, &b);  // Get response from the user.

  printf("What is your name:");
  // Can store up to 40 characters.
  char name[40];
  // Do not use & if variable is already a pointer such as char[] or char*.
  scanf("%s", name);

  // Extract formatted data.
  printf("What is your birthday(MM/DD/YYYY)?\n");
  int month, day, year;
  scanf("%d/%d/%d", &month, &day, &year);

  // Read numbers from a file.
  int count = 3;
  printf("Please enter %d decimal numbers:", count);
  double nums[count];
  for (int i = 0; i < count; i++) scanf("%lf", &(nums[i]));  // Shorthand for arrays are scanf("%f",nums + i);

  // Output Examples.
  printf("\nThe sum of %d + %d = %d.\n", a, b, a + b);
  printf("Your name is %s and your birthday month is %d.\n", name, month);
  printf("The decimal numbers are: ");
  for (int i = 0; i < count; i++) printf("%lf ", nums[i]);

  // Outputting links for further learning.
  printf("\n\n*Learn more*\n============\n-File Input and Output: src/fundamentals/file_io.c\n-C++ Input and Output: src/getting_started/io.cpp\n-C-style Strings: src/getting_started/strings.c\n-Primitive Data Types: src/getting_started/primitive_datatypes.c\n-Escape Sequences: src/fundamentals/escape_seq.c\n");
}