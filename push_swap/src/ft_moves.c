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

int	ft_swap(t_list	**list, char c, int check)
{
	t_list	*temp;

	if (*list && (*list)->next != NULL)
	{
		temp = *list;
		*list = (*list)->next;
		temp->next = (*list)->next;
		(*list)->next = temp;
		if (check == 1)
			ft_printf("s%c\n", c);
		return (1);
	}
	return (0);
}

int	ft_push(t_list **a, t_list **b, char c, int check)
{
	t_list	*temp;

	if (!b || !*b)
		return (0);
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		temp = (*b)->next;
		ft_lstadd_front(a, *b);
		*b = temp;
	}
	if (!*a)
	{
		free(a);
		return (0);
	}
	if (check == 1)
		ft_printf("p%c\n", c);
	return (1);
}

int	ft_rotate(t_list **list, int index, char c, int check)
{
	t_list	*temp;

	if (*list && (*list)->next)
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = *list;
		*list = (*list)->next;
		temp->next->next = NULL;
		if (check == 1)
			ft_printf("r%c\n", c);
		if (index)
			index--;
		return (1);
	}
	return (0);
}

int	ft_reverse_rotate(t_list **list, int index, char c, int check)
{
	t_list	*temp;

	if (*list && (*list)->next)
	{
		temp = *list;
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = *list;
		*list = temp->next;
		temp->next = NULL;
		if (check == 1)
			ft_printf("rr%c\n", c);
		if (index)
			index++;
		return (1);
	}
	return (0);
}
