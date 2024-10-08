/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:36:45 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/08 14:46:41 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	number;
	int	i;
	int	negate;

	number = 0;
	negate = 1;
	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negate = -1;
		i++;
	}
	while (nptr[i] != 0)
	{
		if (nptr[i] >= 48 && nptr[i] <= 57)
			number = 10 * number + (nptr[i] - 48);
		else
			return (number * negate);
		i++;
	}
	return (number * negate);
}
