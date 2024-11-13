/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:16:13 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/13 12:16:13 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_error(int error)
{
	ft_printf("\e[91mError!\n");
	if (error == 1)
		ft_printf("\e[92mCorrect usage: ./push_swap <list of int>\n");
		ft_printf("\e[96mFor example: ./push_swap %c1 2 3 4 5 6 7%c\n", 34, 34);
	if (error == 2)
		ft_printf("\e")
	return (0);
}

int check_digits(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && ())
		{
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
		return (ft_error(1));
	if (!check_digits(av[1]))
		return (ft_error(2));
	ft_printf("Hello World!");
}