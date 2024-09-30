/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:51:01 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/30 19:29:07 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_a_to_top(t_stack *a, int target_index)
{
	if (target_index <= stack_size(a) / 2)
	{
		while (target_index-- > 0)
			ra(a, 1);
	}
	else
	{
		while (target_index++ < stack_size(a))
			rra(a, 1);
	}
}

void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	size_a;
	int	mid_point;

	// int	chunk_size;
	size_a = stack_size(a);
	// chunk_size = size_a / 4; // Adjust this value to optimize performance
	while (size_a > 3)
	{
		mid_point = find_mid_point(a);
		while (stack_size(a) > 3 && within_chunk_range(a, INT_MIN, mid_point))
		{
			if (a->top->value <= mid_point)
			{
				pb(a, b, 1);
				if (b->size > 1 && b->top->value < find_mid_point(b))
					rb(b, 1);
			}
			else
				ra(a, 1);
		}
		size_a = stack_size(a);
	}
	sort_3(a);
}

void	push_back_sorted(t_stack *a, t_stack *b)
{
	int	max_value;
	int	target_pos;
	int	min_pos;

	while (stack_size(b) > 0)
	{
		max_value = find_largest_elem(b);
		rotate_stack_b_to_top(b, max_value);
		if (stack_size(a) == 0)
		{
			pa(a, b, 1);
		}
		else if (stack_size(a) == 1)
		{
			if (b->top->value > a->top->value)
			{
				pa(a, b, 1);
				sa(a, 1);
			}
			else
			{
				pa(a, b, 1);
			}
		}
		else
		{
			target_pos = find_insert_position(a, b->top->value);
			rotate_stack_a_to_position(a, target_pos);
			pa(a, b, 1);
		}
	}
	// Final rotation to ensure the smallest element is at the top
	min_pos = find_elem_index(a, find_smallest_elem(a));
	rotate_stack_a_to_position(a, min_pos);
}

void	sort_6_plus(t_stack *a, t_stack *b)
{
	push_chunks_to_b(a, b);
	push_back_sorted(a, b);
}
