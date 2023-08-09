#include "shell.h"

void execmd(char **argv)
{
    char *cmd = NULL;

    printf("Here 1\n");
    if (argv)
    {
        printf("Here 2\n");
        /* get the command */
        cmd = argv[0];

        printf("%s\n second: %s\n", cmd, argv[1]);

        /*execute the command with execve */
        if (execve(cmd, argv, NULL) == -1)
        {
            perror("Error:");
        }
        
    }
    
}