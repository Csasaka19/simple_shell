#include "hsh.h"

/**
 * parse - parse input
 * @info: shell information
 *
 * Description: This function expands aliases, variables, and word splitting
 *
 * Return: the final number of tokens
 */
<<<<<<< HEAD
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
=======
int parse(info_t *info)
{
	char **tokens, *tok;
	size_t n = 0;
	cmdlist_t *cmd = info->commands = cmd_to_list(info->line);

	while (cmd)
	{
		remove_comments(cmd);
		if (!cmd->tokens)
		{
			cmd = cmd->next;
			del_cmd(&(info->commands), n);
			continue;
		}
		expand_aliases(info->aliases, &(cmd->tokens));
		if (!cmd->tokens)
		{
			cmd = cmd->next;
			del_cmd(&(info->commands), n);
			continue;
		}
		expand_vars(info, &(cmd->tokens));
		if (!cmd->tokens)
		{
			cmd = cmd->next;
			del_cmd(&(info->commands), n);
			continue;
		}
		tokens = cmd->tokens;
		for (tok = *tokens; tok; tok = *(++tokens))
		{
			*tokens = dequote(tok);
			free(tok);
		}
		cmd = cmd->next;
		++n;
	}
	return (n);
>>>>>>> 1b01d2cdb835821452e7d39a565367656e654d48
}
