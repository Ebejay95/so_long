/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:05:15 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:04:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

void	play_sound(pthread_t thread, void *(*play)(void *))
{
	pthread_create(&thread, NULL, play, NULL);
	pthread_join(thread, NULL);
}
