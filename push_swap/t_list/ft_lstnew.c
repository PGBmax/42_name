/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:13:29 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/09 23:32:34 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)ft_calloc(sizeof(*list), 1);
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}