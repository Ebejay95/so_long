/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:31:21 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/29 00:08:41 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	*player_move_sound(void *arg)
{
	(void)arg;
	if (fork() == 0)
	{
		execlp("afplay", "afplay", "-v", "0.6", "assets/m.mp3", (char *) NULL);
		_exit(1);
	}
	return (NULL);
}

void	*win_sound(void *arg)
{
	(void)arg;
	if (fork() == 0)
	{
		execlp("afplay", "afplay", "assets/win.mp3", (char *) NULL);
		_exit(1);
	}
	return (NULL);
}

void	*loose_sound(void *arg)
{
	(void)arg;
	if (fork() == 0)
	{
		execlp("afplay", "afplay", "assets/loose.mp3", (char *) NULL);
		_exit(1);
	}
	return (NULL);
}

void	*exit_sound(void *arg)
{
	(void)arg;
	if (fork() == 0)
	{
		execlp("afplay", "afplay", "assets/exit.mp3", (char *) NULL);
		_exit(1);
	}
	return (NULL);
}

void	*collect_sound(void *arg)
{
	(void)arg;
	if (fork() == 0)
	{
		execlp("afplay", "afplay", "assets/collectable.mp3", (char *) NULL);
		_exit(1);
	}
	return (NULL);
}
