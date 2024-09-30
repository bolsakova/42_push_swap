/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:22:06 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/27 20:16:59 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, int checker)
{
	t_node	*top_b;

	if (b->size == 0)
		return ;
	top_b = b->top;
	b->top = top_b->next;
	top_b->next = a->top;
	a->top = top_b;
	b->size--;
	a->size++;
	if (checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int checker)
{
	t_node	*top_a;

	if (a->size == 0)
		return ;
	top_a = a->top;
	a->top = top_a->next;
	top_a->next = b->top;
	b->top = top_a;
	a->size--;
	b->size++;
	if (checker)
		write(1, "pb\n", 3);
}
