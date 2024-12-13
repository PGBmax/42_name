/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:30:47 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/12 15:03:20 by pboucher         ###   ########.fr       */
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

void ft_show_map(mlx_t *mlx, t_game game, char c)
{	
	if (c == '1')
		ft_show_walls(mlx, game);
	if (c == '0' || c == 'E')
		mlx_image_to_window(mlx, game.image.ground, game.y * SIZE, game.x * SIZE);
	if (c == 'P')
		mlx_image_to_window(mlx, game.image.player, game.y * SIZE, game.x * SIZE);
	if (c == 'C')
		mlx_image_to_window(mlx, game.image.collec, game.y * SIZE, game.x * SIZE);
}
