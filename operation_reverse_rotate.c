/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:45:33 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/27 16:29:09 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int checker)
{
	t_node	*last;
	t_node	*second_last;

	if (checker == 1)
		write(1, "rra\n", 4);
	if (a->size < 2)
		return ;
	last = a->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = a->top;
	a->top = last;
}

void	rrb(t_stack *b, int checker)
{
	t_node	*last;
	t_node	*second_last;

	if (checker == 1)
		write(1, "rrb\n", 4);
	if (b->size < 2)
		return ;
	last = b->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = b->top;
	b->top = last;
}

void	rrr(t_stack *a, t_stack *b, int checker)
{
	if (checker == 1)
		write(1, "rrr\n", 4);
	rra(a, 0);
	rrb(b, 0);
}
