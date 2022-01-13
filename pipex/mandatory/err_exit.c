#include "pipex.h"

static void	free_list(t_pipex *data);

/* exit fct for errors during parsing / input checking.
Frees already malloced nodes. */
void	err_exit(t_pipex *data, char *msg, int len)
{
	free_list(data);
	write(2, msg, len);
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
