#include "scanner.h"

int main(int argc, char *argv[]){
        SCANNER scanner;
        scnr_Init(&scanner,"text.txt");
        /* printing all the tokens */
        while(scanner.hasNext)
                printf("%s\n",scnr_next(&scanner));
        scnr_Close(&scanner);
        return 0;
}

