#include "pipex_bonus.h"

static void	prep_pipe_b(t_pipex *data);
static void	prep_pipe_a(t_pipex *data);

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
