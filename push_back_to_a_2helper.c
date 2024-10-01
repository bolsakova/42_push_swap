/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a_2helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:20:25 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/01 13:25:18 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (0);
}
