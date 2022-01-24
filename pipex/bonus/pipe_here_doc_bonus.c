#include "pipex_bonus.h"

static void	read_from_here_doc(t_pipex *data, char **argv);
static char	*join_here_doc(t_pipex *data, char *tmp_next_line, char *limiter);
static void	put_here_doc_in_pipe(t_pipex *data);


void	pipe_here_doc(t_pipex *data, char **argv)
{
	read_from_here_doc(data, argv);
	/* hier piping() callen und das if statement checkt dann wie es weiter geht.
	alles außer write_in_pipe kann hoffentlich übernommen werden */
	put_here_doc_in_pipe(data);
}

static void	read_from_here_doc(t_pipex *data, char **argv)
{
	char	*tmp_next_line;
	char	*limiter;

	limiter = ft_strjoin(argv[2], "\n");
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
	free(data->here_doc);
	data->here_doc = NULL;
	data->here_doc = ft_strdup(tmp_here_doc);
	if (!data->here_doc)
		err_exit(data, "Error: ft_strdup(tmp_here_doc)", 30);
	free(tmp_here_doc);
	tmp_here_doc = NULL;
	return (tmp_next_line);
}

static void	put_here_doc_in_pipe(t_pipex *data)
{

}