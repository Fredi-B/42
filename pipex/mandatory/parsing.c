#include "pipex.h"
static char	*get_paths_from_env(char **env, t_pipex *data);

void	put_input_in_struct(int argc, char **argv, char **env, t_pipex *data)
{

	get_paths_from_env(env, data);
	dsprintf(data->paths[2]);
	
	
	/* to use unused parameters... */
	argc = 1;
	argv[2] = "test";
	write(1, "test\n", 6);
}

static char	*get_paths_from_env(char **env, t_pipex *data)
{
	int		i;

	i = 0;
	while (1)
	{
		if (env[i] == NULL)
		{
			/* change to "command not found: 'cmd'" (s. Alf)" */
			write(STDERR_FILENO, "PATH not found\n", 15);
			break ;
		}
		if (ft_strnstr(env[i], "PATH=", ft_strlen(env[i])) != NULL)
		{
			/* to do: free data->paths */
			data->paths = ft_split(&env[i][5], ':');
			break ;
		}
		i++;
	}
	return (NULL);
}

