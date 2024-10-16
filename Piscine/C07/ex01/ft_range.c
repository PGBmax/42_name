/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:00:26 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/16 18:43:01 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void ft_range(int min, int max)
{
	int	i;
	int	*list;

	i = 0;
	if (min >= max)
	{
		list = NULL;
	}
	list = malloc((max - min) * sizeof(int));
	while (min < max)
	{
		list[i] = min;
		printf("%d  ",min);
		i++;
		min++;
	}
}

int main(void)
{
	ft_range(0, 2147483647);
}
