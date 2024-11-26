/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:57:50 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/26 18:16:07 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int check_map(char *map)
{
	int i;
	int j;
	char *check;

	i = ft_strlen(map) - 1;
	check = ".ber";
	j = ft_strlen(check) - 1;
	while (map[i] == check[j])
	{
		i--;
		j--;
	}
	if (j < 0)
		return (1);
	else
		return (0);
}

int ft_error(int n)
{
	if (n == 1)
		printf("Error!\nCorrect Usage : ./so_long <map.ber>\n");
	if (n == 2)
		printf("Error!\nWrong name for map! Must be a .ber\n");
	if (n == 3)
		printf("Error!\nThis file doesn't exist.\n");
	return (0);
}

void	ft_load_textures(t_game *game)
{
	game->walls = mlx_load_png("./textures/walls.png");
	game->ground = mlx_load_png("./textures/ground.png");
	game->exit = mlx_load_png("./textures/exit.png");
	game->player = mlx_load_png("./textures/pac_man.png");
	game->collec = mlx_load_png("./textures/ghost.png");
}

int main(int ac, char **av)
{
    mlx_t			*mlx;
	t_game			game;

	if (ac != 2)
		return (ft_error(1));
	if (!check_map(av[1]))
		return (ft_error(2));
	if (!open(av[1], O_RDONLY))
		return (ft_error(3));
	ft_load_textures(&game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(WIDTH, HEIGHT, "Pac Man", true);
	ft_create_map(mlx, av[1], game);
	mlx_loop(mlx);
}
