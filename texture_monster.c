/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_monster.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:25:56 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/05 15:31:40 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	load_texture_monster(t_game *game)
{
	game->img.monster_t = mlx_load_png("assets/monster.png");
	if (!game->img.monster_t)
	{
		ft_putstr_fd(2, "Error loading monster.png\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	game->img.monster_i = mlx_texture_to_image(game->mlx, game->img.monster_t);
	if (!game->img.monster_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(game->mlx);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	load_textures_monsters(t_game *game)
{
	int	exit_code;

	exit_code = 0;
	exit_code = load_texture_monster(game);
	if (exit_code > 0)
		return (exit_code);
	else
	{
		mlx_resize_image(game->img.monster_i, BLOCK, BLOCK);
	}
	return (0);
}
