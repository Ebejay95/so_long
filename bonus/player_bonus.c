/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:24:15 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:04:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

t_point	get_player_position(t_game *game)
{
	t_point	position;
	int		index;

	position.y = 0;
	position.x = 0;
	index = 0;
	while (game->map[index])
	{
		if (game->map[index] == 'P')
		{
			position.y = index / (game->size.x + 1);
			position.x = index % (game->size.x + 1);
			break ;
		}
		index++;
	}
	return (position);
}

void	render_move(t_game *g)
{
	int	nx;
	int	ny;
	int	x;
	int	y;

	nx = g->new_x;
	ny = g->new_y;
	x = g->player_pos.x;
	y = g->player_pos.y;
	load_player_frames(g, g->new_x, g->new_y);
	if (g->map_array[y][x] != 'E')
		mlx_image_to_window(g->mlx, g->bg_i, x * BLOCK, y * BLOCK);
	else
	{
		mlx_image_to_window(g->mlx, g->bg_i, x * BLOCK, y * BLOCK);
		mlx_image_to_window(g->mlx, g->ex_i, x * BLOCK, y * BLOCK);
	}
	g->player_pos.x = nx;
	g->player_pos.y = ny;
}

char	move_player(t_game *g, mlx_key_data_t keydata)
{
	char	moved_to;
	int		did_move;

	did_move = 0;
	moved_to = '\0';
	g->new_x = g->player_pos.x;
	g->new_y = g->player_pos.y;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		handlevert_moves(g, keydata, &did_move);
		handlehor_moves(g, keydata, &did_move);
		if (g->new_x >= 0 && g->new_x < g->size.x)
		{
			if (g->new_y >= 0 && g->new_y < g->size.y)
			{
				if (g->map_array[g->new_y][g->new_x] != '1' && did_move == 1)
				{
					moved_to = g->map_array[g->new_y][g->new_x];
					render_move(g);
				}
			}
		}
	}
	return (moved_to);
}
