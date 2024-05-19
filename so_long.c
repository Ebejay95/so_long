/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:35:01 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/18 15:39:48 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void cleanup(mlx_t *mlx_ptr)
{
    if (mlx_ptr)
        mlx_terminate(mlx_ptr);
}

int main(void)
{
    mlx_t *mlx_ptr;

    mlx_ptr = mlx_init(600, 400, "hi :)", true);
    if (!mlx_ptr)
    {
        ft_printf("Failed to initialize MLX\n");
        return (1);
    }

    ft_printf("MLX pointer: %p\n", mlx_ptr);

    // Event loop goes here (if needed)

    cleanup(mlx_ptr);
    return (0);
}