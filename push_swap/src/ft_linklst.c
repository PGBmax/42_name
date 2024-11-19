/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linklst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:35:43 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/19 00:35:43 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(int argc, char **argv)
{
	int			i;
	t_list	*list;
	t_list	*tmp;

	i = 1;
	list = ft_newnode(ft_atoi(argv[i]));
	tmp = list;
	while (++i < argc)
	{
		tmp->next = ft_newnode(ft_atoi(argv[i]));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (list);
}

t_list	*ft_newnode(int content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

void	ft_clearnodes(t_list **lst)
{
	t_list	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
}

int	ft_listsize(t_list *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

t_list	*ft_lstlast(t_list *head)
{	
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}