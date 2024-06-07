/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:06:15 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 16:07:11 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	fill_mlx_pl(t_game *game)
{
	game->pl_l_t[0] = NULL;
	game->pl_r_t[0] = NULL;
	game->pl_u_t[0] = NULL;
	game->pl_d_t[0] = NULL;
	game->pl_l_i[0] = NULL;
	game->pl_r_i[0] = NULL;
	game->pl_u_i[0] = NULL;
	game->pl_d_i[0] = NULL;
	game->pl_l_t[1] = NULL;
	game->pl_r_t[1] = NULL;
	game->pl_u_t[1] = NULL;
	game->pl_d_t[1] = NULL;
	game->pl_l_i[1] = NULL;
	game->pl_r_i[1] = NULL;
	game->pl_u_i[1] = NULL;
	game->pl_d_i[1] = NULL;
	game->pl_l_t[2] = NULL;
	game->pl_r_t[2] = NULL;
	game->pl_u_t[2] = NULL;
	game->pl_d_t[2] = NULL;
	game->pl_l_i[2] = NULL;
	game->pl_r_i[2] = NULL;
	game->pl_u_i[2] = NULL;
	game->pl_d_i[2] = NULL;
}
