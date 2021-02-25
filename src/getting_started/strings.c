/*
  ---------------------------------------------------------------------
  Title: C-Style Strings
  Developer:Kevin Chevalier
  Labels:string, container, array
  Difficulty:Easy
  ---------------------------------------------------------------------

  =====================================================================
  Description
  =====================================================================
  This is an overview of C-style strings.

  =====================================================================
  Notes
  =====================================================================
  - C strings are used to store text as an group of characters (numbers, letters and symbols).
  - Strings can be created using a pair of "", which is known as a string literal.
  - The data type of a string is an array of chars, noted with 'char' and '[]'.
  - After the last element of the array should be a zero (not ALWAYS required to do it yourself).
  - C-style strings are lightweight, fast, fixed length but may be unsafe.
  - The other type of string is 'std::string' from C++.
  - The functions below are reserved for C-style strings only.

*/

#include <stdio.h>
#include <string.h>

int main() {
  // Creating strings.
  // Syntax 1: "CHARS...";.
  // Syntax 2: {'C', 'H', 'A'..., '0'};
  char start[] = "apple";                   // This string implicitly ends with a zero.
  char end[] = {'t', 'r', 'e', 'e', '\0'};  // This string MUST be explicitly ending with a zero.
  printf("Your strings are %s and %s.\n", start, end);

  // Get the number of characters in the string as a size_t data type (integer).
  // Syntax: strlen(string);
  size_t startLength = strlen(start);  // Proper data type.
  int endLength = strlen(end);         // This is ok too.
  printf("%s has %zu chars and %s has %d chars.\n", start, startLength, end, endLength);

  // Use [] operator to get the char at a position.
  // Syntax: string[position];
  char startFirstLetter = start[0];
  char endLastLetter = end[endLength - 1];
  printf("%s starts with %c and %s ends with %c.\n", start, startFirstLetter, end, endLastLetter);

  // Check if two strings are equal.
  // Two strings are equal if the output is 0.
  // Syntax: strcmp(string1, string2);
  if (strcmp(start, end) == 0) {
    printf("They are the same string.\n");
  } else {
    printf("They are different strings.\n");
  }

  // Check if PART of two strings are equal.
  // Two parts are equal if the output is 0.
  // Syntax: strncmp(string1, string2, length);
  if (strncmp(start, end, 1) == 0) {
    printf("They start the same.\n");
  } else {
    printf("They start differently.\n");
  }

  // Join a string to another (conCATenate).
  // Make sure the destination string has space to hold the new chars.
  // Syntax: strcat(destinationString, sourceString);
  // Example: strcat("abc","def"); "abc" -> "abcdef"
  char word[startLength + endLength];
  strcat(word, start);
  strcat(word, end);
  printf("%s + %s = %s\n", start, end, word);

  // Join PART of a string to another (coNCATenate).
  // Make sure the destination string has space to hold the new chars.
  // Syntax: strncat(destinationString, sourceString, length);
  // Example: strncat("abc","def"); "abc" -> "abcdef"
  char shortWord[startLength + endLength];
  strncat(shortWord, start, 2);
  strncat(shortWord, end, 1);
  printf("(2 from %s) + (1 from %s) = %s\n", start, end, shortWord);

  // Make a copy of a string and change the first letter.
  // Syntax: strcpy(destinationString, sourceString);
  char newStart[startLength];  // Create empty string with the correct length.
  strcpy(newStart, start);
  newStart[0] = 'A';
  newStart[2] = 'P';
  printf("We can copy %s and change it to %s.\n", start, newStart);

  // Copy PART of a string.
  // Syntax: strncpy(destinationString, sourceString, length);
  int newLength = 2;
  char shortStart[newLength];  // Create empty string with the correct length.
  strncpy(shortStart, start, newLength);
  printf("We can copy %s from %s.\n", shortStart, start);

  // Find a substring starting with a char.
  // The output must be stored in a pointer (char*), instead of (char[])
  // Pointers must be used when returning a string from a function.
  // Syntax: strchr(STRING, CHAR);
  char* firstP = strchr(start, 'p');
  printf("%s is within %s.\n", firstP, start);

  // Find a substring ending with a char.
  // Syntax: strrchr(STRING, CHAR);
  char* lastP = strrchr(start, 'p');
  printf("%s is within %s.\n", lastP, start);

  // Iterate each char individually.
  // Syntax: for (int counter = 0; string[counter] != 0; counter++) {}
  for (int i = 0; start[i] != 0; i++) {
    char c = start[i];
    printf("The char at %d is %c.\n", i, c);
  }

  // Outputting links for further learning.
  printf("\n\n*Learn more*\n============\n-Data Types: src/getting_started/datatypes.c\n-Char Data Type: src/getting_started/primitive_datatypes.c\n-Variables: src/getting_started/variables.c\n-Arrays: src/fundamentals/arrays.c\n-Escape Sequences: src/fundamentals/escape_seq.c\n-C++ String: src/containers_stl/strings.cpp\n");
}