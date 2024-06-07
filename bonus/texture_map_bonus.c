/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:00:48 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 20:11:10 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

int	load_texture_map_bg(t_game *game)
{
	game->bg_t = mlx_load_png("assets/background.png");
	if (!game->bg_t)
	{
		ft_putstr_fd(2, "Error loading background.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->bg_i = mlx_texture_to_image(game->mlx, game->bg_t);
	if (!game->bg_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_texture_map_bbg(t_game *game)
{
	game->bbg_t = mlx_load_png("assets/background.png");
	if (!game->bbg_t)
	{
		ft_putstr_fd(2, "Error loading background.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->bbg_i = mlx_texture_to_image(game->mlx, game->bbg_t);
	if (!game->bbg_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_texture_map_wall(t_game *game)
{
	game->wall_t = mlx_load_png("assets/wall.png");
	if (!game->wall_t)
	{
		ft_putstr_fd(2, "Error loading wall.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->wall_i = mlx_texture_to_image(game->mlx, game->wall_t);
	if (!game->wall_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_textures_map(t_game *game)
{
	int	exit_code;

	exit_code = 0;
	if (exit_code == 0)
		exit_code = load_texture_map_bg(game);
	if (exit_code == 0)
		exit_code = load_texture_map_bbg(game);
	if (exit_code == 0)
		exit_code = load_texture_map_wall(game);
	if (exit_code > 0)
		return (exit_code);
	else
	{
		mlx_resize_image(game->bbg_i, game->winwidth, game->winheight);
		mlx_resize_image(game->bg_i, BLOCK, BLOCK);
		mlx_resize_image(game->wall_i, BLOCK, BLOCK);
		mlx_image_to_window(game->mlx, game->bbg_i, 0, 0);
	}
	return (0);
}
