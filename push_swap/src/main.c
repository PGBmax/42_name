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

int	main(int argc, char **argv)
{
	t_stack	stacks;

	ft_error(argc, argv);
	stacks.a = create_list_a(argc, argv);
	stacks.b = NULL;
	check_for_doubles(stacks.a);
	sorting(&stacks);
	ft_clearnodes(&stacks->a);
	ft_clearnodes(&stacks->b);
}
