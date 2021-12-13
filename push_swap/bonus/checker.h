/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:42:21 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/10 13:42:22 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/* ----------------------------- Includes ---------------------------------- */

# include "../libft/libft.h"
# include <limits.h>

/* ----------------------------- Defines ---------------------------------- */

# define TRUE 1
# define FALSE 0

/* ----------------------------- Structures -------------------------------- */

typedef struct s_node
{
	int				nbr;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_stacks
{
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*head_b;
	t_node	*tail_b;
	t_node	*a;
	t_node	*b;
	int		len_a;
	int		len_b;
	int		len_lis;
	int		*long_inc_sub;
	int		a_min;
	int		a_max;
}				t_stacks;

typedef struct s_rot
{
	int		a;
	int		b;
	int		total;
	int		tmp_a;
	int		tmp_b;
	int		tmp_total;
	int		a_b_pos;
	int		tmp_a_b_pos;
	int		relative_a;
	int		relative_b;
	int		relative_total;
}				t_rot;

/*  ------------------------ Function prototypes --------------------------- */

/*  ----------------------------- checker.c -------------------------------- */
void	err_exit(t_stacks *stack, char *msg, int len, int fd);
void	free_two_d_arr(int **lis_arr, int i);

/*  --------------------------- parse_bonus.c ------------------------------ */
void	parse(int argc, char **argv, t_stacks *stack);

/*  ----------------------- check_doubles_bonus.c -------------------------- */
void	check_doubles(t_stacks *stack);

/*  ------------------------- is_sorted_bonus.c ---------------------------- */
int		is_sorted(t_stacks *stack);

/*  -------------------------- swap_ops_bonus.c ---------------------------- */
void	swap_a(t_stacks *stack);
void	swap_b(t_stacks *stack);
void	swap_a_b(t_stacks *stack);

/*  ------------------------- push_ops_bonus.c ----------------------------- */
void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);

/*  ------------------------ rotate_ops_bonus.c ---------------------------- */
void	rotate_a(t_stacks *stack);
void	rotate_b(t_stacks *stack);
void	rotate_a_b(t_stacks *stack);

/*  ----------------------- reverse_ops_bonus.c ---------------------------- */
void	reverse_a(t_stacks *stack);
void	reverse_b(t_stacks *stack);
void	reverse_a_b(t_stacks *stack);

/*  ---------------------- check_instructions.c ---------------------------- */

void	get_check_do_instructions(t_stacks *stack);

#endif
