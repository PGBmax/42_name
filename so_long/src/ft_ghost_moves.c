/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:50:20 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/18 16:19:22 by pboucher         ###   ########.fr       */
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

void ft_frames_mobs(t_game *game, int n)
{
	game->image.blinky[4]->instances->x = -1 * SIZE;
	game->image.pinky[4]->instances->x = -1 * SIZE;
	game->image.inky[4]->instances->x = -1 * SIZE;
	game->image.clyde[4]->instances->x = -1 * SIZE;
	game->image.blinky[5]->instances->x = -1 * SIZE;
	game->image.pinky[5]->instances->x = -1 * SIZE;
	game->image.inky[5]->instances->x = -1 * SIZE;
	game->image.clyde[5]->instances->x = -1 * SIZE;
	game->image.blinky[6]->instances->x = -1 * SIZE;
	game->image.pinky[6]->instances->x = -1 * SIZE;
	game->image.inky[6]->instances->x = -1 * SIZE;
	game->image.clyde[6]->instances->x = -1 * SIZE;
	game->image.inky[n]->instances->x = game->inky_y * SIZE;
	game->image.inky[n]->instances->y = game->inky_x * SIZE;
	game->image.blinky[n]->instances->x = game->blinky_y * SIZE;
	game->image.blinky[n]->instances->y = game->blinky_x * SIZE;
	game->image.pinky[n]->instances->x = game->pinky_y * SIZE;
	game->image.pinky[n]->instances->y = game->pinky_x * SIZE;
	game->image.clyde[n]->instances->x = game->clyde_y * SIZE;
	game->image.clyde[n]->instances->y = game->clyde_x * SIZE;
	
}

void frame_mobs(t_game *game)
{
	static int count = 0;

	if (count < FRAMEG)
		ft_frames_mobs(game, 4);
	else if (count < FRAMEG * 2)
		ft_frames_mobs(game, 6);
	else if (count < FRAMEG * 3)
		ft_frames_mobs(game, 5);
	else if (count < FRAMEG * 4)
		ft_frames_mobs(game, 6);
	else if (count == FRAMEG * 4)
	{
		ft_frames_mobs(game, 4);
		count = 0;
	}
	count++;
}


void ft_moves_blinky(t_game *game, int i)
{
	int j;

	j = rand() % 4;
	if (game->nmb_ghost[0] == 0 || i > 9)
	{
		game->image.blinky[0]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[0]->instances->y = game->blinky_x * SIZE;
		return ;
	}
	game->image.blinky[0]->instances->x = -1 * SIZE;
	game->image.blinky[1]->instances->x = -1 * SIZE;
	game->image.blinky[2]->instances->x = -1 * SIZE;
	game->image.blinky[3]->instances->x = -1 * SIZE;
	game->image.blinky[4]->instances->x = -1 * SIZE;
	game->image.blinky[5]->instances->x = -1 * SIZE;
	if (game->blinky_x != -1 && game->blinky_y != -1 && 
	check_x(game, game->blinky_x - 1, game->blinky_y) && j == 0)
	{
		game->blinky_x--;
		game->image.blinky[0]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[0]->instances->y = game->blinky_x * SIZE;
	}
	else if (game->blinky_x != game->max_x && game->blinky_y != game->max_y &&
	check_x(game, game->blinky_x + 1, game->blinky_y) && j == 1)
	{
		game->blinky_x++;
		game->image.blinky[1]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[1]->instances->y = game->blinky_x * SIZE;
	}
	else if (game->blinky_x != -1 && game->blinky_y != -1 &&
	check_y(game, game->blinky_x, game->blinky_y - 1) && j == 2)
	{
		game->blinky_y--;
		game->image.blinky[2]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[2]->instances->y = game->blinky_x * SIZE;
	}
	else if (game->blinky_x != game->max_x && game->blinky_y != game->max_y &&
	check_y(game, game->blinky_x, game->blinky_y + 1) && j == 3)
	{
		game->blinky_y++;
		game->image.blinky[3]->instances->x = game->blinky_y * SIZE;
		game->image.blinky[3]->instances->y = game->blinky_x * SIZE;
	}
	else
		ft_moves_blinky(game, i + 1);
	if (game->blinky_x == game->player_x && game->blinky_y == game->player_y)
		game->victory = -1;
}

void ft_moves_clyde(t_game *game, int i)
{
	int j;

	j = rand() % 4;
	if (game->nmb_ghost[1] == 0 || i > 9)
	{
		game->image.clyde[0]->instances->x = game->clyde_y * SIZE;
		game->image.clyde[0]->instances->y = game->clyde_x * SIZE;
		return ;
	}
	game->image.clyde[0]->instances->x = -1 * SIZE;
	game->image.clyde[1]->instances->x = -1 * SIZE;
	game->image.clyde[2]->instances->x = -1 * SIZE;
	game->image.clyde[3]->instances->x = -1 * SIZE;
	game->image.clyde[4]->instances->x = -1 * SIZE;
	game->image.clyde[5]->instances->y = -1 * SIZE;
	if (game->clyde_x != -1 && game->clyde_y != -1 &&
	check_x(game, game->clyde_x - 1, game->clyde_y) && j == 1)
	{
		game->clyde_x--;
		game->image.clyde[0]->instances->x = game->clyde_y * SIZE;
		game->image.clyde[0]->instances->y = game->clyde_x * SIZE;
	}
	else if (game->clyde_x != game->max_x && game->clyde_y != game->max_y &&
	check_x(game, game->clyde_x + 1, game->clyde_y) && j == 2)
	{
		game->clyde_x++;
		game->image.clyde[1]->instances->x = game->clyde_y * SIZE;
		game->image.clyde[1]->instances->y = game->clyde_x * SIZE;
	}
	else if (game->clyde_x != -1 && game->clyde_y != -1 &&
	check_y(game, game->clyde_x, game->clyde_y - 1) && j == 3)
	{
		game->clyde_y--;
		game->image.clyde[2]->instances->x = game->clyde_y * SIZE;
		game->image.clyde[2]->instances->y = game->clyde_x * SIZE;
	}
	else if (game->clyde_x != game->max_x && game->clyde_y != game->max_y &&
	check_y(game, game->clyde_x, game->clyde_y + 1) && j == 0)
	{
		game->clyde_y++;
		game->image.clyde[3]->instances->x = game->clyde_y * SIZE;
		game->image.clyde[3]->instances->y = game->clyde_x * SIZE;
	}
	else
		ft_moves_clyde(game, i + 1);
	if (game->clyde_x == game->player_x && game->clyde_y == game->player_y)
		game->victory = -1;
}

