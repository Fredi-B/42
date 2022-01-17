#include "pipex.h"

char	*add_slash_and_join(char *path, char *cmd_part);

void	join_path_and_cmds(t_pipex *data)
{
	char	*tmp_c_p;
	char	*tmp_p_f;
	int		i;

	data->cmds = data->head;
	while (data->cmds != NULL)
	{
		i = 0;
		while (data->paths[i] != NULL)
		{
			tmp_c_p = add_slash_and_join(data->paths[i], data->cmds->cmd_path);
			if (access(tmp_c_p, X_OK) == 0)
			{
				free(data->cmds->cmd_path);
				/* to do: free data->cmds->cmd_path */
				data->cmds->cmd_path = tmp_c_p;
				tmp_p_f = add_slash_and_join(data->paths[i], *data->cmds->path_and_flags);
				/* to do: free data->cmds->path_and_flags */
				data->cmds->path_and_flags = ft_split(tmp_p_f, ' ');
				free(tmp_p_f);
				break ;
			}
			free(tmp_c_p);
			i++;
			/* hier schon prüfen, ob die cmds aus dem Input valide sind? 
			d.h. prüfen, ob if (access()) in der while Schleife mal wahr war.
			Wenn nicht, mit Fehlermsg raus? */
		}
		data->cmds = data->cmds->next;
	}
	/* for checking only */
	// data->cmds = data->head;
	// while (data->cmds)
	// {
	// 	dsprintf(data->cmds->path_and_flags);
	// 	dsprintf(data->cmds->cmd_path);
	// 	data->cmds = data->cmds->next;
	// }

}

char	*add_slash_and_join(char *path, char *cmd_part)
{
	char	*tmp_path;
	char	*tmp;

	tmp_path = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp_path, cmd_part);
	free(tmp_path);
	return (tmp);
}


void	get_files(int argc, char **argv, t_pipex *data)
{
	data->files = (char **)malloc(sizeof(char *) * 2);
	/* to do: protecten */
	data->files[0] = argv[1];
	data->files[1] = argv[argc -1];
	if (access(data->files[0], R_OK) != 0 || access(data->files[1], W_OK) != 0)
	{
		/* to do: error handling */
		dsprintf("error");
	}
}
