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

void	ft_sorting(t_list **a, t_list **b)
{
	int index;

	index = 0;
	if ()
}

int	main(int ac, char **av)
{
	t_stack	stacks;

	if (ac == 1)
		exit (0);
	stacks.a = NULL;
	stacks.b = NULL;
	av = ft_split_all(ac, av);
	if (!av || ft_double(ac, av) || ft_stack_check(ac, av, stacks.a) == 0)
	{
		ft_clean_all(stacks.a, NULL, av);
		ft_printf("Error\n");
		exit (0);
	}
	if (!ft_sorted(stacks.a))
		ft_sorting(&stacks.a, &stacks.b);
	ft_clean_all(stacks.a, stacks.b, av);
	exit (0);
}
