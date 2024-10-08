/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:10:24 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/08 14:16:28 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t i;

	i = 0;
	str = (unsigned char *) s;
	while (*str && i < n)
	{
		if (*str == c)
			return ((unsigned char *)s);
		str++;
		i++;
	}
	if (c == '\0')
		return ((unsigned char *)s);
	return (0);
}
