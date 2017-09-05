#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mytoc.h"

int main(){

    int len = 1024;
    char inputString[len], delim = ' ';
    char** tokenizedString;

    LOOP:

    write(1,"$ ", 2);
    fgets (inputString, len, stdin) ;

/*
    char* s = inputString;
    while(*s != '\0'){
        write(1, s, 1);
        s++;
    }
*/
    if (stringCompare(inputString, "exit\n")){
        return 0;
    }

    int numWords = numberOfWords(inputString, delim);
    tokenizedString = myToc(inputString, delim);
    int i;

    write(1,"\n", 1);

    for (i = 0; i < numWords + 1; i++){
        char* temp = tokenizedString[i];
        while(*temp != '\0'){
            write(1, temp, 1);
            temp++;
        }
        write(1,"\n", 1);
    }

    for (i = 0; i < numWords + 1; i++){
        free(tokenizedString[i]);
    }

    free(tokenizedString);
    goto LOOP;

    return 0;
}
