#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

 typedef struct Scanner {
	FILE *file;
	char currLine[256];
	char currToken[32];
	bool hasNextLine;
	bool hasNext;
} Scanner;

/* initializing the Scanner "object" */
bool scnr_init(Scanner *scanner,char *location);

/* returning the next token from the file */
char* scnr_next(Scanner *scanner);

/* returning the next line of the file */
char* scnr_nextLine(Scanner *scanner);

/* returning the next token as an integer from the file */
int scnr_nextInt(Scanner *scanner);

/* returning the next token as a double from the file */
double scnr_nextDouble(Scanner *scanner);

/* cleaning up */
void scnr_close(Scanner *scanner);
#endif
