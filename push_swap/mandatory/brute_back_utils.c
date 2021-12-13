/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_back_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:40:09 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/08 10:40:11 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_small_smaller(t_stacks *stack, t_rot *rot)
{
	while (rot->b > 0)
	{
		if (stack->head_a == NULL || stack->head_b == NULL)
			break ;
		rotate_a_b(stack);
		rot->b--;
		rot->total--;
	}
	while (rot->total > 0)
	{
		rotate_a(stack);
		rot->total--;
	}
	if (stack->head_b->nbr > stack->a_max)
		stack->a_max = stack->head_b->nbr;
	if (stack->head_b->nbr < stack->a_min)
		stack->a_min = stack->head_b->nbr;
	push_a(stack);
}

void	push_smaller_small(t_stacks *stack, t_rot *rot)
{
	while (rot->a > 0)
	{
		rotate_a_b(stack);
		rot->a--;
		rot->total--;
	}
	while (rot->total > 0)
	{
		rotate_b(stack);
		rot->total--;
	}
	if (stack->head_b->nbr > stack->a_max)
		stack->a_max = stack->head_b->nbr;
	if (stack->head_b->nbr < stack->a_min)
		stack->a_min = stack->head_b->nbr;
	push_a(stack);
}

void	push_small_big(t_stacks *stack, t_rot *rot)
{
	while (rot->a > 0)
	{
		rotate_a(stack);
		rot->a--;
	}
	while (rot->b > 0)
	{
		reverse_b(stack);
		rot->b--;
	}
	if (stack->head_b->nbr > stack->a_max)
		stack->a_max = stack->head_b->nbr;
	if (stack->head_b->nbr < stack->a_min)
		stack->a_min = stack->head_b->nbr;
	push_a(stack);
}

void	push_big_small(t_stacks *stack, t_rot *rot)
{
	while (rot->a > 0)
	{
		reverse_a(stack);
		rot->a--;
	}
	while (rot->b > 0)
	{
		rotate_b(stack);
		rot->b--;
	}
	if (stack->head_b->nbr > stack->a_max)
		stack->a_max = stack->head_b->nbr;
	if (stack->head_b->nbr < stack->a_min)
		stack->a_min = stack->head_b->nbr;
	push_a(stack);
}

void	push_big_big(t_stacks *stack, t_rot *rot)
{
	while (rot->a > 0 && rot->b > 0)
	{
		if (stack->head_a == NULL || stack->head_b == NULL)
			break ;
		reverse_a_b(stack);
		rot->a--;
		rot->b--;
	}
	while (rot->a > 0)
	{
		reverse_a(stack);
		rot->a--;
	}
	while (rot->b > 0)
	{
		reverse_b(stack);
		rot->b--;
	}
	if (stack->head_b->nbr > stack->a_max)
		stack->a_max = stack->head_b->nbr;
	if (stack->head_b->nbr < stack->a_min)
		stack->a_min = stack->head_b->nbr;
	push_a(stack);
}
