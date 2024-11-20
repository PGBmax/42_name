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

int	ft_sorted(t_list	*list)
{
	int		stocked;
	t_list	*temp;

	temp = list;
	stocked = temp->content;
	while (temp)
	{
		if (stocked > temp->content)
			return (0);
		stocked = temp->content;
		temp = temp->next;
	}
	ft_lstclear(&temp);
	return (1);
}

t_list	*create_list(int ac, char **av)
{
	int		i;
	t_list	*list;

	i = 1;
	list = ft_lstnew(ft_atoi(av[i]));
	while (++i < ac)
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(av[i])));
	return (list);
}

int	main(int ac, char **av)
{
	t_stack	stacks;
	// t_list	*temp;

	if (ac == 1)
		exit (0);
	stacks.a = create_list(ac, av);
	ft_printf("\nIs sorted : %d\n", ft_sorted(stacks.a));
	// stacks.b = NULL;
	// if (!av || ft_double(stacks->a))
	// {
	// 	ft_clean_all(stacks.a, NULL, av);
	// 	ft_printf("Error\n");
	// 	exit (0);
	// }
	// if (!ft_sorted(stacks.a))
	// 	ft_sorting(&stacks.a, &stacks.b);
	// ft_clean_all(stacks.a, stacks.b, av);
	// exit (0);
}