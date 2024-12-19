/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:28:48 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/19 17:55:26 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_check_values(char c)
{
	if (c != '0' && c != '1'
		&& c != 'P' && c != 'E'
		&& c != 'C' && c != 'K'
		&& c != 'O' && c != 'R' && c != 'B')
		return (0);
	return (1);
}

char	**fill_map(t_game game)
{
	char	**map;
	int		x;
	int		y;

	x = -1;
	map = ft_calloc(sizeof(char *), game.max_y + 2);
	map[game.max_y + 1] = NULL;
	while (++x <= game.max_y)
	{
		map[x] = ft_calloc(game.max_x + 2, 1);
		if (!map[x])
			return (NULL);
		y = -1;
		while (++y <= game.max_x)
		{
			map[x][y] = game.map[x][y];
			if (!ft_check_values(map[x][y]))
			{
				ft_error(11);
				return (NULL);
			}
		}
		map[x][y] = 0;
	}
	return (map);
}

int	ft_somes_verifs(t_game game, char **map)
{
	if (!map)
		return (0);
	if (game.nmb_player != 1)
		return (ft_error(10));
	if (game.nmb_exit != 1)
		return (ft_error(5));
	if (game.nmb_ghost[0] > 1)
		return (ft_error(13));
	if (game.nmb_ghost[1] > 1)
		return (ft_error(14));
	if (game.nmb_ghost[2] > 1)
		return (ft_error(15));
	if (game.nmb_ghost[3] > 1)
		return (ft_error(16));
	return (1);
}

int	ft_parsing(t_game game)
{
	int		x;
	int		y;
	char	**map;

	if (game.max_collec == 0)
		return (ft_error(8));
	if (!ft_somes_verifs(game, game.map))
		return (0);
	map = fill_map(game);
	fill(&game, game.player_y, game.player_x, map);
	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'C')
			{
				free_map(map);
				return (ft_error(6));
			}
			if (map[x][y] == 'E')
			{
				free_map(map);
				return (ft_error(7));
			}
		}
	}
	x = 0;
	while (map[x])
	{
		free(map[x]);
		x++;
	}
	free(map);
	return (1);
}

void	ft_load_textures(mlx_t *mlx, t_textures *tex, t_image *img)
{
	ft_textures_ghost(mlx, tex, img);
	ft_textures_walls_1(mlx, tex, img);
	ft_textures_walls_2(mlx, tex, img);
	ft_textures_data(mlx, tex, img);
	ft_textures_player(mlx, tex, img);
	ft_frames_ghost(mlx, tex, img);
	tex->collec[0] = mlx_load_png("./text/collec.png");
	tex->collec[1] = mlx_load_png("./texb/collec_2.png");
	tex->collec[2] = mlx_load_png("./texb/collec_3.png");
	tex->collec[3] = mlx_load_png("./texb/collec_4.png");
	img->collec[0] = mlx_texture_to_image(mlx, tex->collec[0]);
	img->collec[1] = mlx_texture_to_image(mlx, tex->collec[1]);
	img->collec[2] = mlx_texture_to_image(mlx, tex->collec[2]);
	img->collec[3] = mlx_texture_to_image(mlx, tex->collec[3]);
	tex->ground = mlx_load_png("./text/ground.png");
	img->ground = mlx_texture_to_image(mlx, tex->ground);
	tex->fground = mlx_load_png("./texb/fake_ground.png");
	img->fground = mlx_texture_to_image(mlx, tex->fground);
	tex->exit = mlx_load_png("./text/exit.png");
	img->exit = mlx_texture_to_image(mlx, tex->exit);
}
