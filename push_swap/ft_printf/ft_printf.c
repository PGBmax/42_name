/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:35:17 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/23 18:34:56 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

long	ft_atoi(char *nptr)
{
	int				i;
	int				sign;
	unsigned int	num;

	i = 0;
	sign = 1;
	num = 0;
	if (!nptr || !*nptr)
		return (0);
	if ((nptr[0] == '-' || nptr[0] == '+') && ++i != -1)
		if (nptr[0] == '-')
			sign = -1;
	if (i > 0 && (nptr[0] != '-' && nptr[0] != '+'))
		i = 0;
	while (nptr[i] != 0 && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (num >= 2147483647)
			return (0);
		num = num * 10 + (nptr[i] - '0');
		i ++;
	}
	if (((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
		|| (nptr[i] != 0 && !(nptr[i] >= '0' && nptr[i] <= '9')))
		return (0);
	return ((int)num * sign);
}

int	ft_format(va_list list, char str)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (str == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (str == 'p')
		count += ft_puthexa(va_arg(list, unsigned long));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(list, int), 0);
	else if (str == 'u')
		count += ft_putnbr(va_arg(list, unsigned int), 1);
	else if (str == 'x')
		count += ft_puthexa_uol(va_arg(list, unsigned int), 0);
	else if (str == 'X')
		count += ft_puthexa_uol(va_arg(list, unsigned int), 1);
	else if (str == '%')
		count += ft_putchar('%');
	else
	{
		count += ft_putchar('%');
		count += ft_putchar(str);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	if (!str)
		return (-1);
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
