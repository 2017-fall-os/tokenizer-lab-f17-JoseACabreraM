This directory contains:

A program that implements a tokenizing function. The program continously prompts the user to input lines of text that get tokenized based on a delimiter, ' ' by default. 
The tokens are copied from the input String and stored in an array (vector). The vector is then printed out, one token per line. An alternative tokekinzer function was 
also included, it also creates 

The user also has the following commands at his disposal. 

  exit - End execution of the program.
  
  tTest - Provies a sample test of the program using 5 predefined strings.
  
  nDel - Prompts the user to input a new delimiter character.
  
  rDel - Resets the delimiter character to ' '.
  
  aToc - Changes tokenizer function to an alternative version that doesn't make copies of the words.
  
  rToc - Restores default tokenizer function.

This program contains the following files:

mytoc.c - Contains the tokenizer and its helper functions. 
test.c - Applies the tokenizer, prompts user for input Strings due for tokenization. 
myToc.c - myToc.c.c Header file.

To test it, try:

$ make load

To compile and make object files:

$ make test

To delete binaries:

$ make clean
