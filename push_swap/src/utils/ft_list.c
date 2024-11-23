/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:16:12 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/23 01:16:12 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_has_double(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
	}
	return (0);
}

int	ft_has_letter(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= '0' && str[i] <= '9')
			&& !((str[i] == '+' || str[i] == '-') && (str[i + 1]
					&& str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (1);
		i ++;
	}
	len = 0;
	while (str[len] != 0)
	{
		len ++;
	}
	if (len != i || len + i == 0)
		return (1);
	return (0);
}

int	ft_create_list(int ac, char **av, t_list **a)
{
	int	i;

	i = 1;
	if (!av || !*av)
		return (0);
	*a = ft_lstnew(ft_atoi(av[i - 1]));
	if (*a == NULL || (av[i - 1] && ft_atoi(av[i - 1]) == 0
			&& (av[i - 1][0] != '0' || av[i - 1][1] != 0)))
	{
		ft_lstclear(a);
		return (0);
	}
	while (i < ac)
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(av[i])));
		if (*a == NULL || (ft_atoi(av[i]) == 0 && (av[i][0] != '0'
				|| av[i][1] != 0)))
		{
			ft_lstclear(a);
			return (0);
		}
		i ++;
	}
	return (1);
}

char	**ft_clean_args2(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_has_letter(av[i]))
		{
			i = 0;
			while (av[i])
			{
				free(av[i]);
				i ++;
			}
			free(av[i]);
			free(av);
			return (NULL);
		}
		i ++;
	}
	if (i == 0)
	{
		free(av);
		return (NULL);
	}
	return (av);
}

char	**ft_clean_args(int *ac, char **av)
{
	char	**new_args;
	char	*tp_args;
	int		i;

	i = 2;
	tp_args = ft_strlcat(NULL, av[1], 0);
	while (i < *ac)
	{
		if (ft_has_letter(av[i]))
		{
			free(tp_args);
			return (NULL);
		}
		tp_args = ft_strlcat(tp_args, av[i], 1);
		i ++;
	}
	if (av[0] != 0)
	{
		new_args = ft_split(tp_args, " "[0], ac);
		free (tp_args);
		if (new_args == NULL)
			return (NULL);
		return (ft_clean_args2(new_args));
	}
	return (NULL);
}