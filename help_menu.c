#include "simple_shell.h"

/**
 * display_help - displays the help menu
 * @data: a pointer to a data structure
 * Return: 0 on success, -1 on error
 */
int display_help(sh_t *data)
{
int fd, fw, rd = 1;
char s;

fd = open(data->args[1], O_RDONLY);
if (fd < 0)
{
data->error_msg = _strdup("no help topics match\n");
return (FAIL);
}
while (rd > 0)
{
rd = read(fd, &s, 1);
fw = write(STDOUT_FILENO, &s, rd);
if (fw < 0)
{
data->error_msg = _strdup("cannot write: permission denied\n");
return (FAIL);
}
}
PRINT("\n");
return (0);
}
