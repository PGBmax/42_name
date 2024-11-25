/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:55:33 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/24 13:55:33 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		exit (0);
	a = NULL;
	b = NULL;
	av = ft_clean_args(&ac, av);
	if (!av || ft_has_double(ac, av)
		|| !ft_create_list(ac, av, &a))
	{
		ft_clean_all(a, NULL, av);
		write(2, "Error\n", 6);
		exit (0);
	}
	if (!ft_sorted(a))
		ft_sorting(&a, &b);
	ft_clean_all(a, b, av);
	exit (0);
}
