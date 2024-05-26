/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:49 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/26 19:43:47 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <pthread.h>
# include <fcntl.h>
# include "./../mlx42/include/MLX42/MLX42.h"
# include "./../libft/libft.h"

# ifndef BLOCK
#  define BLOCK 100
# endif
# ifndef BG
#  define BG 0xFFFFFF
# endif

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_images
{
	mlx_texture_t   *bbg_texture;
	mlx_image_t     *bbg_image;
	mlx_texture_t   *bg_texture;
	mlx_image_t     *bg_image;
	mlx_texture_t   *wall_texture;
	mlx_image_t     *wall_image;
	mlx_texture_t   *collctbl_texture;
	mlx_image_t     *collctbl_image;
	mlx_texture_t   *exit_texture;
	mlx_image_t     *exit_image;
	mlx_texture_t   *player_left_texture;
	mlx_image_t     *player_left_image;
	mlx_texture_t   *player_right_texture;
	mlx_image_t     *player_right_image;
	mlx_texture_t   *player_up_texture;
	mlx_image_t     *player_up_image;
	mlx_texture_t   *player_down_texture;
	mlx_image_t     *player_down_image;
}	t_images;

typedef struct s_game
{
	mlx_t           *mlx;
	char            *map;
	char            **map_array;
	t_point         size;
	t_point         player_pos;
	t_images        images;
}	t_game;

t_point	get_player_position(t_game *game);
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