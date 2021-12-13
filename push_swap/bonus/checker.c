/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:30:43 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/10 14:04:27 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	init_stacks(t_stacks *stack);
static void	free_list(t_stacks *stack);

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc < 2)
		return (0);
	init_stacks(&stack);
	parse(argc, argv, &stack);
	check_doubles(&stack);
	get_check_do_instructions(&stack);
	if (is_sorted(&stack) == TRUE && stack.head_b == NULL)
		err_exit(&stack, "OK\n", 3, 1);
	else
		err_exit(&stack, "KO\n", 3, 1);
	free_list(&stack);
	return (0);
}

static void	init_stacks(t_stacks *stack)
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
}

/* exit fct for errors during parsing / input checking.
Frees already malloced nodes. */
void	err_exit(t_stacks *stack, char *msg, int len, int fd)
{
	free_list(stack);
	write(fd, msg, len);
	exit(0);
}

void	free_two_d_arr(int **lis_arr, int i)
{
	while (i > 0)
	{
		free(lis_arr[i - 1]);
		lis_arr[i] = NULL;
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
