/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:06:39 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/15 00:11:01 by pboucher         ###   ########.fr       */
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
#define FRAMEP 6
#define FRAMEC 10

typedef struct s_textures
{
	mlx_texture_t	*off_wall[4];
	mlx_texture_t	*off_corner[4];
	mlx_texture_t	*walls[3];
	mlx_texture_t	*corner[4];
	mlx_texture_t	*link[4];
	mlx_texture_t	*ground;
	mlx_texture_t	*fake_ground;
	mlx_texture_t	*player[5];
	mlx_texture_t	*collec[4];
	mlx_texture_t	*exit;
	mlx_texture_t 	*pac_man_exit[5];
	mlx_texture_t	*pac_frame[12];
	mlx_texture_t	*clyde[4];
	mlx_texture_t	*inky[4];
	mlx_texture_t	*pinky[4];
	mlx_texture_t	*blinky[4];
	mlx_texture_t	*pac_death[7];
	mlx_texture_t	*digit[10];
	
}	t_textures;

typedef struct s_image
{
	mlx_image_t	*off_wall[4];
	mlx_image_t	*off_corner[4];
	mlx_image_t	*walls[3];
	mlx_image_t	*corner[4];
	mlx_image_t	*link[4];
	mlx_image_t	*ground;
	mlx_image_t	*fake_ground;
	mlx_image_t	*player[5];
	mlx_image_t	*collec[4];
	mlx_image_t	*exit;
	mlx_image_t *pac_man_exit[5];
	mlx_image_t	*pac_frame[12];
	mlx_image_t	*clyde[4];
	mlx_image_t	*inky[4];
	mlx_image_t	*pinky[4];
	mlx_image_t	*blinky[4];
	mlx_image_t	*pac_death[7];

	mlx_image_t	*digit[10];
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
	int state;

	int clyde_x;
	int clyde_y;
	int blinky_x;
	int blinky_y;
	int inky_x;
	int inky_y;
	int pinky_x;
	int pinky_y;

	int max_collec;
	int get_collec;
	int nmb_count;
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
int			ft_create_map(mlx_t *mlx, t_game game);
void		ft_link_walls(mlx_t *mlx, t_game game, int x, int y);
int			ft_pars_walls(t_game game);
int			ft_parsing(t_game game);
void		ft_frames_of_player(mlx_t *mlx, t_game game);
void		ft_frames_of_ghosts(mlx_t *mlx, t_game game);

#endif