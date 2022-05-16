#iinclude "simple_shell.h"
/**
 * read_line - read a line from the standard input
 * @data: pointer to the struct of data
 * Return: 0 success, -1 on error
 */
int read_line(sh_t *data)
{
char *csr_ptr, *end_ptr, c;
size_t size = BUFSIZE, read_st, length, new_size;

data->line = malloc(size * sizeof(char));
if (data->line == NULL)
return (FAIL);
if (isatty(STDIN_FILENO))
PRINT(PROMPT);
for (csr_ptr = data->line, end_ptr = data->line + size;;)
{
read_st = read(STDIN_FILENO, &c, 1);
if (read_st == 0)
return (FAIL);
*csr_ptr++ = c;
if (c == '\n')
{
*csr_ptr = '\0';
return (SUCCESS);
}
if (csr_ptr + 2 >= end_ptr)
{
new_size = size * 2;
length = csr_ptr - data->line;
data->line = _realloc(data->line, size * sizeof(char),
new_size * sizeof(char));
if (data->line == NULL)
return (FAIL);
size = new_size;
end_ptr = data->line + size;
csr_ptr = data->line + length;
}
}
}
