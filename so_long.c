/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:01 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 16:15:30 by jeberle          ###   ########.fr       */
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
	ft_printf("\033[32mYou won :)   score: %i\n\033[0m", game->c);
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
