/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:30:03 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/27 18:35:55 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int checker)
{
	t_node	*first;
	t_node	*last;

	if (checker == 1)
		write(1, "ra\n", 3);
	if (a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	last = a->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rb(t_stack *b, int checker)
{
	t_node	*first;
	t_node	*last;

	if (checker == 1)
		write(1, "rb\n", 3);
	if (b->size < 2)
		return ;
	first = b->top;
	b->top = first->next;
	last = b->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rr(t_stack *a, t_stack *b, int checker)
{
	if (checker == 1)
		write(1, "rr\n", 3);
	ra(a, 0);
	rb(b, 0);
}
