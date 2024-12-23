/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:37:49 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/23 01:37:49 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_malloc_size(size_t max_sub, size_t len)
{
	if (max_sub > len)
		return (len);
	else
		return (max_sub);
}

static int	ft_check_start(char const *s, unsigned int start)
{
	if ((int)start > ft_strlen(s))
		return (0);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			max_sub;
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s || ft_check_start(s, start) == 0)
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	max_sub = ft_strlen(&s[start]);
	max_sub = ft_malloc_size(max_sub, len);
	sub = malloc((max_sub + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < max_sub)
	{
		sub[i] = s[start + i];
		i ++;
	}
	sub[i] = 0;
	return (sub);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		temp = ft_calloc(1, 1);
		if (!temp)
			return (NULL);
		return (temp);
	}
	if (nmemb * size > 2147483647)
		return (0);
	temp = malloc((size * nmemb) + 1);
	if (!temp)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)temp)[i] = 0;
		i ++;
	}
	((char *)temp)[size * nmemb] = 0;
	return (temp);
}
