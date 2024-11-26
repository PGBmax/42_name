/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:41:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/26 18:10:07 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char **ft_read_map(char *str)
{
	char			**true_map;
	char			*map;
	int				fd;
	int				i;
	int				j;

	i = 0;
	j = 0;
	fd = open(str, O_RDONLY);
	map = get_next_line(fd);
	while (map)
	{
		i++;
		free(map);
		map = get_next_line(fd);
	}
	free(map);
	close(fd);
	fd = open(str, O_RDONLY);
	true_map = ft_calloc(i + 1, sizeof(char *));
	true_map[j] = get_next_line(fd);
	while (j < i)
	{
		j++;
		true_map[j] = get_next_line(fd);
	}
	true_map[j] = NULL;
	return (true_map);
}

void ft_show_map(mlx_t *mlx, t_game game, char c)
{
	mlx_image_t		*image;
	
	if (c == '1')
		image = mlx_texture_to_image(mlx, game.walls);
	if (c == '0')
		image = mlx_texture_to_image(mlx, game.ground);
	if (c == 'E')
		image = mlx_texture_to_image(mlx, game.exit);
	if (c == 'P')
		image = mlx_texture_to_image(mlx, game.player);
	if (c == 'C')
		image = mlx_texture_to_image(mlx, game.collec);
	mlx_image_to_window(mlx, image, game.y * SIZE, game.x * SIZE);
}
void ft_create_map(mlx_t *mlx, char *str, t_game game)
{
	char			**map;

	int i = 0;
	map = ft_read_map(str);
	while (map[i])
	{
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = 0;
		i++;
	}
	game.x = 0;
	while (map[game.x])
	{
		game.y = 0;
		while (map[game.x][game.y])
		{
			ft_show_map(mlx, game, map[game.x][game.y]);
			game.y++;
		}
		game.x++;
	}
}
