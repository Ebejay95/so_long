/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:49 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/20 11:39:04 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "./../mlx42/include/MLX42/MLX42.h"
# include "./../libft/libft.h"

# ifndef BLOCK
#  define BLOCK 50
# endif
# ifndef BG
#  define BG 0xFFFFFF
# endif

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int		validate_player_exit(size_t *count, char *map);
void	flood(char **tab, t_point size);
int		validate_map_chars(char *map);
int		validate_map_rect(char *map);
int		validate_map_walls(char *map);
char	*get_file_content(char *filename);
t_point	get_mapsize(char *map);
int		validate_map(char *map);
int		validate_input(int argc, char **argv);
int		validate_map_content(char *map);
#endif