#include "simple_shell.h"

/**
 * handle_builtin - handles and manages the builtins commands
 * @data: a pointer to data structure
 * Return: 0 on success, -1 on error
 */
int handle_builtin(sh_t *data)
{
blt_t blt[] = {
{"exit", abort_prg},
{"cd", change_dir},
{"help", display_help},
{NULL, NULL}
};
int F = 0;

while ((blt + F)->cmd)
{
if (_strcmp(data->args[0], (blt + F)->cmd) == 0)
return ((blt + F)->f(data));
F++;
}
return (FAIL);
}
