/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:34:10 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/16 18:26:56 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int ft_format(va_list list, char str)
{
	int count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(list, int));
	if (str == 's')
		count += ft_putstr(va_arg(list, char *));
	if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(list, int));
	if (str == 'u')
		count += ft_putnbr(va_arg(list, unsigned long));
	if (str)
	if (str == '%')
		count += ft_putchar(37);
	return (count);
}
int ft_printf(const char *str, ...)
{
	va_list list;
	int i;
	int count;

	i = 0;
	count = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_format(list, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (count);
}


int main(void)
{
	printf("   %d\n", ft_printf("%s %u %u", "bonsoir les gens", 2147483648, LONG_MIN));
}