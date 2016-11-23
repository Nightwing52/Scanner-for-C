#ifndef SCANNER_H
#define SCANNER_H
#include <stdio.h> //for file input
#include <string.h> //for C-style strings
#include <stdlib.h> //for type conversions
typedef struct SCANNER{
        FILE *file;
        char currLine[256];
        char currToken[32];
        int hasNextLine; //true by default
        int hasNext; //true by default
} SCANNER;

/* initializing the Scanner "object" */
int scnr_Init(SCANNER *scanner,char *location){
        /* initializing our bools */
        scanner->hasNext=1;
        scanner->hasNextLine=1;
        /* opening a file and doing some error checking */
        scanner->file=fopen(location,"r");
        if (scanner->file == NULL) {
                printf("Could not open the file at location %s.",location);
                return 0;
        }
        return 1;
}

/* returning the next token from the file */
char* scnr_next(SCANNER *scanner){
        /* advancing to the next token before we start reading */
        int space=1; //bool; is a space
        while(space==1){
                char curr=fgetc(scanner->file);
                if(feof(scanner->file) != 0){
                        scanner->hasNext=0;
                        space=0;
                        ungetc(curr,scanner->file);
                }
                if(curr != ' '){
                        space=0; //not a space
                        ungetc(curr,scanner->file);
                }
        }
        /* getting the token */
        space=0;
        int currIndex=0;
        while(space==0){
                char curr=fgetc(scanner->file);
                if(curr != ' '){
                        scanner->currToken[currIndex]=curr;
                        ++currIndex;
                }
                else
                        space=1; //is a space
        }
        return scanner->currToken;
}

/* returning the next line of the file */
char* scnr_nextLine(SCANNER *scanner){
        fgets(scanner->currLine,256,scanner->file);
        if(feof(scanner->file))
                scanner->hasNextLine=0;
        return scanner->currLine;
}

/* returning the next token as an integer from the file */
int scnr_nextInt(SCANNER *scanner){
        scnr_next(scanner);
        return atoi(scanner->currToken);
}

/* returning the next token as a double from the file */
double scnr_nextDouble(SCANNER *scanner){
        scnr_next(scanner);
        return atof(scanner->currToken);
}

/* cleaning up */
void scnr_Close(SCANNER *scanner){
        fclose(scanner->file);
}
#endif
