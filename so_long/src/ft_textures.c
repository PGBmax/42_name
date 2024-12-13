/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:30:47 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/13 18:03:47 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void ft_block_walls(mlx_t *mlx, t_game game, int x, int y)
{
	if (game.map[x - 1][y - 1] == '1' && game.map[x - 1][y] == '1' && game.map[x - 1][y + 1] == '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y - 1] == '1' && game.map[x + 1][y] == '1' && game.map[x + 1][y + 1] == '1')
		mlx_image_to_window(mlx, game.image.ground, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1'
		&& game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.corner_3, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y] == '1'
		&& game.map[x + 1][y - 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_4, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y] == '1'
		&& game.map[x + 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_3, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y] == '1'
		&& game.map[x - 1][y - 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_1, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y] == '1'
		&& game.map[x - 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_2, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] != '1'
		&& game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.corner_4, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1'
		&& game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y] != '1')
		mlx_image_to_window(mlx, game.image.corner_2, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] == '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] != '1'
		&& game.map[x + 1][y] != '1')
		mlx_image_to_window(mlx, game.image.corner_1, y * SIZE, x * SIZE);
	else if ((game.map[x - 1][y] == '1' || game.map[x + 1][y] == '1')
		&& game.map[x][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.wall_v, y * SIZE, x * SIZE);
	else if ((game.map[x - 1][y] == '1' || game.map[x + 1][y] == '1')
		&& game.map[x][y - 1] != '1')
		mlx_image_to_window(mlx, game.image.wall_v, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1'
		&& (game.map[x][y - 1] == '1'
		|| game.map[x][y + 1] == '1'))
		mlx_image_to_window(mlx, game.image.wall_h, y * SIZE, x * SIZE);
	else if (game.map[x][y - 1] == '1'
		&& (game.map[x][y + 1] == '1'
		|| game.map[x + 1][y] != '1'))
		mlx_image_to_window(mlx, game.image.wall_h, y * SIZE, x * SIZE);
	else if (game.map[x - 1][y] != '1'
		&& game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.corner_3, y * SIZE, x * SIZE);
	else
		mlx_image_to_window(mlx, game.image.exit, y * SIZE, x * SIZE);
}

