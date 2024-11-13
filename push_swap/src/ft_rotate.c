/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:24:10 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/12 12:24:10 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate(t_stack *stacks, char c)
{
	t_list	*a;
	t_list	*b;

	a = stacks->a;
	b = stacks->b;
	if (c == 'a')
	{
		ft_r(stacks, stacks->a, c, 0);
		ft_printf("ra\n");
	}
	else if (c == 'b')
	{
		ft_r(stacks, stacks->b, c, 1);
		ft_printf("rb\n");
	}
	else
	{
		ft_r(stacks, stacks->a, c, 0);
		ft_r(stacks, b, c, 1);
		ft_printf("rr\n");
	}
}

void ft_r(t_stack *stacks, t_list *list, char c, int check)
{
	t_list	*tmp;

	tmp = list;
	if (check == 0)
	{
		stacks.a = a->next;
		while (a->next)
			list = a->next;
		a->next = tmp;
	}
	else
	{
		stacks.b = b->next;
		while (b->next)
			list = b->next;
		b->next = tmp;
	}
	tmp->next = NULL;
}
