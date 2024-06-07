/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_items_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:02:29 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:04:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

int	load_texture_item_collectable(t_game *game)
{
	game->cllctbl_t = mlx_load_png("assets/collectable.png");
	if (!game->cllctbl_t)
	{
		ft_putstr_fd(2, "Error loading collectable.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->cllctbl_i = mlx_texture_to_image(game->mlx, game->cllctbl_t);
	if (!game->cllctbl_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_texture_item_exit(t_game *game)
{
	game->exit_t = mlx_load_png("assets/exit.png");
	if (!game->exit_t)
	{
		ft_putstr_fd(2, "Error loading exit.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->ex_i = mlx_texture_to_image(game->mlx, game->exit_t);
	if (!game->ex_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		terminate_mlx(game);
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
		mlx_resize_image(game->cllctbl_i, BLOCK, BLOCK);
		mlx_resize_image(game->ex_i, BLOCK, BLOCK);
	}
	return (0);
}