void ft_link_walls(mlx_t *mlx, t_game game, int x, int y)
{
	if (y == game.max_x && x != game.max_y && x != 0
		&& (game.map[x - 1][y - 1] != '1' || game.map[x + 1][y - 1] != '1')
		&& game.map[x - 1][y] == '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link_right, y * SIZE, x * SIZE);
	if (y == 0 && x != game.max_y && x != 0
		&& (game.map[x - 1][y + 1] != '1' || game.map[x + 1][y + 1] != '1')
		&& game.map[x - 1][y] == '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link_left, y * SIZE, x * SIZE);
	if (x == 0 && y != game.max_x && y != 0
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1'
		&& (game.map[x + 1][y - 1] != '1' || game.map[x + 1][y + 1] != '1')
		&& game.map[x + 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link_top, y * SIZE, x * SIZE);
	if (x == game.max_y && y != game.max_x && y != 0
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1'
		&& (game.map[x - 1][y - 1] != '1' || game.map[x - 1][y + 1] != '1')
		&& game.map[x - 1][y] == '1')
		mlx_image_to_window(mlx, game.image.link_bottom, y * SIZE, x * SIZE);
	if (x != game.max_y && y != game.max_x && y != 0 && x != 0
		&& game.map[x - 1][y] != '1'
		&& game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] != '1'
		&& game.map[x + 1][y] != '1')
		mlx_image_to_window(mlx, game.image.single_wall, y * SIZE, x * SIZE);
}



void	ft_show_walls(mlx_t *mlx, t_game game)
{
	if (game.x == 0 && game.y == 0)
		mlx_image_to_window(mlx, game.image.corner_top_left, game.y * SIZE, game.x * SIZE);
	if (game.x == 0 && game.y == game.max_x)
		mlx_image_to_window(mlx, game.image.corner_top_right, game.y * SIZE, game.x * SIZE);
	if (game.x == game.max_y && game.y == 0)
		mlx_image_to_window(mlx, game.image.corner_bottom_left, game.y * SIZE, game.x * SIZE);
	if (game.x == game.max_y && game.y == game.max_x)
		mlx_image_to_window(mlx, game.image.corner_bottom_right, game.y * SIZE, game.x * SIZE);
	if (game.y == 0 && game.x != 0 && game.x != game.max_y)
		mlx_image_to_window(mlx, game.image.wall_left, game.y * SIZE, game.x * SIZE);
	if (game.y == game.max_x  && game.x != 0 && game.x != game.max_y)
		mlx_image_to_window(mlx, game.image.wall_right, game.y * SIZE, game.x * SIZE);
	if (game.x == 0 && game.y != 0 && game.y != game.max_x)
		mlx_image_to_window(mlx, game.image.wall_top, game.y * SIZE, game.x * SIZE);
	if (game.x == game.max_y && game.y != 0 && game.y != game.max_x)
		mlx_image_to_window(mlx, game.image.wall_bottom, game.y * SIZE, game.x * SIZE);
	if (game.x != 0 && game.x != game.max_y && game.y != 0 && game.y != game.max_x)
		ft_block_walls(mlx, game, game.x, game.y);
	ft_link_walls(mlx, game, game.x, game.y);
}

void ft_frames_of_ghosts(mlx_t *mlx, t_game game)
{
	mlx_image_to_window(mlx, game.image.ground, game.clyde_y * SIZE, game.clyde_x * SIZE);
	mlx_image_to_window(mlx, game.image.ground, game.pinky_y * SIZE, game.pinky_x * SIZE);
	mlx_image_to_window(mlx, game.image.ground, game.blinky_y * SIZE, game.blinky_x * SIZE);
	mlx_image_to_window(mlx, game.image.ground, game.inky_y * SIZE, game.inky_x * SIZE);
	mlx_image_to_window(mlx, game.image.clyde[0], game.clyde_y * SIZE, game.clyde_x * SIZE);
	mlx_image_to_window(mlx, game.image.pinky[0], game.pinky_y * SIZE, game.pinky_x * SIZE);
	mlx_image_to_window(mlx, game.image.inky[0], game.inky_y * SIZE, game.inky_x * SIZE);
	mlx_image_to_window(mlx, game.image.blinky[0], game.blinky_y * SIZE, game.blinky_x * SIZE);
}

void ft_frames_of_player(mlx_t *mlx, t_game game)
{
	mlx_image_to_window(mlx, game.image.ground, game.player_y * SIZE, game.player_x * SIZE);
	mlx_image_to_window(mlx, game.image.pac_up_frame2, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_up_frame3, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_up_frame4, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_down_frame2, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_down_frame3, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_down_frame4, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_left_frame2, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_left_frame3, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_left_frame4, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_right_frame2, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_right_frame3, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.pac_right_frame4, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.player_u, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.player_d, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.player_l, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.player_r, -1 * SIZE, -1 * SIZE);
	mlx_image_to_window(mlx, game.image.player, game.player_y * SIZE, game.player_x * SIZE);
}

void ft_show_map(mlx_t *mlx, t_game game, char c)
{
	static int collec_i = 0;

	if (c == '1')
		ft_show_walls(mlx, game);
	if (c == '0' || c == 'E')
		mlx_image_to_window(mlx, game.image.ground, game.y * SIZE, game.x * SIZE);
	if (c == 'C')
	{
		mlx_image_to_window(mlx, game.image.fake_ground, game.y * SIZE, game.x * SIZE);
		mlx_image_to_window(mlx, game.image.collec, game.y * SIZE, game.x * SIZE);
		mlx_image_to_window(mlx, game.image.collec_2, game.y * SIZE, game.x * SIZE);
		mlx_image_to_window(mlx, game.image.collec_3, game.y * SIZE, game.x * SIZE);
		mlx_image_to_window(mlx, game.image.collec_4, game.y * SIZE, game.x * SIZE);
		game.image.fake_ground->instances[collec_i].enabled = 0;
		game.image.collec_2->instances[collec_i].enabled = 0;
		game.image.collec_3->instances[collec_i].enabled = 0;
		game.image.collec_4->instances[collec_i].enabled = 0;
		collec_i++;
	}
}
