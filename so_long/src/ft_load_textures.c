/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:37:19 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/14 23:37:19 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_frames_ghost(mlx_t *mlx, t_textures *tex, t_image *img)
{
	int	i;

	i = 3;
	tex->blinky[4] = mlx_load_png("./texb/red_frame0.png");
	tex->blinky[5] = mlx_load_png("./texb/red_frame1.png");
	tex->pinky[4] = mlx_load_png("./texb/pink_frame0.png");
	tex->pinky[5] = mlx_load_png("./texb/pink_frame1.png");
	tex->inky[4] = mlx_load_png("./texb/cyan_frame0.png");
	tex->inky[5] = mlx_load_png("./texb/cyan_frame1.png");
	tex->clyde[4] = mlx_load_png("./texb/orange_frame0.png");
	tex->clyde[5] = mlx_load_png("./texb/orange_frame1.png");
	tex->blinky[6] = mlx_load_png("./texb/red_frame2.png");
	tex->pinky[6] = mlx_load_png("./texb/pink_frame2.png");
	tex->inky[6] = mlx_load_png("./texb/cyan_frame2.png");
	tex->clyde[6] = mlx_load_png("./texb/orange_frame2.png");
	while (++i < 7)
	{
		img->clyde[i] = mlx_texture_to_image(mlx, tex->clyde[i]);
		img->inky[i] = mlx_texture_to_image(mlx, tex->inky[i]);
		img->pinky[i] = mlx_texture_to_image(mlx, tex->pinky[i]);
		img->blinky[i] = mlx_texture_to_image(mlx, tex->blinky[i]);
	}
}

void	ft_textures_ghost(mlx_t *mlx, t_textures *tex, t_image *img)
{
	static int	i = -1;

	tex->inky[0] = mlx_load_png("./texb/cyan_up.png");
	tex->inky[1] = mlx_load_png("./texb/cyan_down.png");
	tex->inky[2] = mlx_load_png("./texb/cyan_left.png");
	tex->inky[3] = mlx_load_png("./texb/cyan_right.png");
	tex->pinky[0] = mlx_load_png("./texb/pink_up.png");
	tex->pinky[1] = mlx_load_png("./texb/pink_down.png");
	tex->pinky[2] = mlx_load_png("./texb/pink_left.png");
	tex->pinky[3] = mlx_load_png("./texb/pink_right.png");
	tex->blinky[0] = mlx_load_png("./texb/red_up.png");
	tex->blinky[1] = mlx_load_png("./texb/red_down.png");
	tex->blinky[2] = mlx_load_png("./texb/red_left.png");
	tex->blinky[3] = mlx_load_png("./texb/red_right.png");
	tex->clyde[0] = mlx_load_png("./texb/orange_up.png");
	tex->clyde[1] = mlx_load_png("./texb/orange_down.png");
	tex->clyde[2] = mlx_load_png("./texb/orange_left.png");
	tex->clyde[3] = mlx_load_png("./texb/orange_right.png");
	while (++i < 4)
	{
		img->clyde[i] = mlx_texture_to_image(mlx, tex->clyde[i]);
		img->inky[i] = mlx_texture_to_image(mlx, tex->inky[i]);
		img->pinky[i] = mlx_texture_to_image(mlx, tex->pinky[i]);
		img->blinky[i] = mlx_texture_to_image(mlx, tex->blinky[i]);
	}
}

void	ft_textures_walls_1(mlx_t *mlx, t_textures *tex, t_image *img)
{
	int	i;

	i = -1;
	tex->off_wall[0] = mlx_load_png("./text/walls_left.png");
	tex->off_wall[1] = mlx_load_png("./text/walls_right.png");
	tex->off_wall[2] = mlx_load_png("./text/walls_top.png");
	tex->off_wall[3] = mlx_load_png("./text/walls_bottom.png");
	tex->off_corner[0] = mlx_load_png("./text/corner_bottom_left.png");
	tex->off_corner[1] = mlx_load_png("./text/corner_bottom_right.png");
	tex->off_corner[2] = mlx_load_png("./text/corner_top_left.png");
	tex->off_corner[3] = mlx_load_png("./text/corner_top_right.png");
	tex->corner[0] = mlx_load_png("./text/corner_1.png");
	tex->corner[1] = mlx_load_png("./text/corner_2.png");
	tex->corner[2] = mlx_load_png("./text/corner_3.png");
	tex->corner[3] = mlx_load_png("./text/corner_4.png");
	while (++i < 4)
	{
		img->off_wall[i] = mlx_texture_to_image(mlx, tex->off_wall[i]);
		img->off_corner[i] = mlx_texture_to_image(mlx, tex->off_corner[i]);
		img->corner[i] = mlx_texture_to_image(mlx, tex->corner[i]);
	}
}

