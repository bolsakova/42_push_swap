/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:55:55 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/30 15:21:25 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	return (stack->size);
}

int	check_if_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	if (!current || !current->next)
		return (0);
	while (current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	within_chunk_range(t_stack *a, int min, int max)
{
	t_node	*current;

	current = a->top;
	while (current != NULL)
	{
		if (current->value >= min && current->value <= max)
			return (1);
		current = current->next;
	}
	return (0);
}

int	find_smallest_elem(t_stack *stack)
{
	int		smallest;
	t_node	*current;

	smallest = INT_MAX;
	current = stack->top;
	while (current)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

int	find_insert_position(t_stack *a, int value)
{
	t_node	*current;
	int		pos;
	int		size;
	int		smallest;
	int		largest;

	size = stack_size(a);
	if (size == 0)
		return (0);
	smallest = find_smallest_elem(a);
	largest = find_largest_elem(a);
	if (value < smallest || value > largest)
		return (find_elem_index(a, smallest));
	current = a->top;
	pos = 0;
	while (current->next)
	{
		if ((value > current->value && value < current->next->value)
			|| (current->value > current->next->value && (value > current->value
					|| value < current->next->value)))
			return ((pos + 1) % size);
		current = current->next;
		pos++;
	}
	return (0); // This line should never be reached
}