void ft_moves_pinky(t_game *game, int i)
{
	int j;

	j = rand() % 4;
	if (game->nmb_ghost[2] == 0 || i > 9)
	{
		game->image.pinky[0]->instances->x = game->pinky_y * SIZE;
		game->image.pinky[0]->instances->y = game->pinky_x * SIZE;
		return ;
	}
	game->image.pinky[0]->instances->x = -1 * SIZE;
	game->image.pinky[1]->instances->x = -1 * SIZE;
	game->image.pinky[2]->instances->x = -1 * SIZE;
	game->image.pinky[3]->instances->x = -1 * SIZE;
	game->image.pinky[4]->instances->x = -1 * SIZE;
	game->image.pinky[5]->instances->x = -1 * SIZE;
	if (game->pinky_x != -1 && game->pinky_y != -1 && 
	check_x(game, game->pinky_x - 1, game->pinky_y) && j == 2)
	{
		game->pinky_x--;
		game->image.pinky[0]->instances->x = game->pinky_y * SIZE;
		game->image.pinky[0]->instances->y = game->pinky_x * SIZE;
	}
	else if (game->pinky_x != game->max_x && game->pinky_y != game->max_y &&
	check_x(game, game->pinky_x + 1, game->pinky_y) && j == 3)
	{
		game->pinky_x++;
		game->image.pinky[1]->instances->x = game->pinky_y * SIZE;
		game->image.pinky[1]->instances->y = game->pinky_x * SIZE;
	}
	else if (game->pinky_x != -1 && game->pinky_y != -1 &&
	check_y(game, game->pinky_x, game->pinky_y - 1) && j == 0)
	{
		game->pinky_y--;
		game->image.pinky[2]->instances->x = game->pinky_y * SIZE;
		game->image.pinky[2]->instances->y = game->pinky_x * SIZE;
	}
	else if (game->pinky_x != game->max_x && game->pinky_y != game->max_y &&
	check_y(game, game->pinky_x, game->pinky_y + 1) && j == 1)
	{
		game->pinky_y++;
		game->image.pinky[3]->instances->x = game->pinky_y * SIZE;
		game->image.pinky[3]->instances->y = game->pinky_x * SIZE;
	}
	else
		ft_moves_pinky(game, i + 1);
	if (game->pinky_x == game->player_x && game->pinky_y == game->player_y)
		game->victory = -1;
}

void ft_moves_inky(t_game *game, int i)
{
	int j;

	j = rand() % 4;
	if (game->nmb_ghost[3] == 0 || i > 9)
	{
		game->image.inky[0]->instances->x = game->inky_y * SIZE;
		game->image.inky[0]->instances->y = game->inky_x * SIZE;
		return ;
	}
	game->image.inky[0]->instances->x = -1 * SIZE;
	game->image.inky[1]->instances->x = -1 * SIZE;
	game->image.inky[2]->instances->x = -1 * SIZE;
	game->image.inky[3]->instances->x = -1 * SIZE;
	game->image.inky[4]->instances->x = -1 * SIZE;
	game->image.inky[5]->instances->x = -1 * SIZE;
	if (game->inky_x != -1 && game->inky_y != -1 && 
	check_x(game, game->inky_x - 1, game->inky_y) && j == 3)
	{
		game->inky_x--;
		game->image.inky[0]->instances->x = game->inky_y * SIZE;
		game->image.inky[0]->instances->y = game->inky_x * SIZE;
	}
	else if (game->inky_x != game->max_x && game->inky_y != game->max_y &&
	check_x(game, game->inky_x + 1, game->inky_y) && j == 0)
	{
		game->inky_x++;
		game->image.inky[1]->instances->x = game->inky_y * SIZE;
		game->image.inky[1]->instances->y = game->inky_x * SIZE;
	}
	else if (game->inky_x != -1 && game->inky_y != -1 &&
	check_y(game, game->inky_x, game->inky_y - 1) && j == 1)
	{
		game->inky_y--;
		game->image.inky[2]->instances->x = game->inky_y * SIZE;
		game->image.inky[2]->instances->y = game->inky_x * SIZE;
	}
	else if (game->inky_x != game->max_x && game->inky_y != game->max_y &&
	check_y(game, game->inky_x, game->inky_y + 1) && j == 2)
	{
		game->inky_y++;
		game->image.inky[3]->instances->x = game->inky_y * SIZE;
		game->image.inky[3]->instances->y = game->inky_x * SIZE;
	}
	else
		ft_moves_inky(game, i + 1);
	if (game->inky_x == game->player_x && game->inky_y == game->player_y)
		game->victory = -1;
}
