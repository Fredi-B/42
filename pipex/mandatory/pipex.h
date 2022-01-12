/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:11:58 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/12 17:18:46 by fbechtol         ###   ########.fr       */
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

# define dsprintf(expr) printf("\n" #expr ":\n%s\n", expr)
# define diprintf(expr) printf("\n" #expr ":\n%d\n", expr)


/* ----------------------------- Structures -------------------------------- */

typedef struct s_pipex
{
	char	**paths;
	char	**files;
	/* cmds als linked list? in eigenem struct */
	char	**cmds;
	char	**envp;
}				t_pipex;

/*  ------------------------ Function prototypes --------------------------- */

/*  ----------------------------- parsing.c -------------------------------- */

void	put_input_in_struct(int argc, char **argv, char **env, t_pipex *data);

#endif
