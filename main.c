/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:19:41 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/30 19:03:21 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **splited_arg)
{
	int	i;

	i = 0;
	while (splited_arg[i])
	{
		free(splited_arg[i++]);
	}
	free(splited_arg);
}

static void	handle_single_arg(char *av[], t_stack *a, t_stack *b)
{
	char	**splited_arg;
	int		num_args;

	splited_arg = ft_split(av[1], 32, a, b);
	num_args = 0;
	while (splited_arg[num_args])
		num_args++;
	if (validate_input(splited_arg, num_args))
	{
		free_stack(a);
		free_stack(b);
		free(splited_arg);
		exit(1);
	}
	create_stack(a, splited_arg, num_args);
	free_split(splited_arg);
}

static void	handle_multiple_args(int ac, char *av[], t_stack *a, t_stack *b)
{
	if (validate_input(av + 1, ac - 1))
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	create_stack(a, av + 1, ac - 1);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	a->size = stack_size(a);
	if (check_if_sorted(a) == 1)
	{
		if (a->size == 2)
			sa(a, 1);
		else if (a->size == 3)
			sort_3(a);
		else if (a->size == 4 || a->size == 5)
			sort_4_or_5(a, b);
		else if (a->size >= 6)
			sort_6_plus(a, b);
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack();
	b = init_stack();
	if (ac < 2 || !av[1][0])
	{
		ft_putstr_fd("Error: No input\n", 2);
		return (1);
	}
	if (ac == 2 && av[1][0])
		handle_single_arg(av, a, b);
	else if (ac > 2)
		handle_multiple_args(ac, av, a, b);
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
