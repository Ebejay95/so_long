/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:01 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/27 22:22:48 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

char *ft_array_strchr(char **array, char c)
{
	int		length;
	int		i;
	char	*found;

	if (array == NULL)
		return (NULL);
	i = 0;
	found = NULL;
	length = ft_array_length(array);
	while (length > i && found == NULL)
	{
		found = ft_strchr(array[i], c);
		i++;
	}
	return (found);
}

void *player_move_sound(void *arg) {
	(void)arg;
	if (fork() == 0) {
		execlp("afplay", "afplay","-v", "0.6","assets/move.mp3", (char *)NULL);
		_exit(1);
	}
	return NULL;
}

void *win_sound(void *arg) {
	(void)arg;
	if (fork() == 0) {
		execlp("afplay", "afplay", "assets/win.mp3", (char *)NULL);
		_exit(1);
	}
	return NULL;
}

void *loose_sound(void *arg) {
	(void)arg;
	if (fork() == 0) {
		execlp("afplay", "afplay", "assets/loose.mp3", (char *)NULL);
		_exit(1);
	}
	return NULL;
}

void *exit_sound(void *arg) {
	(void)arg;
	if (fork() == 0) {
		execlp("afplay", "afplay", "assets/exit.mp3", (char *)NULL);
		_exit(1);
	}
	return NULL;
}

void *collect_sound(void *arg) {
	(void)arg;
	if (fork() == 0) {
		execlp("afplay", "afplay", "assets/collectable.mp3", (char *)NULL);
		_exit(1);
	}
	return NULL;
}

void *background_music(void *arg) {
	t_music_data *music_data = (t_music_data *)arg;
	while (music_data->run_music) {
		if (fork() == 0) {
			execlp("afplay", "afplay","-v", "0.5","assets/background.mp3", (char *)NULL);
			_exit(1);
		}
		sleep(24);
	}
	return NULL;
}

void *start_music(void) {
	if (fork() == 0) {
		execlp("afplay", "afplay", "assets/start.mp3", (char *)NULL);
	}
	return NULL;
}

void	initial_map_paint(t_game *game)
{
	int x, y, index;
	index = 0;
	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->map[index] != '\n')
			{
				if (game->map[index] == '1') {
					mlx_image_to_window(game->mlx, game->images.wall_image, x * BLOCK, y * BLOCK);
				} else if (game->map[index] == '0') {
					mlx_image_to_window(game->mlx, game->images.bg_image, x * BLOCK, y * BLOCK);
				} else if (game->map[index] == 'C') {
					mlx_image_to_window(game->mlx, game->images.collctbl_image, x * BLOCK, y * BLOCK);
				} else if (game->map[index] == 'E') {
					mlx_image_to_window(game->mlx, game->images.exit_image, x * BLOCK, y * BLOCK);
				} else if (game->map[index] == 'P') {
					mlx_image_to_window(game->mlx, game->images.player_left_image, x * BLOCK, y * BLOCK);
					game->player_pos.x = x;
					game->player_pos.y = y;
				}
				x++;
			}
			index++;
		}
		y++;
	}
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;
	int new_x = game->player_pos.x;
	int new_y = game->player_pos.y;
	char direction;
	pthread_t sound_thread;
	pthread_t exit_sound_thread;
	pthread_t collect_sound_thread;
	pthread_t win_sound_thread;
	pthread_t loose_sound_thread;

	direction = 'l';
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) {
		if (keydata.key == MLX_KEY_UP) {
			direction = 'u';
			ft_printf("hoch\n");
			new_y--;
		} else if (keydata.key == MLX_KEY_DOWN) {
			direction = 'd';
			ft_printf("runter\n");
			new_y++;
		} else if (keydata.key == MLX_KEY_LEFT) {
			direction = 'l';
			ft_printf("links\n");
			new_x--;
		} else if (keydata.key == MLX_KEY_RIGHT) {
			direction = 'r';
			ft_printf("rechts\n");
			new_x++;
		}

		if (game->map_array[new_y][new_x] != '1') {
		
			if (game->map_array[game->player_pos.y][game->player_pos.x] != 'E')
			{
				mlx_image_to_window(game->mlx, game->images.bg_image, game->player_pos.x * BLOCK, game->player_pos.y * BLOCK);
			}
			game->player_pos.x = new_x;
			game->player_pos.y = new_y;

			if (game->map_array[new_y][new_x] == 'E')
			{
				pthread_create(&exit_sound_thread, NULL, exit_sound, NULL);
				pthread_join(exit_sound_thread, NULL);
				game->music_data.run_music = false;
				pthread_join(game->background_music_thread, NULL);
				
				mlx_terminate(game->mlx);
				free(game->map);
				if (!ft_array_strchr(game->map_array, 'C'))
				{
					pthread_create(&win_sound_thread, NULL, win_sound, NULL);
					pthread_join(win_sound_thread, NULL);
				}
				else
				{
					pthread_create(&loose_sound_thread, NULL, loose_sound, NULL);
					pthread_join(loose_sound_thread, NULL);
				}
			}

			if (game->map_array[new_y][new_x] == 'C')
			{
				game->map_array[new_y][new_x] = '0';
				pthread_create(&collect_sound_thread, NULL, collect_sound, NULL);
				pthread_join(collect_sound_thread, NULL);
			}
			if (direction == 'u')
				mlx_image_to_window(game->mlx, game->images.player_up_image, new_x * BLOCK, new_y * BLOCK);
			else if (direction == 'd')
				mlx_image_to_window(game->mlx, game->images.player_down_image, new_x * BLOCK, new_y * BLOCK);
			else if (direction == 'l')
				mlx_image_to_window(game->mlx, game->images.player_left_image, new_x * BLOCK, new_y * BLOCK);
			else if (direction == 'r')
				mlx_image_to_window(game->mlx, game->images.player_right_image, new_x * BLOCK, new_y * BLOCK);
		}
	}
	pthread_create(&sound_thread, NULL, player_move_sound, NULL);
	pthread_join(sound_thread, NULL);
}

