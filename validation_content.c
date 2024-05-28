/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:09:12 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/28 22:30:45 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	flood_one(char *ref, int *check, char *work)
{
	if (ft_strchr(ref, *work))
	{
		*work = 'X';
		(*check)--;
	}
}

int	check_xy_nexts(char **tab, int ydex, int xdex, t_point size)
{
	int		check;
	char	*ref;

	check = 0;
	ref = ft_strdup("0CE");
	if (ydex != 0)
		flood_one(ref, &check, &tab[ydex - 1][xdex]);
	if (xdex != 0)
		flood_one(ref, &check, &tab[ydex][xdex - 1]);
	if (ydex != (size.y - 1))
		flood_one(ref, &check, &tab[ydex + 1][xdex]);
	if (xdex != (size.x - 1))
		flood_one(ref, &check, &tab[ydex][xdex + 1]);
	free(ref);
	return (check);
}

void	flood(char **tab, t_point size)
{
	int		check;
	int		xdex;
	int		ydex;

	check = -1;
	while (check < 0)
	{
		check = 0;
		ydex = 0;
		while (ydex < size.y)
		{
			xdex = 0;
			while (xdex < size.x)
			{
				if ('X' == tab[ydex][xdex])
					check = check + check_xy_nexts(tab, ydex, xdex, size);
				xdex++;
			}
			ydex++;
		}
	}
}

int	validate_map_content(char *map)
{
	char	*valmap;
	t_point	size;
	char	**vmap;
	size_t	lines;

	size = get_mapsize(map);
	valmap = ft_strdup(map);
	valmap = ft_strreplace(valmap, "P", "X");
	vmap = ft_split(valmap, '\n');
	flood(vmap, size);
	lines = ft_count_words(valmap, '\n');
	lines--;
	while (lines)
	{
		if (ft_strchr(vmap[lines], 'E') || ft_strchr(vmap[lines], 'C'))
		{
			ft_putstr_fd(2, "map content must be playable\n");
			return (1);
		}
		lines--;
	}
	return (0);
}

int	check_top_bottom(char *line)
{
	size_t	linelen;
	size_t	refcount;

	linelen = ft_strlen(line);
	refcount = 0;
	while (*line != '\0')
	{
		if (*line == '1')
			refcount++;
		line++;
	}
	if (linelen != refcount)
		return (1);
	return (0);
}
