/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:01 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/05 20:45:36 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	loose_exit(t_game *game)
{
	game->music.run_music = false;
	game->music.bg_sec = 24;
	sleep(1);
	if (game->music.music_pid > 0)
		kill(game->music.music_pid, SIGKILL);
	play_sound(game->loose_sound_thread, loose_sound);
	pthread_join(game->bg_music_thrt, NULL);
	sleep(1);
	mlx_terminate(game->mlx);
	free(game->map);
	ft_array_free(game->map_array);
	ft_printf("\033[31mYou lost :/\n\033[0m");
	exit(EXIT_SUCCESS);
}

void	win_exit(t_game *game)
{
	play_sound(game->exit_sound_thread, exit_sound);
	game->music.run_music = false;
	game->music.bg_sec = 24;
	sleep(1);
	if (game->music.music_pid > 0)
		kill(game->music.music_pid, SIGKILL);
	play_sound(game->win_sound_thread, win_sound);
	pthread_join(game->bg_music_thrt, NULL);
	sleep(1);
	mlx_terminate(game->mlx);
	free(game->map);
	ft_array_free(game->map_array);
	ft_printf("\033[32mYou won :) -score: %i\n\033[0m", game->c);
	exit(EXIT_SUCCESS);
}

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
	game->c = 0;
	game->isinited = 0;
	game->state = 0;
	game->active_frame = 0;
	game->monster_move_count = 0;
	game->frame_count = 0;
	game->direction = 'l';
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
	game->isinited = 1;
	return (0);
}

void	animate(t_game *g)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (g->img.pl_l_i[i] != NULL)
		{
			if (g->direction == 'l' && g->isinited)
			{
				if (i == g->active_frame)
				{
					if (g->img.pl_l_i[i]->instances != NULL)
					{
						ft_printf("ja bei l %i\n", i);
						g->img.pl_l_i[i]->instances[0].enabled = 1;
					}
				}
				else
				{
					if (g->img.pl_l_i[i]->instances != NULL)
						g->img.pl_l_i[i]->instances[0].enabled = 0;
				}
			}
			else if (g->direction == 'r' && g->isinited)
			{
				if (i == g->active_frame)
				{
					if (g->img.pl_r_i[i]->instances != NULL)
					{
						ft_printf("ja bei r %i\n", i);
						g->img.pl_r_i[i]->instances[0].enabled = 1;
					}
				}
				else
				{
					if (g->img.pl_r_i[i]->instances != NULL)
						g->img.pl_r_i[i]->instances[0].enabled = 0;
				}
			}
		}
		i++;
	}
}

void	loop_hooky(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (g->frame_count > 29)
		g->frame_count = 0;
	if (g->monster_move_count > 199)
		g->monster_move_count = 0;
	if ((g->frame_count % 10) == 0)
	{
		g->active_frame = g->frame_count / 10;
		animate(g);
	}
	if ((g->monster_move_count % 20) == 0)
	{
		monster_action(g);
	}
	g->frame_count++;
	g->monster_move_count++;
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
	mlx_loop_hook(game.mlx, loop_hooky, &game);
	mlx_loop(game.mlx);
	loose_exit(&game);
	return (exit_code);
}
