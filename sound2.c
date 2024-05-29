/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:36:40 by jeberle           #+#    #+#             */
/*   Updated: 2024/05/29 11:24:02 by jeberle          ###   ########.fr       */
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

void	*exitny_sound(void *arg)
{
	(void)arg;
	if (fork() == 0)
	{
		execlp("afplay", "afplay", "-v", "0.1", "assets/no.mp3", (char *) NULL);
		_exit(1);
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
		music->music_pid = fork();
		if (music->music_pid == 0)
		{
			execlp(cmd, cmd, "-v", "0.5", "assets/bg.mp3", (char *) NULL);
			_exit(1);
		}
		music->bg_sec = 0;
		while (music->bg_sec < 24)
		{
			if (!music->run_music)
				break ;
			sleep(1);
			music->bg_sec++;
		}
	}
	free(cmd);
	return (NULL);
}

void	play_sound(pthread_t thread, void *(*play)(void *))
{
	pthread_create(&thread, NULL, play, NULL);
	pthread_join(thread, NULL);
}
