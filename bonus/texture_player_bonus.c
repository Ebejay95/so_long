/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:03:32 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:04:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

int	load_textures_player(t_game *game)
{
	int	exit_code;

	exit_code = 0;
	if (exit_code == 0)
		exit_code = load_texture_player_left(game);
	if (exit_code == 0)
		exit_code = load_texture_player_right(game);
	if (exit_code == 0)
		exit_code = load_texture_player_up(game);
	if (exit_code == 0)
		exit_code = load_texture_player_down(game);
	if (exit_code == 0)
		exit_code = load_image_player_left(game);
	if (exit_code == 0)
		exit_code = load_image_player_right(game);
	if (exit_code == 0)
		exit_code = load_image_player_up(game);
	if (exit_code == 0)
		exit_code = load_image_player_down(game);
	return (exit_code);
}
