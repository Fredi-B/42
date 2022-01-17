/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:11:58 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/17 17:06:09 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ----------------------------- Includes ---------------------------------- */

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/wait.h>

/* ----------------------------- Defines ----------------------------------- */

# define TRUE 1
# define FALSE 0

/* ---------------------- Defines for debugging ---------------------------- */

# define dsprintf(expr) printf("\n" #expr ":\n|%s|\n", expr)
# define diprintf(expr) printf("\n" #expr ":\n|%d|\n", expr)


/* ----------------------------- Structures -------------------------------- */

typedef struct s_cmd_node
{
	char				*cmd_path;
	char				**path_and_flags;
	struct s_cmd_node	*next;
}				t_cmd_node;

typedef struct s_pipex
{
	char	**paths;
	char	**files;
	char	**envp;
	t_cmd_node	*cmds;
	t_cmd_node	*head;
}				t_pipex;

/*  ------------------------ Function prototypes --------------------------- */

/*  ----------------------------- parsing.c -------------------------------- */

void	parsing(int argc, char **argv, char **env, t_pipex *data);

/*  -------------------------- parsing_utils.c ----------------------------- */

void	join_path_and_cmds(t_pipex *data);
void	get_files(int argc, char **argv, t_pipex *data);


/*  ----------------------------- err_exit.c -------------------------------- */

void	err_exit(t_pipex *data, char *msg, int len);
void	free_two_d_arr(char **arr);

#endif
