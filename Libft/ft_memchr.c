/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:10:24 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/09 19:31:28 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (!(c <= 127 && c >= 0))
		return ((char *)s);
	i = 0;
	str = (unsigned char *)s;
	while (str && i < n)
	{
		if (*str == c)
			return (str);
		i++;
		str++;
	}
	if (c == '\0' || i > n)
		return (str);
	return (0);
}
