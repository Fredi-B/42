#include "pipex.h"

static void	free_list(t_pipex *data);

void	free_data(t_pipex *data)
{
	if (data->paths != NULL)
		free_two_d_arr(data->paths);
	write(1, "2\n", 2);

	if (data->files != NULL)
		free_two_d_arr(data->files);
	write(1, "3\n", 2);

	if (data->envp != NULL)
		free_two_d_arr(data->envp);
	write(1, "4\n", 2);

	dsprintf(data->cmds->cmd_path);
	if (data->cmds != NULL)
		free_list(data);
	write(1, "5\n", 2);

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
	free_data(data);
	write(STDERR_FILENO, msg, len);
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
			dsprintf(data->cmds->path_and_flags[0]);
			dsprintf(data->cmds->path_and_flags[1]);
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
