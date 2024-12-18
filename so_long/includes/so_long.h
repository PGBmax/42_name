/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:06:39 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/18 16:07:39 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*	includes	*/
# include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "GNL/get_next_line.h"
#include "fcntl.h"
#include <signal.h>

/*	DONT TOUCH !!!	*/
#define SIZE 32

/*	DELAY OF FRAMES, YOU CANE MOVE IT BUT DONT WRITE 0 !	*/
#define FRAMEP 5
#define FRAMEG 8
#define FRAMEC 8

/*	MY TEXTURES	*/
typedef struct s_textures
{
	mlx_texture_t	*off_wall[4];
	mlx_texture_t	*off_corner[4];
	mlx_texture_t	*walls[3];
	mlx_texture_t	*corner[4];
	mlx_texture_t	*link[4];
	mlx_texture_t	*ground;
	mlx_texture_t	*fground;
	mlx_texture_t	*player[5];
	mlx_texture_t	*collec[4];
	mlx_texture_t	*exit;
	mlx_texture_t 	*pac_man_exit[5];
	mlx_texture_t	*pac_frame[12];
	mlx_texture_t	*clyde[7];
	mlx_texture_t	*inky[7];
	mlx_texture_t	*pinky[7];
	mlx_texture_t	*blinky[7];
	mlx_texture_t	*pac_death[7];
	mlx_texture_t	*digit[10];
	
}	t_textures;

/*	MY IMAGES	*/
typedef struct s_image
{
	mlx_image_t	*off_wall[4];
	mlx_image_t	*off_corner[4];
	mlx_image_t	*walls[3];
	mlx_image_t	*corner[4];
	mlx_image_t	*link[4];
	mlx_image_t	*ground;
	mlx_image_t	*fground;
	mlx_image_t	*player[5];
	mlx_image_t	*collec[4];
	mlx_image_t	*exit;
	mlx_image_t *pac_man_exit[5];
	mlx_image_t	*pac_frame[12];
	mlx_image_t	*clyde[7];
	mlx_image_t	*inky[7];
	mlx_image_t	*pinky[7];
	mlx_image_t	*blinky[7];
	mlx_image_t	*pac_death[7];

	mlx_image_t	*digit[10];
}	t_image;

/*	GAMES VALUES	*/
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
	int nmb_count;
	int nmb_ghost[4];
	int state;

	int clyde_x;
	int clyde_y;
	int blinky_x;
	int blinky_y;
	int inky_x;
	int inky_y;
	int pinky_x;
	int pinky_y;

	int in_move;
	int max_collec;
	int get_collec;
	int mooves;
	int victory;
}	t_game;

/*	temp.c*/
int		ft_error(int n);
void	ft_moves_blinky(t_game *game, int i);
void	ft_moves_clyde(t_game *game, int i);
void	ft_moves_pinky(t_game *game, int i);
void	ft_moves_inky(t_game *game, int i);
void	ft_frames_ghost(mlx_t *mlx, t_textures *tex, t_image *img);
void	ft_frames_mobs(t_game *game, int n);
void	frame_mobs(t_game *game);

/*	ft_check_map.c	*/
void	ft_check_case(t_game *game, char c);
void	ft_know_size_map(t_game *game);
int		check_map(char *map);
int		ft_pars_walls(t_game game);
void	fill(t_game *game, int row, int col, char **map);

/*	ft_load_textures.c	*/
void	ft_textures_ghost(mlx_t *mlx, t_textures *tex, t_image *img);
void	ft_textures_walls_1(mlx_t *mlx, t_textures *tex, t_image *img);
void	ft_textures_walls_2(mlx_t *mlx, t_textures *tex, t_image *img);
void	ft_textures_data(mlx_t *mlx, t_textures *tex, t_image *img);
void	ft_textures_player(mlx_t *mlx, t_textures *tex, t_image *img);

/*	ft_loops.c	*/
void ft_screen_victory(t_game *game);
void ft_screen_lose(t_game *game);

/*	ft_parsing.c	*/
int		ft_check_values(char c);
char	**fill_map(t_game game);
int		ft_somes_verifs(t_game game, char **map);
int		ft_parsing(t_game game);
void	ft_load_textures(mlx_t *mlx, t_textures *tex, t_image *img);

/*	ft_textures.c	*/
void	ft_frames_for_long(mlx_t *mlx, t_game game, mlx_image_t *img, int check);
void	ft_frames_of_ghosts(mlx_t *mlx, t_game game, t_image *img);
void	ft_frames_of_player(mlx_t *mlx, t_game game, t_image *img);
void	ft_show_map(mlx_t *mlx, t_game game, char c);

/*	ft_walls.c	*/
void	ft_block_walls_3(mlx_t *mlx, t_game game, int x, int y);
void	ft_block_walls_2(mlx_t *mlx, t_game game, int x, int y);
void	ft_block_walls(mlx_t *mlx, t_game game, int x, int y);
void	ft_link_walls(mlx_t *mlx, t_game game, int x, int y);
void	ft_show_walls(mlx_t *mlx, t_game game, int x, int y);

/*	map.c	*/
int		t_know_map(int fd);
char	**ft_read_map(char *str);
void	ft_display_number(mlx_t *mlx, t_game game, int i, t_image img);
char	**remove_return_line(char **map);
int		ft_create_map(mlx_t *mlx, t_game game);
#endif