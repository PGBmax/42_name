/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:41:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/27 12:33:21 by pboucher         ###   ########.fr       */
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
	while (++j < i)
		true_map[j] = get_next_line(fd);
	true_map[j] = NULL;
	return (true_map);
}

void ft_create_map(mlx_t *mlx, t_game game)
{
	int	i;

	i = 0;
	while (game.map[i])
	{
		if (game.map[i][ft_strlen(game.map[i]) - 1] == '\n')
			game.map[i][ft_strlen(game.map[i]) - 1] = 0;
		i++;
	}
	game.x = 0;
	while (game.map[game.x])
	{
		game.y = 0;
		while (game.map[game.x][game.y])
		{
			ft_show_map(mlx, game, game.map[game.x][game.y]);
			game.y++;
		}
		game.x++;
	}
}
