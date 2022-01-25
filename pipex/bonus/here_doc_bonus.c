#include "pipex_bonus.h"

static char	*join_here_doc(t_pipex *data, char *tmp_next_line, char *limiter);

void	get_cmd_here_doc(int argc, char **argv, t_pipex *data)
{
	t_cmd_node	*new_node;
	int			i;
	char		**tmp_argv;

	i = argc - 2;
	while (i >= 3)
	{
		new_node = (t_cmd_node *)malloc(sizeof(t_cmd_node));
		if (!new_node)
			err_exit(data, "Error: malloc new_node", 22);
		data->cmds = new_node;
		data->cmds->tmp_argv_cmds = ft_strdup(argv[i]);
		if (!data->cmds->tmp_argv_cmds)
			err_exit(data, "Error: strdup(argv[1]", 21);
		tmp_argv = ft_split(argv[i], ' ');
		if (!tmp_argv)
			err_exit(data, "Error: split argv[i]", 20);
		data->cmds->cmd_path = ft_strdup(tmp_argv[0]);
		if (!data->cmds->cmd_path)
			err_exit(data, "Error: strdup(tmp_argv[0]", 25);
		free_two_d_arr(tmp_argv);
		add_node(data, new_node);
		i--;
	}
}

void	read_from_here_doc(t_pipex *data, char **argv)
{
	char	*tmp_next_line;
	char	*limiter;

	limiter = ft_strjoin(argv[2], "\n");
	if (!limiter)
		err_exit(data, "Error: ft_strjoin(limiter)", 26);
	tmp_next_line = get_next_line(0);
	if (ft_strncmp(tmp_next_line, limiter, ft_strlen(tmp_next_line) != 0))
		data->here_doc = ft_strdup(data->here_doc);
	while (ft_strncmp(tmp_next_line, limiter, ft_strlen(tmp_next_line)) != 0)
		tmp_next_line = join_here_doc(data, tmp_next_line, limiter);
	free(limiter);
	limiter = NULL;
	free(tmp_next_line);
	tmp_next_line = NULL;
}


static char	*join_here_doc(t_pipex *data, char *tmp_next_line, char *limiter)
{
	char	*tmp_here_doc;

	free(tmp_next_line);
	tmp_next_line = NULL;
	tmp_next_line = get_next_line(0);
	if (!tmp_next_line)
		err_exit(data, "Error: get_next_line", 20);
	if (ft_strncmp(tmp_next_line, limiter, ft_strlen(tmp_next_line)) == 0)
		return (tmp_next_line);
	tmp_here_doc = ft_strjoin(data->here_doc, tmp_next_line);
	if (!tmp_here_doc)
		err_exit(data, "Error: ft_strjoin(here_doc)", 27);
	free(data->here_doc);
	data->here_doc = NULL;
	data->here_doc = ft_strdup(tmp_here_doc);
	if (!data->here_doc)
		err_exit(data, "Error: ft_strdup(tmp_here_doc)", 30);
	free(tmp_here_doc);
	tmp_here_doc = NULL;
	return (tmp_next_line);
}

void	put_here_doc_in_pipe(t_pipex *data)
{
	int	fd_here_doc[2];

	if (pipe(fd_here_doc) == -1)
		err_exit(data, "Error: create fd_here_doc", 25);
	write(fd_here_doc[1], data->here_doc, ft_strlen(data->here_doc));
	dup2(fd_here_doc[0], STDIN_FILENO);
	close(fd_here_doc[0]);
	close(fd_here_doc[1]);
	close(data->fd_pipe_a[0]);
	if (dup2(data->fd_pipe_a[1], STDOUT_FILENO) == -1)
		err_exit(data, "Error: redirect STDOUT", 22);
	close(data->fd_pipe_a[1]);
	if (execve \
		(data->cmds->cmd_path, data->cmds->path_and_flags, data->envp) == -1)
	{
		write(2, "command not found: ", 19);
		write(2, data->cmds->cmd_path, ft_strlen(data->cmds->cmd_path));
		err_exit(data, "", 0);
	}
}
