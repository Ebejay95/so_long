/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:40:38 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 19:33:18 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long.h"

int	validate_input(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd(2, "./so_long [map.ber]\n");
		return (1);
	}
	if (!ft_strendswith(argv[1], ".ber"))
	{
		ft_putstr_fd(2, "map must be .ber file\n");
		return (1);
	}
	if (access(argv[1], R_OK) != 0)
	{
		ft_putstr_fd(2, "cannot read from map file\n");
		return (1);
	}
	return (0);
}

void	wall_val_free(char **maplines, size_t linecount)
{
	ft_array_l_free(maplines, linecount);
	ft_putstr_fd(2, "map is not closed\n");
}

void	mcontent_free(char *vm, char *vmt, char **vmap, size_t linecount)
{
	ft_putstr_fd(2, "map content must be playable\n");
	free(vmt);
	free(vm);
	ft_array_l_free(vmap, linecount);
}
