/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:14:30 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/01 14:46:33 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	swapped;

	while (1)
	{
		i = 0;
		swapped = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			break ;
	}
}

int	find_mid_point(t_stack *stack)
{
	int		*arr;
	int		size;
	int		mid_point;
	t_node	*current;

	size = stack_size(stack);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	current = stack->top;
	size = 0;
	while (current)
	{
		arr[size++] = current->value;
		current = current->next;
	}
	bubble_sort(arr, size);
	mid_point = arr[size / 2];
	free(arr);
	return (mid_point);
}
