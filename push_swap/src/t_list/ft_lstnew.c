/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:30:16 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/20 15:30:16 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*temp;

	temp = malloc(sizeof(*temp));
	if (!temp)
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}