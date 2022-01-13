#include "pipex.h"
static char	*get_paths_from_env(char **env, t_pipex *data);
static int	get_prefix_len(char *env);


void	put_input_in_struct(int argc, char **argv, char **env, t_pipex *data)
{
	get_paths_from_env(env, data);
	dsprintf(data->paths[1]);
	
	/* to use unused parameters... */
	argc = 1;
	argv[2] = "test";
}

static char	*get_paths_from_env(char **env, t_pipex *data)
{
	int		i;
	int		len_prefix;

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
			len_prefix = get_prefix_len(env[i]);
			/* to do: free data->paths */
			data->paths = ft_split(&env[i][len_prefix], ':');
			break ;
		}
		i++;
	}
	return (NULL);
}

static int	get_prefix_len(char *env)
{
	char	**prefix;
	int		len;
	int		i;

	len = 0;
	prefix = ft_split(env, '=');
	len = ft_strlen(prefix[0]);
	i = 0;
	while (prefix[i])
	{
		free(prefix[i]);
		i++;
	} 
	free(prefix);
	return (len + 1);
}
