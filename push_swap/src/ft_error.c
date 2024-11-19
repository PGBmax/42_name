/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:33:53 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/19 00:33:53 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	check_integers(argc, argv);
	check_int_size(argc, argv);
}

void	check_integers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
		{
			ft_printf("Error\n");
			exit(0);
		}
		while (j < (int)ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (j == 0 && ft_strlen(argv[i]) != 1 && \
					(argv[i][j] == '-' || argv[i][j] == '+'))
					j++;
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
	}
}

void	check_int_size(int argc, char **argv)
{
	long	num;
	int		i;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			ft_printf("Error\n");
			exit(0);
		}
		i++;
	}
}

void	check_for_doubles(t_list *a)
{
	t_list	*tmp;
	t_list	*ptr;
	int			num;

	ptr = a;
	while (ptr != NULL)
	{
		tmp = ptr;
		num = tmp->content;
		tmp = tmp->next;
		while (tmp != NULL)
		{
			if (num == tmp->content)
			{
				ft_clearnodes(&a);
				ft_printf("Error\n");
				exit(0);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}