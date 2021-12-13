/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:29:26 by fbechtol          #+#    #+#             */
/*   Updated: 2021/12/10 13:32:17 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	create_or_add_b(t_stacks *stack);
static void	create_or_add_a(t_stacks *stack);

/* Take first element at top of a, put it at top of b. 
Does nothing if a is empty. 
a_empty flag: last element was pushed to b*/
void	push_b(t_stacks *stack)
{
	int	a_empty;

	a_empty = FALSE;
	if (stack->head_a == NULL)
		return ;
	stack->a = stack->head_a;
	if (stack->tail_a->next == stack->tail_a)
		a_empty = TRUE;
	stack->b = stack->a;
	stack->head_a->next->prev = stack->tail_a;
	stack->tail_a->next = stack->head_a->next;
	stack->head_a = stack->tail_a->next;
	create_or_add_b(stack);
	if (a_empty == TRUE)
	{
		stack->a = NULL;
		stack->head_a = NULL;
	}
	stack->len_a--;
	stack->len_b++;
}

static void	create_or_add_b(t_stacks *stack)
{
	if (stack->head_b == NULL)
	{
		stack->head_b = stack->b;
		stack->tail_b = stack->b;
		stack->b->next = stack->head_b;
		stack->b->prev = stack->tail_b;
	}
	else
	{
		stack->b->next = stack->head_b;
		stack->head_b->prev = stack->b;
		stack->b->prev = stack->tail_b;
		stack->tail_b->next = stack->b;
		stack->head_b = stack->b;
	}
}

/* Take first element at top of b, put it at top of a. 
Does nothing if b is empty. 
b_empty flag: last element was pushed to a*/
void	push_a(t_stacks *stack)
{
	int	b_empty;

	b_empty = FALSE;
	if (stack->head_b == NULL)
		return ;
	stack->b = stack->head_b;
	if (stack->tail_b->next == stack->tail_b)
		b_empty = TRUE;
	stack->a = stack->b;
	stack->head_b->next->prev = stack->tail_b;
	stack->tail_b->next = stack->head_b->next;
	stack->head_b = stack->tail_b->next;
	create_or_add_a(stack);
	if (b_empty == TRUE)
	{
		stack->b = NULL;
		stack->head_b = NULL;
	}
	stack->len_a++;
	stack->len_b--;
}

static void	create_or_add_a(t_stacks *stack)
{
	if (stack->head_a == NULL)
	{
		stack->head_a = stack->a;
		stack->tail_a = stack->a;
		stack->a->next = stack->head_a;
		stack->a->prev = stack->tail_a;
	}
	else
	{
		stack->a->next = stack->head_a;
		stack->head_a->prev = stack->a;
		stack->a->prev = stack->tail_a;
		stack->tail_a->next = stack->a;
		stack->head_a = stack->a;
	}
}