int main(int argc, char **argv) {
	t_game game;
	int window_width;
	int window_height;

	if (validate_input(argc, argv) > 0)
		return (EXIT_FAILURE);
	game.map = get_file_content(argv[1]);
	game.map = ft_strtrim(game.map, "\n");
	if (validate_map(game.map) > 0) {
		free(game.map);
		return (EXIT_FAILURE);
	}
	game.size = get_mapsize(game.map);
	game.player_pos = get_player_position(&game);
	game.map_array = ft_split(game.map, '\n');
	window_width = game.size.x * BLOCK;
	window_height = game.size.y * BLOCK;
	game.mlx = mlx_init(window_width, window_height, "so_long", false);
	if (!game.mlx) {
		ft_putstr_fd(2, (char *)mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	game.images.bg_texture = mlx_load_png("assets/background.png");
	if (!game.images.bg_texture) {
		ft_putstr_fd(2, "Error loading background.png\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.bg_image = mlx_texture_to_image(game.mlx, game.images.bg_texture);
	if (!game.images.bg_image) {
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.bbg_texture = mlx_load_png("assets/background.png");
	if (!game.images.bbg_texture) {
		ft_putstr_fd(2, "Error loading background.png\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.bbg_image = mlx_texture_to_image(game.mlx, game.images.bbg_texture);
	if (!game.images.bbg_image) {
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.wall_texture = mlx_load_png("assets/wall.png");
	if (!game.images.wall_texture) {
		ft_putstr_fd(2, "Error loading wall.png\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.wall_image = mlx_texture_to_image(game.mlx, game.images.wall_texture);
	if (!game.images.wall_image) {
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.collctbl_texture = mlx_load_png("assets/collectable.png");
	if (!game.images.collctbl_texture) {
		ft_putstr_fd(2, "Error loading collectable.png\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.collctbl_image = mlx_texture_to_image(game.mlx, game.images.collctbl_texture);
	if (!game.images.collctbl_image) {
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.exit_texture = mlx_load_png("assets/exit.png");
	if (!game.images.exit_texture) {
		ft_putstr_fd(2, "Error loading exit.png\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.exit_image = mlx_texture_to_image(game.mlx, game.images.exit_texture);
	if (!game.images.exit_image) {
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.player_left_texture = mlx_load_png("assets/player_left.png");
	if (!game.images.player_left_texture) {
		ft_putstr_fd(2, "Error loading player.png\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.player_left_image = mlx_texture_to_image(game.mlx, game.images.player_left_texture);
	if (!game.images.player_left_image) {
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.player_right_texture = mlx_load_png("assets/player_right.png");
	if (!game.images.player_right_texture) {
		ft_putstr_fd(2, "Error loading player.png\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.player_right_image = mlx_texture_to_image(game.mlx, game.images.player_right_texture);
	if (!game.images.player_right_image) {
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.player_up_texture = mlx_load_png("assets/player_up.png");
	if (!game.images.player_up_texture) {
		ft_putstr_fd(2, "Error loading player.png\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.player_up_image = mlx_texture_to_image(game.mlx, game.images.player_up_texture);
	if (!game.images.player_up_image) {
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.player_down_texture = mlx_load_png("assets/player_down.png");
	if (!game.images.player_down_texture) {
		ft_putstr_fd(2, "Error loading player.png\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	game.images.player_down_image = mlx_texture_to_image(game.mlx, game.images.player_down_texture);
	if (!game.images.player_down_image) {
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game.mlx);
		return (EXIT_FAILURE);
	}
	mlx_resize_image(game.images.bbg_image, window_width, window_height);
	mlx_resize_image(game.images.bg_image, BLOCK, BLOCK);
	mlx_resize_image(game.images.wall_image, BLOCK, BLOCK);
	mlx_resize_image(game.images.collctbl_image, BLOCK, BLOCK);
	mlx_resize_image(game.images.exit_image, BLOCK, BLOCK);
	mlx_resize_image(game.images.player_left_image, BLOCK, BLOCK);
	mlx_resize_image(game.images.player_right_image, BLOCK, BLOCK);
	mlx_resize_image(game.images.player_up_image, BLOCK, BLOCK);
	mlx_resize_image(game.images.player_down_image, BLOCK, BLOCK);
	mlx_image_to_window(game.mlx, game.images.bbg_image, 0, 0);
	initial_map_paint(&game);
	start_music();
	sleep(2);

	game.music_data.run_music = true;
	pthread_create(&game.background_music_thread, NULL, background_music, &game.music_data);

	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);

	game.music_data.run_music = false;
	pthread_join(game.background_music_thread, NULL);

	mlx_terminate(game.mlx);
	free(game.map);
	return (EXIT_SUCCESS);
}