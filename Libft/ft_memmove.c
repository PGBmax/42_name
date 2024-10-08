/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:21:54 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/08 12:43:04 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*strdest;
	unsigned char	*strsrc;

	if (!dest || !src || n == 0)
		return (NULL);
	strdest = (unsigned char *) dest;
	strsrc = (unsigned char *) src;
	while (0 <= n)
	{
		strdest[n] = strsrc[n];
		n--;
	}
	return (dest);
}
