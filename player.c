/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:24:15 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/05 20:33:17 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

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
	int	y;
	int	x;

	y = g->player_pos.y;
	x = g->player_pos.x;
	nx = g->new_x;
	ny = g->new_y;
	if (g->direction == 'u')
		mlx_image_to_window(g->mlx, g->img.pl_u_i[0], nx * BLOCK, ny * BLOCK);
	else if (g->direction == 'd')
		mlx_image_to_window(g->mlx, g->img.pl_d_i[0], nx * BLOCK, ny * BLOCK);
	else if (g->direction == 'l')
		mlx_image_to_window(g->mlx, g->img.pl_l_i[0], nx * BLOCK, ny * BLOCK);
	else if (g->direction == 'r')
		mlx_image_to_window(g->mlx, g->img.pl_r_i[0], nx * BLOCK, ny * BLOCK);
	if (g->map_array[y][x] != 'E')
		mlx_image_to_window(g->mlx, g->img.bg_i, x * BLOCK, y * BLOCK);
	else
	{
		mlx_image_to_window(g->mlx, g->img.bg_i, x * BLOCK, y * BLOCK);
		mlx_image_to_window(g->mlx, g->img.exit_i, x * BLOCK, y * BLOCK);
	}
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
