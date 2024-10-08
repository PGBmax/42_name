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

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (*str)
	{
		if (*str == c)
			return ((unsigned char *)s);
		str++;
	}
	if (c == '\0')
		return ((unsigned char *)s);
	return (0);
}
