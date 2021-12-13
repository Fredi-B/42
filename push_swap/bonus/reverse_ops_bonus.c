/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:17:48 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/10 13:32:30 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* Shift down all elements of stack a by 1.
The last element becomes the first one. */
void	reverse_a(t_stacks *stack)
{
	if (stack->head_a == NULL)
		return ;
	stack->head_a = stack->tail_a;
	stack->tail_a = stack->tail_a->prev;
}

/* Shift down all elements of stack b by 1.
The last element becomes the first one. */
void	reverse_b(t_stacks *stack)
{
	if (stack->head_b == NULL)
		return ;
	stack->head_b = stack->tail_b;
	stack->tail_b = stack->tail_b->prev;
}

/* Shift down all elements of stack a and b by 1.
The last elements become the first ones. */
void	reverse_a_b(t_stacks *stack)
{
	if (stack->head_b == NULL || stack->head_a == NULL)
		return ;
	stack->head_a = stack->tail_a;
	stack->tail_a = stack->tail_a->prev;
	stack->head_b = stack->tail_b;
	stack->tail_b = stack->tail_b->prev;
}
