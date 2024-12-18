/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:41:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/18 17:36:27 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_know_map(int fd)
{
	char	*map;
	int		i;

	i = 0;
	map = get_next_line(fd);
	while (map)
	{
		i++;
		free(map);
		map = get_next_line(fd);
	}
	free(map);
	return (i);
}

char	**ft_read_map(char *str)
{
	char			**true_map;
	int				fd;
	int				i;
	int				j;

	i = 0;
	j = 0;
	fd = open(str, O_RDONLY);
	i = ft_know_map(fd);
	close(fd);
	fd = open(str, O_RDONLY);
	true_map = malloc((i + 1) * sizeof(char *));
	if (!true_map)
		return (NULL);
	true_map[j] = get_next_line(fd);
	while (++j < i)
		true_map[j] = get_next_line(fd);
	true_map[j] = NULL;
	return (true_map);
}

void	ft_display_number(mlx_t *mlx, t_game game, int i, t_image img)
{
	mlx_image_to_window(mlx, img.digit[1], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[2], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[3], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[4], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[5], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[6], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[7], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[8], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[9], game.y * SIZE, game.x * SIZE);
	mlx_image_to_window(mlx, img.digit[0], game.y * SIZE, game.x * SIZE);
	img.digit[1]->instances[i].enabled = 0;
	img.digit[2]->instances[i].enabled = 0;
	img.digit[3]->instances[i].enabled = 0;
	img.digit[4]->instances[i].enabled = 0;
	img.digit[5]->instances[i].enabled = 0;
	img.digit[6]->instances[i].enabled = 0;
	img.digit[7]->instances[i].enabled = 0;
	img.digit[8]->instances[i].enabled = 0;
	img.digit[9]->instances[i].enabled = 0;
}

char	**remove_return_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = 0;
		if (i > 0 && ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			return (0);
		i++;
	}
	return (map);
}

int	ft_create_map(mlx_t *mlx, t_game game)
{
	int	i;

	game.map = remove_return_line(game.map);
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
				ft_display_number(mlx, game, i, game.image);
				i++;
			}
			game.y++;
		}
		game.x++;
	}
	ft_frames_of_ghosts(mlx, game, &game.image);
	ft_frames_of_player(mlx, game, &game.image);
	return (i);
}
