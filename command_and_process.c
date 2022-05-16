#include "simple_shell.h"

/**
 * process_cmd - process command and execute process
 * @data: a pointer to the struct of data
 *
 * Return: 0 on success, -1 on error
 */
int process_cmd(sh_t *data)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{
signal(SIGINT, SIG_DFL);
if (execve(data->cmd, data->args, environ) < 0)
data->error_msg = _strdup("not found\n");
return (FAIL);
}
else
{
waitpid(pid, &status, WUNTRACED);
}
return (0);
}
