/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:43:54 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/20 15:43:54 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_lstclear(t_list **list)
{
	t_list	*temp;
	t_list	*lst;

	if (!(*list))
		return ;
	temp = *list;
	while (temp->next)
	{
		lst = temp->next;
		if (temp)
			free (temp);
		temp = lst;
	}
	if (temp)
		free (temp);
	*list = NULL;
}