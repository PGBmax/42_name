/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:04:03 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/19 14:30:07 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void free_textures2(t_textures *tex)
{
	int i;

	i = -1;
	while (++i < 7)
	{
		mlx_delete_texture(tex->clyde[i]);
		mlx_delete_texture(tex->blinky[i]);
		mlx_delete_texture(tex->pinky[i]);
		mlx_delete_texture(tex->inky[i]);
		mlx_delete_texture(tex->pac_death[i]);
	}
	i = -1;
	while (++i < 10)
		mlx_delete_texture(tex->digit[i]);
	i = -1;
	while (++i < 12)
		mlx_delete_texture(tex->pac_frame[i]);
}

void free_textures(t_textures *tex)
{
	int i;

	i = -1;
	mlx_delete_texture(tex->ground);
	mlx_delete_texture(tex->fground);
	mlx_delete_texture(tex->exit);
	mlx_delete_texture(tex->walls[0]);
	mlx_delete_texture(tex->walls[1]);
	mlx_delete_texture(tex->walls[2]);
	while (++i < 4)
	{
		mlx_delete_texture(tex->off_wall[i]);
		mlx_delete_texture(tex->off_corner[i]);
		mlx_delete_texture(tex->corner[i]);
		mlx_delete_texture(tex->link[i]);
		mlx_delete_texture(tex->collec[i]);
	}
	i = -1;
	while (++i < 5)
	{
		mlx_delete_texture(tex->player[i]);
		mlx_delete_texture(tex->pac_man_exit[i]);
	}
	free_textures2(tex);
}

void free_map(char **map)
{
	int i;
	
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map[i]);
	free(map);
}

void free_all(t_game *game)
{
	free_textures(&game->textures);
	free_map(game->map);
	game->nmb_ghost[0] = 0;
	game->nmb_ghost[1] = 0;
	game->nmb_ghost[2] = 0;
	game->nmb_ghost[3] = 0;
}