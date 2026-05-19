/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:35:31 by ccastro           #+#    #+#             */
/*   Updated: 2026/05/19 13:09:55 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/**
 * @brief Free and destroy everything and terminate the program.
 *
 * @param data Contains all the structs to free.
 */
static void	close_game(t_data *data)
{
	free_all(data->file.lines, data);
	exit(EXIT_SUCCESS);
}

/**
 * @brief Callback function that identify keycodes.
 *
 * @param keycode The code of the key pressed.
 * @param data The struct to pass to the function called.
 *
 * @return int Returns a number due to mlx_key_hook() implementation.
 */
static int	on_key_press(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_game(data);
	return (0);
}

/**
 * @brief Callback function that identify the window close event.
 *
 * @param data Pass data struct.
 * @return int Returns a number due to mlx_hook() implementation.
 */
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
