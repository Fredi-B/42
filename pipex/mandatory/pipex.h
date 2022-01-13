/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:11:58 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/13 19:27:36 by fbechtol         ###   ########.fr       */
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
	/* here goes cmd joined with path */
	char				*cmd_path;
	/* here goes cmd joined with path and flags */
	char				*path_and_flags;
	struct s_cmd_node	*next;
}				t_cmd_node;

typedef struct s_pipex
{
	char	**paths;
	char	**files;
	char	**envp;
	/* brauch i das? oder übergebe ich beide struct seperat lieber? */
	t_cmd_node	*cmds;
	t_cmd_node	*head;
}				t_pipex;

/*  ------------------------ Function prototypes --------------------------- */

/*  ----------------------------- parsing.c -------------------------------- */

void	put_input_in_struct(int argc, char **argv, char **env, t_pipex *data);

/*  ----------------------------- err_exit.c -------------------------------- */

void	err_exit(t_pipex *data, char *msg, int len);
void	free_two_d_arr(char **arr);

#endif
