/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_monster_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:25:56 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:04:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

int	load_texture_monster(t_game *game)
{
	game->monster_t = mlx_load_png("assets/monster.png");
	if (!game->monster_t)
	{
		ft_putstr_fd(2, "Error loading monster.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->m_i = mlx_texture_to_image(game->mlx, game->monster_t);
	if (!game->m_i)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		terminate_mlx(game);
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
		mlx_resize_image(game->m_i, BLOCK, BLOCK);
	}
	return (0);
}
