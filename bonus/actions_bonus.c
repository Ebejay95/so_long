/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:28:59 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 18:02:27 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

void	handlevert_moves(t_game *game, mlx_key_data_t keydata, int *moved)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		game->direction = 'u';
		game->new_y--;
		*moved = 1;
	}
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{
		game->direction = 'd';
		game->new_y++;
		*moved = 1;
	}
}

void	handlehor_moves(t_game *game, mlx_key_data_t keydata, int *moved)
{
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		game->direction = 'l';
		game->new_x--;
		*moved = 1;
	}
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		game->direction = 'r';
		game->new_x++;
		*moved = 1;
	}
}

void	move_processing(t_game *g)
{
	int	x;
	int	y;

	x = g->player_pos.x;
	y = g->player_pos.y;
	play_sound(g->sound_thread, player_move_sound);
	if (g->map_array[g->new_y][g->new_x] == 'M')
		loose_exit(g);
	if (g->map_array[g->new_y][g->new_x] == 'C')
		play_sound(g->collect_sound_thread, collect_sound);
	if (g->map_array[y][x] != 'E')
		g->map_array[y][x] = '0';
	g->player_pos.x = g->new_x;
	g->player_pos.y = g->new_y;
	if (g->map_array[g->new_y][g->new_x] != 'E')
		g->map_array[g->new_y][g->new_x] = 'P';
	if (g->map_array[g->new_y][g->new_x] == 'E')
	{
		if (!ft_array_strchr(g->map_array, 'C'))
			g->state = 1;
		else
			play_sound(g->exitny_sound_thread, exitny_sound);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*g;
	char	moved_to;
	char	*score_str;

	g = (t_game *)param;
	if (g->state == 1)
		win_exit(g);
	else if (g->state == 2)
		loose_exit(g);
	if (keydata.key == MLX_KEY_ESCAPE)
		loose_exit(g);
	mlx_delete_image(g->mlx, g->score);
	moved_to = move_player(g, keydata);
	if (moved_to != '\0')
	{
		move_processing(g);
		g->c++;
	}
	score_str = ft_itoa(g->c);
	g->score = mlx_put_string(g->mlx, score_str, BLOCK / 6, BLOCK / 6);
	free(score_str);
}
