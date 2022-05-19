#include "simple_shell.h"

#define DELIMITER ":"
/**
 * parse_line - parses arguments to a valid command
 * @data: a pointer to the struct of data
 *
 * Return: 0 on success, -1 on error
 */
int parse_line(sh_t *data)
{
if (is_path_form(data) > 0)
return (0);
if (is_builtin(data) > 0)
{
if (handle_builtin(data) < 0)
return (FAIL);
}
is_short_form(data);
return (0);
}
#undef  DELIMITER
