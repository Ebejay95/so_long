/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:49 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 16:07:32 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <pthread.h>
# include <fcntl.h>
# include <signal.h>
# include "./../mlx42/include/MLX42/MLX42.h"
# include "./../libft/libft.h"

# ifndef BLOCK
#  define BLOCK 60
# endif
# ifndef MONSTER_MAX
#  define MONSTER_MAX 10
# endif
# ifndef BG
#  define BG 0xFFFFFF
# endif

typedef struct s_music
{
	int		run_music;
	int		bg_sec;
	pid_t	music_pid;
}	t_music;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_monster
{
	int		dire;
	t_point	p;
	t_point	np;
}	t_monster;

typedef struct s_game
{
	mlx_t			*mlx;
	int				state;
	int				winwidth;
	int				winheight;
	int				c;
	int				isinited;
	int				frame_count;
	int				active_frame;
	int				monster_move_count;
	char			*map;
	char			**map_array;
	t_point			size;
	t_point			player_pos;
	int				new_x;
	int				new_y;
	char			direction;
	t_music			music;
	int				frame_count_buffer;
	pthread_t		bg_music_thrt;
	pthread_t		sound_thread;
	pthread_t		exit_sound_thread;
	pthread_t		exitny_sound_thread;
	pthread_t		collect_sound_thread;
	pthread_t		win_sound_thread;
	pthread_t		loose_sound_thread;
	mlx_image_t		*score;
	mlx_texture_t	*bbg_t;
	mlx_image_t		*bbg_i;
	mlx_texture_t	*bg_t;
	mlx_image_t		*bg_i;
	mlx_texture_t	*wall_t;
	mlx_image_t		*wall_i;
	mlx_texture_t	*cllctbl_t;
	mlx_image_t		*cllctbl_i;
	mlx_texture_t	*exit_t;
	mlx_image_t		*ex_i;
	mlx_texture_t	*pl_l_t[3];
	mlx_texture_t	*pl_r_t[3];
	mlx_texture_t	*pl_u_t[3];
	mlx_texture_t	*pl_d_t[3];
	mlx_image_t		*pl_l_i[3];
	mlx_image_t		*pl_r_i[3];
	mlx_image_t		*pl_u_i[3];
	mlx_image_t		*pl_d_i[3];
	mlx_texture_t	*monster_t;
	mlx_image_t		*m_i;
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
void	update_player(t_game *g);
void	handlevert_moves(t_game *game, mlx_key_data_t keydata, int *moved);
void	handlehor_moves(t_game *game, mlx_key_data_t keydata, int *moved);
void	retireve_key_input(t_game *g, mlx_key_data_t keydata);
int		field_handler(t_game *g);
void	key_hook(mlx_key_data_t keydata, void *param);
void	win_exit(t_game *game);
void	loose_exit(t_game *game);
char	move_player(t_game *g, mlx_key_data_t keydata);
int		initialize(t_game *game, int argc, char **argv);
void	initial_map_paint(t_game *game);
void	terminate_mlx(t_game *game);
void	animate(t_game *g);
void	load_player_frames(t_game *game, int x, int y);
void	monster_action(t_game *game);
int		load_textures_monsters(t_game *game);
void	play_sound(pthread_t thread, void *(*play)(void *));
void	*player_move_sound(void *arg);
void	*win_sound(void *arg);
void	*loose_sound(void *arg);
void	*exit_sound(void *arg);
void	*exitny_sound(void *arg);
void	*collect_sound(void *arg);
void	*start_music(void);
void	*bg_music(void *arg);
int		can_move(char c);
int		monster_stuck(char n[4]);
void	load_pl_left(t_game *g, int x, int y, int i);
void	load_pl_right(t_game *g, int x, int y, int i);
void	load_pl_up(t_game *g, int x, int y, int i);
void	load_pl_down(t_game *g, int x, int y, int i);
void	animate(t_game *g);
int		load_texture_player_left(t_game *g);
int		load_texture_player_right(t_game *g);
int		load_texture_player_up(t_game *g);
int		load_texture_player_down(t_game *g);
int		load_image_player_left(t_game *g);
int		load_image_player_right(t_game *g);
int		load_image_player_up(t_game *g);
int		load_image_player_down(t_game *g);
void	fill_mlx_pl(t_game *game);
#endif