/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:03:32 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/05 20:33:17 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	load_texture_player_left(t_game *game)
{
	game->img.pl_l_t[0] = mlx_load_png("assets/player_left.png");
	game->img.pl_l_t[1] = mlx_load_png("assets/player_left_animated.png");
	game->img.pl_l_t[2] = mlx_load_png("assets/player_left.png");
	game->img.pl_l_i[0] = mlx_texture_to_image(game->mlx, game->img.pl_l_t[0]);
	game->img.pl_l_i[1] = mlx_texture_to_image(game->mlx, game->img.pl_l_t[1]);
	game->img.pl_l_i[2] = mlx_texture_to_image(game->mlx, game->img.pl_l_t[2]);
	return (0);
}

int	load_texture_player_right(t_game *game)
{
	game->img.pl_r_t[0] = mlx_load_png("assets/player_right.png");
	game->img.pl_r_t[1] = mlx_load_png("assets/player_left_animated.png");
	game->img.pl_r_t[2] = mlx_load_png("assets/player_right.png");
	game->img.pl_r_i[0] = mlx_texture_to_image(game->mlx, game->img.pl_r_t[0]);
	game->img.pl_r_i[1] = mlx_texture_to_image(game->mlx, game->img.pl_r_t[1]);
	game->img.pl_r_i[2] = mlx_texture_to_image(game->mlx, game->img.pl_r_t[2]);
	return (0);
}

int	load_texture_player_up(t_game *game)
{
	game->img.pl_u_t[0] = mlx_load_png("assets/player_up.png");
	game->img.pl_u_t[1] = mlx_load_png("assets/player_left_animated.png");
	game->img.pl_u_t[2] = mlx_load_png("assets/player_up.png");
	game->img.pl_u_i[0] = mlx_texture_to_image(game->mlx, game->img.pl_u_t[0]);
	game->img.pl_u_i[1] = mlx_texture_to_image(game->mlx, game->img.pl_u_t[1]);
	game->img.pl_u_i[2] = mlx_texture_to_image(game->mlx, game->img.pl_u_t[2]);
	return (0);
}

int	load_texture_player_down(t_game *game)
{
	game->img.pl_d_t[0] = mlx_load_png("assets/player_down.png");
	game->img.pl_d_t[1] = mlx_load_png("assets/player_left_animated.png");
	game->img.pl_d_t[2] = mlx_load_png("assets/player_down.png");
	game->img.pl_d_i[0] = mlx_texture_to_image(game->mlx, game->img.pl_d_t[0]);
	game->img.pl_d_i[1] = mlx_texture_to_image(game->mlx, game->img.pl_d_t[1]);
	game->img.pl_d_i[2] = mlx_texture_to_image(game->mlx, game->img.pl_d_t[2]);
	return (0);
}

int	load_textures_player(t_game *game)
{
	int	exit_code;

	exit_code = 0;
	exit_code = load_texture_player_left(game);
	exit_code = load_texture_player_right(game);
	exit_code = load_texture_player_up(game);
	exit_code = load_texture_player_down(game);
	if (exit_code > 0)
		return (exit_code);
	else
	{
		mlx_resize_image(game->img.pl_l_i[0], BLOCK, BLOCK);
		mlx_resize_image(game->img.pl_l_i[1], BLOCK, BLOCK);
		mlx_resize_image(game->img.pl_l_i[2], BLOCK, BLOCK);
		mlx_resize_image(game->img.pl_r_i[0], BLOCK, BLOCK);
		mlx_resize_image(game->img.pl_r_i[1], BLOCK, BLOCK);
		mlx_resize_image(game->img.pl_r_i[2], BLOCK, BLOCK);
		mlx_resize_image(game->img.pl_u_i[0], BLOCK, BLOCK);
		mlx_resize_image(game->img.pl_u_i[1], BLOCK, BLOCK);
		mlx_resize_image(game->img.pl_u_i[2], BLOCK, BLOCK);
		mlx_resize_image(game->img.pl_d_i[0], BLOCK, BLOCK);
		mlx_resize_image(game->img.pl_d_i[1], BLOCK, BLOCK);
		mlx_resize_image(game->img.pl_d_i[2], BLOCK, BLOCK);
	}
	return (0);
}
