/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:57:50 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/12 14:30:02 by pboucher         ###   ########.fr       */
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
	game->textures.fake_ground = mlx_load_png("./tex_bonus/fake_ground.png");
	game->textures.exit = mlx_load_png("./textures/exit.png");
	game->textures.player = mlx_load_png("./textures/pac_man.png");

	game->textures.pac_man_exit1 = mlx_load_png("./textures/pac_man_exit1.png");
	game->textures.pac_man_exit2 = mlx_load_png("./textures/pac_man_exit2.png");
	game->textures.pac_man_exit3 = mlx_load_png("./textures/pac_man_exit3.png");
	game->textures.pac_man_exit4 = mlx_load_png("./textures/pac_man_exit4.png");
	game->textures.pac_man_exit5 = mlx_load_png("./textures/pac_man_exit5.png");

	game->textures.pac_up_frame2 = mlx_load_png("./tex_bonus/pac_up_2.png");
	game->textures.pac_up_frame3 = mlx_load_png("./tex_bonus/pac_up_3.png");
	game->textures.pac_up_frame4 = mlx_load_png("./tex_bonus/pac_up_4.png");
	
	game->textures.pac_down_frame2 = mlx_load_png("./tex_bonus/pac_down_2.png");
	game->textures.pac_down_frame3 = mlx_load_png("./tex_bonus/pac_down_3.png");
	game->textures.pac_down_frame4 = mlx_load_png("./tex_bonus/pac_down_4.png");
	
	game->textures.pac_left_frame2 = mlx_load_png("./tex_bonus/pac_left_2.png");
	game->textures.pac_left_frame3 = mlx_load_png("./tex_bonus/pac_left_3.png");
	game->textures.pac_left_frame4 = mlx_load_png("./tex_bonus/pac_left_4.png");
	
	game->textures.pac_right_frame2 = mlx_load_png("./tex_bonus/pac_right_2.png");
	game->textures.pac_right_frame3 = mlx_load_png("./tex_bonus/pac_right_3.png");
	game->textures.pac_right_frame4 = mlx_load_png("./tex_bonus/pac_right_4.png");

	game->textures.player_u = mlx_load_png("./textures/pac_up.png");
	game->textures.player_d = mlx_load_png("./textures/pac_down.png");
	game->textures.player_l = mlx_load_png("./textures/pac_left.png");
	game->textures.player_r = mlx_load_png("./textures/pac_right.png");
	game->textures.collec = mlx_load_png("./textures/collec.png");
	game->textures.collec_2 = mlx_load_png("./tex_bonus/collec_2.png");
	game->textures.collec_3 = mlx_load_png("./tex_bonus/collec_3.png");
	game->textures.collec_4 = mlx_load_png("./tex_bonus/collec_4.png");
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
	game->image.fake_ground = mlx_texture_to_image(mlx, game->textures.fake_ground);
	game->image.exit = mlx_texture_to_image(mlx, game->textures.exit);
	game->image.player = mlx_texture_to_image(mlx, game->textures.player);

	game->image.pac_man_exit1 = mlx_texture_to_image(mlx, game->textures.pac_man_exit1);
	game->image.pac_man_exit2 = mlx_texture_to_image(mlx, game->textures.pac_man_exit2);
	game->image.pac_man_exit3 = mlx_texture_to_image(mlx, game->textures.pac_man_exit3);
	game->image.pac_man_exit4 = mlx_texture_to_image(mlx, game->textures.pac_man_exit4);
	game->image.pac_man_exit5 = mlx_texture_to_image(mlx, game->textures.pac_man_exit5);

	game->image.pac_up_frame2 = mlx_texture_to_image(mlx, game->textures.pac_up_frame2);
	game->image.pac_up_frame3 = mlx_texture_to_image(mlx, game->textures.pac_up_frame3);
	game->image.pac_up_frame4 = mlx_texture_to_image(mlx, game->textures.pac_up_frame4);

	game->image.pac_down_frame2 = mlx_texture_to_image(mlx, game->textures.pac_down_frame2);
	game->image.pac_down_frame3 = mlx_texture_to_image(mlx, game->textures.pac_down_frame3);
	game->image.pac_down_frame4 = mlx_texture_to_image(mlx, game->textures.pac_down_frame4);

	game->image.pac_left_frame2 = mlx_texture_to_image(mlx, game->textures.pac_left_frame2);
	game->image.pac_left_frame3 = mlx_texture_to_image(mlx, game->textures.pac_left_frame3);
	game->image.pac_left_frame4 = mlx_texture_to_image(mlx, game->textures.pac_left_frame4);

	game->image.pac_right_frame2 = mlx_texture_to_image(mlx, game->textures.pac_right_frame2);
	game->image.pac_right_frame3 = mlx_texture_to_image(mlx, game->textures.pac_right_frame3);
	game->image.pac_right_frame4 = mlx_texture_to_image(mlx, game->textures.pac_right_frame4);

	game->image.player_u = mlx_texture_to_image(mlx, game->textures.player_u);
	game->image.player_d = mlx_texture_to_image(mlx, game->textures.player_d);
	game->image.player_l = mlx_texture_to_image(mlx, game->textures.player_l);
	game->image.player_r = mlx_texture_to_image(mlx, game->textures.player_r);
	game->image.collec = mlx_texture_to_image(mlx, game->textures.collec);
	game->image.collec_2 = mlx_texture_to_image(mlx, game->textures.collec_2);
	game->image.collec_3 = mlx_texture_to_image(mlx, game->textures.collec_3);
	game->image.collec_4 = mlx_texture_to_image(mlx, game->textures.collec_4);
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
	else if (count == FRAMEP)
		mlx_image_to_window(game->mlx, game->image.pac_man_exit1, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == FRAMEP * 2)
		mlx_image_to_window(game->mlx, game->image.pac_man_exit2, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == FRAMEP * 3)
		mlx_image_to_window(game->mlx, game->image.pac_man_exit3, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == FRAMEP * 4)
		mlx_image_to_window(game->mlx, game->image.pac_man_exit4, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == FRAMEP * 5)
		mlx_image_to_window(game->mlx, game->image.pac_man_exit5, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == FRAMEP * 6)
		mlx_image_to_window(game->mlx, game->image.exit, game->exit_y * SIZE, game->exit_x * SIZE);
	else if (count == FRAMEP * 7)
	{
		mlx_close_window(game->mlx);
		free(game->map);
		printf("\n\e[92mGood Job! 🎉\nYou won with %d mooves! 🥳\n\n\e[97m", game->mooves);
	}
	count++;
}

