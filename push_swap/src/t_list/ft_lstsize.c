/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:32:38 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/20 15:32:38 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *list)
{
	int		i;
	t_list	*temp;

	if (!list)
		return (0);
	i = 0;
	temp = list;
	while (temp && temp->next)
	{
		// ft_printf("%p, %d\n", &temp, temp->content);
		// ft_printf("%p, %d\n", &temp->next, temp->next->content);
		temp = temp->next;
		i++;
	}
	return (i);
}
