/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:08:31 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/12 23:08:31 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst && !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
