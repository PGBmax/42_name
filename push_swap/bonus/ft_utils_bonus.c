/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 00:40:39 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/23 00:40:39 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	pos;

	pos = -1;
	if (n < 1)
		return (0);
	while (++pos < n && (unsigned char)s1[pos] != 0
		&& (unsigned char)s2[pos] != 0)
		if ((unsigned char)s1[pos] != (unsigned char)s2[pos])
			return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}

int	ft_rr(t_list **a, t_list **b)
{
	int	tp;

	tp = ft_rotate(a, NULL, 'a', 0);
	tp += ft_rotate(b, NULL, 'b', 0);
	if (tp == 2)
		return (1);
	return (0);
}

int	ft_rrr(t_list **a, t_list **b)
{
	int	tp;

	tp = ft_reverse_rotate(a, NULL, 'a', 0);
	tp += ft_reverse_rotate(b, NULL, 'b', 0);
	if (tp == 2)
		return (1);
	return (0);
}

int	ft_ss(t_list **a, t_list **b)
{
	int	tp;

	tp = ft_swap(a, 'a', 0);
	tp += ft_swap(b, 'b', 0);
	if (tp == 2)
		return (1);
	return (0);
}
