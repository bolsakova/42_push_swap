/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:55:55 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/01 13:27:45 by tbolsako         ###   ########.fr       */
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
