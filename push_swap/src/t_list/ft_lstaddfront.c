/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:39:06 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/20 15:39:06 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_lstadd_front(t_list **list, t_list *new)
{
	if (!*list)
	{
		*list = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		new->next = *list;
	}
}