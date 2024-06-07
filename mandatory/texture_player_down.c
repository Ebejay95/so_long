/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_player_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:33:55 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 19:50:17 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	load_texture_player_down(t_game *game)
{
	game->pl_d_t = mlx_load_png("assets/player_down_0.png");
	if (!game->pl_d_t)
	{
		ft_putstr_fd(2, "Error loading player_down_0.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->pl_d_i = mlx_texture_to_image(game->mlx, game->pl_d_t);
	return (0);
}

int	load_image_player_down(t_game *game)
{
	game->pl_d_i = mlx_texture_to_image(game->mlx, game->pl_d_t);
	if (!game->pl_d_i)
	{
		ft_putstr_fd(2, "Error loading player_down_0.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	mlx_resize_image(game->pl_d_i, BLOCK, BLOCK);
	return (0);
}
