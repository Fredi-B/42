/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:09:07 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/09 13:23:08 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	**malloc_lis(t_stacks *stack);
static int	add_new_row(t_stacks *stack, int **lis_arr, int counter);
static void	replace_row(t_stacks *stack, int **lis_arr, int counter);

void	get_long_inc_sub(t_stacks *stack)
{
	int	**lis_arr;
	int	counter;

	stack->a = stack->head_a;
	lis_arr = malloc_lis(stack);
	lis_arr[0][0] = stack->a->nbr;
	counter = 0;
	while (TRUE)
	{
		if (stack->a->nbr <= lis_arr[0][0])
			lis_arr[0][0] = stack->a->nbr;
		else if (stack->a->nbr > lis_arr[counter][counter])
			counter = add_new_row(stack, lis_arr, counter);
		else
			replace_row(stack, lis_arr, counter);
		if (stack->a->next == stack->head_a)
			break ;
		stack->a = stack->a->next;
	}
	stack->long_inc_sub = ft_int_strdup(lis_arr[counter], counter + 1);
	stack->len_lis = counter;
	free_two_d_arr(lis_arr, stack->len_a);
}

static int	add_new_row(t_stacks *stack, int **lis_arr, int counter)
{
	int	new_row;
	int	collum;

	new_row = counter + 1;
	collum = counter;
	lis_arr[new_row][collum + 1] = stack->a->nbr;
	while (collum >= 0)
	{
		lis_arr[new_row][collum] = lis_arr[counter][collum];
		collum--;
	}
	counter++;
	return (counter);
}

static void	replace_row(t_stacks *stack, int **lis_arr, int counter)
{
	int	end_elem;
	int	replaced_row;
	int	collum;

	end_elem = counter;
	while (end_elem >= 0)
	{
		if (stack->a->nbr > lis_arr[end_elem][end_elem])
		{
			replaced_row = end_elem + 1;
			collum = end_elem;
			lis_arr[replaced_row][collum + 1] = stack->a->nbr;
			while (collum >= 0)
			{
				lis_arr[replaced_row][collum] = lis_arr[end_elem][collum];
				collum--;
			}
			break ;
		}
		end_elem--;
	}
}

static int	**malloc_lis(t_stacks *stack)
{
	int	**lis_arr;
	int	i;

	lis_arr = (int **)malloc(sizeof(int **) * stack->len_a);
	if (!lis_arr)
		err_exit(stack, "Error", 6);
	i = 0;
	while (i < stack->len_a)
	{
		lis_arr[i] = (int *)malloc(sizeof(int *) * (i + 1));
		if (!lis_arr[i])
		{
			free_two_d_arr(lis_arr, i);
			err_exit(stack, "Error", 6);
		}
		i++;
	}
	return (lis_arr);
}
