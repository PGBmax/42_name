/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:06:39 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/27 18:02:28 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "GNL/get_next_line.h"
#include "fcntl.h"
#define SIZE 32

typedef struct s_textures
{
	mlx_texture_t	*wall_left;
	mlx_texture_t	*wall_right;
	mlx_texture_t	*wall_top;
	mlx_texture_t	*wall_bottom;
	mlx_texture_t	*corner_bottom_left;
	mlx_texture_t	*corner_bottom_right;
	mlx_texture_t	*corner_top_left;
	mlx_texture_t	*corner_top_right;

	mlx_texture_t	*block_wall_left;
	mlx_texture_t	*block_wall_right;
	mlx_texture_t	*block_wall_top;
	mlx_texture_t	*block_wall_bottom;
	mlx_texture_t	*block_corner_bottom_left;
	mlx_texture_t	*block_corner_bottom_right;
	mlx_texture_t	*block_corner_top_left;
	mlx_texture_t	*block_corner_top_right;

	mlx_texture_t	*ground;
	mlx_texture_t	*player;
	mlx_texture_t	*collec;
	mlx_texture_t	*exit;
	
}	t_textures;

typedef struct s_image
{
	mlx_image_t	*wall_left;
	mlx_image_t	*wall_right;
	mlx_image_t	*wall_top;
	mlx_image_t	*wall_bottom;
	mlx_image_t	*corner_bottom_left;
	mlx_image_t	*corner_bottom_right;
	mlx_image_t	*corner_top_left;
	mlx_image_t	*corner_top_right;

	mlx_image_t	*block_wall_left;
	mlx_image_t	*block_wall_right;
	mlx_image_t	*block_wall_top;
	mlx_image_t	*block_wall_bottom;
	mlx_image_t	*block_corner_bottom_left;
	mlx_image_t	*block_corner_bottom_right;
	mlx_image_t	*block_corner_top_left;
	mlx_image_t	*block_corner_top_right;

	mlx_image_t	*ground;
	mlx_image_t	*player;
	mlx_image_t	*collec;
	mlx_image_t	*exit;
}	t_image;

typedef struct	s_game
{
	t_textures		textures;
	t_image			image;
	char			**map;

	int x;
	int y;
	int max_x;
	int max_y;
}	t_game;

void		ft_know_size_map(t_game *game);
int			check_map(char *map);
mlx_image_t	*ft_check_walls(mlx_t *mlx, t_game game);
void	 	ft_show_map(mlx_t *mlx, t_game game, char c);
int			ft_error(int n);
void		ft_load_textures(mlx_t *mlx, t_game *game);
char		**ft_read_map(char *str);
void		ft_create_map(mlx_t *mlx, t_game game);

#endif