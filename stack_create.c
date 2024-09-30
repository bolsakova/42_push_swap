/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:47:07 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/30 18:12:08 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		exit(1);
	}
	new_stack->top = NULL;
	new_stack->size = 0;
	return (new_stack);
}

void	add_node_to_stack(t_stack *stack, t_node *new_node)
{
	t_node	*tmp;

	if (!stack->top)
		stack->top = new_node;
	else
	{
		tmp = stack->top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->size = 0;
	free(stack);
}

void	create_stack(t_stack *stack, char **args, int num_args)
{
	t_node	*new_node;
	int		i;

	i = 0;
	while (i < num_args)
	{
		new_node = ft_nodenew(ft_atoi(args[i]));
		if (!new_node)
		{
			ft_putstr_fd("Error: Memory allocation failed\n", 2);
			free_stack(stack);
			return ;
		}
		add_node_to_stack(stack, new_node);
		stack->size++;
		i++;
	}
}
