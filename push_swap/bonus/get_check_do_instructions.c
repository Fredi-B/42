/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_check_do_instructions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:44:06 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/10 14:03:28 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_instructions(t_stacks *stack, char *inst);
static void	do_instructions(t_stacks *stack, char *inst);

void	get_check_do_instructions(t_stacks *stack)
{
	char	*inst;

	while (TRUE)
	{
		inst = get_next_line(0);
		if (!inst)
			break ;
		check_instructions(stack, inst);
		do_instructions(stack, inst);
	}
}

static void	check_instructions(t_stacks *stack, char *inst)
{
	if (ft_strncmp(inst, "sa\n", 3) != 0 && ft_strncmp(inst, "sb\n", 3) != 0 && \
	ft_strncmp(inst, "ss\n", 3) != 0 && ft_strncmp(inst, "pa\n", 3) != 0 && \
	ft_strncmp(inst, "pb\n", 3) != 0 && ft_strncmp(inst, "rra\n", 4) != 0 && \
	ft_strncmp(inst, "ra\n", 3) != 0 && ft_strncmp(inst, "rrb\n", 4) != 0 && \
	ft_strncmp(inst, "rb\n", 3) != 0 && ft_strncmp(inst, "rrr\n", 4) != 0 && \
	ft_strncmp(inst, "rr\n", 3) != 0)
	{
		free(inst);
		err_exit(stack, "Error\n", 6, 2);
	}
}

static void	do_instructions(t_stacks *stack, char *inst)
{
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		swap_a(stack);
	if (ft_strncmp(inst, "sb\n", 3) == 0)
		swap_b(stack);
	if (ft_strncmp(inst, "ss\n", 3) == 0)
		swap_a_b(stack);
	if (ft_strncmp(inst, "pa\n", 3) == 0)
		push_a(stack);
	if (ft_strncmp(inst, "pb\n", 3) == 0)
		push_b(stack);
	if (ft_strncmp(inst, "ra\n", 3) == 0)
		rotate_a(stack);
	if (ft_strncmp(inst, "rb\n", 3) == 0)
		rotate_b(stack);
	if (ft_strncmp(inst, "rr\n", 3) == 0)
		rotate_a_b(stack);
	if (ft_strncmp(inst, "rra\n", 4) == 0)
		reverse_a(stack);
	if (ft_strncmp(inst, "rrb\n", 4) == 0)
		reverse_b(stack);
	if (ft_strncmp(inst, "rrr\n", 4) == 0)
		reverse_a_b(stack);
	free(inst);
}
