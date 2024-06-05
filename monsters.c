/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:48:15 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/05 20:37:49 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	m_render_move(t_game *g, t_monster monsters[MONSTER_MAX], int m_count)
{
	int	m_dex;

	m_dex = 0;
	while (m_count > m_dex)
	{
		mlx_image_to_window(g->mlx, g->img.monster_i, monsters[m_dex].newpos.x * BLOCK, monsters[m_dex].newpos.y * BLOCK);
		if (g->map_array[monsters[m_dex].pos.y][monsters[m_dex].pos.x] != 'E')
			mlx_image_to_window(g->mlx, g->img.bg_i, monsters[m_dex].pos.x * BLOCK, monsters[m_dex].pos.y * BLOCK);
		else
		{
			mlx_image_to_window(g->mlx, g->img.bg_i, monsters[m_dex].pos.x * BLOCK, monsters[m_dex].pos.y * BLOCK);
			mlx_image_to_window(g->mlx, g->img.exit_i, monsters[m_dex].pos.x * BLOCK, monsters[m_dex].pos.y * BLOCK);
		}
		m_dex++;
	}
}

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

int	get_move(t_game *g, int x, int y)
{
	char	nexts[4];
	int		random;

	nexts[0] = g->map_array[y - 1][x];
	nexts[1] = g->map_array[y][x - 1];
	nexts[2] = g->map_array[y + 1][x];
	nexts[3] = g->map_array[y][x + 1];
	if (monster_stuck(nexts))
	{
		srand(time(NULL));
		random = rand() % 4;
		while (!can_move(nexts[random]))
		{
			if (!can_move(nexts[random]))
				random = rand() % 4;
		}
		return (random);
	}
	return (-1);
}

void	monsters_move(t_game *g, t_monster monsters[MONSTER_MAX], int m_count)
{
	int	m_dex;

	m_dex = 0;
	while (m_count > m_dex)
	{
		monsters[m_dex].dire = get_move(g, monsters[m_dex].pos.x, monsters[m_dex].pos.y);
		monsters[m_dex].newpos.x = monsters[m_dex].pos.x;
		monsters[m_dex].newpos.y = monsters[m_dex].pos.y;
		if (monsters[m_dex].dire == 0)
			monsters[m_dex].newpos.y = monsters[m_dex].pos.y - 1;
		else if (monsters[m_dex].dire == 1)
			monsters[m_dex].newpos.x = monsters[m_dex].pos.x - 1;
		else if (monsters[m_dex].dire == 2)
			monsters[m_dex].newpos.y = monsters[m_dex].pos.y + 1;
		else if (monsters[m_dex].dire == 3)
			monsters[m_dex].newpos.x = monsters[m_dex].pos.x + 1;
		if (g->map_array[monsters[m_dex].newpos.y][monsters[m_dex].newpos.x] == 'P')
			loose_exit(g);
		g->map_array[monsters[m_dex].newpos.y][monsters[m_dex].newpos.x] = 'M';
		if (monsters[m_dex].pos.y != monsters[m_dex].newpos.y || monsters[m_dex].pos.x != monsters[m_dex].newpos.x)
			g->map_array[monsters[m_dex].pos.y][monsters[m_dex].pos.x] = '0';
		m_dex++;
	}
}

void	monster_action(t_game *g)
{
	t_monster	monsters[MONSTER_MAX];
	int			length;
	int			y;
	int			x;
	int			m_count;
	int			m_dex;

	m_dex = 0;
	y = 0;
	m_count = ft_array_strcchr(g->map_array, 'M');
	length = ft_array_length(g->map_array);
	while (length > y)
	{
		x = 0;
		while (g->map_array[y][x] != '\0')
		{
			if (g->map_array[y][x] == 'M')
			{
				monsters[m_dex].pos.x = x;
				monsters[m_dex].pos.y = y;
				m_dex++;
			}
			x++;
		}
		y++;
	}
	monsters_move(g, monsters, m_count);
	m_render_move(g, monsters, m_count);
}
