/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:01 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/29 00:20:39 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	initial_map_paint(t_game *game)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->map[index] != '\n')
			{
				print_texture(game, index, x, y);
				x++;
			}
			index++;
		}
		y++;
	}
}

int	initialize(t_game *game, int argc, char **argv)
{
	if (validate_input(argc, argv) > 0)
		return (EXIT_FAILURE);
	if (validate_map(game, argv[1]) > 0)
		return (free(game->map), EXIT_FAILURE);
	game->count = 0;
	game->size = get_mapsize(game->map);
	game->player_pos = get_player_position(game);
	game->map_array = ft_split(game->map, '\n');
	game->winwidth = game->size.x * BLOCK;
	game->winheight = game->size.y * BLOCK;
	game->mlx = mlx_init(game->winwidth, game->winheight, "so_long", false);
	if (!game->mlx)
		return (ft_putstr_fd(2, (char *)mlx_strerror(mlx_errno)), EXIT_FAILURE);
	if (load_textures(game) > 0)
		return (free(game->map), EXIT_FAILURE);
	initial_map_paint(game);
	start_music();
	sleep(2);
	game->music.run_music = true;
	return (0);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	int				new_x;
	int				new_y;
	char			direction;
	t_game			*game;

	game = (t_game *)param;
	new_x = game->player_pos.x;
	new_y = game->player_pos.y;
	direction = 'l';
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) {
		mlx_delete_image(game->mlx, game->score);
		if (keydata.key == MLX_KEY_UP) {
			direction = 'u';
			game->count++;
			new_y--;
		} else if (keydata.key == MLX_KEY_DOWN) {
			direction = 'd';
			game->count++;
			new_y++;
		} else if (keydata.key == MLX_KEY_LEFT) {
			direction = 'l';
			game->count++;
			new_x--;
		} else if (keydata.key == MLX_KEY_RIGHT) {
			direction = 'r';
			game->count++;
			new_x++;
		}
		game->score = mlx_put_string(game->mlx, ft_itoa(game->count), BLOCK / 6, BLOCK / 6);

		if (game->map_array[new_y][new_x] != '1') {
		
			if (game->map_array[game->player_pos.y][game->player_pos.x] != 'E')
			{
				mlx_image_to_window(game->mlx, game->img.bg_i, game->player_pos.x * BLOCK, game->player_pos.y * BLOCK);
			}
			game->player_pos.x = new_x;
			game->player_pos.y = new_y;

			if (game->map_array[new_y][new_x] == 'E')
			{
				play_sound(game->exit_sound_thread, exit_sound);
				game->music.run_music = false;
				pthread_join(game->bg_music_thrt, NULL);
				
				mlx_terminate(game->mlx);
				free(game->map);
				if (!ft_array_strchr(game->map_array, 'C'))
					play_sound(game->win_sound_thread, win_sound);
				else
					play_sound(game->loose_sound_thread, loose_sound);
			}

			if (game->map_array[new_y][new_x] == 'C')
			{
				game->map_array[new_y][new_x] = '0';
					play_sound(game->collect_sound_thread, collect_sound);
			}
			if (direction == 'u')
				mlx_image_to_window(game->mlx, game->img.plyr_u_i, new_x * BLOCK, new_y * BLOCK);
			else if (direction == 'd')
				mlx_image_to_window(game->mlx, game->img.plyr_d_i, new_x * BLOCK, new_y * BLOCK);
			else if (direction == 'l')
				mlx_image_to_window(game->mlx, game->img.plyr_l_i, new_x * BLOCK, new_y * BLOCK);
			else if (direction == 'r')
				mlx_image_to_window(game->mlx, game->img.plyr_r_i, new_x * BLOCK, new_y * BLOCK);
		}
	}
	play_sound(game->sound_thread, player_move_sound);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		exit_code;

	exit_code = initialize(&game, argc, argv);
	if (exit_code > 0)
		return (exit_code);
	pthread_create(&game.bg_music_thrt, NULL, bg_music, &game.music);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	game.music.run_music = false;
	pthread_join(game.bg_music_thrt, NULL);
	mlx_terminate(game.mlx);
	free(game.map);
	return (exit_code);
}
