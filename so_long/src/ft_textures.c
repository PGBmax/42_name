/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:30:47 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/15 03:01:30 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void ft_block_walls_3(mlx_t *mlx, t_game, int x, int y)
{
	if ((game.map[x - 1][y] == '1' || game.map[x + 1][y] == '1')
		&& game.map[x][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.walls[1], y * SIZE, x * SIZE);
	else if ((game.map[x - 1][y] == '1' || game.map[x + 1][y] == '1')
		&& game.map[x][y - 1] != '1')
		mlx_image_to_window(mlx, game.image.walls[1], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1'
		&& (game.map[x][y - 1] == '1' || game.map[x][y + 1] == '1'))
		mlx_image_to_window(mlx, game.image.walls[0], y * SIZE, x * SIZE);
	else if (game.map[x][y - 1] == '1'
		&& (game.map[x][y + 1] == '1' || game.map[x + 1][y] != '1'))
		mlx_image_to_window(mlx, game.image.walls[0], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1' && game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.corner[2], y * SIZE, x * SIZE);
	else
		mlx_image_to_window(mlx, game.image.exit, x * SIZE, y * SIZE);
}

void ft_block_walls_2(mlx_t *mlx, t_game game, int x, int y)
{
	if (game.map[x - 1][y] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1'
		&& game.map[x - 1][y - 1] != '1')
		mlx_image_to_window(mlx, game.image.corner[0], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1'
		&& game.map[x - 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner[1], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1'
		&& game.map[x - 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner[1], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] != '1' && game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.corner[3], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1' && game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] != '1')
		mlx_image_to_window(mlx, game.image.corner[1], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] != '1' && game.map[x + 1][y] != '1')
		mlx_image_to_window(mlx, game.image.corner[0], y * SIZE, x * SIZE);
	else
		ft_block_walls_3(mlx, game, x, y);
}

void ft_block_walls(mlx_t *mlx, t_game game, int x, int y)
{
	if (game.map[x - 1][y - 1] == '1' && game.map[x - 1][y] == '1' 
		&& game.map[x - 1][y + 1] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y - 1] == '1' 
		&& game.map[x + 1][y] == '1' && game.map[x + 1][y + 1] == '1')
		mlx_image_to_window(mlx, game.image.ground, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1' && game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.corner[2], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1'
		&& game.map[x + 1][y - 1] != '1')
		mlx_image_to_window(mlx, game.image.corner[3], y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1' && game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1' && game.map[x + 1][y] == '1'
		&& game.map[x + 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner[2], y * SIZE, x * SIZE);
	else
		ft_block_walls_2(mlx, game, x, y);
}

void ft_link_walls(mlx_t *mlx, t_game game, int x, int y)
{
	if (y == game.max_x && x != game.max_y && x != 0
		&& (game.map[x - 1][y - 1] != '1' || game.map[x + 1][y - 1] != '1')
		&& game.map[x - 1][y] == '1'
		&& game.map[x][y - 1] == '1' && game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link[1], y * SIZE, x * SIZE);
	if (y == 0 && x != game.max_y && x != 0
		&& (game.map[x - 1][y + 1] != '1' || game.map[x + 1][y + 1] != '1')
		&& game.map[x - 1][y] == '1'
		&& game.map[x][y + 1] == '1'&& game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link[0], y * SIZE, x * SIZE);
	if (x == 0 && y != game.max_x && y != 0
		&& game.map[x][y - 1] == '1' && game.map[x][y + 1] == '1'
		&& (game.map[x + 1][y - 1] != '1' || game.map[x + 1][y + 1] != '1')
		&& game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link[2], y * SIZE, x * SIZE);
	if (x == game.max_y && y != game.max_x && y != 0
		&& game.map[x][y - 1] == '1' && game.map[x][y + 1] == '1'
		&& (game.map[x - 1][y - 1] != '1' || game.map[x - 1][y + 1] != '1')
		&& game.map[x - 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link[2], y * SIZE, x * SIZE);
	if (x != game.max_y && y != game.max_x && y != 0 && x != 0
		&& game.map[x - 1][y] != '1' && game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] != '1' && game.map[x + 1][y] != '1')
		mlx_image_to_window(mlx, game.image.walls[2], y * SIZE, x * SIZE);
}

void	ft_show_walls(mlx_t *mlx, t_game game, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_image_to_window(mlx, game.image.off_corner[2], y * SIZE, x * SIZE);
	if (x == 0 && y == game.max_x)
		mlx_image_to_window(mlx, game.image.off_corner[3], y * SIZE, x * SIZE);
	if (x == game.max_y && y == 0)
		mlx_image_to_window(mlx, game.image.off_corner[0], y * SIZE, x * SIZE);
	if (x == game.max_y && y == game.max_x)
		mlx_image_to_window(mlx, game.image.off_corner[1], y * SIZE, x * SIZE);
	if (y == 0 && x != 0 && x != game.max_y)
		mlx_image_to_window(mlx, game.image.off_wall[0], y * SIZE, x * SIZE);
	if (y == game.max_x  && x != 0 && x != game.max_y)
		mlx_image_to_window(mlx, game.image.off_wall[1], y * SIZE, x * SIZE);
	if (x == 0 && y != 0 && y != game.max_x)
		mlx_image_to_window(mlx, game.image.off_wall[2], y * SIZE, x * SIZE);
	if (x == game.max_y && y != 0 && y != game.max_x)
		mlx_image_to_window(mlx, game.image.off_wall[3], y * SIZE, x * SIZE);
	if (x != 0 && x != game.max_y && y != 0 && y != game.max_x)
		ft_block_walls(mlx, game, x, y);
	ft_link_walls(mlx, game, x, y);
}

void ft_frames_of_ghosts(mlx_t *mlx, t_game game)
{
	mlx_image_to_window(mlx, game.image.ground, game.clyde_y * SIZE, game.clyde_x * SIZE);
	mlx_image_to_window(mlx, game.image.ground, game.pinky_y * SIZE, game.pinky_x * SIZE);
	mlx_image_to_window(mlx, game.image.ground, game.blinky_y * SIZE, game.blinky_x * SIZE);
	mlx_image_to_window(mlx, game.image.ground, game.inky_y * SIZE, game.inky_x * SIZE);
	mlx_image_to_window(mlx, game.image.clyde[0], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pinky[0], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.inky[0],-1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.blinky[0], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.clyde[1], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pinky[1], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.inky[1],-1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.blinky[1], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.clyde[2], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pinky[2], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.inky[2],-1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.blinky[2], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.clyde[3], game.clyde_y * SIZE, game.clyde_x * SIZE);
	mlx_image_to_window(mlx, game.image.pinky[3], game.pinky_y * SIZE, game.pinky_x * SIZE);
	mlx_image_to_window(mlx, game.image.inky[3], game.inky_y * SIZE, game.inky_x * SIZE);
	mlx_image_to_window(mlx, game.image.blinky[3], game.blinky_y * SIZE, game.blinky_x * SIZE);
}

void ft_frames_of_player(mlx_t *mlx, t_game game)
{
	mlx_image_to_window(mlx, game.image.ground, game.player_y * SIZE, game.player_x * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[0], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[1], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[2], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[3], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[4], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[5], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[6], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[7], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[8], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[9], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[10], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_frame[11], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.player[1], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.player[2], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.player[3], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.player[4], -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.player[0], game.player_y * SIZE, game.player_x * SIZE);
}

void ft_show_map(mlx_t *mlx, t_game game, char c)
{
	static int collec_i = 0;

	if (c == '1')
		ft_show_walls(mlx, game, game.x, game.y);
	if (c == '0' || c == 'E')
		mlx_image_to_window(mlx, game.image.ground, game.y * SIZE, game.x * SIZE);
	if (c == 'C')
	{
		mlx_image_to_window(mlx, game.image.fake_ground, game.y * SIZE, game.x * SIZE);
		mlx_image_to_window(mlx, game.image.collec[0], game.y * SIZE, game.x * SIZE);
		mlx_image_to_window(mlx, game.image.collec[1], game.y * SIZE, game.x * SIZE);
		mlx_image_to_window(mlx, game.image.collec[2], game.y * SIZE, game.x * SIZE);
		mlx_image_to_window(mlx, game.image.collec[3], game.y * SIZE, game.x * SIZE);
		game.image.fake_ground->instances[collec_i].enabled = 0;
		game.image.collec[1]->instances[collec_i].enabled = 0;
		game.image.collec[2]->instances[collec_i].enabled = 0;
		game.image.collec[3]->instances[collec_i].enabled = 0;
		collec_i++;
	}
}
