/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:06:15 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 19:47:08 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

void	fill_mlx_pl(t_game *game)
{
	game->pl_l_t = NULL;
	game->pl_r_t = NULL;
	game->pl_u_t = NULL;
	game->pl_d_t = NULL;
}
