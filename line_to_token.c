#include "simple_shell.h"

#define DELIMITER " \n\t\r\a\v"
/**
 * split_line - splits line to tokens
 * @data: a pointer to the struct of data
 *
 * Return: 0 on success, -1 on error
 */
int split_line(sh_t *data)
{
char *token;
size_t size = TOKENSIZE, new_size, i = 0;

if (_strcmp(data->line, "\n") == 0)
return (FAIL);
data->args = malloc(size * sizeof(char *));
if (data->args == NULL)
return (FAIL);
token = strtok(data->line, DELIMITER);
if (token == NULL)
return (FAIL);
while (token)
{
data->args[i++] =  token;
if (i + 2 >= size)
{
new_size = size * 2;
data->args = _realloc(data->args, size * sizeof(char *),
new_size *sizeof(char *));
if (data->args == NULL)
return (FAIL);
size = new_size;
}
token = strtok(NULL, DELIMITER);
}
data->args[i] = NULL;
return (0);
}
#undef DELIMITER
