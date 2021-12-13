/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:28:49 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/09 15:25:10 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	parse_nbrs(t_stacks *stack, char **nbrs, int index);
static void	create_stack_a(char *nbr, t_stacks *stack);

void	parse(int argc, char **argv, t_stacks *stack)
{
	char	**nbrs;
	int		i;
	int		index;

	stack->head_a = NULL;
	index = 0;
	i = 1;
	while (i < argc)
	{
		nbrs = ft_split(argv[i], ' ');
		if (!nbrs)
			err_exit(stack, "", 0, 2);
		parse_nbrs(stack, nbrs, index);
		free(nbrs);
		nbrs = NULL;
		i++;
	}
}

static void	parse_nbrs(t_stacks *stack, char **nbrs, int index)
{
	int	j;

	j = 0;
	while (nbrs[j])
	{
		index++;
		create_stack_a(nbrs[j], stack);
		free(nbrs[j]);
		nbrs[j] = NULL;
		j++;
	}
}

static void	create_stack_a(char *nbr, t_stacks *stack)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		err_exit(stack, "", 0, 2);
	stack->a = new_node;
	stack->a->nbr = ft_atoi(nbr);
	if (stack->head_a == NULL)
	{
		stack->head_a = new_node;
		stack->tail_a = new_node;
		stack->a->next = new_node;
		stack->a->prev = new_node;
	}
	else
	{
		stack->tail_a->next = new_node;
		new_node->prev = stack->tail_a;
		new_node->next = stack->head_a;
		stack->head_a->prev = new_node;
		stack->tail_a = new_node;
	}
	stack->len_a++;
}
