/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:35:25 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/03 10:38:23 by pboucher         ###   ########.fr       */
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
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (str);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c, int check)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (check == 1)
	{
		while (s[i] && s[i] != '\n')
			i++;
		if (s[i] == '\n')
			i++;
		return (i);
	}
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*tab;

	if (!s || ft_strlen(s) < start)
		return (NULL);
	j = ft_strlen(s) - start;
	if (j < len)
		len = j;
	tab = ft_calloc(len + 1, 1);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < len)
		tab[i] = s[start + i];
	return (tab);
}

void	*ft_calloc(int nmemb, int size)
{
	void	*alloc;
	int		i;

	if (size * nmemb <= 0)
		alloc = malloc(0);
	else
		alloc = malloc(size * nmemb);
	if (!alloc)
		return (NULL);
	i = -1;
	while (++i < size * nmemb)
		*(unsigned char *)(alloc + i) = 0;
	return (alloc);
}
