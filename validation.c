/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:07:23 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 12:08:57 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	validate_player_exit(size_t *count, char *map)
{
	if (ft_strcchr(map, 'E') < 1)
	{
		ft_putstr_fd(2, "no exit in map\n");
		return (1);
	}
	if (ft_strcchr(map, 'E') > 1)
	{
		ft_putstr_fd(2, "to many exits in map\n");
		return (1);
	}
	if (ft_strcchr(map, 'P') < 1)
	{
		ft_putstr_fd(2, "no player in map\n");
		return (1);
	}
	if (ft_strcchr(map, 'P') > 1)
	{
		ft_putstr_fd(2, "to many player in map\n");
		return (1);
	}
	*count = *count + 2;
	return (0);
}

int	validate_map_chars(char *map)
{
	size_t	count;

	count = 0;
	if (validate_player_exit(&count, map) > 0)
		return (1);
	count = count + ft_strcchr(map, 'C');
	if (ft_strcchr(map, 'C') < 1)
	{
		ft_putstr_fd(2, "no collectable in map\n");
		return (1);
	}
	count = count + ft_strcchr(map, '\n');
	count = count + ft_strcchr(map, 'M');
	if (ft_strcchr(map, 'M') > MONSTER_MAX)
		return (ft_putstr_fd(2, "to many monsters\n"), 1);
	count = count + ft_strcchr(map, '0');
	count = count + ft_strcchr(map, '1');
	if (count != ft_strlen(map))
	{
		ft_putstr_fd(2, "invalid char found\n");
		return (1);
	}
	return (0);
}

int	validate_map_rect(char *map)
{
	size_t	i;
	size_t	linelen;
	char	**maplines;
	size_t	linecount;

	if (ft_strstr(map, "\n\n"))
		return (ft_putstr_fd(2, "map is not a rect\n"), 1);
	i = 0;
	linelen = 0;
	linecount = ft_count_words(map, '\n');
	maplines = ft_split(map, '\n');
	while (i < linecount)
	{
		if (linelen == 0)
			linelen = ft_strlen(maplines[i]);
		if (linelen != ft_strlen(maplines[i]))
		{
			ft_putstr_fd(2, "map is not a rect\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	validate_map_walls(char *map)
{
	size_t	i;
	size_t	linelen;
	char	**maplines;
	size_t	linecount;

	i = 0;
	linecount = ft_count_words(map, '\n');
	maplines = ft_split(map, '\n');
	while (i < linecount)
	{
		linelen = ft_strlen(maplines[i]);
		if (maplines[i][0] != '1' || maplines[i][linelen - 1] != '1')
		{
			ft_putstr_fd(2, "map is not closed\n");
			return (1);
		}
		if (i == 0 || i == linecount - 1)
		{
			if (check_top_bottom(maplines[i]) == 1)
				return (ft_putstr_fd(2, "map is not closed\n"), 1);
		}
		i++;
	}
	return (0);
}
