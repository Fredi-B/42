/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:49:56 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/26 14:50:15 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_prefix_len(char *env)
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

t_cmd_node	*prep_new_node(t_pipex *data, char **argv, int i)
{
	t_cmd_node	*new_node;
	char		**tmp_argv;

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
	return (new_node);
}

void	add_node(t_pipex *data, t_cmd_node *new_node)
{
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
}

void	store_cmds(t_pipex *data, char *tmp_c_p, int i)
{
	char	*tmp_p_f;

	if (data->paths[i] != NULL)
	{
		free(data->cmds->cmd_path);
		data->cmds->cmd_path = tmp_c_p;
	}
	tmp_p_f = add_slash_and_join \
				(data->paths[i], data->cmds->tmp_argv_cmds);
	free(data->cmds->tmp_argv_cmds);
	data->cmds->path_and_flags = ft_split(tmp_p_f, ' ');
	free(tmp_p_f);
}

char	*add_slash_and_join(char *path, char *cmd_part)
{
	char	*tmp_path;
	char	*tmp;

	tmp_path = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp_path, cmd_part);
	free(tmp_path);
	return (tmp);
}
