/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:13:58 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/20 23:13:58 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_replace_list(t_list **list, int index)
{
	int	temp;

	if (index > 0)
		while (index > 0)
			ft_rotate(list, &index, 'c', 0);
	else
	{
		index = index * -1;
		temp = 0;
		while (temp < index)
			ft_reverse_rotate(list, &temp, 'c', 0);
	}
}

int	ft_get_index_b(t_list **a, t_list **b)
{
	int	index;
	int	rr_bool;

	index = -1;
	rr_bool = -1;
	while (a && b && ++index < ft_lstsize(*b)
		&& !((*a)->content > ft_get_max(*b) && ft_find_index_max(*b) == 0)
		&& !((*a)->content < ft_get_min(*b) && ft_find_index_max(*b) == 0)
		&& ((*a)->content < (*b)->content
			|| (*a)->content > ft_lstlast(*b)->content))
	{
		if (rr_bool == 1 || ((*a)->content > (*b)->content
				&& ft_find_index_min(*b) > ft_lstsize(*b) / 2))
		{
			ft_reverse_rotate(b, NULL, 'b', 0);
			rr_bool = 1;
		}
		else
			ft_rotate(b, NULL, 'b', 0);
	}
	ft_replace_list(b, index * rr_bool);
	if (rr_bool == 1)
		index = ft_lstsize(*b) - index;
	return (index);
}

int	ft_move_list(t_list **a, t_list **b, int index, int *indexb_help)
{
	int	temp;

	if (a && index > 0)
	{
		temp = index;
		while (temp > 0)
			ft_rotate(a, &temp, 'a', 0);
	}
	else if (a)
	{
		index = index * -1;
		temp = 0;
		while (temp < index * 2)
			ft_reverse_rotate(a, &temp, 'a', 0);
	}
	temp = ft_get_index_b(a, b);
	*indexb_help = temp;
	if (temp > ft_lstsize(*b) / 2)
		temp = ft_lstsize(*b) - temp;
	return (temp);
}

void	ft_set_values(t_values *vals, int temp, int *indb, int bst_index)
{
	(*vals).min_move = (*vals).index + temp;
	(*vals).best_index = bst_index;
	*indb = (*vals).indexb_help;
}

int	ft_get_index_a(t_list **a, t_list **b, int *indexb)
{
	t_values	vals;
	int			temp;

	vals.index = -1;
	vals.min_move = -1;
	vals.indexb_help = 0;
	while (++vals.index < (ft_lstsize(*a) / 2) + 1
		&& vals.index < (ft_lstsize(*b) / 2) + 1)
	{
		temp = ft_move_list(a, b, vals.index, &vals.indexb_help);
		if (vals.min_move == -1 || vals.index + temp < vals.min_move)
			ft_set_values(&vals, temp, indexb, vals.index);
		temp = ft_move_list(a, b, (vals.index * -1), &vals.indexb_help);
		if (vals.index + temp < vals.min_move)
			ft_set_values(&vals, temp, indexb, ft_lstsize(*a) - vals.index);
		ft_replace_list(a, vals.index);
	}
	return (vals.best_index);
}
