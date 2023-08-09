#include "shell.h"

int main(int ac, char **argv)
{
    char *shell_prompt = "(Lerjorn) $ ";
    char *lineptr = NULL, *lineptr_copy = NULL;
    size_t n = 0;
    ssize_t mchars_read;
    const char *delimit = "\n"; 
    int num_tokens = 0;
    char *token;
    int i;

    /* declaring void variables */
    (void)ac;

    /* creating an infinite loop */
    while (1)
    {
        printf("%s", shell_prompt);
        mchars_read = getline(&lineptr, &n, stdin);

        /* allocate space for a lineptr_copy */
        lineptr_copy = malloc(sizeof(char) * mchars_read);
        if (lineptr_copy == NULL)
        {
            perror("tsh: memory allocation error");
            return(-1);
        }
        
        /* copy lineptr to lineptr_copy */
        strcpy(lineptr_copy, lineptr);

        /* check if getline reaches EOF */
        if (mchars_read == -1)
        {
            printf("Exiting shell...\n");
            return(-1);
        }
        else
        {
           /*calculate the total number of tokens */
            token = strtok(lineptr, delimit);

            while (token != NULL)
            {
            num_tokens++;
            token = strtok(NULL, delimit);
            }
            num_tokens++;

            /* Alloacte space to hold the array of strings in strtok */
            argv = malloc(sizeof(char *) * num_tokens);

            /* store each token in the argv array */
            token = strtok(lineptr_copy, delimit);

            for ( i = 0; token != NULL; i++)
            {
                argv[i] = malloc(sizeof(char) * strlen(token));

                token = strtok(NULL, delimit);
            }
            argv[i] = NULL;

            /* execute the command */
            printf("Here 5\n");
            execmd(argv);
        }
    }
    /*freeing up allocated memory*/
    free(lineptr);
    free(lineptr_copy);
    return(0);
}