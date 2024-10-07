/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:00:26 by pboucher          #+#    #+#             */
/*   Updated: 2024/08/26 12:24:46 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*list;

	i = 0;
	if (min >= max)
	{
		list = NULL;
		return (list);
	}
	list = malloc((max - min) * sizeof(int));
	while (min < max)
	{
		list[i] = min;
		i++;
		min++;
	}
	return (list);
}
