/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:57:50 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/06 16:41:37 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int ft_error(int n)
{
	printf("\n\e[91mError!\n");
	if (n == 1)
		printf("Correct Usage : ./so_long <map.ber>\n\n\e[97m");
	if (n == 2)
		printf("Wrong name for map! Must be a .ber\n\n\e[97m");
	if (n == 3)
		printf("This file doesn't exist.\n\n\e[97m");
	if (n == 4)
		printf("Sides of the map must be walls!\n\n\e[97m");
	if (n == 5)
		printf("Only one exit required!\n\n\e[97m");
	if (n == 6)
		printf("At least 1 collectible is inaccessible!\n\n\e[97m");
	if (n == 7)
		printf("The exit is inaccessible!\n\n\e[97m");
	if (n == 8)
		printf("At least 1 collectible is required!\n\n\e[97m");
	if (n == 9)
		printf("The map should be rectangular!\n\n\e[97m");
	if (n == 10)
		printf("Just one player is needed!\n\n\e[97m");
	if (n == 11)
		printf("A texture is not recognized!\n\n\e[97m");
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

	game->textures.pac_man_exit1 = mlx_load_png("./textures/pac_man_exit1.png");
	game->textures.pac_man_exit2 = mlx_load_png("./textures/pac_man_exit2.png");
	game->textures.pac_man_exit3 = mlx_load_png("./textures/pac_man_exit3.png");
	game->textures.pac_man_exit4 = mlx_load_png("./textures/pac_man_exit4.png");
	game->textures.pac_man_exit5 = mlx_load_png("./textures/pac_man_exit5.png");

	game->textures.player_u = mlx_load_png("./textures/pac_up.png");
	game->textures.player_d = mlx_load_png("./textures/pac_down.png");
	game->textures.player_l = mlx_load_png("./textures/pac_left.png");
	game->textures.player_r = mlx_load_png("./textures/pac_right.png");
	game->textures.collec = mlx_load_png("./textures/collec.png");
	game->textures.single_wall = mlx_load_png("./textures/single_wall.png");

	game->textures.wall_h = mlx_load_png("./textures/wall_h.png");
	game->textures.wall_v = mlx_load_png("./textures/wall_v.png");
	game->textures.corner_1 = mlx_load_png("./textures/corner_1.png");
	game->textures.corner_2 = mlx_load_png("./textures/corner_2.png");
	game->textures.corner_3 = mlx_load_png("./textures/corner_3.png");
	game->textures.corner_4 = mlx_load_png("./textures/corner_4.png");

	game->textures.link_left = mlx_load_png("./textures/link_walls_left.png");
	game->textures.link_right = mlx_load_png("./textures/link_walls_right.png");
	game->textures.link_top = mlx_load_png("./textures/link_walls_top.png");
	game->textures.link_bottom = mlx_load_png("./textures/link_walls_bottom.png");

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

	game->image.pac_man_exit1 = mlx_texture_to_image(mlx, game->textures.pac_man_exit1);
	game->image.pac_man_exit2 = mlx_texture_to_image(mlx, game->textures.pac_man_exit2);
	game->image.pac_man_exit3 = mlx_texture_to_image(mlx, game->textures.pac_man_exit3);
	game->image.pac_man_exit4 = mlx_texture_to_image(mlx, game->textures.pac_man_exit4);
	game->image.pac_man_exit5 = mlx_texture_to_image(mlx, game->textures.pac_man_exit5);

	game->image.player_u = mlx_texture_to_image(mlx, game->textures.player_u);
	game->image.player_d = mlx_texture_to_image(mlx, game->textures.player_d);
	game->image.player_l = mlx_texture_to_image(mlx, game->textures.player_l);
	game->image.player_r = mlx_texture_to_image(mlx, game->textures.player_r);
	game->image.collec = mlx_texture_to_image(mlx, game->textures.collec);
	game->image.single_wall = mlx_texture_to_image(mlx, game->textures.single_wall);

	game->image.wall_v = mlx_texture_to_image(mlx, game->textures.wall_v);
	game->image.wall_h = mlx_texture_to_image(mlx, game->textures.wall_h);
	game->image.corner_1 = mlx_texture_to_image(mlx, game->textures.corner_1);
	game->image.corner_2 = mlx_texture_to_image(mlx, game->textures.corner_2);
	game->image.corner_3 = mlx_texture_to_image(mlx, game->textures.corner_3);
	game->image.corner_4 = mlx_texture_to_image(mlx, game->textures.corner_4);

	game->image.link_left = mlx_texture_to_image(mlx, game->textures.link_left);
	game->image.link_right = mlx_texture_to_image(mlx, game->textures.link_right);
	game->image.link_top = mlx_texture_to_image(mlx, game->textures.link_top);
	game->image.link_bottom = mlx_texture_to_image(mlx, game->textures.link_bottom);
}

