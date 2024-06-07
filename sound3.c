/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:05:15 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 16:05:37 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	play_sound(pthread_t thread, void *(*play)(void *))
{
	pthread_create(&thread, NULL, play, NULL);
	pthread_join(thread, NULL);
}
