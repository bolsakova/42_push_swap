/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:46:00 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/27 18:51:08 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	swap(t_stack *stack, int check)
// {
// 	t_node	*first;
// 	t_node	*second;

// 	if (check == 1)
// 	{
// 		if (stack == 'a')
// 			write(1, "sa\n", 3);
// 		else if (stack == 'b')
// 			write(1, "sb\n", 3);
// 	}
// 	if (!stack || !stack->top || stack->top->next)
// 		return ;
// 	first = stack->top;
// 	second = first->next;
// 	first->next = second->next;
// 	second->next = first;
// 	stack->top = second;
// }

void	sa(t_stack *stack, int check)
{
	t_node	*first;
	t_node	*second;

	if (check == 1)
		write(1, "sa\n", 3);
	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sb(t_stack *stack, int check)
{
	t_node	*first;
	t_node	*second;

	if (check == 1)
		write(1, "sb\n", 3);
	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	ss(t_stack *a, t_stack *b)
{
	if (a && b)
	{
		sa(a, 0);
		sb(b, 0);
		write(1, "ss\n", 3);
	}
}
