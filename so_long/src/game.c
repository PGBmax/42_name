/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:57:50 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/16 18:22:44 by pboucher         ###   ########.fr       */
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
	if (n == 12)
		printf("MLX could not be created!\n\n\e[97m");
	if (n == 13)
		printf("Only one Blinky can exist!\n\n\e[97m");
	if (n == 14)
		printf("Only one Clyde can exist!\n\n\e[97m");
	if (n == 15)
		printf("Only one Pinky can exist!\n\n\e[97m");
	if (n == 16)
		printf("Only one Inky can exist!\n\n\e[97m");
	return (0);
}

void ft_pac_man_instances(mlx_image_t *image, t_game *game)
{
	int i;

	i = -1;
	while (++i < 5)
		game->image.player[i]->instances->x = -1 * SIZE;
	i = -1;
	while (++i < 12)
		game->image.pac_frame[i]->instances->x = -1 * SIZE;
	image->instances->x = game->player_y * SIZE;
	image->instances->y = game->player_x * SIZE;
}

void ft_frame_pac_man(t_game *game, int n)
{
	if (n == 5)
		ft_pac_man_instances(game->image.player[0], game);
	if (n == 1)
		ft_pac_man_instances(game->image.player[game->state], game);
	if (game->state == 1 && n == 2)
		ft_pac_man_instances(game->image.pac_frame[0], game);
	if (game->state == 2 && n == 2)
		ft_pac_man_instances(game->image.pac_frame[3], game);
	if (game->state == 3 && n == 2)
		ft_pac_man_instances(game->image.pac_frame[6], game);
	if (game->state == 4 && n == 2)
		ft_pac_man_instances(game->image.pac_frame[9], game);
	if (game->state == 1 && n == 3)
		ft_pac_man_instances(game->image.pac_frame[1], game);
	if (game->state == 2 && n == 3)
		ft_pac_man_instances(game->image.pac_frame[4], game);
	if (game->state == 3 && n == 3)
		ft_pac_man_instances(game->image.pac_frame[7], game);
	if (game->state == 4 && n == 3)
		ft_pac_man_instances(game->image.pac_frame[10], game);
	if (game->state == 1 && n == 4)
		ft_pac_man_instances(game->image.pac_frame[2], game);
	if (game->state == 2 && n == 4)
		ft_pac_man_instances(game->image.pac_frame[5], game);
	if (game->state == 3 && n == 4)
		ft_pac_man_instances(game->image.pac_frame[8], game);
	if (game->state == 4 && n == 4)
		ft_pac_man_instances(game->image.pac_frame[11], game);
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
		game->image.collec[0]->instances[i].enabled = 0;
		game->image.collec[1]->instances[i].enabled = 0;
		game->image.collec[2]->instances[i].enabled = 0;
		game->image.collec[3]->instances[i].enabled = 0;
		if (game->image.fground->instances[i].enabled != 1)
			game->image.collec[state]->instances[i].enabled = 1;
	}
}

void	ft_frames(t_game *game)
{
	static int count = 0;
	if (count < FRAMEC)
		frames_collec(game, 0);
	else if (count < FRAMEC * 2)
		frames_collec(game, 1);
	else if (count < FRAMEC * 3)
		frames_collec(game, 2);
	else if (count < FRAMEC * 4)
		frames_collec(game, 3);
	else if (count < FRAMEC * 5)
		frames_collec(game, 2);
	else if (count < FRAMEC * 6)
		frames_collec(game, 1);
	else if (count == FRAMEC * 6)
	{
		frames_collec(game, 0);
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
		if (game->image.collec[0]->instances[i].x / SIZE == game->player_y
			&& game->image.collec[0]->instances[i].y / SIZE == game->player_x)
		{
			game->image.collec[1]->instances[i].enabled = 0;
			game->image.collec[2]->instances[i].enabled = 0;
			game->image.collec[3]->instances[i].enabled = 0;
			game->image.collec[0]->instances[i].enabled = 0;
			game->image.fground->instances[i].enabled = 1;
		}
	}
}