void	ft_textures_walls_2(mlx_t *mlx, t_textures *tex, t_image *img)
{
	int	i;

	i = -1;
	tex->link[0] = mlx_load_png("./text/link_walls_left.png");
	tex->link[1] = mlx_load_png("./text/link_walls_right.png");
	tex->link[2] = mlx_load_png("./text/link_walls_top.png");
	tex->link[3] = mlx_load_png("./text/link_walls_bottom.png");
	tex->walls[0] = mlx_load_png("./text/wall_h.png");
	tex->walls[1] = mlx_load_png("./text/wall_v.png");
	tex->walls[2] = mlx_load_png("./text/single_wall.png");
	tex->pac_man_exit[0] = mlx_load_png("./text/pac_man_exit1.png");
	tex->pac_man_exit[1] = mlx_load_png("./text/pac_man_exit2.png");
	tex->pac_man_exit[2] = mlx_load_png("./text/pac_man_exit3.png");
	tex->pac_man_exit[3] = mlx_load_png("./text/pac_man_exit4.png");
	tex->pac_man_exit[4] = mlx_load_png("./text/pac_man_exit5.png");
	while (++i < 4)
		img->link[i] = mlx_texture_to_image(mlx, tex->link[i]);
	i = -1;
	while (++i < 3)
		img->walls[i] = mlx_texture_to_image(mlx, tex->walls[i]);
	i = -1;
	while (++i < 5)
		img->pac_man_exit[i] = mlx_texture_to_image(mlx, tex->pac_man_exit[i]);
}

void	ft_textures_data(mlx_t *mlx, t_textures *tex, t_image *img)
{
	int	i;

	i = -1;
	tex->digit[0] = mlx_load_png("./texb/zero.png");
	tex->digit[1] = mlx_load_png("./texb/one.png");
	tex->digit[2] = mlx_load_png("./texb/two.png");
	tex->digit[3] = mlx_load_png("./texb/three.png");
	tex->digit[4] = mlx_load_png("./texb/four.png");
	tex->digit[5] = mlx_load_png("./texb/five.png");
	tex->digit[6] = mlx_load_png("./texb/six.png");
	tex->digit[7] = mlx_load_png("./texb/seven.png");
	tex->digit[8] = mlx_load_png("./texb/eight.png");
	tex->digit[9] = mlx_load_png("./texb/nine.png");
	tex->pac_death[0] = mlx_load_png("./texb/pac_death_1.png");
	tex->pac_death[1] = mlx_load_png("./texb/pac_death_2.png");
	tex->pac_death[2] = mlx_load_png("./texb/pac_death_3.png");
	tex->pac_death[3] = mlx_load_png("./texb/pac_death_4.png");
	tex->pac_death[4] = mlx_load_png("./texb/pac_death_5.png");
	tex->pac_death[5] = mlx_load_png("./texb/pac_death_6.png");
	tex->pac_death[6] = mlx_load_png("./texb/pac_death_7.png");
	while (++i < 10)
		img->digit[i] = mlx_texture_to_image(mlx, tex->digit[i]);
	i = -1;
	while (++i < 7)
		img->pac_death[i] = mlx_texture_to_image(mlx, tex->pac_death[i]);
}

void	ft_textures_player(mlx_t *mlx, t_textures *tex, t_image *img)
{
	int	i;

	i = -1;
	tex->player[0] = mlx_load_png("./text/pac_man.png");
	tex->player[1] = mlx_load_png("./text/pac_up.png");
	tex->player[2] = mlx_load_png("./text/pac_down.png");
	tex->player[3] = mlx_load_png("./text/pac_left.png");
	tex->player[4] = mlx_load_png("./text/pac_right.png");
	tex->pac_frame[0] = mlx_load_png("./texb/pac_up_2.png");
	tex->pac_frame[1] = mlx_load_png("./texb/pac_up_3.png");
	tex->pac_frame[2] = mlx_load_png("./texb/pac_up_4.png");
	tex->pac_frame[3] = mlx_load_png("./texb/pac_down_2.png");
	tex->pac_frame[4] = mlx_load_png("./texb/pac_down_3.png");
	tex->pac_frame[5] = mlx_load_png("./texb/pac_down_4.png");
	tex->pac_frame[6] = mlx_load_png("./texb/pac_left_2.png");
	tex->pac_frame[7] = mlx_load_png("./texb/pac_left_3.png");
	tex->pac_frame[8] = mlx_load_png("./texb/pac_left_4.png");
	tex->pac_frame[9] = mlx_load_png("./texb/pac_right_2.png");
	tex->pac_frame[10] = mlx_load_png("./texb/pac_right_3.png");
	tex->pac_frame[11] = mlx_load_png("./texb/pac_right_4.png");
	while (++i < 5)
		img->player[i] = mlx_texture_to_image(mlx, tex->player[i]);
	i = -1;
	while (++i < 12)
		img->pac_frame[i] = mlx_texture_to_image(mlx, tex->pac_frame[i]);
}
