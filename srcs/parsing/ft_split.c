/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:48:42 by aait-ela          #+#    #+#             */
/*   Updated: 2025/12/25 10:52:28 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *str, char delimeter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((i == 0 || str[i - 1] == delimeter) && str[i] != delimeter)
			count++;
		i++;
	}
	return (count);
}

static char	*word_dup(char const *str, int start, int len)
{
	int		i;
	char	*splitted;

	splitted = malloc(len + 1);
	if (!splitted)
		return (NULL);
	i = 0;
	while (i < len)
	{
		splitted[i] = str[i + start];
		i++;
	}
	splitted[i] = '\0';
	return (splitted);
}

static char	**free_all(char **new, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(new[i]);
		i++;
	}
	free(new);
	return (NULL);
}

char	**fill_result(char **new, char const *str, char delimeter)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == delimeter)
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && str[i] != delimeter)
			i++;
		new[j] = word_dup(str, start, i - start);
		if (!new[j])
			return (free_all(new, j));
		j++;
	}
	new[j] = NULL;
	return (new);
}

char	**ft_split(char const *str, char delimeter)
{
	char	**new;

	if (!str)
		return (NULL);
	new = malloc(sizeof(char *) * (count_words(str, delimeter) + 1));
	if (!new)
		return (NULL);
	return (fill_result(new, str, delimeter));
}
