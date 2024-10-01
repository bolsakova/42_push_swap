/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:51:01 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/01 12:58:40 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	size_a;
	int	mid_point;

	size_a = stack_size(a);
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

static void	handle_push_to_a(t_stack *a, t_stack *b)
{
	int	target_pos;

	if (stack_size(a) == 0)
		pa(a, b, 1);
	else if (stack_size(a) == 1)
	{
		if (b->top->value > a->top->value)
		{
			pa(a, b, 1);
			sa(a, 1);
		}
		else
			pa(a, b, 1);
	}
	else
	{
		target_pos = find_insert_position(a, b->top->value);
		rotate_stack_a_to_position(a, target_pos);
		pa(a, b, 1);
	}
}

void	push_back_sorted(t_stack *a, t_stack *b)
{
	int	max_value;
	int	min_pos;

	while (stack_size(b) > 0)
	{
		max_value = find_largest_elem(b);
		rotate_stack_b_to_top(b, max_value);
		handle_push_to_a(a, b);
	}
	min_pos = find_elem_index(a, find_smallest_elem(a));
	rotate_stack_a_to_position(a, min_pos);
}

void	sort_6_plus(t_stack *a, t_stack *b)
{
	push_chunks_to_b(a, b);
	push_back_sorted(a, b);
}
