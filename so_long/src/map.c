/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:41:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/13 18:06:37 by pboucher         ###   ########.fr       */
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
	if (!true_map)
		return (NULL);
	true_map[j] = get_next_line(fd);
	while (++j < i)
		true_map[j] = get_next_line(fd);
	true_map[j] = NULL;
	return (true_map);
}

void ft_display_number(mlx_t *mlx, t_game game, int i)
{
	mlx_image_to_window(mlx, game.image.digit[1], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, game.image.digit[2], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, game.image.digit[3], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, game.image.digit[4], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, game.image.digit[5], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, game.image.digit[6], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, game.image.digit[7], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, game.image.digit[8], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, game.image.digit[9], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, game.image.digit[0], game.y * SIZE, game.x * SIZE);
	game.image.digit[1]->instances[i].enabled = 0;
	game.image.digit[2]->instances[i].enabled = 0;
	game.image.digit[3]->instances[i].enabled = 0;
	game.image.digit[4]->instances[i].enabled = 0;
	game.image.digit[5]->instances[i].enabled = 0;
	game.image.digit[6]->instances[i].enabled = 0;
	game.image.digit[7]->instances[i].enabled = 0;
	game.image.digit[8]->instances[i].enabled = 0;
	game.image.digit[9]->instances[i].enabled = 0;
}


int ft_create_map(mlx_t *mlx, t_game game)
{
	int	i;

	i = 0;
	while (game.map[i])
	{
		if (game.map[i][ft_strlen(game.map[i]) - 1] == '\n')
			game.map[i][ft_strlen(game.map[i]) - 1] = 0;
		if (i > 0 && ft_strlen(game.map[i]) != ft_strlen(game.map[i - 1]))
			return (0);
		i++;
	}
	i = 0;
	game.x = 0;
	while (game.map[game.x])
	{
		game.y = 0;
		while (game.map[game.x][game.y])
		{
			ft_show_map(mlx, game, game.map[game.x][game.y]);
			if (game.x == 0 && game.y != 0 && game.y != game.max_x && i < 5)
			{
				ft_display_number(mlx, game, i);
				i++;
			}
			game.y++;
		}
		game.x++;
	}
	ft_frames_of_ghosts(mlx, game);
	ft_frames_of_player(mlx, game);
	return (i);
}
