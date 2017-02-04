#include "scanner.h"

/* initializing the Scanner "object" */
bool scnr_init(Scanner *scanner,char *location) {
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
char* scnr_next(Scanner *scanner) {
	if(fscanf(scanner->file,"%s",scanner->currToken) == true) //if we have another element
		return scanner->currToken;
	else{
		scanner->hasNext=false;
		scanner->hasNextLine=false;
		return "";
	}
}

/* returning the next line of the file */
char* scnr_nextLine(Scanner *scanner) {
	if(fscanf(scanner->file, "%[^\n]\n", scanner->currLine) != EOF) //if we have another line
		return scanner->currLine;
	else{
		scanner->hasNextLine=false;
		scanner->hasNext=false;
		return "";
	}
}

/* returning the next token as an integer from the file */
int scnr_nextInt(Scanner *scanner) {
	if(scnr_next(scanner) == NULL)
		return false;
	else
		return atoi(scanner->currToken);
}

/* returning the next token as a double from the file */
double scnr_nextDouble(Scanner *scanner) {
	if(scnr_next(scanner) == NULL)
		return false;
	else
		return atoi(scanner->currToken);
}

/* cleaning up */
void scnr_close(Scanner *scanner) {
	fclose(scanner->file);
}
