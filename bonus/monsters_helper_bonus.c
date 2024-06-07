/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters_helper_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:33:53 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:04:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

int	can_move(char c)
{
	if (c == '0' || c == 'P')
		return (1);
	return (0);
}

int	monster_stuck(char n[4])
{
	if (can_move(n[0]) || can_move(n[1]) || can_move(n[2]) || can_move(n[3]))
		return (1);
	return (0);
}
