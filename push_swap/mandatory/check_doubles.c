/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:07:49 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/08 11:07:50 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_stacks *stack)
{
	t_node	*tmp;
	int		i;
	int		j;

	stack->a = stack->head_a;
	i = 0;
	while (i < stack->len_a - 1)
	{
		tmp = stack->a->next;
		j = 0;
		while (j < stack->len_a - 1 - i)
		{
			if (stack->a->nbr == tmp->nbr)
				err_exit(stack, "Error\n", 6);
			tmp = tmp->next;
			j++;
		}
		stack->a = stack->a->next;
		i++;
	}
}
