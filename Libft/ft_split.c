/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:44:25 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/10 12:44:25 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	j;
	char	last;

	last = c;
	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (last == c && str[i] != c)
			j++;
		last = str[i];
		i++;
	}
	return (j);
}

static char	**free_all(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split[i]);
	free(split);
	return (NULL);
}

static char	**ft_splited_split(char const *s, char c, char **split)
{
	size_t	tab[4];

	tab[0] = 0;
	tab[1] = 0;
	while (tab[1] < count_words(s, c) && s[tab[0]] != 0)
	{
		while (s[tab[0]] == c)
			tab[0]++;
		tab[2] = 0;
		while (s[tab[0] + tab[2]] != 0 && s[tab[0] + tab[2]] != c)
			tab[2]++;
		split[tab[1]] = malloc((tab[2] + 1) * sizeof(char ));
		if (!split[tab[1]])
			return (free_all(split));
		tab[3] = 0;
		while (tab[3] < tab[2])
			split[tab[1]][tab[3]++] = s[tab[0]++];
		split[tab[1]++][tab[3]] = 0;
	}
	split[tab[1]] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	else
		return (ft_splited_split(s, c, split));
}
