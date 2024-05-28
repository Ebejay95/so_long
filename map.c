/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:43:08 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/28 22:55:47 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

char	*get_file_content(char *filename)
{
	char	*cnt;
	char	*tmp;
	char	*line;
	int		fd;

	cnt = ft_strdup("");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(2, "file cannot be read from\n"), cnt);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_strjoin(cnt, line);
		if (tmp == NULL)
		{
			free(line);
			return (close(fd), cnt);
		}
		free(cnt);
		cnt = tmp;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), cnt);
}

t_point	get_mapsize(char *map)
{
	size_t	i;
	size_t	linelen;
	char	**maplines;
	size_t	linecount;
	t_point	size;

	i = 0;
	linelen = 0;
	linecount = ft_count_words(map, '\n');
	maplines = ft_split(map, '\n');
	while (i < linecount)
	{
		if (linelen == 0)
			linelen = ft_strlen(maplines[i]);
		if (linelen != ft_strlen(maplines[i]))
			linelen = ft_strlen(maplines[i]);
		i++;
	}
	size.x = linelen;
	size.y = linecount;
	return (size);
}

int	validate_map(t_game *game, char *map)
{
	game->map = get_file_content(map);
	game->map = ft_strtrim(game->map, "\n");
	if (validate_map_chars(game->map) > 0)
		return (1);
	if (validate_map_rect(game->map) > 0)
		return (1);
	if (validate_map_walls(game->map) > 0)
		return (1);
	if (validate_map_content(game->map) > 0)
		return (1);
	return (0);
}
