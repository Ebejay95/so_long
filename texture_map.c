/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:00:48 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/28 23:48:31 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	load_texture_map_bg(t_game *game)
{
	game->img.bg_t = mlx_load_png("assets/background.png");
	if (!game->img.bg_t)
	{
		ft_putstr_fd(2, "Error loading background.png\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	game->img.bg_i = mlx_texture_to_image(game->mlx, game->img.bg_t);
	if (!game->img.bg_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_texture_map_bbg(t_game *game)
{
	game->img.bbg_t = mlx_load_png("assets/background.png");
	if (!game->img.bbg_t)
	{
		ft_putstr_fd(2, "Error loading background.png\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	game->img.bbg_i = mlx_texture_to_image(game->mlx, game->img.bbg_t);
	if (!game->img.bbg_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_texture_map_wall(t_game *game)
{
	game->img.wall_t = mlx_load_png("assets/wall.png");
	if (!game->img.wall_t)
	{
		ft_putstr_fd(2, "Error loading wall.png\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	game->img.wall_i = mlx_texture_to_image(game->mlx, game->img.wall_t);
	if (!game->img.wall_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_textures_map(t_game *game)
{
	int	exit_code;

	exit_code = 0;
	exit_code = load_texture_map_bg(game);
	exit_code = load_texture_map_bbg(game);
	exit_code = load_texture_map_wall(game);
	if (exit_code > 0)
		return (exit_code);
	else
	{
		mlx_resize_image(game->img.bbg_i, game->winwidth, game->winheight);
		mlx_resize_image(game->img.bg_i, BLOCK, BLOCK);
		mlx_resize_image(game->img.wall_i, BLOCK, BLOCK);
		mlx_image_to_window(game->mlx, game->img.bbg_i, 0, 0);
	}
	return (0);
}
