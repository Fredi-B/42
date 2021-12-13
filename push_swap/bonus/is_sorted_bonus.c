/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:09:51 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/13 15:50:45 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_is_sorted(t_stacks *stack);

/* Checks if input is already sorted. */
int	is_sorted(t_stacks *stack)
{
	if (stack->len_a < 2)
		return (TRUE);
	if (check_is_sorted(stack) == TRUE)
		return (TRUE);
	return (FALSE);
}

static int	check_is_sorted(t_stacks *stack)
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
			if (stack->a->nbr > tmp->nbr)
				break ;
			tmp = tmp->next;
			j++;
		}
		if (j < stack->len_a - 1 - i)
			break ;
		stack->a = stack->a->next;
		i++;
	}
	if (i == stack->len_a - 1 && j == stack->len_a - i)
		return (TRUE);
	return (FALSE);
}