void ft_pac_man_instances(mlx_image_t *image, t_game *game)
{
	game->image.player->instances->x = -1 * SIZE;
	game->image.player_u->instances->x = -1 * SIZE;
	game->image.player_d->instances->x = -1 * SIZE;
	game->image.player_l->instances->x = -1 * SIZE;
	game->image.player_r->instances->x = -1 * SIZE;
	game->image.pac_up_frame2->instances->x = -1 * SIZE;
	game->image.pac_up_frame3->instances->x = -1 * SIZE;
	game->image.pac_up_frame4->instances->x = -1 * SIZE;
	game->image.pac_down_frame2->instances->x = -1 * SIZE;
	game->image.pac_down_frame3->instances->x = -1 * SIZE;
	game->image.pac_down_frame4->instances->x = -1 * SIZE;
	game->image.pac_left_frame2->instances->x = -1 * SIZE;
	game->image.pac_left_frame3->instances->x = -1 * SIZE;
	game->image.pac_left_frame4->instances->x = -1 * SIZE;
	game->image.pac_right_frame2->instances->x = -1 * SIZE;
	game->image.pac_right_frame3->instances->x = -1 * SIZE;
	game->image.pac_right_frame4->instances->x = -1 * SIZE;
	game->image.ground->instances->x = -1;
	image->instances->x = game->player_y * SIZE;
	image->instances->y = game->player_x * SIZE;
}

void ft_frame_pac_man(t_game *game, int n)
{
	if (n == 5)
		ft_pac_man_instances(game->image.player, game);
	if (game->state == 1 && n == 1)
		ft_pac_man_instances(game->image.player_u, game);
	if (game->state == 2 && n == 1)
		ft_pac_man_instances(game->image.player_d, game);
	if (game->state == 3 && n == 1)
		ft_pac_man_instances(game->image.player_l, game);
	if (game->state == 4 && n == 1)
		ft_pac_man_instances(game->image.player_r, game);
	if (game->state == 1 && n == 2)
		ft_pac_man_instances(game->image.pac_up_frame2, game);
	if (game->state == 2 && n == 2)
		ft_pac_man_instances(game->image.pac_down_frame2, game);
	if (game->state == 3 && n == 2)
		ft_pac_man_instances(game->image.pac_left_frame2, game);
	if (game->state == 4 && n == 2)
		ft_pac_man_instances(game->image.pac_right_frame2, game);
	if (game->state == 1 && n == 3)
		ft_pac_man_instances(game->image.pac_up_frame3, game);
	if (game->state == 2 && n == 3)
		ft_pac_man_instances(game->image.pac_down_frame3, game);
	if (game->state == 3 && n == 3)
		ft_pac_man_instances(game->image.pac_left_frame3, game);
	if (game->state == 4 && n == 3)
		ft_pac_man_instances(game->image.pac_right_frame3, game);
	if (game->state == 1 && n == 4)
		ft_pac_man_instances(game->image.pac_up_frame4, game);
	if (game->state == 2 && n == 4)
		ft_pac_man_instances(game->image.pac_down_frame4, game);
	if (game->state == 3 && n == 4)
		ft_pac_man_instances(game->image.pac_left_frame4, game);
	if (game->state == 4 && n == 4)
		ft_pac_man_instances(game->image.pac_right_frame4, game);
}

