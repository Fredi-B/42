#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	*path;
	int		i;

	argc = 0;
	argv[0] = "t";
	path = NULL;
	i = 0;
	while (1)
	{
		printf("%s\n", env[i]);
		if (env[i] == NULL)
		{
			write(STDERR_FILENO, "PATH not found\n", 15);
			break ;
		}
		if (ft_strnstr(env[i], "eafedfa=", ft_strlen(env[i])) != NULL)
		{
			path = ft_strnstr(env[i], "eafedfa=", ft_strlen(env[i]));
			break ;
		}

		i++;
	}
	printf("%s\n", path);
	return (0);
}