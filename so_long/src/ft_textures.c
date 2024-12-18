/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:30:47 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/18 15:59:08 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_frames_for_long(mlx_t *mlx, t_game game, mlx_image_t *img, int check)
{
	int	s;

	s = SIZE;
	if (check == 0)
		mlx_image_to_window(mlx, img, game.blinky_y * s, game.blinky_x * s);
	else if (check == 1)
		mlx_image_to_window(mlx, img, game.player_y * s, game.player_x * s);
}

void	ft_frames_of_ghosts(mlx_t *mlx, t_game game, t_image *img)
{
	int	s;
	int i;

	s = SIZE;
	i = -1;
	mlx_image_to_window(mlx, img->ground, game.clyde_y * s, game.clyde_x * s);
	mlx_image_to_window(mlx, img->ground, game.pinky_y * s, game.pinky_x * s);
	mlx_image_to_window(mlx, img->ground, game.blinky_y * s, game.blinky_x * s);
	mlx_image_to_window(mlx, img->ground, game.inky_y * s, game.inky_x * s);
	while (++i < 3)
	{
		mlx_image_to_window(mlx, img->clyde[i], -1 * s, -1 * s);
		mlx_image_to_window(mlx, img->pinky[i], -1 * s, -1 * s);
		mlx_image_to_window(mlx, img->inky[i], -1 * s, -1 * s);
		mlx_image_to_window(mlx, img->blinky[i], -1 * s, -1 * s);
	}
	i--;
	while (++i < 7)
	{
		mlx_image_to_window(mlx, img->clyde[i], game.clyde_y * s, game.clyde_x * s);
		mlx_image_to_window(mlx, img->pinky[i], game.pinky_y * s, game.pinky_x * s);
		mlx_image_to_window(mlx, img->inky[i], game.inky_y * s, game.inky_x * s);
		ft_frames_for_long(mlx, game, img->blinky[i], 0);
	}
}

void	ft_frames_of_player(mlx_t *mlx, t_game game, t_image *img)
{
	int	s;

	s = SIZE;
	mlx_image_to_window(mlx, img->pac_frame[0], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->pac_frame[1], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->pac_frame[2], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->pac_frame[3], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->pac_frame[4], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->pac_frame[5], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->pac_frame[6], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->pac_frame[7], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->pac_frame[8], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->pac_frame[9], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->pac_frame[10], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->pac_frame[11], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->player[1], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->player[2], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->player[3], -1 * s, -1 * s);
	mlx_image_to_window(mlx, img->player[4], -1 * s, -1 * s);
	ft_frames_for_long(mlx, game, img->player[0], 1);
}

void	ft_show_map(mlx_t *mlx, t_game game, char c)
{
	static int	collec_i = 0;
	int			s;

	s = SIZE;
	if (c == '1')
		ft_show_walls(mlx, game, game.x, game.y);
	if (c == '0' || c == 'E' || c == 'P')
		mlx_image_to_window(mlx, game.image.ground, game.y * s, game.x * s);
	if (c == 'C')
	{
		mlx_image_to_window(mlx, game.image.fground, game.y * s, game.x * s);
		mlx_image_to_window(mlx, game.image.collec[0], game.y * s, game.x * s);
		mlx_image_to_window(mlx, game.image.collec[1], game.y * s, game.x * s);
		mlx_image_to_window(mlx, game.image.collec[2], game.y * s, game.x * s);
		mlx_image_to_window(mlx, game.image.collec[3], game.y * s, game.x * s);
		game.image.fground->instances[collec_i].enabled = 0;
		game.image.collec[1]->instances[collec_i].enabled = 0;
		game.image.collec[2]->instances[collec_i].enabled = 0;
		game.image.collec[3]->instances[collec_i].enabled = 0;
		collec_i++;
	}
}
