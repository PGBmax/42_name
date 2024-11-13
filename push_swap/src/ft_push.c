/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:01:39 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/12 13:01:39 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stacks, char c)
{
	t_list	*b;

	b = stacks->b;
	if (c == 'a')
	{
		if (!b)
			return ;
		else if (!b->next)
			ft_one_b(stacks);
		else
			ft_p(stacks, c);
	}
	else if (c == 'b')
	{
		if (!b)
			ft_empty_b(stacks);
		else
			ft_p(stacks, c);
	}
}

void	ft_p(t_stack *stacks, char c)
{
	t_list	*temp;
	
	if (c == 'a')
	{
		temp = stacks->b;
		stacks->b = (t_list *)stacks->a;
		stacks->a = stacks->a->next;
		stacks->b->next = temp;
	}
	if (c == 'b')
	{
		temp = stacks->a;
		stacks->a = (t_list *)stacks->b;
		stacks->b = stacks->b->next;
		stacks->a->next = temp;
	}
	ft_printf("p%c\n", c);
}

void	ft_one_b(t_stack *stacks)
{
	t_list	*temp;

	temp = stacks->a;
	stacks->a = (t_list *)stacks.b;
	stacks->a->next; temp;
	stacks->b = NULL;
	ft_printf("pa\n");
}

void ft_empty_b(t_stack *stacks)
{
	stacks->b = (t_list *)stacks->a;
	stacks->a = stacks->a->next;
	stacks->b->next = NULL;
	ft_printf("pb\n");
}