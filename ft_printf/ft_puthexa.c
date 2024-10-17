/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:38:05 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/16 22:38:05 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n)
{
	char	*numbers;
	int		len;

	len = 0;
	numbers = "0123456789abcdef";
	if (!n)
		return (ft_putstr("(nil)"));
	if (n >= 16)
		len = ft_puthexa(n / 16);
	if (len == 0)
		len += ft_putstr("0x");
	len++;
	write(1, &numbers[n % 16], 1);
	return (len);
}

int	ft_puthexa_uol(unsigned int n, int uporlow)
{
	char	*numbers;
	int		len;

	len = 0;
	if (uporlow == 0)
		numbers = "0123456789abcdef";
	else
		numbers = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	if (!n)
		return (ft_putstr("(nil)"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 16)
		len = ft_puthexa_uol(n / 16, uporlow);
	len++;
	write(1, &numbers[n % 16], 1);
	return (len);
}
