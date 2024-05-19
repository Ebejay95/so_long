/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:01 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/19 19:44:44 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

//int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
//{
//    return (r << 24 | g << 16 | b << 8 | a);
//}
//
//void ft_randomize(void* param)
//{
//	(void)param;
//	for (uint32_t i = 0; i < image->width; ++i)
//	{
//		for (uint32_t y = 0; y < image->height; ++y)
//		{
//			uint32_t color = ft_pixel(
//				rand() % 0xFF,
//				rand() % 0xFF,
//				rand() % 0xFF,
//				rand() % 0xFF 
//			);
//			mlx_put_pixel(image, i, y, color);
//		}
//	}
//}
//
//void ft_hook(void* param)
//{
//	mlx_t* mlx = param;
//
//	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
//		mlx_close_window(mlx);
//	if (mlx_is_key_down(mlx, MLX_KEY_UP))
//		image->instances[0].y -= 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
//		image->instances[0].y += 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
//		image->instances[0].x -= 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
//		image->instances[0].x += 5;
//}
//mlx_t* mlx;
//if (!(mlx = mlx_init(WIDTH, HEIGHT, "so_long", true)))
//{
//	ft_putstr_fd(2,(char *) mlx_strerror(mlx_errno));
//	return(EXIT_FAILURE);
//}
//if (!(image = mlx_new_image(mlx, 128, 128)))
//{
//	mlx_close_window(mlx);
//	ft_putstr_fd(2,(char *) mlx_strerror(mlx_errno));
//	return(EXIT_FAILURE);
//}
//if (mlx_image_to_window(mlx, image, 0, 0) == -1)
//{
//	mlx_close_window(mlx);
//	ft_putstr_fd(2,(char *) mlx_strerror(mlx_errno));
//	return(EXIT_FAILURE);
//}
//
//mlx_loop_hook(mlx, ft_randomize, mlx);
//mlx_loop_hook(mlx, ft_hook, mlx);
//
//mlx_loop(mlx);
//mlx_terminate(mlx);
int	main(int argc, char **argv)
{
	char	*map;

	if (validate_input(argc, argv) > 0)
		return (EXIT_FAILURE);
	map = get_file_content(argv[1]);
	if (validate_map(map) > 0)
	{
		free(map);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
