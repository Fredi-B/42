/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:50:54 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/26 14:50:55 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_struct(t_pipex *data, char **env);
static void	cpy_env(char **env, t_pipex *data);

int	main(int argc, char **argv, char **env)
{
	t_pipex	data;

	if (argc != 5)
	{
		write(2, "Use: <infile> \"cmd1\" \"cmd2\" <outfile>\n", 38);
		return (1);
	}
	init_struct(&data, env);
	parsing(argc, argv, env, &data);
	piping(&data);
	free_data(&data);
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
		err_exit(data, "Error: cpy_env", 14);
	data->envp[env_cnt] = NULL;
	env_cnt--;
	while (env_cnt >= 0)
	{
		data->envp[env_cnt] = ft_strdup(env[env_cnt]);
		env_cnt--;
	}
}
