/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:40:41 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/08 10:40:44 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	brute_back(t_stacks *stack, t_rot *rot)
{
	if (rot->a_b_pos == SMALL_A_SMALLER_B)
		push_small_smaller(stack, rot);
	else if (rot->a_b_pos == SMALLER_A_SMALL_B)
		push_smaller_small(stack, rot);
	else if (rot->a_b_pos == SMALL_A_BIG_B)
		push_small_big(stack, rot);
	else if (rot->a_b_pos == BIG_A_SMALL_B)
		push_big_small(stack, rot);
	else
		push_big_big(stack, rot);
	stack->b = stack->head_b;
}
