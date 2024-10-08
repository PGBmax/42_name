/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:21:54 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/08 17:39:55 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*strdest;
	unsigned char	*strsrc;

	strdest = (unsigned char *) dest;
	strsrc = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		if (strdest[i] == 0)
			strdest[i] = strsrc[i];
		i++;
	}
	return (dest);
}
