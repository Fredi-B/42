/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:50:26 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/26 14:50:27 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	write_in_pipe(t_pipex *data);
static void	read_from_pipe(t_pipex *data, int *pipe_w);
static void	close_pipes(t_pipex *data);

void	piping(t_pipex *data)
{
	int	pid_w;
	int	pid_w_and_r;
	int	pid_r;

	pid_w_and_r = 1;
	pid_w = fork_write_child(data);
	if (pid_w == 0)
	{
		if (data->here_doc_flag == YES)
			put_here_doc_in_pipe(data);
		else
			write_in_pipe(data);
	}
	else
		pid_w_and_r = check_for_middle_cmds(data);
	if (pid_w != 0 && pid_w_and_r != 0)
	{
		pid_r = fork();
		if (pid_r == -1)
			err_exit(data, "Error: create fork r", 20);
		if (pid_r == 0)
			read_from_pipe(data, data->pipe_w);
	}
	close_pipes(data);
	wait(NULL);
}

static void	write_in_pipe(t_pipex *data)
{
	int	fd_infile;

	close(data->fd_pipe_a[0]);
	if (dup2(data->fd_pipe_a[1], STDOUT_FILENO) == -1)
		err_exit(data, "Error: redirect STDOUT", 22);
	close(data->fd_pipe_a[1]);
	fd_infile = open(data->files[0], O_CREAT | O_RDONLY, 0777);
	if (fd_infile == -1)
		err_exit(data, "Error: infile: permission denied", 32);
	if (dup2(fd_infile, STDIN_FILENO) == -1)
		err_exit(data, "Error: redirect STDIN", 21);
	close(fd_infile);
	if (execve \
		(data->cmds->cmd_path, data->cmds->path_and_flags, data->envp) == -1)
	{
		write(2, "command not found: ", 19);
		write(2, data->cmds->cmd_path, ft_strlen(data->cmds->cmd_path));
		err_exit(data, "", 0);
	}
}

void	read_write_pipe(t_pipex *data, int *pipe_r, int *pipe_w)
{
	close(pipe_w[0]);
	if (dup2(pipe_w[1], STDOUT_FILENO) == -1)
		err_exit(data, "Error: redirect STDOUT", 22);
	close(pipe_w[1]);
	if (dup2(pipe_r[0], STDIN_FILENO) == -1)
		err_exit(data, "Error: redirect STDIN", 21);
	close(pipe_r[0]);
	if (execve \
		(data->cmds->cmd_path, data->cmds->path_and_flags, data->envp) == -1)
	{
		write(2, "command not found: ", 19);
		write(2, data->cmds->cmd_path, ft_strlen(data->cmds->cmd_path));
		err_exit(data, "", 0);
	}
}

static void	read_from_pipe(t_pipex *data, int *pipe_w)
{
	int	fd_outfile;

	close(pipe_w[1]);
	if (dup2(pipe_w[0], STDIN_FILENO) == -1)
		err_exit(data, "Error: redirect STDIN", 21);
	close(pipe_w[0]);
	if (data->here_doc_flag == YES)
		fd_outfile = open(data->files[1], O_CREAT | O_WRONLY | O_APPEND, 0777);
	else
		fd_outfile = open(data->files[1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_outfile == -1)
		err_exit(data, "Error: outfile: permission denied", 33);
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		err_exit(data, "Error: redirect STDOUT", 22);
	close(fd_outfile);
	if (execve \
		(data->cmds->cmd_path, data->cmds->path_and_flags, data->envp) == -1)
	{
		write(2, "command not found: ", 19);
		write(2, data->cmds->cmd_path, ft_strlen(data->cmds->cmd_path));
		err_exit(data, "", 0);
	}
}

static void	close_pipes(t_pipex *data)
{
	close(data->fd_pipe_a[0]);
	close(data->fd_pipe_a[1]);
	if (data->fd_pipe_b != NULL)
	{
		close(data->fd_pipe_b[0]);
		close(data->fd_pipe_b[1]);
	}
}
