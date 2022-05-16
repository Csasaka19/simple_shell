#include "simple_shell.h"

/**
 * abort_prg - exit the program
 * @data: pointer to data structure
 * Return: 0 on success, -1 on error
 */
int abort_prg(sh_t *data __attribute__((unused)))
{
int code, k = 0;

if (data->args[1] == NULL)
{
free_data(data);
exit(errno);
}
while (data->args[1][k])
{
if (_isalpha(data->args[1][k++]) < 0)
{
data->error_msg = _strdup("Illegal number\n");
return (FAIL);
}
}
code = _atoi(data->args[1]);
free_data(data);
exit(code);
}
