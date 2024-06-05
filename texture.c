/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:11:27 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/05 20:33:17 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

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

void	print_texture(t_game *g, int index, int x, int y)
{
	if (g->map[index] == '1')
		mlx_image_to_window(g->mlx, g->img.wall_i, x * BLOCK, y * BLOCK);
	else if (g->map[index] == '0')
		mlx_image_to_window(g->mlx, g->img.bg_i, x * BLOCK, y * BLOCK);
	else if (g->map[index] == 'C')
		mlx_image_to_window(g->mlx, g->img.cllctbl_i, x * BLOCK, y * BLOCK);
	else if (g->map[index] == 'E')
		mlx_image_to_window(g->mlx, g->img.exit_i, x * BLOCK, y * BLOCK);
	else if (g->map[index] == 'M')
		mlx_image_to_window(g->mlx, g->img.monster_i, x * BLOCK, y * BLOCK);
	else if (g->map[index] == 'P')
	{
		mlx_image_to_window(g->mlx, g->img.pl_l_i[0], x * BLOCK, y * BLOCK);
		g->player_pos.x = x;
		g->player_pos.y = y;
	}
}
