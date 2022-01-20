#include "pipex.h"

static void	write_in_pipe(t_pipex *data);
static void	read_from_pipe(t_pipex *data);

void	piping(t_pipex *data)
{
	data->fd_pipe = (int *)malloc(sizeof(int) * 2);
	if (!data->fd_pipe)
		err_exit(data, "Error: malloc data->fd_pipe", 27);
	if (pipe(data->fd_pipe) == -1)
		err_exit(data, "Error: create pipe", 18);
	data->cmds = data->head; //woanners hin? durchloopen?
	data->pid1 = fork();
	if (data->pid1 == -1)
		err_exit(data, "Error: create fork", 18);
	if (data->pid1 == 0)
		write_in_pipe(data);
	if (data->pid1 != 0)
	{
		wait(NULL);
		data->cmds = data->cmds->next; //woanners hin? durchloopen?
		data->pid2 = fork();
		if (data->pid2 == -1)
			err_exit(data, "Error: create fork", 18);
		if (data->pid2 == 0)
			read_from_pipe(data);
	}
	close(data->fd_pipe[0]);
	close(data->fd_pipe[1]);
	wait(NULL);
}

static void	write_in_pipe(t_pipex *data)
{
	int	fd_infile;

	close(data->fd_pipe[0]);
	if (dup2(data->fd_pipe[1], STDOUT_FILENO) == -1)
		err_exit(data, "Error: redirect STDOUT", 19);
	close(data->fd_pipe[1]);
	fd_infile = open(data->files[0], O_CREAT | O_RDONLY, 0777);
	if (dup2(fd_infile, STDIN_FILENO) == -1)
		err_exit(data, "Error: redirect STDIN", 18);
	close(fd_infile);
	if (execve(data->cmds->cmd_path, data->cmds->path_and_flags, data->envp) == -1)
		err_exit(data, "Error: execve cmd1", 18);

}

static void	read_from_pipe(t_pipex *data)
{
	int	fd_outfile;

	close(data->fd_pipe[1]);
	if (dup2(data->fd_pipe[0], STDIN_FILENO) == -1)
		err_exit(data, "Error: redirect STDIN", 18);
	close(data->fd_pipe[0]);
	fd_outfile = open(data->files[1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		err_exit(data, "Error: redirect STDOUT", 19);
	close(fd_outfile);
	if (execve(data->cmds->cmd_path, data->cmds->path_and_flags, data->envp) == -1)
		err_exit(data, "Error: execve cmd2", 18);
}
