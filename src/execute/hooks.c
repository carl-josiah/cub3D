/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:35:31 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/12 16:28:17 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	close_game(t_data *data)
{
	free_all(data->file.lines, data);
	exit(EXIT_SUCCESS);
}

static int	on_key_press(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_game(data);
	return (0);
}

static int	on_window_close(t_data *data)
{
	close_game(data);
	return (0);
}

void	event_handlers(t_data *data)
{
	mlx_key_hook(data->mlx.win, on_key_press, data);
	mlx_hook(data->mlx.win, DESTROY_NOTIFY, 0, on_window_close, data);
}
