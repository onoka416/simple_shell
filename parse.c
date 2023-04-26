# include "shell.h"

/**
 * is_cmd - checks if path points to a regular file
 * @info: pointer to the info_t struct
 * @path: string representing the file path
 *
 * Return: 1 if path points to a regular file, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void) info;
	if (!path || stat(path, &st) == -1)
		return (0);

	if ((st.st_mode & S_IFMT) == S_IFREG)
		return (1);

	return (0);
}

/**
 * dup_chars - Copies a substring of a string
 * @pathstr: Pointer to the original string
 * @start: Starting index of the substring to copy
 * @stop: Stopping index of the substring to copy
 *
 * Return: A pointer to the copied substring
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i, k = 0;

	for (i = start; i < stop; i++)
	{
		if (pathstr[i] != ':')
		{
			buf[k++] = pathstr[i];
		}
	}
	buf[k] = '\0';
	return (buf);
}

/**
 * find_path - Finds the full path of a command.
 * @info: Pointer to a struct containing information about the shell.
 * @pathstr: String containing the paths to search separated by colons.
 * @cmd: The command to search for.
 *
 * Return: The full path to the command if found, otherwise NULL.
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int y = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[y] || pathstr[y] == ':')
		{
			path = dup_chars(pathstr, curr_pos, y);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[y])
				break;
			curr_pos = y;
		}
		y++;
	}
	return (NULL);
}

