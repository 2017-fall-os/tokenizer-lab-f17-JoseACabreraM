#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mytoc.h"

int main(){

    int len = 1024, tocChoice = 1;
    char inputString[len], delim = ' ';
    char** tokenizedString;

    LOOP:

    write(1,"$ ", 2);
    fgets (inputString, len, stdin) ;

    // To end execution
    if (stringCompare(inputString, "exit\n")){
        printf("\nEnd of Execution\n\n");
        return 0;
    }

    // To change the delimiter character
    if (stringCompare(inputString, "nDel\n")){
        changeDelimiter(&delim);
        goto LOOP;
    }

    // To restore the delimiter character
    if (stringCompare(inputString, "rDel\n")){
        delim = ' ';
        printf("\nRestored default delimiter\n\n");
        goto LOOP;
    }

    // To change the tokenizer function to the alternative one
    if (stringCompare(inputString, "aToc\n")){
        tocChoice = 0;
        printf("\nUsing alternative tokenizer\n\n");
        goto LOOP;
    }

    // To restore the original tokenizer function
    if (stringCompare(inputString, "rToc\n")){
        tocChoice = 1;
        printf("\nRestored regular tokenizer\n\n");
        goto LOOP;
    }

    int numWords = numberOfWords(inputString, delim);

    // Create the token vector depending on the tokenizer function
    if (tocChoice){
        tokenizedString = myToc(inputString, delim);
    } else {
        tokenizedString = myToc2(inputString, delim);
    }

    int i;

    // Prints the token vector, token by toke, character by character
    write(1,"\n", 1);
    for (i = 0; i < numWords; i++){
        char* temp = tokenizedString[i];
        while(*temp != '\0'){
            write(1, temp, 1);
            temp++;
        }
        write(1,"\n", 1);
    }
    write(1,"\n", 1);

    // Only free each token memory if they were allocated using the regular tokenizer
    if (tocChoice){
        for (i = 0; i < numWords + 1; i++){
            free(tokenizedString[i]);
        }
    }

    // Free the pointer array from memory
    free(tokenizedString);
    goto LOOP;

    return 0;
}
