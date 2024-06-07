/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:14:09 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:57:59 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

void	terminate_pl_imgs(t_game *game)
{
	if (game->pl_l_i[0])
		mlx_delete_image(game->mlx, game->pl_l_i[0]);
	if (game->pl_r_i[0])
		mlx_delete_image(game->mlx, game->pl_r_i[0]);
	if (game->pl_u_i[0])
		mlx_delete_image(game->mlx, game->pl_u_i[0]);
	if (game->pl_d_i[0])
		mlx_delete_image(game->mlx, game->pl_d_i[0]);
	if (game->pl_l_i[1])
		mlx_delete_image(game->mlx, game->pl_l_i[1]);
	if (game->pl_r_i[1])
		mlx_delete_image(game->mlx, game->pl_r_i[1]);
	if (game->pl_u_i[1])
		mlx_delete_image(game->mlx, game->pl_u_i[1]);
	if (game->pl_d_i[1])
		mlx_delete_image(game->mlx, game->pl_d_i[1]);
	if (game->pl_l_i[2])
		mlx_delete_image(game->mlx, game->pl_l_i[2]);
	if (game->pl_r_i[2])
		mlx_delete_image(game->mlx, game->pl_r_i[2]);
	if (game->pl_u_i[2])
		mlx_delete_image(game->mlx, game->pl_u_i[2]);
	if (game->pl_d_i[2])
		mlx_delete_image(game->mlx, game->pl_d_i[2]);
}

void	terminate_imgs(t_game *game)
{
	if (game->score)
		mlx_delete_image(game->mlx, game->score);
	if (game->bbg_i)
		mlx_delete_image(game->mlx, game->bbg_i);
	if (game->bg_i)
		mlx_delete_image(game->mlx, game->bg_i);
	if (game->wall_i)
		mlx_delete_image(game->mlx, game->wall_i);
	if (game->cllctbl_i)
		mlx_delete_image(game->mlx, game->cllctbl_i);
	if (game->ex_i)
		mlx_delete_image(game->mlx, game->ex_i);
	terminate_pl_imgs(game);
}

void	terminate_pl_texs(t_game *game)
{
	if (game->pl_l_t[0])
		mlx_delete_texture(game->pl_l_t[0]);
	if (game->pl_r_t[0])
		mlx_delete_texture(game->pl_r_t[0]);
	if (game->pl_u_t[0])
		mlx_delete_texture(game->pl_u_t[0]);
	if (game->pl_d_t[0])
		mlx_delete_texture(game->pl_d_t[0]);
	if (game->pl_l_t[1])
		mlx_delete_texture(game->pl_l_t[1]);
	if (game->pl_r_t[1])
		mlx_delete_texture(game->pl_r_t[1]);
	if (game->pl_u_t[1])
		mlx_delete_texture(game->pl_u_t[1]);
	if (game->pl_d_t[1])
		mlx_delete_texture(game->pl_d_t[1]);
	if (game->pl_l_t[2])
		mlx_delete_texture(game->pl_l_t[2]);
	if (game->pl_r_t[2])
		mlx_delete_texture(game->pl_r_t[2]);
	if (game->pl_u_t[2])
		mlx_delete_texture(game->pl_u_t[2]);
	if (game->pl_d_t[2])
		mlx_delete_texture(game->pl_d_t[2]);
}

void	terminate_texs(t_game *game)
{
	if (game->bbg_t)
		mlx_delete_texture(game->bbg_t);
	if (game->bg_t)
		mlx_delete_texture(game->bg_t);
	if (game->wall_t)
		mlx_delete_texture(game->wall_t);
	if (game->cllctbl_t)
		mlx_delete_texture(game->cllctbl_t);
	if (game->exit_t)
		mlx_delete_texture(game->exit_t);
	if (game->monster_t)
		mlx_delete_texture(game->monster_t);
	terminate_pl_texs(game);
}

void	terminate_mlx(t_game *game)
{
	terminate_imgs(game);
	terminate_texs(game);
	mlx_close_window(game->mlx);
}
