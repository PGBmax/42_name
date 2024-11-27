/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:28:14 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/27 12:28:30 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_know_size_map(t_game *game)
{
	game->x = 0;
	while (game->map[game->x])
	{
		game->y = 0;
		while (game->map[game->x][game->y])
			game->y++;
		game->x++;
	}
	game->max_x = game->y - 1;
	game->max_y = game->x - 1;
}

int check_map(char *map)
{
	int i;
	int j;
	char *check;

	i = ft_strlen(map) - 1;
	check = ".ber";
	j = ft_strlen(check) - 1;
	while (map[i] == check[j])
	{
		i--;
		j--;
	}
	if (j < 0)
		return (1);
	else
		return (0);
}