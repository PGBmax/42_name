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

void	swap(t_list *a, t_list *b, char c)
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

void	push(t_list *a, t_list *b, char c)
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

void	rotate(t_list *a, t_list *b, char c)
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

void	reverse_rotate(t_list *a, t_list *b, char c)
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

int main(void)
{
	t_list	*a0;
	t_list	*a1;
	t_list	*a2;
	t_list	*a3;
	t_list	*a4;
	t_list	*a5;
	t_list	**b;
	
	a0->content = 1;
	a1->content = 2;
	a2->content = 3;
	a3->content = 4;
	a4->content = 5;
	a5->content = 6;
	a0->next = a1;
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = NULL;

	b = &a0;
	while ((*b))
	{
		printf("%s", (*b)->content);
		(*b)++;
	}
	swap(a0, b, 'a');
	b = &a0;
	while ((*b))
	{
		printf("%s", (*b)->content);
		(*b)++;
	}
}
