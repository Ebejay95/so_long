/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:56:53 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:58:26 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

void	fill_mlx(t_game *game)
{
	game->score = NULL;
	game->bbg_t = NULL;
	game->bbg_i = NULL;
	game->bg_t = NULL;
	game->bg_i = NULL;
	game->wall_t = NULL;
	game->wall_i = NULL;
	game->cllctbl_t = NULL;
	game->cllctbl_i = NULL;
	game->exit_t = NULL;
	game->ex_i = NULL;
	game->monster_t = NULL;
	fill_mlx_pl(game);
}

void	fill_struct(t_game *game)
{
	game->c = 0;
	game->isinited = 0;
	game->state = 0;
	game->active_frame = 0;
	game->monster_move_count = 0;
	game->frame_count = 0;
	game->direction = 'l';
	game->size = get_mapsize(game->map);
	game->player_pos = get_player_position(game);
	game->map_lines = ft_count_words(game->map, '\n');
	game->map_array = ft_split(game->map, '\n');
	game->winwidth = game->size.x * BLOCK;
	game->winheight = game->size.y * BLOCK;
	game->mlx = mlx_init(game->winwidth, game->winheight, "so_long", false);
	fill_mlx(game);
}

int	initialize(t_game *game, int argc, char **argv)
{
	if (validate_input(argc, argv) > 0)
		return (EXIT_FAILURE);
	if (validate_map(game, argv[1]) > 0)
		return (free(game->map), EXIT_FAILURE);
	fill_struct(game);
	if (!game->mlx)
		return (ft_putstr_fd(2, (char *)mlx_strerror(mlx_errno)), EXIT_FAILURE);
	if (load_textures(game) > 0)
		return (free(game->map), EXIT_FAILURE);
	initial_map_paint(game);
	start_music();
	sleep(2);
	game->music.run_music = true;
	game->isinited = 1;
	return (0);
}
