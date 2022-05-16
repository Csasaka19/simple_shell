#include "simple_shell.h"

#define SETOWD(V) (V = _strdup(_getenv("OLDPWD")))
/**
 * change_dir - changes directory
 * @data:  pointer to data structure
 * Return:  0 is returned on success, -1 on error
 */
int change_dir(sh_t *data)
{
char *home;

home = _getenv("HOME");
if (data->args[1] == NULL)
{
SETOWD(data->oldpwd);
if (chdir(home) < 0)
return (FAIL);
return (SUCCESS);
}
if (_strcmp(data->args[1], "-") == 0)
{
if (data->oldpwd == 0)
{
SETOWD(data->oldpwd);
if (chdir(home) < 0)
return (FAIL);
}
else
{
SETOWD(data->oldpwd);
if (chdir(data->oldpwd) < 0)
return (FAIL);
}
}
else
{
SETOWD(data->oldpwd);
if (chdir(data->args[1]) < 0)
return (FAIL);
}
return (SUCCESS);
}
#undef GETCWD
