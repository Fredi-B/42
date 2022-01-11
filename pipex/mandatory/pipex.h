/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:11:58 by fbechtol          #+#    #+#             */
/*   Updated: 2022/01/11 17:38:23 by fbechtol         ###   ########.fr       */
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

/* ----------------------------- Defines ---------------------------------- */

# define TRUE 1
# define FALSE 0
# define SMALL_A_SMALL_B 2
# define SMALL_A_SMALLER_B 3
# define SMALLER_A_SMALL_B 4
# define SMALL_A_BIG_B 5
# define BIG_A_SMALL_B 6
# define BIG_A_BIG_B 7
# define BIGGER_A_BIG_B 8
# define BIG_A_BIGGER_B 9

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

/*  ---------------------------- push_swap.c ------------------------------- */
void	init_stacks_and_rot(t_stacks *stack, t_rot *rot);
void	err_exit(t_stacks *stack, char *msg, int len);
void	free_two_d_arr(int **lis_arr, int i);

/*  ------------------------------ parse.c --------------------------------- */
void	parse(int argc, char **argv, t_stacks *stack);

/*  -------------------------- check_doubles.c ----------------------------- */
void	check_doubles(t_stacks *stack);

/*  ---------------------------- is_sorted.c ------------------------------- */
int		is_sorted(t_stacks *stack);

/*  ---------------------------- swap_ops.c -------------------------------- */
void	swap_a(t_stacks *stack);
void	swap_b(t_stacks *stack);

/*  ---------------------------- push_ops.c -------------------------------- */
void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);

/*  --------------------------- rotate_ops.c ------------------------------- */
void	rotate_a(t_stacks *stack);
void	rotate_b(t_stacks *stack);
void	rotate_a_b(t_stacks *stack);

/*  -------------------------- reverse_ops.c ------------------------------- */
void	reverse_a(t_stacks *stack);
void	reverse_b(t_stacks *stack);
void	reverse_a_b(t_stacks *stack);

/*  ----------------------- sort_short_lists.c ----------------------------- */
void	sort_three(t_stacks *stack);
void	sort_five(t_stacks *stack);

/*  ------------------------------- sort.c --------------------------------- */
void	sort(t_stacks *stack, t_rot *rot);

/*  ------------------------------ get_lis.c ------------------------------- */
void	get_long_inc_sub(t_stacks *stack);

/*  ---------------------------- brute_search.c ---------------------------- */
void	brute_search(t_stacks *stack, t_rot *rot);

/*  ------------------------- brute_search_utils.c ------------------------- */
int		get_pos(t_stacks *stack, t_rot *rot);
int		get_total_rot(int a, int b, t_stacks *stack, t_rot *rot);

/*  ----------------------------- brute_back.c ----------------------------- */
void	brute_back(t_stacks *stack, t_rot *rot);

/*  -------------------------- brute_back_utils.c -------------------------- */
void	push_small_smaller(t_stacks *stack, t_rot *rot);
void	push_smaller_small(t_stacks *stack, t_rot *rot);
void	push_small_big(t_stacks *stack, t_rot *rot);
void	push_big_small(t_stacks *stack, t_rot *rot);
void	push_big_big(t_stacks *stack, t_rot *rot);

#endif
