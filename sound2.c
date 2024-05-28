/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:36:40 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/29 00:12:46 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	*start_music(void)
{
	if (fork() == 0)
	{
		execlp("afplay", "afplay", "assets/start.mp3", (char *) NULL);
	}
	return (NULL);
}

void	*bg_music(void *arg)
{
	char	*cmd;
	t_music	*music;

	cmd = ft_strdup("afplay");
	music = (t_music *)arg;
	while (music->run_music)
	{
		if (fork() == 0)
		{
			execlp(cmd, cmd, "-v", "0.5", "assets/bg.mp3", (char *) NULL);
			_exit(1);
		}
		sleep(24);
	}
	free(cmd);
	return (NULL);
}

void	play_sound(pthread_t thread, void *(*play)(void *))
{
	pthread_create(&thread, NULL, play, NULL);
	pthread_join(thread, NULL);
}
