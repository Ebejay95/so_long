/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:11:27 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:04:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

int	load_textures(t_game *game)
{
	int	exit_code;

	exit_code = 0;
	exit_code = load_textures_map(game);
	if (exit_code > 0)
		return (exit_code);
	exit_code = load_textures_items(game);
	if (exit_code > 0)
		return (exit_code);
	exit_code = load_textures_player(game);
	if (exit_code > 0)
		return (exit_code);
	exit_code = load_textures_monsters(game);
	if (exit_code > 0)
		return (exit_code);
	return (exit_code);
}

void	load_player_frames(t_game *g, int x, int y)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (g->direction == 'l')
			load_pl_left(g, x, y, i);
		if (g->direction == 'r')
			load_pl_right(g, x, y, i);
		if (g->direction == 'u')
			load_pl_up(g, x, y, i);
		if (g->direction == 'd')
			load_pl_down(g, x, y, i);
		i++;
	}
}

void	print_texture(t_game *g, int index, int x, int y)
{
	if (g->map[index] == '1')
		mlx_image_to_window(g->mlx, g->wall_i, x * BLOCK, y * BLOCK);
	else if (g->map[index] == '0')
		mlx_image_to_window(g->mlx, g->bg_i, x * BLOCK, y * BLOCK);
	else if (g->map[index] == 'C')
		mlx_image_to_window(g->mlx, g->cllctbl_i, x * BLOCK, y * BLOCK);
	else if (g->map[index] == 'E')
		mlx_image_to_window(g->mlx, g->ex_i, x * BLOCK, y * BLOCK);
	else if (g->map[index] == 'M')
		mlx_image_to_window(g->mlx, g->m_i, x * BLOCK, y * BLOCK);
	else if (g->map[index] == 'P')
	{
		load_player_frames(g, x, y);
		g->player_pos.x = x;
		g->player_pos.y = y;
	}
}
