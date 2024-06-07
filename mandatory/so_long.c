/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:01 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 19:51:55 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

void	loose_exit(t_game *game)
{
	mlx_terminate(game->mlx);
	free(game->map);
	ft_array_free(game->map_array);
	ft_printf("\033[31mYou lost :/\n\033[0m");
	exit(EXIT_SUCCESS);
}

void	win_exit(t_game *game)
{
	mlx_terminate(game->mlx);
	free(game->map);
	ft_array_free(game->map_array);
	ft_printf("\033[32mYou won :)   score: %i\n\033[0m", game->c);
	exit(EXIT_SUCCESS);
}

void	initial_map_paint(t_game *game)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->map[index] != '\n')
			{
				print_texture(game, index, x, y);
				x++;
			}
			index++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		exit_code;

	exit_code = initialize(&game, argc, argv);
	if (exit_code > 0)
		return (exit_code);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	loose_exit(&game);
	return (exit_code);
}
