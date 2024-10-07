/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:55:28 by pboucher          #+#    #+#             */
/*   Updated: 2024/08/28 20:10:14 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	good_position(char *q, int i, int x)
{
	while (++x < i)
	{
		if (q[x] == q[i] || x - i + q[i] == q[x] || - x + i + q[i] == q[x])
			return (0);
	}
	return (1);
}

int	ft_rec_puzzle(char *q, int i, int count, int j)
{
	while (++j < 10)
	{
		q[i] = j + '0';
		if (good_position(q, i, -1))
		{
			if (i == 9)
			{
				write(1, q, 10);
				write(1, "\n", 1);
				count++;
			}
			else
				count += ft_rec_puzzle(q, i + 1, 0, -1);
		}
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	q[10];

	return (ft_rec_puzzle(q, 0, 0, -1));
}
