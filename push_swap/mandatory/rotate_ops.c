/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:18:07 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/08 13:18:08 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift up all elements of stack a by 1.
The first element becomes the last one. */
void	rotate_a(t_stacks *stack)
{
	if (stack->head_a == NULL)
		return ;
	stack->tail_a = stack->head_a;
	stack->head_a = stack->head_a->next;
	write(1, "ra\n", 3);
}

/* Shift up all elements of stack b by 1.
The first element becomes the last one. */
void	rotate_b(t_stacks *stack)
{
	if (stack->head_b == NULL)
		return ;
	stack->tail_b = stack->head_b;
	stack->head_b = stack->head_b->next;
	write(1, "rb\n", 3);
}

/* Shift up all elements of stack a and b by 1.
The first elements become the last ones.  */
void	rotate_a_b(t_stacks *stack)
{
	if (stack->head_b == NULL || stack->head_a == NULL)
		return ;
	stack->tail_a = stack->head_a;
	stack->head_a = stack->head_a->next;
	stack->tail_b = stack->head_b;
	stack->head_b = stack->head_b->next;
	write(1, "rr\n", 3);
}
