/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:23:34 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/10 13:32:44 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_stacks *stack)
{
	t_node	tmp;

	stack->a = stack->head_a;
	if (stack->head_a == NULL || stack->head_a->next == stack->head_a)
		return ;
	tmp.nbr = stack->a->nbr;
	stack->a->nbr = stack->a->next->nbr;
	stack->a->next->nbr = tmp.nbr;
}

void	swap_b(t_stacks *stack)
{
	t_node	tmp;

	stack->b = stack->head_b;
	if (stack->head_b == NULL || stack->head_b->next == stack->head_b)
		return ;
	tmp.nbr = stack->b->nbr;
	stack->b->nbr = stack->b->next->nbr;
	stack->b->next->nbr = tmp.nbr;
}

void	swap_a_b(t_stacks *stack)
{
	t_node	tmp;

	stack->a = stack->head_a;
	stack->b = stack->head_b;
	if (stack->head_a == NULL || stack->head_a->next == stack->head_a \
		|| stack->head_b == NULL || stack->head_b->next == stack->head_b)
		return ;
	tmp.nbr = stack->a->nbr;
	stack->a->nbr = stack->a->next->nbr;
	stack->a->next->nbr = tmp.nbr;
	tmp.nbr = stack->b->nbr;
	stack->b->nbr = stack->b->next->nbr;
	stack->b->next->nbr = tmp.nbr;
}
