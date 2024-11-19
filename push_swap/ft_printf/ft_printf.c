/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:07:24 by pboucher          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/19 00:41:54 by pboucher         ###   ########.fr       */
=======
/*   Updated: 2024/11/08 14:38:34 by pboucher         ###   ########.fr       */
>>>>>>> de39aed00c7688252fa8716c5f50d494b817f41d
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

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

<<<<<<< HEAD
long	ft_atoi(char *nptr)
{
	int		i;
	long	temp;
	int		negatif;
=======
int	ft_atoi(char *nptr)
{
	int	i;
	int	temp;
	int	negatif;
>>>>>>> de39aed00c7688252fa8716c5f50d494b817f41d

	i = 0;
	temp = 0;
	negatif = 1;
	while (((nptr[i] >= 9 && nptr[i] <= 13)
			|| nptr[i] == 32) && nptr[i] != '\0')
		i++;
	if ((nptr[i] == 43 || nptr[i] == 45) && nptr[i] != '\0')
	{
		if (nptr[i] == 45)
			negatif = -1;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		temp = 10 * temp + (nptr[i] - '0');
		i++;
	}
	return (temp * negatif);
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
