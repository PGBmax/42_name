/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:06:09 by pboucher          #+#    #+#             */
/*   Updated: 2024/08/18 19:46:47 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	comb(int *tab);
int		verif(char *line, char *view);
char	*create_line(int a, int b, int c, int d);

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
			write(1, &line[i], 1);
			if (i == 3 || i == 7 || i == 11 || i == 15)
			{
				write(1, "\n", 1);
			}
			else
				write(1, " ", 1);
			i++;
		}
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int	ft_loop(int *base, int *tvar, char *line, char *view)
{
	line = malloc(17 * sizeof(char));
	free(line);
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
		write(1, "Error\n", 6);
	free(line);
	free(tvar);
	free(base);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] != 32 && i % 2 == 1)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (i != 31)
		write(1, "Error\n", 6);
	else
		ft_prepare(argv[1]);
}
