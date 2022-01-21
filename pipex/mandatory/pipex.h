/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:11:58 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/21 10:45:32 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ----------------------------- Includes ---------------------------------- */

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* ----------------------------- Defines ----------------------------------- */

/* # define TRUE 1
# define FALSE 0 */

/* ---------------------- Defines for debugging ---------------------------- */

/* # define dsprintf(expr) printf("\n" #expr ":\n|%s|\n", expr)
# define diprintf(expr) printf("\n" #expr ":\n|%d|\n", expr) */

/* ----------------------------- Structures -------------------------------- */

typedef struct s_cmd_node
{
	char				*tmp_argv_cmds;
	char				*cmd_path;
	char				**path_and_flags;
	struct s_cmd_node	*next;
}				t_cmd_node;

typedef struct s_pipex
{
	char		**paths;
	char		**files;
	char		**envp;
	t_cmd_node	*cmds;
	t_cmd_node	*head;
	int			*fd_pipe;
	int			pid1;
	int			pid2;
}				t_pipex;

/*  ------------------------ Function prototypes --------------------------- */

/*  ----------------------------- parsing.c -------------------------------- */

void	parsing(int argc, char **argv, char **env, t_pipex *data);

/*  -------------------------- parsing_utils.c ----------------------------- */

char	*add_slash_and_join(char *path, char *cmd_part);
void	add_node(t_pipex *data, t_cmd_node *new_node);
void	store_cmds(t_pipex *data, char *tmp_c_p, int i);
int		get_prefix_len(char *env);

/*  ------------------------------ piping.c -------------------------------- */

void	piping(t_pipex *data);

/*  ----------------------------- err_exit.c -------------------------------- */

void	free_data(t_pipex *data);
void	err_exit(t_pipex *data, char *msg, int len);
void	free_two_d_arr(char **arr);

#endif
