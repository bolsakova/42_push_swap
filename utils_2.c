/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:17:28 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/01 12:36:28 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*allocate_word(const char *str, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, i + 1);
	return (word);
}

static char	**allocate_split(char **split, char const *str, char a,
		size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		while (*str && *str == a)
			str++;
		split[i] = allocate_word(str, a);
		if (!split[i])
		{
			while (i > 0)
				free(split[--i]);
			free(split);
			return (NULL);
		}
		while (*str && *str != a)
			str++;
		i++;
	}
	split[count] = NULL;
	return (split);
}

char	**ft_split(char const *str, char c, t_stack *a, t_stack *b)
{
	char	**split;
	size_t	count;

	if (!str)
		return (NULL);
	count = count_words(str, c);
	if (count == 1)
	{
		printf("Nothing to do with one number\n");
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (allocate_split(split, str, c, count));
}
