#include <stdlib.h>
#include "main.h"
/**
 * _setenv - A function that sets an environment variable
 * @name: a string representing the environment variable.
 * @value: a string representing the value to be assigned
 * to the enviroment variable.
 * @overwrite: an integer flag to overwrite the environment variable,
 * if the variable already exists.
 * Return: 0 if success any other number if it fails.
 */

int _setenv(const char *name, const char *value, int overwrite)
{
    char *env_var;
    if (name || value != NULL)
    {
        env_var = getenv(name);
        if (env_var != NULL && overwrite == 0)
        {
            return (0);
        }
        else
        {
            return (1);
        }
        return (0);
    }
    else
    {
        return (1);
    }
    
}