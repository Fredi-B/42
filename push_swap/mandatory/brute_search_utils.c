/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_search_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:57:51 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/08 10:57:53 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	part_two(int a, int b, t_rot *rot);
static int	part_three(int a, int b, t_stacks *stack, t_rot *rot);

int	get_pos(t_stacks *stack, t_rot *rot)
{
	if (rot->tmp_a <= stack->len_a / 2)
	{
		if (rot->tmp_b <= stack->len_b / 2)
			return (SMALL_A_SMALL_B);
		else
			return (SMALL_A_BIG_B);
	}
	else
	{
		if (rot->tmp_b <= stack->len_b / 2)
			return (BIG_A_SMALL_B);
		else
			return (BIG_A_BIG_B);
	}
}

int	get_total_rot(int a, int b, t_stacks *stack, t_rot *rot)
{
	int	total;

	if (rot->tmp_a_b_pos == SMALL_A_SMALL_B)
		total = part_two(a, b, rot);
	else if (rot->tmp_a_b_pos == BIG_A_BIG_B)
		total = part_three(a, b, stack, rot);
	else if (rot->tmp_a_b_pos == SMALL_A_BIG_B)
	{
		rot->relative_a = a;
		rot->relative_b = stack->len_b - b;
		total = a + rot->relative_b;
	}
	else
	{
		rot->relative_a = stack->len_a - a;
		rot->relative_b = b;
		total = rot->relative_a + b;
	}
	return (total);
}

static int	part_two(int a, int b, t_rot *rot)
{
	int	total;

	if (a > b)
	{
		rot->relative_a = a;
		rot->relative_b = b;
		total = a;
		rot->tmp_a_b_pos = SMALL_A_SMALLER_B;
	}
	else
	{
		rot->relative_a = a;
		rot->relative_b = b;
		total = b;
		rot->tmp_a_b_pos = SMALLER_A_SMALL_B;
	}
	return (total);
}

static int	part_three(int a, int b, t_stacks *stack, t_rot *rot)
{
	int	total;

	rot->relative_a = stack->len_a - a;
	rot->relative_b = stack->len_b - b;
	if (rot->relative_a > rot->relative_b)
	{
		total = rot->relative_a;
		rot->tmp_a_b_pos = BIGGER_A_BIG_B;
	}
	else
	{
		total = rot->relative_b;
		rot->tmp_a_b_pos = BIG_A_BIGGER_B;
	}
	return (total);
}
