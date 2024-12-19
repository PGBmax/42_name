/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:41:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/19 18:07:28 by pboucher         ###   ########.fr       */
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

void	ft_read_map(t_game *game, char *str)
{
	int				fd;
	int				i;
	int				j;

	i = 0;
	j = 0;
	fd = open(str, O_RDONLY);
	i = ft_know_map(fd);
	close(fd);
	fd = open(str, O_RDONLY);
	game->map = ft_calloc(i + 1, sizeof(char *));
	if (!game->map)
		return ;
	game->map[j] = get_next_line(fd);
	while (++j < i)
		game->map[j] = get_next_line(fd);
	game->map[j] = NULL;
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

int	remove_return_line(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
			game->map[i][ft_strlen(game->map[i]) - 1] = 0;
		if (i > 0 && ft_strlen(game->map[i]) != ft_strlen(game->map[i - 1]))
			return (ft_error(9));
		i++;
	}
	return (1);
}

int check_off_walls(char **map,	int x,	int y)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (map[0][++j])
	{
		if (map[0][j] != '1')
			return (ft_error(4));
	}
	j = -1;
	while (map[y][++j])
	{
		if (map[y][j] != '1')
			return (ft_error(4));
	}
	j = -1;
	while (++i < y)
	{
		if (map[i][0] != '1' || map[i][x] != '1')
			return (ft_error(4));
	}
	return (1);
}


int	ft_create_map(mlx_t *mlx, t_game *game)
{
	int	i;

	if (!remove_return_line(game) ||
		!check_off_walls(game->map, game->max_x, game->max_y))
		return (0);
	i = 0;
	game->x = 0;
	while (game->map[game->x])
	{
		game->y = 0;
		while (game->map[game->x][game->y])
		{
			ft_show_map(mlx, *game, game->map[game->x][game->y]);
			if (game->x == 0 && game->y != 0 && game->y != game->max_x && i < 5)
			{
				ft_display_number(mlx, *game, i, game->image);
				i++;
			}
			game->y++;
		}
		game->x++;
	}
	ft_frames_of_ghosts(mlx, *game, &game->image);
	ft_frames_of_player(mlx, *game, &game->image);
	return (i);
}
