/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:47:30 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/12 12:47:30 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack *stacks, char c)
{
	t_list	*a;
	t_list	*b;

	a = stacks->a;
	b = stacks->b;
	if (c == 'a')
		ft_s(a, c, 1);
	else if (c == 'b')
		ft_s(b, c, 1);
	else
	{
		ft_s(a, c, 0);
		ft_s(b, c, 0);
		ft_printf("ss\n");
	}
}

void	ft_s(t_list *list, char c, int check)
{
	void	*temp;

	temp = list->content;
	list->content = list->next->content;
	list->next->content = temp;
	if (check == 1)
		ft_printf("s%c\n", c);
}