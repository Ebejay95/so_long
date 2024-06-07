/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:36:40 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 16:05:32 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	*start_music(void)
{
	if (access("assets/start.mp3", F_OK) != -1)
	{
		if (fork() == 0)
		{
			execlp("afplay", "afplay", "assets/start.mp3", (char *) NULL);
		}
	}
	else
	{
		ft_printf("The file 'assets/start.mp3' does not exist.\n");
	}
	return (NULL);
}

void	*exitny_sound(void *arg)
{
	char	*cmd;

	cmd = ft_strdup("afplay");
	(void)arg;
	if (access("assets/no.mp3", F_OK) != -1)
	{
		if (fork() == 0)
		{
			execlp(cmd, cmd, "-v", "0.1", "assets/no.mp3", (char *) NULL);
			_exit(1);
		}
	}
	else
	{
		ft_printf("The file 'assets/no.mp3' does not exist.\n");
	}
	free(cmd);
	return (NULL);
}

void	play_music(char *cmd)
{
	execlp(cmd, cmd, "-v", "0.5", "assets/bg.mp3", (char *) NULL);
	_exit(1);
}

void	*bg_music_loop(t_music *music, char *cmd)
{
	while (music->run_music)
	{
		music->music_pid = fork();
		if (music->music_pid == 0)
		{
			play_music(cmd);
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
	return (NULL);
}

void	*bg_music(void *arg)
{
	char	*cmd;
	t_music	*music;

	cmd = ft_strdup("afplay");
	music = (t_music *)arg;
	if (access("assets/bg.mp3", F_OK) != -1)
	{
		bg_music_loop(music, cmd);
	}
	else
	{
		ft_printf("The file 'assets/bg.mp3' does not exist.\n");
	}
	free(cmd);
	return (NULL);
}
