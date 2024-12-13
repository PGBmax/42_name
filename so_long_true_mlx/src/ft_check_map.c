/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:28:14 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/06 16:11:23 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_know_size_map(t_game *game)
{
	game->max_collec = 0;
	game->x = -1;
	while (game->map[++game->x])
	{
		game->y = -1;
		while (game->map[game->x][++game->y])
		{
			if (game->map[game->x][game->y] == 'C')
				game->max_collec++;
			if (game->map[game->x][game->y] == 'P')
			{
				game->nmb_player++;
				game->player_x = game->x;
				game->player_y = game->y;
			}
			if (game->map[game->x][game->y] == 'E')
			{
				game->nmb_exit++;
				game->exit_x = game->x;
				game->exit_y = game->y;
			}
		}	
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

int ft_pars_walls(t_game game)
{
	int x;
	int y;

	x = 0;
	while (game.map[x])
	{
		y = 0;
		while (game.map[x][y])
		{
			if (game.map[x][y] != '1' && (x == 0 || x == game.max_y))
				return (1);
			if (game.map[x][y] != '1' && (y == 0 || y == game.max_x))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void fill(t_game *game, int row, int col, char **map)
{
	if (row < 0 || col < 0 || row > game->max_x || col > game->max_y)
		return	;
	if (map[col][row] == '1' || map[col][row] == 'D')
		return	;
	map[col][row] = 'D';
	fill(game, row - 1, col, map);
	fill(game, row + 1, col, map);
	fill(game, row, col + 1, map);
	fill(game, row, col - 1, map);
}

int ft_check_values(char c)
{
	if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
		return (0);
	return (1);
}

char **fill_map(t_game game)
{
	char **map;
	int	x;
	int y;
	
	x = -1;
	map = ft_calloc(sizeof(char *), game.max_y + 2);
	map[game.max_y + 1] = NULL;
	while (++x <= game.max_y)
	{
		map[x] = ft_calloc(game.max_x + 2, 1);
		if (!map[x])
			return (NULL);
		y = -1;
		while (++y <= game.max_x)
		{
			map[x][y] = game.map[x][y];
			if (!ft_check_values(map[x][y]))
			{
				ft_error(11);
				return (NULL);
			}
		}
		map[x][y] = 0;
	}
	return (map);
}


int ft_parsing(t_game game)
{
	int x = -1;
	int y = -1;
	char **map;
	
	map = fill_map(game);
	if (!map)
		return (0);
	if (game.nmb_player != 1)
		return (ft_error(10));
	if (game.nmb_exit != 1)
		return (ft_error(5));
	fill(&game, game.player_y, game.player_x, map);
	x = -1;
	if (game.max_collec == 0)
		return (ft_error(8));
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'C')
				return (ft_error(6));
			if (map[x][y] == 'E')
				return (ft_error(7));
		}
	}
	free(map);
	return (1);
}
