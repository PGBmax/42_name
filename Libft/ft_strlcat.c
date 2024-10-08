/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:55:51 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/08 16:51:18 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size2;

	size2 = size;
	while (size > 0 && *dst)
	{
		dst++;
		size--;
	}
	if (size == 0)
		return (size2);
	while (size > 0 && *src)
	{
		*dst++ = *src++;
		size--;
	}
	if (size == 0)
		return (size2);
	*dst = 0;
	return (size2);
}
