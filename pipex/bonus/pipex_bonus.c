#include "pipex_bonus.h"

static void	init_struct(t_pipex *data, char **env);
static void	cpy_env(char **env, t_pipex *data);

int	main(int argc, char **argv, char **env)
{
	t_pipex	data;

	if (argc < 5)
	{
		write(2, "Use: <infile> \"cmd1\" ... \"cmdn\" <outfile>\n", 42);
		write(2, "or: here_doc LIMITER \"cmd1\" \"cmd2\" <file>\n", 42);
		return (1);
	}
	init_struct(&data, env);
	parsing(argc, argv, env, &data);
	if (ft_strncmp(argv[1], "here_doc\0", 9) == 0)
		pipe_here_doc(&data, argv);
	else
		piping(&data);
	free_data(&data);
	// system("leaks pipex");
	return (0);
}

static void	init_struct(t_pipex *data, char **env)
{
	data->paths = NULL;
	data->files = NULL;
	data->cmds = NULL;
	data->head = NULL;
	data->fd_pipe_a = NULL;
	data->fd_pipe_b = NULL;
	data->here_doc = NULL;
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
		err_exit(data, "Error: cpy_env", 14);
	data->envp[env_cnt] = NULL;
	env_cnt--;
	while (env_cnt >= 0)
	{
		data->envp[env_cnt] = ft_strdup(env[env_cnt]);
		env_cnt--;
	}
}
