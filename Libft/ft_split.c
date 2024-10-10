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

int	count_words(const char *str, char c)
{
	int i;
	int j;
	char last;

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

char		**ft_split(char const *s, char c)
{
	int		i;
	size_t	j;
	size_t	k;
	size_t	temp;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (1)
	{
		while ( s[i] == c)
			i++;
		if (s[i] == 0)
			break;
		k = 0;
		while (s[i + k] != 0 && s[i + k] != c)
			k++;
		split[j] = (char *)malloc((k + 1) * sizeof(char));
		if (!split[j])
			return (NULL);
		temp = 0;
		while (temp < k)
		{
			split[j][temp] = s[i];
			temp++;
			i++;
		}
		split[j][temp] = 0;
		j++;
	}
	split[j] = NULL;
	return (split); 
}
