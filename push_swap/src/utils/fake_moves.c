/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:15:05 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/21 01:15:05 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	fake_rotate(t_list **list, int *place)
{
	t_list	*temp;

	if (list && *list && (*list)->next)
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = *list;
		*list = (*list)->next;
		temp->next->next = NULL;
		if (place && *place && *place != -1)
			*place = *place - 1;
		return (1);
	}
	return (0);
}

int	fake_rrotate(t_list **list, int *place)
{
	t_list	*temp;

	if (list && *list && (*list)->next)
	{
		temp = *list;
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = *list;
		*list = temp->next;
		temp->next = NULL;
		if (place && *place != -1)
			*place = *place + 1;
		return (1);
	}
	return (0);
}