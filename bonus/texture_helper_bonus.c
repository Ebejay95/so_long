/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:41:42 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:04:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

void	load_pl_left(t_game *g, int x, int y, int i)
{
	g->pl_l_i[i] = mlx_texture_to_image(g->mlx, g->pl_l_t[i]);
	mlx_resize_image(g->pl_l_i[i], BLOCK, BLOCK);
	mlx_image_to_window(g->mlx, g->pl_l_i[i], x * BLOCK, y * BLOCK);
	if (i > 0)
		g->pl_l_i[i]->instances[0].enabled = 0;
}

void	load_pl_right(t_game *g, int x, int y, int i)
{
	g->pl_r_i[i] = mlx_texture_to_image(g->mlx, g->pl_r_t[i]);
	mlx_resize_image(g->pl_r_i[i], BLOCK, BLOCK);
	mlx_image_to_window(g->mlx, g->pl_r_i[i], x * BLOCK, y * BLOCK);
	if (i > 0)
		g->pl_r_i[i]->instances[0].enabled = 0;
}

void	load_pl_up(t_game *g, int x, int y, int i)
{
	g->pl_u_i[i] = mlx_texture_to_image(g->mlx, g->pl_u_t[i]);
	mlx_resize_image(g->pl_u_i[i], BLOCK, BLOCK);
	mlx_image_to_window(g->mlx, g->pl_u_i[i], x * BLOCK, y * BLOCK);
	if (i > 0)
		g->pl_u_i[i]->instances[0].enabled = 0;
}

void	load_pl_down(t_game *g, int x, int y, int i)
{
	g->pl_d_i[i] = mlx_texture_to_image(g->mlx, g->pl_d_t[i]);
	mlx_resize_image(g->pl_d_i[i], BLOCK, BLOCK);
	mlx_image_to_window(g->mlx, g->pl_d_i[i], x * BLOCK, y * BLOCK);
	if (i > 0)
		g->pl_d_i[i]->instances[0].enabled = 0;
}
