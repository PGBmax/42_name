/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:50:04 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/23 01:31:35 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sorted(t_list *list)
{
	int	temp;

	if (!list)
		return (0);
	temp = list->content;
	if (list->next)
		list = list->next;
	while (list && list->next)
	{
		if (list->content < temp)
			return (0);
		temp = list->content;
		list = list->next;
	}
	if (list && list->content < temp)
		return (0);
	return (1);
}

void	ft_sorting(t_list **a, t_list **b)
{
	int	indexa;
	int	indexb;

	indexb = 0;
	if (ft_lstsize(*a) > 3)
	{
		ft_push(b, a, 'b', 1);
		if (ft_lstsize(*a) > 3)
			ft_push(b, a, 'b', 1);
	}
	while (ft_lstsize(*a) > 3 && !ft_sorted(*a))
	{
		indexa = ft_get_index_a(a, b, &indexb);
		ft_do_move(a, b, indexa, indexb);
	}
	ft_sort_three(a);
	ft_empty_b(a, b);
	while (ft_find_index_min(*a) != 0
		&& ft_find_index_min(*a) != ft_lstsize(*a))
	{
		if (ft_lstsize(*a) - ft_find_index_min(*a) < (ft_lstsize(*a)) / 2)
			ft_reverse_rotate(a, NULL, 'a', 1);
		else
			ft_rotate(a, NULL, 'a', 1);
	}
}

void	ft_do_rrr(t_list **a, t_list **b, int *indexa, int *indexb)
{
	while (a && b && *indexa > 0
		&& *indexa < ft_lstsize(*a)
		&& *indexb > 0 && *indexb < ft_lstsize(*b)
		&& ((ft_lstsize(*a) - *indexa < ((ft_lstsize(*a)) / 2) + 1
				&& ft_lstsize(*b) - *indexb < ((ft_lstsize(*b)) / 2) + 1)
			|| (ft_lstsize(*a) - *indexa > ((ft_lstsize(*a)) / 2)
				&& ft_lstsize(*b) - *indexb > ((ft_lstsize(*b)) / 2))))
	{
		if (ft_lstsize(*a) - *indexa < ((ft_lstsize(*a)) / 2) + 1
			&& ft_lstsize(*b) - *indexb < ((ft_lstsize(*b)) / 2) + 1)
		{
			ft_reverse_rotate(a, indexa, 'a', 0);
			ft_reverse_rotate(b, indexb, 'b', 0);
			ft_printf("rrr\n");
		}
		else if (ft_lstsize(*a) - *indexa > ((ft_lstsize(*a)) / 2)
			&& ft_lstsize(*b) - *indexb > ((ft_lstsize(*b)) / 2))
		{
			ft_rotate(a, indexa, 'a', 0);
			ft_rotate(b, indexb, 'b', 0);
			ft_printf("rr\n");
		}
	}
}

char	*ft_strlcat(char *dest, char *src, int check)
{
	int		i;
	int		j;
	char	*temp;

	temp = (char *)ft_calloc(ft_strlen(dest) + ft_strlen(src) + 1, 1);
	if (!temp)
		return (NULL);
	i = -1;
	j = -1;
	while (dest && dest[++i] != 0)
		temp[i] = dest[i];
	temp[i] = ' ';
	while (src && src[j] != 0)
		temp[++i] = src[j];
	if (dest && check == 1)
		free(dest);
	return (temp);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		temp = ft_calloc(1, 1);
		if (!temp)
			return (NULL);
		return (temp);
	}
	if (nmemb * size > 2147483647)
		return (0);
	temp = malloc((size * nmemb) + 1);
	if (!temp)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)temp)[i] = 0;
		i ++;
	}
	((char *)temp)[size * nmemb] = 0;
	return (temp);
}