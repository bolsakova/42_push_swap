/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:17:07 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/01 13:19:42 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (-1);
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

void	rotate_stack_a_to_position(t_stack *a, int target_pos)
{
	int	current_size;

	current_size = stack_size(a);
	if (target_pos <= current_size / 2)
	{
		while (target_pos-- > 0)
			ra(a, 1);
	}
	else
	{
		while (target_pos++ < current_size)
			rra(a, 1);
	}
}
