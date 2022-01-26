/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:50:43 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/26 14:50:44 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//für mandatory part total unnötig:
//Länge vom prefix hat man ja schon im if statement
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
