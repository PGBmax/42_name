/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:30:47 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/27 19:16:59 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void ft_block_walls(mlx_t *mlx, t_game game, int x, int y)
{
	if (game.map[x - 1][y - 1] != '1'
		&& game.map[x - 1][y] != '1'
		&& game.map[x - 1][y + 1] != '1'
		&& game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y - 1] != '1'
		&& game.map[x + 1][y] == '1'
		&& game.map[x + 1][y + 1] == '1')
		mlx_image_to_window(mlx, game.image.corner_top_left, y * SIZE, x * SIZE);
	if (game.map[x - 1][y - 1] != '1'
		&& game.map[x - 1][y] != '1'
		&& game.map[x - 1][y + 1] != '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] != '1'
		&& game.map[x + 1][y - 1] == '1'
		&& game.map[x + 1][y] == '1'
		&& game.map[x + 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_top_right, y * SIZE, x * SIZE);
	if (game.map[x - 1][y - 1] != '1'
		&& game.map[x - 1][y] == '1'
		&& game.map[x - 1][y + 1] == '1'
		&& game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y - 1] != '1'
		&& game.map[x + 1][y] != '1'
		&& game.map[x + 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_bottom_left, y * SIZE, x * SIZE);
	if (game.map[x - 1][y - 1] == '1'
		&& game.map[x - 1][y] == '1'
		&& game.map[x - 1][y + 1] != '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] != '1'
		&& game.map[x + 1][y - 1] != '1'
		&& game.map[x + 1][y] != '1'
		&& game.map[x + 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_bottom_right, y * SIZE, x * SIZE);
	if (game.map[x - 1][y - 1] == '1'
		&& game.map[x - 1][y] == '1'
		&& game.map[x -1][y + 1] != '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] != '1'
		&& game.map[x + 1][y - 1] == '1'
		&& game.map[x + 1][y] == '1'
		&& game.map[x + 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.wall_right, y * SIZE, x * SIZE);
	if (game.map[x - 1][y - 1] != '1'
		&& game.map[x - 1][y] == '1'
		&& game.map[x -1][y + 1] == '1'
		&& game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y - 1] != '1'
		&& game.map[x + 1][y] == '1'
		&& game.map[x + 1][y + 1] == '1')
		mlx_image_to_window(mlx, game.image.wall_left, y * SIZE, x * SIZE);
	if (game.map[x - 1][y - 1] != '1'
		&& game.map[x - 1][y] != '1'
		&& game.map[x -1][y + 1] != '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y - 1] == '1'
		&& game.map[x + 1][y] == '1'
		&& game.map[x + 1][y + 1] == '1')
		mlx_image_to_window(mlx, game.image.wall_top, y * SIZE, x * SIZE);
	if (game.map[x - 1][y - 1] == '1'
		&& game.map[x - 1][y] == '1'
		&& game.map[x -1][y + 1] == '1'
		&& game.map[x][y - 1] == '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y - 1] != '1'
		&& game.map[x + 1][y] != '1'
		&& game.map[x + 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.wall_bottom, y * SIZE, x * SIZE);
	if (game.map[x - 1][y - 1] != '1'
		&& game.map[x - 1][y] != '1'
		&& game.map[x -1][y + 1] != '1'
		&& game.map[x][y - 1] != '1'
		&& game.map[x][y + 1] == '1'
		&& game.map[x + 1][y - 1] != '1'
		&& game.map[x + 1][y] == '1'
		&& game.map[x + 1][y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_top_left, y * SIZE, x * SIZE);
}


void	ft_show_details(mlx_t *mlx, t_game game)
{
	if (game.x != 0 && game.y == 0 && game.x != game.max_y
		&& game.map[game.x - 1][game.y] == '1' 
		&& game.map[game.x - 1][game.y + 1] != '1' 
		&& game.map[game.x][game.y + 1] == '1'
		&& game.map[game.x + 1][game.y] != '1'
		&& game.map[game.x + 1][game.y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_bottom_left, game.y * SIZE, game.x * SIZE);
	if (game.x != 0 && game.y == 0 && game.x != game.max_y
		&& game.map[game.x - 1][game.y] != '1' 
		&& game.map[game.x - 1][game.y + 1] != '1' 
		&& game.map[game.x][game.y + 1] == '1'
		&& game.map[game.x + 1][game.y] == '1'
		&& game.map[game.x + 1][game.y + 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_top_left, game.y * SIZE, game.x * SIZE);
	if (game.x != 0 && game.y == game.max_x && game.x != game.max_y
		&& game.map[game.x - 1][game.y] == '1' 
		&& game.map[game.x - 1][game.y - 1] != '1' 
		&& game.map[game.x][game.y - 1] == '1'
		&& game.map[game.x + 1][game.y] != '1'
		&& game.map[game.x + 1][game.y - 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_bottom_right, game.y * SIZE, game.x * SIZE);
	if (game.x != 0 && game.y == game.max_x && game.x != game.max_y
		&& game.map[game.x - 1][game.y] != '1' 
		&& game.map[game.x - 1][game.y - 1] != '1' 
		&& game.map[game.x][game.y - 1] == '1'
		&& game.map[game.x + 1][game.y] == '1'
		&& game.map[game.x + 1][game.y - 1] != '1')
		mlx_image_to_window(mlx, game.image.corner_top_right, game.y * SIZE, game.x * SIZE);
	if (game.x != 0 && game.x != game.max_y && game.y != 0 && game.y != game.max_x)
		ft_block_walls(mlx, game, game.x, game.y);
		
		
}

void	ft_show_walls(mlx_t *mlx, t_game game)
{
	if (game.x == 0 && game.y == 0)
		mlx_image_to_window(mlx, game.image.corner_top_left, game.y * SIZE, game.x * SIZE);
	else if (game.x == 0 && game.y == game.max_x)
		mlx_image_to_window(mlx, game.image.corner_top_right, game.y * SIZE, game.x * SIZE);
	else if (game.x == game.max_y && game.y == 0)
		mlx_image_to_window(mlx, game.image.corner_bottom_left, game.y * SIZE, game.x * SIZE);
	else if (game.x == game.max_y && game.y == game.max_x)
		mlx_image_to_window(mlx, game.image.corner_bottom_right, game.y * SIZE, game.x * SIZE);
	else if (game.y == 0 && game.x != 0 && game.x != game.max_y)
		mlx_image_to_window(mlx, game.image.wall_left, game.y * SIZE, game.x * SIZE);
	else if (game.y == game.max_x  && game.x != 0 && game.x != game.max_y)
		mlx_image_to_window(mlx, game.image.wall_right, game.y * SIZE, game.x * SIZE);
	else if (game.x == 0 && game.y != 0 && game.y != game.max_x)
		mlx_image_to_window(mlx, game.image.wall_top, game.y * SIZE, game.x * SIZE);
	else if (game.x == game.max_y && game.y != 0 && game.y != game.max_x)
		mlx_image_to_window(mlx, game.image.wall_bottom, game.y * SIZE, game.x * SIZE);
	ft_show_details(mlx, game);
}

void ft_show_map(mlx_t *mlx, t_game game, char c)
{	
	if (c == '1')
		ft_show_walls(mlx, game);
	if (c == '0')
		mlx_image_to_window(mlx, game.image.ground, game.y * SIZE, game.x * SIZE);
	if (c == 'E')
		mlx_image_to_window(mlx, game.image.exit, game.y * SIZE, game.x * SIZE);
	if (c == 'P')
		mlx_image_to_window(mlx, game.image.player, game.y * SIZE, game.x * SIZE);
	if (c == 'C')
		mlx_image_to_window(mlx, game.image.collec, game.y * SIZE, game.x * SIZE);
}
