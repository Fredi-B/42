/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:18:30 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/08 13:18:31 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	part_two_sort_three(t_stacks *stack);
static void	rotate_smallest_nbr_to_top(t_stacks *stack);
static int	get_index_smallest_nbr(t_stacks *stack);

void	sort_three(t_stacks *stack)
{
	if (is_sorted(stack) == TRUE)
		return ;
	stack->a = stack->head_a;
	if (stack->len_a == 2)
	{
		swap_a(stack);
		return ;
	}
	if (stack->a->nbr > stack->a->next->nbr)
	{
		if (stack->a->next->nbr < stack->a->next->next->nbr && \
			stack->a->nbr < stack->a->next->next->nbr)
			swap_a(stack);
		else if (stack->a->next->nbr < stack->a->next->next->nbr && \
			stack->a->nbr > stack->a->next->next->nbr)
			rotate_a(stack);
		else
		{
			swap_a(stack);
			reverse_a(stack);
		}
	}
	else
		part_two_sort_three(stack);
}

static void	part_two_sort_three(t_stacks *stack)
{
	if (stack->a->next->nbr > stack->a->next->next->nbr && \
		stack->a->nbr > stack->a->next->next->nbr)
		reverse_a(stack);
	else
	{
		swap_a(stack);
		rotate_a(stack);
	}
}

void	sort_five(t_stacks *stack)
{
	while (stack->len_a > 3)
	{
		stack->a = stack->head_a;
		rotate_smallest_nbr_to_top(stack);
		push_b(stack);
	}
	sort_three(stack);
	while (stack->len_b > 0)
		push_a(stack);
}

static void	rotate_smallest_nbr_to_top(t_stacks *stack)
{
	int	index;

	index = get_index_smallest_nbr(stack);
	if (index <= stack->len_a / 2)
	{
		while (index > 1)
		{
			rotate_a(stack);
			index--;
		}
	}
	else
	{
		while (index <= stack->len_a)
		{
			reverse_a(stack);
			index++;
		}
	}
}

static int	get_index_smallest_nbr(t_stacks *stack)
{
	t_node	*tmp;
	int		i;
	int		index;

	tmp = stack->head_a;
	i = 0;
	while (i < stack->len_a)
	{
		if (stack->a->next->nbr < tmp->nbr)
			tmp = stack->a->next;
		stack->a = stack->a->next;
		i++;
	}
	index = 1;
	stack->a = stack->head_a;
	while (stack->a->nbr != tmp->nbr)
	{
		index++;
		stack->a = stack->a->next;
	}
	return (index);
}
