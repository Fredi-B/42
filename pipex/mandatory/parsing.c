#include "pipex.h"
static char	*get_paths_from_env(char **env, t_pipex *data);
static int	get_prefix_len(char *env);
static void	get_cmds(int argc, char **argv, t_pipex *data);

void	put_input_in_struct(int argc, char **argv, char **env, t_pipex *data)
{
	get_paths_from_env(env, data);
	get_cmds(argc, argv, data);
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

static void	get_cmds(int argc, char **argv, t_pipex *data)
{
	t_cmd_node	*new_node;
	int			i;
	char		**tmp_argv;

	i = argc - 2;
	while (i >= 2)
	{
		new_node = (t_cmd_node *)malloc(sizeof(t_cmd_node));
		/* protecten mit exit fct, in der alles gefreet wird unso (s. push_swap) */
		if (!new_node)
			return ;
		data->cmds = new_node;
		data->cmds->path_and_flags = argv[i];
		/* to do: free tmp_argv */
		tmp_argv = ft_split(argv[i], ' ');
		// if (!tmp_argv)
		// 	err_exit(data, "", 0);
		data->cmds->cmd_path = tmp_argv[0];
		if (data->cmds == NULL)
		{
			data->head = new_node;
			data->head->next = NULL;
		}
		else
		{
			new_node->next = data->head;
			data->head = new_node;
		}
		i--;
	}
	/* for checking only */
	while (data->cmds)
	{
		dsprintf(data->cmds->path_and_flags);
		dsprintf(data->cmds->cmd_path);
		data->cmds = data->cmds->next;
	}
}
