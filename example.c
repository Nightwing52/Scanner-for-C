#include "scanner.h"

int main(int argc, char *argv[]) {
	/* creating and setting up our Scanner object */
	Scanner *scanner=(Scanner *)malloc(sizeof(Scanner));
	scnr_init(scanner,"text.txt");

	/* printing all the tokens */
	while(scanner->hasNext)
		printf("%s\n",scnr_next(scanner));

	/* cleaning up */
	scnr_close(scanner);
	free(scanner);
	return 0;
}

