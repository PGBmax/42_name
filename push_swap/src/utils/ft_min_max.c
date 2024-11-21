/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:22:36 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/21 01:22:36 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index_min(t_list *list)
{
	int	index;
	int	min;
	int	i;

	if (list)
	{
		min = list->content;
		index = 0;
		i = 0;
		while (list && list->next != NULL)
		{
			if (list->content < min)
			{
				index = i;
				min = list->content;
			}
			i ++;
			list = list->next;
		}
		if (list->content < min)
			index = i;
		return (index);
	}
	return (-1);
}

int	ft_find_index_max(t_list *list)
{
	int	index;
	int	max;
	int	i;

	if (list)
	{
		max = list->content;
		index = 0;
		i = 0;
		while (list && list->next != NULL)
		{
			if (list->content > max)
			{
				index = i;
				max = list->content;
			}
			i ++;
			list = list->next;
		}
		if (list->content > max)
			index = i;
		return (index);
	}
	return (-1);
}

int	ft_get_min(t_list *list)
{
	int	min;

	min = 0;
	if (list)
		min = list->content;
	while (list && list->next)
	{
		if (list->content < min)
			min = list->content;
		list = list->next;
	}
	if (list && list->content < min)
		min = list->content;
	return (min);
}

int	ft_get_max(t_list *list)
{
	int	max;

	max = 0;
	if (list)
		max = list->content;
	while (list && list->next)
	{
		if (list->content > max)
			max = list->content;
		list = list->next;
	}
	if (list && list->content > max)
		max = list->content;
	return (max);
}