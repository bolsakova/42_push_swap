/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:40:25 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/30 18:58:47 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_num(char *str)
{
	if (!str || *str == '\0')
		return (1);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

static int	check_if_repetitions(char *str_arr[], int index, int len)
{
	int	next_index;

	while (index < len - 1)
	{
		next_index = index + 1;
		while (next_index < len)
		{
			if (ft_strcmp(str_arr[index], str_arr[next_index]) == 0)
				return (1);
			next_index++;
		}
		index++;
	}
	return (0);
}

static long	check_max_min_int(char *str)
{
	long	num;
	int		sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	num = 0;
	while (*str)
	{
		if (!isdigit(*str))
			return (1);
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num > (long)(INT_MAX)
				+ 1))
			return (1);
		str++;
	}
	num *= sign;
	return (0);
}

int	validate_input(char **splited_str, int num_args)
{
	int	i;

	i = 0;
	while (splited_str[i])
	{
		if (check_if_num(splited_str[i]) == 1)
		{
			ft_putstr_fd("Error: not numbers.\n", 2);
			return (1);
		}
		else if (check_if_repetitions(splited_str, 0, num_args) == 1)
		{
			ft_putstr_fd("Error: repetitions.\n", 2);
			return (1);
		}
		else if (check_max_min_int(splited_str[i]) == 1)
		{
			ft_putstr_fd("Error: number out of range.\n", 2);
			return (1);
		}
		else if (splited_str[1] == NULL)
		{
			free(splited_str);
			return (1);
		}
		i++;
	}
	return (0);
}
