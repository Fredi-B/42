/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:50:30 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/26 14:50:31 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	prep_pipe_b(t_pipex *data);
static void	prep_pipe_a(t_pipex *data);

int	fork_write_child(t_pipex *data)
{
	int	pid_w;

	data->fd_pipe_a = (int *)malloc(sizeof(int) * 2);
	if (!data->fd_pipe_a)
		err_exit(data, "Error: malloc data->fd_pipe_a", 29);
	if (pipe(data->fd_pipe_a) == -1)
		err_exit(data, "Error: create pipe_a", 20);
	data->cmds = data->head;
	pid_w = fork();
	if (pid_w == -1)
		err_exit(data, "Error: create fork w", 20);
	return (pid_w);
}

int	check_for_middle_cmds(t_pipex *data)
{
	int	pid_w_and_r;

	data->pipe_flag = PIPE_B;
	data->pipe_w = data->fd_pipe_a;
	data->cmds = data->cmds->next;
	while (data->cmds->next != NULL)
	{
		check_pipe_flag(data);
		pid_w_and_r = fork();
		wait(NULL);
		if (pid_w_and_r == -1)
			err_exit(data, "Error: create fork w_and_r", 26);
		if (pid_w_and_r == 0)
			read_write_pipe(data, data->pipe_r, data->pipe_w);
		else
		{
			close(data->pipe_r[0]);
			wait(NULL);
		}
		data->cmds = data->cmds->next;
	}
	return (pid_w_and_r);
}

void	check_pipe_flag(t_pipex *data)
{
	if (data->pipe_flag == PIPE_B)
		prep_pipe_b(data);
	else
		prep_pipe_a(data);
}

static void	prep_pipe_b(t_pipex *data)
{
	if (data->fd_pipe_b != NULL)
	{
		free(data->fd_pipe_b);
		data->fd_pipe_b = NULL;
	}
	data->fd_pipe_b = (int *)malloc(sizeof(int) * 2);
	if (!data->fd_pipe_b)
		err_exit(data, "Error: malloc data->fd_pipe_b", 29);
	if (pipe(data->fd_pipe_b) == -1)
		err_exit(data, "Error: create pipe_b", 20);
	close(data->fd_pipe_a[1]);
	data->pipe_r = data->fd_pipe_a;
	data->pipe_w = data->fd_pipe_b;
	data->pipe_flag = PIPE_A;
}

static void	prep_pipe_a(t_pipex *data)
{
	if (data->fd_pipe_a != NULL)
	{
		free(data->fd_pipe_a);
		data->fd_pipe_a = NULL;
	}
	data->fd_pipe_a = (int *)malloc(sizeof(int) * 2);
	if (!data->fd_pipe_a)
		err_exit(data, "Error: malloc data->fd_pipe_a", 29);
	if (pipe(data->fd_pipe_a) == -1)
		err_exit(data, "Error: create pipe_a", 20);
	close(data->fd_pipe_b[1]);
	data->pipe_r = data->fd_pipe_b;
	data->pipe_w = data->fd_pipe_a;
	data->pipe_flag = PIPE_B;
}
