/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:24:15 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/29 19:48:58 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	initialize_player_animation(t_game *game)
{
	game->player_l_animation[0] = game->img.plyr_l_i1;
	game->player_l_animation[1] = game->img.plyr_l_i2;
	game->player_l_animation[2] = game->img.plyr_l_i3;
}

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

void	render_move(t_game *g, int frame)
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
		mlx_image_to_window(g->mlx, g->img.plyr_u_i, nx * BLOCK, ny * BLOCK);
	else if (g->direction == 'd')
		mlx_image_to_window(g->mlx, g->img.plyr_d_i, nx * BLOCK, ny * BLOCK);
	else if (g->direction == 'l')
		mlx_image_to_window(g->mlx, g->player_l_animation[frame], x * BLOCK, y * BLOCK);
	else if (g->direction == 'r')
		mlx_image_to_window(g->mlx, g->img.plyr_r_i, nx * BLOCK, ny * BLOCK);
	if (g->map_array[y][x] != 'E')
		mlx_image_to_window(g->mlx, g->img.bg_i, x * BLOCK, y * BLOCK);
	else
	{
		mlx_image_to_window(g->mlx, g->img.bg_i, x * BLOCK, y * BLOCK);
		mlx_image_to_window(g->mlx, g->img.exit_i, x * BLOCK, y * BLOCK);
	}
//
	//	mlx_image_to_window(g->mlx, g->img.bg_i, x * BLOCK, y * BLOCK);
	//if (g->direction == 'u')
	//	mlx_image_to_window(g->mlx, g->img.plyr_u_i, x * BLOCK, y * BLOCK);
	//else if (g->direction == 'd')
	//	mlx_image_to_window(g->mlx, g->img.plyr_d_i, x * BLOCK, y * BLOCK);
	//else if (g->direction == 'l')
	//{
	//	mlx_image_to_window(g->mlx, g->player_l_animation[frame], x * BLOCK, y * BLOCK);
	//}//	mlx_image_to_window(g->mlx, g->img.plyr_l_i, x * BLOCK, nyyy * BLOCK);
	//else if (g->direction == 'r')
	//	mlx_image_to_window(g->mlx, g->img.plyr_r_i, x * BLOCK, y * BLOCK);
	//if (g->map_array[y][x] != 'E')
	//	//mlx_image_to_window(g->mlx, g->img.bg_i, x * BLOCK, y * BLOCK);
	//else
	//{
	//	//mlx_image_to_window(g->mlx, g->img.bg_i, x * BLOCK, y * BLOCK);
	//	//mlx_image_to_window(g->mlx, g->img.exit_i, x * BLOCK, y * BLOCK);
	//}
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
				}
			}
		}
	}
	return (moved_to);
}
