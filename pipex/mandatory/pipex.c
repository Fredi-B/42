#include "pipex.h"

void	init_struct(t_pipex *data, char **env);

int	main(int argc, char **argv, char **env)
{
	t_pipex	data;

	init_struct(&data, env);
	put_input_in_struct(argc, argv, env, &data);



}

void	init_struct(t_pipex *data, char **env)
{
	int	i;

	data->cmds = NULL;
	data->files = NULL;
	data->paths = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		write(1, "test\n", 6);
		/* data->envp mallocen? */
		ft_strlcpy(data->envp[i], env[i], ft_strlen(env[i]));
		dsprintf(env[i]);
		i++;
	}
}
