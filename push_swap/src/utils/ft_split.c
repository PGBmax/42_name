/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:36:47 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/23 01:36:47 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_free_tab(char **splitted, int nb_elem)
{
	while (nb_elem >= 0)
	{
		free(splitted[nb_elem]);
		nb_elem --;
	}
	free(splitted);
}

static char	**ft_fill_tab(char	**splitted, char const *s, char c, int nb_nb)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < nb_nb)
	{
		n = ft_n_len(s, c, n, 0);
		splitted[i] = ft_substr(s, n, ft_n_len(s, c, n, 1));
		if (!splitted)
		{
			ft_free_tab(splitted, i);
			return (NULL);
		}
		n = n + ft_n_len(s, c, n, 1);
		i ++;
	}
	splitted[i] = 0;
	return (splitted);
}

static int	ft_n_len(char const *s, char c, int index, int chc)
{
	int	res;

	res = 0;
	if (chc == 0)
	{
		res = index;
		while (s[res] == c && s[res] != 0)
			res ++;
	}
	else
	{
		while (s[index + res] != c && s[index + res] != 0)
			res ++;
	}
	return (res);
}

static int	ft_find_nb_nb(char const *str, char stop)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[i] != stop && str[i] != 0)
		res ++;
	while (str[i] != 0)
	{
		if (str[i] == stop)
		{
			while (str[i] == stop && str[i] != 0)
				i ++;
			if (str[i] != 0)
				res ++;
		}
		else
			i ++;
	}
	return (res);
}

char	**ft_split(char const *s, char c, int *nb_nb)
{
	char	**splitted;

	if (!s)
		return (NULL);
	*nb_nb = ft_find_nb_nb(s, c);
	splitted = malloc((*nb_nb + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	splitted = ft_fill_tab(splitted, s, c, *nb_nb);
	if (!splitted)
		return (NULL);
	return (splitted);
}