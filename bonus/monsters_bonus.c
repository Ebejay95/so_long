/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:48:15 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:04:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

void	m_render_move(t_game *g, t_monster monsters[MONSTER_MAX], int m_count)
{
	int			m_dex;
	t_monster	m;

	m_dex = 0;
	while (m_count > m_dex)
	{
		m = monsters[m_dex];
		mlx_image_to_window(g->mlx, g->m_i, m.np.x * BLOCK, m.np.y * BLOCK);
		if (g->map_array[m.p.y][m.p.x] != 'E')
			mlx_image_to_window(g->mlx, g->bg_i, m.p.x * BLOCK, m.p.y * BLOCK);
		else
		{
			mlx_image_to_window(g->mlx, g->bg_i, m.p.x * BLOCK, m.p.y * BLOCK);
			mlx_image_to_window(g->mlx, g->ex_i, m.p.x * BLOCK, m.p.y * BLOCK);
		}
		m_dex++;
	}
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
	int			m_dex;
	t_monster	*m;

	m_dex = 0;
	while (m_count > m_dex)
	{
		m = &monsters[m_dex];
		m->dire = get_move(g, m->p.x, m->p.y);
		m->np.x = m->p.x;
		m->np.y = m->p.y;
		if (m->dire == 0)
			m->np.y = m->p.y - 1;
		else if (m->dire == 1)
			m->np.x = m->p.x - 1;
		else if (m->dire == 2)
			m->np.y = m->p.y + 1;
		else if (m->dire == 3)
			m->np.x = m->p.x + 1;
		if (m->np.x == g->player_pos.x && m->np.y == g->player_pos.y)
			loose_exit(g);
		g->map_array[m->np.y][m->np.x] = 'M';
		if (m->p.y != m->np.y || m->p.x != m->np.x)
			g->map_array[m->p.y][m->p.x] = '0';
		m_dex++;
	}
}

void	monster_action(t_game *g)
{
	t_monster	monsters[MONSTER_MAX];
	int			y;
	int			x;
	int			m_dex;

	m_dex = 0;
	y = 0;
	while (ft_array_length(g->map_array) > y)
	{
		x = 0;
		while (g->map_array[y][x] != '\0')
		{
			if (g->map_array[y][x] == 'M')
			{
				monsters[m_dex].p.x = x;
				monsters[m_dex].p.y = y;
				m_dex++;
			}
			x++;
		}
		y++;
	}
	monsters_move(g, monsters, ft_array_strcchr(g->map_array, 'M'));
	m_render_move(g, monsters, ft_array_strcchr(g->map_array, 'M'));
}
