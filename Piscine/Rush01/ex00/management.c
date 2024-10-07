/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:09:01 by pboucher          #+#    #+#             */
/*   Updated: 2024/08/18 18:25:55 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	comb(int *tab)
{
	tab[0] = 1234;
	tab[1] = 1243;
	tab[2] = 1324;
	tab[3] = 1342;
	tab[4] = 1423;
	tab[5] = 1432;
	tab[6] = 2134;
	tab[7] = 2143;
	tab[8] = 2314;
	tab[9] = 2341;
	tab[10] = 2413;
	tab[11] = 2431;
	tab[12] = 3124;
	tab[13] = 3142;
	tab[14] = 3214;
	tab[15] = 3241;
	tab[16] = 3412;
	tab[17] = 3421;
	tab[18] = 4123;
	tab[19] = 4132;
	tab[20] = 4213;
	tab[21] = 4231;
	tab[22] = 4312;
	tab[23] = 4321;
}

void	cpy_line(int *i, int var, char *line)
{
	int	j;

	j = 0;
	while (j <= 3)
	{
		line[*i] = var % 10 + '0';
		var /= 10;
		j++;
		*i -= 1;
	}
}

char	*create_line(int a, int b, int c, int d)
{
	int		i;
	char	*line;

	line = malloc(17 * sizeof(char));
	i = 15;
	cpy_line(&i, d, line);
	cpy_line(&i, c, line);
	cpy_line(&i, b, line);
	cpy_line(&i, a, line);
	return (line);
}

void	create_column(char *line, char *column)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= 15)
	{
		if (i == 16)
			i = 1;
		if (i == 17)
			i = 2;
		if (i == 18)
			i = 3;
		if (i == 19)
			i = 4;
		column[j] = line[i];
		i += 4;
		j++;
	}
}
