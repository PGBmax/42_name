/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:55:01 by pboucher          #+#    #+#             */
/*   Updated: 2024/08/20 16:55:31 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 1)
		return (ft_recursive_factorial(nb - 1) * nb);
	else if (nb == 1)
		return (nb);
	else if (nb < 0)
		return (0);
	return (1);
}
