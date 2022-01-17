#include "pipex.h"

static void	init_struct(t_pipex *data, char **env);
static void	cpy_env(char **env, t_pipex *data);

int	main(int argc, char **argv, char **env)
{
	t_pipex	data;

	init_struct(&data, env);
	parsing(argc, argv, env, &data);
	return (0);
}

static void	init_struct(t_pipex *data, char **env)
{
	data->paths = NULL;
	data->files = NULL;
	cpy_env(env, data);
	data->cmds = NULL;
	data->head = NULL;
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
