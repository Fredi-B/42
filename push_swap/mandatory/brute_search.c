/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:07:03 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/08 11:07:06 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	search_in_b(t_stacks *stack, t_rot *rot);
static void	update_rot(t_rot *rot);

void	brute_search(t_stacks *stack, t_rot *rot)
{
	int	i;

	rot->tmp_a = 0;
	rot->total = INT_MAX;
	i = 0;
	while (i < stack->len_a)
	{
		search_in_b(stack, rot);
		rot->tmp_a++;
		stack->a = stack->a->next;
		i++;
	}
}

static void	search_in_b(t_stacks *stack, t_rot *rot)
{
	int	i;

	rot->tmp_b = 0;
	i = 0;
	while (i < stack->len_b)
	{
		if ((stack->b->nbr > stack->a_max && \
			stack->a->prev->nbr == stack->a_max) \
			|| (stack->b->nbr < stack->a_min && \
			stack->a->nbr == stack->a_min) \
			|| (stack->b->nbr < stack->a->nbr && \
			stack->b->nbr > stack->a->prev->nbr))
		{
			rot->tmp_a_b_pos = get_pos(stack, rot);
			rot->relative_total = get_total_rot \
					(rot->tmp_a, rot->tmp_b, stack, rot);
			if (rot->relative_total < rot->total)
				update_rot(rot);
		}
		rot->tmp_b++;
		stack->b = stack->b->next;
		i++;
	}
}

static void	update_rot(t_rot *rot)
{
	rot->a = rot->relative_a;
	rot->b = rot->relative_b;
	rot->total = rot->relative_total;
	rot->a_b_pos = rot->tmp_a_b_pos;
}
