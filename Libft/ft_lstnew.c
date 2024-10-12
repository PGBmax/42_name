/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:13:29 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/12 18:18:04 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *test;
	
	test = (t_list *)malloc(sizeof(*test));
	if (!test)
		return (NULL);
	test->content = (t_list *)content;
	test->next = NULL;
	return (test);
}