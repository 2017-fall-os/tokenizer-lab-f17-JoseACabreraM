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

    if (stringCompare(inputString, "exit\n")){
        return 0;
    }
    if (stringCompare(inputString, "nDel\n")){
        changeDelimiter(&delim);
        goto LOOP;
    }
    if (stringCompare(inputString, "rDel\n")){
        delim = ' ';
        goto LOOP;
    }

    int numWords = numberOfWords(inputString, delim);
    tokenizedString = myToc(inputString, delim);
    int i;

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

    for (i = 0; i < numWords + 1; i++){
        free(tokenizedString[i]);
    }

    free(tokenizedString);
    goto LOOP;

    return 0;
}
