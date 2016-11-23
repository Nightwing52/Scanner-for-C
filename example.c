#include "scanner.h"

int main(int argc, char *argv[]){
        SCANNER scanner;
        scnr_Init(&scanner,"text.txt");
        while(scanner.hasNext)
                printf("%s\n",scnr_next(&scanner));
        return 0;
}

