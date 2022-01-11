#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int	main(int argc, char ** argv, char **env)
{
	// char	*path;
	pid_t	pid;
	char	*cmds[2];
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		cmds[j] = argv[i];
		j++;
		i++;
	}
	cmds[j] = NULL;
	// path = "/bin/ls";
	// argv[1] = NULL;
	pid = fork();
	if (pid == 0)
	{

		// execve(argv[1], argv, env);
		if (execve("/bin/ls", cmds, env) == -1)
		{
			write(STDERR_FILENO, "command not found: ", 19);
			write(STDERR_FILENO, cmds[0], 2); 
				// ft_strlen(data->cmds[data->cnt][0]));
			write(STDERR_FILENO, "\n", 1);
			// p_free(data);
			exit(1);
		}
	}
	wait(NULL);
	return (0);
}
