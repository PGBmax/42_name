/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:11:09 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/13 12:15:38 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rrotate(t_stack *stacks, char c)
{
	t_list	*a;
	t_list	*b;
	
	a = stacks.a;
	b = stacks.b;
	if (c == 'a')
		ft_rr(a, c);
	else if (c == 'b')
		ft_rr(b, c);
	else
	{
		ft_rr(a, c);
		ft_rr(b, c);
	}
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
	else
		ft_printf("rrr\n")
}
