/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:01:05 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/21 18:14:45 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skycrapper.h"

int	verif_echo(char *plate)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 3)
	{
		j = ++i;
		while (j <= 3)
		{
			if (plate[i] == plate[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verif_left(char *plate, char view)
{
	int	i;
	int	count;
	int	max_view;
	int	last_verif;

	i = 0;
	count = 0;
	last_verif = 0;
	max_view = plate[i];
	while (i <= 3)
	{
		if (plate[i] >= max_view)
		{
			max_view = plate[i];
			count++;
		}
		last_verif += plate[i++];
	}
	count += '0';
	if (count != view || last_verif != 202
		|| verif_echo(plate))
		return (0);
	return (1);
}

int	verif_right(char *plate, char view)
{
	int	i;
	int	count;
	int	max_view;
	int	last_verif;

	i = 3;
	count = 0;
	last_verif = 0;
	max_view = plate[i];
	while (i >= 0)
	{
		if (plate[i] >= max_view)
		{
			max_view = plate[i];
			count++;
		}
		last_verif += plate[i--];
	}
	count += '0';
	if (count != view || last_verif != 202
		|| verif_echo(plate))
		return (0);
	return (1);
}

int	verif(char *line, char *view)
{
	char	*column;

	column = malloc(17 * sizeof(char));
	if (!column)
		return (0);
	create_column(line, column);
	if (verif_left(&column[0], view[0]) && verif_left(&column[4], view[2])
		&& verif_left(&column[8], view[4]) && verif_left(&column[12], view[6])
		&& verif_right(&column[0], view[8]) && verif_right(&column[4], view[10])
		&& verif_right(&column[8], view[12])
		&& verif_right(&column[12], view[14])
		&& verif_left(&line[0], view[16]) && verif_left(&line[4], view[18])
		&& verif_left(&line[8], view[20]) && verif_left(&line[12], view[22])
		&& verif_right(&line[0], view[24]) && verif_right(&line[4], view[26])
		&& verif_right(&line[8], view[28]) && verif_right(&line[12], view[30]))
	{
		free(column);
		return (1);
	}
	free(column);
	return (0);
}
