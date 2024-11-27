/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:57:50 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/27 18:46:06 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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

void	ft_load_textures(mlx_t *mlx, t_game *game)
{
	game->textures.wall_left = mlx_load_png("./textures/walls_left.png");
	game->textures.wall_right = mlx_load_png("./textures/walls_right.png");
	game->textures.wall_top = mlx_load_png("./textures/walls_top.png");
	game->textures.wall_bottom = mlx_load_png("./textures/walls_bottom.png");
	game->textures.corner_bottom_left = mlx_load_png("./textures/corner_bottom_left.png");
	game->textures.corner_bottom_right = mlx_load_png("./textures/corner_bottom_right.png");
	game->textures.corner_top_left = mlx_load_png("./textures/corner_top_left.png");
	game->textures.corner_top_right = mlx_load_png("./textures/corner_top_right.png");
	game->textures.ground = mlx_load_png("./textures/ground.png");
	game->textures.exit = mlx_load_png("./textures/exit.png");
	game->textures.player = mlx_load_png("./textures/pac_man.png");
	game->textures.collec = mlx_load_png("./textures/collec.png");

	game->textures.block_wall_left = mlx_load_png("./textures/block_wall_left.png");
	game->textures.block_wall_right = mlx_load_png("./textures/block_wall_right.png");
	game->textures.block_wall_top = mlx_load_png("./textures/block_wall_top.png");
	game->textures.block_wall_bottom = mlx_load_png("./textures/block_wall_bottom.png");
	game->textures.block_corner_bottom_left = mlx_load_png("./textures/block_corner_bottom_left.png");
	game->textures.block_corner_bottom_right = mlx_load_png("./textures/block_corner_bottom_right.png");
	game->textures.block_corner_top_left = mlx_load_png("./textures/block_corner_top_left.png");
	game->textures.block_corner_top_right = mlx_load_png("./textures/block_corner_top_right.png");

	game->image.wall_left = mlx_texture_to_image(mlx, game->textures.wall_left);
	game->image.wall_right = mlx_texture_to_image(mlx, game->textures.wall_right);
	game->image.wall_top = mlx_texture_to_image(mlx, game->textures.wall_top);
	game->image.wall_bottom = mlx_texture_to_image(mlx, game->textures.wall_bottom);
	game->image.corner_bottom_left = mlx_texture_to_image(mlx, game->textures.corner_bottom_left);
	game->image.corner_bottom_right = mlx_texture_to_image(mlx, game->textures.corner_bottom_right);
	game->image.corner_top_left = mlx_texture_to_image(mlx, game->textures.corner_top_left);
	game->image.corner_top_right = mlx_texture_to_image(mlx, game->textures.corner_top_right);
	game->image.ground = mlx_texture_to_image(mlx, game->textures.ground);
	game->image.exit = mlx_texture_to_image(mlx, game->textures.exit);
	game->image.player = mlx_texture_to_image(mlx, game->textures.player);
	game->image.collec = mlx_texture_to_image(mlx, game->textures.collec);

	game->image.block_wall_left = mlx_texture_to_image(mlx, game->textures.block_wall_left);
	game->image.block_wall_right = mlx_texture_to_image(mlx, game->textures.block_wall_right);
	game->image.block_wall_top = mlx_texture_to_image(mlx, game->textures.block_wall_top);
	game->image.block_wall_bottom = mlx_texture_to_image(mlx, game->textures.block_wall_bottom);
	game->image.block_corner_bottom_left = mlx_texture_to_image(mlx, game->textures.block_corner_bottom_left);
	game->image.block_corner_bottom_right = mlx_texture_to_image(mlx, game->textures.block_corner_bottom_right);
	game->image.block_corner_top_left = mlx_texture_to_image(mlx, game->textures.block_corner_top_left);
	game->image.block_corner_top_right = mlx_texture_to_image(mlx, game->textures.block_corner_top_right);
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
	game.map = ft_read_map(av[1]);
	ft_know_size_map(&game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(game.y * SIZE, game.x * SIZE, "Pac Man", true);
	ft_load_textures(mlx, &game);
	ft_create_map(mlx, game);
	mlx_loop(mlx);
}
