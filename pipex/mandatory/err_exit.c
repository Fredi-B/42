/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:50:37 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/26 14:50:38 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_list(t_pipex *data);

void	free_data(t_pipex *data)
{
	if (data->paths != NULL)
		free_two_d_arr(data->paths);
	if (data->files != NULL)
		free_two_d_arr(data->files);
	if (data->envp != NULL)
		free_two_d_arr(data->envp);
	if (data->cmds != NULL)
		free_list(data);
	if (data->fd_pipe != NULL)
	{
		free(data->fd_pipe);
		data->fd_pipe = NULL;
	}
}

/* exit fct for errors during parsing / input checking.
Frees already malloced nodes. */
void	err_exit(t_pipex *data, char *msg, int len)
{
	write(STDERR_FILENO, msg, len);
	write(STDERR_FILENO, "\n", 1);
	free_data(data);
	exit(0);
}

static void	free_list(t_pipex *data)
{
	t_cmd_node	*tmp;

	data->cmds = data->head;
	if (data->head != NULL)
	{
		while (data->cmds != NULL)
		{
			tmp = data->cmds->next;
			if (data->cmds->path_and_flags != NULL)
				free_two_d_arr(data->cmds->path_and_flags);
			free(data->cmds->cmd_path);
			data->cmds->cmd_path = NULL;
			free(data->cmds);
			data->cmds = NULL;
			data->cmds = tmp;
		}
	}
}

void	free_two_d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	while (i > 0)
	{
		free(arr[i - 1]);
		arr[i - 1] = NULL;
		i--;
	}
	free(arr);
	arr = NULL;
}
