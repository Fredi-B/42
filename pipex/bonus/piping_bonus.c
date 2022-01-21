#include "pipex_bonus.h"

static void	write_in_pipe(t_pipex *data);
static void	read_write_pipe(t_pipex *data, int *pipe_r, int *pipe_w);
static void	read_from_pipe(t_pipex *data, int *pipe_w);

void	piping(t_pipex *data)
{
	int	pid_w;
	int	pid_w_and_r;
	int	pid_r;

	pid_w_and_r = 1;
	data->fd_pipe_a = (int *)malloc(sizeof(int) * 2);
	if (!data->fd_pipe_a)
		err_exit(data, "Error: malloc data->fd_pipe_a", 29);
	if (pipe(data->fd_pipe_a) == -1)
		err_exit(data, "Error: create pipe_a", 20);
	data->cmds = data->head;
	pid_w = fork();
	if (pid_w == -1)
		err_exit(data, "Error: create fork w", 20);
	if (pid_w == 0)
		write_in_pipe(data);
	else
	{
		wait(NULL);
		data->pipe_flag = PIPE_B;
		data->pipe_w = data->fd_pipe_a;
		data->cmds = data->cmds->next;
		while (data->cmds->next != NULL)
		{
			check_pipe_flag(data);
			pid_w_and_r = fork();
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
	}
	if (pid_w != 0 && pid_w_and_r != 0)
	{
		pid_r = fork();
		if (pid_r == -1)
			err_exit(data, "Error: create fork r", 20);
		if (pid_r == 0)
			read_from_pipe(data, data->pipe_w);
	}
	close(data->fd_pipe_a[0]);
	close(data->fd_pipe_a[1]);
	if (data->fd_pipe_b != NULL)
	{
		close(data->fd_pipe_b[0]);
		close(data->fd_pipe_b[1]);
	}
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

static void	read_write_pipe(t_pipex *data, int *pipe_r, int *pipe_w)
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
