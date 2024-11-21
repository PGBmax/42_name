/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:23:22 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/18 14:23:22 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		exit (0);
	if (ft_double(ac, av))
	{
		ft_printf("Error\n");
		exit (0);
	}
	a = create_list(ac, av);
	b = NULL;
	if (!ft_sorted(a))
		ft_sorting(&a, &b);
	ft_printf("is sorted : %d\n", ft_sorted(a));
	// t_list	*temp = b;
	// while (temp)
	// {
	// 	ft_printf("%d ", temp->content);
	// 	temp = temp->next;
	// }
	// ft_printf("\n");
	ft_lstclear(&b);
	b = a;
	while (b)
	{
		ft_printf("%d ", b->content);
		b = b->next;
	}
	ft_lstclear(&a);
	exit (0);
}
