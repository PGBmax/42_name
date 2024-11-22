/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:30:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/22 16:48:58 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

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
	ft_lstclear(&b);
	ft_lstclear(&a);
	exit (0);
}