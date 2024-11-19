<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:42:36 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/14 15:42:36 by pboucher         ###   ########.fr       */
=======
<<<<<<<< HEAD:push_swap/src/ft_swap.c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:47:30 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/12 12:47:30 by pboucher         ###   ########.fr       */
>>>>>>> de39aed00c7688252fa8716c5f50d494b817f41d
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
void	ft_rrotate(t_stack *stacks, char c)
{
	t_list	*b;

	b = stacks->b;
	if (c == 'a')
	{
		ft_rr(stacks, stacks->a, 0);
	}
	else if (c == 'b')
		ft_rr(stacks, b, 1);
	else
	{
		ft_rr(stacks, stacks->a, 0);
		ft_rr(stacks, b, 1);
		ft_printf("rrr\n");
	}
}

void ft_rr(t_stack *stacks, t_list *list, int check)
{
	t_list	*temp;
	int		i;
	int		size;

	size = ft_lstsize(list);
	temp = list;
	while (temp->next)
		list = list->next;
	list->next = temp;
	if (check == 0)
	{
		stacks->a = list;
		temp = stacks->a;
	}
	else
	{
		stacks->b = list;
		temp = stacks->b;
	}
	while (i++ < size - 1)
		temp = temp->next;
	temp->next = NULL;
}
=======
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
========
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
>>>>>>>> de39aed00c7688252fa8716c5f50d494b817f41d:push_swap/src/ft_rrotate.c
>>>>>>> de39aed00c7688252fa8716c5f50d494b817f41d
