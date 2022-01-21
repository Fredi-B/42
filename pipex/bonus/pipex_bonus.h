/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:11:58 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/21 19:47:26 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

# define PIPE_A 1
# define PIPE_B 0

/* ---------------------- Defines for debugging ---------------------------- */

// # define dsprintf(expr) printf("\n" #expr ":\n|%s|\n", expr)
// # define diprintf(expr) printf("\n" #expr ":\n|%d|\n", expr)

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
	int			*fd_pipe_a;
	int			*fd_pipe_b;
	int			*pipe_r;
	int			*pipe_w;
	int			pipe_flag;
}				t_pipex;

/*  ------------------------ Function prototypes --------------------------- */

/*  -------------------------- parsing_bonus.c ----------------------------- */

void	parsing(int argc, char **argv, char **env, t_pipex *data);

/*  ----------------------- parsing_utils_bonus.c -------------------------- */

char	*add_slash_and_join(char *path, char *cmd_part);
void	add_node(t_pipex *data, t_cmd_node *new_node);
void	store_cmds(t_pipex *data, char *tmp_c_p, int i);
int		get_prefix_len(char *env);

/*  --------------------------- piping_bonus.c ----------------------------- */

void	piping(t_pipex *data);
void	read_write_pipe(t_pipex *data, int *pipe_r, int *pipe_w);

/*  ------------------------ piping_utils_bonus.c -------------------------- */

int		fork_write_child(t_pipex *data);
int		check_for_middle_cmds(t_pipex *data);
void	check_pipe_flag(t_pipex *data);

/*  --------------------------- err_exit_bonus.c --------------------------- */

void	free_data(t_pipex *data);
void	err_exit(t_pipex *data, char *msg, int len);
void	free_two_d_arr(char **arr);

#endif
