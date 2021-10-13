// Assignment #2 
// Shayanna Gatchalian & John Paul Tran
// 3.3.2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>

// main function to take in arguments from command line
int main(int argc, char *argv[]) 
{
    double total_summation = 0;                 // sum of all summations from files
    int summation_pipe[2];                      // pipe

    char *str = argv[argc - 1];         // gets last arg from command line, define as power value
    
    if(str == NULL)
    {
        printf("power value not inputted\n");
        exit(1);
    }

    double power = atoi(str);                   // cast to double
    
    // create the child processes
    for (int i = 1; i < argc - 1; i++)          // for each number file
    {
        if (pipe(summation_pipe) == -1)         // if pipe fails
        {
            fprintf(stderr, "pipe failed");
            return 1;
        }

        pid_t p = fork();

        if (p < 0)                              // if fork fails
        {
            fprintf(stderr, "fork failed");
            return 1;
        }

        // child process
        if (p == 0)
        {
            FILE *fp = fopen(argv[i], "r");
            double summation = 0;               // summation to be returned
            
            close(summation_pipe[0]);           // close reading end of pipe

            if (fp != NULL)                     // make sure file opened for reading
            {
                double n;                       // number to be read in from text file
                
                while (fscanf(fp, "%lf", &n) != EOF) {
                    n = pow(n, power);          // put n to power
                    summation += n;             // add result to summation
                }
            }
            else    // if file couldnt be opened
            {
                fprintf(stderr, "file cannot open %s\n", argv[i]);
            }

            write(summation_pipe[1], &summation, sizeof(summation));

            // close writing end of pipe and file
            close(summation_pipe[1]);
            fclose(fp);

            // exit child
            exit(0);
        }
    }

    for (int j = 1; j > argc; j++)
    {
        close(summation_pipe[1]);   // close writing pipe end

        wait(NULL);     // wait for child

        // read summations of current file in pipe
        double summation;
        read(summation_pipe[0], &summation, sizeof(summation));

        // calculate total summation
        total_summation += summation;
    }

    close(summation_pipe[0]);
    printf("%0.2lf\n", total_summation);  // print summation

    return 0;
}