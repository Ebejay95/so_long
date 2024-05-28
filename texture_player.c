/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:03:32 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/28 23:42:38 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	load_texture_player_left(t_game *game)
{
	game->img.plyr_l_t = mlx_load_png("assets/player_left.png");
	if (!game->img.plyr_l_t)
	{
		ft_putstr_fd(2, "Error loading player.png\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	game->img.plyr_l_i = mlx_texture_to_image(game->mlx, game->img.plyr_l_t);
	if (!game->img.plyr_l_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_texture_player_right(t_game *game)
{
	game->img.plyr_r_t = mlx_load_png("assets/player_right.png");
	if (!game->img.plyr_r_t)
	{
		ft_putstr_fd(2, "Error loading player.png\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	game->img.plyr_r_i = mlx_texture_to_image(game->mlx, game->img.plyr_r_t);
	if (!game->img.plyr_r_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_texture_player_up(t_game *game)
{
	game->img.plyr_u_t = mlx_load_png("assets/player_up.png");
	if (!game->img.plyr_u_t)
	{
		ft_putstr_fd(2, "Error loading player.png\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	game->img.plyr_u_i = mlx_texture_to_image(game->mlx, game->img.plyr_u_t);
	if (!game->img.plyr_u_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_texture_player_down(t_game *game)
{
	game->img.plyr_d_t = mlx_load_png("assets/player_down.png");
	if (!game->img.plyr_d_t)
	{
		ft_putstr_fd(2, "Error loading player.png\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	game->img.plyr_d_i = mlx_texture_to_image(game->mlx, game->img.plyr_d_t);
	if (!game->img.plyr_d_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
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
		mlx_resize_image(game->img.plyr_l_i, BLOCK, BLOCK);
		mlx_resize_image(game->img.plyr_r_i, BLOCK, BLOCK);
		mlx_resize_image(game->img.plyr_u_i, BLOCK, BLOCK);
		mlx_resize_image(game->img.plyr_d_i, BLOCK, BLOCK);
	}
	return (0);
}
