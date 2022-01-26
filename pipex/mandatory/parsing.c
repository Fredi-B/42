/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:50:47 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/26 14:50:48 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_paths_from_env(char **env, t_pipex *data);
static void	get_cmds(int argc, char **argv, t_pipex *data);
static void	join_path_and_cmds(t_pipex *data);
static void	get_files(int argc, char **argv, t_pipex *data);

void	parsing(int argc, char **argv, char **env, t_pipex *data)
{
	get_paths_from_env(env, data);
	get_cmds(argc, argv, data);
	join_path_and_cmds(data);
	get_files(argc, argv, data);
}

static char	*get_paths_from_env(char **env, t_pipex *data)
{
	int		i;
	int		len_prefix;

	i = 0;
	while (1)
	{
		if (env[i] == NULL)
			err_exit(data, "PATH not found", 14);
		if (ft_strnstr(env[i], "PATH=", ft_strlen("PATH=")) != NULL)
		{
			len_prefix = get_prefix_len(env[i]);
			data->paths = ft_split(&env[i][len_prefix], ':');
			break ;
		}
		i++;
	}
	return (NULL);
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
		if (!new_node)
			err_exit(data, "Error: malloc new_node", 22);
		data->cmds = new_node;
		data->cmds->tmp_argv_cmds = ft_strdup(argv[i]);
		if (!data->cmds->tmp_argv_cmds)
			err_exit(data, "Error: strdup(argv[1]", 21);
		tmp_argv = ft_split(argv[i], ' ');
		if (!tmp_argv)
			err_exit(data, "Error: split argv[i]", 20);
		data->cmds->cmd_path = ft_strdup(tmp_argv[0]);
		if (!data->cmds->cmd_path)
			err_exit(data, "Error: strdup(tmp_argv[0]", 25);
		free_two_d_arr(tmp_argv);
		add_node(data, new_node);
		i--;
	}
}

static void	join_path_and_cmds(t_pipex *data)
{
	char	*tmp_c_p;
	int		i;

	data->cmds = data->head;
	while (data->cmds != NULL)
	{
		i = 0;
		while (data->paths[i] != NULL)
		{
			tmp_c_p = add_slash_and_join(data->paths[i], data->cmds->cmd_path);
			if (access(tmp_c_p, X_OK) == 0)
			{
				store_cmds(data, tmp_c_p, i);
				break ;
			}
			free(tmp_c_p);
			i++;
			if (data->paths[i] == NULL)
				store_cmds(data, tmp_c_p, i);
		}
		data->cmds = data->cmds->next;
	}
}

static void	get_files(int argc, char **argv, t_pipex *data)
{
	data->files = (char **)malloc(sizeof(char *) * (2 + 1));
	if (!data->files)
		err_exit(data, "Error: malloc data->files", 25);
	data->files[0] = ft_strdup(argv[1]);
	if (!data->files[0])
		err_exit(data, "Error: strdup(argv[1]", 21);
	data->files[1] = ft_strdup(argv[argc - 1]);
	if (!data->files[1])
		err_exit(data, "Error: strdup(argv[argc - 1]", 28);
	data->files[2] = NULL;
}
