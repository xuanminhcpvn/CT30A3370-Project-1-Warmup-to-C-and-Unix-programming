#include <stdio.h>
#include <stdlib.h> //for exit()
#include <string.h> //for strcmp()
int main(int argc, char *argv[]){
    //handling command-line arguments
        printf("You have entered %d arguments: \n", argc);
        //for (int i = 0; i < argc;i++){
        //   printf("%s\n",argv[i]);
        //}

        //One of the error check requirement
        if (argc == 1){
            //When invoked without any arguments, your reversing program should read from standard input (stdin), which is the input that a user types in, and write to standard output (i.e., the screen).
            
        } else if (argc == 2){
            //expected .txt file
            //When invoked with just one command-line argument, the user supplies the input file, but the file should be printed to the screen. In Unix-based systems, printing to the screen is the same as writing to a special file known as standard output, or stdout for short.
        } else if (argc == 3){
            //expect input.txt and output.txt ms
            //hen invoked with two command-line arguments, the program should read from the input file the user supplies and write the reversed version of said file to the output file the user supplies.
            //first check is .txt
            //then check saame input output must be different
            if (strcmp(argv[1],argv[2]) == 0){
                fprintf(stderr, "Input and output file must differ\n");
                exit(1);
            }
            //file open error
        } else {
            fprintf(stderr, "usage: reverse <input> <ouput> \n");
            exit(1);
        }
        return 0;
}
