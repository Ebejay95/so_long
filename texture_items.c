/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:02:29 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/28 23:50:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	load_texture_item_collectable(t_game *game)
{
	game->img.cllctbl_t = mlx_load_png("assets/collectable.png");
	if (!game->img.cllctbl_t)
	{
		ft_putstr_fd(2, "Error loading collectable.png\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	game->img.cllctbl_i = mlx_texture_to_image(game->mlx, game->img.cllctbl_t);
	if (!game->img.cllctbl_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_texture_item_exit(t_game *game)
{
	game->img.exit_t = mlx_load_png("assets/exit.png");
	if (!game->img.exit_t)
	{
		ft_putstr_fd(2, "Error loading exit.png\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	game->img.exit_i = mlx_texture_to_image(game->mlx, game->img.exit_t);
	if (!game->img.exit_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_textures_items(t_game *game)
{
	int	exit_code;

	exit_code = 0;
	exit_code = load_texture_item_collectable(game);
	exit_code = load_texture_item_exit(game);
	if (exit_code > 0)
		return (exit_code);
	else
	{
		mlx_resize_image(game->img.cllctbl_i, BLOCK, BLOCK);
		mlx_resize_image(game->img.exit_i, BLOCK, BLOCK);
	}
	return (0);
}