/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:29:16 by pboucher          #+#    #+#             */
/*   Updated: 2024/08/20 16:56:12 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	power--;
	if (power == -1)
		return (1);
	else if (power < -1)
		return (0);
	while (power > 0)
	{
		nb = nb * i;
		power--;
	}
	return (nb);
}
