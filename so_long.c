/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:01 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/20 11:58:02 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

// int	main(int argc, char **argv)
// {
// 	char			*map;
// 	t_point			size;
// 	mlx_t			*mlx;
// 	mlx_image_t*	image;
// 	if (validate_input(argc, argv) > 0)
// 		return (EXIT_FAILURE);
// 	map = get_file_content(argv[1]);
// 	if (validate_map(map) > 0)
// 	{
// 		free(map);
// 		return (EXIT_FAILURE);
// 	}
// 	size = get_mapsize(map);
// 	if (!(mlx = mlx_init(size.x * BLOCK, size.y * BLOCK, "so_long", true)))
// 	{
// 		ft_putstr_fd(2,(char *) mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		ft_putstr_fd(2,(char *) mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	mlx_image_fill_color(image, BG);
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		ft_putstr_fd(2,(char *) mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
int	main(int argc, char **argv)
{
	char			*map;
	t_point			size;
	mlx_t			*mlx;
	mlx_texture_t	*wall_texture;
	mlx_image_t		*wall_image;
	mlx_texture_t	*bg_texture;
	mlx_image_t		*bg_image;
	mlx_texture_t	*collctbl_texture;
	mlx_image_t		*collctbl_image;
	mlx_texture_t	*exit_texture;
	mlx_image_t		*exit_image;
	mlx_texture_t	*player_texture;
	mlx_image_t		*player_image;
	int				window_width;
	int				window_height;
	int				index;
	int				y;
	int				x;

	if (validate_input(argc, argv) > 0)
		return (EXIT_FAILURE);
	map = get_file_content(argv[1]);
	if (validate_map(map) > 0)
	{
		free(map);
		return (EXIT_FAILURE);
	}
	size = get_mapsize(map);
	window_width = size.x * BLOCK;
	window_height = size.y * BLOCK;
	mlx = mlx_init(window_width, window_height, "so_long", false);
	if (!mlx)
	{
		ft_putstr_fd(2, (char *)mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	bg_texture = mlx_load_png("assets/background.png");
	if (!bg_texture)
	{
		ft_putstr_fd(2, "Error loading background.png\n");
		mlx_close_window(mlx);
		return (EXIT_FAILURE);
	}
	bg_image = mlx_texture_to_image(mlx, bg_texture);
	if (!bg_image)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(mlx);
		return (EXIT_FAILURE);
	}
	wall_texture = mlx_load_png("assets/wall.png");
	if (!wall_texture)
	{
		ft_putstr_fd(2, "Error loading wall.png\n");
		mlx_close_window(mlx);
		return (EXIT_FAILURE);
	}
	wall_image = mlx_texture_to_image(mlx, wall_texture);
	if (!wall_image)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(mlx);
		return (EXIT_FAILURE);
	}
	collctbl_texture = mlx_load_png("assets/collectable.png");
	if (!collctbl_texture)
	{
		ft_putstr_fd(2, "Error loading collectable.png\n");
		mlx_close_window(mlx);
		return (EXIT_FAILURE);
	}
	collctbl_image = mlx_texture_to_image(mlx, collctbl_texture);
	if (!collctbl_image)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(mlx);
		return (EXIT_FAILURE);
	}
	exit_texture = mlx_load_png("assets/exit.png");
	if (!exit_texture)
	{
		ft_putstr_fd(2, "Error loading exit.png\n");
		mlx_close_window(mlx);
		return (EXIT_FAILURE);
	}
	exit_image = mlx_texture_to_image(mlx, exit_texture);
	if (!exit_image)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(mlx);
		return (EXIT_FAILURE);
	}
	player_texture = mlx_load_png("assets/player.png");
	if (!player_texture)
	{
		ft_putstr_fd(2, "Error loading player.png\n");
		mlx_close_window(mlx);
		return (EXIT_FAILURE);
	}
	player_image = mlx_texture_to_image(mlx, player_texture);
	if (!player_image)
	{
		ft_putstr_fd(2, "Error creating image from texture\n");
		mlx_close_window(mlx);
		return (EXIT_FAILURE);
	}
	mlx_resize_image(bg_image, window_width, window_height);
	mlx_resize_image(wall_image, BLOCK, BLOCK);
	mlx_resize_image(collctbl_image, BLOCK, BLOCK);
	mlx_resize_image(exit_image, BLOCK, BLOCK);
	mlx_resize_image(player_image, BLOCK, BLOCK);
	mlx_image_to_window(mlx, bg_image, 0, 0);
	index = 0;
	y = 0;
	x = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (map[index] == '1')
			{
				mlx_image_to_window(mlx, wall_image, x * BLOCK, y * BLOCK);
			}
			if (map[index] == 'C')
			{
				mlx_image_to_window(mlx, collctbl_image, x * BLOCK, y * BLOCK);
			}
			if (map[index] == 'E')
			{
				mlx_image_to_window(mlx, exit_image, x * BLOCK, y * BLOCK);
			}
			if (map[index] == 'P')
			{
				mlx_image_to_window(mlx, player_image, x * BLOCK, y * BLOCK);
			}
			index++;
			x++;
		}
		index++;
		y++;
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(map);
	return (EXIT_SUCCESS);
}
