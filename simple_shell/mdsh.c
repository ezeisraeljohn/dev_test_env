#include "main.h"

/**
 * main - tests the custom getline function
 * @argc: command line arguments counter
 * @argv: command line arguments
 *
 * Return: 0 on success or an exit code of the just exited process
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n_read = 0;
	int retval = 0, running = 1;
	path_t *path_list = NULL;

	path_list = build_path(&path_list);
	if (argc >= 2)
		return (handle_file_as_input(argv[1], path_list));

	while (running)
	{
		/*printf("mdsh$ ");*/
		fflush(stdout);

		n_read = _getline(&line, &len, STDIN_FILENO);
		if (n_read == -1)
		{
			safe_free(line);
			perror("_getline");
			return (-1);
		}

		if (n_read == 0)
		{
			/*printf("\n");*/
			safe_free(line);
			free_list(&path_list);
			/* most definitely Ctrl+D or Ctrl+C was received */
			return (retval);
		}
		if ((n_read == 1 && *line == '\n') || *line == '#')
			continue; /* skip normal ENTER keys and comments */

		retval = parse_line(line, path_list);
		safe_free(line);
	}
	free_list(&path_list);

	return (retval);
}
