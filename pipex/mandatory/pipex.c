#include "pipex.h"

static void	init_struct(t_pipex *data, char **env);
static void	cpy_env(char **env, t_pipex *data);

int	main(int argc, char **argv, char **env)
{
	t_pipex	data;

	init_struct(&data, env);
	parsing(argc, argv, env, &data);
	data.fd_pipe = (int *)malloc(sizeof(int) * 2);
	if (pipe(data.fd_pipe) == -1)
		return (1); //to do: error handling
	data.cmds = data.head; //woanners hin? durchloopen?
	data.pid1 = fork();
	if (data.pid1 == -1)
		return (2); //to do: error handling
	if (data.pid1 == 0)
	{
		write_in_pipe(&data);
	}
	if (data.pid1 != 0)
	{
		wait(NULL);
		data.cmds = data.head->next;
		data.pid2 = fork();
		if (data.pid2 == -1)
			return (3); //to do: error handling
		if (data.pid2 == 0)
		{
			read_from_pipe(&data);
		}
	}
	if (data.pid1 != 0 && data.pid2 != 0)
	{
		close(data.fd_pipe[0]);
		close(data.fd_pipe[1]);
		wait(NULL);
	}


	return (0);
}

static void	init_struct(t_pipex *data, char **env)
{
	data->paths = NULL;
	data->files = NULL;
	cpy_env(env, data);
	data->cmds = NULL;
	data->head = NULL;
	data->fd_pipe = NULL;
}

static void	cpy_env(char **env, t_pipex *data)
{
	int	env_cnt;

	env_cnt = 0;
	while (env[env_cnt] != NULL)
		env_cnt++;
	/* to do: free data->envp */
	data->envp = (char **)malloc(sizeof(char *) * env_cnt);
	/* to do: protecten */
	// if (data->envp == NULL)
	// 	exit(0);
	while (env_cnt > 0)
	{
		/* to do: free data->envp[] */
		data->envp[env_cnt] = ft_strdup(env[env_cnt]);
		env_cnt--;
	}
}
