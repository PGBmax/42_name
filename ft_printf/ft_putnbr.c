/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:44:55 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/16 18:32:34 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int int_len(long long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

int	ft_putnbr(long long n)
{
	int	a;
	int len;

	if (n == 0 || n == -0 || n == 0)
		return (ft_putchar('0'));
	len = int_len(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	a = n;
	if (n >= 0 && n <= 9)
	{
		a = a + '0';
		write(1, &a, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (len);
}
