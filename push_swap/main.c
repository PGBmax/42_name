/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:05:32 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/09 23:05:32 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
}

t_list	*swap(t_list *a, t_list *b, char c)
{
	t_list	*temp;

	if ((c == 'a' || c == 's') && a && a->next)
	{
		temp = a;
		a = a->next;
		a->next = temp;
	}
	if ((c == 'b' || c == 's') && b && b->next)
	{
		temp = b;
		b = b->next;
		b->next = temp;
	}
	printf("s%s\n", c);
}

t_list	*push(t_list *a, t_list *b, char c)
{
	t_list	*temp;
	if (c == 'a' && b)
	{
		temp = b;
		temp->next = a;
		b = b->next;
	}
	if (c == 'b' && a)
	{
		temp = a;
		temp->next = b;
		a = a->next;
	}
	printf("p%s\n", c);
}

t_list	*rotate(t_list *a, t_list *b, char c)
{
	t_list *temp;

	if ((c == 'a' || c == 'r') && a)
	{
		temp = ft_lstlast(a);
		temp->next = a;
		a = a->next;
	}
	if ((c == 'b' || c == 'r') && b)
	{
		temp = ft_lstlast(b);
		temp->next = b;
		b = b->next;
	}
	printf("r%s\n", c);
}

t_list	*reverse_rotate(t_list *a, t_list *b, char c)
{
	t_list	**temp;
	t_list	*real_temp;
	if ((c == 'a' || c == 'r') && a)
	{
		temp = ft_lstlast(&a);
		real_temp = temp;
		real_temp->next = a;
		temp = NULL;
	}
	if ((c == 'b' || c == 'r') && b)
	{
		temp = ft_lstlast(&b);
		real_temp = temp;
		real_temp->next = b;
		temp = NULL;
	}
	printf("rr%s\n", c);
}