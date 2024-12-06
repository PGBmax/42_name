/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:06:39 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/06 15:58:05 by pboucher         ###   ########.fr       */
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
	mlx_texture_t	*single_wall;

	mlx_texture_t	*wall_v;
	mlx_texture_t	*wall_h;
	mlx_texture_t	*corner_1;
	mlx_texture_t	*corner_2;
	mlx_texture_t	*corner_3;
	mlx_texture_t	*corner_4;

	mlx_texture_t	*link_left;
	mlx_texture_t	*link_right;
	mlx_texture_t	*link_top;
	mlx_texture_t	*link_bottom;

	mlx_texture_t	*ground;
	mlx_texture_t	*player;

	mlx_texture_t	*player_u;
	mlx_texture_t	*player_d;
	mlx_texture_t	*player_l;
	mlx_texture_t	*player_r;
	
	mlx_texture_t	*collec;
	mlx_texture_t	*exit;
	mlx_texture_t 	*pac_man_exit1;
	mlx_texture_t 	*pac_man_exit2;
	mlx_texture_t 	*pac_man_exit3;
	mlx_texture_t 	*pac_man_exit4;
	mlx_texture_t 	*pac_man_exit5;
	
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
	mlx_image_t	*single_wall;

	mlx_image_t	*wall_v;
	mlx_image_t	*wall_h;
	mlx_image_t	*corner_1;
	mlx_image_t	*corner_2;
	mlx_image_t	*corner_3;
	mlx_image_t	*corner_4;

	mlx_image_t	*link_left;
	mlx_image_t	*link_right;
	mlx_image_t	*link_top;
	mlx_image_t	*link_bottom;

	mlx_image_t	*ground;
	mlx_image_t	*player;

	mlx_image_t	*player_u;
	mlx_image_t	*player_d;
	mlx_image_t	*player_l;
	mlx_image_t	*player_r;

	mlx_image_t	*collec;
	mlx_image_t	*exit;
	mlx_image_t *pac_man_exit1;
	mlx_image_t *pac_man_exit2;
	mlx_image_t *pac_man_exit3;
	mlx_image_t *pac_man_exit4;
	mlx_image_t *pac_man_exit5;
}	t_image;

typedef struct	s_game
{
	mlx_t			*mlx;
	t_textures		textures;
	t_image			image;
	char			**map;

	int x;
	int y;
	int max_x;
	int max_y;
	int player_x;
	int player_y;
	int exit_x;
	int exit_y;
	int nmb_exit;
	int nmb_player;

	int max_collec;
	int get_collec;
	int mooves;
	int victory;
}	t_game;

void		ft_know_size_map(t_game *game);
int			check_map(char *map);
mlx_image_t	*ft_check_walls(mlx_t *mlx, t_game game);
void	 	ft_show_map(mlx_t *mlx, t_game game, char c);
int			ft_error(int n);
void		ft_load_textures(mlx_t *mlx, t_game *game);
char		**ft_read_map(char *str);
int		ft_create_map(mlx_t *mlx, t_game game);
void		ft_link_walls(mlx_t *mlx, t_game game, int x, int y);
int			ft_pars_walls(t_game game);
int			ft_parsing(t_game game);

#endif