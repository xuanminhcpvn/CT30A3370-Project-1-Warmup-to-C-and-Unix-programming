/*CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi 

*/
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h> //for exit()
#include <string.h> //for strcmp()
#include "reverse.h"

int main(int argc, char *argv[]){
    if (argc == 1){
        printf("Insert the string you want to reverse line by line (:quit to finish): \n");
        reverse(stdin, stdout);
        return 0;
    }   else if (argc == 2){
        //expected .txt file
        //When invoked with just one command-line argument, the user supplies the input file, but the file should be printed to the screen. In Unix-based systems, printing to the screen is the same as writing to a special file known as standard output, or stdout for short
        FILE *pInput_file = fopen(argv[1], "r");
        if (pInput_file == NULL){
            fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
            exit(1);
        }
        reverse(pInput_file,stdout);
        fclose(pInput_file);
        printf("File '%s' read.\n", argv[1]);
        return 0;
    }   else if (argc == 3){
        //expect input.txt and output.txt ms
        //hen invoked with two command-line arguments, the program should read from the input file the user supplies and write the reversed version of said file to the output file the user supplies.
        //first check is .txt
        //then check saame input output must be different
        if (strcmp(argv[1],argv[2]) == 0){
            fprintf(stderr, "Input and output file must differ\n");
            exit(1);
        }
        //file open error
        FILE *input_file = fopen(argv[1], "r");

        if (input_file == NULL)
        {
            fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
            exit(1);
        }

        FILE *output_file = fopen(argv[2], "w");

        if (output_file == NULL)
        {
            fclose(input_file);
            fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
            exit(1);
        }

        reverse(input_file, output_file);

        fclose(input_file);
        printf("File '%s' read.\n", argv[1]);
        fclose(output_file);
        printf("File '%s' written.\n", argv[2]);
        return 0;
    } else {
        fprintf(stderr, "usage: reverse <input> <ouput> \n");
        exit(1);
    }
    return 0;
}