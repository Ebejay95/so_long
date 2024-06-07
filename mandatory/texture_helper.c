/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:41:42 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 19:46:04 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

void	load_pl_left(t_game *g, int x, int y)
{
	g->pl_l_i = mlx_texture_to_image(g->mlx, g->pl_l_t);
	mlx_resize_image(g->pl_l_i, BLOCK, BLOCK);
	mlx_image_to_window(g->mlx, g->pl_l_i, x * BLOCK, y * BLOCK);
}

void	load_pl_right(t_game *g, int x, int y)
{
	g->pl_r_i = mlx_texture_to_image(g->mlx, g->pl_r_t);
	mlx_resize_image(g->pl_r_i, BLOCK, BLOCK);
	mlx_image_to_window(g->mlx, g->pl_r_i, x * BLOCK, y * BLOCK);
}

void	load_pl_up(t_game *g, int x, int y)
{
	g->pl_u_i = mlx_texture_to_image(g->mlx, g->pl_u_t);
	mlx_resize_image(g->pl_u_i, BLOCK, BLOCK);
	mlx_image_to_window(g->mlx, g->pl_u_i, x * BLOCK, y * BLOCK);
}

void	load_pl_down(t_game *g, int x, int y)
{
	g->pl_d_i = mlx_texture_to_image(g->mlx, g->pl_d_t);
	mlx_resize_image(g->pl_d_i, BLOCK, BLOCK);
	mlx_image_to_window(g->mlx, g->pl_d_i, x * BLOCK, y * BLOCK);
}
