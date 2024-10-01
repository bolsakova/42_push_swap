/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:26:10 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/01 12:36:06 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_helper(t_stack *a, long top, long mid, long bott)
{
	if (top > mid && mid < bott && top < bott)
		sa(a, 1);
	else if (top > mid && mid < bott && top > bott)
		ra(a, 1);
	else if (top < mid && mid > bott && top < bott)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (top > mid && mid > bott)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (top < mid && mid > bott && top > bott)
		rra(a, 1);
}

void	sort_3(t_stack *a)
{
	long	top;
	long	mid;
	long	bott;

	if (!a || !a->top || !a->top->next)
		return ;
	top = a->top->value;
	mid = a->top->next->value;
	bott = a->top->next->next->value;
	if (top < mid && mid < bott)
		return ;
	sort_3_helper(a, top, mid, bott);
}

int	find_smallest(t_stack *stack)
{
	int		smallest;
	t_node	*current;

	if (!stack || !stack->top)
		return (INT_MAX);
	smallest = stack->top->value;
	current = stack->top;
	while (current)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

int	pos_of_smallest(t_stack *stack)
{
	int		pos;
	int		pos_of_smallest;
	int		smallest;
	t_node	*current;

	if (!stack || !stack->top)
		return (-1);
	smallest = stack->top->value;
	pos = 0;
	pos_of_smallest = 0;
	current = stack->top;
	while (current)
	{
		if (current->value < smallest)
		{
			smallest = current->value;
			pos_of_smallest = pos;
		}
		current = current->next;
		pos++;
	}
	return (pos_of_smallest);
}

void	sort_4_or_5(t_stack *a, t_stack *b)
{
	int	smallest;

	while (stack_size(a) > 3)
	{
		smallest = find_smallest(a);
		while (a->top->value != smallest)
		{
			if (pos_of_smallest(a) <= stack_size(a) / 2)
				ra(a, 1);
			else
				rra(a, 1);
		}
		pb(a, b, 1);
	}
	sort_3(a);
	while (stack_size(b) > 0)
		pa(a, b, 1);
}
