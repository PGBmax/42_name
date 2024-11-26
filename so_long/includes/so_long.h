/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:06:39 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/26 17:08:22 by pboucher         ###   ########.fr       */
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
#define WIDTH 1920
#define HEIGHT 1080
#define SIZE 32

typedef struct	s_game
{
	mlx_texture_t	*walls;
	mlx_texture_t	*ground;
	mlx_texture_t	*player;
	mlx_texture_t	*collec;
	mlx_texture_t	*exit;

	mlx_image_t		*image;

	int x;
	int y;
}	t_game;

void ft_create_map(mlx_t *mlx, char *str, t_game game);

#endif