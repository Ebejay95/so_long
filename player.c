/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:24:15 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/20 18:18:08 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

t_point	get_player_position(t_game *game)
{
	t_point	position;
	int		index;

	position.y = 0;
	position.x = 0;
	index = 0;
	while(game->map[index])
	{
		if (game->map[index] == 'P')
		{
			position.y = index / (game->size.x + 1);
			position.x = index % (game->size.x + 1);
			break ;
		}
		index++;
	}
	return (position);
}