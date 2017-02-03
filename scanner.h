#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

 typedef struct SCANNER {
	FILE *file;
	char currLine[256];
	char currToken[32];
	bool hasNextLine;
	bool hasNext;
} SCANNER;

/* initializing the Scanner "object" */
bool scnr_Init(SCANNER *scanner,char *location) {
	/* initializing our bools */
	scanner->hasNext=true;
	scanner->hasNextLine=true;

	/* opening a file and doing some error checking */
	scanner->file=fopen(location,"r");
	if (scanner->file == NULL) {
		printf("Could not open the file at location %s.",location);
		return false;
	}
	return true;
}

/* returning the next token from the file */
char* scnr_next(SCANNER *scanner) {
	if(scanner->hasNextLine && fscanf(scanner->file,"%s",scanner->currToken) == true) //if we have another element
		return scanner->currToken;
	else{
		scanner->hasNext=false;
		scanner->hasNextLine=false;
		return "";
	}
}

/* returning the next line of the file */
char* scnr_nextLine(SCANNER *scanner) {
	if(scanner->hasNextLine && fscanf(scanner->file, "%[^\n]\n", scanner->currLine) != EOF) //if we have another line
		return scanner->currLine;
	else{
		scanner->hasNextLine=false;
		scanner->hasNext=false;
		return "";
	}
}

/* returning the next token as an integer from the file */
int scnr_nextInt(SCANNER *scanner) {
	if(scnr_next(scanner) == NULL)
		return false;
	else
		return atoi(scanner->currToken);
}

/* returning the next token as a double from the file */
double scnr_nextDouble(SCANNER *scanner) {
	if(scnr_next(scanner) == NULL)
		return false;
	else
		return atoi(scanner->currToken);
}

/* cleaning up */
void scnr_close(SCANNER *scanner) {
	fclose(scanner->file);
}
#endif
