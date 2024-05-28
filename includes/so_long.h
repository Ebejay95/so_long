/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:49 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/29 00:17:17 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <pthread.h>
# include <fcntl.h>
# include "./../mlx42/include/MLX42/MLX42.h"
# include "./../libft/libft.h"

# ifndef BLOCK
#  define BLOCK 40
# endif
# ifndef BG
#  define BG 0xFFFFFF
# endif

typedef struct s_music
{
	int	run_music;
}	t_music;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	mlx_texture_t	*bbg_t;
	mlx_image_t		*bbg_i;
	mlx_texture_t	*bg_t;
	mlx_image_t		*bg_i;
	mlx_texture_t	*wall_t;
	mlx_image_t		*wall_i;
	mlx_texture_t	*cllctbl_t;
	mlx_image_t		*cllctbl_i;
	mlx_texture_t	*exit_t;
	mlx_image_t		*exit_i;
	mlx_texture_t	*plyr_l_t;
	mlx_image_t		*plyr_l_i;
	mlx_texture_t	*plyr_r_t;
	mlx_image_t		*plyr_r_i;
	mlx_texture_t	*plyr_u_t;
	mlx_image_t		*plyr_u_i;
	mlx_texture_t	*plyr_d_t;
	mlx_image_t		*plyr_d_i;
}	t_img;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*score;
	int				winwidth;
	int				winheight;
	int				count;
	char			*map;
	char			**map_array;
	t_point			size;
	t_point			player_pos;
	t_img			img;
	t_music			music;
	pthread_t		bg_music_thrt;
	pthread_t		sound_thread;
	pthread_t		exit_sound_thread;
	pthread_t		collect_sound_thread;
	pthread_t		win_sound_thread;
	pthread_t		loose_sound_thread;
}	t_game;

int		check_top_bottom(char *line);
t_point	get_player_position(t_game *game);
int		validate_player_exit(size_t *count, char *map);
void	flood(char **tab, t_point size);
int		validate_map_chars(char *map);
int		validate_map_rect(char *map);
int		validate_map_walls(char *map);
char	*get_file_content(char *filename);
t_point	get_mapsize(char *map);
int		validate_map(t_game *game, char *map);
int		validate_input(int argc, char **argv);
int		validate_map_content(char *map);
int		load_textures(t_game *game);
int		load_textures_items(t_game *game);
int		load_textures_map(t_game *game);
int		load_textures_player(t_game *game);
void	print_texture(t_game *game, int index, int x, int y);

void	play_sound(pthread_t thread, void *(*play)(void *));
void	*player_move_sound(void *arg);
void	*win_sound(void *arg);
void	*loose_sound(void *arg);
void	*exit_sound(void *arg);
void	*collect_sound(void *arg);
void	*start_music(void);
void	*bg_music(void *arg);
#endif