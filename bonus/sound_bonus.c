/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:31:21 by jeberle           #+#    #+#             */
/*   Updated: 2024/06/07 17:04:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/so_long_bonus.h"

void	*player_move_sound(void *arg)
{
	char	*cmd;

	cmd = ft_strdup("afplay");
	(void)arg;
	if (access("assets/m.mp3", F_OK) != -1)
	{
		if (fork() == 0)
		{
			execlp(cmd, cmd, "-v", "0.6", "assets/m.mp3", (char *) NULL);
			_exit(1);
		}
	}
	else
	{
		ft_printf("The file 'assets/m.mp3' does not exist.\n");
	}
	free(cmd);
	return (NULL);
}

void	*win_sound(void *arg)
{
	(void)arg;
	if (access("assets/win.mp3", F_OK) != -1)
	{
		if (fork() == 0)
		{
			execlp("afplay", "afplay", "assets/win.mp3", (char *) NULL);
			_exit(1);
		}
	}
	else
	{
		ft_printf("The file 'assets/win.mp3' does not exist.\n");
	}
	return (NULL);
}

void	*loose_sound(void *arg)
{
	(void)arg;
	if (access("assets/loose.mp3", F_OK) != -1)
	{
		if (fork() == 0)
		{
			execlp("afplay", "afplay", "assets/loose.mp3", (char *) NULL);
			_exit(1);
		}
	}
	else
	{
		ft_printf("The file 'assets/loose.mp3' does not exist.\n");
	}
	return (NULL);
}

void	*exit_sound(void *arg)
{
	(void)arg;
	if (access("assets/exit.mp3", F_OK) != -1)
	{
		if (fork() == 0)
		{
			execlp("afplay", "afplay", "assets/exit.mp3", (char *) NULL);
			_exit(1);
		}
	}
	else
	{
		ft_printf("The file 'assets/exit.mp3' does not exist.\n");
	}
	return (NULL);
}

void	*collect_sound(void *arg)
{
	(void)arg;
	if (access("assets/collectable.mp3", F_OK) != -1)
	{
		if (fork() == 0)
		{
			execlp("afplay", "afplay", "assets/collectable.mp3", (char *) NULL);
			_exit(1);
		}
	}
	else
	{
		ft_printf("The file 'assets/collectable.mp3' does not exist.\n");
	}
	return (NULL);
}