void ft_screen_victory(t_game *game)
{
	static int count = 0;

	if (game->victory != 1)
		return ;
	if (count == 0)
		mlx_image_to_window(game->mlx, game->image.player, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == 5)
		mlx_image_to_window(game->mlx, game->image.pac_man_exit1, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == 10)
		mlx_image_to_window(game->mlx, game->image.pac_man_exit2, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == 15)
		mlx_image_to_window(game->mlx, game->image.pac_man_exit3, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == 20)
		mlx_image_to_window(game->mlx, game->image.pac_man_exit4, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == 25)
		mlx_image_to_window(game->mlx, game->image.pac_man_exit5, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == 30)
		mlx_image_to_window(game->mlx, game->image.exit, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == 50)
	{
		mlx_close_window(game->mlx);
		free(game->map);
		printf("\n\e[92mGood Job! 🎉\nYou won with %d mooves! 🥳\n\n\e[97m", game->mooves);
	}
	count++;
}


void	ft_move_pac_man(t_game *game, int o, char c)
{
	mlx_image_to_window(game->mlx, game->image.ground, game->player_y * SIZE, game->player_x * SIZE);
	if (c == 'u' || c == 'd')
		game->player_x = game->player_x + o;
	else
		game->player_y = game->player_y + o;
	if (c == 'u')
		mlx_image_to_window(game->mlx, game->image.player_u, game->player_y * SIZE, game->player_x * SIZE);
	else if (c == 'd')
		mlx_image_to_window(game->mlx, game->image.player_d, game->player_y * SIZE, game->player_x * SIZE);
	else if (c == 'l')
		mlx_image_to_window(game->mlx, game->image.player_l, game->player_y * SIZE, game->player_x * SIZE);
	else if (c == 'r')
		mlx_image_to_window(game->mlx, game->image.player_r, game->player_y * SIZE, game->player_x * SIZE);
	game->mooves++;
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->get_collec++;
		if (game->get_collec == game->max_collec)
			mlx_image_to_window(game->mlx, game->image.exit, game->exit_y * SIZE, game->exit_x * SIZE);
	}
	if (game->map[game->player_x][game->player_y] == 'E' && game->get_collec == game->max_collec)
		game->victory = 1;
}

void	ft_hook(mlx_key_data_t key_data,t_game *game)
{
	if ((key_data.action != MLX_PRESS || game->victory == 1) && key_data.key != MLX_KEY_ESCAPE)
		return ;
	else if (key_data.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(game->mlx);
		if (game->victory == 1)
			printf("\n\e[93mPac Man just gave up about winning. 💀\n\n\e[97m");
		else
			printf("\n\e[91mPac Man just got deleted from the existence. 😔\n\n\e[97m");
	}
	else if (key_data.key == MLX_KEY_UP && game->map[game->player_x - 1][game->player_y] != '1')
		ft_move_pac_man(game, -1, 'u');
	else if (key_data.key == MLX_KEY_DOWN && game->map[game->player_x + 1][game->player_y] != '1')
		ft_move_pac_man(game, 1, 'd');
	else if (key_data.key == MLX_KEY_LEFT && game->map[game->player_x][game->player_y - 1] != '1')
		ft_move_pac_man(game, -1, 'l');
	else if (key_data.key == MLX_KEY_RIGHT && game->map[game->player_x][game->player_y + 1] != '1')
		ft_move_pac_man(game, 1, 'r');
	else if (key_data.key == MLX_KEY_UP && game->map[game->player_x - 1][game->player_y] == '1')
		mlx_image_to_window(game->mlx, game->image.player_u, game->player_y * SIZE, game->player_x * SIZE);
	else if (key_data.key == MLX_KEY_DOWN && game->map[game->player_x + 1][game->player_y] == '1')
		mlx_image_to_window(game->mlx, game->image.player_d, game->player_y * SIZE, game->player_x * SIZE);
	else if (key_data.key == MLX_KEY_LEFT && game->map[game->player_x][game->player_y - 1] == '1')
		mlx_image_to_window(game->mlx, game->image.player_l, game->player_y * SIZE, game->player_x * SIZE);
	else if (key_data.key == MLX_KEY_RIGHT && game->map[game->player_x][game->player_y + 1] == '1')
		mlx_image_to_window(game->mlx, game->image.player_r, game->player_y * SIZE, game->player_x * SIZE);
}

void init_game_values(t_game *game)
{
	game->mooves = 0;
	game->get_collec = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->nmb_exit = 0;
	game->nmb_player = 0;
	game->victory = 0;
}

int main(int ac, char **av)
{
	t_game			game;

	if (ac != 2)
		return (ft_error(1));
	if (!check_map(av[1]))
		return (ft_error(2));
	if (!open(av[1], O_RDONLY) || open(av[1], O_RDONLY) == -1)
		return (ft_error(3));
	game.map = ft_read_map(av[1]);
	init_game_values(&game);
	ft_know_size_map(&game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game.mlx = mlx_init(game.y * SIZE, game.x * SIZE, "Pac Man", true);
	ft_load_textures(game.mlx, &game);
	if (!ft_create_map(game.mlx, game))
		return (ft_error(9));
	if (!ft_parsing(game))
		return (0);
	mlx_key_hook(game.mlx, (void (*))ft_hook, (void *)&game);
	mlx_loop_hook(game.mlx, (void (*))ft_screen_victory, (void *)&game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
