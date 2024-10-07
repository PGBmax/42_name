/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:33:39 by pboucher          #+#    #+#             */
/*   Updated: 2024/08/20 17:02:33 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (2);
	else if (nb == 2147483647)
		return (2147483647);
	while (nb % i != 0)
		i++;
	if (nb == i)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
	return (nb);
}
