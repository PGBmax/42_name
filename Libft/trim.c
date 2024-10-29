/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melferre <melferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 00:39:49 by melferre          #+#    #+#             */
/*   Updated: 2024/10/21 23:07:32 by melferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*first_cut(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = (char *)s1;
	while (newstr[i])
	{
		while (set[j])
		{
			if (newstr[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
		{
			break ;
		}
		i++;
		j = 0;
	}
	return (&newstr[i]);
}

char	*sec_cut(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = (char *)s1;
	while (newstr[i])
		i++;
	i = i - 1;
	while (i >= 0)
	{
		while (set[j])
		{
			if (newstr[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		i--;
		j = 0;
	}
	return (&newstr[i + 1]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*newstr;
	char	*first;
	char	length;

	i = 0;
	length = sec_cut(s1, set) - first_cut(s1, set);
	first = first_cut(s1, set);
	if (length < 0)
	{
		newstr = malloc (1);
		newstr[0] = '\0';
		return (newstr);
	}
	newstr = malloc (length + 1);
	if (!newstr)
		return (NULL);
	while (first != sec_cut(s1, set))
	{
		newstr[i] = *first;
		i++;
		first++;
	}
	newstr[i] = '\0';
	return (newstr);
}