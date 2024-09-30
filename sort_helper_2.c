/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:50:20 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/30 15:21:40 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_chunk_min(t_stack *a, int chunk_size)
{
	int		min_value;
	int		i;
	t_node	*current;

	min_value = a->top->value;
	current = a->top;
	i = 0;
	while (current != NULL && i < chunk_size)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
		i++;
	}
	return (min_value);
}

int	find_chunk_max(t_stack *a, int chunk_size)
{
	int		max_value;
	int		i;
	t_node	*current;

	max_value = a->top->value;
	i = 0;
	current = a->top;
	while (current != NULL && i < chunk_size)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
		i++;
	}
	return (max_value);
}

int	find_nearest_elem_in_range(t_stack *a, int min, int max)
{
	t_node	*current;
	int		i;
	int		diff;

	current = a->top;
	i = 0;
	diff = current->value - min;
	while (current != NULL)
	{
		if (current->value - min > diff)
		{
			diff = current->value - min;
			i++;
		}
		if (current->value - max > diff)
		{
			diff = current->value - max;
			i++;
		}
		current = current->next;
	}
	return (i);
}

int	find_largest_elem(t_stack *b)
{
	int		max_value;
	t_node	*current;

	max_value = b->top->value;
	current = b->top;
	while (current != NULL)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	return (max_value);
}

int	find_elem_index(t_stack *stack, int value)
{
	t_node	*current;
	int		index;

	current = stack->top;
	index = 0;
	while (current != NULL)
	{
		if (current->value == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1); // Value not found
}

void	rotate_stack_b_to_top(t_stack *b, int max_value)
{
	int	index;
	int	size;

	index = find_elem_index(b, max_value);
	size = stack_size(b);
	if (index <= size / 2)
	{
		while (b->top->value != max_value)
			rb(b, 1);
	}
	else
	{
		while (b->top->value != max_value)
			rrb(b, 1);
	}
}
