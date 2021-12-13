/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:30:43 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/10 13:55:12 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_list(t_stacks *stack);

int	main(int argc, char **argv)
{
	t_stacks	stack;
	t_rot		rot;

	if (argc < 2)
		return (0);
	init_stacks_and_rot(&stack, &rot);
	parse(argc, argv, &stack);
	check_doubles(&stack);
	if (is_sorted(&stack) == TRUE)
		err_exit(&stack, "", 0);
	sort(&stack, &rot);
	free_list(&stack);
	return (0);
}

void	init_stacks_and_rot(t_stacks *stack, t_rot *rot)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->head_a = NULL;
	stack->tail_a = NULL;
	stack->head_b = NULL;
	stack->tail_b = NULL;
	stack->long_inc_sub = NULL;
	stack->len_a = 0;
	stack->len_b = 0;
	stack->a_min = INT_MAX;
	stack->a_max = INT_MIN;
	rot->a = 0;
	rot->b = 0;
	rot->total = INT_MAX;
	rot->tmp_a = 0;
	rot->tmp_b = 0;
	rot->tmp_total = INT_MAX;
	rot->a_b_pos = 0;
}

/* exit fct for errors during parsing / input checking.
Frees already malloced nodes. */
void	err_exit(t_stacks *stack, char *msg, int len)
{
	free_list(stack);
	write(2, msg, len);
	exit(0);
}

void	free_two_d_arr(int **lis_arr, int i)
{
	while (i > 0)
	{
		free(lis_arr[i - 1]);
		lis_arr[i - 1] = NULL;
		i--;
	}
	free(lis_arr);
	lis_arr = NULL;
}

static void	free_list(t_stacks *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	stack->a = stack->head_a;
	if (stack->len_a > 1)
	{
		while (i < stack->len_a)
		{
			tmp = stack->a->next;
			free(stack->a);
			stack->a = NULL;
			stack->a = tmp;
			i++;
		}
	}
}
