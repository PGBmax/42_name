/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:04:03 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/18 17:32:33 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void free_textures2(t_textures *tex)
{
	int i;

	i = -1;
	while (++i < 7)
	{
		free(tex->clyde[i]);
		free(tex->blinky[i]);
		free(tex->pinky[i]);
		free(tex->inky[i]);
		free(tex->pac_death[i]);
	}
	i = -1;
	while (++i < 10)
		free(tex->digit[i]);
	i = -1;
	while (++i < 12)
		free(tex->pac_frame[i]);
}

void free_textures(t_textures *tex)
{
	int i;

	i = -1;
	free(tex->ground);
	free(tex->fground);
	free(tex->exit);
	free(tex->walls[0]);
	free(tex->walls[1]);
	free(tex->walls[2]);
	while (++i < 4)
	{
		free(tex->off_wall[i]);
		free(tex->off_corner[i]);
		free(tex->corner[i]);
		free(tex->link[i]);
		free(tex->collec[i]);
	}
	i = -1;
	while (++i < 5)
	{
		free(tex->player[i]);
		free(tex->pac_man_exit[i]);
	}
	free_textures2(tex);
}

void free_map(char **map)
{
	int i;
	
	i = 0;
	while (map[++i])
		free(map[i]);
	free(map[i]);
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