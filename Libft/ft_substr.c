/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:30:17 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/11 17:30:54 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sigma(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (i == start)
		{
			while (j < len && s[i] != 0)
			{
				i++;
				j++;
			}
		}
		i++;
	}
	j++;
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	int				count;
	unsigned int	i;
	size_t			j;

	count = ft_sigma(s, start, len);
	str = malloc(count * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (i == start)
		{
			while (j < len && s[i] != 0)
				str[j++] = s[i++];
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
