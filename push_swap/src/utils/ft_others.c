/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:26:08 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/21 01:26:08 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_do_move(t_list **a, t_list **b, int indexa, int indexb)
{
	ft_do_rrr(a, b, &indexa, &indexb);
	while (indexa > 0 && indexa < ft_lstsize(*a))
	{
		if (ft_lstsize(*a) - indexa < ((ft_lstsize(*a)) / 2) + 1)
			ft_reverse_rotate(a, &indexa, 'a', 1);
		else
			ft_rotate(a, &indexa, 'a', 1);
	}
	while (indexb > 0 && indexb < ft_lstsize(*b))
	{
		if (ft_lstsize(*b) - indexb < ((ft_lstsize(*b)) / 2) + 1)
			ft_reverse_rotate(b, &indexb, 'b', 1);
		else
			ft_rotate(b, &indexb, 'b', 1);
	}
	ft_push(b, a, 'b', 1);
}

int	ft_find_num(t_list *list, int num)
{
	int	index;

	index = 0;
	while (list && list->content != num && index < ft_lstsize(list))
	{
		list = list->next;
		index ++;
	}
	return (index);
}

void	ft_sort_three(t_list **a)
{
	int	min;
	int	max;

	min = ft_find_index_min(*a);
	max = ft_find_index_max(*a);
	if ((min == 0 && max == 1) || (min == 2 && max == 0))
		ft_swap(a, 'a', 1);
	else if ((min == 1 && max == 2) || (min == 1 && max == 2))
		ft_swap(a, 'a', 1);
}

int	ft_get_place(t_list *list, int num)
{
	int		i;

	i = 0;
	while (list && !(list->content > num
			&& ft_lstlast(list)->content < num) && i < ft_lstsize(list))
	{
		ft_rotate(&list, NULL, 'c', 0);
		i ++;
	}
	ft_replace_list(&list, -1 * i);
	return (i);
}

void	ft_empty_b(t_list **a, t_list **b)
{
	int	move_count;
	// t_list	*temp = *b;
	// while (temp)
	// {
	// 	ft_printf("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// ft_printf("\n");
	// ft_printf("1: %p, 2: %p, 3: %p, 4: %p\n", &(*b), &((*b)->next), &((*b)->next->next), &((*b)->next->next->next));
	while (ft_lstsize(*b))
	{
		if ((*b)->content > ft_get_max(*a))
			move_count = ft_find_index_max(*a) + 1;
		else if ((*b)->content < ft_get_min(*a))
			move_count = ft_find_index_min(*a);
		else
			move_count = ft_get_place(*a, (*b)->content);
		while (a && *a && (move_count > 0 && move_count < ft_lstsize(*a)))
		{
			if (ft_lstsize(*a) - move_count < (ft_lstsize(*a) + 1) / 2)
				ft_reverse_rotate(a, &move_count, 'a', 1);
			else
				ft_rotate(a, &move_count, 'a', 1);
		}
		ft_push(a, b, 'a', 1);
	}
	ft_push(a, b, 'a', 1);
	// ft_printf("lstsize(b): %d\n", ft_lstsize(*b));
}
