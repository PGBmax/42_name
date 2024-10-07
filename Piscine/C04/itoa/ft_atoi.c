/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:13:50 by pboucher          #+#    #+#             */
/*   Updated: 2024/08/28 11:10:42 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_itoa(int value, char *str)
{
	int i;

	i = 0;
	if (value < 0)
	{
		str[0] = '-';
		i++;
		value = -value;
	}
	while (value >= 10)
	{
		str[i] = value % 10 + '0';
		value /= 10;
		i++;
	}
	return (str);
}

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char str[1024];
	printf("Ma fonction %s\n", ft_itoa(-1234, str));
}
