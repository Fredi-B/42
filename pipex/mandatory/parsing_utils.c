#include "pipex.h"

//für mandatory part total unnötig:
//Länge vom prefix hat man ja schon im if statement
int	get_prefix_len(char *env)
{
	char	**prefix;
	int		len;
	int		i;

	len = 0;
	prefix = ft_split(env, '=');
	len = ft_strlen(prefix[0]);
	i = 0;
	while (prefix[i])
	{
		free(prefix[i]);
		i++;
	}
	free(prefix);
	return (len + 1);
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
