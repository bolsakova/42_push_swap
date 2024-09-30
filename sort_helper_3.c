/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:20:37 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/30 15:13:54 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mid_point(t_stack *stack)
{
	int		*arr;
	int		size;
	int		mid_point;
	int		i;
	t_node	*current;

	size = stack_size(stack);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	current = stack->top;
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	// Simple bubble sort to find the median
	for (i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
		}
	}
	mid_point = arr[size / 2];
	free(arr);
	return (mid_point);
}

int	find_next_largest_elem(t_stack *b, int max_value)
{
	int		next_max;
	t_node	*current;

	next_max = INT_MIN;
	current = b->top;
	while (current)
	{
		if (current->value < max_value && current->value > next_max)
			next_max = current->value;
		current = current->next;
	}
	return (next_max);
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

int	get_last_elem(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current->next)
		current = current->next;
	return (current->value);
}
