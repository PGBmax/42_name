/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:06:09 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/21 18:15:40 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapper.h"

int	ft_print_plate(int *base, int *tvar, char *line, char *view)
{
	int	i;

	i = 0;
	line = create_line(base[tvar[0]], base[tvar[1]],
			base[tvar[2]], base[tvar[3]]);
	if (verif(line, view))
	{
		while (i <= 15)
		{
			ft_printf("\e[96m%c\e[97m", line[i]);
			if (i == 3 || i == 7 || i == 11 || i == 15)
			{
				ft_printf("\n");
			}
			else
				ft_printf(" ");
			i++;
		}
		free(line);
		ft_printf("\n\e[92mSuccess !\n\n\e[97m");
		return (1);
	}
	free(line);
	return (0);
}

int	ft_loop(int *base, int *tvar, char *line, char *view)
{
	tvar[0] = 0;
	while (tvar[0] <= 23)
	{
		tvar[1] = 0;
		while (tvar[1] <= 23)
		{
			tvar[2] = 0;
			while (tvar[2] <= 23)
			{
				tvar[3] = 0;
				while (tvar[3] <= 23)
				{
					if (ft_print_plate(base, tvar, line, view))
						return (1);
					tvar[3]++;
				}
				tvar[2]++;
			}
			tvar[1]++;
		}
		tvar[0]++;
	}
	return (0);
}

int	ft_prepare(char *view)
{
	int		*base;
	int		*tvar;
	char	*line;

	line = 0;
	tvar = malloc(4 * sizeof(int));
	base = malloc(24 * sizeof(int));
	comb(base);
	if (!ft_loop(base, tvar, line, view))
		ft_error();
	free(line);
	free(tvar);
	free(base);
	return (0);
}

int ft_error(void)
{
	ft_printf("\e[91mError!\n\e[97m");
	ft_printf("\e[91mWrongs Input or there are no solutions!\n\e[97m");
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 2)
		return(ft_error());
	while (argv[1][++i] != '\0')
		if (argv[1][i] != 32 && i % 2 == 1)
			return(ft_error());
	if (i != 31)
		ft_error();
	else
		ft_prepare(argv[1]);
}
