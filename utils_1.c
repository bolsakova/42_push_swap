/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:24:45 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/24 17:47:53 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

t_node	*ft_nodenew(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node)
	{
		new_node->value = value;
		new_node->next = NULL;
	}
	return (new_node);
}

size_t	ft_strlcpy(char *dest, const char *source, size_t size)
{
	size_t	i;
	size_t	source_len;

	i = 0;
	source_len = 0;
	while (source[source_len])
		source_len++;
	if (size == 0)
		return (source_len);
	while (i < size - 1 && source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (source_len);
}

int	ft_atoi(const char *ptr)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (ptr[i] && ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32))
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i + 1] == '+' || ptr[i + 1] == '-' || !('0' <= ptr[i + 1]
				&& ptr[i + 1] <= '9'))
			return (0);
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ptr[i] && ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = (result * 10) + (ptr[i] - '0');
		i++;
	}
	return (result * sign);
}
