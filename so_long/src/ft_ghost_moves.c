/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:50:20 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/16 18:28:09 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int check_x(t_game *game, int x, int y)
{
	if (x == game->inky_x || x == game->pinky_x || 
	x == game->clyde_x || x == game->blinky_x)
		return (0);
	if (game->map[x][y] == '1' || game->map[x][y] == 'E')
		return (0);
	return (1);
}

int check_y(t_game *game, int x, int y)
{
	if (y == game->inky_y || y == game->pinky_y || 
	y == game->clyde_y || y == game->blinky_y)
		return (0);
	if (game->map[x][y] == '1' || game->map[x][y] == 'E')
		return (0);
	return (1);
}

void ft_moves_blinky(t_game *game)
{
	if (game->nmb_ghost[0] == 0)
		return ;
	game->image.blinky[0]->instances->x = -1 * SIZE;
	game->image.blinky[1]->instances->x = -1 * SIZE;
	game->image.blinky[2]->instances->x = -1 * SIZE;
	game->image.blinky[3]->instances->x = -1 * SIZE;
	if (game->blinky_x != -1 && game->blinky_y != -1 && 
	check_x(game, game->blinky_x - 1, game->blinky_y) && rand() % 4 == 0)
	{
		game->blinky_x--;
		game->image.blinky[0]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[0]->instances->y = game->blinky_x * SIZE;
	}
	else if (game->blinky_x != game->max_x && game->blinky_y != game->max_y &&
	check_x(game, game->blinky_x + 1, game->blinky_y) && rand() % 4 == 1)
	{
		game->blinky_x++;
		game->image.blinky[1]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[1]->instances->y = game->blinky_x * SIZE;
	}
	else if (game->blinky_x != -1 && game->blinky_y != -1 &&
	check_y(game, game->blinky_x, game->blinky_y - 1) && rand() % 4 == 2)
	{
		game->blinky_y--;
		game->image.blinky[2]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[2]->instances->y = game->blinky_x * SIZE;
	}
	else if (game->blinky_x != game->max_x && game->blinky_y != game->max_y &&
	check_y(game, game->blinky_x, game->blinky_y + 1) && rand() % 4 == 3)
	{
		game->blinky_y++;
		game->image.blinky[3]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[3]->instances->y = game->blinky_x * SIZE;
	}
	else
		ft_moves_blinky(game);
	if (game->blinky_x == game->player_x && game->blinky_y == game->player_y)
		game->victory = -1;
}
