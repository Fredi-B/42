#include "pipex.h"

void	write_in_pipe(t_pipex *data)
{
	int	fd_infile;

	close(data->fd_pipe[0]);
	if (dup2(data->fd_pipe[1], 1) == -1)
		return ; //to do: error handling
	close(data->fd_pipe[1]);
	fd_infile = open(data->files[0], O_CREAT | O_RDONLY, 777);
	if (dup2(fd_infile, 0) == -1)
		return ; //to do: error handling
	close(fd_infile);
	//to do: protecten (falls es cmd nicht gibt o.ä.: siehe test_execve.c)
	execve(data->cmds->cmd_path, data->cmds->path_and_flags, data->envp);
}

void	read_from_pipe(t_pipex *data)
{
	int	fd_outfile;

	close(data->fd_pipe[1]);
	if (dup2(data->fd_pipe[0], 0) == -1)
		return ; //to do: error handling
	close(data->fd_pipe[0]);
	fd_outfile = open(data->files[1], O_CREAT | O_WRONLY, 777);
	if (dup2(fd_outfile, 1) == -1)
		return ; //to do: error handling
	close(fd_outfile);
	data->cmds = data->head->next; //woanners hin? durchloopen?
	//to do: protecten (falls es cmd nicht gibt o.ä.: siehe test_execve.c)
	execve(data->cmds->cmd_path, data->cmds->path_and_flags, data->envp);
	write(2, "test\n", 5);
	
}