#include "scanner.h"

int main(int argc, char *argv[]) {
	/* creating and setting up our SCANNER object */
	SCANNER scanner;
	scnr_Init(&scanner,"text.txt");

	/* printing all the tokens */
	while(scanner.hasNext)
		printf("%s\n",scnr_next(&scanner));

	/* cleaning up */
	scnr_close(&scanner);
	return 0;
}

