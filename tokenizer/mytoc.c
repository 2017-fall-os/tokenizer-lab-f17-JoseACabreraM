#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int stringCompare(char* fString, char* sString){

    int i = 0;
    while (fString[i] == sString[i]){
        if (fString[i] == '\0' || sString[i] == '\0'){
            break;
        }
        i++;
    }
    return(fString[i] == '\0' && sString[i] == '\0');
}

int numberOfWords(char* inputString, char delim){

    if (*inputString == '\n'){
        return 0;
    }

    char* temp = inputString;
    int i = 0;
    int wordFound = 0;

    while(1){
        if (*temp != delim && *temp != '\n'){
            wordFound = 1;
        }
        if ((wordFound && *temp == delim) || (wordFound && *temp == '\n')){
            i++;
            wordFound = 0;
        }
        if (*temp == '\0'){
            return i;
        }
        temp++;
    }

    return i;
}

char** myToc(char* inputString, char delim){

    int numWords = numberOfWords(inputString, delim);
    char** tokenizedStrings = (char**) malloc(sizeof(char*) * (numWords + 1));

    int currentStringLength = 0, i = 0, readingWord = 1, j;
    char* temp = inputString;
    char* wordStart = inputString;

    while(1){
        if(*temp != delim && *temp != '\n' && *temp != '\0'){
            currentStringLength++;
            if (readingWord){
                readingWord = 0;
                wordStart = temp;
            }
        }
        if((*temp == delim || *temp == '\0') && !readingWord){
            tokenizedStrings[i] = (char*) malloc(sizeof(char) * (currentStringLength + 1));

            for (j = 0; j < currentStringLength; j++){
                tokenizedStrings[i][j] = *wordStart;
                wordStart++;
            }
            tokenizedStrings[i][currentStringLength] = '\0';
            currentStringLength = 0;
            i++;
            readingWord = 1;

            if(*temp == '\0'){
                break;
            }

        }
        temp++;
    }

    tokenizedStrings[numWords] = (char*) malloc(sizeof(char));
    tokenizedStrings[numWords][0] = '\0';

    return tokenizedStrings;
}
/*
char** myToc2(char* inputString, char delim){

    int numWords = numberOfWords(inputString, delim);
    char** tokenizedStrings = (char**) malloc(sizeof(char*) * (numWords + 1));
    int insertWord = 1;
    int i = 0;
    char* temp = inputString;

    while(1){
        if (*temp == '\0'){
            tokenizedStrings[i] = temp;
            return tokenizedStrings;
        }
        if (insertWord && *temp != delim){
            tokenizedStrings[i] = temp;
            i++;
            insertWord = 0;
        }
        if (*temp == delim || *temp == '\n'){
            insertWord = 1;
            *temp = '\0';
        }
        temp++;
    }

    return tokenizedStrings;
}
*/