void ft_show_count(t_game *game, int j, int i)
{
	if (i < 0)
		return	;
	game->image.digit[1]->instances[i].enabled = 0;
	game->image.digit[2]->instances[i].enabled = 0;
	game->image.digit[3]->instances[i].enabled = 0;
	game->image.digit[4]->instances[i].enabled = 0;
	game->image.digit[5]->instances[i].enabled = 0;
	game->image.digit[6]->instances[i].enabled = 0;
	game->image.digit[7]->instances[i].enabled = 0;
	game->image.digit[8]->instances[i].enabled = 0;
	game->image.digit[9]->instances[i].enabled = 0;
	game->image.digit[0]->instances[i].enabled = 0;
	game->image.digit[j]->instances[i].enabled = 1;
}

void	ft_update_count(t_game *game, int num, int step)
{
	if (num >= 10)
		ft_update_count(game, num / 10, step - 1);
	ft_show_count(game, num % 10, step);
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
	{
		game->mooves++;
		ft_update_count(game, game->mooves, game->nmb_count - 1);
		printf("\e[96mNumber of steps : %d\n\e[97m", game->mooves);
	}
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		disable_collec(game);
		game->map[game->player_x][game->player_y] = '0';
		game->get_collec++;
		if (game->get_collec == game->max_collec)
			mlx_image_to_window(game->mlx, game->image.exit, game->exit_y * SIZE, game->exit_x * SIZE);
	}
	if (game->map[game->player_x][game->player_y] == 'E' && game->get_collec == game->max_collec)
		game->victory = 1;
	if ((game->blinky_x == game->player_x && game->blinky_y == game->player_y) ||
		(game->pinky_x == game->player_x && game->pinky_y == game->player_y) ||
		(game->clyde_x == game->player_x && game->clyde_y == game->player_y) ||
		(game->inky_x == game->player_x && game->inky_y == game->player_y))
		game->victory = -1;
	if (game->victory == 0)
	{
		ft_moves_blinky(game);
		// ft_moves_inky(game);
		// ft_moves_pinky(game);
		// ft_moves_clyde(game);
	}
}

void	ft_hook(mlx_key_data_t key_data,t_game *game)
{
	if ((key_data.action != MLX_PRESS || game->victory != 0) && key_data.key != MLX_KEY_ESCAPE)
		return ;
	else if (key_data.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(game->mlx);
		if (game->victory == 1)
			printf("\n\e[93mPac Man just gave up about winning. 💀\n\n\e[97m");
		else if (game->victory == -1)
			printf("\n\e[93mPac Man just killed himself before dying. 💀\n\n\e[97m");
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
	game->state = 0;
	game->nmb_count = 0;
	game->blinky_x = -1;
	game->blinky_y = -1;
	game->inky_x = -1;
	game->inky_y = -1;
	game->pinky_x = -1;
	game->pinky_y = -1;
	game->clyde_x = -1;
	game->clyde_y = -1;
	game->nmb_ghost[0] = 0;
	game->nmb_ghost[1] = 0;
	game->nmb_ghost[2] = 0;
	game->nmb_ghost[3] = 0;
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
	init_game_values(&game);
	game.map = ft_read_map(av[1]);
	ft_know_size_map(&game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game.mlx = mlx_init(game.y * SIZE, game.x * SIZE, "Pac Man", true);
	if (!game.mlx)
		return (ft_error(12));
	ft_load_textures(game.mlx, &game.textures, &game.image);
	game.nmb_count = ft_create_map(game.mlx, game);
	if (!game.nmb_count)
		return (ft_error(9));
	if (!ft_parsing(game))
		return (0);
	mlx_key_hook(game.mlx, (void (*))ft_hook, (void *)&game);
	mlx_loop_hook(game.mlx, (void (*))ft_screen_victory, (void *)&game);
	mlx_loop_hook(game.mlx, (void (*))ft_screen_lose, (void *)&game);
	mlx_loop_hook(game.mlx, (void (*))ft_frames, (void *)&game);
	mlx_loop_hook(game.mlx, (void (*))frames_player, (void *)&game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
