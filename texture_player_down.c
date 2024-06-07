/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_player_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:33:55 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 15:54:49 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	load_texture_player_down(t_game *game)
{
	game->pl_d_t[0] = mlx_load_png("assets/player_down_0.png");
	if (!game->pl_d_t[0])
	{
		ft_putstr_fd(2, "Error loading player_down_0.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->pl_d_t[1] = mlx_load_png("assets/player_down_1.png");
	if (!game->pl_d_t[1])
	{
		ft_putstr_fd(2, "Error loading player_down_1.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->pl_d_t[2] = mlx_load_png("assets/player_down_2.png");
	if (!game->pl_d_t[2])
	{
		ft_putstr_fd(2, "Error loading player_down_2.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->pl_d_i[0] = mlx_texture_to_image(game->mlx, game->pl_d_t[0]);
	game->pl_d_i[1] = mlx_texture_to_image(game->mlx, game->pl_d_t[1]);
	game->pl_d_i[2] = mlx_texture_to_image(game->mlx, game->pl_d_t[2]);
	return (0);
}

int	load_image_player_down(t_game *game)
{
	game->pl_d_i[0] = mlx_texture_to_image(game->mlx, game->pl_d_t[0]);
	if (!game->pl_d_i[0])
	{
		ft_putstr_fd(2, "Error loading player_down_0.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->pl_d_i[1] = mlx_texture_to_image(game->mlx, game->pl_d_t[1]);
	if (!game->pl_d_i[1])
	{
		ft_putstr_fd(2, "Error loading player_down_1.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	game->pl_d_i[2] = mlx_texture_to_image(game->mlx, game->pl_d_t[2]);
	if (!game->pl_d_i[2])
	{
		ft_putstr_fd(2, "Error loading player_down_2.png\n");
		terminate_mlx(game);
		return (EXIT_FAILURE);
	}
	mlx_resize_image(game->pl_d_i[0], BLOCK, BLOCK);
	mlx_resize_image(game->pl_d_i[1], BLOCK, BLOCK);
	mlx_resize_image(game->pl_d_i[2], BLOCK, BLOCK);
	return (0);
}
