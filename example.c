#include "scanner.h"

int main(int argc, char *argv[]) {
	SCANNER scanner;
	scnr_Init(&scanner,"text.txt");
	/* printing all the tokens */
	while(scanner.hasNextLine)
		printf("%s\n",scnr_nextLine(&scanner));
	scnr_Close(&scanner);
	return 0;
}

