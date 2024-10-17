/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:44:55 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/16 22:15:20 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int int_len(int n)
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

int	ft_putnbr(int n, int check)
{
	int	a;
	int len;

	len = int_len(n);
	if (n == -2147483648 && check == 0)
		return (ft_putstr("-2147483648"));
	else if (n == -2147483648 && check == 1)
		return (ft_putstr("2147483648"));
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
		ft_putnbr(n / 10, 0);
		ft_putnbr(n % 10, 0);
	}
	return (len);
}
