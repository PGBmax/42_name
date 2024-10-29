/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:35:25 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/28 16:23:55 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	free(s1);
	s1 = NULL;
	return (str);
}

int ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return(i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	return (NULL);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	int		j;
	char	*tab;

	if (!s || ft_strlen(s) < start)
		return (NULL);
	j = ft_strlen(s + start);
	if (j < len)
		len = j;
	tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < len)
		tab[i] = s[start + i];
	tab[i] = '\0';
	return (tab);
}