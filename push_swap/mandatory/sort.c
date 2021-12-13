/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:22:13 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/08 13:27:40 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_unsorted_nbrs(t_stacks *stack);
static void	get_a_min_max(t_stacks *stack);
static void	min_to_top(t_stacks *stack);

void	sort(t_stacks *stack, t_rot *rot)
{
	if (stack->len_a <= 3)
		sort_three(stack);
	else if (stack->len_a <= 5)
		sort_five(stack);
	else
	{
		get_long_inc_sub(stack);
		push_unsorted_nbrs(stack);
		get_a_min_max(stack);
		while (stack->len_b > 0)
		{
			brute_search(stack, rot);
			brute_back(stack, rot);
		}
		min_to_top(stack);
	}
}

static void	push_unsorted_nbrs(t_stacks *stack)
{
	int		i;
	int		len_unsorted_nbrs;
	t_node	*tmp_a;

	stack->a = stack->head_a;
	i = 0;
	len_unsorted_nbrs = stack->len_a - stack->len_lis - 1;
	while (stack->len_b < len_unsorted_nbrs)
	{
		if (stack->a->nbr == stack->long_inc_sub[i])
		{
			rotate_a(stack);
			stack->a = stack->a->next;
			i++;
		}
		else
		{
			tmp_a = stack->a->next;
			push_b(stack);
			stack->a = tmp_a;
		}
	}
	free(stack->long_inc_sub);
	stack->a = stack->head_a;
}

/* gets min and max from the sorted numbers */
static void	get_a_min_max(t_stacks *stack)
{
	int	tmp_len_a;

	stack->a = stack->head_a;
	tmp_len_a = stack->len_a;
	while (tmp_len_a >= 0)
	{
		if (stack->a->nbr < stack->a_min)
			stack->a_min = stack->a->nbr;
		stack->a = stack->a->next;
		tmp_len_a--;
	}
	tmp_len_a = stack->len_a;
	while (tmp_len_a >= 0)
	{
		if (stack->a->nbr > stack->a_max)
			stack->a_max = stack->a->nbr;
		stack->a = stack->a->next;
		tmp_len_a--;
	}
	stack->a = stack->head_a;
}

static void	min_to_top(t_stacks *stack)
{
	int	i;

	stack->a = stack->head_a;
	i = 0;
	while (stack->a->nbr != stack->a_min)
	{
		i++;
		stack->a = stack->a->next;
	}
	if (i < stack->len_a / 2)
	{
		while (i > 0)
		{
			rotate_a(stack);
			i--;
		}
	}
	else
	{
		while (i < stack->len_a)
		{
			reverse_a(stack);
			i++;
		}
	}
}
