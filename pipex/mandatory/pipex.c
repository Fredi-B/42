#include "pipex.h"

static void	init_struct(t_pipex *data, char **env);
static void	cpy_env(char **env, t_pipex *data);

int	main(int argc, char **argv, char **env)
{
	t_pipex	data;

	init_struct(&data, env);
	write(1, "1\n", 2);
	parsing(argc, argv, env, &data);
	write(1, "2\n", 2);
	
	piping(&data);
	write(1, "3\n", 2);
	
	free_data(&data);
	write(1, "4\n", 2);

	return (0);
}

static void	init_struct(t_pipex *data, char **env)
{
	data->paths = NULL;
	data->files = NULL;
	data->cmds = NULL;
	data->head = NULL;
	data->fd_pipe = NULL;
	cpy_env(env, data);
}

static void	cpy_env(char **env, t_pipex *data)
{
	int	env_cnt;

	env_cnt = 0;
	while (env[env_cnt] != NULL)
		env_cnt++;
	data->envp = (char **)malloc(sizeof(char *) * (env_cnt + 1));
	if (!data->envp)
		err_exit(data, "Error: cpy_env\n", 15);
	data->envp[env_cnt] = NULL;
	env_cnt--;
	while (env_cnt >= 0)
	{
		data->envp[env_cnt] = ft_strdup(env[env_cnt]);
		env_cnt--;
	}
}