void frames_player(t_game *game)
{
	static int count = 0;

	if (game->victory == 1)
		return ;
	if (count < FRAMEP)
		ft_frame_pac_man(game, 1);
	else if (count < FRAMEP * 2)
		ft_frame_pac_man(game, 2);
	else if (count < FRAMEP * 3)
		ft_frame_pac_man(game, 3);
	else if (count < FRAMEP * 4)
		ft_frame_pac_man(game, 4);
	else if (count < FRAMEP * 5)
		ft_frame_pac_man(game, 5);
	else if (count < FRAMEP * 6)
		ft_frame_pac_man(game, 4);
	else if (count < FRAMEP * 7)
		ft_frame_pac_man(game, 3);
	else if (count < FRAMEP * 8)
		ft_frame_pac_man(game, 2);
	else if (count == FRAMEP * 8)
	{
		ft_frame_pac_man(game, 1);
		count = 0;
	} 
	count++;
}

void	frames_collec(t_game *game, int state)
{
	int	i;

	i = -1;
	while (++i < game->max_collec )
	{
		game->image.collec->instances[i].enabled = 0;
		game->image.collec_2->instances[i].enabled = 0;
		game->image.collec_3->instances[i].enabled = 0;
		game->image.collec_4->instances[i].enabled = 0;
		if (state == 1 && game->image.fake_ground->instances[i].enabled != 1)
			game->image.collec->instances[i].enabled = 1;
		if (state == 2 && game->image.fake_ground->instances[i].enabled != 1)
			game->image.collec_2->instances[i].enabled = 1;
		if (state == 3 && game->image.fake_ground->instances[i].enabled != 1)
			game->image.collec_3->instances[i].enabled = 1;
		if (state == 4 && game->image.fake_ground->instances[i].enabled != 1)
			game->image.collec_4->instances[i].enabled = 1;
	}
}

void	ft_frames(t_game *game)
{
	static int count = 0;
	if (count < FRAMEC)
		frames_collec(game, 3);
	else if (count < FRAMEC * 2)
		frames_collec(game, 2);
	else if (count < FRAMEC * 3)
		frames_collec(game, 3);
	else if (count < FRAMEC * 4)
		frames_collec(game, 2);
	else if (count < FRAMEC * 5)
		frames_collec(game, 3);
	else if (count < FRAMEC * 6)
		frames_collec(game, 2);
	else if (count == FRAMEC * 6)
	{
		frames_collec(game, 3);
		count = 0;
	}
	count++;
}

void	disable_collec(t_game *game)
{
	int i;
	
	i = -1;
	while (++i < game->max_collec)
	{
		if (game->image.collec->instances[i].x / SIZE == game->player_y
			&& game->image.collec->instances[i].y / SIZE == game->player_x)
		{
			game->image.collec->instances[i].enabled = 0;
			game->image.collec_2->instances[i].enabled = 0;
			game->image.collec_3->instances[i].enabled = 0;
			game->image.collec_4->instances[i].enabled = 0;
			game->image.fake_ground->instances[i].enabled = 1;
		}
	}
}

void	ft_move_pac_man(t_game *game, int o, char c, int state)
{
	if (c == 'u' || c == 'd')
		game->player_x = game->player_x + o;
	else
		game->player_y = game->player_y + o;
	frames_player(game);
	game->state = state;
	if (o != 0)
		game->mooves++;
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		disable_collec(game);
		game->map[game->player_x][game->player_y] = '0';
		game->get_collec++;
		if (game->get_collec == game->max_collec)
			game->image.exit->instances[0].enabled = 1;
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
		ft_move_pac_man(game, -1, 'u', 1);
	else if (key_data.key == MLX_KEY_DOWN && game->map[game->player_x + 1][game->player_y] != '1')
		ft_move_pac_man(game, 1, 'd', 2);
	else if (key_data.key == MLX_KEY_LEFT && game->map[game->player_x][game->player_y - 1] != '1')
		ft_move_pac_man(game, -1, 'l', 3);
	else if (key_data.key == MLX_KEY_RIGHT && game->map[game->player_x][game->player_y + 1] != '1')
		ft_move_pac_man(game, 1, 'r', 4);
	else if (key_data.key == MLX_KEY_UP && game->map[game->player_x - 1][game->player_y] == '1')
		ft_move_pac_man(game, 0, 'u', 1);
	else if (key_data.key == MLX_KEY_DOWN && game->map[game->player_x + 1][game->player_y] == '1')
		ft_move_pac_man(game, 0, 'd', 2);
	else if (key_data.key == MLX_KEY_LEFT && game->map[game->player_x][game->player_y - 1] == '1')
		ft_move_pac_man(game, 0, 'l', 3);
	else if (key_data.key == MLX_KEY_RIGHT && game->map[game->player_x][game->player_y + 1] == '1')
		ft_move_pac_man(game, 0, 'r', 4);
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
	mlx_loop_hook(game.mlx, (void (*))ft_frames, (void *)&game);
	mlx_loop_hook(game.mlx, (void (*))frames_player, (void *)&game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}