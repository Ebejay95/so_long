/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:52:40 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 13:00:02 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	animate_left(t_game *g, int i)
{
	if (i == g->active_frame)
	{
		if (g->pl_l_i[i])
		{
			if (g->pl_l_i[i]->instances != NULL)
			{
				g->pl_l_i[i]->instances[0].enabled = 1;
			}
		}
	}
	else
	{
		if (g->pl_l_i[i]->instances != NULL)
			g->pl_l_i[i]->instances[0].enabled = 0;
	}
}

void	animate_right(t_game *g, int i)
{
	if (i == g->active_frame)
	{
		if (g->pl_r_i[i]->instances != NULL)
		{
			g->pl_r_i[i]->instances[0].enabled = 1;
		}
	}
	else
	{
		if (g->pl_r_i[i]->instances != NULL)
			g->pl_r_i[i]->instances[0].enabled = 0;
	}
}

void	animate_up(t_game *g, int i)
{
	if (i == g->active_frame)
	{
		if (g->pl_u_i[i]->instances != NULL)
		{
			g->pl_u_i[i]->instances[0].enabled = 1;
		}
	}
	else
	{
		if (g->pl_u_i[i]->instances != NULL)
			g->pl_u_i[i]->instances[0].enabled = 0;
	}
}

void	animate_down(t_game *g, int i)
{
	if (i == g->active_frame)
	{
		if (g->pl_d_i[i]->instances != NULL)
		{
			g->pl_d_i[i]->instances[0].enabled = 1;
		}
	}
	else
	{
		if (g->pl_d_i[i]->instances != NULL)
			g->pl_d_i[i]->instances[0].enabled = 0;
	}
}

void	animate(t_game *g)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (g->pl_l_i[i] != NULL)
		{
			if (g->direction == 'l' && g->isinited)
				animate_left(g, i);
			else if (g->direction == 'r' && g->isinited)
				animate_right(g, i);
			else if (g->direction == 'u' && g->isinited)
				animate_up(g, i);
			else if (g->direction == 'd' && g->isinited)
				animate_down(g, i);
		}
		i++;
	}
}
