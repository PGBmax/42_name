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

void	ft_clean_all(t_list *a, t_list *b, char **argv)
{
	int	i;

	if (a)
		ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i ++;
		}
		free(argv);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		exit (0);
	a = NULL;
	b = NULL;
	av = ft_clean_args(&ac, av);
	if (!av || ft_has_double(av, ac)
		|| ft_create_list(ac, av, &a) == 0)
	{
		ft_clean_all(a, NULL, av);
		ft_printf("Error\n");
		exit (0);
	}
	if (!ft_is_sorted(a))
		ft_algo(&a, &b);
	ft_clean_all(a, b, av);
	exit (0);
}